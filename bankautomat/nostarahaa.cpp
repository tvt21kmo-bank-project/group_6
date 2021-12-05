#include "nostarahaa.h"
#include "ui_nostarahaa.h"

NostaRahaa::NostaRahaa(QString test2, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NostaRahaa)
{
    ui->setupUi(this);
    kayttis=test2;
    olioApuSivu = new apusivu;

    connect(olioApuSivu-> olioNostaRahaaQtimer,SIGNAL(timeout()),this,SLOT(nostaRahaaTimerSlot()));

}

NostaRahaa::~NostaRahaa()
{
    delete ui;
    delete olioApuSivu-> olioNostaRahaaQtimer;
    olioApuSivu-> olioNostaRahaaQtimer = nullptr;
}

void NostaRahaa::on_pushButton_20_clicked()
{
    qDebug()<<"20e tulossa";
    QJsonObject json; //luodaan JSON objekti ja lisätään data
  //  kayttis = olioToimintosivu->urli;

    json.insert("idKortti",kayttis);
    json.insert("summa",200);
    QString site_url="http://localhost:3000/debitnosto/nostarahaa";
    QString credentials="newAdmin:newPass";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    naytaSaldoManager2 = new QNetworkAccessManager(this);
    connect(naytaSaldoManager2, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(naytaSaldoSlot2(QNetworkReply*)));
    reply3 = naytaSaldoManager2->post(request, QJsonDocument(json).toJson());


}

void NostaRahaa::naytaSaldoSlot2(QNetworkReply *reply3)
{
    QByteArray response_data=reply3->readAll();
    ui->textBrowser_Infokentta->setText("Tililtä nostettu: "+response_data);

}

void NostaRahaa::nostaRahaaTimerSlot()
{
    olioApuSivu-> timerCounter++;
    qDebug()<<"nosta rahaa timer "<<olioApuSivu-> timerCounter;

    if (olioApuSivu-> timerCounter==olioApuSivu-> timerAika2)
    {
        olioApuSivu-> olioNostaRahaaQtimer->stop();
        qDebug()<<"Timer stop";
        olioApuSivu-> timerCounter = 0;
        this->close();
        olioApuSivu-> olioToimintosivuQtimer->start(1000);
    }
}

void NostaRahaa::on_pushButton_Palaa_clicked()
{
    olioApuSivu-> olioNostaRahaaQtimer->stop();
    olioApuSivu-> timerCounter = 0;
    olioApuSivu-> olioToimintosivuQtimer->start(1000);
    this->close();
}



void NostaRahaa::on_pushButton_Muu_Summa_clicked()
{

    olioMuuSummaNosto = new MuuSummaNosto(kayttis);
    olioMuuSummaNosto -> show();
}

