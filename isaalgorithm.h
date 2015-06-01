#ifndef ISAALGORITHM_H
#define ISAALGORITHM_H
#include "icountry.h"

class ISAAlgorithm
{
private:
    const double _START_T = 0.001;
    const double _DELTA_T = 0.0001;
    const int _STEPS_FOR_ONE_ITERATION = 1000;

public:
    ISAAlgorithm();
    ~ISAAlgorithm();

    ICountry* run();
    virtual ICountry* getFirstSolutin() = 0;
    virtual ICountry* getRandomNeigbour(ICountry *Country) = 0;
};

#endif // ISAALGORITHM_H
