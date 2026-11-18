#include "funz2.h"

int main(){
    punto*X;
    int d;
    X=leggiPunto("punti.dat",d);

    minAsc(X,d);
    maxAsc(X,d);

    float Xcm=CMx(X,d);
    float Ycm=CMy(X,d);

    selSort(X,0,d,Xcm,Ycm);

    Eliminapunti(X,d,Xcm,Ycm);

    return 0;
}
