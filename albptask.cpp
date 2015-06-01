#include "albptask.h"


double ALBPTask::time() const
{
    return _time;
}

void ALBPTask::setTime(double time)
{
    _time = time;
}

int ALBPTask::number() const
{
    return _number;
}

void ALBPTask::setNumber(int number)
{
    _number = number;
}
ALBPTask::ALBPTask(double time, int number) :
    _time(time),
    _number(number)
{
    
}

ALBPTask::~ALBPTask()
{
    
}


