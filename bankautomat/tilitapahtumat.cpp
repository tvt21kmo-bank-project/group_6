#include "tilitapahtumat.h"
#include "ui_tilitapahtumat.h"


Tilitapahtumat::Tilitapahtumat(QString test2, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Tilitapahtumat)
{
    ui->setupUi(this);
    kayttis=test2;
    Naytatilitapahtumat();
}

Tilitapahtumat::~Tilitapahtumat()
{
    delete ui;
    delete olioToimintosivuQtimer;
    olioPinQtimer = nullptr;
}

void Tilitapahtumat::connectTimerTilitapahtumat()
{
    connect(olioTilitapahtumatQtimer,SIGNAL(timeout()),this,SLOT(TilitapahtumatTimerSlot()));
    timerCounter = 0;
    olioTilitapahtumatQtimer->start(1000);
}

void Tilitapahtumat::Naytatilitapahtumat()
{
    QJsonObject json;
    json.insert("idKortti",kayttis);
    json.insert("offset",offsetmuuttuja);
    json.insert("Tila1", Debit_Credit);
    QString site_url="http://localhost:3000/tapahtumat/TapahtumaLisaa";
    QString credentials="newAdmin:newPass";
    QNetworkRequest request((site_url));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    QByteArray data = credentials.toLocal8Bit().toBase64();
    QString headerData = "Basic " + data;
    request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
    naytaTilitapahtumatManager = new QNetworkAccessManager(this);
    connect(naytaTilitapahtumatManager, SIGNAL(finished (QNetworkReply*)),
    this, SLOT(naytaTilitapahtumatSlot(QNetworkReply*)));
    reply3 = naytaTilitapahtumatManager->post(request, QJsonDocument(json).toJson());
}

void Tilitapahtumat::naytaTilitapahtumatSlot(QNetworkReply *reply3)
{
    QByteArray response_data=reply3->readAll();
    QJsonDocument json_doc = QJsonDocument::fromJson(response_data);
    QJsonArray json_array = json_doc.array();
    QString Tapahtumat;


    //qDebug()<<response_data;
    qDebug()<<"tassa mennaan";


    foreach (const QJsonValue &value, json_array)
    {
    QJsonObject json_obj = value.toObject();
    Tapahtumat+=QString::number(json_obj["idTilitapahtumat"].toInt())+" |   PVM: "+json_obj["aika"].toString()+"    |   Tapahtuma: "+json_obj["Tapahtuma"].toString()+"  |   Summa: "+QString::number(json_obj["Maara"].toInt())+"\r";
    }

    Tapahtumat2= Tapahtumat;
   // qDebug()<<Tapahtumat;
    if (Tapahtumat == ""){
        ListanLoppu=1;
         Tapahtumat2= Tapahtumat;
      //  qDebug()<<"töttöröö";
        ui->label_Eilisaa->setText("EI ENEMPÄÄ TILITAPAHTUMIA");
    }
    ui->textBrowser_2->setText(Tapahtumat);
    reply3->deleteLater();
    naytaTilitapahtumatManager->deleteLater();
}


void Tilitapahtumat::on_pushButton_NaytaVahemman_clicked()
{
    offsetmuuttuja= offsetmuuttuja-10;
    if (offsetmuuttuja < 0)
    {   offsetmuuttuja = 0;
        Naytatilitapahtumat();
    }

    qDebug()<<offsetmuuttuja;
    ui->label_Eilisaa->setText("");

    Naytatilitapahtumat();

    timerCounter=0;
}


void Tilitapahtumat::on_pushButton_Palaa_clicked()
{
        disconnect(olioTilitapahtumatQtimer,SIGNAL(timeout()),this,SLOT(TilitapahtumatTimerSlot()));
        olioTilitapahtumatQtimer->stop();
        timerCounter=0;

        olioToimintosivuQtimer->start(1000);
        this->close();
}


void Tilitapahtumat::on_pushButton_NaytaLisaa_clicked()
{

    qDebug()<<offsetmuuttuja;

    if (Tapahtumat2 == ""){
    Naytatilitapahtumat();
   //ui->label_Eilisaa->setText("EI ENEMPÄÄ TILITAPAHTUMIA");
    }
    else
    {   qDebug()<<"tassa mennaan2";
        offsetmuuttuja= offsetmuuttuja+10;

     Naytatilitapahtumat();
    }
    timerCounter=0;
}

void Tilitapahtumat::TilitapahtumatTimerSlot()
{
    timerCounter++;
    qDebug()<<"Tilitapahtumat timer "<<timerCounter;

    if (timerCounter==timerAika2)
    {
        olioTilitapahtumatQtimer->stop();
        disconnect(olioTilitapahtumatQtimer,SIGNAL(timeout()),this,SLOT(TilitapahtumatTimerSlot()));
        qDebug()<<"Timer stop";
        timerCounter = 0;
        this->close();
        olioToimintosivuQtimer->start(1000);
    }
}
