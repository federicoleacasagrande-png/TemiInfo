#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

struct netpacket{
    int time;
    double db;
    char data;
};

netpacket *leggiDATA(const char nomefile[],int& d);
void Eliminapacchetto(netpacket* V, int& d);
void scambia(netpacket&A, netpacket&B);
int findmin(netpacket* V, int low, int high);
void ordTimeStamp(netpacket* V, int low, int high);
void stampa(netpacket* V,int d);
void printMex(netpacket* V, int d);
