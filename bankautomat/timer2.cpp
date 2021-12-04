#include "timer2.h"

Timer2::Timer2(QObject *parent) : QObject(parent)
{
    olioQtimer2 = new QTimer;

    connect(olioQtimer2,SIGNAL(timeout()),this,SLOT(timerSlot()));
    connect(olioQtimer2,SIGNAL(timeout()),this,SLOT(suljePaasivu()));

}

Timer2::~Timer2()
{
    delete olioQtimer2;
    olioQtimer2 = nullptr;
}

void Timer2::Timerkayntiin()
{
    olioQtimer2->start(1000);
}

void Timer2::timerSlot()
{
    timerCounter3++;
    qDebug()<<"hellurei timer "<<timerCounter3;

    if (timerCounter3==timerAika3)
    {
       //77 olioQtimer2->stop();
        qDebug()<<"Timer stop";
        //timerCounter3 = 0;
       // ui->labelHylatty->setText("");
       //this->close();
    }
}
