#include "funz1.h"

int main(){
	netpacket* Pack;
	int dim=0;
	Pack=leggiDATA("pacchetti.dat",dim);
	Eliminapacchetto(Pack,dim);
	ordTimeStamp(Pack,0,dim);
	stampa(Pack,dim);
	printMex(Pack,dim);

	return 0;
}
