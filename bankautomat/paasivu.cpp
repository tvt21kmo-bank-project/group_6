#include "paasivu.h"
#include "ui_paasivu.h"

paaSivu::paaSivu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::paaSivu)
{
    ui->setupUi(this);
    olioQtimer = new QTimer;
    timerCounter = 0;

    connect(olioQtimer,SIGNAL(timeout()),this,SLOT(myTimerSlot()));
    olioQtimer->start(1000);
}

paaSivu::~paaSivu()
{
    delete ui;
    delete olioQtimer;
    olioQtimer = nullptr;
}

void paaSivu::on_kirjauduNappi_clicked()
{
    qDebug()<<"Kirjaudu painettu";
   // olioQtimer->start(1000);
}

void paaSivu::on_takaisinNappi_clicked()
{
    this->close();                                      // suljetaan pääsivu
    qDebug()<<"takaisin painettu";
}

void paaSivu::myTimerSlot()
{
    timerCounter++;
    qDebug()<<timerCounter;

    if (timerCounter==5)
    {
        olioQtimer->stop();
        qDebug()<<"Timer stop";
        timerCounter = 0;
        this->close();
    }
}
