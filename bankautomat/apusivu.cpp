#include "apusivu.h"

apusivu::apusivu(QObject *parent) : QObject(parent)
{

    olioQtimer = new QTimer;

    olioPinQtimer = new QTimer;

    olioTyyppiQtimer = new QTimer;

    olioNostaRahaaQtimer = new QTimer;

    olioToimintosivuQtimer = new QTimer;

    olioPanoQtimer = new QTimer;

   // connect(olioQtimer,SIGNAL(timeout()),this,SLOT(myTimerSlot()));
}

apusivu::~apusivu()
{

}
