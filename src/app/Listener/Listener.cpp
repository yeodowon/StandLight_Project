#include "Listener.h"
#include <wiringPi.h>

using namespace std;

Listener::Listener(Button *modeButton, Button *powerButton, Button *motorButton, Button *timerButton, Button *runstopButton, Button* resetButton,
                   Controller *control, ClockCheck *clock, DHT11 *dht11, UltraSonic *ultraSonic, Motor *motor)
{
    this->modeButton = modeButton;
    this->powerButton = powerButton;
    this->motorButton = motorButton;
    this->timerButton = timerButton;
    this->runstopButton = runstopButton;
    this->resetButton = resetButton;
    this->controller = control;
    this->clockCheck = clock;
    this->dht11 = dht11;
    this->ultraSonic = ultraSonic;
    this->motor = motor;
}

Listener::~Listener()
{
}

void Listener::checkEvent()
{
    if (modeButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("modeButton");
    }

    if (powerButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("powerButton");
    }

    if (clockCheck->isUpdate())
    {
        controller->updateEvent("clockUpdate");
    }

     if (timerButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("timerButton");
        cout << "listen, timerButton" << endl;
    }

     if (runstopButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("runstopButton");
    }
    
       if (runstopButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("resetButton");
    }
    
    if (motorButton->getState() == RELEASE_ACTIVE)
    {
        controller->updateEvent("motorButton");
    }

    static unsigned int prevTempHumidTime = 0;
    if (millis() - prevTempHumidTime > 2000)
    {
        prevTempHumidTime = millis();
        DHT_Data dhtData = dht11->readData();
        if (!dhtData.error)
        {
            controller->updateTempHumid(dhtData);
            dht11->pre_RH = dhtData.RH;
            dht11->pre_RHDec = dhtData.RHDec;
            dht11->pre_Temp = dhtData.Temp;
            dht11->pre_TempDec = dhtData.TempDec;
        }
    }

    if (dht11->pre_Temp > 30)
    {
        controller->updateMotor(true);
    }
    else
    {
        controller->updateMotor(false);
    }

    static unsigned int prevUltraSonicTime = 0;
    if (millis() - prevUltraSonicTime > 2000)
    {
        prevUltraSonicTime = millis();
        int distance = ultraSonic->readDistance();
        controller->updateDistance(distance);
    }
}