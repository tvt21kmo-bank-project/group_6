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
    olioPaaSivu->olioQtimer->start(1000);


    qDebug()<<"jatka painettu";

    //  olioPaaSivu->hide();
    //  this->show();
}
