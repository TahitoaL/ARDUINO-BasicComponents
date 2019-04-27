#include "Arduino.h"
#include "./../BasicComponents.h"
#include "Streaming.h"

BasicMotor::BasicMotor(char pin, int id, String name, int minPwm = 0, int maxPwm = 255) : PwmReceiver(pin, id, name, 0)
{
    _speed = 0;
    _minPwm = minPwm;
    _maxPwm = maxPwm;
}

void BasicMotor::setSpeed(int speed) // from 0 to 100
{
    _speed = speed;
    if (speed == 0) //Stop Motor
    {
        Serial << _name << " : " << 0 << endl;
        setDutyCycleValue(0);
    }
    else
    {
        Serial << _name << " : " << _dutyCycleValue << endl;
        setDutyCycleValue(map(_speed, 0, 100, _minPwm, _maxPwm));
    }
    
}

int BasicMotor::getSpeed()
{
    return _speed;
}