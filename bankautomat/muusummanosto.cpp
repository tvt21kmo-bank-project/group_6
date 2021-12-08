#include "muusummanosto.h"
#include "ui_muusummanosto.h"

// timer tanne kun painettu nostettava summa, niin palais kayttoliittymaaan

MuuSummaNosto::MuuSummaNosto(QString test2, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MuuSummaNosto)
{
    ui->setupUi(this);
    kayttis=test2;
}

MuuSummaNosto::~MuuSummaNosto()
{
    delete ui;
}

void MuuSummaNosto::on_pushButton_MuuSummaNosto_clicked()
{
    QJsonObject json; //luodaan JSON objekti ja lisätään data
       // MuuSumma1 = ui->lineEdit_MuuSumma->text();

       // json.insert("summa",ui->LineEdit_pinKoodi->text());
        qDebug()<<kayttis;
        json.insert("idKortti",kayttis);
        json.insert("summa",ui->lineEdit_MuuNosto->text());
        json.insert("Tila1", Debit_Credit);
        QString site_url="http://localhost:3000/debitnosto/nostarahaa";
        QString credentials="newAdmin:newPass";
        QNetworkRequest request((site_url));
        request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
        QByteArray data = credentials.toLocal8Bit().toBase64();
        QString headerData = "Basic " + data;
        request.setRawHeader( "Authorization", headerData.toLocal8Bit() );
        loginManager = new QNetworkAccessManager(this);
        connect(loginManager, SIGNAL(finished (QNetworkReply*)),
        this, SLOT(naytaSaldoSlot3(QNetworkReply*)));
        reply = loginManager->post(request, QJsonDocument(json).toJson());


}

void MuuSummaNosto::naytaSaldoSlot3(QNetworkReply *reply4)
{
    QByteArray response_data=reply4->readAll();
    ui->label_MuuNosto->setText(response_data);

}

