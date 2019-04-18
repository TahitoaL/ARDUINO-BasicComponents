#include "Arduino.h"
#include "./../BasicComponents.h"

//Add feature lap

BasicChronometer::BasicChronometer()
{
    _startMillis = 0;
    _durationSinceStart = 0;
}

void BasicChronometer::start()
{
    _startMillis = millis();
}

void BasicChronometer::stop()
{
    _durationSinceStart = millis() - _startMillis;
}

BasicDuration* BasicChronometer::getDurationSinceStart()
{
    return new BasicDuration(0, _durationSinceStart);
}