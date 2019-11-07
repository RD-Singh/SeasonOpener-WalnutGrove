#ifndef _MOTORS_H_
#define _MOTORS_H_

class Motors
{
  public:

    explicit Motors();
    void driveBrakeHold();
    void resetBrake();
    void resetPos();
    void ultrasonicPID (int power);
    void sonicReset(int power, int cm);
    void drive(int speed, int trayP, int time);
    void setZero();
};


#endif
