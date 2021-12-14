#ifndef TOIMINTOSIVU_H
#define TOIMINTOSIVU_H

#include <QDialog>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkAccessManager>
#include <QString>
#include "nostarahaa.h"
#include "pano.h"
#include "tilitapahtumat.h"
#include "saldosivu.h"

namespace Ui {
class Toimintosivu;
}

class Toimintosivu : public QDialog
{
    Q_OBJECT

public:
    explicit Toimintosivu(QString test, QWidget *parent = nullptr);
    ~Toimintosivu();
    void setKayttajatunnus2(const QString &newKayttajatunnus2);
    void tarkistaTyyppi();
    void connectTimerToimintosivu();

private slots:


    void on_pushButtonKirjauduUlos2_clicked();

    void on_pushButtonSaldo_clicked();

    void naytaAsiakasSlot (QNetworkReply *reply2);

    void on_pushButtonNosta_clicked();

    void on_pushButtonTilitapahtumat_clicked();

    void on_pushButtonPane_clicked();

    void toimintosivuTimerSlot();

private:
    Ui::Toimintosivu *ui;

    QNetworkReply *reply;
    QNetworkReply *reply2;
    QNetworkAccessManager *naytaAsiakasManager;




    NostaRahaa *olioNostarahaa;
    Pano *olioPano;
    QString urli;
    QString kayttajatunnus2;
    Tilitapahtumat *olioTilitapahtumat;
    Saldosivu *olioSaldoSivu;



};

#endif // TOIMINTOSIVU_H
