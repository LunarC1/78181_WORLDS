#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;
controller Controller1 = controller(primary);

motor LF = motor(PORT8, ratio6_1, true);
motor LM = motor(PORT2, ratio6_1, true);
motor LB = motor(PORT3, ratio6_1, false);
motor RF = motor(PORT4, ratio6_1, false);
motor RM = motor(PORT5, ratio6_1, false);
motor RB = motor(PORT6, ratio6_1, true);

inertial Inertial1 = inertial(PORT1);

digital_out front_wings = digital_out(Brain.ThreeWirePort.C);
digital_out hangpiston = digital_out(Brain.ThreeWirePort.A);
digital_out back_wings = digital_out(Brain.ThreeWirePort.B);

digital_out lightsaber = digital_out(Brain.ThreeWirePort.D);

limit limitselect = limit(Brain.ThreeWirePort.E);

motor intakeMotor = motor(PORT7, ratio18_1, true);

motor cataMotor = motor(PORT9, ratio18_1, false);
motor cataMotor1 = motor(PORT10, ratio18_1, false);

distance balance = distance(PORT19);

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