#include "toimintosivu.h"
#include "ui_toimintosivu.h"
#include "paasivu.h"

Toimintosivu::Toimintosivu(QString test, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Toimintosivu)
{
    ui->setupUi(this);
    ui->textBrowserAsiakkaanNimi->setText("Tilin haltija "+test);
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
    qDebug()<<"saldo painettu";

    QString site_url="http://localhost:3000/pankki/1";
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
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    qDebug()<<json_doc["saldo"];
    QString pankki=json_doc["saldo"].toString();//+" : "+json_doc["author"].toString()+" : "+json_doc["isbn"].toString();
    ui->textBrowserSaldo->setText(pankki);
}

