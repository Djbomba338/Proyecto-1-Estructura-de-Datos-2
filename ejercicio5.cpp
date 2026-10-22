#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/MFset.cpp"
#include "tads/HeapIMP.cpp"

using namespace std;
struct nodo{
    int peso;
    int inicio;
    int destino;

    bool operator<(nodo otro) {
        if(peso == otro.peso){
            return peso < otro.peso;
        }
        return peso < otro.peso;
    }
    bool operator==(nodo otro) {
        return peso == otro.peso;
    }
    bool operator<=(nodo otro){
        if(peso == otro.peso){
            return peso <= otro.peso;
        }
        return peso <= otro.peso;
    }
};
int main()
{
    int v = 0;
    int e = 0;

    cin>> v >> e;

    MinHeap<nodo>* ret = new MinHeap<nodo>(e); 

    for(int i = 0 ; i< e ; i++){
        int j = 0;
        int p = 0;
        int d = 0;
        cin>> j>>d>>p;
        nodo aux ;
        aux.inicio =j;
        aux.destino = d;
        aux.peso = p;
        ret->insertar(aux);
    }

    if(v == 1){
        cout<< 0 << endl;
        return 0;
    }

    long long retorno = 0;
    int cantVisitados = 0;
    MFSet mf(v+1);
    while(!ret->esVacio() && cantVisitados< v-1){
        nodo aux = ret->eliminarMinimo();
        if(mf.representante(aux.inicio) != mf.representante(aux.destino)){
            retorno += aux.peso;
            mf.unir(aux.inicio,aux.destino);
            cantVisitados ++;
        }
    }
    if(cantVisitados != v-1){
        cout <<"imposible" << endl;
    }else{
        cout << retorno << endl;
    }


    delete ret;
    return 0;


}