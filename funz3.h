#include <iostream>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

struct misura{
    float t;
    float x;
    float y;
    float dscrx;
    float dscry;
    float de;
};

misura* leggiDati(const char nomefile[], int&d);
void scambia(misura&a,misura&b);
void EliminaEl(misura*V, int& d);
int findMin(misura*V, int low, int high);
void selSort(misura* V, int low, int high);
