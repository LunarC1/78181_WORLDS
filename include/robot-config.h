using namespace vex;

extern brain Brain;
extern controller Controller1;
extern motor LF;
extern motor LM;
extern motor LB;
extern motor RF;
extern motor RM;
extern motor RB;
extern inertial Inertial100;

extern motor intakeMotor;
extern motor cataMotor;
extern motor kicker;

extern digital_out front_wings;
extern digital_out front_wings2;
extern digital_out pistonratchet;
extern digital_out back_wings;
extern digital_out back_wings2;

extern limit limitselect;

extern distance balance;

extern distance recoil;

extern optical placement;

extern rotation hangrot;
// VEXcode devices

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );