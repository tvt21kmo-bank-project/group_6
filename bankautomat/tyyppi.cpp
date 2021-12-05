#include "tyyppi.h"
#include "ui_tyyppi.h"
#include "mainwindow.h"

Tyyppi::Tyyppi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tyyppi)
{
    ui->setupUi(this);

    olioApusivu = new apusivu;

    connect(olioApusivu->olioTyyppiQtimer,SIGNAL(timeout()),this,SLOT(MyTimerTyyppiSlot()));
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
    olioApusivu-> olioTyyppiQtimer->stop();
    olioApusivu-> timerCounter = 0;
    olioApusivu-> olioToimintosivuQtimer->start(1000);
}


void Tyyppi::on_pushButtonKirjauduUlos_clicked()
{
    this->close();
}

void Tyyppi::MyTimerTyyppiSlot()
{
    olioApusivu-> timerCounter++;
    qDebug()<<"TyyppiSivuTimer "<<olioApusivu-> timerCounter;

    if (olioApusivu->timerCounter==olioApusivu-> timerAika2)
    {
        olioApusivu-> olioTyyppiQtimer->stop();
        qDebug()<<"Timer stop";
        olioApusivu-> timerCounter = 0;
        this->close();
    }
}

void Tyyppi::setKayttajaTunnus(const QString &newKayttajaTunnus)
{
    kayttajaTunnus = newKayttajaTunnus;
    olioApusivu-> olioTyyppiQtimer->start(1000);
}

