#include "paasivu.h"
#include "ui_paasivu.h"

paaSivu::paaSivu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::paaSivu)
{
    ui->setupUi(this);
   // olioQtimer = new QTimer;
   // timerCounter = 0;

  //  connect(olioApusivu->olioQtimer,SIGNAL(timeout()),this,SLOT(myTimerSlot()));
  //  connect(olioApusivu->olioPinQtimer,SIGNAL(timeout()),this,SLOT(myPinTimerSlot()));

    oliotyyppi = new Tyyppi;

 //   olioApusivu->olioQtimer
}

paaSivu::~paaSivu()
{
    delete ui;
   // delete olioQtimer;
   // olioQtimer = nullptr;
    delete oliotyyppi;
    oliotyyppi = nullptr;

}

void paaSivu::on_kirjauduNappi_clicked()
{
    qDebug()<<"Kirjaudu painettu";


       QJsonObject json; //luodaan JSON objekti ja lisätään data
           kayttajaTunnus = ui->LineEdit_kayttajaTunnus->text();
           qDebug()<< kayttajaTunnus;
           json.insert("username",ui->LineEdit_kayttajaTunnus->text());
           json.insert("password",ui->LineEdit_pinKoodi->text());

         //  QJsonObject json2;
         //  json2.insert("username",ui->LineEdit_kayttajaTunnus->text());
          // QJsonDocument doc(json2);                                      //nailla saa tulostettua kayttajatunnuksen qdebugilla
           //QByteArray bytes = doc.toJson();
           //qDebug() << json2;


           QString site_url="http://localhost:3000/login";
           QString credentials="newAdmin:newPass";
           QNetworkRequest request((site_url));
           request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
           QByteArray data = credentials.toLocal8Bit().toBase64();
           QString headerData = "Basic " + data;
           request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
           loginManager = new QNetworkAccessManager(this);
           connect(loginManager, SIGNAL(finished (QNetworkReply*)),
           this, SLOT(kirjauduSisaan(QNetworkReply*)));
           reply = loginManager->post(request, QJsonDocument(json).toJson());



}

void paaSivu::on_takaisinNappi_clicked()
{
    this->close();                                      // suljetaan pääsivu
    qDebug()<<"takaisin painettu";
}

void paaSivu::myTimerSlot()
{
    olioApusivu->timerCounter++;
    qDebug()<<"paasivu timer "<<olioApusivu->timerCounter;

    if (olioApusivu->timerCounter==olioApusivu->timerAika2)
    {
       olioApusivu->olioQtimer->stop();
        qDebug()<<"Timer stop";
        olioApusivu->timerCounter = 0;
        ui->labelHylatty->setText("");
        this->close();
    }
}

void paaSivu::myPinTimerSlot()
{
    olioApusivu->timerCounter++;
    qDebug()<<"vaara pin timer "<<olioApusivu->timerCounter;

    if (olioApusivu->timerCounter==olioApusivu-> timerAika1)
    {
        olioApusivu-> olioPinQtimer->stop();
        qDebug()<<"Timer stop";
        olioApusivu->timerCounter = 0;
        this->close();
    }
}

void paaSivu::kirjauduSisaan(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
        qDebug()<<response_data;
        if(response_data=="true"){
            qDebug()<<"Oikea tunnus ...avaa form";
            oliotyyppi->setKayttajaTunnus(kayttajaTunnus);
            oliotyyppi->show();
            ui->LineEdit_pinKoodi->setText("");
            ui->LineEdit_kayttajaTunnus->setText("");
            olioApusivu-> olioQtimer->stop();
            olioApusivu->timerCounter = 0;
            this->close();
        }
        else {
            vaaraPin++;
            ui->LineEdit_pinKoodi->setText("");
            ui->LineEdit_kayttajaTunnus->setText("");
            qDebug()<<"tunnus ja salasana ei täsmää" << vaaraPin;
            ui->labelHylatty->setText("koitappa uudellee");
            olioApusivu->timerCounter = 0;

            if (vaaraPin >= 3)
            {
                qDebug()<<"kortti lukittu " << vaaraPin;
                ui->labelHylatty->setText("kortti lukittu kolmmannen yrityksen jälkeen");
                vaaraPin = 0;
                olioApusivu-> olioQtimer->stop();
                olioApusivu->timerCounter = 0;
                olioApusivu-> olioPinQtimer->start(1000);

            }
        }
}


