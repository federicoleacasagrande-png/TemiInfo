#include "funz3.h"

misura* leggiDati(const char nomefile[], int&d){
    misura* V;
    int conta=0;
    misura appo;
    ifstream myfile(nomefile);
    ofstream Mio("risultati.dat");
    myfile.is_open();
    if(!myfile.is_open()){
        cout<<"Errore apertura file lettura"<<endl;
        return NULL;
    }
    myfile>>appo.t>>appo.x>>appo.y;
    while(!myfile.eof()){
        conta++;
        myfile>>appo.t>>appo.x>>appo.y;
    }
    myfile.clear();
    myfile.seekg(0);
    d=conta;
    V=new misura[conta];
    Mio.is_open();
    if(!Mio.is_open()){
        cout<<"Errore prima apertura file scrittura"<<endl;
        return NULL;
    }
    cout<<"L'array del file è composto da "<<conta<<" punti."<<endl;
    Mio<<"L'array del file è composto da "<<conta<<" punti:"<<endl;
    for(int i=0;i<conta;i++){
        myfile>>V[i].t>>V[i].x>>V[i].y;
        V[i].dscrx=V[i].x-(5*cos(2*V[i].t));
        V[i].dscry=V[i].y-(5*sin(2*V[i].t));
        V[i].de=sqrt(pow(V[i].dscrx,2)+pow(V[i].dscry,2));
        Mio<<"Tempo="<<V[i].t<<setw(10)<<"Ordinata="<<V[i].x<<setw(10)<<"Ascissa="<<V[i].y<<setw(10)<<"Discrepanza X="<<V[i].dscrx<<setw(10)<<"Discrepanza Y="<<V[i].dscry<<setw(10)<<"Discrepanza totale="<<V[i].de<<endl;
    }
    cout<<"Le prime 5-tuple dei primi 10 elementi del file sono:"<<endl;
    for(int i=0;i<10;i++){
        cout<<"Tempo="<<V[i].t<<setw(10)<<"Ordinata="<<V[i].x<<setw(10)<<"Ascissa="<<V[i].y<<setw(10)<<"Discrepanza X="<<V[i].dscrx<<setw(10)<<"Discrepanza Y="<<V[i].dscry<<endl;
    }
    myfile.close();
    Mio.close();
    return V;
}
void scambia(misura&a,misura&b){
    misura c=a;
    a=b;
    b=c;
}
void EliminaEl(misura*V, int& d){
    ofstream Mio("risultati.dat",ios::app);
    Mio.is_open();
    if(!Mio.is_open()){
        cout<<"Errore seconda apertura file scrittura"<<endl;
    }
    cout<<endl<<"Gli elementi presenti nel primo quadrante, i quali verranno eliminati, sono i seguenti:"<<endl;
    Mio<<endl<<"Gli elementi presenti nel primo quadrante, i quali verranno eliminati, sono i seguenti:"<<endl;
    for(int i=0;i<d;i++){
        if((V[i].x>0)&&(V[i].y>0)){
            cout<<"Tempo="<<V[i].t<<setw(10)<<"Ordinata="<<V[i].x<<setw(10)<<"Ascissa="<<V[i].y<<setw(10)<<"Discrepanza X="<<V[i].dscrx<<setw(10)<<"Discrepanza Y="<<V[i].dscry<<setw(10)<<"Discrepanza totale="<<V[i].de<<endl;
            Mio<<"Tempo="<<V[i].t<<setw(10)<<"Ordinata="<<V[i].x<<setw(10)<<"Ascissa="<<V[i].y<<setw(10)<<"Discrepanza X="<<V[i].dscrx<<setw(10)<<"Discrepanza Y="<<V[i].dscry<<setw(10)<<"Discrepanza totale="<<V[i].de<<endl;
            for(int j=i;j<d;j++){
                scambia(V[j],V[j+1]);
            }
            i--;
            d--;
        }
    }
    cout<<endl;
    Mio<<endl;
    Mio.close();
}
int findMin(misura*V, int low, int high){
    float valMin=V[low].de;
    int posMin=low;
    for(int i=low+1;i<high;i++){
        if(V[i].de<valMin){
            valMin=V[i].de;
            posMin=i;
        }
    }
    return posMin;
}
void selSort(misura* V, int low, int high){
    ofstream Mio("risultati.dat",ios::app);
    Mio.is_open();
    if(!Mio.is_open()){
        cout<<"Errore terza apertura file di scrittura"<<endl;
    }
    int posMin;
    for(int i=low;i<=high;i++){
        posMin=findMin(V,i,high);
        scambia(V[i],V[posMin]);
    }
    cout<<"Gli ultimi 10 elementi dell'array ordinato in ordine crescente in base alla discrepanza totale è: "<<endl;
    Mio<<"Gli ultimi 10 elementi dell'array ordinato in ordine crescente in base alla discrepanza totale è: "<<endl;
    for(int i=high-10;i<high;i++){
        cout<<"Tempo="<<V[i].t<<setw(10)<<"Ordinata="<<V[i].x<<setw(10)<<"Ascissa="<<V[i].y<<setw(10)<<"Discrepanza X="<<V[i].dscrx<<setw(10)<<"Discrepanza Y="<<V[i].dscry<<setw(10)<<"Discrepanza totale="<<V[i].de<<endl;
        Mio<<"Tempo="<<V[i].t<<setw(10)<<"Ordinata="<<V[i].x<<setw(10)<<"Ascissa="<<V[i].y<<setw(10)<<"Discrepanza X="<<V[i].dscrx<<setw(10)<<"Discrepanza Y="<<V[i].dscry<<setw(10)<<"Discrepanza totale="<<V[i].de<<endl;
    }
    cout<<endl;
    Mio<<endl;
    Mio.close();
}
