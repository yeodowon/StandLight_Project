#ifndef MOTOR_H
#define MOTOR_H

#include <iostream>
#include <softPwm.h>

class Motor
{
private:
    int pinNumber;

public:
    bool motorSet;
    
    Motor(int pin);
    
    virtual ~Motor();

    void PWM_Write(int speed);
};

#endif