#include "Arduino.h"
#include "BasicReceiverCollection.h"

BasicReceiverCollection::BasicReceiverCollection(int id, string name)
{
    
}

const int BasicReceiverCollection::getId()
{

}

const string BasicReceiverCollection::getName()
{

}

int BasicReceiverCollection::getSize()
{

}

void BasicReceiverCollection::addReceiver(BasicReceiver& receiver)
{

}

BasicReceiver* BasicReceiverCollection::getReceiver(int index)
{

}

BasicReceiver* BasicReceiverCollection::getReceiver(char pin)
{
    
}

void BasicReceiverCollection::removeSensor(int index)
{

}

void BasicReceiverCollection::removeSensor(char pin)
{
    
}

void BasicReceiverCollection::removeSensor(BasicReceiver& receiver)
{
    
}

void BasicReceiverCollection::refresh()
{

}

void BasicReceiverCollection::switchOn()
{

}

void BasicReceiverCollection::switchOn(BasicDuration const& duration)
{

}

void BasicReceiverCollection::switchOff()
{

}

void BasicReceiverCollection::blink(int blinkPerMinute)
{

}

void BasicReceiverCollection::blink(BasicDuration const& duration)
{
    
}