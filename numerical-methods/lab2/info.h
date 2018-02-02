#ifndef INFO_H
#define INFO_H


class Info
{
public:
    Info();
    double getErrorIter() const;
    void setErrorIter(double value);

    int getIterNumIter() const;
    void setIterNumIter(int value);

    double getErrorTangent() const;
    void setErrorTangent(double value);

    int getIterNumTangent() const;
    void setIterNumTangent(int value);

    double getRootValueIter() const;
    void setRootValueIter(double value);

    double getRootValueTangent() const;
    void setRootValueTangent(double value);

private:
    double rootValueIter;
    double rootValueTangent;
    double errorIter; // error using iteration precision method
    int iterNumIter; //number of iterations using iteration precision method
    double errorTangent; // error using tangent precision method
    int iterNumTangent;//number of iterations using tangent precision method
};

#endif // INFO_H
