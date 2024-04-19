#include "vex.h"
#include "usercontrol.hpp"
#include "vexfield.h"
#include "logo.h"
#include "rlogo.h"
#include "autofunctions.hpp"
#include <cmath>
#include <iomanip>
using namespace vex;
competition Competition;

Drive chassis(

//Specify your drive setup below. There are seven options:
//ZERO_TRACKER_NO_ODOM, ZERO_TRACKER_ODOM, TANK_ONE_ENCODER, TANK_ONE_ROTATION, TANK_TWO_ENCODER, TANK_TWO_ROTATION, HOLONOMIC_TWO_ENCODER, and HOLONOMIC_TWO_ROTATION
//For example, if you are not using odometry, put ZERO_TRACKER_NO_ODOM below:
// ZERO_TRACKER_ODOM,
ZERO_TRACKER_NO_ODOM,

//Add the names of your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).
//You will input whatever motor names you chose when you configured your robot using the sidebar configurer, they don't have to be "Motor1" and "Motor2".

//Left Motors:
motor_group(LF,LM,LB),

//Right Motors:
motor_group(RF,RM,RB),

//Specify the PORT NUMBER of your inertial sensor, in PORT format (i.e. "PORT1", not simply "1"):
PORT7,

//Input your wheel diameter. (4" omnis are actually closer to 4.125"):
3.25,

//External ratio, must be in decimal, in the format of input teeth/output teeth.
//If your motor has an 84-tooth gear and your wheel has a 60-tooth gear, this value will be 1.4.
//If the motor drives the wheel directly, this value is 1:
0.75,

//Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
//For most cases 360 will do fine here, but this scale factor can be very helpful when precision is necessary.
352,

/*---------------------------------------------------------------------------*/
/*                                  PAUSE!                                   */
/*                                                                           */
/*  The rest of the drive constructor is for robots using POSITION TRACKING. */
/*  If you are not using position tracking, leave the rest of the values as  */
/*  they are.                                                                */
/*---------------------------------------------------------------------------*/

//If you are using ZERO_TRACKER_ODOM, you ONLY need to adjust the FORWARD TRACKER CENTER DISTANCE.

//FOR HOLONOMIC DRIVES ONLY: Input your drive motors by position. This is only necessary for holonomic drives, otherwise this section can be left alone.
//LF:      //RF:    
PORT1,     -PORT2,

//LB:      //RB: 
PORT3,     -PORT4,

//If you are using position tracking, this is the Forward Tracker port (the tracker which runs parallel to the direction of the chassis).
//If this is a rotation sensor, enter it in "PORT1" format, inputting the port below.
//If this is an encoder, enter the port as an integer. Triport A will be a "1", Triport B will be a "2", etc.
3,

//Input the Forward Tracker diameter (reverse it to make the direction switch):
2.75,

//Input Forward Tracker center distance (a positive distance corresponds to a tracker on the right side of the robot, negative is left.)
//For a zero tracker tank drive with odom, put the positive distance from the center of the robot to the right side of the drive.
//This distance is in inches:
-2,

//Input the Sideways Tracker Port, following the same steps as the Forward Tracker Port:
1,

//Sideways tracker diameter (reverse to make the direction switch):
-2.75,

//Sideways tracker center distance (positive distance is behind the center of the robot, negative is in front):
5.5

);

void debug_menu(int selection){
  bool debug_is_pressed = false;
  while(1){
    if(debug_is_pressed == false){
      Brain.Screen.drawImageFromBuffer(vexfield, 50, 0, sizeof(vexfield));
      Brain.Screen.drawImageFromBuffer(logo, 10, 0, sizeof(logo));
      Brain.Screen.setPenWidth(4); 
      Brain.Screen.setFont(monoL); 
      Brain.Screen.drawLine(310,0,310,240); 
      Brain.Screen.drawLine(310,70,480,70); 
      Brain.Screen.setFillColor(black); 
      if(selection == 0) Brain.Screen.printAt(350, 43, "AWP");
      else if(selection == 1) Brain.Screen.printAt(350, 43, "Safe Six");
      else if(selection == 2) Brain.Screen.printAt(350, 43, "Steal AWP");
      else if(selection == 3) Brain.Screen.printAt(350, 43, "Sixball");
      else if(selection == 4) Brain.Screen.printAt(350, 43, "Safe Five");
      else if(selection == 5) Brain.Screen.printAt(350, 43, "Skills");
      Brain.Screen.setFont(mono40);
      Brain.Screen.setFillColor(blue);
      Brain.Screen.drawRectangle(310,70,170,210);
      Brain.Screen.printAt(345,160,"Debug");
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
    wait(20,msec);
  }
}

int current_auton_selection = 0;
bool auto_started = false;
int autonState = 0; 

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
  while(1){
    switch(autonState){
      case 0:
        debug_menu(0);
        break; 
      case 1:
        debug_menu(1);
        break; 
      case 2:
        debug_menu(2);
        break; 
      case 3:
        debug_menu(3);
        break; 
      case 4:
        debug_menu(4);
        break; 
      case 5:
        debug_menu(5);
        break; 

      default:
        debug_menu(0);
        break;
    }
    if(limitselect.pressing()){
      while(limitselect.pressing()) {}
      Brain.Screen.clearScreen();
      autonState++; 
    }
    else if(autonState>4){
      autonState = 0; 
    }
  }
}

void autonomous(void) {
  switch(autonState){  
    case 0:
      // testing();
      // ramAWP2();
      noramAWP2();
      // sixball();
      // Safesix();
      // RushNoRamAWP();
      // Worlds_Skills();
      break;
    case 1:
      Safesix();
      break;
    case 2:
      RushNoRamAWP();
      break;  
    case 3:
      sixball();
      break;
    case 4:
      fiveballtouch();
      break;
    case 5:
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

  while (1) {
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
      chassis.turn_to_angle(69.5);
      chassis.drive_distance(-4);
      back_wings2.set(true);
    }
    wait(20, msec);
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