#include "tyyppi.h"
#include "ui_tyyppi.h"

Tyyppi::Tyyppi(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tyyppi)
{
    ui->setupUi(this);

}

Tyyppi::~Tyyppi()
{
    delete ui;


}

void Tyyppi::on_pushButtonCredit_clicked()
{
    qDebug()<<"credit painettu";


}


void Tyyppi::on_pushButtonDebit_clicked()
{
    qDebug()<<"debit painettu";

}


void Tyyppi::on_pushButtonKirjauduUlos_clicked()
{
    this->close();
}

