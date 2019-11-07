#include "main.h"

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */

 pros::Motor trayM(4, TORQUE, N_REV, DEGREES);

 pros::Motor rIntake(3, HIGHSPEED, N_REV, DEGREES);
 pros::Motor lIntake(8, HIGHSPEED, REV, DEGREES);
 pros::Motor liftM(7, TORQUE, REV, DEGREES);


 static Drive * move = new Drive();
 static Motors * m = new Motors();

 int auton = 0;

/*
void bSmallZn()
{
  liftM.set_current_limit(2500);

  trayM.move(50);

  pros::delay(350);

  liftM.move(127);

  trayM.move(0);

  pros::delay(1600);

  liftM.move(-127);

  trayM.move(0);
  lIntake.move(0);
  rIntake.move(0);

  pros::delay(800);

  lIntake.move(97);
  rIntake.move(97);

  pros::delay(500);

  move->move(37, 62, 97, 0, -10);

  rIntake.move(77);
  lIntake.move(77);

  pros::delay(550);

  move->move(-22, 60, 50, 0, 0);

  pros::delay(300);

  move->turn(137, -70);

  pros::delay(200);

  move->move(9, 65, 40, 0, 0);

  pros::delay(300);

  trayM.move_relative(480, 30);

  pros::delay(2600);

  move->move(4, 30, 0, 0, 0);

  pros::delay(400);

  move->move(-9, 40, 0, -20, 0);
}
*/
void rSmallZn()
{
liftM.set_current_limit(2500);

trayM.move(50);

pros::delay(350);

liftM.move(127);

trayM.move(0);

pros::delay(1600);

liftM.move(-127);

trayM.move(0);
lIntake.move(0);
rIntake.move(0);

pros::delay(800);

  rIntake.move(97);
  lIntake.move(97);

  pros::delay(500);

  move->move(36, 62, 97, 0, -10);

  lIntake.move(77);
  rIntake.move(77);

  pros::delay(550);

  move->move(-21, 60, 30, 0, 0);

  pros::delay(300);

  move->turn(117, 70);

  pros::delay(200);

  move->move(8, 65, 40, 0, 0);

  pros::delay(300);

  trayM.move_relative(480, 30);

  pros::delay(2600);

  m->drive(35, 0, 600);

  pros::delay(200);

  move->move(-9, 40, 0, -20, 0);
}

void onePdoubleZone()
{
  m->drive(-70, 0, 600);

  m->drive(70, 0, 500);

  trayM.move(50);

  pros::delay(350);

  liftM.move(127);

  pros::delay(1000);

  trayM.move(0);
  lIntake.move(0);
  rIntake.move(0);

}

//double targetDistance, int maxPower, int rIntakePL, int trayP, int liftP

void bSmallZn()
{
  trayM.move(50);

  pros::delay(350);

  liftM.move(127);

  pros::delay(1000);

  trayM.move(0);
  lIntake.move(0);
  rIntake.move(0);

  move->move(10, 50, 127, -50, -127);

  move->move(27.5, 65, 127, 0, -30);

  move->move(-10.5, 65, 90, 0, -30);

  pros::delay(100);

  move->turn(50, 65);

  pros::delay(100);

  move->move(-24.5, 90, 90, 0, 0);

  pros::delay(200);

  move->turn(-49, 65);

  pros::delay(200);

  move->move(24.8, 70, 127, 0, 0);

  lIntake.move(127);
  rIntake.move(127);

  pros::delay(300);

  move->move(-13.7, 93, 127, 0, 0);

  pros::delay(300);

  move->turn(-134, 55);

  pros::delay(150);

  m->drive(60, 80, 700);

  rIntake.move(40);
  lIntake.move(40);

  trayM.move_relative(350, 40);

  pros::delay(700);

  rIntake.move(0);
  lIntake.move(0);

  pros::delay(800);

  trayM.move_relative(80, 25);

  pros::delay(400);

  m->drive(20, 0, 400);

  move->move(-9, 40, 0, -20, 0);

//  move->move(-10, 40, -10, 0, 0);
}

void doubleZone()
{
  trayM.move(50);

  pros::delay(350);

  liftM.move(127);

  pros::delay(1000);

  trayM.move(0);
  liftM.move(-127);
  lIntake.move(0);
  rIntake.move(0);

  pros::delay(850);

  move->move(16, 48, 127, 0, -30);

  pros::delay(100);

  move->turn(90, 55);

  pros::delay(100);

  move->move(27, 50, 80, 0, -20);

  move->move(-23, 90, 57, 0, 0);

  pros::delay(100);

  move->turn(145, 55);

  pros::delay(100);

  m->drive(40, 80, 700);

  rIntake.move(-20);
  lIntake.move(-20);

  trayM.move_relative(350, 50);

  pros::delay(700);

  rIntake.move(0);
  lIntake.move(0);

  pros::delay(600);

  trayM.move_relative(120, 25);

  pros::delay(400);

  m->drive(30, 0, 580);

  move->move(-9, 40, 0, -20, 0);
}

void autonomous() {
/*
  if(auton == 0)
  {
    rSmallZn();
  }
  else if(auton == 1)
  {
    bSmallZn();
  }
  else if(auton == 2)
  {
    doubleZone();
  }
  else if(auton == 3)
  {
    onePdoubleZone();
  }*/
  doubleZone();
//  bSmallZn();

}
