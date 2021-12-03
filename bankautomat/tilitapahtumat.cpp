#include "tilitapahtumat.h"
#include "ui_tilitapahtumat.h"

Tilitapahtumat::Tilitapahtumat(QString test2, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tilitapahtumat)
{
    urli=test2;
    ui->setupUi(this);  
    QString site_url= QString("http://localhost:3000/tapahtumat/saldotapahtuma/%1").arg(urli);
    QString credentials="newAdmin:newPass";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    naytaTilitapahtumatManager = new QNetworkAccessManager(this);
    connect(naytaTilitapahtumatManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(naytaTilitapahtumatSlot(QNetworkReply*)));
    reply3 = naytaTilitapahtumatManager->get(request);
    qDebug()<<"Tilitapahtumat painettu";
}

Tilitapahtumat::~Tilitapahtumat()
{
    delete ui;
    delete olioToimintosivuQtimer;
    olioPinQtimer = nullptr;
}

void Tilitapahtumat::naytaTilitapahtumatSlot(QNetworkReply *reply3)
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
    ui->textBrowser_2->setText(Tapahtumat);
    reply3->deleteLater();
    naytaTilitapahtumatManager->deleteLater();
}


void Tilitapahtumat::on_pushButton_KirjauduUlos_clicked()
{

    {
       /*olioNostaRahaaQtimer->stop();  // tahan oma timer
        */
        timerCounter = 0;
        olioToimintosivuQtimer->start(1000);
        this->close();
    }
}


void Tilitapahtumat::on_pushButton_Palaa_clicked()
{ // tajan vissiin halutaankin palaa takasin tapahtumissa? nyt se palaa takaisin edelliseen sivuun niinkuin toi kirjaudu uloskin. OOn nappara
    {
       /*olioNostaRahaaQtimer->stop();  // tahan oma timer
        */
        timerCounter = 0;
        olioToimintosivuQtimer->start(1000);
        this->close();
    }

}

