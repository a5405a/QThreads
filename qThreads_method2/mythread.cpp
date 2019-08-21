#include "mythread.h"

#include <qcoreapplication.h>
#include <QApplication>

void threadProcess()
{

    qDebug()<<"myThreadSlot() start to execute";
    qDebug()<<"     current thread ID:"<<QThread::currentThreadId()<<'\n';


    while(true)
    {
//        QCoreApplication::processEvents();
        for(int i = 0;i<0x10000000;++i)
        {
            QApplication::processEvents();
//            QCoreApplication::processEvents();
        }

        qDebug()<<"      finish the work and sent the resultReady signal\n";

    }

}


MyThread::MyThread()
{
    jumpOut = false;
}

void MyThread::run()
{

    qDebug()<<"myThreadSlot() start to execute";
    qDebug()<<"     current thread ID:"<<QThread::currentThreadId()<<'\n';

    while(true)
    {
//        QCoreApplication::processEvents();

        if (jumpOut)
        {
            qDebug()<<"Stop the work!!\n";
            jumpOut = false;
            break;
        }

        for(int i = 0;i<0x10000000;++i)
        {}


        qDebug()<<"      finish the work and sent the resultReady signal\n";

    }

    //threadProcess();

    exec();
}
