#include "Arduino.h"
#include "./../BasicComponents.h"

/**
 * @brief Construct a new Basic Sensor:: Basic Sensor object
 * 
 * @param pin 
 * @param id 
 * @param name 
 * @param defaultValue 
 */
BasicSensor::BasicSensor(int pin, char id, String name, int defaultValue)
{
    _pin = pin;
    _id = id;
    _name = name;
    _value[0] = defaultValue; //current value
    _value[1] = 0; //last value
    _state[0] = false;
    _state[1] = false;
}

/**
 * @brief Construct a new Basic Sensor:: Basic Sensor object
 * 
 * @param pin 
 * @param id 
 * @param name 
 */
BasicSensor::BasicSensor(int pin, char id, String name)
{
    _pin = pin;
    _id = id;
    _name = name;
    _value[0] = 0; //current value
    _value[1] = 0; //last value
    _state[0] = false;
    _state[1] = false;
}

/**
 * @brief set up the pin in the Arduino script
 * 
 */
void BasicSensor::setUp()
{
    pinMode(_pin, INPUT);
}

/**
 * @brief return the id of the component
 * 
 * @return char 
 */
char BasicSensor::getId() const
{
    return _id;
}

/**
 * @brief get the name of the component
 * 
 * @return String 
 */
String BasicSensor::getName() const
{
    return _name;
}

/**
 * @brief get the pin of the component
 * 
 * @return int 
 */
int BasicSensor::getPin() const
{
    return _pin;
}

/**
 * @brief must be executed at each loop to make output blink. Save the previous state of the input.
 * 
 */
void BasicSensor::savePreviousData()
{
    _state[1] = _state[0];
    _value[1] = _value[0];
    _state[0] = readState();
    _value[0] = readValue();
}

/**
 * @brief check whether the state of the input has changed
 * 
 * @return boolean 
 */
boolean BasicSensor::stateHasChanged()
{
    return (_state[1] == _state[0]) ? false : true;
}

/**
 * @brief check whether the state of the input has rising
 * 
 * @return boolean 
 */
boolean BasicSensor::stateHasRising()
{
    return (_state[0] > _state[1]) ? true : false;
}

/**
 * @brief check whether the state of the input has falling
 * 
 * @return boolean 
 */
boolean BasicSensor::stateHasFalling()
{
    return (_state[0] < _state[1]) ? true : false;
}

//-------------------------------------------------------------------

/**
 * @brief Construct a new Digital Sensor:: Digital Sensor object. Use to control binary sensor.
 * 
 * @param pin 
 * @param pullup 
 * @param id 
 * @param name 
 * @param defaultValue 
 */
DigitalSensor::DigitalSensor(int pin, boolean pullup, char id, String name, int defaultValue) : BasicSensor(pin, id, name, defaultValue)
{
    _pullup = pullup;
}

/**
 * @brief Construct a new Digital Sensor:: Digital Sensor object
 * 
 * @param pin 
 * @param pullup 
 * @param id 
 * @param name 
 */
DigitalSensor::DigitalSensor(int pin, boolean pullup, char id, String name) : BasicSensor(pin, id, name)
{
    _pullup = pullup;
}

/**
 * @brief set up the pin in the Arduino script.
 * 
 */
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

/**
 * @brief read the state of the binary input
 * 
 * @return boolean 
 */
boolean DigitalSensor::readState()
{
    if (!_pullup)
    {
        return (digitalRead(_pin) == HIGH) ? true : false;   
    }
    else
    {
        return (digitalRead(_pin) == LOW) ? true : false;
    }
}

/**
 * @brief read the state of the binary input
 * 
 * @return int 
 */
int DigitalSensor::readValue()
{
    if (!_pullup)
    {
        return (digitalRead(_pin) == HIGH) ? 1 : 0;
    }
    else
    {
        return (digitalRead(_pin) == LOW) ? 1 : 0;
    }
}

/**
 * @brief return the last saved state of the input (WITHOUT reading it)
 * 
 * @return boolean 
 */
boolean DigitalSensor::getState()
{
    return _state[0];
}

/**
 * @brief return the last value of the input (WITHOUT reading it)
 * 
 * @return int 
 */
int DigitalSensor::getValue()
{
    return _value[0];
}

//-------------------------------------------------------------------

/**
 * @brief Construct a new Analog Sensor:: Analog Sensor object. Use to control an analog input.
 * 
 * @param pin 
 * @param id 
 * @param name 
 * @param minValue 
 * @param maxValue 
 * @param thresholdValue 
 * @param hysteresisValue 
 * @param defaultValue 
 */
AnalogSensor::AnalogSensor(int pin, char id, String name, int minValue, int maxValue, int thresholdValue, int hysteresisValue, int defaultValue) : BasicSensor(pin, id, name, defaultValue)
{
    _minValue = minValue;
    _maxValue = maxValue;
    _thresholdValue = thresholdValue;
    _hysteresisValue = hysteresisValue;
    _state[0] = 0;
    _state[1] = 0;
}

/**
 * @brief Construct a new Analog Sensor:: Analog Sensor object
 * 
 * @param pin 
 * @param id 
 * @param name 
 * @param minValue 
 * @param maxValue 
 * @param thresholdValue 
 * @param hysteresisValue 
 */
AnalogSensor::AnalogSensor(int pin, char id, String name, int minValue, int maxValue, int thresholdValue, int hysteresisValue) : BasicSensor(pin, id, name)
{
    _minValue = minValue;
    _maxValue = maxValue;
    _thresholdValue = thresholdValue;
    _hysteresisValue = hysteresisValue;
    _state[0] = 0;
    _state[1] = 0;
}

/**
 * Virtual function
 * @brief 
 * 
 */
void AnalogSensor::setUp()
{
      
}

/**
 * @brief read the state of the binary input (using the hysteresis)
 * 
 * @return boolean 
 */
boolean AnalogSensor::readState()
{
    _value[0] = analogRead(_pin);
    if (_value[0] <= (_thresholdValue - _hysteresisValue) && _state[0] != 0)
    {
        _state[0] = 0;
    }
    else if (_value[0] > (_thresholdValue + _hysteresisValue) && _state[0] != 1)
    {
        _state[0] = 1;
    }
    return _state[0];
}

/**
 * @brief return a 0 to 1024 scaled value
 * 
 * @return int 
 */
int AnalogSensor::readValue()
{
    return analogRead(_pin);
}

/**
 * @brief return the last state of the input (WITHOUT reading it)
 * 
 * @return boolean 
 */
boolean AnalogSensor::getState()
{
    return _state[0];
}

/**
 * @brief return the last value of the input (WITHOUT reading it)
 * 
 * @return int 
 */
int AnalogSensor::getValue()
{
    return _value[0];
}