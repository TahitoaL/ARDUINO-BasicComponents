#include "Arduino.h"
#include "./../BasicComponents.h"

BasicMotor::BasicMotor(char pin, int id, String name) : PwmReceiver(pin, id, name, 0)
{
    _speed = 0;
}

void BasicMotor::setSpeed(int speed) // form 0 to 100
{
    _speed = speed;

    setDutyCycleValue(map(_speed, 0, 100, 120, 255));
}

int BasicMotor::getSpeed()
{
    return _speed;
}