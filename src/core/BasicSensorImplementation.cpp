#include "Arduino.h"
#include "./../BasicComponents.h"

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