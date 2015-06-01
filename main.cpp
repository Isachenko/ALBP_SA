#include <iostream>
#include "albpgraph.h"
#include "albpasalgorithm.h"

int main()
{
    std::cout << "Start" << std::endl;

    ALBPGraph* graph = new ALBPGraph();
    graph->readFromFile("problem10.txt");
    ALBPCountry::setGraph(graph);
    ISAAlgorithm* alogorithm = new ALBPASAlgorithm();
    ALBPCountry* solution = (ALBPCountry*) alogorithm->run();
    std::cout << solution->toString().toStdString();

    return 0;
}
