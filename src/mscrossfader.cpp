#include "mscrossfader.h"
#include "control/controlproxy.h"
//#include "control/controllinpotmeter.h"


MSCrossFader::MSCrossFader(){
    mscrossfad = new ControlProxy("[Master]", "crossfader");
    getBPM = new ControlProxy(ConfigKey("[Channel1]","bpm"));
    //getEngBPM = new ControlLinPotmeter(ConfigKey("[Channel1]", "bpm"));

}

void MSCrossFader::performTransition(){
    double i = 1.0;
    setCrossFader(1.0);
//    while(i<1000){
//        if(i%100 == 0){
//            setCrossFader(((i/100)%2));
//        }
//    }

}

double MSCrossFader::getCrossFader(){
    double val = mscrossfad->get();
    //printf("cross fader value in mscrossfader:%d", val);
    //qDebug() << "Inside getCrossFader, with value: %f" << val;

    //qDebug() << "The BPM right now:" << (getEngBPM->get());
    return val;
}


void MSCrossFader::setCrossFader(double value){
    //double current_val = mscrossfad_.get(); //Will be used
    mscrossfad->set(value);
}


double MSCrossFader::getBPMnow(){
    qDebug() << "The BPM right now:" << (getBPM->get());
    return getBPM->get();
}

double MSCrossFader::fadercalc(int nBars){

    double bpm = getBPMnow();
    double time = nBars/bpm * 240;

    return time;

}


MSCrossFader::~MSCrossFader(){
    delete mscrossfad;

}





































//class MSCrossFaderData : public QSharedData
//{
//public:

//};

//MSCrossFader::MSCrossFader() : data(new MSCrossFaderData)
//{

//}

//MSCrossFader::MSCrossFader(const MSCrossFader &rhs) : data(rhs.data)
//{

//}

//MSCrossFader &MSCrossFader::operator=(const MSCrossFader &rhs)
//{
//    if (this != &rhs)
//        data.operator=(rhs.data);
//    return *this;
//}


