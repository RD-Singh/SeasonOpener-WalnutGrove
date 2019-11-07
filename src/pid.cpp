/*#include "main.h"
#include "definitions.h"
#include "pid.h"

PID::PID()
{

}

void PID::driveSet(int speed){
  leftF.move(speed);
  leftB.move(speed);
  rightF.move(speed);
  rightB.move(speed);
}

void PID::leftSet(int speed){
  leftF.move(speed);
  leftB.move(speed);
}

void PID::rightSet(int speed){
  rightF.move(speed);
  rightB.move(speed);
}

double PID::powerLimit(double maxSpeed, double currentSpeed){

      if (currentSpeed > maxSpeed){
          currentSpeed = maxSpeed;
      }

      if (currentSpeed < -maxSpeed){
          currentSpeed = -maxSpeed;
      }

      return currentSpeed;
  }

  void PID::initializePID(double kp, double ki, double kd, double integralLimit, double integralUsage){

       kp = kp;
       ki = ki;
       kd = kd;

       proportional = 0;
       integral = 0;
       derivative = 0;

       integralLimit = integralLimit;
       error = 0;
       last_error = 0;
       power = 0;
       integralUsage = integralUsage;

  }

  double PID::calculatePID(double target, double sensor){

      error = target - sensor;
      derivative = (error -  last_error);
      last_error =  error;
      proportional =  error;
      integral =  error +  integral;

          if ((integral)*(ki) >  integralLimit){
             integral =  integralLimit;
          }
          if ((integral)*(ki) < -integralLimit){
             integral = - integralLimit;
          }

          if(abs(error) > integralUsage){
             integral = 0;
          }

       power = (proportional)*( kp) + (integral)*(ki) + (derivative)*(kd);

      return power;

  }


void PID::resetEncoders(){
 leftF.tare_position();
 leftB.tare_position();
 rightF.tare_position();
 rightB.tare_position();
}

/*void PID::reset_error_globals(){
 correction_drive = 0;
 correction_turn = 0;
 degrees_flag = 0;
 prev_correction_turn = 0;
 prev_correction_drive = 0;
 drive_distance_correction = 0;

 reset_gyro = true;
 prev_degs = 0;
}


void PID::drivePID(double target, int maxSpeed){

 resetEncoders();			//reset encoder values

    double Kp = 0.21;
    double Ki = 0.01;
    double Kd = 0.3;


     double finalPower;
     double calculatedPower;

     double targetTick = (target/(4*pi)) * 900;

//     double error_c;

     double encoderAvg = 0;

     PID::initializePID(Kp, Ki, Kd, 40, (12/(4*pi)*900));


     error = targetTick - encoderAvg;

         while(error != 0){

           encoderAvg = (leftF.get_position() + rightF.get_position() +
                             leftB.get_position() + rightB.get_position())/4;

           calculatedPower = PID::calculatePID(((target)/(4*pi) * 900), encoderAvg);

           finalPower = PID::powerLimit(maxSpeed, calculatedPower);

            // error_c = correction_drive + gyro.get_value();

             PID::leftSet(finalPower);
             PID::rightSet(finalPower);


           if (abs(error) < (1/(4*pi) * 900)){	//less than 1 inches

             error = 0;
             PID::driveSet(0);
           }

         pros::delay(20);

     }
     PID::resetEncoders();

   }*/
