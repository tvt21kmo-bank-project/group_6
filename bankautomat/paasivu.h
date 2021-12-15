#ifndef PAASIVU_H
#define PAASIVU_H

#include <QDialog>

#include <QTimer>

#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QThread>

#include "tyyppi.h"
#include "apusivu.h"

namespace Ui {
class paaSivu;
}

class paaSivu : public QDialog
{
    Q_OBJECT

public:
    explicit paaSivu(QWidget *parent = nullptr);
    ~paaSivu();

private slots:
    void on_kirjauduNappi_clicked();
    void on_takaisinNappi_clicked();

    void kirjauduSisaan(QNetworkReply *reply);

public slots:
    void myTimerSlot();
    void myPinTimerSlot();
    void KortinTyyppiSlot(QNetworkReply *reply8);
    void KorttiLukittuSlot(QNetworkReply *reply12);


private:
    Ui::paaSivu *ui;
    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QNetworkAccessManager *haeKorttiManager;
    QNetworkAccessManager *haeKorttiManager2;
    QNetworkReply *reply8;

    Tyyppi *oliotyyppi;
    QString kayttajaTunnus;
    int vaaraPin = 0;
    void KortinTyyppi();
    QString Tapahtumat2 = 0;
    void KorttiLukittu();
    int Kortinlukitus = 3;


signals:

};

#endif // PAASIVU_H
