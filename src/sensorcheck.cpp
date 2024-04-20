#include "vex.h"
using namespace vex;

void warning(int level = 0){
  if(level == 0){
    // Brain.Screen.setFillColor(green);
    // Brain.Screen.setPenColor(black);
    wait(20,msec);
  }
  else if(level == 1){
    Brain.Screen.setFillColor(orange);
    Brain.Screen.drawRectangle(10,0,285,480);
    Controller1.rumble(". . ");
  }
  else if(level == 2){
    Brain.Screen.setFillColor(red);
    Brain.Screen.drawRectangle(10,0,285,480);
    Controller1.rumble("- - ");
  
  }
}

void checkBattery(){
  //can change the battery thing 
  if(Brain.Battery.capacity() >= 80 )
    warning(0);
  else if(Brain.Battery.capacity() >= 40)
    warning(1);
  else
    warning(2);
  Brain.Screen.print("Battery : %lu %%\n",Brain.Battery.capacity());
  Brain.Screen.newLine();
  printf("Battery : %lu %%\n",Brain.Battery.capacity());
}

void checkMotors(char const *motorName , motor motorChecking){

  if(motorChecking.installed()){ //if its installed 
    warning(0);
    Brain.Screen.print("Motor: %s checked", motorName);
    printf("Motor: %s\tchecked", motorName);
    wait(10,msec);
    double  motorTemperature = motorChecking.temperature(percent);
    if(motorTemperature > 30)
      warning(1);
    else if(motorTemperature > 40)
      warning(2);
    Brain.Screen.print(" Temperature %.0f %%", motorTemperature);
    printf("\t Temperature %.0f %%", motorTemperature);
    
  }
  else{
    warning(2);
    Brain.Screen.print("Motor: %s Not Found", motorName);
    Controller1.Screen.print("%s Not Found", motorName);
    Controller1.Screen.newLine();
    printf("Motor: %s Not Found !!", motorName);
  }
  Brain.Screen.newLine();
  printf("\n");

}

void checkSensors(char const *sensorName , optical sensorChecking){

  if(sensorChecking.installed()){
    warning(0);
    Brain.Screen.print("Optical: %s checked", sensorName);
    printf("Optical: %s\tchecked", sensorName);
  
  }
  else{
    warning(2);
    Brain.Screen.print("Optical: %s Not Found", sensorName);
    Controller1.Screen.print("%s Not Found", sensorName);
    Controller1.Screen.newLine();
    printf("Optical: %s Not Found !!", sensorName);
  }
  Brain.Screen.newLine();
  printf("\n");

}

void checkSensors(char const *sensorName , distance sensorChecking){

  if(sensorChecking.installed()){
    warning(0);
    Brain.Screen.print("Distance: %s checked", sensorName);
    printf("Distance: %s\tchecked", sensorName);
  
  }
  else{
    warning(2);
    Brain.Screen.print("Distance: %s Not Found", sensorName);
    Controller1.Screen.print("%s Not Found", sensorName);
    Controller1.Screen.newLine();
    printf("Distance: %s Not Found !!", sensorName);
  }
  Brain.Screen.newLine();
  printf("\n");

}

void checkSensors(char const *sensorName , inertial sensorChecking){

  if(sensorChecking.installed()){
    warning(0);
    Brain.Screen.print("Inertial: %s checked", sensorName);
    printf("Inertial: %s\tchecked", sensorName);
  
  }
  else{
    warning(2);
    Brain.Screen.print("Inertial: %s Not Found", sensorName);
    Controller1.Screen.print("%s Not Found", sensorName);
    Controller1.Screen.newLine();
    printf("Inertial: %s Not Found !!", sensorName);
  }
  Brain.Screen.newLine();
  printf("\n");

}

void checkSensors(char const *sensorName , gps sensorChecking){

  if(sensorChecking.installed()){
    warning(0);
    Brain.Screen.print("GPS: %s checked", sensorName);
    printf("GPS: %s\tchecked", sensorName);
  
  }
  else{
    warning(2);
    Brain.Screen.print("GPS: %s Not Found", sensorName);
    Controller1.Screen.print("%s Not Found", sensorName);
    Controller1.Screen.newLine();
    printf("GPS: %s Not Found !!", sensorName);
  }
  Brain.Screen.newLine();
  printf("\n");

}

void checkSensors(char const *sensorName , vision sensorChecking){

  if(sensorChecking.installed()){
    warning(0);
    Brain.Screen.print("vision: %s checked", sensorName);
    printf("vision: %s\tchecked", sensorName);
  
  }
  else{
    warning(2);
    Brain.Screen.print("vision: %s Not Found", sensorName);
    Controller1.Screen.print("%s Not Found", sensorName);
    Controller1.Screen.newLine();
    printf("vision: %s Not Found !!", sensorName);
  }
  Brain.Screen.newLine();
  printf("\n");

}

void checkSensors(char const *sensorName , controller sensorChecking){

  if(sensorChecking.installed()){
    warning(0);
    Brain.Screen.print("%s checked", sensorName);
    printf("%s\tchecked", sensorName);
  
  }
  else{
    warning(2);
    Brain.Screen.print("%s Not Found", sensorName);
    Controller1.Screen.print("%s Not Found", sensorName);
    Controller1.Screen.newLine();
    printf("%s Not Found !!", sensorName);
  }
  Brain.Screen.newLine();
  printf("\n");


}
