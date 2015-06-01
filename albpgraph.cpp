#include "albpgraph.h"
#include <QFile>
#include <QSet>


int ALBPGraph::cicleTime() const
{
    return _cicleTime;
}

void ALBPGraph::setCicleTime(int cicleTime)
{
    _cicleTime = cicleTime;
}
ALBPGraph::ALBPGraph()
{

}

ALBPGraph::~ALBPGraph()
{

}

ALBPGraph *ALBPGraph::readFromFile(const QString filename)
{
    FILE* file = fopen(filename.toStdString().c_str(), "r");

    int tasksCount;

    fscanf(file, "%d %d", &tasksCount, &_cicleTime);
    for(int i = 0; i < tasksCount; ++i) {
        double time;
        fscanf(file, "%lf", &time);
        ALBPTask* task = new ALBPTask(time, i+1);
        _tasks.append(task);
    }
    for(int i = 0; i < tasksCount; ++i) {
        int predcessorsCount;
        fscanf(file, "%d", &predcessorsCount);

        for(int j = 0; j < predcessorsCount; ++j) {
            int predcessorNumber;
            fscanf(file, "%d", &predcessorNumber);
            ALBPTask* predcessor = _tasks.at(predcessorNumber);
            _taskPredcessors[_tasks.at(i)].append(predcessor);
            _taskSuccessors[predcessor].append(_tasks.at(i));
        }
    }

    fclose(file);
}

QSet<ALBPTask *> ALBPGraph::getOpenTasks(QSet<ALBPTask *> complitedTasks)
{
    QSet<ALBPTask *> openTasks;
    foreach(ALBPTask* task, _tasks) {
        if (complitedTasks.contains(task)) {
            continue;
        }
        bool isOpen = true;
        foreach(ALBPTask* predcessor, _taskPredcessors[task]) {
            if (!complitedTasks.contains(predcessor)) {
                isOpen = false;
            }
        }
        if (isOpen) {
            openTasks.insert(task);
        }
    }
    return openTasks;
}

int ALBPGraph::getPredcessorsCount(ALBPTask *task)
{
    return _taskPredcessors[task].count();
}

int ALBPGraph::getSuccessorsCount(ALBPTask *task)
{
    return _taskSuccessors[task].count();
}

int ALBPGraph::getTaskCount()
{
    return _tasks.size();
}

