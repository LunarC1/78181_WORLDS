#include "vex.h"
#include "usercontrol.hpp"
#include "autofunctions.hpp"

using namespace vex;
competition Competition;

/*---------------------------------------------------------------------------*/
/*                             VEXcode Config                                */
/*                                                                           */
/*  Before you do anything else, start by configuring your motors and        */
/*  sensors using the V5 port icon in the top right of the screen. Doing     */
/*  so will update robot-config.cpp and robot-config.h automatically, so     */
/*  you don't have to. Ensure that your motors are reversed properly. For    */
/*  the drive, spinning all motors forward should drive the robot forward.   */
/*---------------------------------------------------------------------------*/

/*---------------------------------------------------------------------------*/
/*                             JAR-Template Config                           */
/*                                                                           */
/*  Where all the magic happens. Follow the instructions below to input      */
/*  all the physical constants and values for your robot. You should         */
/*  already have configured your robot manually with the sidebar configurer. */
/*---------------------------------------------------------------------------*/


Drive chassis(

//Specify your drive setup below. There are seven options:
//ZERO_TRACKER_NO_ODOM, ZERO_TRACKER_ODOM, TANK_ONE_ENCODER, TANK_ONE_ROTATION, TANK_TWO_ENCODER, TANK_TWO_ROTATION, HOLONOMIC_TWO_ENCODER, and HOLONOMIC_TWO_ROTATION
//For example, if you are not using odometry, put ZERO_TRACKER_NO_ODOM below:
ZERO_TRACKER_ODOM,
// ZERO_TRACKER_NO_ODOM,

//Add the names of your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).
//You will input whatever motor names you chose when you configured your robot using the sidebar configurer, they don't have to be "Motor1" and "Motor2".

//Left Motors:
motor_group(LF,LM,LB),

//Right Motors:
motor_group(RF,RM,RB),

//Specify the PORT NUMBER of your inertial sensor, in PORT format (i.e. "PORT1", not simply "1"):
PORT1,

//Input your wheel diameter. (4" omnis are actually closer to 4.125"):
4,

//External ratio, must be in decimal, in the format of input teeth/output teeth.
//If your motor has an 84-tooth gear and your wheel has a 60-tooth gear, this value will be 1.4.
//If the motor drives the wheel directly, this value is 1:
0.57,

//Gyro scale, this is what your gyro reads when you spin the robot 360 degrees.
//For most cases 360 will do fine here, but this scale factor can be very helpful when precision is necessary.
360,

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

int autonState = 0; 
// int current_auton_selection = 0;
// bool auto_started = false;

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  default_constants();
  Inertial1.calibrate();
  intakeMotor.setStopping(hold);
  bool limitval = false;
  Brain.Screen.clearScreen();

  while(1){
    switch(autonState){
      case 0: 
        Brain.Screen.printAt(50, 50, "default");
        break;
      case 1: 
        Brain.Screen.printAt(50, 50, "AWP");
        break;
      case 2: 
        Brain.Screen.printAt(50, 50, "Sixball");
        break;
      case 3: 
        Brain.Screen.printAt(50, 50, "Rush + AWP");
        break;
      case 4: 
        Brain.Screen.printAt(50, 50, "Skills");
        break;
      case 5: 
        Brain.Screen.printAt(50, 50, "Skills");
        break;
    }
    if(limitselect.pressing()){
      while(limitselect.pressing()) {}
      autonState++; 
    if(autonState>5){
      autonState = 0; 
    }
    }
  }
}

void autonomous(void) {
  switch(autonState){
    case 0: 
      // skills3(); 
      AWP();
      // sixball();
      break;
    case 1: 
      AWP();  
      break;
    case 2: 
      sixball(); 
      break;
    case 3: 
      RushAWP(); 
      break;
    case 4: 
      skills3();
      break;
    case 5:
      sixball_safe();
      break;
  }
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*----------------------------------------------- ----------------------------*/

void usercontrol(void) {
  task Suck1task(UC_Intake);
  task Launchtask(UC_Slapper);
  task Extendtask(UC_Hang);
  task Releasetask(UC_frontwings);
  task Extask(UC_backwings);
  task Endgametask(UC_distance);
  task lightsabertask(UC_stick);
  task setuptask(UC_setup);
  Brain.Screen.clearScreen();
  // bool setup_io = false;
  while (1) {
    chassis.control_arcade();
    if(Controller1.ButtonY.pressing()){
      chassis.set_drive_exit_conditions(0.3, 10, 600);;
      chassis.set_heading(315);
      intakeMotor.spin(reverse,60,percent);
      chassis.drive_distance(17);
      chassis.turn_to_angle(62);
      chassis.drive_distance(-2);
      back_wings.set(true);
      intakeMotor.stop(hold);
      // cataMotor.spin(forward,67,percent);
      // cataMotor1.spin(forward,67,percent);
      // // wait(3,sec);
      // wait(21,sec);
      // cataMotor.stop(brake);
      // cataMotor1.stop(brake);
      // back_wings.set(false);
      
    }
    // if(Controller1.ButtonUp.pressing()){
    //   setup_io = !setup_io;
    // }
    // if(setup_io==true){
    //   cataMotor.spin(forward,67,percent);
    //   cataMotor1.spin(forward,67,percent);
    // }
    // else{
    //   cataMotor.stop(coast);
    //   cataMotor1.stop(coast);
    // }
    // else if(setup_io==false){
    //   cataMotor.stop(coast);
    //   cataMotor1.stop(coast);
    // }
    wait(20, msec);
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
