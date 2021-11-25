#include "paasivu.h"
#include "ui_paasivu.h"

paaSivu::paaSivu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::paaSivu)
{
    ui->setupUi(this);
    olioQtimer = new QTimer;
    timerCounter = 0;

    connect(olioQtimer,SIGNAL(timeout()),this,SLOT(myTimerSlot()));

    oliotyyppi = new Tyyppi;
}

paaSivu::~paaSivu()
{
    delete ui;
    delete olioQtimer;
    olioQtimer = nullptr;
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
    timerCounter++;
    qDebug()<<timerCounter;

    if (timerCounter==5)
    {
        olioQtimer->stop();
        qDebug()<<"Timer stop";
        timerCounter = 0;
        ui->labelHylatty->setText("");
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
            this->close();
        }
        else {
            vaaraPin++;
            ui->LineEdit_pinKoodi->setText("");
            ui->LineEdit_kayttajaTunnus->setText("");
            qDebug()<<"tunnus ja salasana ei täsmää" << vaaraPin;
            ui->labelHylatty->setText("koitappa uudellee");

            if (vaaraPin >= 3)
            {
                qDebug()<<"kortti lukittu " << vaaraPin;
                ui->labelHylatty->setText("kortti lukittu kolmmannen yrityksen jälkeen");
                vaaraPin = 0;
                olioQtimer->start(1000);
            }
        }
}


