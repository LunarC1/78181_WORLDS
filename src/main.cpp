#include "vex.h"
#include "usercontrol.hpp"
#include "vexfield.h"
#include "logo.h"
#include "rlogo.h"
#include "autofunctions.h"
#include <cmath>
#include <iomanip>
#include "sensorcheck.h"

using namespace vex;
competition Competition;

Drive chassis(
//ZERO_TRACKER_NO_ODOM, ZERO_TRACKER_ODOM, TANK_ONE_ENCODER, TANK_ONE_ROTATION, TANK_TWO_ENCODER, TANK_TWO_ROTATION, HOLONOMIC_TWO_ENCODER, and HOLONOMIC_TWO_ROTATION
ZERO_TRACKER_NO_ODOM,

//Left Motors:
motor_group(LF,LM,LB),

//Right Motors:
motor_group(RF,RM,RB),

//Inertial Port
PORT7,

//Wheel Diameter
3.25,

//Gear ratio
0.75,

//Gyro scale
352,

/*---------------------------------------------------------------------------*/
/*                                  PAUSE!                                   */
/*---------------------------------------------------------------------------*/

//HOLO DT

//LF:      //RF:    
PORT1,     -PORT2,

//LB:      //RB: 
PORT3,     -PORT4,

//If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
//Rotation sensor: "PORT1"
//Encoder: Triport A will be "1", 
3,

//Forward Tracker diameter
2.75,

//Forward Tracker center distance
-2,

//Sideways Tracker Port
1,

//Sideways tracker diameter
-2.75,

//Sideways tracker center distance
5.5

);

int current_auton_selection = 0;
bool auto_started = false;
int autonState = 0; 

void debug_menu(int selection){
  // int inertialval;
  bool debug_is_pressed = false;
  while(1){
    float inertialval = Inertial100.heading();
    if(debug_is_pressed == false){
      Brain.Screen.drawImageFromBuffer(vexfield, 50, 0, sizeof(vexfield));
      Brain.Screen.drawImageFromBuffer(logo, 10, 0, sizeof(logo));
      Brain.Screen.setPenWidth(4); 
      Brain.Screen.setFont(monoL); 
      Brain.Screen.drawLine(310,0,310,240); 
      Brain.Screen.drawLine(310,70,480,70); 
      Brain.Screen.setFillColor(black); 
      Brain.Screen.setFont(mono40);
      Brain.Screen.setFillColor(blue);
      Brain.Screen.drawRectangle(310,70,170,210);
      Brain.Screen.printAt(345,140,"Debug");
      Brain.Screen.setFont(monoM);
      Brain.Screen.printAt(345,180,"Inertial:");
      Brain.Screen.printAt(345,195,"%f",inertialval);
    }
    if(Brain.Screen.pressing()){
      Brain.Screen.clearScreen();
      waitUntil(Brain.Screen.pressing() == false);
        debug_is_pressed =!debug_is_pressed;
    }
    if(debug_is_pressed == true){
      Brain.Screen.setFillColor(clearerr); 
      Brain.Screen.setFont(mono30);
      Brain.Screen.setPenColor(blue);
      Brain.Screen.printAt(155, 40, "Debug Menu:");
      Brain.Screen.setFont(mono20);
      Brain.Screen.setPenColor(white);
      Brain.Screen.printAt(20, 90, "Heading:%f",std::floor(Inertial100.heading()));
      Brain.Screen.printAt(20, 140, "Battery:%f",std::floor(Brain.Battery.capacity()));
      Brain.Screen.printAt(20, 190, "DT Avg Temp:%f",std::floor((LF.temperature(percent)+LM.temperature(percent)+LB.temperature(percent)+RF.temperature(percent)+RM.temperature(percent)+RB.temperature(percent))/6));
      Brain.Screen.printAt(270, 90, "Hang Temp:%f",std::floor(cataMotor.temperature(percent)));
      Brain.Screen.printAt(270, 140, "Intake Temp:%f",std::floor(intakeMotor.temperature(percent)));
      Brain.Screen.printAt(270, 190, "Kicker Temp:%f",std::floor(kicker.temperature(percent)));
    }
    if(limitselect.pressing()){
      waitUntil(limitselect.pressing());
      break;
    }
    wait(20,msec);
  }
}

