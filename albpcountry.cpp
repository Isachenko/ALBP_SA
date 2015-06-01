#include "albpcountry.h"

ALBPGraph* ALBPCountry::_graph = nullptr;

ALBPCountry::ALBPCountry() :
    ICountry()
{

}

ALBPCountry::~ALBPCountry()
{
}

ICountry *ALBPCountry::createRandom()
{
    ALBPCountry* albpCountry = new ALBPCountry();
    for(int i = 0; i < graph()->getTaskCount(); ++i) {
        int randomRule = qrand() % _maxRuleValue;
        albpCountry->_rules.append(randomRule);
    }
    return albpCountry;
}

double ALBPCountry::getFitnessValue()
{
    QVector<int> workers;
    QSet<ALBPTask*> complitedTasks = QSet<ALBPTask*>();
    QSet<ALBPTask*> openTasks;
    workers.append(0);
    for(int  i = 0; i < graph()->getTaskCount(); ++i) {
        openTasks = _graph->getOpenTasks(complitedTasks);
        ALBPTask* taskToAssign;
        int rule = _rules.at(i);
        double minTime = 99999;
        double maxTime = -1;
        int maxPredcCount = -1;
        int maxSucCount = -1;
        switch (rule) {
        case 0:
            foreach (ALBPTask* task, openTasks) {
                if (task->time() < minTime) {
                    taskToAssign = task;
                    minTime = task->time();
                }
            }
            break;
        case 1:
            foreach (ALBPTask* task, openTasks) {
                if (task->time() > maxTime) {
                    taskToAssign = task;
                    maxTime = task->time();
                }
            }
            break;
        case 2:
            foreach (ALBPTask* task, openTasks) {
                int predcCoutn = _graph->getPredcessorsCount(task);
                if (predcCoutn > maxPredcCount) {
                    taskToAssign = task;
                    maxPredcCount = predcCoutn;
                }
            }

            break;
        case 3:
            foreach (ALBPTask* task, openTasks) {
                int sucCoutn = _graph->getSuccessorsCount(task);
                if (sucCoutn > maxSucCount) {
                    taskToAssign = task;
                    maxSucCount = sucCoutn;
                }
            }

            break;
        default:
            break;
        }
        if ((workers.at(workers.size() - 1) + taskToAssign->time()) <= _graph->cicleTime()) {
            workers[(workers.size() - 1)] += taskToAssign->time();
        } else {
            workers.append(taskToAssign->time());
        }
        complitedTasks.insert(taskToAssign);
    }
    double cicleTime = _graph->cicleTime();
    double cost = workers.count();
    foreach(int time, workers) {
        cost += (cicleTime - (double)time) / cicleTime;
    }
    cost = 1/cost;
    return cost;
}

void ALBPCountry::makeSimilarTo(ICountry *country)
{
    ALBPCountry* albpCountry = static_cast<ALBPCountry*>(country);
    for(int i = 0; i < _graph->getTaskCount(); ++i) {
        int magic = qrand() % 2;
        if (magic != 0) {
            this->_rules[i] = albpCountry->_rules.at(i);
        }
    }
}

ALBPCountry *ALBPCountry::getRandomNeigbour()
{
    ALBPCountry *neigbour = new ALBPCountry();
    neigbour->_rules = this->_rules;

    int index = qrand() % neigbour->_rules.size();
    int magic = qrand() % 2;
    if (magic) {
        neigbour->_rules[index] += 1;
        if (neigbour->_rules[index] >= _maxRuleValue) {
            neigbour->_rules[index] = 0;
        }
    } else {
        neigbour->_rules[index] -= 1;
        if (neigbour->_rules[index] < 0) {
            neigbour->_rules[index] = _maxRuleValue-1;
        }
    }
    return neigbour;
}

QString ALBPCountry::toString()
{
    QString string("task = {");

    QVector<int> workers;
    QSet<ALBPTask*> complitedTasks = QSet<ALBPTask*>();
    QSet<ALBPTask*> openTasks;
    workers.append(0);
    for(int  i = 0; i < graph()->getTaskCount(); ++i) {
        openTasks = _graph->getOpenTasks(complitedTasks);
        ALBPTask* taskToAssign;
        int rule = _rules.at(i);
        double minTime = 99999;
        double maxTime = -1;
        int maxPredcCount = -1;
        int maxSucCount = -1;
        switch (rule) {
        case 0:
            foreach (ALBPTask* task, openTasks) {
                if (task->time() < minTime) {
                    taskToAssign = task;
                    minTime = task->time();
                }
            }
            break;
        case 1:
            foreach (ALBPTask* task, openTasks) {
                if (task->time() > maxTime) {
                    taskToAssign = task;
                    maxTime = task->time();
                }
            }
            break;
        case 2:
            foreach (ALBPTask* task, openTasks) {
                int predcCoutn = _graph->getPredcessorsCount(task);
                if (predcCoutn > maxPredcCount) {
                    taskToAssign = task;
                    maxPredcCount = predcCoutn;
                }
            }

            break;
        case 3:
            foreach (ALBPTask* task, openTasks) {
                int sucCoutn = _graph->getSuccessorsCount(task);
                if (sucCoutn > maxSucCount) {
                    taskToAssign = task;
                    maxSucCount = sucCoutn;
                }
            }

            break;
        default:
            break;
        }
        if ((workers.at(workers.size() - 1) + taskToAssign->time()) <= _graph->cicleTime()) {
            workers[(workers.size() - 1)] += taskToAssign->time();
        } else {
            string += "} summury time = " + QString::number(workers[(workers.size() - 1)]) + "\ntask = {";
            workers.append(taskToAssign->time());
        }
        string += QString::number(taskToAssign->number()) + "(time: " + QString::number(taskToAssign->time()) + ") ";
        complitedTasks.insert(taskToAssign);
    }
    string += "} time = " + QString::number(workers[(workers.size() - 1)]) + "\ntotal workers count: " + QString::number(workers.size()) + "\n";
    return string;
}

