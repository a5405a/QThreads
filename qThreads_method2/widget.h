#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>


#include<QThread>
#include<QDebug>

#include "mythread.h"


namespace Ui {
class Widget;
}



//class MyThread : public QThread
//{
//    Q_OBJECT

//public:
//    MyThread(QObject* parent = nullptr);

//    //自定义发送的信号
////signals:
////    void myThreadSignal(const int);
////    //自定义槽
////signals:
////    void threadSignal();

////public slots:
////    void myThreadSlot(const int);


//protected:
//    void run() override;

//};


class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();


signals:
    void operate();


private slots:
    void on_pushButtonStart_clicked();

    void on_pushButtonStop_clicked();

private:
    Ui::Widget *ui;



public:
        MyThread myThrd;


//public:
//        void threadProcess();


};

#endif // WIDGET_H
