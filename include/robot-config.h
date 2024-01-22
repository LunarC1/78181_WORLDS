using namespace vex;

extern brain Brain;
extern controller Controller1;
extern motor LF;
extern motor LM;
extern motor LB;
extern motor RF;
extern motor RM;
extern motor RB;
extern inertial Inertial1;

extern motor intakeMotor;
extern motor cataMotor;
extern motor cataMotor1;

extern digital_out front_wings;
extern digital_out hangpiston;
extern digital_out back_wings;

extern digital_out lightsaber;

extern limit limitselect;

extern distance balance;
// VEXcode devices

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );