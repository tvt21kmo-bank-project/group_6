#ifndef TIMER_H
#define TIMER_H

#include <QDialog>
#include <QTimer>
#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QThread>
//#include <QObject>



class Timer : QObject
{
    Q_OBJECT

public:
    explicit Timer();
    ~Timer();
    QTimer *olioQtimer;

    short timerCounter;

private:


private slots:
    void myTimerSlot();

};

#endif // TIMER_H
