#include "ClockView.h"
#include "wiringPi.h"
#include <stdio.h>

ClockView::ClockView(LCD *lcd)
{
    this->lcd = lcd;
    //timeDate = 0;
}

ClockView::~ClockView()
{
}

void ClockView::setClockState(int clockstate)
{
    clockState = clockstate;
}

void ClockView::setTimerState(int timerstate)
{
    timerState = timerstate;
}

void ClockView::updateTimerCount()
{
    static unsigned int prevTimerTime = 0;

    switch(timerState)
    {
        case TIMER_START:
            if(millis() - prevTimerTime >= 1000)
            {
                prevTimerTime = millis();
                timerCount++;
            }
        break;

        case TIMER_TEMPSTOP:
            Temp_timerCount = timerCount;
        break;

        case TIMER_RESTART:
            timerCount = Temp_timerCount;
            timerState = TIMER_START;
        break;

        case TIMER_RESET:
            prevTimerTime = 0;
            timerCount = 0;
            Temp_timerCount = 0;
            timerState = TIMER_STOP;
        break;
    }
}



void ClockView::updateTime(struct tm *timeData)
{
    char buff[30];
    sprintf(buff, "%02d:%02d:%02d",
            timeData->tm_hour,
            timeData->tm_min,
            timeData->tm_sec);
    lcd->WriteStringXY(1, 0, buff);
}


void ClockView::TimerView()
{
    if(clockState == TIMER)
    {
        char buff[30];
        unsigned int timerCount_hour, timerCount_min, timerCount_sec;
        timerCount_hour = (timerCount / 3600) % 24;
        timerCount_min = (timerCount / 60) % 60;
        timerCount_sec = timerCount % 60;
        sprintf(buff, "TIMER : %02d:%02d:%02d",
        timerCount_hour,
        timerCount_min,
        timerCount_sec
        );
        lcd->WriteStringXY(0, 0, buff);
    }
}
