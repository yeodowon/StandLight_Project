#include "Service.h"
#include <iostream>

using namespace std;

Service::Service(View *viewer)
{
    view = viewer;
    lightState = LIGHT_OFF;
    bDistanceLight = false;
    distanceErrorCounter = 0;
}

Service::~Service()
{
}

void Service::updateState(std::string strState)
{
    switch (lightState)
    {
    case LIGHT_OFF:
        if (strState == "modeButton")
        {
            lightState = LIGHT_1;
            view->setState(lightState);
        }
        break;

    case LIGHT_1:
        if (strState == "modeButton")
        {
            lightState = LIGHT_2;
        }
        if (strState == "powerButton")
        {  
            lightState = LIGHT_OFF;
        }
        view->setState(lightState);
        if (bDistanceLight == true)
        {
            view->setState(lightState);
        }

        else
        {
            view->setState(LIGHT_OFF);
        }
        break;
    case LIGHT_2:
        if (strState == "modeButton")
        {
            lightState = LIGHT_3;
        }
        if (strState == "powerButton")
        {
            lightState = LIGHT_OFF;
        }
        view->setState(lightState);
        if (bDistanceLight == true)
        {
            view->setState(lightState);
        }

        else
        {
            view->setState(LIGHT_OFF);
        }
        break;
    case LIGHT_3:
        if (strState == "modeButton")
        {
            lightState = LIGHT_4;
        }
        if (strState == "powerButton")
        {
            lightState = LIGHT_OFF;
        }
        view->setState(lightState);
        if (bDistanceLight == true)
        {
            view->setState(lightState);
        }

        else
        {
            view->setState(LIGHT_OFF);
        }
        break;
    case LIGHT_4:
        if (strState == "modeButton")
        {
            lightState = LIGHT_5;
        }
        if (strState == "powerButton")
        {
            lightState = LIGHT_OFF;
        }
        view->setState(lightState);
        if (bDistanceLight == true)
        {
            view->setState(lightState);
        }

        else
        {
            view->setState(LIGHT_OFF);
        }
        break;
    case LIGHT_5:
        if (strState == "modeButton")
        {
            lightState = LIGHT_OFF;
        }
        if (strState == "powerButton")
        {
            lightState = LIGHT_OFF;
        }
        view->setState(lightState);
        if (bDistanceLight == true)
        {
            view->setState(lightState);
        }

        else
        {
            view->setState(LIGHT_OFF);
        }
        break;
    }
}

void Service::updateDistance(int distance)
{
    cout << "distance : " << distance << endl;

    if (distance < 0) // Light off
    {
        distanceErrorCounter++;
        if (distanceErrorCounter >=10){
        bDistanceLight = false;
        view->setState(LIGHT_OFF);
        }
    }
    else // Light on
    {
        distanceErrorCounter = 0;
        bDistanceLight = true;
        view->setState(lightState);
    }
}
