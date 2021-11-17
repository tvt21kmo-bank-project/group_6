#ifndef PAASIVU_H
#define PAASIVU_H

#include <QDialog>

#include <QTimer>

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
    void myTimerSlot();

private:
    Ui::paaSivu *ui;
    short timerCounter;
    QTimer *olioQtimer;

signals:

};

#endif // PAASIVU_H
