#ifndef APUSIVU_H
#define APUSIVU_H


#include <QTimer>


//#include <QtGlobal>

/*

QT_BEGIN_NAMESPACE
class QString;
QT_END_NAMESPACE
*/


extern short timerCounter;
extern short timerCounter2;
extern short timerAika1;
extern short timerAika2;
extern short korttiTyyppi;

extern QTimer *olioQtimer;
extern QTimer *olioTyyppiQtimer;
extern QTimer *olioPinQtimer;
extern QTimer *olioToimintosivuQtimer;
extern QTimer *olioNostaRahaaQtimer;
extern QTimer *olioPanoQtimer;
extern QTimer *olioTilitapahtumatQtimer;
extern QTimer *olioSaldosivuQtimer;

extern int Debit_Credit;


#endif // APUSIVU_H
