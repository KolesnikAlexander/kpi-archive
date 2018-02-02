#include "root.h"

#include <iostream>
#include <cstdlib>
#include <vector>
#include <math.h>

using namespace std;

vector<Root*> roots;

void fillData(){
    Root* root;

    root = new Root();
    root->setValue(-1.28);
    root->setA(-1.3);
    root->setB(-1.25);
    root->setQ(0.1502);
    root->setDerivativeIsNegative(false);
    root->setMinDeriv(1.872);
    root->setMaxDeriv(2.203);
    roots.push_back(root);

    root = new Root();
    root->setValue(-0.412);
    root->setA(-0.45);
    root->setB(-0.4);
    root->setQ(0.0387);
    root->setDerivativeIsNegative(true);
    root->setMinDeriv(1.193);
    root->setMaxDeriv(1.241);
    roots.push_back(root);

    root = new Root();
    root->setA(0.8);
    root->setB(0.85);
    root->setValue(0.827);
    root->setQ(0.12);
    root->setDerivativeIsNegative(false);
    root->setMinDeriv(2.823);
    root->setMaxDeriv(3.208);
    roots.push_back(root);

}

void setDisplay(){
    cout << std::scientific;
    std::cout.precision(2);
}

double f(double x){
    return x*x + x*x*x - sin(x) - 0.5;
}

double derivativeF(double x){
    return 2*x + 3*x*x - cos(x);
}

double phi(double x, Root* root){
    double maxDeriv = root->getMaxDeriv();
    if (!root->getDerivativeIsNegative())
        return x - (double)1/maxDeriv*(x*x + x*x*x -sin(x) - 0.5);
    else
        return x + (double)1/maxDeriv*(x*x + x*x*x -sin(x) - 0.5);
}

void iterMethod(double eps, double x0, Root* root){
    double x;
    double xNext = x0;
    double q = root->getQ();
    double error = 0;
    double k = q/(1-q);
    int n = 0;
    do{
         x = xNext;
         xNext = phi(x, root);
         n++;
         error = fabs(x - xNext)*k;

    }while ((error) > eps);

    Info* info = root->getEpsilonsInfo().find(eps)->second;
    info->setRootValueIter(xNext);
    info->setErrorIter(error);
    info->setIterNumIter(n);
}

void tangentMethod(double eps, double x0, Root* root){
    double x;
    double xNext = x0;
    double error = 0;
    double fValue;
    double minDeriv = root->getMinDeriv();
    int n = 0;
    do{
         x = xNext;
         fValue = f(x);
         xNext = x - fValue/derivativeF(x);
         error = fabs(x - xNext);
         n++;
    }while (fabs(fValue)/minDeriv > eps);
    Info* info = root->getEpsilonsInfo().find(eps)->second;
    info->setRootValueTangent(xNext);
    info->setErrorTangent(error);
    info->setIterNumTangent(n);
    }

void calcInfo(Root* root){
    double eps = 0.01;
    double x0 = root->getA();

    for(int i = 0; i < 5; i++){
        Info* info = root->getEpsilonsInfo().find(eps)->second;
        iterMethod( eps, x0, root);
        tangentMethod( eps, x0, root);
        eps*=0.001;
    }

}

void displayIter(){
    cout<<"ITERATION METHOD"<<endl;
    for(int i = 0; i < 3; i++){
        Root* root = roots.at(i);
        cout <<"Root " << i + 1 <<endl;

        double eps = 0.01;
        cout << "    eps" << "  |   " <<"root"<<"    |   "<<"delta"<<endl;
         for(int i = 0; i < 5; i++){
             Info* info = root->getEpsilonsInfo().find(eps)->second;
             cout << eps << " | " <<info->getRootValueIter()<< " | "<<info->getErrorIter()<<endl;
             eps*=0.001;
         }
    }
    cout<<endl;
}

void displayTangent(){
    cout<<"TANGENTS METHOD"<<endl;
    for(int i = 0; i < 3; i++){
        Root* root = roots.at(i);
        cout <<"Root " << i + 1 <<endl;

        double eps = 0.01;
        cout << "    eps" << "  |   " <<"root"<<"   |   "<<"delta"<<endl;
         for(int i = 0; i < 5; i++){
             Info* info = root->getEpsilonsInfo().find(eps)->second;
             cout << eps << " | " <<info->getRootValueTangent()<< " | "<<info->getErrorTangent()<<endl;
             eps*=0.001;
         }
    }
    cout<<endl;
}
void displayRateComparison(){
    cout<<"THE RATE OF CONVERGENCE"<<endl;
    for(int i = 0; i < 3; i++){
        Root* root = roots.at(i);
        cout <<"Root " << i + 1 <<endl;

        double eps = 0.01;
        cout << "    eps" << "  |" <<"Iter"<<"|"<<"Tangents"<<endl;
         for(int i = 0; i < 5; i++){
             Info* info = root->getEpsilonsInfo().find(eps)->second;
             cout << eps << " |  " <<info->getIterNumIter()<< " | "<<info->getIterNumTangent()<<endl;
             eps*=0.001;
         }
    }
    cout<<endl;
}

void displayResults(){
    displayIter();
    displayTangent();
    displayRateComparison();
}

int main()
{
    setDisplay();
    fillData();

    for(int i = 0; i < 3; i++){
        Root* root = roots.at(i);
        calcInfo(root);
    }
    displayResults();

    return 0;
}
