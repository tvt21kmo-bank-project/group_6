#include "tyyppi.h"
#include "ui_tyyppi.h"
#include "mainwindow.h"

Tyyppi::Tyyppi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tyyppi)
{
    ui->setupUi(this);

    connect(olioTyyppiQtimer,SIGNAL(timeout()),this,SLOT(MyTimerTyyppiSlot()));
}

Tyyppi::~Tyyppi()
{
    delete ui;
    delete olioToimintoSivu;
    olioToimintoSivu = nullptr;
}

void Tyyppi::on_pushButtonCredit_clicked()
{
    qDebug()<<"credit painettu";
    this->close();
}


void Tyyppi::on_pushButtonDebit_clicked()
{
    qDebug()<<"debit painettu";
    qDebug()<<kayttajaTunnus;
    olioToimintoSivu = new Toimintosivu(kayttajaTunnus);
    //olioToimintoSivu->setKT(kayttajaTunnus);
    olioToimintoSivu->show();
    this->close();
    olioTyyppiQtimer->stop();
    timerCounter = 0;
    olioToimintosivuQtimer->start(1000);
}


void Tyyppi::on_pushButtonKirjauduUlos_clicked()
{
    this->close();
}

void Tyyppi::MyTimerTyyppiSlot()
{
    timerCounter++;
    qDebug()<<"TyyppiSivuTimer "<<timerCounter;

    if (timerCounter==timerAika2)
    {
        olioTyyppiQtimer->stop();
        qDebug()<<"Timer stop";
        timerCounter = 0;
        this->close();
    }
}

void Tyyppi::setKayttajaTunnus(const QString &newKayttajaTunnus)
{
    kayttajaTunnus = newKayttajaTunnus;
    olioTyyppiQtimer->start(1000);
}

