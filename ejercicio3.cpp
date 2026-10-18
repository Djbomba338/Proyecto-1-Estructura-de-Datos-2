#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/HeapIMP.cpp"


using namespace std;

int main(){
    int n =0 ;
    cin>> n;

    MinHeap* ret = new MinHeap(n);
    
    for(int i = 0 ; i<n ; i++){
        long long t;
        cin>>t;
        ret->insertar(t);
    }

    long long costo = 0;
    while(ret->tamanio()>1){
        long long suma = 0;
        suma+= ret->eliminarMinimo();
        suma+= ret->eliminarMinimo();
        costo+= suma;

        ret->insertar(suma);
    }

    cout<< costo <<endl;
}