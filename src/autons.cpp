#include "vex.h"
#include <cmath>

void default_constants(){
  chassis.set_drive_constants(12, 1, 0, 0.5, 0);
  // chassis.set_turn_constants(12, 0.35, 0, 0.8, 0);//0.33
  chassis.set_turn_constants(12, 0.35, .05, 2, 10);
  chassis.set_swing_constants(12, 0, 0, 0, 0);
  chassis.set_diff_constants(12, .137, 0.001, 0, 0);
  chassis.set_drive_exit_conditions(0.1, 20, 2000);//2000
  chassis.set_turn_exit_conditions(0.1, 20, 3000);//900
  chassis.set_swing_exit_conditions(0, 1000, 1500);
  chassis.set_diff_exit_conditions(1, 10, 900);

  // chassis.set_drive_constants(12, 0.79, 0, 0.83, 0);
  // // chassis.set_turn_constants(12, 0.35, 0, 0.8, 0);//0.33
  // chassis.set_turn_constants(12, 0.2, .01, 0.81, 15);
  // chassis.set_swing_constants(12, 0, 0, 0, 0);
  // chassis.set_diff_constants(12, .137, 0.001, 0, 0);
  // chassis.set_drive_exit_conditions(0.1, 0, 2000);//2000
  // chassis.set_turn_exit_conditions(0.45, 5, 3000);//900
  // chassis.set_swing_exit_conditions(0, 1000, 1500);
  // chassis.set_diff_exit_conditions(1, 10, 900);

  // chassis.set_drive_constants(10, 0.53, 0, 1.23, 0);
  // chassis.set_turn_constants(12, .325, .01, 1.45, 15);
  
  // chassis.set_swing_constants(12, .14, 0.001, 0.013, 0);
  // chassis.set_diff_constants(12, .137, 0.001, 0.01, 0);
  // // chassis.set_swing_constants(12, .1285, 0.001, 0.3, 15);
  // // chassis.set_swing_constants(12, .3, .001, 2, 15);
  // chassis.set_drive_exit_conditions(1, 10, 2000);
  // chassis.set_turn_exit_conditions(0.7, 10, 900);  
  // chassis.set_swing_exit_conditions(1, 10, 1500);
  // chassis.set_diff_exit_conditions(1, 10, 900);
}


void odom_constants(){ 
  default_constants();
  chassis.drive_max_voltage = 10;
  chassis.drive_settle_error = 3;
}

void testing(){
  default_constants();
  chassis.set_heading(0);
  // intakeMotor.spin(forward,-100,percent);
  // chassis.drive_distance(24);
  // chassis.diff(35,70,2000,300);
  // chassis.drive_distance(24);
  // chassis.drive_distance(-24);

  chassis.turn_to_angle(90);
  // chassis.turn_to_angle(180);
  // chassis.turn_to_angle(270);
  chassis.turn_to_angle(0);

  // chassis.right_swing_to_angle(90);
  // chassis.right_swing_to_angle(180);
  // chassis.right_swing_to_angle(270);
  // chassis.right_swing_to_angle(0);
}

void PID_Test(){
  chassis.drive_distance(24);
}

void noramAWP(){
  chassis.drive_max_voltage = 11;
  chassis.set_heading(315);
  intakeMotor.spin(forward,-100,percent);
  // back_wings.set(true);
  back_wings2.set(true);
  // chassis.turn_to_angle(275);
  chassis.turn_to_angle(280);
  wait(200,msec);
  back_wings2.set(false);
  // 
  chassis.turn_to_angle(270);
  chassis.drive_distance(36.5);
  back_wings.set(true);
  wait(600,msec);
  // back_wings.set(false);
  back_wings2.set(false);
}

void noramAWP2(){
  chassis.drive_max_voltage = 11;
  chassis.set_heading(135);
  intakeMotor.spin(forward,-100,percent);
  chassis.drive_distance(10);
  wait(100,msec);
  // back_wings.set(true);
  back_wings.set(true);
  wait(100,msec);
  // chassis.drive_distance(-6);
  // chassis.turn_to_angle(275);
  chassis.turn_to_angle(80);
  wait(100,msec);
  back_wings.set(false);
  chassis.turn_to_angle(319);
  chassis.drive_distance(11.5);
  chassis.turn_to_angle(270);
  chassis.drive_distance(28.5);
}

void ramAWP2(){
  chassis.drive_max_voltage = 11;
  chassis.set_heading(135);
  intakeMotor.spin(forward,-100,percent);
  chassis.drive_distance(10);
  wait(100,msec);
  // back_wings.set(true);
  back_wings.set(true);
  wait(100,msec);
  // chassis.drive_distance(-6);
  // chassis.turn_to_angle(275);
  chassis.turn_to_angle(80);
  wait(100,msec);
  back_wings.set(false);
  chassis.turn_to_angle(310);
  chassis.diff(-38,-70,1700,200);
  chassis.drive_distance(10);
  chassis.turn_to_angle(315);
  chassis.drive_distance(30);
  chassis.turn_to_angle(270);
  chassis.drive_distance(27);
}

void AWP2(){
  chassis.drive_max_voltage = 11;
  chassis.set_heading(315);
  intakeMotor.spin(forward,-100,percent);
  back_wings2.set(true);
  // chassis.turn_to_angle(275);
  chassis.turn_to_angle(278);
  wait(200,msec);
  back_wings2.set(false);
  chassis.turn_to_angle(269);
  chassis.diff(-35,-70,1700,200);
  chassis.drive_distance(10);
  chassis.turn_to_angle(315);
  chassis.drive_distance(30);
  chassis.turn_to_angle(270);
  chassis.drive_distance(29.5);
}

