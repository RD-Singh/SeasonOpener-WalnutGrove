#include "main.h"

pros::Motor leftBDrive(11, HIGHSPEED, N_REV, DEGREES);
pros::Motor rightBDrive(9, HIGHSPEED, REV, DEGREES);
pros::Motor leftFDrive(1, HIGHSPEED, N_REV, DEGREES);
pros::Motor rightFDrive(10, HIGHSPEED, REV, DEGREES);

pros::Vision vision (6);

//static Motors * dr = new Motors();

Vision::Vision()
{

}

void Vision::visionCorrect(int sig)
{
  int midX = 158;

  bool linedUp = true;

  int x;

  while(linedUp)
  {
    pros::vision_object_s_t obj = vision.get_by_sig(0, sig);
    x = obj.x_middle_coord;

    if(x < (midX - 4))
    {
      leftBDrive.move(-20);
      leftFDrive.move(-20);
      rightFDrive.move(20);
      rightBDrive.move(20);
    }
    else if(x > (midX + 4))
    {
      leftBDrive.move(20);
      leftFDrive.move(20);
      rightFDrive.move(-20);
      rightBDrive.move(-20);
    }
    else
    {
      linedUp = false;
    //  dr->setZero();
    }
    pros::lcd::set_text(5, "The Current Number is: " + std::to_string(x));

  }
}
