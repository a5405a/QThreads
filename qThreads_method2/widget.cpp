#include "widget.h"
#include "ui_widget.h"


//https://blog.csdn.net/qq_33485434/article/details/81742564
//https://blog.csdn.net/zhangbinsijifeng/article/details/50032471
//https://openhome.cc/Gossip/Qt4Gossip/StopThread.html



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





