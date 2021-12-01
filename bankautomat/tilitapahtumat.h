#ifndef TILITAPAHTUMAT_H
#define TILITAPAHTUMAT_H

#include <QDialog>
#include <QJsonObject>
#include <QJsonDocument>
#include <QNetworkAccessManager>
#include <QString>

namespace Ui {
class Tilitapahtumat;
}

class Tilitapahtumat : public QDialog
{
    Q_OBJECT

public:
    explicit Tilitapahtumat(QString test2, QWidget *parent = 0);
    ~Tilitapahtumat();

private:
    Ui::Tilitapahtumat *ui;
    QNetworkAccessManager *naytaTilitapahtumatManager;
    QString urli;
    QNetworkReply *reply3;

private slots:
    void naytaTilitapahtumatSlot (QNetworkReply *reply3);
};

#endif // TILITAPAHTUMAT_H
