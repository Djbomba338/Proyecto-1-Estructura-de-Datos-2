#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/HASHAbierto.cpp"

using namespace std;

int main()
{
    int in = 0 ;
    cin>> in;
    TablaHash* ret = ret->crear(in);

    for (int i = 0 ; i < in; i++){
        
        string c;
        cin>>c;
        ret->agregar(c,ret);

    };

    int q  =0 ;
    cin>> q;
    int retorno;
    for(int i = 0; i< q; i++){
        string c;
        cin>>c;
        retorno = ret->cantEnBucket(c, ret);
        cout << retorno<< endl;
    }

    cout<< ret->darCantBuckets(ret)<< " " << ret->darMax(ret)<< endl;

};