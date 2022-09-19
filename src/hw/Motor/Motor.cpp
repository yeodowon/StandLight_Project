#include "Motor.h"

Motor::Motor(int pin)
{
    this->pinNumber = pin;
    softPwmCreate(this->pinNumber, 0, 100);
    motorSet = false;
}

Motor::~Motor()
{
}

void Motor::PWM_Write(int speed)
{
    softPwmWrite(this->pinNumber, speed);
}