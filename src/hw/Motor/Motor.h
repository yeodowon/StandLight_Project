#ifndef MOTOR_H
#define MOTOR_H

#include<softPwm.h>
#include<wiringPi.h>

#pragma once

class Motor
{
private:
    const bool On = 1;
    const bool Off = 0;
    
    int pinNumber;
    bool motorState;

    void writePin(bool pinState);

public:
    Motor(int pin);
    virtual ~Motor();

    void motorOn();
    void motorOff();


};

#endif