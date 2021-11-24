#include "tyyppi.h"
#include "ui_tyyppi.h"

Tyyppi::Tyyppi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tyyppi)
{
    ui->setupUi(this);
 olioToimintoSivu = new Toimintosivu;

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


}


void Tyyppi::on_pushButtonDebit_clicked()
{
    qDebug()<<"debit painettu";
    olioToimintoSivu->show();
}


void Tyyppi::on_pushButtonKirjauduUlos_clicked()
{
    this->close();
}

