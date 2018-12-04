#include "Arduino.h"
#include "./../BasicComponents.h"

SpeedSensor::SpeedSensor(char pin, int id, String name, float wheelDiameter) : DigitalSensor(pin, id, name) {
    _pin = pin;
    _id = id;
    _name = name;
}

int SpeedSensor::readValue(boolean save = false)
{

}

float SpeedSensor::readRawValue(boolean save = false)
{

}

boolean SpeedSensor::isStop()
{
    
}

//-------------------------------------------------------------------

ColorSensor::ColorSensor(char pin, int id, String name) : BasicSensor(pin, id, name)
{
    _pin = pin;
    _id = id;
    _name = name;
}

int ColorSensor::readValue(boolean save = false)
{

}

int ColorSensor::readColor(int color)
{

}

boolean ColorSensor::lineDetected()
{

}