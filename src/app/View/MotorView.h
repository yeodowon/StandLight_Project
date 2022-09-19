#ifndef MOTORVIEW_H
#define MOTORVIEW_H

#include "Motor.h"

class MotorView
{
private:
    Motor *motor;

public:
    MotorView(Motor *motor);
   virtual  ~MotorView();

    void updateMotor(int spd);
   
};

#endif