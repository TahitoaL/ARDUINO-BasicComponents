#include "Arduino.h"
#include "./../BasicComponents.h"

/**
 * @brief Construct a new Basic Receiver Collection:: Basic Receiver Collection object
 * 
 * @param id 
 * @param name 
 */
BasicReceiverCollection::BasicReceiverCollection(int id, String name)
{
    _id = id;
    _name = name;
    _size = 0;
}

const int BasicReceiverCollection::getId()
{
    return _id;
}

const String BasicReceiverCollection::getName()
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
        _receivers[_size] = &receiver;
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
        if (pin == _receivers[i]->getPin())
        {
            return _receivers[i];
        }
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
        if (pin == _receivers[i]->getPin())
            _receivers[i] = 0;
    }
}

void BasicReceiverCollection::removeSensor(BasicReceiver& receiver)
{
    for (int i = 0; i < _size; i++)
    {
        if (receiver.getId() == _receivers[i]->getId())
            _receivers[i] = 0;
    }
}

void BasicReceiverCollection::setUp()
{
    for (int i = 0; i < _size; i++)
    {
        _receivers[i]->setUp();
    }
}

void BasicReceiverCollection::refresh()
{
    for (int i = 0; i < _size; i++)
    {
        _receivers[i]->refresh();
    }
}

void BasicReceiverCollection::switchOn()
{
    for (int i = 0; i < _size; i++)
    {
        _receivers[i]->switchOn();
    }
}

void BasicReceiverCollection::switchOn(BasicDuration const& duration)
{}

void BasicReceiverCollection::switchOff()
{
    for (int i = 0; i < _size; i++)
    {
        _receivers[i]->switchOff();
    }
}

void BasicReceiverCollection::blink(int blinkPerMinute)
{
    for (int i = 0; i < _size; i++)
    {
        _receivers[i]->blink(blinkPerMinute);
    }
}

void BasicReceiverCollection::blink(BasicDuration const& duration)
{
    for (int i = 0; i < _size; i++)
    {
        _receivers[i]->blink(duration);
    }
}