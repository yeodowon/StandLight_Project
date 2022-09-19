#ifndef __CLOCKSERVICE_H__
#define __CLOCKSERVICE_H__

#include <time.h>
#include <string>
#include "Timer.h"
#include "ClockState.h"
#include "ClockView.h"

class ClockService
{
private:
    time_t curTime;
    int clockState;
    int timerState; 
    ClockView *clockView;

public:
    ClockService(ClockView *view);
    virtual ~ClockService();
    
    void updateEvent();
    void updateClockState(std::string strState);
    void updateTimerState(std::string strState);
};

#endif /* __CLOCKSERVICE_H__ */