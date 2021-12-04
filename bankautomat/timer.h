#ifndef TIMER_H
#define TIMER_H

#include <QDialog>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkAccessManager>
#include <QString>
#include <QNetworkReply>
#include <QTimer>

#include <QMainWindow>
#include <QtNetwork>


class timer : public QDialog
{

    Q_OBJECT

public:
    timer();
    ~timer();

    QTimer *olioQtimer2;

    int timerCounter2;
    int timerAika3;

public slots:
    void timerSlot();

private:

};

#endif // TIMER_H
