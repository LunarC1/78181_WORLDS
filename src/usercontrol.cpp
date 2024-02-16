#include "vex.h"

int UC_Intake(){
  while(1){
    if(Controller1.ButtonL1.pressing()){
      intakeMotor.spin(forward,(100)*120,voltageUnits::mV);
    }
    else if(Controller1.ButtonR1.pressing()){
      intakeMotor.spin(reverse,(100)*120,voltageUnits::mV);
    }
    else{
      intakeMotor.stop(hold);
    }
  }
}

int UC_Slapper(){
  bool setup_io = false;
  while(1){
    if (Controller1.ButtonR2.pressing()){
      cataMotor.spin(forward,67,percent);
      cataMotor1.spin(forward,67,percent);
    }
    else{
      cataMotor.stop(coast);
      cataMotor1.stop(coast);
    }
    // if(Controller1.ButtonR2.pressing()){
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
  }
}

int UC_Hang(){
  bool hang_io = false; 
  while(1){
    if(Controller1.ButtonB.pressing()){
      waitUntil(Controller1.ButtonB.pressing() == false);
      hang_io =!hang_io;
    }
    hangpiston.set(hang_io);
    wait(20,msec);
  }  
}

int UC_frontwings(){
  while(1){
    if(Controller1.ButtonL2.pressing()){
      front_wings.set(true);
      // back_wings.set(true);
    }
    else{
      front_wings.set(false);
      // back_wings.set(false);
    }
  }
}

int UC_backwings(){
  bool bwing_io = false; 
  while(1){
    if(Controller1.ButtonA.pressing()){
      waitUntil(Controller1.ButtonA.pressing() == false);
      bwing_io =!bwing_io;
    }
    // front_wings.set(bwing_io);
    back_wings.set(bwing_io);
    wait(20,msec);
  }  
}

int UC_distance(){
  double distanceground;
  while(1){
    distanceground = balance.objectDistance(mm);
    Controller1.Screen.clearLine(); 
    Controller1.Screen.print("%d",distanceground); 
    if(distanceground > 27 && distanceground < 37){
      Controller1.rumble(rumbleShort); 
    }
    wait(50,msec);
  }
}

int UC_stick(){
  bool stick_io = false; 
  while(1){
    if(Controller1.ButtonX.pressing()){
      waitUntil(Controller1.ButtonX.pressing() == false);
      stick_io =!stick_io;
    }
    lightsaber.set(stick_io);
    wait(20,msec);
  }  
}

int UC_destroy(){
  while(1){
    Controller1.rumble("..... ..... ..... ..... ..... ");
  }
//   return 0;
}