void Safesix(){
  chassis.drive_max_voltage = 11.2;
  chassis.set_drive_exit_conditions(0.5, 3, 1000);
  chassis.set_turn_exit_conditions(1.1, 3, 900);
  intakeMotor.setStopping(hold);
  chassis.set_heading(90);
  // chassis.set_coordinates(-36, 59, 162);
  intakeMotor.spin(forward,100,pct);
  back_wings.set(true);
  wait(130,msec);
  back_wings.set(false);
  chassis.drive_distance(10);
  wait(300,msec);
  chassis.drive_distance(-30);
  back_wings.set(true);
  chassis.diff(-70,-30,1700,620);
  // chassis.set_heading(0);
  chassis.drive_distance(9);
  chassis.turn_to_angle(201);
  intakeMotor.spin(fwd,-100,pct);
  chassis.DriveL.spin(fwd, 9, volt);
  chassis.DriveR.spin(fwd, 9.1, volt);
  wait(450,msec);
  chassis.DriveL.spin(fwd,0,volt);
  chassis.DriveR.spin(fwd,0,volt);
  chassis.turn_to_angle(225);
  chassis.drive_distance(-7);
  // chassis.diff(-15,-60,400,200);
  // chassis.drive_distance(9);
  chassis.turn_to_angle(111);
  wait(200,msec);

  intakeMotor.spin(forward,100,pct);

  chassis.set_drive_exit_conditions(0.8, 3, 1150);
  chassis.set_turn_exit_conditions(1.1, 2, 700);
  chassis.drive_distance(46);
  wait(200,msec);
  chassis.turn_to_angle(235);
  chassis.set_drive_exit_conditions(1, 3, 265);
  intakeMotor.spin(reverse,100,pct);
  chassis.drive_distance(3);
  wait(200,msec);//300
  intakeMotor.spin(forward,100,pct);
  chassis.set_drive_exit_conditions(0.4, 3, 1150);
  chassis.turn_to_angle(157);
  chassis.drive_distance(19);
  wait(100,msec);

  chassis.turn_to_angle(263);

  front_wings.set(true);
  front_wings2.set(true);
  intakeMotor.spin(reverse,100,percent);
  chassis.DriveL.spin(fwd, 12, volt);
  chassis.DriveR.spin(fwd, 12, volt);
  wait(1000,msec);
  chassis.set_heading(270);
  front_wings.set(false);
  front_wings2.set(false);
  chassis.drive_distance(-15);
  chassis.turn_to_angle(90);
}

void sixball(){
  chassis.drive_max_voltage = 11.2;
  chassis.set_drive_exit_conditions(0.5, 3, 1000);
  chassis.set_turn_exit_conditions(1.1, 3, 900);
  intakeMotor.setStopping(hold);
  chassis.set_heading(163);
  // chassis.set_coordinates(-36, 59, 162);
  intakeMotor.spin(forward,100,pct);
  // cataMotor.spin(forward,100,percent);
  // kicker.spin(forward,100,percent);
  // wait(500,msec);
  // cataMotor.stop();
  // kicker.stop();
  front_wings2.set(true);
  back_wings.set(true);
  wait(130,msec);
  front_wings2.set(false);
  back_wings.set(false);
  chassis.drive_distance(57);//57
  // chassis.drive_to_point(-26,9,12,127,0.4,10,850);
  wait(200,msec);
  intakeMotor.stop(hold);
  chassis.drive_distance(-59);//59
  chassis.turn_to_angle(225);
  intakeMotor.spin(reverse,100,pct);
  wait(300,msec);
  intakeMotor.spin(forward,100,pct);
  chassis.turn_to_angle(90);
  chassis.drive_distance(35);
  // chassis.set_heading(89);
  wait(100,msec);
  chassis.set_drive_exit_conditions(0.5, 3, 600);
  // intakeMotor.stop(hold);
  chassis.drive_distance(-27);
  chassis.turn_to_angle(240);
  intakeMotor.spin(reverse,100,pct);
  // chassis.drive_distance(6);
  wait(150,msec);
  chassis.turn_to_angle(73);
  back_wings.set(true);
  chassis.diff(-70,-34,1700,630);
  

  chassis.turn_to_angle(45);
  chassis.drive_distance(7);
  // chassis.diff(-15,-60,400,200);
  // chassis.drive_distance(9);
  chassis.turn_to_angle(111);
  wait(200,msec);

  intakeMotor.spin(forward,100,pct);

  chassis.set_drive_exit_conditions(0.8, 3, 1150);
  chassis.set_turn_exit_conditions(1.1, 2, 700);
  chassis.drive_distance(46);
  wait(200,msec);
  chassis.turn_to_angle(235);
  chassis.set_drive_exit_conditions(1, 3, 265);
  intakeMotor.spin(reverse,100,pct);
  chassis.drive_distance(3);
  wait(200,msec);//300
  intakeMotor.spin(forward,100,pct);
  chassis.set_drive_exit_conditions(0.4, 3, 1150);
  chassis.turn_to_angle(157);
  chassis.drive_distance(19);
  wait(100,msec);

  chassis.turn_to_angle(263);

  front_wings.set(true);
  front_wings2.set(true);
  intakeMotor.spin(reverse,100,percent);
  chassis.DriveL.spin(fwd, 12, volt);
  chassis.DriveR.spin(fwd, 12, volt);
  wait(1000,msec);
  chassis.set_heading(270);
  front_wings.set(false);
  front_wings2.set(false);
  chassis.drive_distance(-15);
  chassis.turn_to_angle(90);
}

void RushAWP2(){
  chassis.drive_max_voltage = 11;
  chassis.set_drive_exit_conditions(0.5, 3, 1000);
  chassis.set_turn_exit_conditions(1.1, 3, 900);
  intakeMotor.setStopping(hold);
  chassis.set_heading(192);
  // chassis.set_coordinates(-36, 59, 162);
  intakeMotor.spin(forward,100,pct);
  // cataMotor.spin(forward,100,percent);
  // kicker.spin(forward,100,percent);
  // wait(500,msec);
  // cataMotor.stop();
  // kicker.stop();
  front_wings.set(true);
  back_wings.set(true);
  wait(130,msec);
  front_wings2.set(false);
  back_wings.set(false);
  chassis.drive_distance(54);
  // chassis.drive_to_point(-26,9,12,127,0.4,10,850);
  wait(200,msec);
  intakeMotor.stop(hold);
  chassis.drive_distance(-59);
  // chassis.diff2(-60,60,700,700);
  chassis.turn_to_angle(295);
  intakeMotor.spin(reverse,100,pct);
  chassis.drive_distance(-7);
  wait(200,msec);
  back_wings2.set(true);
  intakeMotor.spin(forward,100,pct);
  chassis.turn_to_angle(80);
  wait(200,msec);
  back_wings2.set(false);
  chassis.turn_to_angle(285);
  chassis.diff(-36,-70,1700,630);
  // chassis.drive_distance(-7);


}

