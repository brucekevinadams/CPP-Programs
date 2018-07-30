#include <cmath>
#include <iostream>
using namespace std;

double normal(double u, double sig, double x){
    return (1.0/2.0)*(1.0 + erf((x-u)/(sig*pow(2.0,0.5))));
}


int main() {
    cout.precision(2);
    cout<<fixed<<(1.0 - normal(70,10,80))*100.0<<endl<<(1.0-normal(70,10,60))*100.0<<endl<<normal(70,10,60)*100.0;
    return 0;
}