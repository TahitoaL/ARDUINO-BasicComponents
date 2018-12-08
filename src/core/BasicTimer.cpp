#include "Arduino.h"
#include "./../BasicComponents.h"

BasicTimer::BasicTimer(int duration)
{
    _duration = duration;
}

void BasicTimer::init()
{
    _timeStart = millis();
}

bool BasicTimer::timeIsUp()
{
    if ((millis() - _timeStart) >= duration)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int BasicTimer::getDuration()
{
    return _duration;