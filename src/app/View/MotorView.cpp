#include "MotorView.h"

MotorView::MotorView(Motor *motor)
{
    this->motor = motor;
    }

MotorView::~MotorView()
{

}

void MotorView::updateMotor(int spd)
{
    motor->PWM_Write(spd);
}