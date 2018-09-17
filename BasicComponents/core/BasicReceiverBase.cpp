#include "Arduino.h"
#include "BasicReceiverBase.h"

BasicReceiver::BasicReceiver(char pin, int id, string name)
{

}

void BasicReceiver::setUp()
{

}

void BasicReceiver::blink(int blinkPerMinute)
{

}

void BasicReceiver::blink(BasicDuration const& blinkDuration)
{

}

void BasicReceiver::blink(BasicDuration const& onDuration, BasicDuration const& offDuration)
{

}

void BasicReceiver::refresh()
{

}

//------------------------------------------------------------------------------

DigitalReceiver::DigitalReceiver(char pin, int id, string name) : BasicReceiver (pin, id, name)
{

}

void BasicReceiver::switchOn()
{

}

void BasicReceiver::switchOn(BasicDuration const& duration)
{

}

void BasicReceiver::switchOff()
{

}

//------------------------------------------------------------------------------

PwmReceiver::PwmReceiver(char pin, int id, string name, int dutyCycleValue = 100) : BasicReceiver(pin, id, name)
{

}

void PwmReceiver::switchOn()
{

}

void PwmReceiver::switchOn(BasicDuration const& duration)
{

}

void PwmReceiver::switchOff()
{

}

void PwmReceiver::switchOn(int dutyCycleValue)
{

}

void setDutyCycleValue(int dutyCycleValue)
{
    
}