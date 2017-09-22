#include "appstore.h"
#include "ui_appstore.h"
#include <cstdio>
#include <iostream>
#include <QProcess>
#include <thread>
#include <chrono>

AppStore::AppStore(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AppStore){

    ui->setupUi(this);
}

AppStore::~AppStore(){

    delete ui;
}

void AppStore::on_btSearch_clicked(){
    QString program = "pacman";
    QStringList arguments;
    arguments << "-Ssq" << ui->textPacName->text();

    ui->listWidget->clear();

    QProcess *myProcess = new QProcess();
    myProcess->start(program, arguments);
    myProcess->waitForFinished();

    std::vector<QString> vet;
    QString res = myProcess->readAllStandardOutput();
    QStringList temp = res.split('\n');
    ui->listWidget->addItems(temp);
}

void AppStore::on_btInstall_clicked(){
    QString program = "pkexec";
    QStringList arguments;
    QString package = ui->listWidget->selectedItems().takeFirst()->text();
    arguments << "pacman" << "-S" << "--noconfirm" << package;
    QString t = arguments.join(" ");
    std::cout << t.toStdString() << std::endl;
    QProcess *myProcess = new QProcess();
    myProcess->start(program, arguments);
    //myProcess->waitForStarted();
//    ui->listWidget->clear();
//    while(myProcess->waitForStarted()){
//        if(myProcess->canReadLine()) ui->listWidget->addItem(myProcess->readLine(50));
//        std::this_thread::sleep_for(std::chrono::nanoseconds(5000));
//        if(myProcess->state() == QProcess::NotRunning){
//            break;
//        }
//    }
    myProcess->waitForFinished();

    ui->listWidget->clear();
    ui->listWidget->addItems(QStringList{"Package installed: ", package});
}
