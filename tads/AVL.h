#ifndef AVL_H
#define AVL_H

template <class T>
class AVL{

public:

    virtual void insertar(T x) = 0;
    virtual bool buscar(T x);
    virtual ListImp buscarEntre(T x1, T x2);
    virtual ~AVL() {}
};
template <class T>
AVL<T>* crearAVL();

#endif