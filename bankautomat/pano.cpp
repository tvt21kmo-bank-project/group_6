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

    connect(olioPanoQtimer,SIGNAL(timeout()),this,SLOT(PaneTimerSlot()));

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
    json.insert("summa",20);
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
    timerCounter=0;
}

void Pano::on_pushButtonKuuskymppia_clicked()
{
    qDebug()<<"60ellä pannaa";
    QJsonObject json; //luodaan JSON objekti ja lisätään data
  //  kayttis = olioToimintosivu->urli;

    json.insert("idKortti",kayttis);
    json.insert("summa",60);
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


    ui->label_pane->setText("Pantu kuudella kympillä");
    timerCounter=0;

}

void Pano::on_pushButtonSatane_clicked()
{
    qDebug()<<"Satasella pannaa";
    QJsonObject json; //luodaan JSON objekti ja lisätään data
  //  kayttis = olioToimintosivu->urli;

    json.insert("idKortti",kayttis);
    json.insert("summa",100);
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


    ui->label_pane->setText("Pantu satasella");
    timerCounter=0;
}

void Pano::on_pushButtonNelkyt_clicked()
{
    qDebug()<<"Nelkyt euroa pannaa";
    QJsonObject json; //luodaan JSON objekti ja lisätään data
  //  kayttis = olioToimintosivu->urli;

    json.insert("idKortti",kayttis);
    json.insert("summa",40);
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


    ui->label_pane->setText("Pantu Neljalla kympilla");
    timerCounter=0;
}

void Pano::on_pushButtonKaksSataa_clicked()
{
    qDebug()<<"Kaksi sataa euroa pannaa";
    QJsonObject json; //luodaan JSON objekti ja lisätään data
  //  kayttis = olioToimintosivu->urli;

    json.insert("idKortti",kayttis);
    json.insert("summa",200);
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


    ui->label_pane->setText("Pantu Kahdella sadalla");
    timerCounter=0;
}


void Pano::PaneTimerSlot()
{
    timerCounter++;
    qDebug()<<"Pano timer "<<timerCounter;

    if (timerCounter==timerAika2)
    {
        olioPanoQtimer->stop();
        qDebug()<<"Timer stop";
        timerCounter = 0;
        this->close();
        olioToimintosivuQtimer->start(1000);
    }

}


void Pano::on_pushButton_Palaa_clicked()
{
    /*olioNostaRahaaQtimer->stop();  // tahan oma timer
     */
     timerCounter = 0;
     olioToimintosivuQtimer->start(1000);
     this->close();
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







