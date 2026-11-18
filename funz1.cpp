#include "funz1.h"

netpacket *leggiDATA(const char nomefile[],int &d){
    ifstream myFile(nomefile);
    netpacket *V=NULL;
    int conta;
    int goodPack=0;
    int badPack=0;
    netpacket appo;
    myFile.is_open();
    if(!myFile.is_open()){
        cout<<"Errore apertura file di lettura"<<endl;
        return NULL;
    }
    myFile>>appo.time>>appo.db>>appo.data;
    while(!myFile.eof()){
        conta++;
        myFile>>appo.time>>appo.db>>appo.data;
    }
    myFile.clear();
    myFile.seekg(0);
    cout<<"Sono stati caricati "<<conta<<" pacchetti"<<endl;
    V=new netpacket[conta];
    for(int i=0;i<conta;i++){
        myFile>>V[i].time>>V[i].db>>V[i].data;
        if(V[i].db>=90){
            goodPack++;
        }
        else{
            badPack++;
        }
    }
    myFile.close();
    cout<<"All'interno del file sono presenti "<<goodPack<<" di buona qualita' e "<<badPack<<" di pessima qualita'."<<endl;
    ofstream Mio("risultati.dat");
    Mio.is_open();
    if(!Mio.is_open()){
	    cout<<"Errore apertura file di scrittura"<<endl;
	    return NULL;
    }
    Mio<<"Il numero di pacchetti totali è: "<<conta<<". Di questi "<<goodPack<<" sono di buona qualità e "<<badPack<<" sono di pessima qualità."<<endl<<endl;
    Mio.close();
    d=conta;
    return V;
}
void scambia(netpacket&A,netpacket&B){
    netpacket C=A;
    A=B;
    B=C;
}
void Eliminapacchetto(netpacket* V, int& d){
    ofstream Mio("Corrotti.dat");
    Mio.is_open();
    if(!Mio.is_open()){
        cout<<"Errore seconda apertura file di scrittura"<<endl;
    }
    Mio<<"Pacchetti eliminati: "<<endl;
        for(int i=0;i<d;i++){
            if(V[i].db<90){
                Mio<<V[i].time<<" "<<V[i].db<<" "<<V[i].data<<endl;
		for(int j=i;j<d;j++){
                	scambia(V[j],V[j+1]);
		}
		i--;
		d--;
           }
        }
    }
int findmin(netpacket* V, int low, int high){
    int valMin=V[low].time;
    int posMin=low;

    for(int i=low+1; i<=high; i++){
        if(V[i].time<valMin){
            valMin = V[i].time;
            posMin = i;
        }
    }

    return posMin;
}
void ordTimeStamp(netpacket* V, int low, int high){
    int posmin;
    for(int i=low;i<high;i++){
        posmin=findmin(V,i,high);
        scambia(V[i],V[posmin]);
    }
}
void stampa(netpacket* V, int d){
	ofstream Mio("risultati.dat");
	Mio.is_open();
	if(!Mio.is_open()){
		cout<<"Errore terza apertura file di scrittura"<<endl;
	}
	else{
		cout<<"I primi 5 valori dopo il riordinamento sono:"<<endl;
		Mio<<"I primi 5 valori dopo il riordinamento sono:"<<endl;
		for(int i=0;i<5;i++){
			cout<<"tempo="<<V[i].time<<setw(20)<<"qualità="<<V[i].db<<setw(20)<<"carattere="<<V[i].data<<endl;
			Mio<<"tempo="<<V[i].time<<setw(20)<<"qualità="<<V[i].db<<setw(20)<<"carattere="<<V[i].data<<endl;
		}
		cout<<endl<<"Gli ultimi 5 valori dopo il riordinamento sono:"<<endl;
		Mio<<endl<<"Gli ultimi 5 valori dopo il riordinamento sono:"<<endl;
		for(int i=d-5;i<d;i++){
			cout<<"tempo="<<V[i].time<<setw(20)<<"qualità="<<V[i].db<<setw(20)<<"carattere="<<V[i].data<<endl;
                        Mio<<"tempo="<<V[i].time<<setw(20)<<"qualità="<<V[i].db<<setw(20)<<"carattere="<<V[i].data<<endl;
		}
	}
	Mio.close();
}
void printMex(netpacket*V, int d){
	ofstream Mio("messaggio.out");
	Mio.is_open();
	if(!Mio.is_open()){
		cout<<"Errore quarta apertura file di scrittura"<<endl;
	}
	for(int i=0;i<d;i++){
		if(V[i].data=='?'){
			cout<<'\n';
			Mio<<'\n';
		}
		else if(V[i].data=='#'){
			cout<<' ';
			Mio<<' ';
		}
		else{
			cout<<V[i].data;
			Mio<<V[i].data;
		}
	}
}	