void AWP(){
  chassis.drive_max_voltage = 11;
  chassis.set_coordinates(45, 61, 315);
  front_wings.set(true);
  intakeMotor.spin(reverse,15,pct);
  chassis.drive_distance(14);
  front_wings.set(false);
  back_wings.set(true);
  // intakeMotor.stop();
  chassis.drive_distance(-7);
  chassis.turn_to_angle(270);
  wait(200,msec);
  back_wings.set(false);
  // chassis.turn_to_angle(135);
  // chassis.drive_distance(-10);
  // chassis.right_swing_to_angle(180);
  // // chassis.drive_distance(-16);
  // chassis.DriveL.spin(fwd, -12, volt);
  // chassis.DriveR.spin(fwd, -12, volt);
  // wait(600,msec);
  // chassis.drive_distance(6);
  // chassis.turn_to_angle(135);
  // chassis.drive_distance(28);
  chassis.turn_to_angle(315);
  chassis.drive_distance(-10);
  chassis.turn_to_angle(270);
  chassis.DriveL.spin(fwd, -3, volt);
  chassis.DriveR.spin(fwd, -3, volt);
}
void AWP_Elims(){
  chassis.set_drive_exit_conditions(0.5, 3, 1000);
  chassis.set_turn_exit_conditions(1.1, 3, 900);
  intakeMotor.setStopping(hold);
  chassis.set_coordinates(36, 59, 192);
  intakeMotor.spin(forward,100,pct);
  front_wings.set(true);
  wait(250,msec);
  front_wings.set(false);
  chassis.drive_to_point(26,3,11,127,0.4,10,850);
  wait(250,msec);
  intakeMotor.stop(hold);
  chassis.drive_distance(-69);
  chassis.right_swing_to_angle(287);
  // chassis.turn_to_angle(287);
  intakeMotor.spin(reverse,100,pct);
  wait(270,msec);
  // intakeMotor.spin(forward,100,pct);
  chassis.drive_distance(-12.5);
  back_wings.set(true);
  chassis.drive_distance(8);
  chassis.turn_to_angle(250);
  back_wings.set(false);
  chassis.turn_to_angle(315);
  chassis.drive_distance(9);
  chassis.right_swing_to_angle(270);
  chassis.drive_distance(33);
  chassis.drive_distance(-28);
  chassis.turn_to_angle(295);

  chassis.left_swing_to_angle(270);
  chassis.right_swing_to_angle(350);

  chassis.left_swing_to_angle(253);
  chassis.drive_distance(-7);
  }


