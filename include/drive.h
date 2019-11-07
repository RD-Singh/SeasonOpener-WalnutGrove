#ifndef _DRIVE_H_
#define _DRIVE_H_

class Drive
{
  public:

    explicit Drive();

    void turn(double degrees, int speed);
    double checkPower(double power);
    void powerDrive(int powerLeft, int powerRight);
    void turnPID(int power);
    void backPID(int power);
    void movePID(int power);
    double pidCal(double targetDistance, double currentDistance, double kp, double ki, double kd);
    double powerLimit(double maxSpeed, double speed);
    void move(double targetDistance, int maxPower, int intakeP, int trayP, int liftP);
};


#endif
