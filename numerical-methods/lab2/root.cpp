#include "root.h"
#include <iostream>
#include <utility>
#include <string>

using namespace std;

Root::Root()
{
    double eps = 0.01;
    for(int i = 0; i < 5; i++){
         epsilonsInfo.insert( pair<double, Info*>(eps,new Info));
         eps*=0.001;
    }
//    eps = 0.01;
//    for(int i = 0; i < 5; i++){
//       cout<< epsilonsInfo.find(eps)->first<<endl;
//       eps*=0.001;
//    }
}

double Root::getValue() const
{
    return value;
}

void Root::setValue(double value)
{
    this->value = value;
}

double Root::getQ() const
{
    return q;
}

void Root::setQ(double value)
{
    q = value;
}

Info Root::getEps2() const
{
    return eps2;
}

void Root::setEps2(const Info &value)
{
    eps2 = value;
}

Info Root::getEps5() const
{
    return eps5;
}

void Root::setEps5(const Info &value)
{
    eps5 = value;
}

Info Root::getEps8() const
{
    return eps8;
}

void Root::setEps8(const Info &value)
{
    eps8 = value;
}

Info Root::getEps11() const
{
    return eps11;
}

void Root::setEps11(const Info &value)
{
    eps11 = value;
}

double Root::getA() const
{
    return a;
}

void Root::setA(double value)
{
    a = value;
}

double Root::getB() const
{
    return b;
}

void Root::setB(double value)
{
    b = value;
}

bool Root::getDerivativeIsNegative() const
{
    return derivativeIsNegative;
}

void Root::setDerivativeIsNegative(bool value)
{
    derivativeIsNegative = value;
}

double Root::getMinDeriv() const
{
    return minDeriv;
}

void Root::setMinDeriv(double value)
{
    minDeriv = value;
}

double Root::getMaxDeriv() const
{
    return maxDeriv;
}

void Root::setMaxDeriv(double value)
{
    maxDeriv = value;
}

std::map<double, Info *> Root::getEpsilonsInfo()
{
    return epsilonsInfo;
}
