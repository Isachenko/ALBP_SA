#ifndef ALBPTASK_H
#define ALBPTASK_H


class ALBPTask
{
    double _time;
    int _number = 0;

public:
    ALBPTask(double time, int number);
    ~ALBPTask();

    double time() const;
    void setTime(double time);
    int number() const;
    void setNumber(int number);
};

#endif // ALBPTASK_H
