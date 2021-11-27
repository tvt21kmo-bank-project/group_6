#include "tyyppi.h"
#include "ui_tyyppi.h"

Tyyppi::Tyyppi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tyyppi)
{
    ui->setupUi(this);

 //qDebug()<<kayttajaTunnus;

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
}


void Tyyppi::on_pushButtonKirjauduUlos_clicked()
{
    this->close();
}

void Tyyppi::setKayttajaTunnus(const QString &newKayttajaTunnus)
{
    kayttajaTunnus = newKayttajaTunnus;
}

