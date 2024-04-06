#include "vex.h"
#include "usercontrol.hpp"
#include "vexfield.h"
#include "logo.h"
#include "rlogo.h"
#include "autofunctions.hpp"
#include "button.h"
#include <cmath>
#include <iomanip>
// #include <string>
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
// ZERO_TRACKER_ODOM,
ZERO_TRACKER_NO_ODOM,

//Add the names of your Drive motors into the motor groups below, separated by commas, i.e. motor_group(Motor1,Motor2,Motor3).
//You will input whatever motor names you chose when you configured your robot using the sidebar configurer, they don't have to be "Motor1" and "Motor2".

//Left Motors:
motor_group(LF,LM,LB),

//Right Motors:
motor_group(RF,RM,RB),

//Specify the PORT NUMBER of your inertial sensor, in PORT format (i.e. "PORT1", not simply "1"):
PORT14,

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

int autonState = 0; 
// int current_auton_selection = 0;
// bool auto_started = false;

int horvert(){
  double hangpos;
  bool ver_is_pressed = false;
  bool hor_is_pressed = false;
  hangrot.resetPosition(); 
  while(1){
    hangpos = std::abs(hangrot.position(rotationUnits::rev));
    // Brain.Screen.printAt(200, 120, "Position:%f\n",hangpos);
    if(Controller1.ButtonA.pressing() && hor_is_pressed == false){ //Click once, set ratchet to false, lift up
      // pistonratchet.set(false);
      // ratchet = false;
      while(hangpos <= 1.15){
        hangpos = std::abs(hangrot.position(rotationUnits::rev));
        cataMotor.spin(forward,-100,pct);
        // Brain.Screen.printAt(200, 120, "Position:%f\n",hangpos);
        wait(20,msec);
      }
      cataMotor.stop(hold);
      hor_is_pressed = true;
    }
    else if(Controller1.ButtonA.pressing() && hor_is_pressed == true){ //Click another time, set ratchet to true, lift down
      // pistonratchet.set(true);
      // ratchet = true;
      while(hangpos >= 0.01){
        hangpos = std::abs(hangrot.position(rotationUnits::rev));
        cataMotor.spin(forward,100,pct);
        wait(20,msec);
      }
      cataMotor.stop(hold);
    }

    if(Controller1.ButtonB.pressing() && ver_is_pressed == false){ //Click once, set ratchet to false, lift up
      // pistonratchet.set(false);
      // ratchet = false;
      while(hangpos <= 3.8){
        cataMotor.spin(forward,-100,pct);
        hangpos = std::abs(hangrot.position(rotationUnits::rev));
        wait(20,msec);
      }
      cataMotor.stop(hold);
      ver_is_pressed = true;
    }
    else if(Controller1.ButtonB.pressing() && ver_is_pressed == true){ //Click another time, set ratchet to true, lift down
      // ratchet = true;
      // pistonratchet.set(true);z
      while(hangpos >= 0.125){
        cataMotor.spin(forward,100,pct);
        hangpos = std::abs(hangrot.position(rotationUnits::rev));
        wait(20,msec);
      }
      cataMotor.stop(hold);
    }

    if(Controller1.ButtonDown.pressing()){ //Manual Lift function
      // pistonratchet.set(false);
      // ratchet = false;
      cataMotor.spin(forward,100,percent);
    }
    else if (Controller1.ButtonUp.pressing()){
      // pistonratchet.set(true);
      // ratchet = true;
      cataMotor.spin(forward,-100,percent);
    }
    else cataMotor.stop(hold);
  }
    wait(20,msec);
}