void Worlds_Skills(){
      // back_wings.set(true);
      // back_wings2.set(true);
      // chassis.diff(-80,-74,1500,10000);
      // wait(10000,sec);
      chassis.set_drive_exit_conditions(0.3, 10, 600);
      // chassis.set_swing_exit_conditions(1.2, 10, 1300);
      chassis.diff(-45, -80, 1700, 300);
      chassis.set_heading(180);
      chassis.drive_distance(10);
      chassis.turn_to_angle(73.5);
      chassis.drive_distance(-4);
      back_wings2.set(true);
      kicker.spin(forward,70,pct);
      wait(3,sec);
      kicker.stop(coast);
      back_wings2.set(false);
      chassis.set_drive_exit_conditions(0.3, 10, 2500);
      intakeMotor.spin(forward,-100,pct);
      chassis.drive_distance(49);
      chassis.turn_to_angle(0);
      front_wings2.set(true);
      chassis.ram(1300,8.1,8.1);
      // chassis.ram(150,-8,-8);
      // chassis.drive_distance(-3);
      // chassis.drive_distance(65);
      front_wings2.set(false);
      chassis.turn_to_angle(90);
      chassis.drive_distance(-46.5);
      // chassis.set_heading(90);
      chassis.turn_to_angle(45);
      chassis.drive_distance(32);
      chassis.turn_to_angle(89);
      // front_wings.set(true);
      // front_wings2.set(true);
      chassis.drive_distance(69);
      // front_wings.set(false);
      // front_wings2.set(false);
      chassis.diff(85,42.5,1450,200);
      chassis.reramF();
      chassis.drive_distance(-10);
      chassis.turn_to_angle(255);

      intakeMotor.spin(forward,100,pct);

      chassis.set_drive_exit_conditions(0.8, 3, 1150);
      chassis.set_turn_exit_conditions(0.7, 2, 700);
      chassis.drive_distance(44);
      chassis.turn_to_angle(315);
      back_wings.set(true);
      back_wings2.set(true);
      chassis.diff(-80,-63,1200,1200);
      // chassis.turn_to_angle(0);
      // chassis.drive_distance(-23);
      chassis.turn_to_angle(270);
      chassis.drive_distance(7);
      back_wings.set(false);
      back_wings2.set(false);
      // back_wings2.set(true);
      // chassis.ram(1450,-9,-9);
      chassis.drive_distance(20);
      chassis.turn_to_angle(0);
      back_wings.set(true);
      chassis.drive_distance(-44);
      chassis.turn_to_angle(225);
      back_wings2.set(true);
      chassis.diff(-64,-80,1200,1200);
      chassis.turn_to_angle(270);
      chassis.drive_distance(5);
      back_wings.set(false);
      back_wings2.set(false);
      chassis.turn_to_angle(1);
      chassis.drive_distance(-48);
      chassis.turn_to_angle(215);
      chassis.ram(1450,-9.5,-9.5);
      chassis.reramB();
      chassis.drive_distance(7);
      
      chassis.diff(90,47,1200,1200);



      
}
void skills3(){
  chassis.set_drive_exit_conditions(0.3, 10, 600);
  
  // chassis.set_heading(315);
  // intakeMotor.spin(reverse,30,percent);
  // chassis.drive_distance(17);
  // chassis.turn_to_angle(63);
  // chassis.drive_distance(-2);
  // // back_wings.set(true);
  // intakeMotor.stop(hold);
  // cataMotor.spin(forward,68,percent);
  // kicker.spin(forward,68,percent);
  // wait(3,sec);
  // // wait(21.3,sec);
  // cataMotor.stop(brake);
  // kicker.stop(brake);

  // // back_wings.set(false);
  // chassis.turn_to_angle(165);
  // chassis.DriveL.spin(fwd, -12, volt);
  // chassis.DriveR.spin(fwd, -12, volt);
  // wait(600,msec);
  // chassis.set_heading(180);
  // wait(100,msec);
  // chassis.drive_distance(7);
  chassis.set_heading(90);
  intakeMotor.spin(reverse,30,percent);
  chassis.diff(-51, -100, 1400, 300);
  // chassis.set_heading(180);
  chassis.right_swing_to_angle(70.6);
  // back_wings.set(true);
  chassis.drive_distance(-7);
  intakeMotor.stop(hold);
  cataMotor.spin(forward,68,percent);
  kicker.spin(forward,68,percent);
  // wait(3,sec);
  wait(20.2,sec);
  cataMotor.stop(brake);
  kicker.stop(brake);


  
  chassis.turn_to_angle(136.7);
  chassis.set_drive_exit_conditions(1, 10, 1800);
  intakeMotor.spin(reverse,100,pct);
  // chassis.drive_distance(30);
  chassis.drive_distance(31);
  
  chassis.turn_to_angle(91);
  
  chassis.drive_distance(76);

  chassis.set_drive_exit_conditions(0.3, 10, 600);
  chassis.turn_to_angle(270);
  back_wings.set(true);
  chassis.diff(-90, -45.9, 1500, 500);
  // wait(1400,msec);
  chassis.turn_to_angle(180);
  chassis.drive_distance(13);
  chassis.DriveL.spin(fwd, -9, volt);
  chassis.DriveR.spin(fwd, -9, volt);
  wait(800,msec);
  chassis.set_heading(180);
  chassis.drive_distance(10);
  chassis.turn_to_angle(270);
  // chassis.turn_to_angle(270+13.5);

  intakeMotor.spin(forward,100,pct);
  chassis.set_drive_exit_conditions(0.8, 3, 1150);
  chassis.set_turn_exit_conditions(1.1, 2, 700);
  chassis.drive_distance(26);

  chassis.turn_to_angle(0);
  front_wings.set(true);
  chassis.drive_distance(16);
  front_wings.set(false);
  chassis.set_turn_exit_conditions(1.1, 2, 1400);

  // chassis.turn_to_angle(90);
  // chassis.drive_distance(-14);
  // back_wings.set(true);
  // chassis.DriveL.spin(fwd, -7.5, volt);
  // chassis.DriveR.spin(fwd, -7.5, volt);
  // wait(900,msec);
  // chassis.turn_to_angle(225);
  // chassis.drive_distance(39);

  chassis.turn_to_angle(270);
  chassis.drive_distance(17.5);
  chassis.drive_distance(-3.5);

  chassis.left_swing_to_angle(79);
  intakeMotor.spin(reverse,100,pct);
  front_wings.set(true);
  chassis.DriveL.spin(fwd, 7.5, volt);
  chassis.DriveR.spin(fwd, 7.5, volt);
  wait(1050,msec);
  front_wings.set(false);
  chassis.turn_to_angle(45);
  chassis.set_drive_exit_conditions(1, 3, 1150);
  chassis.drive_distance(-39);

  chassis.turn_to_angle(0);
  
  intakeMotor.spin(fwd,100,pct);


  // chassis.drive_distance(28);
  // chassis.turn_to_angle(90);

  // intakeMotor.spin(reverse,100,pct);
  // front_wings.set(true);
  // chassis.DriveL.spin(fwd, 7.3, volt);
  // chassis.DriveR.spin(fwd, 7.3, volt);
  // wait(1050,msec);
  // front_wings.set(false);
  // chassis.drive_distance(-33);
  // chassis.turn_to_angle(0);

  // chassis.drive_distance(29);
  chassis.drive_distance(60);


  // chassis.drive_distance(60);
  chassis.turn_to_angle(140);
  intakeMotor.spin(fwd,-100,pct);
  front_wings.set(true);
  chassis.set_drive_exit_conditions(2, 3, 1150);
  chassis.drive_distance(19);
  chassis.set_drive_exit_conditions(1, 3, 1150);
  chassis.set_swing_exit_conditions(2.2, 10, 1200);

  chassis.right_swing_to_angle(90);

  chassis.DriveL.spin(fwd, 7, volt);
  chassis.DriveR.spin(fwd, 7, volt);

  wait(1300,msec);
  front_wings.set(false);
  chassis.turn_to_angle(90);
  chassis.drive_distance(-24);
  front_wings.set(true);
  chassis.DriveL.spin(fwd, 7.9, volt);
  chassis.DriveR.spin(fwd, 7.9, volt);
  wait(1100,msec);
  front_wings.set(false);
  
  chassis.turn_to_angle(90);
  chassis.drive_distance(-28);
  chassis.turn_to_angle(205);
  chassis.drive_distance(-37);
  back_wings.set(true);
  chassis.diff(-22,-90 ,1850, 300);
  chassis.turn_to_angle(0);
  // chassis.drive_distance(12);
  // chassis.DriveL.spin(fwd, -11, volt);
  // chassis.DriveR.spin(fwd, -11, volt);
  // wait(700,msec);
  // chassis.set_heading(0);
  chassis.diff(51,100,920,0);
  pistonratchet.set(true);
  chassis.turn_to_angle(270);
  chassis.endgame(1230);
  // front_wings.set(true);
  // chassis.diff(100,15,900,300);
  // chassis.DriveL.spin(fwd, 70, volt);
  // chassis.DriveR.spin(fwd, 70, volt);
  // wait(350,msec);
  // front_wings.set(false);
  // chassis.turn_to_angle(90);
  // chassis.drive_distance(-24);
  // front_wings.set(true);
  // chassis.DriveL.spin(fwd, 70, volt);
  // chassis.DriveR.spin(fwd, 70, volt);
  // wait(700,msec);
  // front_wings.set(false);
  // chassis.drive_distance(-28.5);
  // chassis.turn_to_angle(0);
  // chassis.drive_distance(7);
  // chassis.left_swing_to_angle(90);
  // front_wings.set(true);
  // chassis.DriveL.spin(fwd, 70, volt);
  // chassis.DriveR.spin(fwd, 70, volt);
  // wait(800,msec);
  // front_wings.set(false);
  // chassis.turn_to_angle(90);
  // chassis.drive_distance(-24);
  // front_wings.set(true);
  // chassis.DriveL.spin(fwd, 70, volt);
  // chassis.DriveR.spin(fwd, 70, volt);
  // wait(700,msec);
  // front_wings.set(false);

  // chassis.drive_distance(-28);
  // chassis.turn_to_angle(205);
  // chassis.drive_distance(-39);
  // chassis.diff(-25,-100 ,2000, 300);
  // chassis.turn_to_angle(0);
  // chassis.drive_distance(9);
  // chassis.DriveL.spin(fwd, -70, volt);
  // chassis.DriveR.spin(fwd, -70, volt);
  // wait(600,msec);
  // chassis.set_heading(0);

  // chassis.drive_distance(10);
  // chassis.turn_to_angle(270-13.5);

  // intakeMotor.spin(reverse,100,pct);
  // chassis.set_drive_exit_conditions(0.8, 3, 1150);
  // chassis.set_turn_exit_conditions(1.1, 2, 700);
  // chassis.drive_distance(18);
  // front_wings.set(true);
  // chassis.diff(15,100,900,300);
  // chassis.turn_to_angle(90);
  // chassis.DriveL.spin(fwd, 70, volt);
  // chassis.DriveR.spin(fwd, 70, volt);
  // wait(500,msec);
  // front_wings.set(false);


  // // chassis.turn_to_angle(90);
  // // chassis.drive_distance(-24);
  // // front_wings.set(true);
  // // chassis.DriveL.spin(fwd, 70, volt);
  // // chassis.DriveR.spin(fwd, 70, volt);
  // // wait(700,msec);
  // // front_wings.set(false);
  // // chassis.drive_distance(-14.5);


  // // chassis.turn_to_angle(180);
  // // chassis.drive_distance(-48);
  // // chassis.turn_to_angle(270);
  // // pistonratchet.set(true);
  // // chassis.drive_distance(31);
  // // pistonratchet.set(false);
}

