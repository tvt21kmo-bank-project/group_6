#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    olioPaaSivu = new paaSivu;




}

MainWindow::~MainWindow()
{
    delete ui;
    ui = nullptr;

    delete olioPaaSivu;
    olioPaaSivu = nullptr;
}

void MainWindow::on_jatka_clicked()
{
   // this->hide();                         // piilotetaan nykyinen sivu
    olioPaaSivu->show();                    // avataan pääsivu
    //olioQtimer->start(1000);
  //  olioQtimer2->start(1000;

    Timer2 * olioTimer2;
   olioTimer2 = new Timer2;

   olioTimer2->Timerkayntiin();


    qDebug()<<olioTimer2->timerCounter3;

   if (olioTimer2->timerCounter3 == olioTimer2->timerAika3){
       qDebug()<<"paasivu suljettu";
       olioPaaSivu->paaSivuSulku();
   }

}
