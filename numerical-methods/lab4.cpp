#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;

//#define a -1
//#define b 15


// uncomment and set precision that is needed
void setDisplay(){
    cout << std::scientific;
    std::cout.precision(8);
}
double f(double x){
    return -exp(x)*(sin(x) + cos(x))/64;
}
//exact value calculated with a Newton-Leibniz formula
double integral(){
    double topBound = -exp(15)*sin(15)/64;
    double bottomBound = -exp(-1)*sin(-1)/64;
    return topBound - bottomBound;
}
double calcH(double eps, double m4, int &n){
double a = -1;
double b =15;
    double root4 = std::pow(180*eps/( (b-a)*fabs(m4)), 1./4.);
    double length = b - a;
    n = (int)(length/root4) + 1;
    if((n % 2) == 0){
        return length/n;
    }
    else{
        n++;
        return length/n;
    }
}

void simpsonsMethod(double n, double h, double &result){
    double a = -1;
    double b =15;

    double y0 = f(a);
    double yn = f(b);

    double sigma1 = 0;
    double sigma2 = 0;

    for(int i = 1;i <= n-1;i+=2){
        sigma1+=f(a+i*h);
    }
    for(int i = 2;i <= n-2;i+=2){
        sigma2+=f(a+i*h);
    }

    result = h*(y0 + yn + 4*sigma1 + 2*sigma2)/3;
}

void task1(double eps, double &delta){
    double m4 = exp(9*M_PI/2)/16; //max of fourth derivative(abs value)
    int n;
    double h = calcH(eps, m4, n);//step

    double result;
    simpsonsMethod(n, h, result);

    double integralValue = integral();
    delta = fabs(integralValue-result);

    cout <<"TASK 1: "<<endl;
    cout<<"M4 = "<<m4<<endl;
    cout<<"      eps      |       step     |     integral    |    delta"<<endl;
    cout<<eps<<" | "<<h<<" | "<<integralValue<<" | "<<delta<<endl;

}
void task2(double eps){
    double a = -1;
    double b =15;

    int n = (int)(1/std::pow(eps, 1./4.));
    if((n % 2) != 0)
        n++;
    double h = (b-a)/n;
    double result;

    double integral0;
    double integral1;

    simpsonsMethod(n, h, integral1);
    double rn;
    double delta;
    do{
        n*=2;
        h/=2;
        integral0 = integral1;
        simpsonsMethod(n, h, integral1);
        delta = fabs(integral1 - integral0);
        rn = delta/(15);
    }while(rn > eps);

    cout <<"TASK 2: "<<endl;
    cout<<"      eps      |       step     |    rn"<<endl;
    cout<<eps<<" | "<<h<<" | "<<rn<<endl;

    cout<<"delta:"<<delta<<endl;

}

int main()
{
    setDisplay();

    double eps = 0.0001;
    double delta;
    task1(eps, delta);
    task2(delta);

    return 0;
}
