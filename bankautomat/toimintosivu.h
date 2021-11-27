#ifndef TOIMINTOSIVU_H
#define TOIMINTOSIVU_H

#include <QDialog>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkAccessManager>
#include <QString>

namespace Ui {
class Toimintosivu;
}

class Toimintosivu : public QDialog
{
    Q_OBJECT

public:
    explicit Toimintosivu(QString test, QWidget *parent = nullptr);
    ~Toimintosivu();






private slots:


    void on_pushButtonKirjauduUlos2_clicked();

    void on_pushButtonSaldo_clicked();

    void naytaSaldoSlot (QNetworkReply *reply);

private:
    Ui::Toimintosivu *ui;

    QNetworkAccessManager *naytaSaldoManager;
    QNetworkReply *reply;
    QNetworkReply *reply2;
    QNetworkAccessManager *naytaAsiakasManager;

    QString urli;
    QString testi6;




};

#endif // TOIMINTOSIVU_H