void skills4(){
  chassis.set_drive_exit_conditions(0.3, 10, 600);
  chassis.set_heading(90);
  intakeMotor.spin(reverse,30,percent);
  chassis.diff(-51, -100, 1400, 300);
  // chassis.set_heading(180);
  chassis.right_swing_to_angle(74.3);
  // back_wings.set(true);
  chassis.drive_distance(-7);
  intakeMotor.stop(hold);
  cataMotor.spin(forward,68,percent);
  kicker.spin(forward,68,percent);
  wait(3,sec);
  // wait(21.3,sec);
  cataMotor.stop(brake);
  kicker.stop(brake);

  chassis.set_drive_exit_conditions(1, 10, 1800);
  intakeMotor.spin(reverse,100,pct);
  chassis.drive_distance(49);
  // chassis.turn_to_angle(180);
  // chassis.drive_distance(-31);

  // chassis.turn_to_angle(254);
  // chassis.diff(-75,-57,670,0);
  chassis.set_turn_exit_conditions(0.7, 2, 1400);
  chassis.turn_to_angle(180);
  back_wings.set(true);
  chassis.set_drive_exit_conditions(1, 10, 1350);
  chassis.drive_distance(-68);
  back_wings.set(false);
  chassis.turn_to_angle(270);
  chassis.diff(89.3,25.814285714286,950,0);
  chassis.turn_to_angle(90);
  

  chassis.drive_distance(76);

  chassis.set_drive_exit_conditions(0.3, 10, 600);
  chassis.turn_to_angle(270);
  back_wings.set(true);
  chassis.diff(-45.9, -90, 1500, 330);
  // wait(1400,msec);
  chassis.turn_to_angle(0);
  chassis.drive_distance(13);
  chassis.DriveL.spin(fwd, -9, volt);
  chassis.DriveR.spin(fwd, -9, volt);
  wait(700,msec);
  chassis.set_heading(0);
  chassis.drive_distance(10);
  chassis.turn_to_angle(270);
  // chassis.turn_to_angle(270+13.5);

  intakeMotor.spin(forward,100,pct);
  chassis.set_drive_exit_conditions(1, 3, 1000);
  chassis.set_turn_exit_conditions(1.1, 2, 700);
  chassis.drive_distance(26);


  chassis.turn_to_angle(180);
  front_wings.set(true);
  chassis.drive_distance(16);
  front_wings.set(false);
  chassis.set_turn_exit_conditions(1.1, 2, 1400);

  chassis.turn_to_angle(270);
  chassis.drive_distance(14);
  chassis.right_swing_to_angle(101);//79
  intakeMotor.spin(reverse,100,pct);
  front_wings.set(true);
  chassis.DriveL.spin(fwd, 7.3, volt);
  chassis.DriveR.spin(fwd, 7.3, volt);
  wait(1050,msec);
  front_wings.set(false);
  chassis.turn_to_angle(135);
  chassis.drive_distance(-39);

  chassis.turn_to_angle(180);
  chassis.drive_distance(30);
  chassis.turn_to_angle(90);

  intakeMotor.spin(reverse,100,pct);
  front_wings.set(true);
  chassis.DriveL.spin(fwd, 7.3, volt);
  chassis.DriveR.spin(fwd, 7.3, volt);
  wait(1050,msec);
  front_wings.set(false);
  chassis.drive_distance(-27);
  chassis.turn_to_angle(180);

  chassis.drive_distance(21);
  chassis.turn_to_angle(40);//140 90 50 40
  front_wings.set(true);
  chassis.set_drive_exit_conditions(1.7, 3, 900);
  chassis.drive_distance(19);
  chassis.set_drive_exit_conditions(1, 3, 1000);


  chassis.set_swing_exit_conditions(2, 10, 1300);

  chassis.right_swing_to_angle(90);

  chassis.DriveL.spin(fwd, 7.5, volt);
  chassis.DriveR.spin(fwd, 7.5, volt);

  wait(1050,msec);//1200
  front_wings.set(false);
  chassis.turn_to_angle(90);
  chassis.drive_distance(-24);
  front_wings.set(true);
  chassis.DriveL.spin(fwd, 11, volt);
  chassis.DriveR.spin(fwd, 11, volt);
  wait(800,msec);
  front_wings.set(false);
  
  chassis.turn_to_angle(90);
  chassis.drive_distance(-28);
  chassis.turn_to_angle(335);//205 270 65 335
  chassis.drive_distance(-31);
  chassis.diff(-100,-22.5 ,1900, 300);
  chassis.turn_to_angle(180);
  chassis.drive_distance(12);
  chassis.DriveL.spin(fwd, -11, volt);
  chassis.DriveR.spin(fwd, -11, volt);
  wait(700,msec);
  chassis.set_heading(180);
  pistonratchet.set(true);
  chassis.diff(100,51,920,0);
  chassis.turn_to_angle(270);
  chassis.endgame(1230);
}


