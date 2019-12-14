#include "main.h"

pros::Motor backL(2, HIGHSPEED, N_REV, COUNTS);
pros::Motor backR(9, HIGHSPEED, REV, COUNTS);
pros::Motor frontL(1, HIGHSPEED, N_REV, COUNTS);
pros::Motor frontR(10, HIGHSPEED, REV, COUNTS);
pros::Motor tray(4, TORQUE, N_REV, DEGREES);

pros::Motor intakeR(6, HIGHSPEED, N_REV, DEGREES);
pros::Motor intakeL(8, HIGHSPEED, REV, DEGREES);
pros::Motor lift(7, HIGHSPEED, REV, DEGREES);

static Motors * drive = new Motors();

double integralLimit = 10;
double integralActiveZone = (12/(12.566) * 900);

Drive::Drive()
{

}
/*
void Drive::turnPID(int power)
{
  double kp = 0.75;
  int main = 0;
  int secondary = 0;
  int error = 1;
  int powerLeft, powerRight;
  int maxPower = power;
  int MIN_POWER = maxPower - 4;

  main = (abs(frontR.get_position()) >= abs(frontL.get_position())) ? abs(frontR.get_position()) : abs(frontL.get_position());
  secondary = (abs(frontR.get_position()) >= abs(frontL.get_position())) ? abs(frontL.get_position()) : abs(frontR.get_position());
  error = main - secondary;

  if(main > secondary)
  {
      power = power - (error * kp);
   }

  if(power > 0)
  {
    if(power < MIN_POWER)
    {
      power = MIN_POWER;
    }
  }
  else if(power < 0)
  {
    if(power > -MIN_POWER)
    {
      power = -MIN_POWER;
    }
  }

  if(abs(frontR.get_position()) > abs(frontL.get_position()))
  {
    powerLeft = -maxPower;
    powerRight = power;
  }
  else
  {
    powerLeft = -power;
    powerRight = maxPower;
  }

  frontL.move(powerLeft);
  frontR.move(powerRight);
  backL.move(powerLeft);
  backR.move(powerRight);

}*/
/*
void Drive::movePID(int initPower)
{
  double kp = 0.850;
  double kd = 0.980;

  int main = 0;
  int secondary = 0;
  int error = 0;
  int powerLeft, powerRight;
  int derivative;
  int lastError = 0;

  int maxPower = initPower;
  int MIN_POWER = maxPower - 2;
  //int leftPos = (abs(lfdMotor.get_position()) + abs(lbdMotor.get_Position())/2;
  main = ((frontR.get_position()) >= (frontL.get_position())) ? (frontR.get_position()) : (frontL.get_position());
  secondary = ((frontR.get_position()) >= (frontL.get_position())) ? (frontL.get_position()) : (frontR.get_position());

  error = (main - secondary);
  derivative = error - lastError;
  lastError = error;
  int power = 0;

  if(main > secondary)
  {
     power = (error * kp) + (derivative * kd);
  }

  if(power > 0)
  {
    if(power < MIN_POWER)
    {
      power = MIN_POWER;
    }
  }
  else if(power < 0)
  {
    if(power > -MIN_POWER)
    {
      power = -MIN_POWER;
    }
  }

  if(frontR.get_position() > frontL.get_position())
  {
    powerLeft = maxPower;
    powerRight = power;
  }
  else
  {
    powerLeft = power;
    powerRight = maxPower;
  }

  frontL.move(powerLeft);
  frontR.move(powerRight);
  backL.move(powerLeft);
  backR.move(powerRight);
}


void Drive::backPID(int power)
{
  double kp = 0.735;

 int main = 0;
 int secondary = 0;
 int error = 1;
  int powerLeft, powerRight;

  int maxPower = power;
  int MIN_POWER = maxPower - 5;
  //int leftPos = (abs(lfdMotor.get_position()) + abs(lbdMotor.get_Position())/2;
 main = (abs(frontR.get_position()) >= abs(frontL.get_position())) ? abs(frontR.get_position()) : abs(frontL.get_position());
 secondary = (abs(frontR.get_position()) >= abs(frontL.get_position())) ? abs(frontL.get_position()) : abs(frontR.get_position());

 error = main - secondary;

  if(main > secondary)
  {
     power = power - (error * kp);
  }


  if(power > 0)
  {
    if(power < MIN_POWER)
    {
      power = MIN_POWER;
    }
  }
  else if(power < 0)
  {
    if(power > -MIN_POWER)
    {
      power = -MIN_POWER;
    }
  }

  if(frontR.get_position() > frontL.get_position())
  {
    powerLeft = maxPower;
    powerRight = power;
  }
  else
  {
    powerLeft = power;
    powerRight = maxPower;
  }

    frontL.move(powerLeft);
    frontR.move(powerRight);
    backL.move(powerLeft);
    backR.move(powerRight);
}

void Drive::turn(double degrees, int speed)
 {
  drive->resetPos();

  double kw = 2.686;

  double currentBearing = 0;
  double error = 10;
  double targetBearing = degrees * kw;

  int left, right;

  while(error != 0)
  {
    left = abs(frontL.get_position());
    right = abs(frontR.get_position());

    currentBearing = (left + right)/2;

    error = targetBearing - currentBearing;

    turnPID(speed);

    if(error < 5 && error > -5)
    {
      error = 0;
      drive->driveBrakeHold();
      drive->setZero();
    }
  }
  drive->setZero();
  drive->resetPos();
}


void Drive::move(double targetDistance, int maxPower, int flyWheelP, int indexerP, int intakeP, int tipperP)
{
  int currentDistance = 0;
  double error = 20, lastError = 0, derivative;

  int targ = (targetDistance/12.566) * 900;

  int leftF, rightF;

  int MAX_POWER = maxPower, MIN_POWER = 30;

  double kp = 0.365, kd = 0.950;

  drive->resetPos();

  int power = 0, paramPower;

  if(maxPower > 0)
  {
    power = 4;
    while(power < maxPower)
    {
      power*=1.575;

      frontL.move(power);
      frontR.move(power);
      backL.move(power);
      backR.move(power);
      pros::delay(50);
    }
  }

  if(maxPower < 0)
  {
    power = -4;
    while(power > -maxPower)
    {
      power*=1.325;

      frontL.move(power);
      frontR.move(power);
      backL.move(power);
      backR.move(power);
      pros::delay(50);
    }
  }

 while(error != 0)
 {
    leftF = abs(frontL.get_position());
    rightF = abs(frontR.get_position());

    currentDistance = (leftF + rightF)/2;

    error = targ - currentDistance;
    derivative = error - lastError;
    lastError = error;


    paramPower = (error * kp) + (derivative * kd);

    if(maxPower < 0)
    {
      paramPower = -paramPower;
    }

    if(paramPower > 0)
    {
      if (paramPower > MAX_POWER)
      {
        paramPower = maxPower;
      }
      else if(paramPower < MIN_POWER)
      {
        paramPower = MIN_POWER;
      }
    }
    else if(paramPower < 0)
    {
      if (paramPower < MAX_POWER)
      {
        paramPower = maxPower;
      }
      else if(paramPower > -MIN_POWER)
      {
        paramPower = -MIN_POWER;
      }
    }

    if(maxPower > 0)
    {
      movePID(paramPower);
    }
    else if(maxPower < 0)
    {
      backPID(paramPower);
    }

      if(error < 20)
      {
        drive->setZero();
        drive->driveBrakeHold();
        error = 0;
      }

      pros::delay(5);
  }
  drive->resetPos();
}*/

