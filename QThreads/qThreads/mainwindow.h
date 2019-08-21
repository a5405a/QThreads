#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include<QDebug>
#include<QThread>


//Andy added 0801
#include "dialog.h"



namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    //Andy added 0801
    QThread workerThread;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;






private slots:
        void on_pushButtonStart_clicked();
        void on_pushButtonStop_clicked();



private:
        Dialog *dialog = new Dialog;



//线程完成工作时发送的信号
signals:
            //发送信号触发线程
            void operate(const int);

            //Andy added 0801
            //Stop loop process
            void stopOperate();

};

#endif // MAINWINDOW_H
