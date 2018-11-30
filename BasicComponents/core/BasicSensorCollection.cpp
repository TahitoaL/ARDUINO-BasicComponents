#include "Arduino.h"
#include "BasicComponents.h"

BasicSensorCollection::BasicSensorCollection(int id, string name)
{
    _id = id;
    _name = name;
    _size = 0;
}

const int BasicSensorCollection::getId()
{
    return _id;
}

const string BasicSensorCollection::getName()
{
    return _name;
}

int BasicSensorCollection::getSize()
{
    return _size;
}

boolean BasicSensorCollection::addSensor(BasicSensor& sensor)
{
    if (_size < MAX_SENSORS)
    {
        _sensors[_size] = &sensor;
        _size++;
        return true;
    }
    else
    {
        return false;
    }
}

BasicSensor* BasicSensorCollection::getSensor(int index)
{
    return (index < MAX_SENSORS - 1) ? _sensors[index] : NULL;
}

BasicSensor* BasicSensorCollection::getSensor(char pin)
{
    for (int i = 0; i < _size; i++)
    {
        if (pin == _sensors[i].pin)
            return _sensors[i]
    }
    return NULL;
}

void BasicSensorCollection::removeSensor(int index)
{
    _sensors[index] = 0;
}

void BasicSensorCollection::removeSensor(char pin)
{
    for (int i = 0; i < _size; i++)
    {
        if (pin == _sensors[i].pin)
            _sensors[i] = 0;
    }
}

void BasicSensorCollection::removeSensor(BasicSensor& sensor)
{
    for (int i = 0; i < _size; i++)
    {
        if (sensor == _sensors[i]) //May not work
            _sensors[i] = 0;
    }
}

void BasicSensorCollection::setUp()
{
    for (int i = 0; i < _size; i++)
    {
        BasicSensor& sensor = _sensors[i];
        sensor->setUp();
    }
}

void BasicSensorCollection::savePreviousData()
{
    for (int i = 0; i < _size; i++)
    {
        BasicSensor& sesor = _sensors[i];
        sensor->savePreviousData();
    }
}