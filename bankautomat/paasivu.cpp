#include "paasivu.h"
#include "ui_paasivu.h"

paaSivu::paaSivu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::paaSivu)
{
    ui->setupUi(this);
    connect(olioQtimer,SIGNAL(timeout()),this,SLOT(myTimerSlot()));
    connect(olioPinQtimer,SIGNAL(timeout()),this,SLOT(myPinTimerSlot()));
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


       QJsonObject json;                                    //luodaan JSON objekti ja lisätään data
           kayttajaTunnus = ui->LineEdit_kayttajaTunnus->text();
           json.insert("username",ui->LineEdit_kayttajaTunnus->text());
           json.insert("password",ui->LineEdit_pinKoodi->text());
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
           KorttiLukittu();
           KortinTyyppi();
}

void paaSivu::on_takaisinNappi_clicked()
{
    olioQtimer->stop();
    timerCounter=0;
    this->close();                                      // suljetaan pääsivu
    qDebug()<<"takaisin painettu";
    ui->labelHylatty->setText("");
    ui->LineEdit_pinKoodi->setText("");
    ui->LineEdit_kayttajaTunnus->setText("");
}

void paaSivu::myTimerSlot()
{
    timerCounter++;
    if (timerCounter==timerAika2)
    {
        olioQtimer->stop();
        qDebug()<<"Timer stop";
        timerCounter = 0;
        ui->labelHylatty->setText("");
        this->close();
        ui->LineEdit_pinKoodi->setText("");
        ui->LineEdit_kayttajaTunnus->setText("");
    }
}

void paaSivu::myPinTimerSlot()
{
    timerCounter++;
    qDebug()<<"vaara pin timer "<<timerCounter;

    if (timerCounter==timerAika1)
    {
        olioPinQtimer->stop();
        qDebug()<<"Timer stop";
        timerCounter = 0;
        this->close();
        ui->labelHylatty->setText("");
        ui->LineEdit_pinKoodi->setText("");
        ui->LineEdit_kayttajaTunnus->setText("");
    }

}

void paaSivu::KortinTyyppiSlot(QNetworkReply *reply8)
{
    QByteArray response_data=reply8->readAll();
    if (response_data == "[]"){
        qDebug()<<"töttörööpaskaa";
        Debit_Credit = 1;
        oliotyyppi->piilotaCredit();
    }
}

void paaSivu::KorttiLukittuSlot(QNetworkReply *reply12)
{
    QByteArray response_data=reply12->readAll();
    //qDebug()<<Kortinlukitus<<"kortinlukitus77";
    qDebug()<<response_data<<"kortinlukitus77";
    while (Kortinlukitus==3){

    if (response_data == "1"){
        //qDebug()<<"töttörööLukittu";
        Kortinlukitus = 1;
        ui->labelHylatty->setText("Kortti lukittu!");
    }
    else if (response_data == "0")
    {
        Kortinlukitus=0;
        qDebug()<<"töttörööeiLukittu";
        ui->labelHylatty->setText("koitappa uudellee");
    }
    else if (response_data =="[]"){
        ui->labelHylatty->setText("Korttia ei olemassa :o!");
        qDebug()<<"töttörööLukittu";
        Kortinlukitus=1;
    }
    }

    if (response_data == "1"){
        //qDebug()<<"töttörööLukittu";
        Kortinlukitus = 1;
        ui->labelHylatty->setText("Kortti lukittu!");
    }
    else if (response_data == "0")
    {
        Kortinlukitus=0;
        //ui->labelHylatty->setText("");
    }
    else if (response_data =="[]"){
        ui->labelHylatty->setText("Korttia ei olemassa :o!");
        qDebug()<<"töttörööLukittu2";
    }



}

void paaSivu::KortinTyyppi()
{
    QString site_url= QString("http://localhost:3000/login/%1").arg(kayttajaTunnus);
    QString credentials="newAdmin:newPass";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    haeKorttiManager2 = new QNetworkAccessManager(this);
    connect(haeKorttiManager2, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(KortinTyyppiSlot(QNetworkReply*)));
    reply8 = haeKorttiManager2->get(request);

}

void paaSivu::KorttiLukittu()
{
    QString site_url= QString("http://localhost:3000/login/lukittu/%1").arg(kayttajaTunnus);
    QString credentials="newAdmin:newPass";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    haeKorttiManager = new QNetworkAccessManager(this);
    connect(haeKorttiManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(KorttiLukittuSlot(QNetworkReply*)));
    reply8 = haeKorttiManager->get(request);
}

void paaSivu::kirjauduSisaan(QNetworkReply *reply)
{
        KorttiLukittu();
        QByteArray response_data=reply->readAll();
        qDebug()<<"Kortin ukitus oon1"<<Kortinlukitus;

        if(Kortinlukitus == 0){

            if(response_data=="true"){
            qDebug()<<"Oikea tunnus ...avaa form";
            oliotyyppi->setKayttajaTunnus(kayttajaTunnus);
            oliotyyppi->show();
            ui->LineEdit_pinKoodi->setText("");
            ui->LineEdit_kayttajaTunnus->setText("");
            ui->labelHylatty->setText("");
            olioQtimer->stop();
            oliotyyppi->timerTyyppiConnect();
            timerCounter = 0;
            this->close();
            }
            else {
            vaaraPin++;
            ui->LineEdit_pinKoodi->setText("");
            ui->LineEdit_kayttajaTunnus->setText("");
            qDebug()<<"tunnus ja salasana ei täsmää" << vaaraPin;
            ui->labelHylatty->setText("koitappa uudellee");
            timerCounter = 0;

             if (vaaraPin >= 3)
            {
                 QJsonObject json;
                 json.insert("id",kayttajaTunnus);
                 QString site_url="http://localhost:3000/asiakas/lukitus";
                 QString credentials="newAdmin:newPass";
                 QNetworkRequest request((site_url));
                 request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
                 QByteArray data = credentials.toLocal8Bit().toBase64();
                 QString headerData = "Basic " + data;
                 request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
                 loginManager = new QNetworkAccessManager(this);
                 reply = loginManager->post(request, QJsonDocument(json).toJson());

                //qDebug()<<"kortti lukittu " << vaaraPin;
                ui->labelHylatty->setText("kortti lukittu kolmmannen yrityksen jälkeen");
                vaaraPin = 0;
                olioQtimer->stop();
                timerCounter = 0;
                olioPinQtimer->start(1000);
              }}}

     //   }
}


