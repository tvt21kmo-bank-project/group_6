#ifndef PAASIVU_H
#define PAASIVU_H

#include <QDialog>

namespace Ui {
class paaSivu;
}

class paaSivu : public QDialog
{
    Q_OBJECT

public:
    explicit paaSivu(QWidget *parent = nullptr);
    ~paaSivu();

private slots:
    void on_kirjauduNappi_clicked();
    void on_takaisinNappi_clicked();

private:
    Ui::paaSivu *ui;
signals:

};

#endif // PAASIVU_H
