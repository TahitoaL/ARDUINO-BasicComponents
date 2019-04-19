#include "Arduino.h"
#include "./../BasicComponents.h"

BasicReceiver::BasicReceiver(char pin, int id, String name)
{
    _pin = pin;
    _id = id;
    _name = name;
    _state = false;
    _blinkActivated = false;
}

void BasicReceiver::setUp()
{
    pinMode(_pin, OUTPUT);
}

const String BasicReceiver::getName()
{
    return _name;
}

const int BasicReceiver::getId()
{
    return _id;
}

const char BasicReceiver::getPin()
{
    return _pin;
}

void BasicReceiver::blink(int blinkPerMinute)
{
    int timerDuration = (60 / (2 * blinkPerMinute));
    _timer = new BasicTimer(timerDuration);
    // _timer->setValue(new BasicDuration()));
    _timer->init();
    _blinkActivated = true;
}

void BasicReceiver::blink(BasicDuration const& blinkDuration)
{
    _timer = new BasicTimer(blinkDuration.getSeconds(), blinkDuration.getMilliseconds());
    // _timer->setValue(blinkDuration);
    _timer->init();
    _blinkActivated = true;
}

void BasicReceiver::blink(BasicDuration const& onDuration, BasicDuration const& offDuration)
{}

void BasicReceiver::stopBlink()
{
    _blinkActivated = false;
    _timer = NULL;
}

void BasicReceiver::refresh()
{
    if (_blinkActivated)
    {
        if (_timer->timeIsUp())
        {
            if (_state)
            {
                switchOff();
            }
            else
            {
                switchOn();
            }
            _timer->init();
        }
    }
}

//------------------------------------------------------------------------------

DigitalReceiver::DigitalReceiver(char pin, int id, String name) : BasicReceiver (pin, id, name)
{
    
}

void DigitalReceiver::switchOn()
{
    digitalWrite(_pin, HIGH);
    _state = true;
}

boolean DigitalReceiver::getState()
{
    return _state;
}

void DigitalReceiver::switchOn(BasicDuration const& duration)
{}

void DigitalReceiver::switchOff()
{
    digitalWrite(_pin, LOW);
    _state = false;
}

//------------------------------------------------------------------------------

PwmReceiver::PwmReceiver(char pin, int id, String name, int dutyCycleValue = 100) : BasicReceiver(pin, id, name)
{
    _dutyCycleValue = dutyCycleValue;
}

void PwmReceiver::setUp() // Add verification of PWM pins
{
    pinMode(_pin, OUTPUT);
}

boolean PwmReceiver::getState()
{
    return (_dutyCycleValue > 0) ? true : false;
}

void PwmReceiver::switchOn()
{
    analogWrite(_pin, _dutyCycleValue);
}

void PwmReceiver::switchOn(BasicDuration const& duration)
{}

void PwmReceiver::switchOff()
{
    analogWrite(_pin, 0);
}

void PwmReceiver::switchOn(int dutyCycleValue)
{
    if (dutyCycleValue <= 100)
    {
        analogWrite(_pin, map(dutyCycleValue, 0, 100, 0, 255));
    }
}

void PwmReceiver::setDutyCycleValue(int dutyCycleValue)
{
    if (dutyCycleValue <= 255 && dutyCycleValue >= 0)
    {
        _dutyCycleValue = dutyCycleValue;
        switchOn();
    }
}