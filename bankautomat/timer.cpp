#include "timer.h"


Timer::Timer()
{
    olioQtimer = new QTimer;
    timerCounter = 0;

    //connect(olioQtimer,SIGNAL(timeout()),this,SLOT(myTimerSlot()));
}


void Timer::myTimerSlot()
{
    timerCounter++;
    qDebug()<<timerCounter;


    if (timerCounter==10)
    {
        olioQtimer->stop();
        qDebug()<<"Timer stop";
        timerCounter = 0;
        //olioPaaSivu->close();
    }
}


Timer::~Timer()
{

}
