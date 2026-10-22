#ifndef MFSET_H
#define MFSET_H

class MFSet {
    private:
    int * padre;
    int * altura; 
    int largo;

    public:
    MFSet(int n) {
        this->largo = n;
        this->padre = new int[this->largo];
        this->altura = new int[this->largo];
        for (int i = 0; i < this->largo; i ++) {
            this->padre[i] = i;
            this->altura[i] = 0;
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
        if (this->altura[repA] > this->altura[repB]) { 
            this->padre[repB] = repA;
        } else if(this->altura[repA] < this->altura[repB]) {
            this->padre[repA] = repB;
        } else{
            this->padre[repA] = repB;
            this->altura[repB]++;
        }
        return true;
    }
};

#endif