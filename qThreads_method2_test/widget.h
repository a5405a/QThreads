#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>


#include<QThread>
#include<QDebug>

#include <QThread>
#include<QDebug>


namespace Ui {
class Widget;
}



class MyThread : public QThread
{
public:
    MyThread();


public:
    bool jumpOut = false;

protected:
    void run() override;
};



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
