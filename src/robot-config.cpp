#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain Brain;
controller Controller1 = controller(primary);

motor LF = motor(PORT4, ratio6_1, true);
motor LM = motor(PORT5, ratio6_1, true);
motor LB = motor(PORT6, ratio6_1, true);
motor RF = motor(PORT15, ratio6_1, false);
motor RM = motor(PORT16, ratio6_1, false);
motor RB = motor(PORT13, ratio6_1, false);

inertial Inertial100 = inertial(PORT14);

digital_out front_wings = digital_out(Brain.ThreeWirePort.B);
digital_out front_wings2 = digital_out(Brain.ThreeWirePort.C);
digital_out pistonratchet = digital_out(Brain.ThreeWirePort.A);
digital_out back_wings = digital_out(Brain.ThreeWirePort.D);
digital_out back_wings2 = digital_out(Brain.ThreeWirePort.E);

limit limitselect = limit(Brain.ThreeWirePort.G);

motor intakeMotor = motor(PORT8, ratio18_1, false);

motor cataMotor = motor(PORT9, ratio18_1, false);
motor kicker = motor(PORT19, ratio18_1, true);

rotation hangrot = rotation(PORT10, false);

// distance balance = distance(PORT19);

// distance recoil = distance(PORT17);

// optical placement = optical(PORT18);
// VEXcode device constructors

// VEXcode generated functions



/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}