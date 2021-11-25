#include "toimintosivu.h"
#include "ui_toimintosivu.h"
#include "paasivu.h"

Toimintosivu::Toimintosivu(QString test, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Toimintosivu)
{
    ui->setupUi(this);


    ui->textBrowserAsiakkaanNimi->setText("terve"+test);
}


Toimintosivu::~Toimintosivu()
{
    delete ui;


}





