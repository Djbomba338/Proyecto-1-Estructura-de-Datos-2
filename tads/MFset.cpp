#ifndef MFSET_H
#define MFSET_H

class MFSet {
    private:
    int * padre;
    int * elementos; 
    int largo;

    public:
    MFSet(int n) {
        this->largo = n;
        this->padre = new int[this->largo];
        this->elementos = new int[this->largo];
        for (int i = 0; i < this->largo; i ++) {
            this->padre[i] = i;
            this->elementos[i] = 1;
        }
    }
    int representante(int a) {
        if (a == this->padre[a]) {
            return a;
        }
        this->padre[a] = representante(this->padre[a]); 
        return this->padre[a];
    }
    bool unir(int a, int b) { 
        int repA = representante(a);
        int repB = representante(b);
        if (repA == repB){
            return false;
        }
        if (this->elementos[repA] > this->elementos[repB]) { 
            this->padre[repB] = repA;
            this->elementos[repA] += this->elementos[repB];
        } else {
            this->padre[repA] = repB;
            this->elementos[repB] += this->elementos[repA];
        }
        return true;
    }
};

#endif