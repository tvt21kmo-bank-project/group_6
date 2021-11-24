#ifndef PAASIVU_H
#define PAASIVU_H

#include <QDialog>

#include <QTimer>

#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>

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

    void testi(QNetworkReply *reply);

private:
    Ui::paaSivu *ui;
    short timerCounter;
    QTimer *olioQtimer;

    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;

signals:

};

#endif // PAASIVU_H
