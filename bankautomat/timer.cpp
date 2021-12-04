#include "timer.h"

timer::timer() :
{
    olioQtimer2 = new QTimer;

    connect(olioQtimer2,SIGNAL(timeout()),this,SLOT(timerSlot()));
}

timer::~timer()
{
    delete olioQtimer2;
    olioQtimer2 = nullptr;
}


void timer::timerSlot()
{
    timerCounter2++;
    qDebug()<<"paasivu timer "<<timerCounter2;

    if (timerCounter2==timerAika3)
    {
        olioQtimer2->stop();
        qDebug()<<"Timer stop";
        timerCounter2 = 0;
       // ui->labelHylatty->setText("");
       // this->close();
    }
}
