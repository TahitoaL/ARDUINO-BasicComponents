#include "Arduino.h"
#include "./../BasicComponents.h"
#include "Streaming.h"

BasicMotor::BasicMotor(char pin, int id, String name, int minPwm = 0, int mawPwm = 255) : PwmReceiver(pin, id, name, 0)
{
    _speed = 0;
    _minPwm = minPwm;
    _maxPwm = maxPwm;
}

void BasicMotor::setSpeed(int speed) // form 0 to 100
{
    _speed = speed;
    Serial << _name << " : " << _dutyCycleValue << endl;
    setDutyCycleValue(map(_speed, 0, 100, _minPwm, _maxPwm));
}

int BasicMotor::getSpeed()
{
    return _speed;
}