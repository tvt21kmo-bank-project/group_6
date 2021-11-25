#ifndef TOIMINTOSIVU_H
#define TOIMINTOSIVU_H

#include <QDialog>
#include <QJsonObject>
#include <QJsonDocument>

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
    void on_btnTesti_clicked();

private:
    Ui::Toimintosivu *ui;



};

#endif // TOIMINTOSIVU_H