void pre_auton(void) {
  vexcodeInit();
  default_constants();
  printf("Battery: %f \n",std::round(Brain.Battery.capacity()));
  intakeMotor.setStopping(hold);
  back_wings.set(false);
  back_wings2.set(false);
  hangrot.resetPosition(); 
  hangrot.setPosition(0, rotationUnits::rev); 
  Brain.Screen.clearScreen();
  while(1) {
    switch(autonState) {
      case 0:
        Brain.Screen.setPenWidth(4);
        Brain.Screen.setFont(monoL);
        Brain.Screen.setFillColor(black); 
        Brain.Screen.printAt(350, 43, "AWP");
        debug_menu(0);
        break; 
      case 1:
        Brain.Screen.setPenWidth(4);
        Brain.Screen.setFont(monoL);
        Brain.Screen.setFillColor(black); 
        Brain.Screen.printAt(350, 43, "Safe Six");
        debug_menu(1);
        break; 
      case 2:
        Brain.Screen.setPenWidth(4);
        Brain.Screen.setFont(monoL);
        Brain.Screen.setFillColor(black); 
        Brain.Screen.printAt(350, 43, "Steal AWP");
        debug_menu(2);
        break; 
      case 3:
        Brain.Screen.setPenWidth(4);
        Brain.Screen.setFont(monoL);
        Brain.Screen.setFillColor(black); 
        Brain.Screen.printAt(350, 43, "Sixball");
        debug_menu(3);
        break; 
      case 4:
        Brain.Screen.setPenWidth(4); 
        Brain.Screen.setFont(monoL);
        Brain.Screen.setFillColor(black); 
        Brain.Screen.printAt(350, 43, "Safe Five");
        debug_menu(4);
        break; 
      case 5:
        Brain.Screen.setPenWidth(4); 
        Brain.Screen.setFont(monoL);
        Brain.Screen.setFillColor(black); 
        Brain.Screen.printAt(350, 43, "Skills");
        debug_menu(5);
        break;
      default:
        Brain.Screen.setPenWidth(4); 
        Brain.Screen.setFont(monoL);
        Brain.Screen.setFillColor(black); 
        Brain.Screen.printAt(350, 43, "AWP");
        debug_menu(0);
        break;
    }
    if(limitselect.pressing()){
      while(limitselect.pressing()) {}
      Brain.Screen.clearScreen();
      autonState++; 
    }
    if(autonState>5) autonState = 0; 
  }
}

void autonomous(void) {
  switch(autonState){  
    case 0:
      // testing();
      // ramAWP2();
      noramAWP2();
      // Worlds_Skills();
      // Worlds_Skills();
      // sixball();
      // Safesix();
      // RushNoRamAWP();
      // PID_Test();
      // Worlds_Skills();
      // sixdisrupt();
      break;
    case 1:
    // noramAWP2();
      Safesix();
      break;
    case 2:
      // Safesix();
      RushNoRamAWP();
      break;  
    case 3:
      // RushNoRamAWP();
      sixball();
      break;
    case 4:
      // sixball();
      fiveballtouch();
      break;
    case 5:
      // fiveballtouch();
      Worlds_Skills();
      break;
    default:
      noramAWP2();
      break;
  }
}

void usercontrol(void) {
  task Suck1task(UC_Intake);
  task Launchtask(UC_Slapper);
  task Releasetask(UC_frontwings);
  task Ratchettask(pistonratchett);
  task verhormac(horvert);
  checkBattery();
  checkMotor(intakeMotor);
  checkMotor(LF);
  checkMotor(LM);
  checkMotor(LB);
  checkMotor(RF);
  checkMotor(RM);
  checkMotor(RB);
  while(1){
    chassis.control_arcade();
    if(Controller1.ButtonY.pressing() && autonState == 5){
      chassis.drive_max_voltage = 11.2;
      chassis.set_drive_exit_conditions(0.5, 20, 1000);
      chassis.set_turn_exit_conditions(0.4, 20, 900);
      back_wings.set(true);
      wait(120,msec);
      back_wings.set(false);
      chassis.diff(-45, -80, 1700, 300);
      chassis.set_heading(180);
      chassis.drive_distance(10);
      chassis.turn_to_angle(69.2);
      chassis.drive_distance(-4);
      back_wings2.set(true);
    }
    wait(20,msec);
  }
}

int main() {
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);
  pre_auton();
  while (true) {
    wait(100, msec);
  }
} 