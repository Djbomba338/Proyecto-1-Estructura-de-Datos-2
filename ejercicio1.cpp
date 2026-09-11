#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include "tads/AVL.h"
#include "tads/AVL.cpp"
using namespace std;

int main()
{

    int n1;
    cin>> n1;

    AVL<long long>*m = crearAVL<long long>();
    AVL<string>*p = crearAVL<string>();

    
    for(int i = 0; i<n1; i++){

        string orden;
        string tipo;
        string c1;
        string c2;


        cin>> orden>> tipo >> c1;

        if( orden == "RANGO"){
            cin>>c2;
        }


        if(orden== "ALTA"){
            if(tipo=="M"){
                long long aNum = stoll(c1);
                m->insertar(aNum);
            } else {
                p->insertar(c1);
            }  
        } else if(orden == "BUSCAR"){
            if(tipo == "M"){
                long long aNum = stoll(c1);
                if(m->buscar(aNum)){
                    cout<<"si"<< endl;
                } else {
                    cout<< "no"<< endl;
                }
            } else{
                if(p->buscar(c1)){
                    cout<<"si"<< endl;
                } else {
                    cout<< "no"<< endl;
                }
            }
        } else {
            if(tipo == "M"){
                long long aNum = stoll(c1);
                long long aNum2 = stoll(c2);
                m->buscarEntre(aNum,aNum2);
            } else{
                p->buscarEntre(c1,c2);
            }
        }

        
    }

}