void Drive::turn(double degrees, int speed)
{

    pros::ADIGyro gyro ('A', 1.03);
    gyro.reset();

    tray.set_brake_mode(HOLD);
    double kp = 0.061; //0.23 on friday //0.24
    double kd = 0.085; //2.7 on friday //2.65 at BCIT //1.54
    double ki = 0.07;

    int maxSpeed = 80;			//caping minimum and maximum speeds for robot

    double power;
    double finalPower;
    double error = 1;

    double targetBearing = degrees*10;
    double currentBearing;

    while(error!=0)
    {
      currentBearing = gyro.get_value();
      error = targetBearing - currentBearing;

      power = Drive::pidCal(targetBearing, currentBearing, kp, ki, kd);

      finalPower = powerLimit(maxSpeed, power);

      frontL.move(finalPower);
      frontR.move(-finalPower);
      backL.move(finalPower);
      backR.move(-finalPower);

      if (fabs(error) < 70)
      {
        error = 0;
        drive->driveBrakeHold();
      }

      pros::delay(20);
    }

    frontL.move(0);
    frontR.move(0);
    backL.move(0);
    backR.move(0);

}

double Drive::pidCal(double targetDistance, double currentDistance, double kp, double ki, double kd)
{
    double lastError = 0;
    double power;

    double error = targetDistance - currentDistance;
    double derivative = (error - lastError);

    lastError = error;

    double proportional = error;
    double integral = error + integral;

           if ((integral * ki) > integralLimit)
           {
             integral = integralLimit;
           }
           if ((integral * ki) < -integralLimit)
           {
             integral = -integralLimit;
           }

           if(fabs(error) > integralActiveZone)
           {
             integral = 0;
           }

       power = (proportional * kp) + (integral * ki) + (derivative * kd);

       return power;
}

