#include "Controller.h"

Controller::Controller(Service *serv, ClockService *clockServ, TempHumidService *tempHumiServ, MotorService *motorServ)
{
    this->service = serv;
    this->clockService = clockServ;
    this->tempHumidService = tempHumiServ;
    this->motorService = motorServ;
    this->lightState = LIGHT_OFF;
}

Controller::~Controller()
{
}

void Controller::updateEvent(std::string strBtn)
{
    if (strBtn == "modeButton")
    {
        service->updateState("modeButton");
    }
    if (strBtn == "powerButton")
    {
        service->updateState("powerButton");
    }
    
    
    if (strBtn == "clockUpdate")
    {
        clockService->updateEvent();

    }
      if (strBtn == "timerButton")
    {
        clockService->updateClockState("timerButton");
    }
     if (strBtn == "runstopButton")
    {
        clockService->updateTimerState("runstopButton");
    }
     if (strBtn == "resetButton")
    {
        clockService->updateTimerState("resetButton");
    }
    
    
    if (strBtn == "motorButton")
    {
        motorService->updateMotor("motorButton");
    }
   
}

void Controller::updateTempHumid(DHT_Data dhtData)
{
    tempHumidService->updateEvent(dhtData);
}

void Controller::updateDistance(int distance)
{
    service->updateDistance(distance);
}

void Controller::updateMotor(bool onoff)
{
    if(onoff)
        motorService->updateMotor("true");
    else
        motorService->updateMotor("false");
}