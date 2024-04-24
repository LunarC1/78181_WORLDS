#include "vex.h"
#include <cmath>

int horhang(){
    double hangpos;
    while(1){
        hangpos = std::abs(hangrot.position(rotationUnits::rev));
        while(hangpos <= 1.15){
            hangpos = std::abs(hangrot.position(rotationUnits::rev));
            cataMotor.spin(forward,-100,pct);
            wait(20,msec);
            // if(startTimeA >= break_condition1) break;
        }
        cataMotor.stop(hold);
    }
}