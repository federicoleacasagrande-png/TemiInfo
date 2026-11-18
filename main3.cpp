#include "funz3.h"

int main(){
    misura*K;
    int dim;
    K=leggiDati("posizioni.in",dim);

    EliminaEl(K,dim);

    selSort(K,0,dim);

    return 0;
}
