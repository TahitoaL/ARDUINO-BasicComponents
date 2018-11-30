#include "Arduino.h"
#include "BasicComponents.h"

BasicReceiverCollection::BasicReceiverCollection(int id, string name)
{
    _id = id;
    _name = name;
    _size = 0;
}

const int BasicReceiverCollection::getId()
{
    return _id;
}

const string BasicReceiverCollection::getName()
{
    return _name;
}

int BasicReceiverCollection::getSize()
{
    return _size;
}

boolean BasicReceiverCollection::addReceiver(BasicReceiver& receiver)
{
    if (_size < MAX_RECEIVERS)
    {
        _sensors[_size] = &receiver;
        _size++;
        return true;
    }
    else
    {
        return false;
    }
}

BasicReceiver* BasicReceiverCollection::getReceiver(int index)
{
    return (index < MAX_RECEIVERS - 1) ? _receivers[index] : NULL;
}

BasicReceiver* BasicReceiverCollection::getReceiver(char pin)
{
    for (int i = 0; i < _size; i++)
    {
        if (pin == _receivers[i].pin)
            return _receivers[i]
    }
    return NULL;
}

void BasicReceiverCollection::removeSensor(int index)
{
    _receivers[index] = 0;
}

void BasicReceiverCollection::removeSensor(char pin)
{
    for (int i = 0; i < _size; i++)
    {
        if (pin == _receivers[i].pin)
            _receivers[i] = 0;
    }
}

void BasicReceiverCollection::removeSensor(BasicReceiver& receiver)
{
    for (int i = 0; i < _size; i++)
    {
        if (receiver == _receivers[i]) //May not work
            _receivers[i] = 0;
    }
}

void BasicReceiverCollection::setUp()
{
    for (int i = 0; i < _size; i++)
    {
        BasicReceiver& receiver = _receivers[i];
        receiver->setUp();
    }
}

void BasicReceiverCollection::refresh()
{
    for (int i = 0; i < _size; i++)
    {
        BasicSensor& receiver = _receivers[i];
        receiver->refresh();
    }
}

void BasicReceiverCollection::switchOn()
{
    for (int i = 0; i < _size; i++)
    {
        BasicSensor& receiver = _receivers[i];
        receiver->switchOn();
    }
}

void BasicReceiverCollection::switchOn(BasicDuration const& duration)
{}

void BasicReceiverCollection::switchOff()
{
    for (int i = 0; i < _size; i++)
    {
        BasicSensor* receiver = _receivers[i];
        receiver->switchOff();
    }
}

void BasicReceiverCollection::blink(int blinkPerMinute)
{
    for (int i = 0; i < _size; i++)
    {
        BasicSensor* receiver = _receivers[i];
        receiver->blink(blinkPerMinute);
    }
}

void BasicReceiverCollection::blink(BasicDuration const& duration)
{
    for (int i = 0; i < _size; i++)
    {
        BasicSensor* receiver = _receivers[i];
        receiver->blink(duration);
    }
}