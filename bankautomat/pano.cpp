#include "pano.h"
#include "ui_pano.h"

Pano::Pano(QString test2, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Pano)
{
    ui->setupUi(this);
    kayttis=test2;
    qDebug()<<"KT2"+kayttajatunnus2;
    qDebug()<<"KT2"+kayttis;

}

Pano::~Pano()
{
    delete ui;
}

void Pano::setKayttajatunnus2(const QString &newKayttajatunnus2)
{
    kayttajatunnus2 = newKayttajatunnus2;
}

void Pano::on_pushButton_pane20_clicked()
{
    qDebug()<<"20ellä pannaa";
    QJsonObject json; //luodaan JSON objekti ja lisätään data
  //  kayttis = olioToimintosivu->urli;

    json.insert("idKortti",kayttis);
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


    ui->label_pane->setText("Pantu parilla kympillä");
}


void Pano::on_pushButton_Palaa_clicked()
{
                                                        //Laura tekee tähän
}


void Pano::on_pushButton_MuuPano_clicked()
{
    qDebug()<<kayttajatunnus2;
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

    olioMuuSumma = new MuuSumma(kayttis);
    olioMuuSumma->show();


}

