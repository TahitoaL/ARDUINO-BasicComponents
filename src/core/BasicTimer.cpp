#include "Arduino.h"
#include "./../BasicComponents.h"
#include "./BasicDuration.h"

BasicTimer::BasicTimer(int seconds, int milliseconds = 0)
{
    _milliseconds = 1000 * seconds + milliseconds;
}

BasicTimer::BasicTimer(BasicDuration const& duration)
{
    _milliseconds = duration.getDurationTime();
}

void BasicTimer::init()
{
    _timeStart = millis();
}

long BasicTimer::getTime()
{
    return (millis() - _timeStart);
}

boolean BasicTimer::timeIsUp()
{
    if (getTime()  > _milliseconds)
    {
        return true;
    }
    else
    {
        return false;
    }

}

long BasicTimer::getDurationValue()
{
    return _milliseconds;
}