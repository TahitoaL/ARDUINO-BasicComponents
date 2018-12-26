#include "Arduino.h"
#include "./../BasicComponents.h"
#include "./BasicDuration.h"

BasicTimer::BasicTimer()
{
    // _duration = new BasicDuration(0);
}

void BasicTimer::setValue(BasicDuration const& duration)
{
    _duration = duration;
    _durationValue = duration.getDurationTime();
}

void BasicTimer::setValue(int seconds, int milliseconds = 0)
{
    _duration = new BasicDuration(seconds, milliseconds);
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
    if (getTime()  > getDurationValue())
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
    return _durationValue;
}

BasicDuration& BasicTimer::getDuration()
{
    return _duration;
}