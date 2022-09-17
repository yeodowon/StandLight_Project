#include "View.h"
#include <wiringPi.h>

View::View(Led *led1, Led *led2, Led *led3, Led *led4, Led *led5, LCD *lcd)
{
    this->light1 = led1;
    this->light2 = led2;
    this->light3 = led3;
    this->light4 = led4;
    this->light5 = led5;
    this->lcd = lcd;
    this->lightState = LIGHT_OFF;
}

View::~View()
{

}

void View::setState(int state)
{
    lightState = state;
}

void View::lightView()
{
    switch (lightState)
    {
        case LIGHT_OFF:
            lightOff();
        break;
        case LIGHT_1:
            lightOn_1();
        break;
        case LIGHT_2:
            lightOn_2();
        break;
        case LIGHT_3:
            lightOn_3();
        break;
        case LIGHT_4:
            lightOn_4();
        break;
        case LIGHT_5:
            lightOn_5();
        break;
    }
}

void View::lightOn_1()
{
    light1->On();
    light2->Off();
    light3->Off();
    light4->Off();
    light5->Off();
}

void View::lightOn_2()
{
    light1->On();
    light2->On();
    light3->Off();
    light4->Off();
    light5->Off();
}

void View::lightOn_3()
{
    light1->On();
    light2->On();
    light3->On();
    light4->Off();
    light5->Off();
}

void View::lightOn_4()
{
    light1->On();
    light2->On();
    light3->On();
    light4->On();
    light5->Off();
}

void View::lightOn_5()
{
    light1->On();
    light2->On();
    light3->On();
    light4->On();
    light5->On();
}

void View::lightOff()
{
    light1->Off();
    light2->Off();
    light3->Off();
    light4->Off();
    light5->Off();
}

void View::lcdDisplay()
{
    char buff[30];
    sprintf(buff, "Light:%d", lightState);
    lcd->WriteStringXY(0, 0, buff);
}

void View::lcdView()
{
    switch (lightState)
    {
    case LIGHT_OFF:
        lcdDisplay();
        lcd->backLightOff();
        break;

    case LIGHT_1:
        lcdDisplay();
        lcd->backLightOn();
        break;

    case LIGHT_2:
        lcdDisplay();
        break;

    case LIGHT_3:
        lcdDisplay();

        break;

    case LIGHT_4:
        lcdDisplay();

        break;

    case LIGHT_5:
        lcdDisplay();

        break;
    }
}
