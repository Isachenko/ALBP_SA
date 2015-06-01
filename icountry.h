#ifndef ICOUNTRY_H
#define ICOUNTRY_H

#include <QString>

class ICountry
{
public:
    ICountry();
    virtual ~ICountry() = 0;

    virtual double getFitnessValue() = 0;
    virtual void makeSimilarTo(ICountry *country) = 0;
};

#endif // ICOUNTRY_H
