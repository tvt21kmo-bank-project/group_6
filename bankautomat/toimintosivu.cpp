#include "toimintosivu.h"
#include "ui_toimintosivu.h"

Toimintosivu::Toimintosivu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Toimintosivu)
{
    ui->setupUi(this);
    ui->textBrowserAsiakkaanNimi->setText("asiakas tattinaama");
}

Toimintosivu::~Toimintosivu()
{
    delete ui;


}
