#include <cassert>
#include <string>
#include <iostream>
#include <limits>
#include <AVL.h>
#include <AVL.cpp>
using namespace std;

int main()
{
    cout<<"Ingresar la cantidad de operaciones a realizar"<<endl; 
    int n1;
    cin>> n1;

    AVL<int>*m = crearAVL<int>();
    AVL<string>*p = crearAVL<string>();

    
    for(int i = 0; i<n1; i++){
        cout<<"Ingrese los valores que quiera ingresar";
        string ingresado;
        int contador=0;
        string orden;
        string tipo;
        int contEsp=0;
        string c1;
        string c2;

        cin>> orden>> tipo >> c1 >> c2;


        if(orden== "ALTA"){
            if(tipo=="m"){
                int aNum = stoi(c1);
                m->insertar(aNum);
            } else {
                p->insertar(c1);
            }  
        } else if(orden == "BUSCAR"){
            if(tipo == "m"){
                int aNum = stoi(c1);
                bool esta = m->buscar(aNum);
                if(esta){
                    cout<<"Si";
                } else {
                    cout<< "No";
                }
            } else{
                bool esta = p->buscar(c1);
                if(esta){
                    cout<<"Si";
                } else {
                    cout<< "No";
                }
            }
        } else {
            if(tipo == "m"){
                int aNum = stoi(c1);
                int aNum2 = stoi(c2);
                m->buscarEntre(aNum,aNum2);
            } else{
                p->buscarEntre(c1,c2);
            }
        }

        
    }

}