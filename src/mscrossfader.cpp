#include "mscrossfader.h"
#include "control/controlproxy.h"


MSCrossFader::MSCrossFader(){
    mscrossfad = new ControlProxy("[Master]", "crossfader");

}

void MSCrossFader::performTransition(){
    int i = 0;
    while(i<1000){
        if(i%100 == 0){
            setCrossFader(((i/100)%2));
        }
    }
}


double MSCrossFader::getCrossFader(){
    return mscrossfad->get();
}


void MSCrossFader::setCrossFader(double value){
    //double current_val = mscrossfad_.get(); //Will be used
    mscrossfad->set(value);
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


