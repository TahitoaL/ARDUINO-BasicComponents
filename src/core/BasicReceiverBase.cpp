#include "Arduino.h"
#include "./../BasicComponents.h"

/**
 * @brief Construct a new Basic Receiver:: Basic Receiver object
 * 
 * @param pin 
 * @param id 
 * @param name 
 */
BasicReceiver::BasicReceiver(char pin, int id, String name)
{
    _pin = pin;
    _id = id;
    _name = name;
    _state = false;
    _blinkActivated = false;
}

/**
 * @brief Set up the pin in the Arduino script
 * 
 */
void BasicReceiver::setUp()
{
    pinMode(_pin, OUTPUT);
}

/**
 * @brief get the name of the component
 * 
 * @return const String name 
 */
const String BasicReceiver::getName()
{
    return _name;
}

/**
 * @brief get the id of the component
 * 
 * @return const int 
 */
const int BasicReceiver::getId()
{
    return _id;
}

/**
 * @brief get the pin of the component
 * 
 * @return const char 
 */
const char BasicReceiver::getPin()
{
    return _pin;
}

/**
 * @brief blink the output
 * 
 * @param blinkPerMinute 
 */
void BasicReceiver::blink(int blinkPerMinute)
{
    int timerDuration = (60 / (2 * blinkPerMinute));
    _timer = new BasicTimer(timerDuration);
    // _timer->setValue(new BasicDuration()));
    _timer->init();
    _blinkActivated = true;
}

/**
 * @brief blink the output
 * 
 * @param blinkDuration 
 */
void BasicReceiver::blink(BasicDuration const& blinkDuration)
{
    _timer = new BasicTimer(blinkDuration.getSeconds(), blinkDuration.getMilliseconds());
    // _timer->setValue(blinkDuration);
    _timer->init();
    _blinkActivated = true;
}

/** [WIP]
 * @brief 
 * 
 * @param onDuration 
 * @param offDuration 
 */
void BasicReceiver::blink(BasicDuration const& onDuration, BasicDuration const& offDuration)
{}

/**
 * @brief stop blink
 * 
 */
void BasicReceiver::stopBlink()
{
    _blinkActivated = false;
    _timer = NULL;
}

/**
 * @brief must be executed at each loop to make output blink
 * 
 */
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

/**
 * @brief Construct a new Digital Receiver:: Digital Receiver object. Use to control binary output for digital component
 * 
 * @param pin 
 * @param id 
 * @param name 
 */
DigitalReceiver::DigitalReceiver(char pin, int id, String name) : BasicReceiver (pin, id, name)
{
    
}

/**
 * @brief switch on the digital component
 * 
 */
void DigitalReceiver::switchOn()
{
    digitalWrite(_pin, HIGH);
    _state = true;
}

/**
 * @brief get the state of the output
 * 
 * @return boolean 
 */
boolean DigitalReceiver::getState()
{
    return _state;
}

/** [WIP]
 * @brief switch on the component for a set time
 * 
 * @param duration 
 */
void DigitalReceiver::switchOn(BasicDuration const& duration)
{}

/**
 * @brief switch off the output
 * 
 */
void DigitalReceiver::switchOff()
{
    digitalWrite(_pin, LOW);
    _state = false;
}

//------------------------------------------------------------------------------

/**
 * @brief Construct a new Pwm Receiver:: Pwm Receiver object. Use to control pwm output for analog component.
 * 
 * @param pin 
 * @param id 
 * @param name 
 * @param dutyCycleValue 
 */
PwmReceiver::PwmReceiver(char pin, int id, String name, int dutyCycleValue = 100) : BasicReceiver(pin, id, name)
{
    _dutyCycleValue = dutyCycleValue;
}

/** 
 * Virtual function
 * @brief set up the pin in the Arduino script
 * 
 */
void PwmReceiver::setUp() // Add verification of PWM pins
{
    pinMode(_pin, OUTPUT);
}

/**
 * Virtual function
 * @brief get the state of the component
 * 
 * @return boolean 
 */
boolean PwmReceiver::getState()
{
    return (_dutyCycleValue > 0) ? true : false;
}

/**
 * @brief switch on the component with the last provided output
 * 
 */
void PwmReceiver::switchOn()
{
    analogWrite(_pin, _dutyCycleValue);
}

/** [WIP]
 * @brief switch on the component with the last provided output for a set time
 * 
 * @param duration 
 */
void PwmReceiver::switchOn(BasicDuration const& duration)
{}

/**
 * @brief switch off the component
 * 
 */
void PwmReceiver::switchOff()
{
    analogWrite(_pin, 0);
}

/**
 * @brief switch on the component with a provided duty cycle
 * 
 * @param dutyCycleValue 
 */
void PwmReceiver::switchOn(int dutyCycleValue)
{
    if (dutyCycleValue <= 100)
    {
        analogWrite(_pin, map(dutyCycleValue, 0, 100, 0, 255));
    }
}

/**
 * @brief change the value of the duty cycle
 * 
 * @param dutyCycleValue 
 */
void PwmReceiver::setDutyCycleValue(int dutyCycleValue)
{
    if (dutyCycleValue <= 255 && dutyCycleValue >= 0)
    {
        _dutyCycleValue = dutyCycleValue;
        switchOn();
    }
}