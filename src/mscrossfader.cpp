#include "mscrossfader.h"
#include "control/controlproxy.h"
#include <QThread>

//#include "control/controllinpotmeter.h"


MSCrossFader::MSCrossFader(){
    mscrossfad = new ControlProxy("[Master]", "crossfader");
    getBPML = new ControlProxy(ConfigKey("[Channel1]","bpm"));
    getBPMR = new ControlProxy(ConfigKey("[Channel2]", "bpm"));
    getLoFilL = new ControlProxy(ConfigKey("[Channel1]", "filterLow"));
    getLoFilR = new ControlProxy(ConfigKey("[Channel2]", "filterLow"));

    //getEngBPM = new ControlLinPotmeter(ConfigKey("[Channel1]", "bpm"));

}

void MSCrossFader::performTransition(int channel){
    //double i = 1.0;

    if(channel == 1){
        qDebug() << "INSIDE LEFT";
    }
    else{
        getLoFilR->set(0.1);
        qDebug() << "INSIDE RIGHT";
    }

    //setCrossFader(1.0);
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
    qDebug() << "Channel1 Filter Value:" << getLoFilL->get();
    qDebug() << "Channel2 Filter Value:" << getLoFilR->get();
    return val;
}


void MSCrossFader::setCrossFader(double value){
    //double current_val = mscrossfad_.get(); //Will be used
    mscrossfad->set(value);
}


double MSCrossFader::getBPMnow(){
    qDebug() << "The BPM right now:" << (getBPML->get());
    return getBPML->get();
}

double MSCrossFader::fadercalc(int nBars){

    double bpm = getBPMnow();
    double time = nBars/bpm * 240;

    return time;

}


MSCrossFader::~MSCrossFader(){
    delete mscrossfad;

}