int pistonratchet2(){
  bool ratchet = false;
  while(1){
    if(Controller1.ButtonX.pressing()){ // Piston Ratchet function
      waitUntil(Controller1.ButtonX.pressing() == false);
      ratchet =!ratchet;
      if(ratchet == true){
        Controller1.Screen.clearScreen();
      Controller1.Screen.setCursor(1,1);
        Controller1.Screen.print("Ratchet Engaged");
      }
      else if(ratchet == false){
        Controller1.Screen.clearScreen();
        Controller1.Screen.setCursor(1,1);
        Controller1.Screen.print("Ratchet NOT Engaged");
      }
    }
    pistonratchet.set(ratchet);
    wait(20,msec);
  }
}

// double round_to(double value, double precision = 1.0){
//     return std::round(value / precision) * precision;
// }

// int rounding(double x){
//   int myx = (int)x;
//   while(myx%10!=0) x/=10;
//   return x;
// }

void debug_menu(int c){
  bool debug_is_pressed = false;
  bool selector_is_pressed = buttons[1].state;
  Brain.Screen.pressed( userTouchCallbackPressed );
  Brain.Screen.released( userTouchCallbackReleased );
  displayButtonControls( 0, false );
  // double heading = std::round(Inertial100.heading());
  // double battery = std::floor(Brain.Battery.capacity());
  // double temp = std::floor((LF.temperature(percent)+LM.temperature(percent)+LB.temperature(percent)+RF.temperature(percent)+RM.temperature(percent)+RB.temperature(percent))/6);
  while(1){
    // double heading = rounding(Inertial100.heading());
    // double battery = round(Brain.Battery.capacity());
    // double temp = round((LF.temperature(percent)+LM.temperature(percent)+LB.temperature(percent)+RF.temperature(percent)+RM.temperature(percent)+RB.temperature(percent))/6);
    if(debug_is_pressed == false){
      
      // while(is_pressed == false) {Brain.Screen.clearScreen(); break;}
      Brain.Screen.drawImageFromBuffer(vexfield, 50, 0, sizeof(vexfield));
      Brain.Screen.drawImageFromBuffer(logo, 10, 0, sizeof(logo));
      Brain.Screen.setPenWidth(4); 
      Brain.Screen.setFont(monoL); 
      Brain.Screen.drawLine(310,0,310,240); 
      Brain.Screen.drawLine(310,70,480,70); 
      Brain.Screen.setFillColor(black); 
      if(c == 0) Brain.Screen.printAt(350, 43, "AWP");
      else if(c == 1) Brain.Screen.printAt(350, 43, "Sixball");
      else if(c == 2) Brain.Screen.printAt(350, 43, "Steal AWP");
      else if(c == 3) Brain.Screen.printAt(350, 43, "Safe Six");
      else if(c == 4) Brain.Screen.printAt(350, 43, "Rush Five");
      else if(c == 5) Brain.Screen.printAt(350, 43, "Skills");
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
      // Brain.Screen.clearScreen();
      // while(is_pressed == true) { break;}
      
      Brain.Screen.setFillColor(clearerr); 
      // Brain.Screen.printAt(60, 30, "Heading:%f",heading);
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
    // return 0;
  }
  // Brain.Screen.clearScreen();
}

int current_auton_selection = 0;
bool auto_started = false;

void pre_auton(void) {
  vexcodeInit();
  default_constants();
  Brain.Screen.pressed( userTouchCallbackPressed );
  Brain.Screen.released( userTouchCallbackReleased );

  // task DebugTask(debug_menu);
  // Inertial100.calibrate();
  printf("Battery: %f \n",std::round(Brain.Battery.capacity()));
  intakeMotor.setStopping(hold);
  back_wings.set(false);
  back_wings2.set(false);
  hangrot.resetPosition(); 
  hangrot.setPosition(0, rotationUnits::rev); 
  // bool limitval = false;
  Brain.Screen.clearScreen();
  while(1){
    if(Brain.Battery.capacity() > 50 && Brain.Battery.capacity() < 100){
      wait(10,msec);
    }

//     while(auto_started == false){            //Changing the names below will only change their names on the
//       // Brain.Screen.clearScreen();            //brain screen for auton selection.
//       switch(current_auton_selection){       //Tap the brain screen to cycle through autons.
//         case 0:
//           Brain.Screen.drawImageFromBuffer(vexfield, 50, 0, sizeof(vexfield));
//           Brain.Screen.drawImageFromBuffer(logo, 10, 0, sizeof(logo));
//           Brain.Screen.setPenWidth(4); 
//           Brain.Screen.setFont(monoL); 
//           Brain.Screen.drawLine(310,0,310,240); 
//           Brain.Screen.drawLine(310,70,480,70); 
//           Brain.Screen.setFillColor(black); 
//           Brain.Screen.printAt(350, 43, "AWP");
//           Brain.Screen.setFont(monoM); 
//           // Brain.Screen.printAt(320, 100, "Heading:%f",std::round(Inertial100.heading()));
//           // Brain.Screen.printAt(320, 150, "Battery:%f",std::round(Brain.Battery.capacity()));
//           // Brain.Screen.printAt(320, 200, "DT Avg Temp:");
//           // Brain.Screen.printAt(320, 220, "%f",std::round((LF.temperature(percent)+LM.temperature(percent)+LB.temperature(percent)+RF.temperature(percent)+RM.temperature(percent)+RB.temperature(percent))/6));
//           Brain.Screen.setFillColor(red); 
//           Brain.Screen.drawRectangle(310,70,170,210);
//           Brain.Screen.setFont(monoL); 
//           Brain.Screen.printAt(320,160, "Debug Menu");
//           break; 
//         case 1:
//           Brain.Screen.drawImageFromBuffer(vexfield, 50, 0, sizeof(vexfield));
//           Brain.Screen.drawImageFromBuffer(logo, 10, 0, sizeof(logo));
//           Brain.Screen.setPenWidth(4); 
//           Brain.Screen.setFont(monoL); 
//           Brain.Screen.drawLine(310,0,310,240); 
//           Brain.Screen.drawLine(310,70,480,70); 
//           Brain.Screen.drawCircle(170, 18, 12); 
//           Brain.Screen.drawCircle(280, 18, 12); 
//           Brain.Screen.printAt(350, 43, "AWP");
//           break; 
//         case 2:
//           Brain.Screen.drawImageFromBuffer(vexfield, 50, 0, sizeof(vexfield));
//           Brain.Screen.drawImageFromBuffer(logo, 10, 0, sizeof(logo));
//           Brain.Screen.setPenWidth(4); 
//           Brain.Screen.setFont(monoL); 
//           Brain.Screen.drawLine(310,0,310,240); 
//           Brain.Screen.drawLine(310,70,480,70); 
//           Brain.Screen.drawCircle(170, 18, 12); 
//           Brain.Screen.drawCircle(280, 18, 12); 
//           Brain.Screen.drawCircle(210, 115, 12); 
//           Brain.Screen.printAt(335, 43, "Steal AWP");
//           break; 
//         case 3:
//           Brain.Screen.drawImageFromBuffer(vexfield, 50, 0, sizeof(vexfield));
//           Brain.Screen.drawImageFromBuffer(logo, 10, 0, sizeof(logo));
//           Brain.Screen.setPenWidth(4); 
//           Brain.Screen.setFont(monoL); 
//           Brain.Screen.drawLine(310,0,310,240); 
//           Brain.Screen.drawLine(310,70,480,70); 
//           Brain.Screen.drawCircle(70, 18, 12); 
//           Brain.Screen.drawCircle(170, 18, 12); 
//           Brain.Screen.drawCircle(130, 120, 12); 
//           Brain.Screen.drawCircle(160, 120, 12); 
//           Brain.Screen.drawCircle(160, 80, 12); 
//           Brain.Screen.printAt(315, 43, "Safe 6 Ball");
//           break; 
//         case 4:
//           Brain.Screen.drawImageFromBuffer(vexfield, 50, 0, sizeof(vexfield));
//           Brain.Screen.drawImageFromBuffer(logo, 10, 0, sizeof(logo));
//           Brain.Screen.setPenWidth(4); 
//           Brain.Screen.setFont(monoL); 
//           Brain.Screen.drawLine(310,0,310,240); 
//           Brain.Screen.drawLine(310,70,480,70); 
//           Brain.Screen.drawCircle(70, 18, 12); 
//           Brain.Screen.drawCircle(130, 120, 12); 
//           Brain.Screen.drawCircle(160, 120, 12); 
//           Brain.Screen.drawCircle(160, 80, 12); 
//           Brain.Screen.printAt(315, 43, "Rush 5 Ball");
//           break; 
//         case 5:
//           Brain.Screen.drawImageFromBuffer(vexfield, 50, 0, sizeof(vexfield));
//           Brain.Screen.drawImageFromBuffer(logo, 10, 0, sizeof(logo));
//           Brain.Screen.setPenWidth(4); 
//           Brain.Screen.setFont(monoL); 
//           Brain.Screen.drawLine(310,0,310,240); 
//           Brain.Screen.drawLine(310,70,480,70); 
//           Brain.Screen.printAt(320, 43, "Skills");
//           break; 
//       }
//       if(Brain.Screen.pressing()){
//         while(Brain.Screen.pressing()) {}
//         Brain.Screen.clearScreen();
//         autonState ++;
//       } else if (current_auton_selection == 8){
//         autonState = 0;
//       }
//       task::sleep(10);
//     }
//   }
// }
    
    switch(autonState){
        case 0:
          // Brain.Screen.drawImageFromBuffer(vexfield, 50, 0, sizeof(vexfield));
          // Brain.Screen.drawImageFromBuffer(logo, 10, 0, sizeof(logo));
          // Brain.Screen.setPenWidth(4); 
          // Brain.Screen.setFont(monoL); 
          // Brain.Screen.drawLine(310,0,310,240); 
          // Brain.Screen.drawLine(310,70,480,70); 
          // Brain.Screen.setFillColor(black); 
          // Brain.Screen.printAt(350, 43, "AWP");
          // Brain.Screen.setFont(monoM); 
          // Brain.Screen.printAt(320, 100, "Heading:%f",std::round(Inertial100.heading()));
          // Brain.Screen.printAt(320, 150, "Battery:%f",std::round(Brain.Battery.capacity()));
          // Brain.Screen.printAt(320, 200, "DT Avg Temp:");
          // Brain.Screen.printAt(320, 220, "%f",std::round((LF.temperature(percent)+LM.temperature(percent)+LB.temperature(percent)+RF.temperature(percent)+RM.temperature(percent)+RB.temperature(percent))/6));
          debug_menu(0);
          // Brain.Screen.setFillColor(blue); 
          // Brain.Screen.drawRectangle(310,70,480,240);
          break; 
        case 1:
          // Brain.Screen.drawImageFromBuffer(vexfield, 50, 0, sizeof(vexfield));
          // Brain.Screen.drawImageFromBuffer(logo, 10, 0, sizeof(logo));
          // Brain.Screen.setPenWidth(4); 
          // Brain.Screen.setFont(monoL); 
          // Brain.Screen.drawLine(310,0,310,240); 
          // Brain.Screen.drawLine(310,70,480,70); 
          // Brain.Screen.drawCircle(170, 18, 12); 
          // Brain.Screen.drawCircle(280, 18, 12); 
          // Brain.Screen.printAt(350, 43, "Sixball");
          // Brain.Screen.setFont(monoM); 
          // // Brain.Screen.printAt(320, 100, "Heading:%f",std::round(Inertial100.heading()));
          // // Brain.Screen.printAt(320, 150, "Battery:%f",std::round(Brain.Battery.capacity()));
          // // Brain.Screen.printAt(320, 200, "DT Avg Temp:");
          // // Brain.Screen.printAt(320, 220, "%f",std::round((LF.temperature(percent)+LM.temperature(percent)+LB.temperature(percent)+RF.temperature(percent)+RM.temperature(percent)+RB.temperature(percent))/6));
          debug_menu(1);
          break; 
        case 2:
          // Brain.Screen.drawImageFromBuffer(vexfield, 50, 0, sizeof(vexfield));
          // Brain.Screen.drawImageFromBuffer(logo, 10, 0, sizeof(logo));
          // Brain.Screen.setPenWidth(4); 
          // Brain.Screen.setFont(monoL); 
          // Brain.Screen.drawLine(310,0,310,240); 
          // Brain.Screen.drawLine(310,70,480,70); 
          // Brain.Screen.drawCircle(170, 18, 12); 
          // Brain.Screen.drawCircle(280, 18, 12); 
          // Brain.Screen.drawCircle(210, 115, 12); 
          // Brain.Screen.printAt(335, 43, "Steal AWP");
          // Brain.Screen.setFont(monoM); 
          // Brain.Screen.printAt(320, 100, "Heading:%f",std::round(Inertial100.heading()));
          // Brain.Screen.printAt(320, 150, "Battery:%f",std::round(Brain.Battery.capacity()));
          // Brain.Screen.printAt(320, 200, "DT Avg Temp:");
          // Brain.Screen.printAt(320, 220, "%f",std::round((LF.temperature(percent)+LM.temperature(percent)+LB.temperature(percent)+RF.temperature(percent)+RM.temperature(percent)+RB.temperature(percent))/6));
          debug_menu(2);
          break; 
        case 3:
          // Brain.Screen.drawImageFromBuffer(vexfield, 50, 0, sizeof(vexfield));
          // Brain.Screen.drawImageFromBuffer(logo, 10, 0, sizeof(logo));
          // Brain.Screen.setPenWidth(4); 
          // Brain.Screen.setFont(monoL); 
          // Brain.Screen.drawLine(310,0,310,240); 
          // Brain.Screen.drawLine(310,70,480,70); 
          // Brain.Screen.drawCircle(70, 18, 12); 
          // Brain.Screen.drawCircle(170, 18, 12); 
          // Brain.Screen.drawCircle(130, 120, 12); 
          // Brain.Screen.drawCircle(160, 120, 12); 
          // Brain.Screen.drawCircle(160, 80, 12); 
          // Brain.Screen.printAt(315, 43, "Safe 6 Ball");
          // Brain.Screen.setFont(monoM); 
          // Brain.Screen.printAt(320, 100, "Heading:%f",std::round(Inertial100.heading()));
          // Brain.Screen.printAt(320, 150, "Battery:%f",std::round(Brain.Battery.capacity()));
          // Brain.Screen.printAt(320, 200, "DT Avg Temp:");
          // Brain.Screen.printAt(320, 220, "%f",std::round((LF.temperature(percent)+LM.temperature(percent)+LB.temperature(percent)+RF.temperature(percent)+RM.temperature(percent)+RB.temperature(percent))/6));
          debug_menu(3);
          break; 
        case 4:
          // Brain.Screen.drawImageFromBuffer(vexfield, 50, 0, sizeof(vexfield));
          // Brain.Screen.drawImageFromBuffer(logo, 10, 0, sizeof(logo));
          // Brain.Screen.setPenWidth(4); 
          // Brain.Screen.setFont(monoL); 
          // Brain.Screen.drawLine(310,0,310,240); 
          // Brain.Screen.drawLine(310,70,480,70); 
          // Brain.Screen.drawCircle(70, 18, 12); 
          // Brain.Screen.drawCircle(130, 120, 12); 
          // Brain.Screen.drawCircle(160, 120, 12); 
          // Brain.Screen.drawCircle(160, 80, 12); 
          // Brain.Screen.printAt(315, 43, "Rush 5 Ball");
          // Brain.Screen.setFont(monoM); 
          // Brain.Screen.printAt(320, 100, "Heading:%f",std::round(Inertial100.heading()));
          // Brain.Screen.printAt(320, 150, "Battery:%f",std::round(Brain.Battery.capacity()));
          // Brain.Screen.printAt(320, 200, "DT Avg Temp:");
          // Brain.Screen.printAt(320, 220, "%f",std::round((LF.temperature(percent)+LM.temperature(percent)+LB.temperature(percent)+RF.temperature(percent)+RM.temperature(percent)+RB.temperature(percent))/6));
          debug_menu(4);
          break; 
        case 5:
          // Brain.Screen.drawImageFromBuffer(vexfield, 50, 0, sizeof(vexfield));
          // Brain.Screen.drawImageFromBuffer(logo, 10, 0, sizeof(logo));
          // Brain.Screen.setPenWidth(4); 
          // Brain.Screen.setFont(monoL); 
          // Brain.Screen.drawLine(310,0,310,240); 
          // Brain.Screen.drawLine(310,70,480,70); 
          // Brain.Screen.printAt(320, 43, "Skills");
          // Brain.Screen.setFont(monoM); 
          // Brain.Screen.printAt(320, 100, "Heading:%f",std::round(Inertial100.heading()));
          // Brain.Screen.printAt(320, 150, "Battery:%f",std::round(Brain.Battery.capacity()));
          // Brain.Screen.printAt(320, 200, "DT Avg Temp:");
          // Brain.Screen.printAt(320, 220, "%f",std::round((LF.temperature(percent)+LM.temperature(percent)+LB.temperature(percent)+RF.temperature(percent)+RM.temperature(percent)+RB.temperature(percent))/6));
          debug_menu(5);
          break; 
    }
    if(limitselect.pressing()){
      while(limitselect.pressing()) {}
      Brain.Screen.clearScreen();
      autonState++; 
    }
    else if(autonState>5){
      autonState = 0; 
    }
  }
}

void autonomous(void) {
  // chassis.set_heading(90);
  // intakeMotor.spin(reverse,30,percent);
  // chassis.diff(-51, -100, 1400, 300);
  // chassis.set_heading(180);
  // chassis.right_swing_to_angle(63);
  // back_wings.set(true);
  // chassis.drive_distance(-2.5);
  // intakeMotor.stop(hold);

  
  // skills3();

  // auto_started = true;
    switch(autonState){  
      case 0:
        Worlds_Skills();
        // ramAWP2();
        // sixball();
        // testing();
        // RushAWP2();
        // PID_Test();
        // skills3(); //This is the default auton, if you don't select from the brain.
        break;        //Change these to be your own auton functions in order to use the auton selector.
      case 1:         //Tap the screen to cycle through autons.
        // noramAWP2();
        sixball();
        break;
      case 2:
        Safesix();
        break;
      case 3:
        sixball_safe();
        break;
      case 4:
        sixball();
        break;
      case 5:
        skills4();
        break;
  }
  // switch(autonState){
  //   case 0: 
  //     sixball();
  //     break;
  //   case 1: 
  //     AWP();  
  //     break;
  //   case 2: 
  //     RushAWP(); 
  //     break;
  //   case 3: 
  //     sixball_safe(); 
  //     break;
  //   case 4: 
  //     skills3();
  //     break;
  //   case 5:
  //     testing();
  //     break;
  // }
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
  task Ratchettask(pistonratchet2);
  // task Extask(UC_backwings);
  // task horizontaltask(UC_horizontalhang);
  // task verticaltask(UC_verticalhang);
  // task hormac(UC_horhangmac);
  // task vermac(UC_verhangmac);

  task verhormac(horvert);
  // chassis.set_heading(0);
  // // intakeMotor.spin(forward,-100,percent);
  // printf("abc\n");
  
  // wait(3,sec);
  // // chassis.turn_to_angle(90);
  // chassis.drive_distance(24);
  
  // printf("123\n");
  // while(1){
  //   chassis.control_arcade();
  //   wait(20,msec);
  // }
  // task Endgametask(UC_distance);
  // task pistonratchettask(UC_stick);
  // task destroytask(UC_destroy);
  // task killtask(UC_destroy);
    // Brain.Screen.clearScreen();
    // // bool setup_io = false;
    // placement.setLight(ledState::on);
    // placement.brightness(100);
    // while(1){
    //   if(recoil.objectDistance(mm) < 75){
    //     cataMotor.stop(brake);
    //     kicker.stop(brake);
    //     if(placement.isNearObject()){
    //       // wait(0.3,sec);
    //       cataMotor.spin(forward,100,pct);
    //       kicker.spin(forward,100,pct); 
    //       wait(0.13,sec);
    //       cataMotor.stop(coast);
    //       kicker.stop(coast);
    //     }
    //   }    
    //   else{
    //     cataMotor.spin(forward,100,pct);
    //     kicker.spin(forward,100,pct);
    //   }
    //   wait(10,msec);
    // }
  //   chassis.set_heading(0);
  // // intakeMotor.spin(forward,-100,percent);
  //   chassis.drive_distance(24);
  while (1) {
    // Brain.Screen.printAt(200, 120, "Position:%f",hangrot.position(rotationUnits::rev));
    // printf("Position:%f",hangrot.position(rotationUnits::rev));
    chassis.control_arcade();
    if(Controller1.ButtonY.pressing()){
      chassis.set_drive_exit_conditions(0.3, 10, 600);
      // chassis.set_swing_exit_conditions(1.2, 10, 1300);
      chassis.diff(-45, -80, 1700, 300);
      chassis.set_heading(180);
      chassis.drive_distance(11);
      chassis.turn_to_angle(72);
      chassis.drive_distance(-4);
      back_wings2.set(true);

      // chassis.set_drive_exit_conditions(0.3, 10, 600);
      // chassis.set_swing_exit_conditions(1.2, 10, 1300);
      // chassis.set_heading(90);
      // intakeMotor.spin(reverse,30,percent);
      // chassis.diff(-40, -80, 1400, 300);
      // // chassis.set_heading(180);
      // chassis.right_swing_to_angle(70.7);
      // // back_wings.set(true);
      // chassis.drive_distance(-7);
      // intakeMotor.stop(hold);

      // // cataMotor.spin(forward,68,percent);
      // // kicker.spin(forward,68,percent);

      // // // wait(3,sec);
      // // wait(20.7,sec);
      // // cataMotor.stop(brake);
      // // kicker.stop(brake);

      // // chassis.set_drive_exit_conditions(0.3, 10, 600);;
      // // chassis.set_heading(315);
      // // intakeMotor.spin(reverse,60,percent);
      // // chassis.drive_distance(17);
      // // chassis.turn_to_angle(62);
      // // chassis.drive_distance(-2);
      // // back_wings.set(true);
      // // intakeMotor.stop(hold);

      
      // // cataMotor.spin(forward,67,percent);
      // // kicker.spin(forward,67,percent);
      // // // wait(3,sec);
      // // wait(21,sec);
      // // cataMotor.stop(brake);
      // // kicker.stop(brake);
      // // back_wings.set(false);
      
    }
    // if(Controller1.ButtonUp.pressing()){
    //   setup_io = !setup_io;
    // }
    // if(setup_io==true){
    //   cataMotor.spin(forward,67,percent);
    //   kicker.spin(forward,67,percent);
    // }
    // else{
    //   cataMotor.stop(coast);
    //   kicker.stop(coast);
    // }
    // else if(setup_io==false){
    //   cataMotor.stop(coast);
    //   kicker.stop(coast);
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