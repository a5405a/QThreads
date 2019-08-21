#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include<QDebug>

class MyThread : public QThread
{
public:
    MyThread();


public:
    bool jumpOut = false;

protected:
    void run() override;
};

#endif // MYTHREAD_H
