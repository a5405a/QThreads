#include "mainwindow.h"
#include "ui_mainwindow.h"





MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    //Andy added 0801

//    jumpLoop = false;

    //调用moveToThread将该任务交给workThread
    dialog->moveToThread(&workerThread);
    //operate信号发射后启动线程工作
    connect(this, SIGNAL(operate(const int)), dialog, SLOT(doWork(int)));
    //该线程结束时销毁
    connect(&workerThread, &QThread::finished, this, &QObject::deleteLater);
    //线程结束后发送信号，对结果进行处理
    //connect(worker, SIGNAL(resultReady(int)), this, SLOT(handleResults(int)));

    //Stop loop process
//    connect(this , SIGNAL(stopOperate()), dialog, SLOT(stopProcessFunc()));
    connect(this , SIGNAL(ui->pushButtonStop->click()), dialog, SLOT(stopProcessFunc()));

    //启动线程
    workerThread.start();

}

MainWindow::~MainWindow()
{

    workerThread.quit();
    workerThread.wait();

    delete dialog;

    delete ui;
}

void MainWindow::on_pushButtonStart_clicked()
{

    //发射信号，开始执行
    qDebug()<<"emit the signal to execute!---------------------------------";
    qDebug()<<"     current thread ID:"<<QThread::currentThreadId()<<'\n';
    emit operate(0);

}

void MainWindow::on_pushButtonStop_clicked()
{

    workerThread.quit();
//    //发送结束信号
    qDebug()<<"      finish the work and sent the resultReady signal\n";

    emit stopOperate();
}

