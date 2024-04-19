#include "vex.h"
#include <cmath>

int UC_Intake(){
  while(1){
    if(Controller1.ButtonL1.pressing() && Controller1.ButtonR1.pressing()){
      back_wings.set(true);
      back_wings2.set(true);
      intakeMotor.spin(fwd,0,pct);
    }
    if(Controller1.ButtonR1.pressing()){
      intakeMotor.spin(forward,(-100)*120,voltageUnits::mV);
    }
    else if(Controller1.ButtonL1.pressing()){
      intakeMotor.spin(forward,(100)*120,voltageUnits::mV);
    }
    
    else{
      intakeMotor.stop(hold);
      back_wings.set(false);
      back_wings2.set(false);
    }
    wait(20,msec);
  }
}

int UC_Slapper(){
  // while(1){
  //   if(Controller1.ButtonRight.pressing()){
  //     kicker.spin(fwd,100,pct);
  //   }
  //   else kicker.stop(coast);
  //   wait(20,msec);
  // }
  bool kick_io = false;
  while(1){
    if (Controller1.ButtonRight.pressing()){
      waitUntil(Controller1.ButtonRight.pressing() == false);
      kick_io=!kick_io;
    }
    if(kick_io == true) kicker.spin(forward,75,percent);
    else kicker.stop(coast);
    wait(20,msec);
  }
}

// int UC_pissrat(){
//   bool pissratc = false; 
//   while(1){
//     if(Controller1.ButtonLeft.pressing()){
//       waitUntil(Controller1.ButtonLeft.pressing() == false);
//       pissratc =!pissratc;
//     }
//     pistonratchet.set(pissratc);
//     wait(10,msec);
//   }
// }

int UC_Hang(){
  while(1){
    // if (Controller1.ButtonDown.pressing()){
    //   cataMotor.spin(forward,100,percent);
    // }
    // else if (Controller1.ButtonUp.pressing()){
    //   cataMotor.spin(forward,-100,percent);
    // }
    // else{
    //   cataMotor.stop(hold);
    // }
    wait(20,msec);
  }
}

int UC_frontwings(){
  while(1){
    if(Controller1.ButtonL2.pressing() && Controller1.ButtonR2.pressing()){
      front_wings.set(true);
      front_wings2.set(true);
    }
    if(Controller1.ButtonL2.pressing()){
      front_wings.set(true);
    }
    else if(Controller1.ButtonR2.pressing()){
      front_wings2.set(true);
    }
    else{
      front_wings.set(false);
      front_wings2.set(false);
    }
  }
}

// int UC_backwings(){
//   bool bwing_io = false; 
//   while(1){
//     if(Controller1.ButtonR2.pressing()){
//       waitUntil(Controller1.ButtonR2.pressing() == false);
//       bwing_io =!bwing_io;
//     }
//     back_wings.set(bwing_io);
//     back_wings2.set(bwing_io);
//     wait(20,msec);
//   }  
// }

// int UC_distance(){
//   double distanceground;
//   while(1){
//     distanceground = balance.objectDistance(mm);
//     Controller1.Screen.clearLine(); 
//     Controller1.Screen.print("%d",distanceground); 
//     if(distanceground > 27 && distanceground < 37){
//       Controller1.rumble(rumbleShort); 
//     }
//     wait(50,msec);
//   }
// }

// int UC_stick(){
//   bool stick_io = false; 
//   while(1){
//     if(Controller1.ButtonX.pressing()){
//       waitUntil(Controller1.ButtonX.pressing() == false);
//       stick_io =!stick_io;
//     }
//     pistonratchet.set(stick_io);
//     wait(20,msec);
//   }  
// }

int UC_destroy(){
  while(1){
    Controller1.rumble("..... ..... ..... ..... ..... ");
  }
//   return 0;
}

// bool ver_is_pressed = false;
// bool hor_is_pressed = false;
// int UC_horizontalhang(){
//   // hangrot.resetPosition(); 
//   while(1){
//     double error = std::abs(hangrot.position(rotationUnits::rev) - 1.15);
//     // cataMotor.spin(forward,100,pct);
//     while(error >= 0.2) cataMotor.spin(forward,-100,pct);
//     cataMotor.stop(hold);
//     pistonratchet.set(true);
//     hor_is_pressed = true;
//     Brain.Screen.printAt(200, 120, "Position:%f",hangrot.position(rotationUnits::rev));
//     wait(20,msec);
//   }
// }

// int UC_verticalhang(){
//   while(1){
//     double error = std::abs(hangrot.position(rotationUnits::rev) - 1.15);
//     // hangrot.resetPosition(); 
//     // cataMotor.spin(forward,100,pct);
//     while(error >= 0.2) cataMotor.spin(forward,-100,pct);
//     cataMotor.stop(hold);
//     pistonratchet.set(true);
//     ver_is_pressed = true;
//   }
// }

// int UC_horhangmac(){
//   while(1){
//     double error = std::abs(hangrot.position(rotationUnits::rev) - 0.4);
//     if(Controller1.ButtonUp.pressing()) UC_horizontalhang();
//     else if(Controller1.ButtonUp.pressing() && hor_is_pressed == true){
//       while(error >= 0.4) cataMotor.spin(forward,100,pct);
//       pistonratchet.set(true);
//     }
//   }
// }

// int UC_verhangmac(){
//   while(1){
//     double error = std::abs(hangrot.position(rotationUnits::rev) - 0.4);
//     if(Controller1.ButtonDown.pressing()) UC_verticalhang();
//     else if(Controller1.ButtonDown.pressing() && ver_is_pressed == true){
//       while(error >= 0.4) cataMotor.spin(forward,100,pct);
//       pistonratchet.set(true);
//     }
//   }
// }

// int horvert(){
//   double hangpos;
//   bool ver_is_pressed = false;
//   bool hor_is_pressed = false;
//   while(1){
//     hangpos = std::abs(hangrot.position(rotationUnits::rev));
//     Brain.Screen.printAt(200, 120, "Position:%f",hangpos);
//     if(Controller1.ButtonUp.pressing()){
//       while(hangpos <= 1.15){
//         cataMotor.spin(forward,-100,pct);
//         wait(20,msec);
//       }
//       cataMotor.stop(hold);
//       hor_is_pressed = !hor_is_pressed;
//     }
//     else if(Controller1.ButtonUp.pressing() && hor_is_pressed == true){
//       while(hangpos >= 0.4){
//         cataMotor.spin(forward,100,pct);
//         wait(20,msec);
//       }
//       pistonratchet.set(true);
//     }
//     else cataMotor.stop(hold);

//     if(Controller1.ButtonDown.pressing()){
//       while(hangpos <= 2.6){
//         cataMotor.spin(forward,-100,pct);
//         wait(20,msec);
//       }
//       cataMotor.stop(hold);
//       ver_is_pressed = !ver_is_pressed;
//     }
//     else if(Controller1.ButtonDown.pressing() && ver_is_pressed == true){
//       while(hangpos >= 0.4){
//         cataMotor.spin(forward,100,pct);
//         wait(20,msec);
//       }
//       pistonratchet.set(true);
//     }
//     else cataMotor.stop(hold);
//     wait(20,msec);
//   }
// }