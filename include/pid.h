#ifndef _PID_H_
#define _PID_H_

#include "main.h"
#include "definitions.h"

class PID{

public:

  explicit PID();

  void resetEncoders();
  void resetGlobals();

  void drivePID(double target, int maxSpeed);

  void initializePID(double kp, double ki, double kd, double integralLimit, double integralUsage);
  double powerLimit(double maxSpeed, double currentSpeed);
  double calculatePID(double target, double sensor);

  void driveSet(int speed);
  void turnSet(int speed);
  void leftSet(int speed);
  void rightSet(int speed);

};


#endif
