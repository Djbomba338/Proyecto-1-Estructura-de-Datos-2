## Bitácora — Obligatorio 1

**Integrantes:** Franco Cardozo (345912), Geronimo Urrutia (351959)



## 2026-09-07 — En conjunto

- Leímos la letra del obligatorio y analizamos cómo distribuir el trabajo. Leímos las pautas e investigamos el template. Además, se avanzó en la implementación de los TAD de AVL y hash.

## 2026-09-08 — En conjunto

- Empezamos a realizar el ejercicio 1. Tuvimos problemas con la implementación del cin, ya que pensamos que entraba todo el texto y entra por palabras según los espacios. En principio, hablamos con los profesores por Teams para poder utilizar bibliotecas extras como sstream, pero al final lo resolvimos de otra manera, ya que nos explicaron que el cin funcionaba distinto.

## 2026-09-11 — Franco

- Continué con el ejercicio 1. Terminé de solucionar los conflictos, por ejemplo, poner el endl para que generara el salto de línea, y solucioné detalles menores de implementación. Utilicé ChatGPT para que me creara un código en Bash para poder correr las pruebas por ejercicio.

## 2026-09-15 — En conjunto

- Realizamos el ejercicio 2. En un principio, no teníamos claro cómo implementar un hash abierto, por lo cual tuvimos que investigar cómo se realizaba y cómo funcionaban las colisiones. Con base en lo dado en el curso e investigando a través de clases y preguntas a los profesores, terminamos de definir el TAD y, a partir de eso, realizamos el ejercicio.

## 2026-10-18 — En conjunto

- Realizamos el ejercicio 3 en conjunto. Este ejercicio nos pareció bastante fácil; desde un principio ya teníamos pensado cómo resolverlo. Lo que hicimos fue ingresar cada uno de los archivos en un heap y fuimos extrayendo los 2 elementos más chicos, los sumamos, sumamos el resultado al costo total y reingresamos la suma al heap. En este ejercicio utilizamos la implementación de heap vista en clase y publicada en Teams por el profesor. El único problema que surgió fue que habíamos inicializado todos los valores como int en lugar de long long y nos daba error, entonces tuvimos que cambiarlos.

## 2026-10-21 — En conjunto

- Realizamos el ejercicio 4 en conjunto. Al momento de comenzar a pensar una resolución del ejercicio y ver que se necesitaba utilizar un heap, tomamos la decisión de modificar la clase heap que habíamos creado previamente para el ejercicio 3 e implementarla con un template para poder utilizarla libremente. Al momento de leer la letra, realizamos una lluvia de ideas sobre cómo complementar el heap con otra estructura para poder realizar el ejercicio. Al principio se nos ocurrió implementar un hash mezclado con un heap, pero nos dimos cuenta de que habíamos interpretado mal la letra, descartamos esa opción y optamos por utilizar el algoritmo de orden topológico de grafos visto en clase. Lo que hicimos fue crear una estructura que contenía el número y su prioridad. Creamos un array de listas del tipo nodo de v+1 posiciones en el cual, a medida que íbamos leyendo las dependencias, las íbamos insertando en la posición correspondiente para simular las aristas de un grafo, a la vez que, en otro array de enteros, íbamos sumando en la posición del vértice que dependía de otro. Luego recorrimos el array en el cual estaban las dependencias de los vértices y fuimos insertando en el heap los vértices que no dependían de ninguno. Después utilizamos la implementación normal de orden topológico enviada por Teams, con la modificación de que, en lugar de una cola, utilizamos el heap. Al momento de ejecutar el código, nos surgieron varios errores que corregimos y fueron los siguientes:
- En la estructura nodo, al implementar los operadores < y <=, nos estaba dando error porque nos habíamos olvidado de que, cuando hay 2 números con la misma prioridad, se desempata por el tamaño del número, lo que causó que nos dieran mal las pruebas.
- Nos olvidamos de agregar el caso de que quedara un ciclo, entonces las pruebas nos estaban dando mal en los casos que tenían que devolver imposible.
- Los últimos errores se debieron a cómo habíamos utilizado la lista, ya que estábamos insertando y borrando mal los nodos. Tuvimos que consultar con ChatGPT para pedirle que nos explicara cómo funcionaba el TAD.

## 2026-10-22 — En conjunto

- Realizamos el ejercicio 5 en conjunto. Leímos la letra del ejercicio e implementamos el algoritmo de Kruskal visto en clase, con algunas modificaciones. Lo primero que hicimos fue pensar cómo modificar el algoritmo. Nuestra idea fue que, como no teníamos vértices para implementar Kruskal como un grafo, utilizamos los senderos como si fueran aristas del grafo y ahí fuimos insertando cada uno en el min-heap que íbamos a utilizar para, más adelante, poder sacar el sendero de menor peso. Después implementamos la condición de que, si tenemos solo un refugio, retornamos 0 e implementamos Kruskal. Al terminar de ejecutar Kruskal, lo que hicimos fue revisar la cantidad de senderos que recorrió y, en caso de recorrer una cantidad distinta de v-1 senderos, imprimimos imposible. Esto se debe a que, en caso de que tengamos 2 refugios que no estén conectados, quiere decir que no hay un sendero entre ellos. Por lo tanto, si no tenemos v-1 senderos que conecten nuestros v refugios, va a ser imposible conectar todos los refugios. Al momento de ejecutar el código, nos dio varios errores. Releímos el código y lo fuimos corrigiendo. Los errores que teníamos eran:
- El heap lo habíamos creado con v+1 espacios en lugar de e espacios.
- El primer for para recibir los datos de los senderos también lo habíamos limitado hasta v+1 y luego lo modificamos hasta e.
- Habíamos inicializado como int la variable para contar el peso del sendero y la tuvimos que cambiar a long long.
- Habíamos creado el heap con v vértices y lo tuvimos que cambiar a v+1.

Luego de realizar todas esas correcciones, el ejercicio nos seguía dando mal. Entonces le preguntamos a ChatGPT y resultó que nos faltaba poner los endl al final de cada cout, y por eso estaba dando mal el ejercicio.