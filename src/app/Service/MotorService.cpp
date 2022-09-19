#include "MotorService.h"

MotorService::MotorService(MotorView *motorView)
{
    this->motorView = motorView;
    this-> motorButtonCnt = 0;
}

MotorService::~MotorService()
{

}

void MotorService::updateMotor(std::string strState)
{
   if (strState == "true")
   {
    motorView->updateMotor(70);
   }
   else if(strState == "motorButton")
   {
    motorButtonCnt++;
    if (motorButtonCnt > 5) motorButtonCnt = 0;
        motorView->updateMotor(motorButtonCnt*20);
   }
   else
   {
    if(motorButtonCnt > 5) motorButtonCnt = 0;
        motorView->updateMotor(motorButtonCnt*20);
   }
}
