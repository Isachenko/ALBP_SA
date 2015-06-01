#ifndef ALBPGRAPH_H
#define ALBPGRAPH_H

#include <QList>
#include <QMap>
#include <QVector>
#include <QSet>

#include "albptask.h"

class ALBPGraph
{
private:
    int _cicleTime = 0;
    QVector<ALBPTask*> _tasks;
    QMap<ALBPTask*, QList<ALBPTask*> > _taskPredcessors;
    QMap<ALBPTask*, QList<ALBPTask*> > _taskSuccessors;

public:
    ALBPGraph();
    ~ALBPGraph();
    ALBPGraph* readFromFile(const QString filename);

    QSet<ALBPTask*> getOpenTasks(QSet<ALBPTask*> complitedTasks = QSet<ALBPTask*>());

    int getPredcessorsCount(ALBPTask* task);
    int getSuccessorsCount(ALBPTask* task);

    int getTaskCount();


    int cicleTime() const;
    void setCicleTime(int cicleTime);
};

#endif // ALBPGRAPH_H
