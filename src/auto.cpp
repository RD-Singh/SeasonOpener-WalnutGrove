/*#include "main.h"

pros::Motor trayM(4, HIGHSPEED, N_REV, DEGREES);

pros::Motor rIntake(3, HIGHSPEED, N_REV, DEGREES);
pros::Motor lIntake(8, HIGHSPEED, REV, DEGREES);
pros::Motor liftM(7, HIGHSPEED, REV, DEGREES);

static Drive * move = new Drive();
static Motors * m = new Motors();

//double targetDistance, int maxPower, int rIntakePL, int trayP, int liftP

Auto::Auto()
{

}

void Auto::deployment()
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

void Auto::rSmallZn()
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

void Auto::bSmallZn()
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

  pros::delay(550);

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

void Auto::redDoubleZone()
{
  Auto::deployment();

  move->move(40, 85, 127, 0, -40);

  move->move(-7, 90, 127, 0, -40);

  move->move(15, 90, 127, 0, -20);

  move->move(-15, 90, 127, 0, -20);

  pros::delay(150);

  move->turn(-138, 55);

  pros::delay(100);


}

/*
//old code for four point one
void redDoubleZone()
{
  deployment();

  move->move(16, 48, 127, 0, -40);

  pros::delay(100);

  move->turn(90, 55);

  pros::delay(100);

  move->move(25.3, 50, 127, 0, -40);

  move->move(-22.5, 90, 57, 0, 0);

  pros::delay(100);

  move->turn(138, 55);

  pros::delay(100);

  m->drive(56, 80, 700);

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

void Auto::blueDoubleZone()
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

  move->move(16, 48, 127, 0, -40);

  pros::delay(100);

  move->turn(-90, 55);

  pros::delay(100);

  move->move(25.3, 50, 127, 0, -35);

  move->move(-22.5, 90, 94, 0, 0);

  pros::delay(100);

  move->turn(-140, 55);

  pros::delay(100);

  m->drive(56, 80, 700);

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

void Auto::onePdoubleZone()
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
*/
