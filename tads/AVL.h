#ifndef AVL_H
#define AVL_H

template <class T>
class AVL{

public:

    virtual void insertar(T x) = 0;
    virtual bool buscar(T x) = 0;
    virtual void buscarEntre(T x1, T x2) = 0;
    virtual ~AVL() {}
};
template <class T>
AVL<T>* crearAVL();

#endif