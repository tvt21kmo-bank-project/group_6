#ifndef TIMER2_H
#define TIMER2_H

#include <QObject>
#include <QDialog>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkAccessManager>
#include <QString>
#include <QNetworkReply>
#include <QTimer>

#include <QMainWindow>
#include <QtNetwork>

class Timer2 : public QObject
{
    Q_OBJECT
public:
    explicit Timer2(QObject *parent = nullptr);
    ~Timer2();

    void Timerkayntiin();

 QTimer *olioQtimer2;

    int timerCounter3 = 0;
    int timerAika3 = 10;
private:


public slots:
    void timerSlot();

signals:

};

#endif // TIMER2_H
