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
 pros::Motor trayM(4, HIGHSPEED, N_REV, DEGREES);

 pros::Motor rIntake(3, HIGHSPEED, N_REV, DEGREES);
 pros::Motor lIntake(8, HIGHSPEED, REV, DEGREES);
 pros::Motor liftM(7, HIGHSPEED, REV, DEGREES);

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

//static Auto * auto = new Auto();

void deployment()
{
  rIntake.move(-127);
  lIntake.move(-127);
  liftM.move(127);
  trayM.move(15);

  pros::delay(1100);

  trayM.move(0);
  liftM.move(-127);
  lIntake.move(0);
  rIntake.move(0);

  pros::delay(650);
}
/*
void redDoubleZone()
{
  deployment();

  move->move(40, 85, 127, 0, -40);

  move->move(-7, 90, 127, 0, -40);

  move->move(15, 90, 127, 0, -20);

  move->move(-15, 90, 127, 0, -20);

  pros::delay(150);

  move->turn(-138, 55);

  pros::delay(100);
}
*/

void bSmallZn()
{
  deployment();

  move->move(35.5, 90, 127, -50, -87);

  move->move(-12.5, 90, 90, 0, -30);

  move->turn(50, 80);

  pros::delay(100);

  move->move(-24, 95, 90, 0, 0);

  move->turn(-50, 80);

  pros::delay(100);

  move->move(25.5, 70, 127, 0, 0);

  lIntake.move(127);
  rIntake.move(127);

  pros::delay(300);

  move->move(-11.5, 85, 127, 0, 0);

  pros::delay(500);

  move->turn(-131.5, 70);

  pros::delay(150);

  m->drive(75, 80, 760);

  rIntake.move(40);
  lIntake.move(40);

  trayM.move_relative(350, 40);

  pros::delay(700);

  rIntake.move(0);
  lIntake.move(0);

  pros::delay(500);

  trayM.move_relative(120, 30);

  pros::delay(600);

  m->drive(30, 40, 480);

  move->move(-9, 127, 0, 0, 0);

//  move->move(-10, 40, -10, 0, 0);
}

void rSmallZn()
{
  deployment();

  move->move(35.5, 90, 127, -50, -87);

  move->move(-12.1, 90, 90, 0, -30);

  move->turn(-50, 80);

  pros::delay(100);

  move->move(-23.5, 95, 90, 0, 0);

  move->turn(52.5, 80);

  pros::delay(100);

  move->move(25.5, 70, 127, 0, 0);

  lIntake.move(127);
  rIntake.move(127);

  pros::delay(300);

  move->move(-11.5, 85, 127, 0, 0);

  pros::delay(500);

  move->turn(131, 70);

  pros::delay(150);

  m->drive(75, 80, 760);

  rIntake.move(40);
  lIntake.move(40);

  trayM.move_relative(350, 40);

  pros::delay(700);

  rIntake.move(0);
  lIntake.move(0);

  pros::delay(500);

  trayM.move_relative(120, 30);

  pros::delay(600);

  m->drive(30, 40, 480);

  move->move(-9, 127, 0, 0, 0);
}

void robotSkills()
{
  liftM.set_brake_mode(HOLD);

  deployment();

  move->move(36.75, 90, 127, -50, -87);

  move->move(-12.5, 90, 90, 0, -10);

  move->turn(50, 80);

  pros::delay(100);

  move->move(-24, 95, 90, 0, 0);

  move->turn(-50, 80);

  pros::delay(100);

  move->move(25.5, 65, 127, 0, 0);

  lIntake.move(127);
  rIntake.move(127);

  pros::delay(300);

  move->move(-11.7, 60, 127, 0, 0);

  pros::delay(700);

  move->turn(-132, 60);

  pros::delay(150);

  m->drive(60, 80, 900);

  rIntake.move(-20);
  lIntake.move(-20);

  trayM.move_relative(270, 30);

  pros::delay(700);

  rIntake.move(0);
  lIntake.move(0);

  pros::delay(650);

  trayM.move_relative(140, 25);

  pros::delay(1800);

  move->move(-18, 80, 0, -120, 0);

  pros::delay(300);

  move->turn(137, 40);

  pros::delay(300);

  move->move(14.5, 50, 87, 0, 0);

  move->move(-5, 40, 0, 0, 80);

  liftM.move(127);

  pros::delay(850);

  liftM.move(0);
  rIntake.move(-90);
  lIntake.move(-90);

  pros::delay(750);

  rIntake.move(0);
  lIntake.move(0);

  move->move(-10, 67, 0, 0, -80);

  pros::delay(100);

  move->turn(-44, 60);

  pros::delay(100);

  move->move(20.5, 55, 80, 0, -60);

  rIntake.move(80);
  lIntake.move(80);

  pros::delay(1000);

  rIntake.move(0);
  lIntake.move(0);

  pros::delay(200);

  move->move(-22, 87, -35, 0, 0);

  pros::delay(100);

  move->turn(-50, 60);

  pros::delay(100);

  liftM.move(127);

  pros::delay(200);

  move->move(11, 87, 0, 0, 127);

  rIntake.move(-80);
  lIntake.move(-80);

  pros::delay(750);

  move->move(-14, 70, 0, 0, -105);

  pros::delay(100);

  move->turn(-170, 60);

  pros::delay(100);

  move->move(8, 50, 75, 0, 0);

  pros::delay(100);

  move->move(-6.5, 40, -20, 0, 80);

  liftM.move(127);

  pros::delay(850);

  move->move(6.5, 60, 0, 0, 0);

  pros::delay(100);

  move->turn(-10, 60);

  liftM.move(0);
  rIntake.move(-100);
  lIntake.move(-100);

  pros::delay(750);

  rIntake.move(0);
  lIntake.move(0);

  move->move(-5, 60, 0, 0, -60);
}

//double targetDistance, int maxPower, int rIntakePL, int trayP, int liftP


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
  //bSmallZn();
  //robotSkills();
//  bSmallZn();

  robotSkills();
}
