#include "Arduino.h"
#include "./../BasicComponents.h"
#include "Streaming.h"

/**
 * @brief Construct a new Basic Motor:: Basic Motor object. Use to control a motor
 * 
 * @param pin 
 * @param id 
 * @param name 
 * @param minPwm 
 * @param maxPwm 
 */
BasicMotor::BasicMotor(char pin, int id, String name, int minPwm = 0, int maxPwm = 255) : PwmReceiver(pin, id, name, 0)
{
    _speed = 0;
    _minPwm = minPwm;
    _maxPwm = maxPwm;
}

/**
 * @brief set the power of the motor from a 0 to 100 scale.
 * 
 * @param speed 
 */
void BasicMotor::setSpeed(int speed) // from 0 to 100
{
    _speed = speed;
    if (speed == 0) //Stop Motor
    {
        setDutyCycleValue(0);
    }
    else
    {
        setDutyCycleValue(map(_speed, 0, 100, _minPwm, _maxPwm));
    }
    
}

/**
 * @brief get the last provided speed value
 * 
 * @return int 
 */
int BasicMotor::getSpeed()
{
    return _speed;
}