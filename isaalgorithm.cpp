#include "isaalgorithm.h"

ISAAlgorithm::ISAAlgorithm()
{

}

ISAAlgorithm::~ISAAlgorithm()
{

}

ICountry* ISAAlgorithm::run()
{
    double t = _START_T;
    ICountry* solution = getFirstSolutin();
    double solutionValue = solution->getFitnessValue();
    while (t > 0) {
        for(int i = 0; i < _STEPS_FOR_ONE_ITERATION; ++i) {
            ICountry *neigbourSolution = getRandomNeigbour(solution);
            double neigbourSolutionValue = neigbourSolution->getFitnessValue();
            if (neigbourSolutionValue > solutionValue) {
                delete solution;
                solution = neigbourSolution;
                solutionValue = neigbourSolutionValue;
            } else {
                double delta = solutionValue - neigbourSolutionValue;
                double pow = delta / t;
                double e = exp(pow);
                double prob = 1 / e;
                double magic = (double)rand() / (double)RAND_MAX;
                if (magic < prob) {
                    delete solution;
                    solution = neigbourSolution;
                    solutionValue = neigbourSolutionValue;
                } else {
                    delete neigbourSolution;
                }
            }
        }
        t -= _DELTA_T;
    }
    return solution;
}


