#include "muusumma.h"
#include "ui_muusumma.h"

MuuSumma::MuuSumma(QString test2, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MuuSumma)
{
    ui->setupUi(this);
    kayttis=test2;

}

MuuSumma::~MuuSumma()
{
    delete ui;
}

void MuuSumma::on_pushButton_MuuSummaSET_clicked()
{
    QJsonObject json; //luodaan JSON objekti ja lisätään data
       // MuuSumma1 = ui->lineEdit_MuuSumma->text();

       // json.insert("summa",ui->LineEdit_pinKoodi->text());
        qDebug()<<kayttis;
        json.insert("idKortti",kayttis);
        json.insert("summa",ui->lineEdit_MuuSumma->text());
        QString site_url="http://localhost:3000/pano/panerahaa";
        QString credentials="newAdmin:newPass";
        QNetworkRequest request((site_url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        QByteArray data = credentials.toLocal8Bit().toBase64();
        QString headerData = "Basic " + data;
        request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
        loginManager = new QNetworkAccessManager(this);
        //connect(loginManager, SIGNAL(finished (QNetworkReply*)),
     //   this, SLOT(kirjauduSisaan(QNetworkReply*)));
        reply = loginManager->post(request, QJsonDocument(json).toJson());


        ui->label_Panosumma->setText(ui->lineEdit_MuuSumma->text());



        //qDebug()<<"20ellä pannaa";
        //QJsonObject json; //luodaan JSON objekti ja lisätään data
      //  kayttis = olioToimintosivu->urli;

       /* json.insert("idKortti",kayttis);
        json.insert("summa",1);
        QString site_url="http://localhost:3000/pano/panerahaa";
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
    */

        //this->close;



}

