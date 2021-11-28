#ifndef TOIMINTOSIVU_H
#define TOIMINTOSIVU_H

#include <QDialog>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkAccessManager>
#include <QString>
#include "nostarahaa.h"

namespace Ui {
class Toimintosivu;
}

class Toimintosivu : public QDialog
{
    Q_OBJECT

public:
    explicit Toimintosivu(QString test, QWidget *parent = nullptr);
    ~Toimintosivu();

    //QString testi9;




    //void setOlioNostarahaa(NostaRahaa *newOlioNostarahaa);

    void setKayttajatunnus2(const QString &newKayttajatunnus2);

private slots:


    void on_pushButtonKirjauduUlos2_clicked();

    void on_pushButtonSaldo_clicked();

    void naytaSaldoSlot (QNetworkReply *reply);

    void naytaAsiakasSlot (QNetworkReply *reply2);

    void on_pushButtonNosta_clicked();

private:
    Ui::Toimintosivu *ui;

    QNetworkAccessManager *naytaSaldoManager;
    QNetworkReply *reply;
    QNetworkReply *reply2;
    QNetworkAccessManager *naytaAsiakasManager;



    NostaRahaa *olioNostarahaa;
    QString urli;
    QString kayttajatunnus2;



};

#endif // TOIMINTOSIVU_H
