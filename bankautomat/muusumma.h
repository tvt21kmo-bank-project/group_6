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
//#include "toimintosivu.h"

namespace Ui {
class MuuSumma;
}

class MuuSumma : public QDialog
{
    Q_OBJECT

public:
    explicit MuuSumma(QString test2, QWidget *parent = nullptr);
    ~MuuSumma();

    void connectTimerMuusumma();
    void connectTimerMuuPano();

private slots:
    void on_pushButton_MuuSummaSET_clicked();

    void MuusummaTimerSlot();
    void MuuPanoTimerSlot();

private:
    Ui::MuuSumma *ui;

   int MuuSumma1 = 0;

   QNetworkAccessManager *loginManager;
   QNetworkReply *reply;
   QString kayttis;

};

#endif // MUUSUMMA_H
