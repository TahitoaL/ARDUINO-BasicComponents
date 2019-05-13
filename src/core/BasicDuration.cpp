#include "Arduino.h"
#include "./../BasicComponents.h"

/**
 * @brief Construct a new Basic Duration:: Basic Duration object
 * 
 */
BasicDuration::BasicDuration()
{
    _milliseconds = 0;
    _seconds = 0;
    _minutes = 0;
    _hours = 0;
}

/**
 * @brief Construct a new Basic Duration:: Basic Duration object
 * 
 * @param duration 
 */
BasicDuration::BasicDuration(const BasicDuration& duration)
{
    _milliseconds = duration._milliseconds;
    _seconds = duration._seconds;
    _minutes = duration._minutes;
    _hours = duration._hours;
}

/**
 * @brief Construct a new Basic Duration:: Basic Duration object
 * 
 * @param seconds 
 * @param milliseconds 
 */
BasicDuration::BasicDuration(int seconds, int milliseconds = 0)
{
    _seconds = seconds;
    _milliseconds = milliseconds;

    _seconds += _milliseconds / 1000;
    _milliseconds %= 1000;
    _minutes += _seconds / 60;
    _seconds %= 60;
    _hours += _minutes / 60;
    _minutes %= 60;
}

/**
 * @brief Construct a new Basic Duration:: Basic Duration object
 * 
 * @param minutes 
 * @param seconds 
 * @param milliseconds 
 */
BasicDuration::BasicDuration(int minutes, int seconds, int milliseconds)
{
    _minutes = minutes;
    _seconds = seconds;
    _milliseconds = milliseconds;

    _seconds += _milliseconds / 1000;
    _milliseconds %= 1000;
    _minutes += _seconds / 60;
    _seconds %= 60;
    _hours += _minutes / 60;
    _minutes %= 60;
}

/**
 * @brief 
 * 
 * @param duration 
 * @return BasicDuration& 
 */
BasicDuration& BasicDuration::operator+=(BasicDuration const& duration)
{
    _milliseconds += duration._milliseconds;
    _seconds += _milliseconds / 1000;
    _milliseconds %= 1000;
    
    _seconds += duration._seconds;
    _minutes += _seconds / 60;
    _seconds %= 60;

    _minutes += duration._minutes;
    _hours += _minutes / 60;
    _minutes %= 60;

    _hours += duration._hours;

    return *this;
}

/**
 * @brief 
 * 
 * @param b 
 * @return true 
 * @return false 
 */
bool BasicDuration::isEqual(BasicDuration const& b)
{
    if (_hours == b._hours && _minutes == b._minutes && _seconds == b._seconds && _milliseconds == b._milliseconds)
        return true;
    else
        return false;
}

/**
 * @brief 
 * 
 * @param b 
 * @return true 
 * @return false 
 */
bool BasicDuration::isInferiorTo(BasicDuration const& b)
{
    if (_hours < b._hours)
        return true;
    else if (_hours == b._hours && _minutes < b._minutes)
        return true;
    else if (_hours == b._hours && _minutes == b._minutes && _seconds < b._seconds)
        return true;
    else if (_hours == b._hours && _minutes == b._minutes && _seconds == b._seconds && _milliseconds < b._milliseconds)
        return true;
    else 
        return false;
}

/**
 * @brief 
 * 
 * @return int 
 */
int BasicDuration::getHours()
{
    return _hours;
}

/**
 * @brief 
 * 
 * @return int 
 */
int BasicDuration::getMinutes()
{
    return _minutes;
}

/**
 * @brief 
 * 
 * @return int 
 */
int BasicDuration::getSeconds()
{
    return _seconds;
}

/**
 * @brief 
 * 
 * @return int 
 */
int BasicDuration::getMilliseconds()
{
    return _milliseconds;
}

/**
 * @brief 
 * 
 * @return long 
 */
long BasicDuration::getDurationTime()
{
    return (((_hours * 60 + _minutes) * 60 + _seconds) * 1000 + _milliseconds);
}

/**
 * @brief 
 * 
 */
void BasicDuration::reset()
{
    _milliseconds = 0;
    _seconds = 0;
    _minutes = 0;
    _hours = 0;
}

/*---------------------*\
        OPERATORS
\*---------------------*/

/**
 * @brief 
 * 
 * @param a 
 * @param b 
 * @return BasicDuration 
 */
BasicDuration operator+(BasicDuration& a, BasicDuration& b)
{
    BasicDuration results(a);
    results += b;
    return results;
}

/**
 * @brief 
 * 
 * @param a 
 * @param b 
 * @return BasicDuration 
 */
BasicDuration operator+(BasicDuration& a, int b)
{
    BasicDuration results(a);
    BasicDuration toAdd(b);
    results += toAdd;
    return results;
}

/**
 * @brief 
 * 
 * @param a 
 * @param b 
 * @return true 
 * @return false 
 */
bool operator==(BasicDuration& a, BasicDuration& b)
{
    return a.isEqual(b);
}

/**
 * @brief 
 * 
 * @param a 
 * @param b 
 * @return true 
 * @return false 
 */
bool operator!=(BasicDuration& a, BasicDuration& b)
{
    if (a == b)
        return false;
    else
        return true;
}

/**
 * @brief 
 * 
 * @param a 
 * @param b 
 * @return true 
 * @return false 
 */
bool operator<(BasicDuration& a, BasicDuration& b)
{
    if (a.isInferiorTo(b))
        return true;
    else
        return false;
}

/**
 * @brief 
 * 
 * @param a 
 * @param b 
 * @return true 
 * @return false 
 */
bool operator>(BasicDuration& a, BasicDuration& b)
{
    if (a.isInferiorTo(b))
        return false;
    else
        return true;
}