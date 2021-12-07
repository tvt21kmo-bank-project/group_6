#ifndef NOSTARAHAA_H
#define NOSTARAHAA_H

#include <QDialog>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkAccessManager>
#include <QString>
#include <QNetworkReply>

#include <QMainWindow>
#include <QtNetwork>

#include "muusumma.h"
//#include "toimintosivu.h"
#include "apusivu.h"
#include "muusummanosto.h"

namespace Ui {
class NostaRahaa;
}

class NostaRahaa : public QDialog
{
    Q_OBJECT

public:
    explicit NostaRahaa(QString test2, QWidget *parent = nullptr);
    ~NostaRahaa();

private slots:
    void on_pushButton_20_clicked();

    void on_pushButton_Palaa_clicked();

    void naytaSaldoSlot2 (QNetworkReply *reply3);

    void nostaRahaaTimerSlot();

    void on_pushButton_Muu_Summa_clicked();

    void on_pushButton_200_clicked();

    void on_pushButton_40_clicked();

    void on_pushButton_60_clicked();

    void on_pushButton_80_clicked();

    void on_pushButton_100_clicked();

private:
    Ui::NostaRahaa *ui;
    //QNetworkAccessManager *debitManager;
    //QNetworkReply *reply;
   // Toimintosivu *olioToimintosivu;
    QNetworkAccessManager *naytaSaldoManager2;
    QNetworkReply *reply3;

    QString kayttis;
    MuuSummaNosto *olioMuuSummaNosto;


};

#endif // NOSTARAHAA_H
