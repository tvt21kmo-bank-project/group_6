#include "paasivu.h"
#include "ui_paasivu.h"

paaSivu::paaSivu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::paaSivu)
{
    ui->setupUi(this);
}

paaSivu::~paaSivu()
{
    delete ui;
}

void paaSivu::on_kirjauduNappi_clicked()
{
    qDebug()<<"Kirjaudu painettu";
}

void paaSivu::on_takaisinNappi_clicked()
{
    this->close();
}
