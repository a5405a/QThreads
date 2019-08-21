#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

//doWork定义了线程要执行的操作
void Dialog::doWork(int parameter)
{
    qDebug()<<"receive the execute signal---------------------------------";
    qDebug()<<"     current thread ID:"<<QThread::currentThreadId();

    //for(int i = 0;i!=1000000;++i)
    while(true)
    {
        for(int i = 0;i<0x10000000;++i)
        {};
        qDebug()<<"      finish the work and sent the resultReady signal\n";
//          ++parameter;
//        if (jumpLoop)
//        {
//            jumpLoop = false;
//            workerThread.quit();
//            return;
//        }
    }
    //发送结束信号
    //qDebug()<<"      finish the work and sent the resultReady signal\n";
    //emit resultReady(parameter);

}
void Dialog::stopProcessFunc()
{
    jumpLoop = true;
//    workerThread.quit();
    //发送结束信号
    qDebug()<<"      finish the work and sent the resultReady signal\n";
}
