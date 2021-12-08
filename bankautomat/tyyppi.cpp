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
    qDebug()<<Debit_Credit;
    Debit_Credit = 0;
    olioToimintoSivu->tarkistaTyyppi();
    olioToimintoSivu->show();
    this->close();
    olioTyyppiQtimer->stop();
    timerCounter = 0;
    olioToimintoSivu->connectTimerToimintosivu();
    disconnect(olioTyyppiQtimer,SIGNAL(timeout()),this,SLOT(MyTimerTyyppiSlot()));


}


void Tyyppi::on_pushButtonDebit_clicked()
{
    qDebug()<<"debit painettu";
    qDebug()<<Debit_Credit;
    qDebug()<<kayttajaTunnus;
    Debit_Credit = 1;
    olioToimintoSivu = new Toimintosivu(kayttajaTunnus);
    //olioToimintoSivu->setKT(kayttajaTunnus);
    olioToimintoSivu->tarkistaTyyppi();
    olioToimintoSivu->show();
    this->close();
    olioTyyppiQtimer->stop();
    olioToimintoSivu->connectTimerToimintosivu();
    disconnect(olioTyyppiQtimer,SIGNAL(timeout()),this,SLOT(MyTimerTyyppiSlot()));
    ui->pushButtonCredit->show();
}


void Tyyppi::on_pushButtonKirjauduUlos_clicked()
{
    timerCounter=0;
    disconnect(olioTyyppiQtimer,SIGNAL(timeout()),this,SLOT(MyTimerTyyppiSlot()));
    this->close();
    ui->pushButtonCredit->show();
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

void Tyyppi::piilotaCredit()
{
    ui->pushButtonCredit->hide();
}

