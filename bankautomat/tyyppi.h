#ifndef TYYPPI_H
#define TYYPPI_H

#include <QDialog>
#include <QDebug>
#include "toimintosivu.h"
#include "apusivu.h"
//#include "mainwindow.h"

namespace Ui {
class Tyyppi;
}

class Tyyppi : public QDialog
{
    Q_OBJECT

public:
    explicit Tyyppi(QWidget *parent = nullptr);
    ~Tyyppi();

    void setKayttajaTunnus(const QString &newKayttajaTunnus);

private slots:
    void on_pushButtonCredit_clicked();
    void on_pushButtonDebit_clicked();
    void on_pushButtonKirjauduUlos_clicked();

    void MyTimerTyyppiSlot();

private:
    Ui::Tyyppi *ui;
    Toimintosivu *olioToimintoSivu;
    QString kayttajaTunnus;
    apusivu *olioApusivu;

};

#endif // TYYPPI_H
