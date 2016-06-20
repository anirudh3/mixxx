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

//class MSCrossFaderData;

class MSCrossFader: public QObject
{
    Q_OBJECT
public:
    MSCrossFader();
    void performTransition();
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
    ControlProxy* getBPM;
    //ControlLinPotmeter* getEngBPM;

};

#endif // MSCROSSFADER_H
