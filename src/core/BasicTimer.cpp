#include "Arduino.h"
#include "./../BasicComponents.h"
#include "./BasicDuration.h"

/**
 * @brief Construct a new Basic Timer:: Basic Timer object
 * 
 * @param seconds 
 * @param milliseconds 
 */
BasicTimer::BasicTimer(int seconds, int milliseconds = 0)
{
    _milliseconds = 1000 * seconds + milliseconds;
}

/**
 * @brief Construct a new Basic Timer:: Basic Timer object
 * 
 * @param duration 
 */
BasicTimer::BasicTimer(BasicDuration const& duration)
{
    _milliseconds = duration.getDurationTime();
}

/**
 * @brief initialize the timer
 * 
 */
void BasicTimer::init()
{
    _timeStart = millis();
}

/**
 * @brief Get the duration elapsed since the last initialization
 * 
 * @return long 
 */
long BasicTimer::getTime()
{
    return (millis() - _timeStart);
}

/**
 * @brief Check if the duration provided during the instantiation has elapsed since the last initialization
 * 
 * @return boolean 
 */
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

/**
 * @brief Get the duration provided during the instantitation
 * 
 * @return long 
 */
long BasicTimer::getDurationValue()
{
    return _milliseconds;
}