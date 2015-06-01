#include "albpasalgorithm.h"

ALBPASAlgorithm::ALBPASAlgorithm()
{

}

ALBPASAlgorithm::~ALBPASAlgorithm()
{

}

ICountry* ALBPASAlgorithm::getFirstSolutin()
{
    return ALBPCountry::createRandom();
}

ICountry *ALBPASAlgorithm::getRandomNeigbour(ICountry *Country)
{
    ALBPCountry* albCOuntry = static_cast<ALBPCountry*>(Country);
    return albCOuntry->getRandomNeigbour();
}

