# Bitácora — Obligatorio 1

**Integrantes:**Franco Cardozo (345912), Geronimo Urrutia (351959)

> **Instrucciones** (borrar esta sección antes de entregar): agregar una entrada por
> cada día trabajado, indicando la fecha y quién trabajó (un integrante o "En conjunto").
> Registrar el proceso real: ideas exploradas, decisiones y su justificación, partes de
> implementaciones, bugs encontrados y cómo se corrigieron, resultados de pruebas y dudas
> abiertas. Si se usó IA ese día, indicar herramienta, consulta y qué se hizo con la
> respuesta. Una bitácora escrita íntegramente el día de la entrega implica pérdida de puntos.


## 2026-09-07 — En conjunto
- Leimos la letra del obligatorio y analizamos como distribuir el trabajo, leimos las pautas e investigamos el template. Ademas se realizo un avance del implemento del Tad de AVL y Hash

## 2026-09-08 — En conjunto
- Empezamos a realizar el ejercicio 1, tuvimos problemas con la implementacion del cin ya que pensamos que entraba todo el texto y entra por palabras segun espacios, en principio hablamos con los profesores por teams para poder utilizar bibliotecas extras como el sstream, pero al final resolvimos de otra manera ya que nos explicaron que el cin funcionaba distinto.

## 2026-09-11 — Franco 
- Continue con el ejercicio 1, termine de solucionar los conflictos por ejemplo poner el endl para que genere el salto de linea y solucione detalles menores de implementaciones, utilice chat gpt para que me cree un codigo en bash para poder correr las pruebas por ejercicio.

## 2026-10-18 — En conjunto 
- Realizamos el ejercicio 3 en conjunto, este ejercicio nos parecio bastante facil, desde un principio ya teniamos pensado como resolverlo, lo que hicimos fue ingresar cada uno de los archivos en un heap y fuimos extrayendo los 2 elementos mas chicos, los sumamos, sumamos el resultado al costo total y reingresamos la suma al heap. En este ejercicio utilizamos la implemetacion de heap vista en clase y publicada en teams por el profesor, el unico problema que surgio fue que habiamos inicializado todos los valores como int en lugar de un long long y nos daba error entonces tuvimos que cambiarlo.

## 2026-10-21 — En conjunto
-Realizamos el ejercicio 4 en conjunto, al momento de comenzar a pensar una resolucion del ejercicio y ver que se necesitaba utlizar un heap tomamos la decision de modificar la clase heap que habiamos creado previamente para el ejercicio 3 e implemenatrla con un template para poder utilizarla libremente. Al momento de leer la letra realizamos una lluvia de ideas de como complementar el heap con otra estructura para poder realizar el ejercicio, al principio se nos ocurrio implementar un hash mezclado con un heap pero nos dimos cuenta de que habiamos interpretado mal la letra y descartamos esa opcion y optamos por utilizar el algoritmo de orden topologico de grafos visto en clase. Lo que hicimos fue crear una estructura la cual contenia el numero y su prioridad, creamos un array de listas del tipo nodo de v+1 posiciones en el cual a medida que ibamos leyendo las dependencias las ibamos insertando en la posicion correspondiente para simular las aristas de un grafo a la ve que en otro array de enteros ibamos sumando en la posicion del vertice que dependia de otro. Luego recorrimos el array en el cual estaban las dependencias de los vertices y los que no dependian de ninguno los fuimos insertando en el heap, luego utilizamos la implementacion normal de orden topologico enviada por teams con la modificacion de que en lugar de una cola utilizamos el heap.Al momento de ejecutar el codigo nos surgieron varios errores los cuales corregimos y fueron los siguientes:
- En la estructura nodo al implementar los operadores de < y <= nos estaba dando error porque nos habiamos olvidado de que cuando hay 2 numeros con la misma prioridad se desempata por el tamaño del numero lo que causo que nos dieran mal las pruebas.
- Nos olivdamos de agregar el caso de que quede un ciclo entonces la pruebas nos estaban dando mal en los casos que tenian que devolver imposible.
- Los ultimos errores fueron de como habiamos utilzado la lista ya que estabamos insertando y borrando mal los nodos y tuvimos que consultar con chatgpt para pedirle que nos explique como funcionaba el tad.
 


## 2026-10-22 — En conjunto
-Realizamos el ejercicio 5 en conjunto, leimos la letra del ejericio e implementamos el algoritmo de kruskal visto en clase con algunas modificaciones. Lo primero que hicimos fue pensar como modificar el algoritmo, nuestra idea fue que como no teniamos vertices para implementar kruskal como un grafo utlizamos los senderos como si fueran una arista del grafo y ahi fuimos insertando cada una el minheap que ibamos a utilizar para mas adelante poder sacar el sendero de menor peso. Despues implementamos la condicion de que si tengo solo un refugio retorno 0 e implementamos kruskal. Al terminarse de ejecutar kruskal lo que hicimos fue revisar la cantidad de senderos que recorrio y en caso de recorrer una cantidad distinta a v-1 senderos imprimimos imposible, esto debido a que en caso de tenga 2 refugios que no esten conectados quiere decir que no ha un sendero entre ellos por lo tanto si yo no tengo v-1 senderos que conecten mis v refugios va a ser imposible conectar todos los refugios. Al momento de ejecutar el codigo nos dio varios errores y releimos el codigo y lo fuimos corrigiendo, los errores que teniamos eran:
- El heap lo habiamos creado con v+1 espacios en lugar de e espacios.
- El primer for para recibir los datos de los senderos tambien lo habiamos limitado hasta v+1 y luego lo modificamos hasata e
- Habiamos inicializado en int la variable para contar el peso del sendero y lo tuvimos que cambiar por long long 
- Habiamos creado el heap con v vertices y lo tuvimos que cambiar por v+1.
Luego de realizar todas esas correcciones el ejercicio nos seguia dando mal entonces le preguntamos a chatgpt y resulto que nos faltaba poner los endl al final de cada cout y por eso estaba dando mal el ejercicio.









