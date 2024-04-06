#include "vex.h"
#include <cmath>
// #include "drive.h"

double LKp = 0;
double LKi = 0;
double LKd = 0;
double AKp = 0;
double AKi = 0;
double AKd = 0;
int osc_count = 0;
bool oscval = false;
double linaddval = 0.5;
double angaddval = 0.5;
double Terr = 0;

void conditions(){
    chassis.set_drive_exit_conditions(0.1, 20, 1500);
    chassis.set_turn_exit_conditions(0.1, 20, 1000);
}

int recursion(int x,double start, double end){
    if(start > end) return false;
    double midval = (start+end)/2;
    if(midval == x) return true;
    else if(x < midval) return recursion(x,start,midval);
    else return recursion(x,midval,end);
}

void osc(int tar, int PD){
    // float start_average_position = (chassis.get_left_position_in()+chassis.get_right_position_in())/2.0;
    if(tar == 1){
        Terr = std::abs(24 - chassis.errlin); 
        if(Terr < 2){
            // count++;
            oscval = 0;
        }
        else oscval = 1;
    }
    else if(tar == 2){
        Terr = std::abs(90 - chassis.errang); 
        if(Terr < 2){
            // count++;
            oscval = 0;
        }
        else oscval = 1;
    }
}

void osc_finder_lin(int PID){
    conditions();
    if(PID == 1){
        while(1){
            chassis.set_drive_constants(12, LKp, 0, 0, 0);
            chassis.drive_distance(24);
            osc(1,1);
            chassis.drive_distance(-24);
            if(oscval == true){
                printf("Linear KP: %f\n",LKp);
            }
            LKp += linaddval;
            wait(20,msec);
        }
    }
    else if(PID == 2){
        while(1){
            chassis.set_drive_constants(12, LKp, LKi, 0, 0);
            chassis.drive_distance(24);
            osc(1,0);
            chassis.drive_distance(-24);
            if(oscval == true){
                printf("Linear KI: %f\n",LKi);
            }
            LKp += linaddval;
            wait(20,msec);
        }
    }
    else if(PID == 3){
        while(1){
            chassis.set_drive_constants(12, LKp, LKi, LKd, 0);
            chassis.drive_distance(24);
            osc(1,2);
            chassis.drive_distance(-24);
            if(oscval == true){
                printf("Linear KD: %f\n",LKi);
            }
            LKp += linaddval;
            wait(20,msec);
        }
    }
    
}

void osc_finder_ang(int PID){
    conditions();
    if(PID == 1){
        while(1){
            chassis.set_drive_constants(12, AKp, 0, 0, 15);
            chassis.turn_to_angle(90);
            osc(2,1);
            if(oscval == true){
                printf("Angular KP: %f\n",AKp);
            }
            AKp += angaddval;
            wait(20,msec);
        }
    }
    else if(PID == 2){
        while(1){
            chassis.set_drive_constants(12, AKp, AKi, 0, 15);
            chassis.turn_to_angle(90);
            osc(2,0);
            if(oscval == true){
                printf("Angular KP: %f\n",AKp);
            }
            AKp += angaddval;
            wait(20,msec);
        }
    }
    else if(PID == 3){
        while(1){
            chassis.set_drive_constants(12, AKp, AKi, AKd, 15);
            chassis.turn_to_angle(90);
            osc(2,2);
            if(oscval == true){
                printf("Angular KP: %f\n",AKp);
            }
            AKp += angaddval;
            wait(20,msec);
        }
    }
}

void tunelinear(int PID){
    conditions();
    chassis.set_drive_constants(12, LKp, LKi, LKd, 0);
}

void tuneangular(int PID){
    conditions();
    chassis.set_turn_constants(12, AKp, AKi, AKd, 15);
}