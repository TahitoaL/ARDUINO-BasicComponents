#include "Arduino.h"
#include "BasicComponents.h"

SpeedSensor::SpeedSensor(char pin, int id, string name, float wheelDiameter) : DigitalSensor(pin, id, name)
{

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

ColorSensor::ColorSensor(char pin, int id, string name) : BasicSensor(pin, id, name)
{

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