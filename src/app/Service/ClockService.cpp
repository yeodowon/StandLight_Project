#include "ClockService.h"
#include <iostream>

using namespace std;

ClockService::ClockService(ClockView *view)
{
    curTime = 0;
    this->clockView = view;
    this->timerState = TIMER_STOP;
    this->clockState = CLOCK;
}

ClockService::~ClockService()
{
}

void ClockService::updateEvent()
{
    curTime = time(NULL);
    struct tm *timeDate = localtime(&curTime);
    clockView->updateTime(timeDate);
}

void ClockService::updateClockState(std::string strState)
{
    switch (clockState)
    {
    case CLOCK:
        if (strState == "timerButton")
        {
            cout << "clock service, timerButton" << endl;
            clockState = TIMER;
            clockView->setClockState(clockState);
        }
        break;

    case TIMER:
        if (strState == "timerButton")
        {
            clockState = CLOCK;
            clockView->setClockState(clockState);
        }
        break;
    }
}

void ClockService::updateTimerState(std::string strState)
{
    if (clockState == TIMER)
    {
        switch (timerState)
        {
        case TIMER_STOP:
            if (strState == "timerButton")
            {
                clockState = CLOCK;
                clockView->setClockState(clockState);
            }
            if (strState == "runstopButton")
            {
                timerState = TIMER_START;
            }
            else if (strState == "resetButton")
            {
                timerState = TIMER_RESET;
            }
            clockView->setTimerState(timerState);
            break;

        case TIMER_START:
            if (strState == "timerButton")
            {
                clockState = CLOCK;
                clockView->setClockState(clockState);
            }
            if (strState == "runstopButton")
            {
                timerState = TIMER_TEMPSTOP;
            }
            clockView->setTimerState(timerState);
            break;

        case TIMER_TEMPSTOP:
            if (strState == "timerButton")
            {
                clockState = CLOCK;
                clockView->setClockState(clockState);
            }
            if (strState == "runstopButton")
            {
                timerState = TIMER_RESTART;
            }
            else if (strState == "resetButton")
            {
                timerState = TIMER_RESET;
            }
            clockView->setTimerState(timerState);
            break;

        case TIMER_RESTART:
            if (strState == "timerButton")
            {
                clockState = CLOCK;
                clockView->setClockState(clockState);
            }
            if (strState == "runstopButton")
            {
                timerState = TIMER_TEMPSTOP;
            }
            clockView->setTimerState(timerState);
            break;

        case TIMER_RESET:
            if (strState == "timerButton")
            {
                clockState = CLOCK;
                timerState = TIMER_STOP;
                clockView->setClockState(clockState);
            }
            if (strState == "runstopButton")
            {
                timerState = TIMER_START;
            }
            clockView->setTimerState(timerState);
            break;
        }
    }
}