#include "toimintosivu.h"
#include "ui_toimintosivu.h"
#include "paasivu.h"


Toimintosivu::Toimintosivu(QString test, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Toimintosivu)
{
    olioApuSivu = new apusivu;

    ui->setupUi(this);
    ui->textBrowserAsiakkaanNimi->setText("Tilin haltija "+test);
    urli = test;
    kayttajatunnus2=urli;
    QString site_url=QString("http://localhost:3000/asiakas/%1").arg(urli);
    QString credentials="newAdmin:newPass";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    naytaAsiakasManager = new QNetworkAccessManager(this);
    connect(naytaAsiakasManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(naytaAsiakasSlot(QNetworkReply*)));
    reply2 = naytaAsiakasManager->get(request);

    connect(olioApuSivu-> olioToimintosivuQtimer,SIGNAL(timeout()),this,SLOT(toimintosivuTimerSlot()));


}

void Toimintosivu::naytaAsiakasSlot(QNetworkReply *reply2)
{
    QByteArray response_data2=reply2->readAll();
    ui->textBrowserAsiakkaanNimi->setText("Tervetuloa: "+response_data2);

}

Toimintosivu::~Toimintosivu()
{
    delete ui;
    delete olioNostarahaa;
    delete olioPano;
    delete olioApuSivu-> olioToimintosivuQtimer;
    delete olioTilitapahtumat;
    delete olioSaldoSivu;
    olioApuSivu-> olioToimintosivuQtimer = nullptr;
    olioNostarahaa = nullptr;
    olioPano = nullptr;
    olioTilitapahtumat = nullptr;
    olioSaldoSivu = nullptr;

}

void Toimintosivu::on_pushButtonKirjauduUlos2_clicked()
{
    this->close();
    qDebug()<<"kirjaudu ulos painettu";
}

void Toimintosivu::on_pushButtonSaldo_clicked()
{
    olioSaldoSivu = new Saldosivu(kayttajatunnus2);
    olioSaldoSivu->show();
    olioSaldoSivu->naytaSaldo();
    olioSaldoSivu->naytaTilitapahtumat();




}

/*void Toimintosivu::naytaSaldoSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    ui->textBrowserSaldo->setText("Tilin Saldo: "+response_data);   
}*/

void Toimintosivu::on_pushButtonNosta_clicked()
{
    olioApuSivu-> olioToimintosivuQtimer->stop();
    olioApuSivu-> olioNostaRahaaQtimer->stop();
    olioApuSivu-> timerCounter = 0;
    olioApuSivu-> olioNostaRahaaQtimer->start(1000);

    olioNostarahaa = new NostaRahaa(kayttajatunnus2); //Nostarahaa(kayttajatunnus2);
    olioNostarahaa->show();
}

void Toimintosivu::setKayttajatunnus2(const QString &newKayttajatunnus2)
{
    kayttajatunnus2 = newKayttajatunnus2;
}



void Toimintosivu::on_pushButtonTilitapahtumat_clicked()
{

    olioTilitapahtumat = new Tilitapahtumat(kayttajatunnus2);
    olioTilitapahtumat->show();




   /* QString site_url= QString("http://localhost:3000/tapahtumat/%1").arg(urli);
    QString credentials="newAdmin:newPass";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    naytaTilitapahtumatManager = new QNetworkAccessManager(this);
    connect(naytaTilitapahtumatManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(naytaTilitapahtumatSlot(QNetworkReply*)));
    reply = naytaTilitapahtumatManager->get(request);
    qDebug()<<"Tilitapahtumat painettu"; */

    olioApuSivu-> olioToimintosivuQtimer->stop();
    olioApuSivu-> timerCounter = 0;
    //olioToimintosivuQtimer->start(1000);

}

/*void Toimintosivu::naytaTilitapahtumatSlot(QNetworkReply *reply3)
{
    QByteArray response_data=reply->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString Tapahtumat;


    foreach (const QJsonValue &value, json_array)
    {
    QJsonObject json_obj = value.toObject();
    Tapahtumat+=QString::number(json_obj["idTilitapahtumat"].toInt())+" |   PVM: "+json_obj["aika"].toString()+"    |   Tapahtuma: "+json_obj["Tapahtuma"].toString()+"  |   Summa: "+QString::number(json_obj["Maara"].toInt())+"\r";
    }

    qDebug()<<Tapahtumat;
    ui->textBrowserTiliTapahtumat->setText(Tapahtumat);
    reply->deleteLater();
    naytaTilitapahtumatManager->deleteLater();
}

void Toimintosivu::naytaSaldoTilitapahtumat()
{
    QString site_url= QString("http://localhost:3000/tapahtumat/saldoTapahtuma/%1").arg(urli);
    QString credentials="newAdmin:newPass";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    naytaTilitapahtumatManager = new QNetworkAccessManager(this);
    connect(naytaTilitapahtumatManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(naytaTilitapahtumatSlot(QNetworkReply*)));
    reply = naytaTilitapahtumatManager->get(request);
    qDebug()<<"Saldo Tilitapahtumat painettu";
}
*/

void Toimintosivu::on_pushButtonPane_clicked()
{
    olioPano = new Pano(kayttajatunnus2); //Nostarahaa(kayttajatunnus2);
    olioPano->show();  
    olioApuSivu-> olioToimintosivuQtimer->stop();
    olioApuSivu-> timerCounter = 0;
    olioApuSivu-> olioPanoQtimer->start(1000);
}

void Toimintosivu::toimintosivuTimerSlot()
{
    olioApuSivu-> timerCounter++;
    qDebug()<<"toimintosivu timer "<<olioApuSivu-> timerCounter;

    if (olioApuSivu-> timerCounter==olioApuSivu-> timerAika2)
    {
        olioApuSivu-> olioToimintosivuQtimer->stop();
        qDebug()<<"Timer stop";
        olioApuSivu-> timerCounter = 0;
        this->close();
    }
}