void testing1(){
  chassis.set_heading(90);
  // chassis.turn_to_angle_chain(0);
  chassis.drive_distance(24);
  chassis.turn_to_angle(90);
  chassis.turn_to_angle(0);
}

















void AWP_ram(){
  // chassis.right_swing_to_angle(90);
  // chassis.drive_distance(24);
  // // chassis.turn_to_angle(180);
  // // chassis.turn_to_angle(0);
  // chassis.drive_distance(-24);
  // // chassis.drive_distance(6);
  // // chassis.drive_distance(12);
  // // chassis.drive_distance(18);
  // chassis.drive_distance(-36);


  chassis.drive_max_voltage = 11;
  chassis.set_coordinates(45, 61, 315);
  intakeMotor.spin(reverse,15,pct);
  chassis.drive_distance(14);
  back_wings.set(true);
  intakeMotor.stop();
  chassis.drive_distance(-7);
  chassis.turn_to_angle(270);
  wait(200,msec);
  back_wings.set(false);
  chassis.turn_to_angle(135);
  chassis.drive_distance(-10);
  chassis.right_swing_to_angle(180);
  // chassis.drive_distance(-16);
  chassis.DriveL.spin(fwd, -12, volt);
  chassis.DriveR.spin(fwd, -12, volt);
  wait(600,msec);
  chassis.drive_distance(6);
  chassis.turn_to_angle(135);
  chassis.drive_distance(28);
  chassis.turn_to_angle(270);
  chassis.DriveL.spin(fwd, -3, volt);
  chassis.DriveR.spin(fwd, -3, volt);

  // chassis.right_swing_to_angle(90);
  // chassis.drive_distance(24);
  // pistonratchet.set(true);


  // chassis.DriveL.stop();
  // chassis.DriveR.stop();


  // chassis.drive_to_point(60,29);
  // chassis.turn_to_angle(174);
  // chassis.drive_distance(14);
}
  


void RushAWP(){
  
  //-36,59
  // chassis.left_swing_to_angle(90);
  // chassis.right_swing_to_angle(0);
}

void sixball_safe(){
  chassis.set_heading(90);
  chassis.set_drive_exit_conditions(1, 10, 600);
  chassis.set_coordinates(-10, 59, 90);
  intakeMotor.spin(forward,100,pct);
  chassis.drive_distance(5);
  intakeMotor.stop(hold);
  // wait(100,msec);
  chassis.set_drive_exit_conditions(1, 10, 1000);
  chassis.drive_distance(-33);
  chassis.left_swing_to_angle(45);
  back_wings.set(true);
  chassis.drive_distance(-8);
  chassis.left_swing_to_angle(0);
  // wait(200,msec);
  back_wings.set(false);
  chassis.turn_to_angle(17);
  chassis.DriveL.spin(fwd, -12, volt);
  chassis.DriveR.spin(fwd, -12, volt);
  wait(600,msec);
  chassis.set_heading(0);
  wait(100,msec);
  chassis.drive_distance(8);
  chassis.turn_to_angle(180);
  intakeMotor.spin(reverse,100,pct);
  wait(70,msec);
  chassis.DriveL.spin(fwd, 12, volt);
  chassis.DriveR.spin(fwd, 12, volt);
  wait(500,msec);
  chassis.set_heading(180);
  wait(100,msec);
  chassis.drive_distance(-9);
  chassis.turn_to_angle(96);//90
  intakeMotor.spin(forward,100,pct);
  // chassis.drive_distance(23);
  // chassis.turn_to_angle(107);
  // chassis.turn_to_angle(std::abs(Inertial100.heading()+3));

  // chassis.right_swing_to_angle(105);

  // chassis.drive_distance(23.5);
  chassis.drive_distance(47);
  chassis.turn_to_angle(235);
  intakeMotor.spin(reverse,100,pct);
  wait(300,msec);
  intakeMotor.spin(forward,100,pct);
  chassis.turn_to_angle(160.3);
  chassis.drive_distance(22);
  wait(100,msec);
  chassis.left_swing_to_angle(270);
  // chassis.turn_to_angle(270);
  front_wings.set(true);
  intakeMotor.spin(reverse,100,percent);
  chassis.DriveL.spin(fwd, 12, volt);
  chassis.DriveR.spin(fwd, 12, volt);
  wait(1000,msec);
  chassis.set_heading(270);
  front_wings.set(false);
  chassis.drive_distance(-5);
  chassis.turn_to_angle(51);
  chassis.drive_distance(29);
  pistonratchet.set(true);
}

