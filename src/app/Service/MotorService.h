#ifndef MOTORSERVICE_H
#define MOTORSERVICE_H

#include <string>
#include "MotorView.h"


class MotorService
{
private:
    int motorButtonCnt;
    MotorView *motorView;
public:
    MotorService(MotorView *motorView);
    virtual ~MotorService();

    void updateMotor(std::string strState);   
};

#endif