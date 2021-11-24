#ifndef TYYPPI_H
#define TYYPPI_H

#include <QDialog>
#include <QDebug>

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

private slots:
    void on_pushButtonCredit_clicked();

    void on_pushButtonDebit_clicked();

    void on_pushButtonKirjauduUlos_clicked();

private:
    Ui::Tyyppi *ui;

};

#endif // TYYPPI_H
