#ifndef PAASIVU_H
#define PAASIVU_H

#include <QDialog>

#include <QTimer>

#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

#include "tyyppi.h"
#include "apusivu.h"
#include "timer2.h"

namespace Ui {
class paaSivu;
}

class paaSivu : public QDialog
{
    Q_OBJECT

public:
    explicit paaSivu(QWidget *parent = nullptr);
    ~paaSivu();

    void paaSivuSulku();

private slots:
    void on_kirjauduNappi_clicked();
    void on_takaisinNappi_clicked();

    void kirjauduSisaan(QNetworkReply *reply);

public slots:
    void myTimerSlot();
    void myPinTimerSlot();


private:
    Ui::paaSivu *ui;
    //short timerCounter;
    //QTimer *olioQtimer;

    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;

    Tyyppi *oliotyyppi;
    QString kayttajaTunnus;
    int vaaraPin = 0;


signals:

};

#endif // PAASIVU_H
