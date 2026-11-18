#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

struct punto{
    float x;
    float y;
    float m;
};

punto *leggiPunto(const char nomefile[], int&d);
void minAsc(punto*V,int d);
void maxAsc(punto*V,int d);
float CMx(punto*V,int d);
float CMy(punto*V,int d);
float dist(punto V, float a, float b);
int findMin(punto*v, int low, int high,float a, float b);
void scambia(punto &a, punto &b);
void selSort(punto*v, int low, int high,float a, float b);
float media(punto*V, int d, float a, float b);
float devstd(punto*V, int d, float a, float b);
void Eliminapunti(punto*V,int&d,float a, float b);
