#ifndef _VISION_H_
#define _VISION_H_

#include "main.h"

class Vision
{
  public:

    explicit Vision();
    void visionCorrect(int sig);
    void visionPID(int power, int e, int sig);
};

#endif
