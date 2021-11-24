#ifndef PAASIVU_H
#define PAASIVU_H

#include <QDialog>
#include <qnetworkaccessmanager.h>
#include <QTimer>
#include <QDebug>

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
    void myTimerSlot();
    void loginSlot (QNetworkReply *reply);

private:
    Ui::paaSivu *ui;
    short timerCounter;
    QTimer *olioQtimer;
    QNetworkAccessManager *loginManager;            //lis'tty
    QNetworkAccessManager *reply;                   //lis'tty

signals:

};

#endif // PAASIVU_H
