#include "tyyppi.h"
#include "ui_tyyppi.h"
#include "mainwindow.h"

Tyyppi::Tyyppi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tyyppi)
{
    ui->setupUi(this);

   // connect(olioTyyppiQtimer,SIGNAL(timeout()),this,SLOT(MyTimerTyyppiSlot()));
}

Tyyppi::~Tyyppi()
{
    delete ui;
    delete olioToimintoSivu;
    olioToimintoSivu = nullptr;
}

void Tyyppi::on_pushButtonCredit_clicked()
{
    olioToimintoSivu = new Toimintosivu(kayttajaTunnus);
    qDebug()<<"credit painettu";
    Debit_Credit = 0;
    olioToimintoSivu->tarkistaTyyppi();
    olioToimintoSivu->show();
    this->close();
    olioTyyppiQtimer->stop();
    timerCounter = 0;
    olioToimintosivuQtimer->start(1000);

}


void Tyyppi::on_pushButtonDebit_clicked()
{
    qDebug()<<"debit painettu";
    qDebug()<<kayttajaTunnus;
    olioToimintoSivu = new Toimintosivu(kayttajaTunnus);
    //olioToimintoSivu->setKT(kayttajaTunnus);
    olioToimintoSivu->tarkistaTyyppi();
    olioToimintoSivu->show();
    this->close();
    Debit_Credit = 1;
    olioTyyppiQtimer->stop();
    timerCounter = 0;
    olioToimintosivuQtimer->start(1000);
}


void Tyyppi::on_pushButtonKirjauduUlos_clicked()
{
    disconnect(olioTyyppiQtimer,SIGNAL(timeout()),this,SLOT(MyTimerTyyppiSlot()));
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
        disconnect(olioTyyppiQtimer,SIGNAL(timeout()),this,SLOT(MyTimerTyyppiSlot()));
        timerCounter = 0;
        this->close();
    }
}

void Tyyppi::setKayttajaTunnus(const QString &newKayttajaTunnus)
{
    kayttajaTunnus = newKayttajaTunnus;
    olioTyyppiQtimer->start(1000);
}

void Tyyppi::timerTyyppiConnect()
{
    connect(olioTyyppiQtimer,SIGNAL(timeout()),this,SLOT(MyTimerTyyppiSlot()));
}

