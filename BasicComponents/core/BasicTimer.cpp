#include "Arduino.h"
#include "BasicComponents.h"

BasicTimer::BasicTimer(BasicDuration const& duration)
{
    _duration = duration;
}

void BasicTimer::init()
{
    _timeStart = millis();
}

bool BasicTimer::timeIsUp()
{
    if ((millis() - _timeStart) >= _duration.getDurationTime())
    {
        return true;
    }
    else
    {
        return false;
    }
}

BasicDuration& BasicTimer::getDuration()
{
    return _duration;