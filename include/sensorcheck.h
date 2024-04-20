#include "vex.h"

#define checkMotor(mymotor) checkMotors(#mymotor, (mymotor))
#define checkSensor(mysensor) checkSensors(#mysensor, (mysensor))

using namespace vex;

void warning(int level = 0);

void checkBattery();

void checkMotors(char const *motorName , motor motorChecking);

void checkSensors(char const *sensorName , optical sensorChecking);

void checkSensors(char const *sensorName , distance sensorChecking);

void checkSensors(char const *sensorName , inertial sensorChecking);

void checkSensors(char const *sensorName , gps sensorChecking);

void checkSensors(char const *sensorName , vision sensorChecking);

void checkSensors(char const *sensorName , controller sensorChecking);