#ifndef TILITAPAHTUMAT_H
#define TILITAPAHTUMAT_H

#include <QDialog>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkAccessManager>
#include <QString>
#include <QNetworkReply>
#include <QtNetwork>
#include "apusivu.h"

namespace Ui {
class Tilitapahtumat;
}

class Tilitapahtumat : public QDialog
{
    Q_OBJECT

public:
    explicit Tilitapahtumat(QString test2, QWidget *parent = 0);
    ~Tilitapahtumat();

private:
    Ui::Tilitapahtumat *ui;
    QNetworkAccessManager *naytaTilitapahtumatManager;
    QString urli;
    QNetworkReply *reply3;
    int offsetmuuttuja = 0;
    QString kayttis;
    void Naytatilitapahtumat();
    QString Tapahtumat2;
    int ListanLoppu=0;


private slots:
    void naytaTilitapahtumatSlot (QNetworkReply *reply3);
    void on_pushButton_KirjauduUlos_clicked();
    void on_pushButton_Palaa_clicked();
    void on_pushButton_NaytaLisaa_clicked();
};

#endif // TILITAPAHTUMAT_H
