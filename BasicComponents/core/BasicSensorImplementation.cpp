#include "Arduino.h"
#include "BasicSensorImplementation.h"

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