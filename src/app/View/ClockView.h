#ifndef __CLOCKVIEW_H__
#define __CLOCKVIEW_H__

#include <time.h>
#include "LCD.h"
#include "Timer.h"
#include "ClockState.h"

class ClockView
{
private:
    int clockState;
    int timerState;
    unsigned int timerCount;
    unsigned int Temp_timerCount;

    struct tm timeDate;
    LCD *lcd;

public:
    ClockView(LCD *lcd);
    virtual ~ClockView();
    void updateTime(struct tm *timeData);
    void setClockState(int clockstate);
    void setTimerState(int timerstate);
    void updateTimerCount();
    void TimerView();
};

#endif /* __CLOCKVIEW_H__ */