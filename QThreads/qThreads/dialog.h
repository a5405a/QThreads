#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include <QThread>


namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private:
    Ui::Dialog *ui;




public slots:
        //doWork定义了线程要执行的操作
    void doWork(int parameter);

    //SLOT : Stop loop process
    void stopProcessFunc();


//线程完成工作时发送的信号
signals:
    void resultReady(const int result);


public:
        bool jumpLoop = false;

};

#endif // DIALOG_H
