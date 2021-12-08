#include "nostarahaa.h"
#include "ui_nostarahaa.h"

NostaRahaa::NostaRahaa(QString test2, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::NostaRahaa)
{
    ui->setupUi(this);
    kayttis=test2;
}

NostaRahaa::~NostaRahaa()
{
    delete ui;
    delete olioNostaRahaaQtimer;
    olioNostaRahaaQtimer = nullptr;
}

void NostaRahaa::on_pushButton_20_clicked()
{
    qDebug()<<"20e tulossa";
    QJsonObject json; //luodaan JSON objekti ja lisätään data
  //  kayttis = olioToimintosivu->urli;

    json.insert("idKortti",kayttis);
    json.insert("summa",20);
    json.insert("Tila1", Debit_Credit);                 //taman voi kopioida muihin mnostobuttoneihin
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


  //  ui->textBrowser_Infokentta->setText("Tililtä nostettu: 20");

}

void NostaRahaa::on_pushButton_40_clicked()
{
    qDebug()<<"40e tulossa";
    QJsonObject json; //luodaan JSON objekti ja lisätään data
  //  kayttis = olioToimintosivu->urli;

    json.insert("idKortti",kayttis);
    json.insert("summa",40);
    json.insert("Tila1", Debit_Credit);
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


   // ui->textBrowser_Infokentta->setText("Tililtä nostettu: 40");
}

void NostaRahaa::on_pushButton_60_clicked()
{
    qDebug()<<"60e tulossa";
    QJsonObject json; //luodaan JSON objekti ja lisätään data
  //  kayttis = olioToimintosivu->urli;

    json.insert("idKortti",kayttis);
    json.insert("summa",60);
    json.insert("Tila1", Debit_Credit);
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


  //  ui->textBrowser_Infokentta->setText("Tililtä nostettu: 60");
}

void NostaRahaa::on_pushButton_80_clicked()
{
    qDebug()<<"80e tulossa";
    QJsonObject json; //luodaan JSON objekti ja lisätään data
  //  kayttis = olioToimintosivu->urli;

    json.insert("idKortti",kayttis);
    json.insert("summa",80);
    json.insert("Tila1", Debit_Credit);
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


   // ui->textBrowser_Infokentta->setText("Tililtä nostettu: 80");
}

void NostaRahaa::on_pushButton_100_clicked()
{
    qDebug()<<"100e tulossa";
    QJsonObject json; //luodaan JSON objekti ja lisätään data
  //  kayttis = olioToimintosivu->urli;

    json.insert("idKortti",kayttis);
    json.insert("summa",100);
    json.insert("Tila1", Debit_Credit);
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


    // ui->textBrowser_Infokentta->setText("Tililtä nostettu: 100");
}

void NostaRahaa::nostaTimerConnect()
{
    connect(olioNostaRahaaQtimer,SIGNAL(timeout()),this,SLOT(nostaRahaaTimerSlot()));
    timerCounter = 0;
    olioNostaRahaaQtimer->start(1000);
}

void NostaRahaa::on_pushButton_200_clicked()
{
    qDebug()<<"200e tulossa";
    QJsonObject json; //luodaan JSON objekti ja lisätään data
  //  kayttis = olioToimintosivu->urli;

    json.insert("idKortti",kayttis);
    json.insert("summa",200);
    json.insert("Tila1", Debit_Credit);
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


   // ui->textBrowser_Infokentta->setText("Tililtä nostettu: 200");

}

void NostaRahaa::naytaSaldoSlot2(QNetworkReply *reply3)
{
    QByteArray response_data=reply3->readAll();
    ui->textBrowser_Infokentta->setText(""+response_data);
}

void NostaRahaa::nostaRahaaTimerSlot()
{
    timerCounter++;
    qDebug()<<"nosta rahaa timer "<<timerCounter;

    if (timerCounter==timerAika2)
    {
        olioNostaRahaaQtimer->stop();
        qDebug()<<"Timer stop";
        disconnect(olioNostaRahaaQtimer,SIGNAL(timeout()),this,SLOT(nostaRahaaTimerSlot()));
        timerCounter = 0;
        this->close();
        olioToimintosivuQtimer->start(1000);
    }
}

void NostaRahaa::on_pushButton_Palaa_clicked()
{
    disconnect(olioNostaRahaaQtimer,SIGNAL(timeout()),this,SLOT(nostaRahaaTimerSlot()));
   // connect(olioToimintosivuQtimer,SIGNAL(timeout()),this,SLOT(toimintosivuTimerSlot()));
    olioNostaRahaaQtimer->stop();
    timerCounter = 0;
    olioToimintosivuQtimer->start(1000);
    this->close();
}



void NostaRahaa::on_pushButton_Muu_Summa_clicked()
{

    olioMuuSummaNosto = new MuuSummaNosto(kayttis);
    olioMuuSummaNosto -> show();
}