void skills1(){
  chassis.set_drive_exit_conditions(0.3, 10, 600);
  
  chassis.set_heading(315);
  intakeMotor.spin(reverse,30,percent);
  chassis.drive_distance(17);
  chassis.turn_to_angle(63);
  chassis.drive_distance(-2);
  back_wings.set(true);
  intakeMotor.stop(hold);
  cataMotor.spin(forward,67,percent);
  kicker.spin(forward,67,percent);
  // wait(3,sec);
  wait(21.8,sec);
  cataMotor.stop(brake);
  kicker.stop(brake);

  back_wings.set(false);
  chassis.turn_to_angle(165);
  chassis.DriveL.spin(fwd, -12, volt);
  chassis.DriveR.spin(fwd, -12, volt);
  wait(600,msec);
  chassis.set_heading(180);
  wait(100,msec);
  chassis.drive_distance(7);
  chassis.turn_to_angle(135);
  chassis.set_drive_exit_conditions(0.3, 10, 1900);
  chassis.drive_distance(30);
  chassis.turn_to_angle(90);
  
  chassis.drive_distance(76);

  chassis.set_drive_exit_conditions(0.3, 10, 600);
  // chassis.left_swing_to_angle(235);
  // back_wings.set(true);
  // chassis.set_drive_exit_conditions(0.3, 10, 600);
  // chassis.drive_distance(-8);
  // chassis.turn_to_angle(180);
  // back_wings.set(false);
  chassis.turn_to_angle(270);
  chassis.diff(-100, -51, 1600, 300);
  // wait(1400,msec);
  chassis.turn_to_angle(180);
  chassis.drive_distance(12);
  chassis.DriveL.spin(fwd, -9, volt);
  chassis.DriveR.spin(fwd, -9, volt);
  wait(800,msec);
  chassis.set_heading(180);
  chassis.drive_distance(10);
  chassis.turn_to_angle(270+13.5);
  // chassis.turn_to_angle(103.5);//90

  intakeMotor.spin(reverse,100,pct);
  // chassis.drive_distance(23);
  // chassis.turn_to_angle(107);
  // chassis.turn_to_angle(std::abs(Inertial100.heading()+3));

  // chassis.right_swing_to_angle(105);

  // chassis.drive_distance(23.5);
  chassis.set_drive_exit_conditions(0.8, 3, 1150);
  chassis.set_turn_exit_conditions(1.1, 2, 700);
  chassis.drive_distance(18);
  front_wings.set(true);
  chassis.diff(100,15,900,300);
  chassis.DriveL.spin(fwd, 70, volt);
  chassis.DriveR.spin(fwd, 70, volt);
  wait(350,msec);
  front_wings.set(false);
  chassis.turn_to_angle(90);
  chassis.drive_distance(-24);
  front_wings.set(true);
  chassis.DriveL.spin(fwd, 70, volt);
  chassis.DriveR.spin(fwd, 70, volt);
  wait(700,msec);
  front_wings.set(false);
  chassis.drive_distance(-28.5);
  chassis.turn_to_angle(35);
  chassis.drive_distance(4);
  front_wings.set(true);
  chassis.diff(100, 25, 750, 300);
  chassis.DriveL.spin(fwd, 70, volt);
  chassis.DriveR.spin(fwd, 70, volt);
  wait(350,msec);
  front_wings.set(false);
  chassis.turn_to_angle(90);
  chassis.drive_distance(-24);
  front_wings.set(true);
  chassis.DriveL.spin(fwd, 70, volt);
  chassis.DriveR.spin(fwd, 70, volt);
  wait(700,msec);
  front_wings.set(false);
  // wait(1000,msec);
  // front_wings.set(false);


  chassis.drive_distance(-28);
  chassis.turn_to_angle(205);
  chassis.drive_distance(-39);
  chassis.diff(-25,-100 ,2000, 300);
  chassis.turn_to_angle(0);
  chassis.drive_distance(9);
  chassis.DriveL.spin(fwd, -70, volt);
  chassis.DriveR.spin(fwd, -70, volt);
  wait(600,msec);
  chassis.set_heading(0);

  chassis.drive_distance(10);
  chassis.turn_to_angle(270-13.5);
  // chassis.turn_to_angle(103.5);//90

  intakeMotor.spin(reverse,100,pct);
  // chassis.drive_distance(23);
  // chassis.turn_to_angle(107);
  // chassis.turn_to_angle(std::abs(Inertial100.heading()+3));

  // chassis.right_swing_to_angle(105);

  // chassis.drive_distance(23.5);
  chassis.set_drive_exit_conditions(0.8, 3, 1150);
  chassis.set_turn_exit_conditions(1.1, 2, 700);
  chassis.drive_distance(18);
  front_wings.set(true);
  chassis.diff(15,100,900,300);
  chassis.turn_to_angle(90);
  chassis.DriveL.spin(fwd, 70, volt);
  chassis.DriveR.spin(fwd, 70, volt);
  wait(350,msec);
  front_wings.set(false);
  chassis.turn_to_angle(90);
  chassis.drive_distance(-24);
  front_wings.set(true);
  chassis.DriveL.spin(fwd, 70, volt);
  chassis.DriveR.spin(fwd, 70, volt);
  wait(700,msec);
  front_wings.set(false);
  chassis.drive_distance(-28.5);
  chassis.turn_to_angle(215);
  chassis.drive_distance(-55);
  chassis.turn_to_angle(270);
  pistonratchet.set(true);
  chassis.drive_distance(31);
  pistonratchet.set(false);
  // chassis.left_swing_to_angle(315);
  // chassis.drive_distance(23);
  // chassis.turn_to_angle(270);
  // chassis.set_drive_exit_conditions(0.8, 3, 1400);
  // chassis.drive_distance(92);
  // chassis.turn_to_angle(180);
  // chassis.set_drive_exit_conditions(0.8, 3, 750);
  // chassis.drive_distance(47);
  // chassis.turn_to_angle(90);
  // front_wings.set(true);
  // chassis.drive_distance(25);
  // front_wings.set(false);
  // chassis.drive_distance(-17);

  // chassis.turn_to_angle(180);
  // chassis.drive_distance(47);
  // chassis.turn_to_angle(90);
  // front_wings.set(true);
  // chassis.drive_distance(25);
  // front_wings.set(false);
  // chassis.drive_distance(-17);
  // chassis.turn_to_angle(180);
  // chassis.drive_distance(29);
  // chassis.turn_to_angle(90);
  // pistonratchet.set(true);
  // chassis.drive_distance(31);
  // pistonratchet.set(false);


  // chassis.set_drive_exit_conditions(1, 3, 265);
  // chassis.turn_to_angle(0);
  // chassis.drive_distance(3);
  // intakeMotor.spin(reverse,100,pct);
  // wait(300,msec);
  // intakeMotor.spin(forward,100,pct);
  // chassis.set_drive_exit_conditions(0.4, 3, 1150);
  // chassis.turn_to_angle(157);
  // chassis.drive_distance(25);
  // wait(100,msec);
  // // chassis.left_swing_to_angle(270);
  // chassis.turn_to_angle(270);
  // // chassis.turn_to_angle(270);
  // front_wings.set(true);
  // intakeMotor.spin(reverse,100,percent);
  // chassis.DriveL.spin(fwd, 12, volt);
  // chassis.DriveR.spin(fwd, 12, volt);
  // wait(1000,msec);
  // chassis.set_heading(270);
  // front_wings.set(false);
  // chassis.set_drive_exit_conditions(0.5, 3, 500);
  // chassis.set_turn_exit_conditions(1.1, 3, 900);
  // chassis.drive_distance(-5);
  // chassis.turn_to_angle(231);
  // back_wings.set(true);
  // chassis.set_drive_exit_conditions(1, 3, 700);
  // chassis.drive_distance(-53);
  // chassis.right_swing_to_angle(270);











  // chassis.left_swing_to_angle(225);
  // chassis.drive_distance(7);
  // chassis.left_swing_to_angle(180);
  // chassis.DriveL.spin(fwd, -6.5, volt);
  // chassis.DriveR.spin(fwd, -6.5, volt);
  // wait(1300,msec);
  // chassis.set_heading(180);
  // chassis.drive_distance(7);
  // chassis.DriveL.spin(fwd, -6.5, volt);
  // chassis.DriveR.spin(fwd, -6.5, volt);
  // wait(1200,msec);
  // chassis.set_heading(180);
  // chassis.drive_distance(9);
  // chassis.turn_to_angle(270);
  // chassis.drive_distance(37);
  // chassis.turn_to_angle(5);
  // chassis.diff(65,100,4000, 300);

  // chassis.diff(85,100);
}

