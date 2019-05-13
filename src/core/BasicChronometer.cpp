#include "Arduino.h"
#include "./../BasicComponents.h"

//Add feature lap

/**
 * @brief Construct a new Basic Chronometer:: Basic Chronometer object
 * 
 */
BasicChronometer::BasicChronometer()
{
    _startMillis = 0;
    _durationSinceStart = 0;
}
 /**
  * @brief start the timer
  * 
  */
void BasicChronometer::start()
{
    _startMillis = millis();
}

/**
 * @brief stop the timer
 * 
 */
void BasicChronometer::stop()
{
    _durationSinceStart = millis() - _startMillis;
}

/**
 * @brief get the time elapsed between start and stop
 * 
 * @return BasicDuration* 
 */
BasicDuration* BasicChronometer::getDurationSinceStart()
{
    return new BasicDuration(0, _durationSinceStart);
}