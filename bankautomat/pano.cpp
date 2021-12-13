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
    delete olioPanoQtimer;
    olioPanoQtimer = nullptr;
}

void Pano::setKayttajatunnus2(const QString &newKayttajatunnus2)
{
    kayttajatunnus2 = newKayttajatunnus2;
}

void Pano::panoTimerConnect()
{
    connect(olioPanoQtimer,SIGNAL(timeout()),this,SLOT(PaneTimerSlot()));
    timerCounter = 0;
    olioPanoQtimer->start(1000);
}

void Pano::tarkastaTyyppiPane()
{
 if(Debit_Credit ==0)
 ui->textBrowser->setText("Lyhennä luottoa");
 else
     {
         ui->textBrowser->setText("Pane rahaa");
     }
}

void Pano::on_pushButton_pane20_clicked()
{
    qDebug()<<"20:llä pannaa";
    QJsonObject json; //luodaan JSON objekti ja lisätään data
  //  kayttis = olioToimintosivu->urli;

    json.insert("idKortti",kayttis);
    json.insert("summa",20);
    json.insert("Tila1", Debit_Credit);
    QString site_url="http://localhost:3000/pano/panerahaa";
    QString credentials="newAdmin:newPass";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    naytaSaldoManager2 = new QNetworkAccessManager(this);
    connect(naytaSaldoManager2, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(naytaPanoVastausSlot(QNetworkReply*)));
    reply3 = naytaSaldoManager2->post(request, QJsonDocument(json).toJson());


    //ui->label_pane->setText("Pantu parilla kympillä");
    timerCounter=0;
}

void Pano::on_pushButtonNelkyt_clicked()
{
    qDebug()<<"Nelkyt euroa pannaa";
    QJsonObject json; //luodaan JSON objekti ja lisätään data
  //  kayttis = olioToimintosivu->urli;

    json.insert("idKortti",kayttis);
    json.insert("summa",40);
    json.insert("Tila1", Debit_Credit);
    QString site_url="http://localhost:3000/pano/panerahaa";
    QString credentials="newAdmin:newPass";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    naytaSaldoManager2 = new QNetworkAccessManager(this);
    connect(naytaSaldoManager2, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(naytaPanoVastausSlot(QNetworkReply*)));
    reply3 = naytaSaldoManager2->post(request, QJsonDocument(json).toJson());


   // ui->label_pane->setText("Pantu Neljalla kympilla");
    timerCounter=0;
}

void Pano::on_pushButtonKuuskymppia_clicked()
{
    qDebug()<<"60:llä pannaa";
    QJsonObject json; //luodaan JSON objekti ja lisätään data
  //  kayttis = olioToimintosivu->urli;

    json.insert("idKortti",kayttis);
    json.insert("summa",60);
    json.insert("Tila1", Debit_Credit);
    QString site_url="http://localhost:3000/pano/panerahaa";
    QString credentials="newAdmin:newPass";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    naytaSaldoManager2 = new QNetworkAccessManager(this);
    connect(naytaSaldoManager2, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(naytaPanoVastausSlot(QNetworkReply*)));
    reply3 = naytaSaldoManager2->post(request, QJsonDocument(json).toJson());


   // ui->label_pane->setText("Pantu kuudella kympillä");
    timerCounter=0;

}

void Pano::on_pushButtonKahekskyt_clicked()
{
    qDebug()<<"Kahdeksankymmentä euroa pannaa";
    QJsonObject json; //luodaan JSON objekti ja lisätään data
  //  kayttis = olioToimintosivu->urli;

    json.insert("idKortti",kayttis);
    json.insert("summa",80);
    json.insert("Tila1", Debit_Credit);
    QString site_url="http://localhost:3000/pano/panerahaa";
    QString credentials="newAdmin:newPass";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    naytaSaldoManager2 = new QNetworkAccessManager(this);
    connect(naytaSaldoManager2, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(naytaPanoVastausSlot(QNetworkReply*)));
    reply3 = naytaSaldoManager2->post(request, QJsonDocument(json).toJson());


   // ui->label_pane->setText("Pantu Kahdeksalla kympillä sadalla");
    timerCounter=0;
}

void Pano::naytaPanoVastausSlot(QNetworkReply *reply3)
{
    QByteArray response_data=reply3->readAll();
    ui->label_pane->setText(""+response_data);
}


void Pano::on_pushButtonSatane_clicked()
{
    qDebug()<<"Satasella pannaa";
    QJsonObject json; //luodaan JSON objekti ja lisätään data
  //  kayttis = olioToimintosivu->urli;

    json.insert("idKortti",kayttis);
    json.insert("summa",100);
    json.insert("Tila1", Debit_Credit);
    QString site_url="http://localhost:3000/pano/panerahaa";
    QString credentials="newAdmin:newPass";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    naytaSaldoManager2 = new QNetworkAccessManager(this);
    connect(naytaSaldoManager2, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(naytaPanoVastausSlot(QNetworkReply*)));
    reply3 = naytaSaldoManager2->post(request, QJsonDocument(json).toJson());


   // ui->label_pane->setText("Pantu satasella");
    timerCounter=0;
}



void Pano::on_pushButtonKaksSataa_clicked()
{
    qDebug()<<"Kaksi sataa euroa pannaa";
    QJsonObject json; //luodaan JSON objekti ja lisätään data
  //  kayttis = olioToimintosivu->urli;

    json.insert("idKortti",kayttis);
    json.insert("summa",200);
    json.insert("Tila1", Debit_Credit);
    QString site_url="http://localhost:3000/pano/panerahaa";
    QString credentials="newAdmin:newPass";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    naytaSaldoManager2 = new QNetworkAccessManager(this);
    connect(naytaSaldoManager2, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(naytaPanoVastausSlot(QNetworkReply*)));
    reply3 = naytaSaldoManager2->post(request, QJsonDocument(json).toJson());


  //  ui->label_pane->setText("Pantu Kahdella sadalla");
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
        disconnect(olioPanoQtimer,SIGNAL(timeout()),this,SLOT(PaneTimerSlot()));
        timerCounter = 0;
        this->close();
        olioToimintosivuQtimer->start(1000);
    }

}


void Pano::on_pushButton_Palaa_clicked()
{
    disconnect(olioPanoQtimer,SIGNAL(timeout()),this,SLOT(PaneTimerSlot()));
    olioPanoQtimer->stop();
    timerCounter = 0;
    olioToimintosivuQtimer->start(1000);
    this->close();

}

void Pano::on_pushButton_MuuPano_clicked()
{
    qDebug()<<kayttajatunnus2;

    disconnect(olioPanoQtimer,SIGNAL(timeout()),this,SLOT(PaneTimerSlot()));
    olioMuuSumma = new MuuSumma(kayttis);
    olioMuuSumma->show();
    olioMuuSumma->connectTimerMuusumma();
    olioPanoQtimer->stop();
    this->close();
}




