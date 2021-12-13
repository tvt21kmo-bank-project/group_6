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

void MuuSumma::connectTimerMuusumma()
{
    connect(olioMuusummaQtimer,SIGNAL(timeout()),this,SLOT(MuusummaTimerSlot()));
    timerCounter=0;
    olioMuusummaQtimer->start(1000);
}

void MuuSumma::connectTimerMuuPano()
{
    connect(olioMuuPanoQtimer,SIGNAL(timeout()),this,SLOT(MuuPanoTimerSlot()));
    timerCounter=0;
    olioMuuPanoQtimer->start(1000);
    olioMuusummaQtimer->stop();
    disconnect(olioMuusummaQtimer,SIGNAL(timeout()),this,SLOT(MuusummaTimerSlot()));
}

void MuuSumma::on_pushButton_MuuSummaSET_clicked()
{
    QJsonObject json;

        qDebug()<<kayttis;
        json.insert("idKortti",kayttis);
        json.insert("summa",ui->lineEdit_MuuSumma->text());
        json.insert("Tila1", Debit_Credit);
        QString site_url="http://localhost:3000/pano/panerahaa";
        QString credentials="newAdmin:newPass";
        QNetworkRequest request((site_url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        QByteArray data = credentials.toLocal8Bit().toBase64();
        QString headerData = "Basic " + data;
        request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
        loginManager = new QNetworkAccessManager(this);

        connect(loginManager, SIGNAL(finished (QNetworkReply*)),
        this, SLOT(naytaSaldoSlot4(QNetworkReply*)));
        reply = loginManager->post(request, QJsonDocument(json).toJson());
      
        connectTimerMuuPano();
}

void MuuSumma::MuusummaTimerSlot()
{
    timerCounter++;
    qDebug()<<"Muusumma timer "<<timerCounter;

    if (timerCounter==timerAika2)
    {

        olioMuusummaQtimer->stop();
        qDebug()<<"Timer stop";
        disconnect(olioMuusummaQtimer,SIGNAL(timeout()),this,SLOT(MuusummaTimerSlot()));
        timerCounter = 0;
        this->close();
        olioToimintosivuQtimer->start(1000);
    }
}

void MuuSumma::naytaSaldoSlot4(QNetworkReply *reply)
{
     QByteArray response_data=reply->readAll();
     ui->label_Panosumma->setText(response_data);
}
void MuuSumma::MuuPanoTimerSlot()
{
    timerCounter++;
    qDebug()<<"MuuPano timer "<<timerCounter;

    if (timerCounter==timerAika3)
    {

        olioMuuPanoQtimer->stop();
        qDebug()<<"Timer stop";
        disconnect(olioMuuPanoQtimer,SIGNAL(timeout()),this,SLOT(MuuPanoTimerSlot()));
        timerCounter = 0;
        this->close();
        olioToimintosivuQtimer->start(1000);
    }

}

