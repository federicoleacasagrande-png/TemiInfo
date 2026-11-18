#include "funz2.h"

punto *leggiPunto(const char nomefile[], int&d){
    punto*V=NULL;
    ofstream Mio("risultati.dat");
    int conta=0;
    punto appo;
    ifstream myFile(nomefile);
    myFile.is_open();
    if(!myFile.is_open()){
        cout<<"Errore apertura file di lettura"<<endl;
        return NULL;
    }
    myFile>>appo.x>>appo.y>>appo.m;
    while(!myFile.eof()){
        conta++;
        myFile>>appo.x>>appo.y>>appo.m;
    }
    V=new punto[conta];
    d=conta;
    myFile.clear();
    myFile.seekg(0);
    Mio.is_open();
    if(!Mio.is_open()){
        cout<<"Errore prima apertura file di scrittura"<<endl;
        return NULL;
    }
    cout<<"Sono stati caricati "<<conta<<" punti"<<endl;
    Mio<<"Sono stati caricati "<<conta<<" punti"<<endl;
    for(int i=0;i<conta;i++){
        myFile>>V[i].x>>V[i].y>>V[i].m;
        cout<<V[i].x<<" "<<V[i].y<<" "<<V[i].m<<endl;
        Mio<<"Ascissa="<<V[i].x<<setw(20)<<" Ordinata="<<V[i].y<<setw(20)<<" Massa="<<V[i].m<<endl;
    }
    cout<<endl;
    Mio<<endl;
    Mio.close();
    myFile.close();
    return V;
}
void minAsc(punto*V,int d){
    int min=V[0].x;
    int posmin=0;
    for(int i=0;i<d-1;i++){
        if(V[i].x<min){
            min=V[i].x;
            posmin=i;
        }
    }
    cout<<"Il punto con il valore dell'ascissa più basso nel file ha posizione e valore rispettivamente: "<<posmin<<" "<<min<<endl;
    ofstream Mio("risultati.dat",ios::app);
    Mio.is_open();
    if(!Mio.is_open()){
        cout<<"Errore seconda apertura file di scrittura"<<endl;
    }
    else{
        Mio<<"Il punto con il valore dell'ascissa più basso nel file ha posizione e valore rispettivamente: "<<posmin<<" "<<min<<endl;
    }
    cout<<endl;
    Mio<<endl;
    Mio.close();
}
void maxAsc(punto*V,int d){
    int max=V[0].x;
    int posmax=0;
    for(int i=0;i<d-1;i++){
        if(V[i].x>max){
            max=V[i].x;
            posmax=i;
        }
    }
    cout<<"Il punto con il valore dell'ascissa più alto nel file ha posizione e valore rispettivamente: "<<posmax<<" "<<max<<endl;
    ofstream Mio("risultati.dat",ios::app);
    Mio.is_open();
    if(!Mio.is_open()){
        cout<<"Errore terza apertura file di scrittura"<<endl;
    }
    else{
        Mio<<"Il punto con il valore dell'ascissa più alto nel file ha posizione e valore rispettivamente: "<<posmax<<" "<<max<<endl;
    }
    cout<<endl;
    Mio<<endl;
    Mio.close();
}
float CMx(punto*V,int d){
    float Mass=0;
    float Mxc=0;
    for(int i=0;i<d;i++){
        Mass+=V[i].m;
        Mxc+=(V[i].m*V[i].x);
    }
    return Mxc/Mass;
}
float CMy(punto*V,int d){
    float Mass=0;
    float Myc=0;
    for(int i=0;i<d;i++){
        Mass+=V[i].m;
        Myc+=(V[i].m*V[i].y);
    }
    return Myc/Mass;
}
float dist(punto V, float a, float b){
    return sqrt(pow(V.x-a,2)+(V.y-b,2));
}
int findMin(punto*v, int low, int high,float a, float b){
    float valMin=dist(v[low],a,b);
    int posMin=low;
    for(int i=low+1;i<high;i++){
        if(dist(v[i],a,b)<valMin){
            valMin=dist(v[i],a,b);
            posMin=i;
        }
    }
    return posMin;
}
void scambia(punto &a, punto &b){
    punto appo=a;
    a=b;
    b=appo;
}
void selSort(punto*v, int low, int high,float a, float b){
    ofstream Mio("risultati.dat",ios::app);
    Mio.is_open();
    if(!Mio.is_open()){
        cout<<"Errore quarta apertura file di scrittura"<<endl;
    }
    int posMin;
    cout<<"L'array ordinato in base alla distanza dal centro di massa è: "<<endl;
    Mio<<"L'array ordinato in base alla distanza dal centro di massa è: "<<endl;
    for(int i=low;i<=high;i++){
        posMin=findMin(v,i,high,a,b);
        scambia(v[i],v[posMin]);
        cout<<v[i].x<<" "<<v[i].y<<" "<<v[i].m<<" "<<dist(v[i],a,b)<<endl;
        Mio<<"Ascissa="<<v[i].x<<setw(20)<<" Ordinata="<<v[i].y<<setw(20)<<" Massa="<<v[i].m<<setw(20)<<" Distanza="<<dist(v[i],a,b)<<endl;
    }
    cout<<endl;
    Mio<<endl;
    Mio.close();
}
float media(punto*V, int d, float a, float b){
    ofstream Mio("risultati.dat",ios::app);
    Mio.is_open();
    if(!Mio.is_open()){
        cout<<"Errore quinta apertura file di scrittura"<<endl;
    }
    float somma=0;
    for(int i=0;i<d;i++){
        somma+=dist(V[i],a,b);
    }
    float means=somma/d;
    cout<<"La distanza media dal centro di massa è: "<<means<<endl<<endl;
    Mio<<"La distanza media dal centro di massa è: "<<means<<endl<<endl;
    Mio.close();
    return means;
}
float devstd(punto*V, int d, float a, float b){
    ofstream Mio("risultati.dat",ios::app);
    Mio.is_open();
    if(!Mio.is_open()){
        cout<<"Errore sesta apertura file di scrittura"<<endl;
    }
    float med=media(V,d,a,b);
    float somma=0;
    for(int i=0;i<d;i++){
        somma+=pow(dist(V[i],a,b)-med,2);
    }
    float devs=sqrt(somma/d);
    cout<<"La deviazione standard delle distanze dal centro di massa è: "<<devs<<endl<<endl;
    Mio<<"La deviazione standard delle distanze dal centro di massa è: "<<devs<<endl<<endl;
    Mio.close();
    return devs;
}
void Eliminapunti(punto*V,int&d,float a, float b){
    ofstream Mio("risultati.dat",ios::app);
    Mio.is_open();
    if(!Mio.is_open()){
        cout<<"Errore settima apertura file di scrittura"<<endl;
    }
    float ds=devstd(V,d,a,b);
    for(int i=0;i<d;i++){
        if(dist(V[i],a,b)>2*ds){
            for(int j=i;j<d-1;j++){
                scambia(V[j],V[j+1]);
            }
            i--;
            d--;
        }
    }
    cout<<"L'array dei punti nel file ripulito di tutti i punti a oltre 2 devstd ha ancora "<<d<<" punti, i quali sono: "<<endl;
    Mio<<"L'array dei punti nel file ripulito di tutti i punti a oltre 2 devstd ha ancora "<<d<<" punti, i quali sono: "<<endl;
    for(int i=0;i<d;i++){
        cout<<"Ascissa="<<V[i].x<<" Ordinata="<<V[i].y<<" Massa="<<V[i].m<<endl;
        Mio<<"Ascissa="<<V[i].x<<setw(20)<<"Ordinata="<<V[i].y<<setw(20)<<"Massa="<<V[i].m<<endl;
    }
    Mio.close();
}
