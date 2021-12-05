#ifndef APUSIVU_H
#define APUSIVU_H

#include <QMainWindow>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QThread>

class apusivu : public QObject
{
    Q_OBJECT
public:
    explicit apusivu(QObject *parent = nullptr);
    ~apusivu();

    short timerCounter = 0;
    short timerCounter2 = 0;;
    short timerAika1 = 5;
    short timerAika2 = 10;



    QTimer *olioQtimer;
    QTimer *olioTyyppiQtimer;
    QTimer *olioPinQtimer;
    QTimer *olioToimintosivuQtimer;
    QTimer *olioNostaRahaaQtimer;
    QTimer *olioPanoQtimer;

signals:

};

#endif // APUSIVU_H
