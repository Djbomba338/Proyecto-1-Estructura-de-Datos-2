# Bitácora — Obligatorio 1

**Integrantes:**Franco Cardozo (345912), Geronimo Urrutia (351959)

> **Instrucciones** (borrar esta sección antes de entregar): agregar una entrada por
> cada día trabajado, indicando la fecha y quién trabajó (un integrante o "En conjunto").
> Registrar el proceso real: ideas exploradas, decisiones y su justificación, partes de
> implementaciones, bugs encontrados y cómo se corrigieron, resultados de pruebas y dudas
> abiertas. Si se usó IA ese día, indicar herramienta, consulta y qué se hizo con la
> respuesta. Una bitácora escrita íntegramente el día de la entrega implica pérdida de puntos.

## 2026-10-22 — En conjunto
-Realizamos el ejercicio 5 en conjunto, leimos la letra del ejericio e implementamos el algoritmo de kruskal visto en clase con algunas modificaciones. Lo primero que hicimos fue pensar como modificar el algoritmo, nuestra idea fue que como no teniamos vertices para implementar kruskal como un grafo utlizamos los senderos como si fueran una arista del grafo y ahi fuimos insertando cada una el minheap que ibamos a utilizar para mas adelante poder sacar el sendero de menor peso. Despues implementamos la condicion de que si tengo solo un refugio retorno 0 e implementamos kruskal. Al terminarse de ejecutar kruskal lo que hicimos fue revisar la cantidad de senderos que recorrio y en caso de recorrer una cantidad distinta a v-1 senderos imprimimos imposible, esto debido a que en caso de tenga 2 refugios que no esten conectados quiere decir que no ha un sendero entre ellos por lo tanto si yo no tengo v-1 senderos que conecten mis v refugios va a ser imposible conectar todos los refugios. Al momento de ejecutar el codigo nos dio varios errores y releimos el codigo y lo fuimos corrigiendo, los errores que teniamos eran:
- El heap lo habiamos creado con v+1 espacios en lugar de e
- 

## 2026-10-07 — En conjunto
-Realizamos el ejercicio 4 para el cual tuvimos que modificar el tad Heap, de manera que tenga un template ahora

## 2026-09-07 — En conjunto
- Leimos la letra del obligatorio y analizamos como distribuir el trabajo, leimos las pautas e investigamos el template. Ademas se realizo un avance del implemento del Tad de AVL y Hash

## 2026-09-08 — En conjunto
- Empezamos a realizar el ejercicio 1, tuvimos problemas con la implementacion del cin ya que pensamos que entraba todo el texto y entra por palabras segun espacios.

## 2026-09-11 — Franco 
- Continue con el ejercicio 1, termine de solucionar los conflictos y solucione detalles menores de implementaciones, corrieron todas las pruebas.

## 2026-10-18 — En conjunto 
- Ejercicio 2 y 3 realizados, utilizamos chat GPT astra 6, codex para pedirle que nos ejecute las pruebas.

