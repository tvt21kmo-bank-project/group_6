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
    olioPaaSivu->show();

   MainWindow w;
    w.show();
}

