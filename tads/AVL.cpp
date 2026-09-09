#ifndef AVL_IMP
#define AVL_IMP

#include "AVL.h"
#include <cassert>
using namespace std;

template <class T>
class AVLImp : public AVL<T> {
    
    private:
        class Nodo{
        public:
            T dato;
            int altura;
            Nodo *izq;
            Nodo *der;
            Nodo(T x) :dato(x), altura(1), izq(NULL) , der(NULL) {}
        };
        Nodo * raiz;

        int calcBalance (Nodo * t){
            int alturaIzq = t->izq ? t->izq->altura : 0;
            int alturaDer = t->der ? t->der->altura : 0;
            return alturaDer - alturaIzq;
        }
        void ActualizarAltura(Nodo * t){
            int alturaIzq = t->izq ? t->izq->altura : 0;
            int alturaDer = t->der ? t->der->altura : 0;
            t->altura = max(alturaDer,alturaIzq)+1;
        }
        Nodo * rotacionIzq(Nodo * a, Nodo * b){
            a->der = b->izq; //Posible cambio 
            b->izq = a;
            ActualizarAltura(a);
            ActualizarAltura(b);
            return b;
        }
        Nodo * rotacionDer(Nodo * a, Nodo * b){
            a->izq = b->der;
            b->der = a;
            ActualizarAltura(a);
            ActualizarAltura(b);
            return b;
        }

        Nodo * insertar (Nodo * t, T x){
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
            //DD
            if (balance > 1 && t->der->dato < x){
                return rotacionIzq(t, t->der);
            }
            //DI
            if (balance > 1 && t->der->dato > x){
                t->der= rotacionDer(t->der, t->der->izq);
                return rotacionIzq(t,t->der);
            }
            //ID
            if (balance < -1 && t->izq->dato < x){
                t->izq= rotacionIzq(t->izq, t->izq->der);
                return rotacionDer(t,t->izq);
            }
            //II
            if (balance < -1 && t->izq->dato > x){
                return rotacionDer(t, t->der);
            }

            return t;
        }

        bool buscar(Nodo * t, T x){
            if(t == NULL){
                return false;
            }
            if(t->dato> x){
                return buscar(t->izq,x);
            } else if(t->dato<x){
                return buscar(t->der,x);
            } else {
                return true;
            }
        }

        void buscarEntre(Nodo * t, T x1, T x2){
            if(t == NULL){
                return 
            }
            if(t->dato>= x1 && t->dato<=x2){
                buscarEntre(t->izq, x1, x2);
                buscarEntre(t->der,x1,x2);
                cout>> t->dato;
            }
            if(t->dato<x1){
                buscarEntre(t->der,x1,x2);
            }
            if(t->dato>x2){
                buscarEntre(t->izq,x1,x2);
            }
        }


   
    public:
        AVL(): raiz(NULL) {}
        ~AVL() { //Estos son los destructores
             
        }
        AVLimp(){
            raiz = NULL;
        }
        void insertar(T x){
            raiz = insertar(raiz,x);
        }

        AVL<T>* crearAVL() {
            return new AVLImp<T>();
        }
        bool buscar(T x) {
            return buscar(raiz, x);
        }
        void buscarEntre(T x1, T x2){
            buscarEntre(raiz,x1,x2);
        }
};

#endif