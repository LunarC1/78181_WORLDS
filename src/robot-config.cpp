#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

brain Brain;
controller Controller1 = controller(primary);

motor LF = motor(PORT4, ratio6_1, true);
motor LM = motor(PORT5, ratio6_1, true);
motor LB = motor(PORT6, ratio6_1, true);
motor RF = motor(PORT1, ratio6_1, false);
motor RM = motor(PORT2, ratio6_1, false);
motor RB = motor(PORT3, ratio6_1, false);

motor intakeMotor = motor(PORT8, ratio6_1, false);
motor cataMotor = motor(PORT9, ratio36_1, false);
motor kicker = motor(PORT18, ratio36_1, true); 

rotation hangrot = rotation(PORT10, false);

inertial Inertial100 = inertial(PORT7);

digital_out front_wings = digital_out(Brain.ThreeWirePort.B);
digital_out front_wings2 = digital_out(Brain.ThreeWirePort.C);
digital_out pistonratchet = digital_out(Brain.ThreeWirePort.G);
digital_out back_wings = digital_out(Brain.ThreeWirePort.D);
digital_out back_wings2 = digital_out(Brain.ThreeWirePort.E);

limit limitselect = limit(Brain.ThreeWirePort.F);

void vexcodeInit( void ) {}