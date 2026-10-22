#include <iostream>
using namespace std;

template <class T>
class MinHeap {
private:
    T* datos;
    long long cantidad;
    long long capacidad;

    long long padre(long long pos) {
        return (pos - 1) / 2;
    }

    long long hijoIzquierdo(long long pos) {
        return 2 * pos + 1;
    }

    long long hijoDerecho(long long pos) {
        return 2 * pos + 2;
    }

    void intercambiar(long long pos1, long long pos2) {
        T aux = datos[pos1];
        datos[pos1] = datos[pos2];
        datos[pos2] = aux;
    }

    void flotar(long long pos) {
        while (pos > 0 && datos[pos] < datos[padre(pos)]) {
            intercambiar(pos, padre(pos));
            pos = padre(pos);
        }
    }

    void hundir(long long pos) {
        while (hijoIzquierdo(pos) < cantidad) {

            long long hijoMenor = hijoIzquierdo(pos);

            if (hijoDerecho(pos) < cantidad &&
                datos[hijoDerecho(pos)] < datos[hijoIzquierdo(pos)]) {

                hijoMenor = hijoDerecho(pos);
            }

            if (datos[pos] <= datos[hijoMenor]) {
                return;
            }

            intercambiar(pos, hijoMenor);
            pos = hijoMenor;
        }
    }

public:
    MinHeap(long long capacidad) {
        this->capacidad = capacidad;
        this->cantidad = 0;
        this->datos = new T[capacidad];
    }

    ~MinHeap() {
        delete[] datos;
    }

    bool esVacio() {
        return cantidad == 0;
    }

    long long tamanio() {
        return cantidad;
    }

    void insertar(T valor) {
        if (cantidad == capacidad) {
            return;
        }

        datos[cantidad] = valor;
        flotar(cantidad);
        cantidad++;
    }

    T obtenerMinimo() {
        if (esVacio()) {
            cout << "Error: el heap esta vacio" << endl;
            return T{};
        }

        return datos[0];
    }

    T eliminarMinimo() {
        if (esVacio()) {
            cout << "Error: el heap esta vacio" << endl;
            return T{};
        }

        T minimo = datos[0];

        datos[0] = datos[cantidad - 1];
        cantidad--;

        if (cantidad > 0) {
            hundir(0);
        }

        return minimo;
    }

    void imprimir() {
        for (long long i = 0; i < cantidad; i++) {
            cout << datos[i] << " ";
        }
        cout << endl;
    }
};