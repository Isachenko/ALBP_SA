#ifndef ALBPASALGORITHM_H
#define ALBPASALGORITHM_H
#include "isaalgorithm.h"
#include "albpcountry.h"


class ALBPASAlgorithm: public ISAAlgorithm
{
public:
    ALBPASAlgorithm();
    ~ALBPASAlgorithm();


    virtual ICountry *getFirstSolutin();
    virtual ICountry* getRandomNeigbour(ICountry *Country);


};

#endif // ALBPASALGORITHM_H
