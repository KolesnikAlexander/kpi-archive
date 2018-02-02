#ifndef ROOT_H
#define ROOT_H

#include "info.h"
#include <map>

class Root
{
public:
    Root();
    double getValue() const;
    void setValue(double value);

    double getQ() const;
    void setQ(double value);

    Info getEps2() const;
    void setEps2(const Info &value);

    Info getEps5() const;
    void setEps5(const Info &value);

    Info getEps8() const;
    void setEps8(const Info &value);

    Info getEps11() const;
    void setEps11(const Info &value);

    double getA() const;
    void setA(double value);

    double getB() const;
    void setB(double value);


    bool getDerivativeIsNegative() const;
    void setDerivativeIsNegative(bool value);

    double getMinDeriv() const;
    void setMinDeriv(double value);

    double getMaxDeriv() const;
    void setMaxDeriv(double value);

    std::map<double, Info *> getEpsilonsInfo();

private:
    double value;
    double q;
    double a;
    double b;
    double minDeriv;
    double maxDeriv;
    bool derivativeIsNegative;
    std::map<double, Info*> epsilonsInfo;
    Info eps2;
    Info eps5;
    Info eps8;
    Info eps11;
    Info eps14;
};

#endif // ROOT_H
