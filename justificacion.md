# Justificación de órdenes — Obligatorio 1

> **Instrucciones** (borrar esta sección antes de entregar): para cada ejercicio cuya
> letra plantea restricciones de órdenes (tiempo o espacio), justificar brevemente por
> qué la solución cumple, indicando qué estructuras de datos o algoritmos se utilizaron.
> Ejemplo: "La letra exige inserción en O(log n); usamos un min-heap sobre arreglo,
> donde flotar/hundir recorren a lo sumo la altura del árbol". Si un ejercicio no tiene
> restricciones de órdenes, indicarlo.

## Ejercicio 1
- Sin restricciones de órdenes. / Justificación: ...

## Ejercicio 2
- Sin restricciones de órdenes. / Justificación: ...

## Ejercicio 3
La letra del ejercicio exige resolucion en orden O(NlogN) y orden espacial O(N). El oriden espacial se cumple porque el unico elemento que utilizamos es un minHeap que almacena N elementos como maximo.
Por otra parte el agregar un elemento a un heap es de O(log N) y como hay que hacer eso N veces en el primer for queda en orden (N logN). Despues dentro del while extraemos un elemento y añadimos uno, las 2 operaciones son de O(logN), como hacemos una cantidad constante de operaciones los costos se suman y hace que se mantenga el O(logN). Ademas como en cada while tenemos un elemento menos el while se ejecuta N-1 veces lo que hace que el costo final sea O((N−1) log N).
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
Por otra parte agregamos E elementos en el heap, cada un con O(logE) lo que resulta en orden E(logE).Mas adelante tenemos que extraer los elementos del Heap lo que tiene costo O(logN) y como en el peor caso hay que extraer los E elementos queda orden E(logE) por ultimo dentro del while las operaciones del MFSet son de orden menor que el dominante entonces no afecta el orden del resto de las operaciones. Luego de realizar las operaciones concluimos que la resolucion tiene O(ElogE).

