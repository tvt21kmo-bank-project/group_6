#ifndef MUUSUMMANOSTO_H
#define MUUSUMMANOSTO_H

#include <QDialog>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkAccessManager>
#include <QString>
#include <QNetworkReply>

#include <QMainWindow>
#include <QtNetwork>

namespace Ui {
class MuuSummaNosto;
}

class MuuSummaNosto : public QDialog
{
    Q_OBJECT

public:
    explicit MuuSummaNosto(QString test2, QWidget *parent = nullptr);
    ~MuuSummaNosto();

private slots:
    void on_pushButton_MuuSummaNosto_clicked();

    void naytaSaldoSlot3 (QNetworkReply *reply4);

private:
    Ui::MuuSummaNosto *ui;
    QNetworkAccessManager *loginManager;
    QNetworkReply *reply;
    QString kayttis;
    QNetworkReply *reply4;
};

#endif // MUUSUMMANOSTO_H
