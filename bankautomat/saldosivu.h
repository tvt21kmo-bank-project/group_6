#ifndef SALDOSIVU_H
#define SALDOSIVU_H

#include <QDialog>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkAccessManager>
#include <QString>
#include <QNetworkReply>
#include <QtNetwork>
#include "apusivu.h"

namespace Ui {
class Saldosivu;
}

class Saldosivu : public QDialog
{
    Q_OBJECT

public:
    explicit Saldosivu(QString test2, QWidget *parent = nullptr);
    ~Saldosivu();
    void naytaTilitapahtumat();
    void naytaSaldo();

private:
    Ui::Saldosivu *ui;
    QString urli;
    QNetworkAccessManager *naytaSaldoManager;
    QNetworkReply *reply;
    QNetworkReply *reply3;
    QNetworkAccessManager *naytaAsiakasManager;
    QNetworkAccessManager *naytaTilitapahtumatManager;


private slots:
    void naytaTilitapahtumatSlot (QNetworkReply *reply3);
    void naytaSaldotapahtumatSlot (QNetworkReply *reply3);
    void SaldosivuTimerSlot();
    void on_pushButton_takaisin_clicked();

};

#endif // SALDOSIVU_H
