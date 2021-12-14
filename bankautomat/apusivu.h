#ifndef APUSIVU_H
#define APUSIVU_H

#include <QTimer>

extern short timerCounter;
extern short timerCounter2;
extern short timerAika1;
extern short timerAika2;
extern short timerAika3;
extern short korttiTyyppi;

extern QTimer *olioQtimer;
extern QTimer *olioTyyppiQtimer;
extern QTimer *olioPinQtimer;
extern QTimer *olioToimintosivuQtimer;
extern QTimer *olioNostaRahaaQtimer;
extern QTimer *olioPanoQtimer;
extern QTimer *olioTilitapahtumatQtimer;
extern QTimer *olioSaldosivuQtimer;
extern QTimer *olioMuusummaQtimer;
extern QTimer *olioMuuPanoQtimer;
extern QTimer *olioMuuNostoQtimer;
extern QTimer *olioMuuNostoPaQtimer;

extern int Debit_Credit;


#endif // APUSIVU_H
