#ifndef AVL_H
#define AVL_H

#include "AVL.H"
#include <cassert>
using namespace std;

template <class AVL>
class AVLImp : public List<AVL> {
    
    private:
        class Nodo{
            int dato;
            Nodo *izq;
            Nodo *der;
            Nodo(int x) : dato(x), izq(NULL) , der(NULL) {}
        }
        Nodo * raiz;
        Nodo * insertar (Nodo * t, int x){
            if(!t){
                return new Nodo(x);
            }
            if(t->dato == x) return t;
            if(t->dato>x){
               t->izq = insertar(t->izq,x);
            } else {
                t->der = insertar(t->der,x);
            }
            ActualizarAltura(t);
            int balance = calcBalance(t);
            if (balance > 1 &&){
                
            }
            
        }
   
    public:
        AVL(): raiz(NULL) {}
        ~AVL() { //Estos son los destructores
             // Liberamos la memoria 
        }
};

#endif