#!/usr/bin/env bash
# Ejecutar desde la carpeta que contiene ejercicio1.cpp, ..., ejercicio5.cpp.
# Uso: bash correr_pruebas.sh [todos|1|2|3|4|5] [carpeta_del_proyecto]
# Variables opcionales:
#   CXX=g++              Compilador (nombre o ruta, sin argumentos).
#   TIMEOUT_SECONDS=10   Limite por prueba, en segundos enteros positivos.
#   TESTS_DIR=/ruta/tests Usar pruebas locales sin descargar el repositorio.
# Fuente: https://github.com/Algoritmos-2/A2-obligatorio-2026-S2-letra/tree/main/tests
# Requiere Bash, g++, Git, diff, sed y GNU timeout (Git Bash o Linux/WSL).
set -euo pipefail
shopt -s nullglob

die() { printf 'ERROR: %s\n' "$*" >&2; exit 2; }
usage() {
    printf '%s\n' \
        'Uso: bash correr_pruebas.sh [todos|1|2|3|4|5] [carpeta_del_proyecto]' \
        'Ejemplos:' \
        '  bash correr_pruebas.sh' \
        '  bash correr_pruebas.sh 3' \
        '  TIMEOUT_SECONDS=30 bash correr_pruebas.sh todos' \
        '  TESTS_DIR=/ruta/tests bash correr_pruebas.sh 1' \
        'Las descargas y los resultados se guardan en .pruebas/ del proyecto.' \
        'Las pruebas descargadas se reutilizan. Para actualizarlas:' \
        '  git -C .pruebas/repositorio pull --ff-only' \
        'Salida: 0 = todo OK; 1 = pruebas/compilaciones fallidas; 2 = error de uso o entorno.'
}

[[ ${1:-} != '--help' && ${1:-} != '-h' ]] || { usage; exit 0; }
(( $# <= 2 )) || die 'Demasiados argumentos. Usa --help.'
selection=${1:-todos}
case "$selection" in
    todos) exercises=(1 2 3 4 5) ;;
    [1-5]) exercises=("$selection") ;;
    *) die 'Selecciona todos o un numero del 1 al 5.' ;;
esac
compiler=${CXX:-g++}
limit=${TIMEOUT_SECONDS:-10}
[[ "$limit" =~ ^[1-9][0-9]*$ ]] || die 'TIMEOUT_SECONDS debe ser un entero positivo.'
for tool in "$compiler" diff sed mktemp; do
    command -v "$tool" >/dev/null 2>&1 || die "No se encontro $tool en PATH."
done
timeout_tool=timeout
if ! timeout --version 2>/dev/null | sed -n '1p' | grep -q 'GNU'; then
    if command -v gtimeout >/dev/null 2>&1; then
        timeout_tool=gtimeout
    else
        die 'Se necesita GNU timeout. Ejecuta desde Git Bash o Linux/WSL con coreutils.'
    fi
fi

project=$(cd -- "${2:-.}" && pwd) || die 'No se pudo abrir la carpeta del proyecto.'
tests=${TESTS_DIR:-}
if [[ -n "$tests" ]]; then
    tests=$(cd -- "$tests" && pwd) || die 'TESTS_DIR no existe.'
fi
cd -- "$project"
mkdir -p -- .pruebas
if [[ -z "$tests" ]]; then
    command -v git >/dev/null 2>&1 || die 'Se necesita Git para descargar las pruebas.'
    repo="$project/.pruebas/repositorio"
    if [[ ! -d "$repo" ]]; then
        printf 'Descargando las pruebas oficiales...\n'
        # Clonar en una carpeta nueva evita reutilizar una descarga incompleta.
        staging=$(mktemp -d "$project/.pruebas/descarga.XXXXXX")
        git -c core.autocrlf=false clone --depth 1 --branch main \
            https://github.com/Algoritmos-2/A2-obligatorio-2026-S2-letra.git \
            "$staging" || die "Fallo la descarga. Revisa la conexion. Descarga parcial: $staging"
        mv -- "$staging" "$repo"
    fi
    tests="$repo/tests"
fi
[[ -d "$tests" ]] || die "No existe la carpeta de pruebas: $tests"
results=$(mktemp -d "$project/.pruebas/resultados.XXXXXX")
passed=0
failed=0
build_errors=0

for n in "${exercises[@]}"; do
    name="ejercicio$n"
    printf '\n=== %s ===\n' "$name"
    dir="$results/$name"
    mkdir -p -- "$dir"
    if [[ ! -f "$name.cpp" ]]; then
        printf 'ERROR: no existe %s.cpp\n' "$name"
        build_errors=$((build_errors + 1))
        continue
    fi
    inputs=("$tests/$name/"*.in.txt)
    if (( ${#inputs[@]} == 0 )); then
        printf 'ERROR: no hay pruebas en %s/%s\n' "$tests" "$name"
        build_errors=$((build_errors + 1))
        continue
    fi
    # La extension .exe tambien funciona en Linux y evita ambiguedades en Windows.
    binary="$dir/$name.exe"
    if ! "$compiler" -std=c++11 -O2 "$name.cpp" -o "$binary" >"$dir/compilacion.log" 2>&1; then
        printf 'ERROR DE COMPILACION:\n'
        sed -n '1,40p' "$dir/compilacion.log"
        build_errors=$((build_errors + 1))
        continue
    fi
    for input in "${inputs[@]}"; do
        case_name=${input##*/}
        case_name=${case_name%.in.txt}
        expected="${input%.in.txt}.out.txt"
        actual="$dir/$case_name.myout.txt"
        errors="$dir/$case_name.stderr.txt"
        difference="$dir/$case_name.diff.txt"
        if [[ ! -f "$expected" ]]; then
            printf 'FALLO %-28s falta el archivo .out.txt\n' "$case_name"
            failed=$((failed + 1))
            continue
        fi
        if "$timeout_tool" -k 2s "${limit}s" "$binary" <"$input" >"$actual" 2>"$errors"; then
            # Normalizar solo CRLF/LF: los espacios y lineas vacias SI se comparan.
            sed 's/\r$//' "$expected" >"$dir/esperado.normalizado.txt"
            sed 's/\r$//' "$actual" >"$dir/obtenido.normalizado.txt"
            if diff -u "$dir/esperado.normalizado.txt" "$dir/obtenido.normalizado.txt" >"$difference" 2>&1; then
                printf 'OK    %s\n' "$case_name"
                passed=$((passed + 1))
            else
                printf 'FALLO %s (salida diferente o error de comparacion)\n' "$case_name"
                sed -n '1,20p' "$difference"
                failed=$((failed + 1))
            fi
        else
            status=$?
            if [[ "$status" == 124 || "$status" == 137 ]]; then
                printf 'FALLO %s (limite de tiempo o proceso terminado; codigo %s)\n' "$case_name" "$status"
            else
                printf 'FALLO %s (error de ejecucion, codigo %s)\n' "$case_name" "$status"
            fi
            sed -n '1,10p' "$errors"
            failed=$((failed + 1))
        fi
    done
done

printf '\nResumen: %s OK | %s pruebas fallidas | %s errores de compilacion/preparacion\n' \
    "$passed" "$failed" "$build_errors"
printf 'Salidas, diferencias y registros: %s\n' "$results"
if (( failed > 0 || build_errors > 0 )); then exit 1; fi
exit 0