double Drive::powerLimit(double maxSpeed, double speed){

       if (speed > maxSpeed){
           speed = maxSpeed;
       }

       if (speed < -maxSpeed){
           speed = -maxSpeed;
       }

       return speed;
   }

void Drive::move(double targetDistance, int maxPower, int intakeP, int trayP, int liftP)
{

    pros::ADIGyro gyro ('A', 0.967742);
    int currentDistance = 0;

    gyro.reset();

    double error = (targetDistance < 0) ? -20 : 20, secError;

    int leftF, rightF, rightB, leftB;

    double kp = 0.105, kd = 0.08, ki = 0.01, secKp = 0.2;

    drive->resetPos();
    drive->resetBrake();


    int power = 0, finalPower;

    double targ = targetDistance/(12.566) * 900;

    if(targetDistance > 0)
    {
      power = 5;
      while(power < maxPower)
      {
        power*=1.52;

        frontL.move(power);
        frontR.move(power);
        backL.move(power);
        backR.move(power);
        pros::delay(50);
      }
    }

    if(targetDistance < 0)
    {
      power = -4;
      while(power > -maxPower)
      {
        power*=1.52;

        frontL.move(power);
        frontR.move(power);
        backL.move(power);
        backR.move(power);
        pros::delay(50);
      }
    }

    while(error != 0)
    {
      leftF = (frontL.get_position());
      rightF = (frontR.get_position());
      leftB = (backL.get_position());
      rightB = (backR.get_position());

      currentDistance = (leftF + rightF + leftB + rightB)/4;

      error = targ - currentDistance;

      power = Drive::pidCal(targ, currentDistance, kp, ki, kd);

      finalPower = Drive::powerLimit(maxPower, power);

      secError = gyro.get_value();//((leftF - rightF)/900) * 360;

      frontL.move(finalPower - (secError * secKp));
      frontR.move(finalPower + (secError * secKp));
      backL.move(finalPower - (secError * secKp));
      backR.move(finalPower + (secError * secKp));

      tray.move(trayP);
      lift.move(liftP);
      intakeR.move(intakeP);
      intakeL.move(intakeP);


        if(fabs(error) < 120)
        {
          drive->setZero();
          drive->resetBrake();
          error = 0;
        }

        pros::delay(20);
    }

    tray.move(0);
    lift.move(0);
    intakeR.move(0);
    intakeL.move(0);
}
/*
void Drive::arcTurn(double distance, double degrees, int intakeP, int trayP, int liftP)
{
  int maxSpeed = 110;

  Drive::move(distance, maxSpeed, intakeP, trayP, liftP);

  tray.set_brake_mode(HOLD);

  pros::ADIGyro gyro ('A', 1.03);

  double kp = 0.061; //0.23 on friday //0.24
  double kd = 0.085; //2.7 on friday //2.65 at BCIT //1.54
  double ki = 0.07;

  double power;
  double finalPower;
  double error = 1;
  double errorRight, errorLeft, KpDist = 0.06;

  double targetBearing = degrees*10;
  double currentBearing;
  double threshErrR, threshErrL;

  backL.set_brake_mode(COAST);
  backR.set_brake_mode(COAST);
  frontL.set_brake_mode(COAST);
  frontR.set_brake_mode(COAST);
  int diff;

  while(error!=0)
  {
    currentBearing = gyro.get_value();
    error = targetBearing - currentBearing;

    power = Drive::pidCal(targetBearing, currentBearing, kp, ki, kd);

    finalPower = distance < 0 ? -127 : 127;

    int diff = distance < 0 ? 25 : -25;


    errorLeft = (frontL.get_position() + backL.get_position())/2;
    errorRight = (frontR.get_position() + backL.get_position())/2;

    threshErrR = (errorRight * KpDist) > finalPower ? finalPower + diff : (errorRight * KpDist);
    threshErrL = (errorLeft * KpDist) < finalPower ? (errorLeft * KpDist) : finalPower + diff;


       if (degrees > 0 && distance > 0){  //when bot is commanded to go right while going forward
         backL.move(finalPower);
         frontL.move(finalPower);
         backR.move(threshErrR);
         frontR.move(threshErrR);
       }

       if (degrees < 0 && distance > 0){  //when bot is commanded to go left while forward
         backR.move(finalPower);
         frontR.move(finalPower);
         backL.move(threshErrL);
         frontL.move(threshErrL);
       }

       if (degrees > 0 && distance < 0){  //when bot is commanded to go right while going backward
         backR.move(-finalPower);
         frontR.move(-finalPower);
         backL.move(threshErrL);
         frontL.move(threshErrL);
       }

       if (degrees < 0 && distance < 0){  //when bot is commanded to go left while going backward
         backL.move(finalPower);
         frontL.move(finalPower);
         backR.move(errorRight * KpDist);
         frontR.move(errorRight * KpDist);
       }

    if (fabs(error) < 45)
    {
      error = 0;
    }

    pros::delay(20);
  }

  frontL.move(0);
  frontR.move(0);
  backL.move(0);
  backR.move(0);

}*/
void Drive::arcTurn(bool direction, bool horizontal)
{
  tray.set_brake_mode(HOLD);

  pros::ADIGyro gyro ('A', 1.03);

  double rightP= 0;
  double leftP = 0;

  if(direction)
  {
    if(horizontal)
    {
      rightP = 120;
      leftP = 50;
    }
    else
    {
      rightP = 50;
      leftP = 120;
    }
  }
  else
  {
    if(horizontal)
    {
      rightP = -90;
      leftP = -30;
    }
    else
    {
      rightP = -50;
      leftP = -120;
    }
  }

  double error = 1;


  double targetBearing = 700;
  double currentBearing;

  backL.set_brake_mode(HOLD);
  backR.set_brake_mode(HOLD);
  frontL.set_brake_mode(HOLD);
  frontR.set_brake_mode(HOLD);

  while(error!=0)
  {
    currentBearing = gyro.get_value();
    error = targetBearing - currentBearing;

    backL.move(leftP);
    frontL.move(leftP);
    backR.move(rightP);
    frontR.move(rightP);
    intakeR.move(127);
    intakeL.move(127);

    if(fabs(error) < 450)
    {
      rightP *= 0.99;
    }

    if (fabs(error) < 30)
    {
      error = 0;
    }

    pros::delay(20);
}
    frontL.move(0);
    frontR.move(0);
    backL.move(0);
    backR.move(0);

    intakeR.move(0);
    intakeL.move(0);

}
