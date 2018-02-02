#include "info.h"

Info::Info()
{

}

double Info::getErrorIter() const
{
    return errorIter;
}

void Info::setErrorIter(double value)
{
    errorIter = value;
}

int Info::getIterNumIter() const
{
    return iterNumIter;
}

void Info::setIterNumIter(int value)
{
    iterNumIter = value;
}

double Info::getErrorTangent() const
{
    return errorTangent;
}

void Info::setErrorTangent(double value)
{
    errorTangent = value;
}

int Info::getIterNumTangent() const
{
    return iterNumTangent;
}

void Info::setIterNumTangent(int value)
{
    iterNumTangent = value;
}

double Info::getRootValueIter() const
{
    return rootValueIter;
}

void Info::setRootValueIter(double value)
{
    rootValueIter = value;
}

double Info::getRootValueTangent() const
{
    return rootValueTangent;
}

void Info::setRootValueTangent(double value)
{
    rootValueTangent = value;
}
