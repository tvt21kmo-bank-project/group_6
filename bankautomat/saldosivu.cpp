#include "saldosivu.h"
#include "ui_saldosivu.h"

Saldosivu::Saldosivu(QString test2, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Saldosivu)
{
    urli = test2;
    ui->setupUi(this);

    connect(olioSaldosivuQtimer,SIGNAL(timeout()),this,SLOT(SaldosivuTimerSlot()));

   // on_pushButtonTilitapahtumat_clicked();

    //naytaTilitapahtumat();
    //naytaSaldo();

   // timerCounter = 0;
   // olioToimintosivuQtimer->start(1000);

}

Saldosivu::~Saldosivu()
{
    delete ui;
}

void Saldosivu::naytaTilitapahtumat()
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

    timerCounter=0;
}

void Saldosivu::naytaSaldo()
{
    QString site_url= QString("http://localhost:3000/pankki/%1").arg(urli);
    QString credentials="newAdmin:newPass";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    naytaSaldoManager = new QNetworkAccessManager(this);
    connect(naytaSaldoManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(naytaSaldotapahtumatSlot(QNetworkReply*)));
    reply = naytaSaldoManager->get(request);
    qDebug()<<"Nayta saldo painettu";
}

void Saldosivu::naytaTilitapahtumatSlot(QNetworkReply *reply3)
{
    QByteArray response_data=reply3->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString Tapahtumat;


    foreach (const QJsonValue &value, json_array)
    {
    QJsonObject json_obj = value.toObject();
    Tapahtumat+=QString::number(json_obj["idTilitapahtumat"].toInt())+" |   PVM: "+json_obj["aika"].toString()+"    |   Tapahtuma: "+json_obj["Tapahtuma"].toString()+"  |   Summa: "+QString::number(json_obj["Maara"].toInt())+"\r";
    }

    qDebug()<<Tapahtumat;
    ui->textBrowser_Tilitapahtumat->setText(Tapahtumat);
    reply3->deleteLater();
    naytaTilitapahtumatManager->deleteLater();
}

void Saldosivu::naytaSaldotapahtumatSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    ui->textBrowser_Saldo->setText("Tilin Saldo: "+response_data);
}

void Saldosivu::on_pushButton_takaisin_clicked()
{
    olioSaldosivuQtimer->stop();
    timerCounter = 0;
    olioToimintosivuQtimer->start(1000);
    this->close();

}

void Saldosivu::SaldosivuTimerSlot()
{
    timerCounter++;
    qDebug()<<"Saldosivu timer "<<timerCounter;

    if (timerCounter==timerAika2)
    {
        olioSaldosivuQtimer->stop();
        qDebug()<<"Timer stop";
        timerCounter = 0;
        this->close();
        olioToimintosivuQtimer->start(1000);
    }
}

