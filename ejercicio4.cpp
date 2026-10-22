#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/ListImp.cpp"
#include "tads/HeapIMP.cpp"

using namespace std;

struct nodo{
    int numero;
    int prioridad;

    bool operator<(nodo otro) {
        if(prioridad == otro.prioridad){
            return numero < otro.numero;
        }
        return prioridad < otro.prioridad;
    }
    bool operator==(nodo otro) {
        return prioridad == otro.prioridad;
    }
    bool operator<=(nodo otro){
        if(prioridad == otro.prioridad){
            return numero <= otro.numero;
        }
        return prioridad <= otro.prioridad;
    }
};

int main(){
    int cantModulos = 0;
    int cantDep=0;
    cin>> cantModulos >> cantDep;
    List<nodo> ** aux = new List<nodo>*[cantModulos+1];
    int * grado = new int [cantModulos+1]{0};
    nodo * aux25 = new nodo [cantModulos+1]; // ya estabamos cansados de los arrays

    for(int i = 1; i< cantModulos+1; i++){
        aux25[i].numero = i;
        cin>> aux25[i].prioridad;
    }
    for(int i = 1 ; i<= cantModulos; i++){
        aux[i]= new ListImp<nodo>();
    }
    for(int i = 0; i< cantDep; i++){
        int a = 0;
        int b = 0;
        cin>> a >> b;
        aux[a]->insert(aux25[b]);
        grado[b]++;

    }

    MinHeap<nodo>* ret = new MinHeap<nodo>(cantModulos+1);
    for (int i = 1; i < cantModulos+1; i ++) {
        if (grado[i] == 0) {
            ret->insertar(aux25[i]);
        }
    }

    int* orden = new int[cantModulos];
    int procesados = 0;
    while (!ret->esVacio()) {
        nodo ns = ret->eliminarMinimo();
        orden[procesados] = ns.numero;
        procesados ++;
        List<nodo> * aux2 = aux[ns.numero];
        while(!aux2->isEmpty()){
            nodo destino = aux2->get(0);
            aux2->removeAt(0);
            grado[destino.numero]--;
            if(grado[destino.numero] == 0){
                ret->insertar(aux25[destino.numero]);
            }
        }
    }
    if(procesados != cantModulos){
        cout << "imposible" << endl;
    }else{
        for(int i = 0; i < procesados; i++){
            cout << orden[i] << '\n';
        }
    }

    delete [] aux25;
    delete [] aux;
    delete [] orden;
    delete [] grado;
    delete ret;
    return 0;
}