#ifndef MUUSUMMA_H
#define MUUSUMMA_H

#include <QDialog>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkAccessManager>
#include <QString>
#include <QNetworkReply>

#include <QMainWindow>
#include <QtNetwork>
#include "apusivu.h"

namespace Ui {
class MuuSumma;
}

class MuuSumma : public QDialog
{
    Q_OBJECT

public:
    explicit MuuSumma(QString test2, QWidget *parent = nullptr);
    ~MuuSumma();

private slots:
    void on_pushButton_MuuSummaSET_clicked();
    void naytaSaldoSlot4(QNetworkReply *reply);

private:
    Ui::MuuSumma *ui;

   int MuuSumma1 = 0;

   QNetworkAccessManager *loginManager;
   QNetworkReply *reply;
   QString kayttis;

};

#endif // MUUSUMMA_H
