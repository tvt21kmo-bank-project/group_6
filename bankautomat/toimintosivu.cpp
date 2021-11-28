#include "toimintosivu.h"
#include "ui_toimintosivu.h"
#include "paasivu.h"

Toimintosivu::Toimintosivu(QString test, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Toimintosivu)
{
    ui->setupUi(this);
    ui->textBrowserAsiakkaanNimi->setText("Tilin haltija "+test);
    urli = test;


    QString site_url=QString("http://localhost:3000/asiakas/%1").arg(urli);
    QString credentials="newAdmin:newPass";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    naytaAsiakasManager = new QNetworkAccessManager(this);
    connect(naytaAsiakasManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(naytaAsiakasSlot(QNetworkReply*)));
    reply2 = naytaAsiakasManager->get(request);


}


void Toimintosivu::naytaAsiakasSlot(QNetworkReply *reply2)
{
    QByteArray response_data2=reply2->readAll();
    ui->textBrowserAsiakkaanNimi->setText("Tervetuloa: "+response_data2);

}


Toimintosivu::~Toimintosivu()
{
    delete ui;
}

void Toimintosivu::on_pushButtonKirjauduUlos2_clicked()
{
    this->close();
    qDebug()<<"kirjaudu ulos painettu";
}


void Toimintosivu::on_pushButtonSaldo_clicked()
{


    QString site_url= QString("http://localhost:3000/pankki/%1").arg(urli);
    QString credentials="newAdmin:newPass";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    naytaSaldoManager = new QNetworkAccessManager(this);
    connect(naytaSaldoManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(naytaSaldoSlot(QNetworkReply*)));
    reply = naytaSaldoManager->get(request);
}

void Toimintosivu::naytaSaldoSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    ui->textBrowserSaldo->setText("Tilin Saldo: "+response_data);
}