void skills2(){
  chassis.set_drive_exit_conditions(0.3, 10, 600);
  
  chassis.set_heading(315);
  intakeMotor.spin(reverse,30,percent);
  chassis.drive_distance(17);
  chassis.turn_to_angle(63);
  chassis.drive_distance(-2);
  back_wings.set(true);
  intakeMotor.stop(hold);
  cataMotor.spin(forward,67,percent);
  kicker.spin(forward,67,percent);
  // wait(6,sec);
  wait(20.5,sec);
  cataMotor.stop(brake);
  kicker.stop(brake);

  back_wings.set(false);

  chassis.turn_to_angle(165);
  chassis.DriveL.spin(fwd, -12, volt);
  chassis.DriveR.spin(fwd, -12, volt);
  wait(600,msec);
  chassis.set_heading(180);
  wait(100,msec);
  chassis.drive_distance(9);
  chassis.turn_to_angle(90);
  chassis.drive_distance(32);
  chassis.turn_to_angle(0);
  chassis.drive_distance(49);
  chassis.turn_to_angle(90);


  intakeMotor.spin(fwd,-100,pct);
  front_wings.set(true);
  chassis.DriveL.spin(fwd, 70, volt);
  chassis.DriveR.spin(fwd, 70, volt);
  // chassis.cross(5000);
  wait(2300,msec);
  front_wings.set(false);
  chassis.turn_to_angle(90);
  chassis.drive_distance(-27);
  chassis.turn_to_angle(135);
  front_wings.set(true);
  chassis.diff(29,100,700, 300);
  wait(1000,msec);
  front_wings.set(false);
  chassis.turn_to_angle(90);
  chassis.drive_distance(-24);
  front_wings.set(true);
  chassis.DriveL.spin(fwd, 70, volt);
  chassis.DriveR.spin(fwd, 70, volt);
  wait(700,msec);
  front_wings.set(false);
  chassis.drive_distance(-26);
  chassis.turn_to_angle(330);
  chassis.drive_distance(-38.5);
  chassis.diff(-100,-25,2000, 300);
  chassis.drive_distance(9);
  chassis.DriveL.spin(fwd, -70, volt);
  chassis.DriveR.spin(fwd, -70, volt);
  wait(600,msec);
  chassis.drive_distance(5.5);

  chassis.turn_to_angle(270);
  intakeMotor.spin(reverse,100,percent);
  chassis.set_drive_exit_conditions(0.3, 10, 3200);
  chassis.set_turn_exit_conditions(1.5,10,1000);
  chassis.drive_distance(111,270,7,8);
  chassis.turn_to_angle(180);
  chassis.set_drive_exit_conditions(0.3, 10, 700);
  chassis.turn_to_angle(270);
  chassis.set_drive_exit_conditions(0.3, 10, 3200);
  chassis.drive_distance(-76);
  chassis.set_drive_exit_conditions(0.3, 10, 600);
  // chassis.left_swing_to_angle(235);
  // back_wings.set(true);
  // chassis.set_drive_exit_conditions(0.3, 10, 600);
  // chassis.drive_distance(-8);
  // chassis.turn_to_angle(180);
  // back_wings.set(false);
  // chassis.turn_to_angle(180);
  chassis.diff(-100, -51, 1600, 300);
  // wait(1400,msec);
  chassis.turn_to_angle(0);
  chassis.drive_distance(12);
  chassis.DriveL.spin(fwd, -9, volt);
  chassis.DriveR.spin(fwd, -9, volt);
  wait(800,msec);
  chassis.set_heading(180);

  chassis.left_swing_to_angle(235);
  chassis.drive_distance(18);
  chassis.turn_to_angle(270);
  pistonratchet.set(true);
  chassis.set_drive_exit_conditions(0.3, 10, 1100);
  chassis.drive_distance(39,270,8,8);
  pistonratchet.set(false);

}



void odom_test(){
  chassis.set_coordinates(0, 0, 0);
  while(1){
    Brain.Screen.clearScreen();
    Brain.Screen.printAt(0,50, "X: %f", chassis.get_X_position());
    Brain.Screen.printAt(0,70, "Y: %f", chassis.get_Y_position());
    Brain.Screen.printAt(0,90, "Heading: %f", chassis.get_absolute_heading());
    Brain.Screen.printAt(0,110, "ForwardTracker: %f", chassis.get_ForwardTracker_position());
    Brain.Screen.printAt(0,130, "SidewaysTracker: %f", chassis.get_SidewaysTracker_position());
    task::sleep(20);
  }
}

void tank_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.turn_to_point(24, 24);
  chassis.drive_to_point(24,24);
  chassis.drive_to_point(0,0);
  chassis.turn_to_angle(0);
}

void holonomic_odom_test(){
  odom_constants();
  chassis.set_coordinates(0, 0, 0);
  chassis.holonomic_drive_to_point(0, 18, 90);
  chassis.holonomic_drive_to_point(18, 0, 180);
  chassis.holonomic_drive_to_point(0, 18, 270);
  chassis.holonomic_drive_to_point(0, 0, 0);
}