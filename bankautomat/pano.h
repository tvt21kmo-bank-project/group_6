#ifndef PANO_H
#define PANO_H

#include <QDialog>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkAccessManager>
#include <QString>
#include <QNetworkReply>

#include <QMainWindow>
#include <QtNetwork>
#include "muusumma.h"
#include "apusivu.h"


namespace Ui {
class Pano;
}

class Pano : public QDialog
{
    Q_OBJECT

public:
    explicit Pano(QString test2, QWidget *parent = nullptr);
    ~Pano();
    void setKayttajatunnus2(const QString &newKayttajatunnus2);

private slots:
    void on_pushButton_pane20_clicked();

    //void naytaSaldoSlot2 (QNetworkReply *reply3);

    void on_pushButton_Palaa_clicked();

    void on_pushButton_MuuPano_clicked();

    void on_pushButtonKuuskymppia_clicked();

    void PaneTimerSlot();

    void on_pushButtonSatane_clicked();

    void on_pushButtonNelkyt_clicked();

    void on_pushButtonKaksSataa_clicked();

private:
    Ui::Pano *ui;

    QNetworkAccessManager *naytaSaldoManager2;
    QNetworkReply *reply3;

    QString kayttis;

    MuuSumma *olioMuuSumma;

    QString kayttajatunnus2;




};

#endif // PANO_H
