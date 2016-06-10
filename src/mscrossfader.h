#ifndef MSCROSSFADER_H
#define MSCROSSFADER_H

//#include <QDeclarativeItem>
#include <QMainWindow>
#include <QObject>
//#include <QQuickItem>
//#include <QSharedDataPointer>
//#include <QWidget>
#include "control/controlproxy.h"

//class MSCrossFaderData;

class MSCrossFader
{
public:
    MSCrossFader();
    void performTransition();
    double getCrossFader();
    void setCrossFader(double);
//    MSCrossFader(const MSCrossFader &);
//    MSCrossFader &operator=(const MSCrossFader &);
    ~MSCrossFader();

private:
//    QSharedDataPointer<MSCrossFaderData> data;
    ControlProxy* mscrossfad;
};

#endif // MSCROSSFADER_H
