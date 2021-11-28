#include "nostarahaa.h"
#include "ui_nostarahaa.h"

NostaRahaa::NostaRahaa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NostaRahaa)
{
    ui->setupUi(this);
}

NostaRahaa::~NostaRahaa()
{
    delete ui;
}

void NostaRahaa::on_pushButton_20_clicked()
{
    qDebug()<<"20e tulossa";


}

