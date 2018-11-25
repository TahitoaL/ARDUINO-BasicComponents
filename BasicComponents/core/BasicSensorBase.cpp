#include "Arduino.h"
#include "BasicComponents.h"

BasicSensor::BasicSensor(int pin, char* id, char* name, int defaultValue = 0)
{
    _pin = pin;
    _id = id;
    _name = name;
    _value[0] = defaultValue; //current value
    _value[1] = 0; //last value
    _state[0] = 0;
    _state[1] = 0;
}

void BasicSensor::setUp()
{
    pinMode(_pin, INPUT);
}

char* BasicSensor::getId() const
{
    return _id;
}

char* BasicSensor::getName() const
{
    return _name;
}

int BasicSensor::getPin() const
{
    return _pin;
}

void BasicSensor::savePreviousData()
{
    _state[1] = _state[0];
    _value[1] = _value[0];
    _state[0] = readState();
    _value[0] = readValue();
}

boolean BasicSensor::stateHasChanged()
{
    return (_state[1] == _state[0]) ? false : true;
}

boolean BasicSensor::stateHasRising()
{
    return (_state[0] > _state[1]) ? true : false;
}

boolean BasicSensor::stateHasFalling()
{
    return (_state[0] < _state[1]) ? true : false;
}

//-------------------------------------------------------------------

DigitalSensor::DigitalSensor(int pin, boolean pullup, char* id, char* name, int defaultValue) : BasicSensor(pin, id, name, defaultValue)
{
    _pullup = pullup;
}

DigitalSensor::DigitalSensor(int pin, boolean pullup, char* id, char* name) : BasicSensor(pin, id, name, 0)
{
    _pullup = pullup;
}

void DigitalSensor::setUp()
{
    if (_pullup)
    {
        pinMode(_pin, INPUT_PULLUP);
    }
    else
    {
        pinMode(_pin, INPUT);
    }
}

boolean DigitalSensor::readState()
{
    return (digitalRead(_pin) == HIGH) ? true : false;
}

int DigitalSensor::readValue()
{
    return (digitalRead(_pin) == HIGH) ? 1 : 0;
}

boolean DigitalSensor::getState()
{
    return _state[0];
}

int DigitalSensor::getValue()
{
    return _value[0];
}

//-------------------------------------------------------------------

AnalogSensor::AnalogSensor(int pin, char* id, char* name, int minValue, int maxValue, int thresholdValue, int hysteresisValue, int defaultValue) : BasicSensor(pin, id, name, defaultValue)
{
    _minValue = minValue;
    _maxValue = maxValue;
    _thresholdValue = thresholdValue;
    _hysteresisValue = hysteresisValue;
    _state[0] = 0;
    _state[1] = 0;
}

AnalogSensor::AnalogSensor(int pin, char* id, char* name, int minValue, int maxValue, int thresholdValue, int hysteresisValue) : BasicSensor(pin, id, name, 0)
{
    _minValue = minValue;
    _maxValue = maxValue;
    _thresholdValue = thresholdValue;
    _hysteresisValue = hysteresisValue;
    _state[0] = 0;
    _state[1] = 0;
}

void AnalogSensor::refreshValues()
{
    _value[1] = _value[0];
    _value[0] = readValue();
}

int AnalogSensor::readValue()
{
    return analogRead(_pin);
}

int AnalogSensor::getValue()
{
    return _value[0];
}

int AnalogSensor::readState()
{
    refreshValues();
    if (_value[0] <= _thresholdValue && _state[0] != 0)
    {
        _state[0] = 0;
    }
    else if (_value[0] > (_thresholdValue + _hysteresisValue) && _state[0] != 1)
    {
        _state[0] = 1;
    }
    return _state[0];
}

int AnalogSensor::getState()
{
    return _state[0];
}