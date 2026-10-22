# Justificación de órdenes — Obligatorio 1


## Ejercicio 1
- La letra del ejercicio exige que Alta y Buscar se realicen en orden temporal O(log K) en peor caso, siendo k la cantidad de piezas registradas en esa coleccion y O(log K + R) siendo R la cantidad de piezas que esa consulta reporta.
Utilizamos solo el tad AVL con template, iniciando con un long long las monedas y string las pinturas.
Alta y Buscar tienen orden O(log k) en el peor caso, esto es porque los avl mantienen una altura O(log k),  y cuando se inserta actualiza las alturas en el caso que lo necesite haciendo rotaciones.
Rango tiene orden O(log de K + R) ya que para la consulta recorremos las piezas en orden y evitamos visitar ramas innecesarias. Los caminos para el rango marcado tienen un costo de O(log K)  cuando recorrer e imprimir las piezas del intervalo cuesta O(R), si sumamos los dos termina costando O(log de K + R)

## Ejercicio 2
- La letra del ejercicio exige que registrar una palabra y responder una consulta tengan O(L) promedio siendo L el largo de la palabra, ademas pide que obtener la ultima linea de salida sea en O(1) en el peor caso, y los dos valores que pide, cajones distintos y palabras del cajón más grande, se mantienen actualizados durante el registro, con O(1) extra por palabra, y que el orden temporal sea lineal con respecto al tamaño total de la de la entrada.
Lo principal se cumple ya que utilizamos una tabla de hash abierta, por cada palabra creamos una clave con un arreglo de 26 posiciones, ahi contamos cuantas veces aparece cada letra, siendo asi que recorrer la palabra cuesta O(L) y calcular el hash tambien cuesta O(L) porque recorremos las posiciones y el alfabeto tiene un tamaño fijo.
El tamaño de la tabla se calcula haciendo el calculo N / 0.6 + 1 siendo n la cantidad de palabras registradas, y como puede haber como maximo n claves distintas el factor de carga se mantiene abajo de 0,6 sin realizar un rehash, y como con una distribucion adecuada buscar en una tabla hash buscar una clave tiene O(1), comparar dos claves tambien tiene O(1).
Ademas guardamos un solo nodo por clave y un contador de palabras asi no teniamos que crear un nodo por palabra con misma clave.
Y por ultimo al sumar costos cada registro y consulta queda en O(L) promedio y como procesamos cada palabra una vez el costo es lineal.

## Ejercicio 3
La letra del ejercicio exige resolucion en orden O(NlogN) y orden espacial O(N). El oriden espacial se cumple porque el unico elemento que utilizamos es un minHeap que almacena N elementos como maximo.
Por otra parte el agregar un elemento a un heap es de O(log N) y como hay que hacer eso N veces en el primer for queda en O(N log N). Despues dentro del while extraemos un elemento y añadimos uno, las 2 operaciones son de O(logN), como hacemos una cantidad constante de operaciones los costos se suman y hace que se mantenga el O(logN). Ademas como en cada while tenemos un elemento menos el while se ejecuta N-1 veces lo que hace que el costo final sea O((N−1) log N).
Por ultimo al sumar todos los costos y simplificar O((N−1) log N) y O(NlogN) nos da como resultado O(NlogN).

## Ejercicio 4
La letra del ejercicio exige resolucion en orden O((V +A)logV ) y orden espacial O(V+A). El orden espacial se cumple ya que las estructuras que utilizamos fueron un MinHeap que tiene como maximo V elementos y arrays de tamaño V, uno de ellos implementado con una lista que contiene como A elementos lo que nos da el O(V + A).
Por otra parte al principio de la implementacion recorrimos las V posiciones de los arrays e insertamos los A elementos a las listas. Como recorrer los arrays tiene un O(V) e insertar un elemento al final de una lista tiene un O(1), al hacerlo A veces obtenemos O(A). 
Después, insertamos en el MinHeap los módulos que tienen grado de entrada igual a cero. Como podemos insertar V módulos como maximo y cada inserción tiene un costo O(log V), obtenemos O(V log V). 
En el while tenemos que extraer los elementos del heap que es de O(logV) y como puedo extraer como maximo V elementos queda O(VlogV). 
Luego tenemos que sacar cada uno de los elementos de la lista que es O(1) y como tengo A elementos va a resultar en O(A). 
Por utlimo tengo que volver a insertar los V elementos en la lista lo que tiene O(VlogV). Luego de sumar todos los costos nos queda: O(V + E + V log V + V log V), que se simplifica a O(V log V + E) lo que cumple con lo pedido

## Ejercicio 5
La letra del ejercicio exige resolucion en orden O(Elog E) y orden espacial O(V+E). El orden espacial se cumple ya que las estructuras que usamos fueron un minheap de E elementos y un MFSet con V + 1 elementos pero como el 1 es constante no se considera para el orden lo que da como resultado O(V+E). 
Por otra parte agregamos E elementos en el heap, cada un con O(logE) lo que resulta en orden E(logE).Mas adelante tenemos que extraer los elementos del Heap lo que tiene costo O(log E) y como en el peor caso hay que extraer los E elementos queda orden E(logE) por ultimo dentro del while las operaciones del MFSet son de orden menor que el dominante entonces no afecta el orden del resto de las operaciones. Luego de realizar las operaciones concluimos que la resolucion tiene O(ElogE).

