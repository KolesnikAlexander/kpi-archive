#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;

#define _USE_MATH_DEFINES
#define a 9.49
#define b 35

void calcMZ(double x, int &m, double &z){
    m = 0;
    while (pow(2, m) <= x) m++;
    while (pow(2, m) > x) m--;
    m++;

    z = x/pow(2, m);
}
void testCalcMZ(double x, int m, double z){
    cout << x <<" = 2^(" << m
         << ") * " << z <<endl;
}
 double calcD(double z){
     return (1-z)/(1+z);
 }
 double calcLk(int k, double d){
     return ((double)pow(d, 2*k-1))/(2*k-1);
 }
 double calcLkOptim(double &numerator, double &denominator, double const &dSqr, double const &denomStep){
     numerator *= dSqr;
     denominator += denomStep;
     return numerator/denominator;
 }

 double series(double d, double eps, int &n, double &r){
     int k = 1;
     double lk = d;
     double sum = d;

     double numerator  = d;
     double denominator = 1;
     double dSqr = d*d;
     double denomStep = 2;

     while (lk >= 4*eps) {
         lk = calcLkOptim(numerator, denominator, dSqr, denomStep);
         sum+=lk;
         k++;
     }

     r = lk;
     n = k;
     return sum;
 }

void task1(){
    double x = (a + b)/(double)2;
    double eps = 0.01;
    int m;
    double z;
    double d;
    calcMZ(x,m,z);
    d = calcD(z);

    cout <<setw(7) <<"eps"<<setw(5)<<"n"<<setw(10)<<"delta"<<setw(10)<<"r"<<endl;
    cout << std::scientific;
    std::cout.precision(2);

    int n;
    for(int i =0; i < 5; i++){
        double r;
        double sum = series(d,eps,n, r);
        double lnX = m*M_LN2 - 2*sum;

        cout <<eps<<" | "<< n << " | "<< abs(log(x) -  lnX)<< " | "<<r<<endl;
        eps = eps * 0.001;
    }
}

double nSeries(double d, int n, double &r){
    double lk = d;
    double sum = d;

    double numerator  = d;
    double denominator = 1;
    double dSqr = d*d;
    double denomStep = 2;

    for (int i = 2; i <= n; i++){
        lk = calcLkOptim(numerator, denominator, dSqr, denomStep);
        sum+=lk;
    }

    r = lk;
    return sum;
}
void task2(){
    int n = 5;
    double h = (b-a)/(double)10;

    cout <<setw(5) <<"x"<<setw(12)<<"delta"<<setw(10)<<"r"<<endl;

    for(int i = 0; i <= 10; i++){
        double x = a + h*i;
        int m;
        double z;
        double d;
        calcMZ(x,m,z);
        d = calcD(z);

        double r;
        double sum = nSeries(d, n, r);
        double lnX = m*M_LN2 - 2*sum;

        cout << x << " | "<< abs(log(x) -  lnX)<< " | "<<r<<endl;
    }
}

int main()
{
    task1();
    cout << "TASK 2:"<<endl;
    task2();

    return 0;
}
