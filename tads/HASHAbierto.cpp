
#include <string>

using namespace std;


struct Nodo{
    int clave[26];
    int voy;
    Nodo * sig;
    
};

class TablaHash {
private:

    Nodo** tabla;
    int capacidad;
    int cantidadBuckets;
    int maximo;

    void llenar_clave(int* clave, string palabra){
        
        for(int i =0; i<palabra.length() ; i++){
            int pos = palabra[i]- 97;
            clave[pos] ++;
        };

    };
    
    int funcionHash(int* clave){
        
        long long ret = 0;
        
        for(int i= 0; i<26; i++){
            for(int j = clave[i] ; j > 0; j--){
                ret = ( ret*31  + (i + 97)) % capacidad;
             };
        };

        ret = ret % capacidad;
        return ret;

    };

public:

    TablaHash* crear(int cantElementosMax){
        TablaHash* ret = new TablaHash;
        ret->cantidadBuckets = 0;
        ret->maximo = 0;
        ret->capacidad = cantElementosMax / 0.6 + 1;
        ret->tabla = new Nodo* [ret->capacidad];
        for( int i = 0 ; i < ret->capacidad ; i++ ){
            ret->tabla[i] = NULL;
        };
        return ret; 
    };
    
    void agregar(string palabra, TablaHash * tabla){
        int clave[26] = {};
        llenar_clave(clave,palabra);

        int pos = funcionHash(clave);
        Nodo * actual = tabla->tabla[pos];
        Nodo * nuevo = new Nodo;
        while(actual != NULL && !mismaClave(actual->clave, clave)){
            actual = actual->sig;
        }


         if(actual == NULL){
            Nodo * nuevo = new Nodo;

                for(int i = 0; i < 26; i++){
                    nuevo->clave[i] = clave[i];
                }

            nuevo->sig = tabla->tabla[pos];
            nuevo->voy = 1;
            tabla->tabla[pos] = nuevo;
            tabla->cantidadBuckets++;

            actual = nuevo;
        }  else{
            actual->voy++;
        }

        if(actual->voy > tabla->maximo){
            tabla->maximo = actual->voy;
        }

    }

    int darMax(TablaHash* tabla){
        return tabla->maximo;
    };

    int darCantBuckets(TablaHash* tabla){
        return tabla->cantidadBuckets;
    }
    

    bool mismaClave(int* PalA, int* PalB){
        for(int i = 0; i < 26; i++){
            if(PalA[i] != PalB[i]){
                return false;
            }
        }
        return true;
    }

    int cantEnBucket(string pal, TablaHash* tabla ){
       
        int clave[26] = {};
        llenar_clave(clave,pal);
        int pos = funcionHash(clave);
        
        Nodo* actual = tabla->tabla[pos];
        while(actual!= NULL){
            if(mismaClave(actual->clave,clave)){
                return actual->voy;
            }
            actual= actual->sig;
        }
        return 0;

    }



};