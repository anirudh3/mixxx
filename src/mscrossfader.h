#ifndef MSCROSSFADER_H
#define MSCROSSFADER_H

//#include <QDeclarativeItem>
#include <QMainWindow>
#include <QObject>
//#include <QQuickItem>
//#include <QSharedDataPointer>
//#include <QWidget>
#include "control/controlproxy.h"
#include "control/controllinpotmeter.h"
#include <QThread>

//class MSCrossFaderData;

class MSCrossFader: public QObject
{
    Q_OBJECT
public:
    MSCrossFader();
    void performTransition(int channel);
    double getCrossFader();
    void setCrossFader(double);
    double getBPMnow();
    double fadercalc(int nBars);
//    MSCrossFader(const MSCrossFader &);
//    MSCrossFader &operator=(const MSCrossFader &);
    ~MSCrossFader();

private:
//    QSharedDataPointer<MSCrossFaderData> data;
    ControlProxy* mscrossfad;
    ControlProxy* getBPML;
    ControlProxy* getBPMR;
    ControlProxy* getHiFil;
    ControlProxy* getMiFil;
    ControlProxy* getLoFilL;
    ControlProxy* getLoFilR;

    //ControlLinPotmeter* getEngBPM;

};

class Sleeper : public QThread
{
public:
    static void usleep(unsigned long usecs){QThread::usleep(usecs);}
    static void msleep(unsigned long msecs){QThread::msleep(msecs);}
    static void sleep(unsigned long secs){QThread::sleep(secs);}
};

#endif // MSCROSSFADER_H
