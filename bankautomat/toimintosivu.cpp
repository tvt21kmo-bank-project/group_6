#include "toimintosivu.h"
#include "ui_toimintosivu.h"
#include "paasivu.h"


Toimintosivu::Toimintosivu(QString test, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Toimintosivu)
{
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
    delete olioToimintosivuQtimer;
    delete olioTilitapahtumat;
    delete olioSaldoSivu;
    olioToimintosivuQtimer = nullptr;
    olioNostarahaa = nullptr;
    olioPano = nullptr;
    olioTilitapahtumat = nullptr;
    olioSaldoSivu = nullptr;

}

void Toimintosivu::on_pushButtonKirjauduUlos2_clicked()
{
    this->close();
    olioToimintosivuQtimer->stop();
    qDebug()<<"kirjaudu ulos painettu";
    disconnect(olioToimintosivuQtimer,SIGNAL(timeout()),this,SLOT(toimintosivuTimerSlot()));
    timerCounter = 0;
}

void Toimintosivu::on_pushButtonSaldo_clicked()
{
    olioSaldoSivu = new Saldosivu(kayttajatunnus2);
    olioSaldoSivu->show();
    olioSaldoSivu->naytaSaldo();
    olioSaldoSivu->naytaTilitapahtumat();

    olioToimintosivuQtimer->stop();
    olioSaldoSivu->connectTimerSaldo();
}

/*void Toimintosivu::naytaSaldoSlot(QNetworkReply *reply)
{
    QByteArray response_data=reply->readAll();
    ui->textBrowserSaldo->setText("Tilin Saldo: "+response_data);   
}*/

void Toimintosivu::on_pushButtonNosta_clicked()
{
   // disconnect(olioToimintosivuQtimer,SIGNAL(timeout()),this,SLOT(toimintosivuTimerSlot()));
   // connect(olioNostaRahaaQtimer,SIGNAL(timeout()),this,SLOT(nostaRahaaTimerSlot()));
    olioToimintosivuQtimer->stop();

    olioNostarahaa = new NostaRahaa(kayttajatunnus2); //Nostarahaa(kayttajatunnus2);
    olioNostarahaa->show();
    olioNostarahaa->nostaTimerConnect();
}

void Toimintosivu::setKayttajatunnus2(const QString &newKayttajatunnus2)
{
    kayttajatunnus2 = newKayttajatunnus2;
}

void Toimintosivu::tarkistaTyyppi()
{

    if (Debit_Credit == 0){
    ui->pushButtonPane->setText("Lyhennä luottoa");
    ui->label_Credit_debit->setText("Credit");
    //tahan kaikki mita muokataan
    qDebug()<<Debit_Credit;
    qDebug()<<"toimintosivu";
    }
    else {
    ui->pushButtonPane->setText("Pane rahaa");
    ui->label_Credit_debit->setText("Debit");
    //tahan kaikki mita muokataan
    }
}

void Toimintosivu::connectTimerToimintosivu()
{
    connect(olioToimintosivuQtimer,SIGNAL(timeout()),this,SLOT(toimintosivuTimerSlot()));
    timerCounter=0;
    olioToimintosivuQtimer->start(1000);
}



void Toimintosivu::on_pushButtonTilitapahtumat_clicked()
{
    olioTilitapahtumat = new Tilitapahtumat(kayttajatunnus2);
    olioToimintosivuQtimer->stop();


    olioTilitapahtumat->show();
   // disconnect(olioToimintosivuQtimer,SIGNAL(timeout()),this,SLOT(toimintosivuTimerSlot()));
    olioTilitapahtumat->connectTimerTilitapahtumat();

}

void Toimintosivu::on_pushButtonPane_clicked()
{
    olioPano = new Pano(kayttajatunnus2); //Nostarahaa(kayttajatunnus2);
    olioPano->show();  
    olioToimintosivuQtimer->stop();
    olioPano->panoTimerConnect();
}

void Toimintosivu::toimintosivuTimerSlot()
{
    timerCounter++;
    qDebug()<<"toimintosivu timer "<<timerCounter;

    if (timerCounter==timerAika2)
    {
        olioToimintosivuQtimer->stop();
        qDebug()<<"Timer stop";
        disconnect(olioToimintosivuQtimer,SIGNAL(timeout()),this,SLOT(toimintosivuTimerSlot()));
        timerCounter = 0;
        this->close();
    }
}

