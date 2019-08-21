#include "widget.h"
#include "ui_widget.h"


//https://blog.csdn.net/qq_33485434/article/details/81742564
//https://blog.csdn.net/zhangbinsijifeng/article/details/50032471
//https://openhome.cc/Gossip/Qt4Gossip/StopThread.html



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



Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);

//    myThrd = new MyThread;

    //该线程结束时销毁
//    connect(myThrd, &QThread::finished, this, &QObject::deleteLater);

//    connect(this,&Widget::operate,myThrd,&MyThread::myThreadSlot);

//    connect(myThrd,&MyThread::threadSignal,this,&Widget::threadProcess);



}

Widget::~Widget()
{

    myThrd.quit();
    myThrd.wait();

    delete ui;
}

void Widget::on_pushButtonStart_clicked()
{


//   emit operate();
    //启动该线程
    myThrd.jumpOut = false;
    myThrd.start();

}

void Widget::on_pushButtonStop_clicked()
{

   myThrd.jumpOut = true;
   myThrd.quit();
   myThrd.wait();


}





