#include "main.h"
#include "definitions.h"

pros::Motor leftB(2, HIGHSPEED, N_REV, COUNTS);
pros::Motor rightB(9, HIGHSPEED, REV, COUNTS);
pros::Motor leftF(1, HIGHSPEED, N_REV, COUNTS);
pros::Motor rightF(10, HIGHSPEED, REV, COUNTS);

pros::Motor TM(4, TORQUE, N_REV, DEGREES);

Motors::Motors()
{

}
/*
void Motors::sonicReset(int power, int cm)
{
  pros::ADIUltrasonic leftW ('C', 'D');
  pros::ADIUltrasonic rightW ('E', 'F');
  pros::ADIUltrasonic front ('G', 'H');

  int left;
  int right;
  int diff;
  int tp;
  int error = 1;

  driveBrakeHold();

  while(error != 0)
  {
    left = leftW.get_value();
    right = rightW.get_value();

    error = ((left + right)/2) - (cm * 10);

    pros::lcd::set_text(4, "left = " + std::to_string(left));
    pros::lcd::set_text(5, "right = " + std::to_string(right));

    leftF.move(power);
    leftB.move(power);
    rightB.move(power);
    rightF.move(power);

    if(error < 15 && error > -15)
    {
      error = 0;
      setZero();
    }
  }
}*/
//TODO
void Motors::drive(int speed, int trayP, int time)
{
  leftF.move(speed);
  leftB.move(speed);
  rightB.move(speed);
  rightF.move(speed);
  TM.move(trayP);

  pros::delay(time);

  leftF.move(0);
  leftB.move(0);
  rightB.move(0);
  rightF.move(0);
  TM.move(0);
}

void Motors::resetPos()
{
  leftB.tare_position();
  rightB.tare_position();
  rightF.tare_position();
  leftF.tare_position();
}

void Motors::driveBrakeHold()
{
  leftB.set_brake_mode(BRAKE);
  leftF.set_brake_mode(BRAKE);
  rightF.set_brake_mode(BRAKE);
  rightB.set_brake_mode(BRAKE);
}

void Motors::resetBrake()
{
  leftB.set_brake_mode(COAST);
  rightB.set_brake_mode(COAST);
  leftF.set_brake_mode(COAST);
  rightF.set_brake_mode(COAST);

}



void Motors::setZero()
{
  leftF.move(0);
  leftB.move(0);
  rightB.move(0);
  rightF.move(0);
}
