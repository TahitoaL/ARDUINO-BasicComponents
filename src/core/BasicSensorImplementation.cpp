#include "Arduino.h"
#include "./../BasicComponents.h"
#include <Array.h>

ColorSensor::ColorSensor(char outputPin, char s0Pin, char s1Pin, char s2Pin, char s3Pin, char ledPin, int id, String name) : BasicSensor(outputPin, id, name)
{
    _outputPin = outputPin;
    _s0Pin = s0Pin;
    _s1Pin = s1Pin;
    _s2Pin = s2Pin;
    _s3Pin = s3Pin;
    _ledPin = ledPin;
    _id = id;
    _name = name;
}

void ColorSensor::setUp()
{
    pinMode(_outputPin, OUTPUT);
    pinMode(_s0Pin, OUTPUT);
    pinMode(_s1Pin, OUTPUT);
    pinMode(_s2Pin, OUTPUT);
    pinMode(_s3Pin, OUTPUT);    
    pinMode(_ledPin, OUTPUT);

    digitalWrite(_s0Pin, HIGH);
    digitalWrite(_s1Pin, HIGH);

    _timerBeforeReadColor = new BasicTimer;
    _timerBeforeReadColor->setValue(new BasicDuration(0, 20));

    _lineDetected = false;

    for(int i = 0; i < 3; i++)
    {
        _colors[i] = 0;
        _rawColors[i] = 0;
    }

    _colorDetected = 0;
}

void ColorSensor::switchOnLed()
{
    digitalWrite(_ledPin, HIGH);
}

void ColorSensor::switchOffLed()
{
    digitalWrite(_ledPin, LOW);
}

int ColorSensor::readRawColor(int rgbSelector) //0 => Red ; 1 => Green, 2 => Blue
{
    switch (rgbSelector) {
        case 0:
            if (_timerBeforeReadColor->timeIsUp())
            {
                digitalWrite(_s2Pin, LOW);
                digitalWrite(_s3Pin, LOW);
                _rawRed = pulseIn(_outputPin, LOW);
                _timerBeforeReadColor->init();
            }
            else
            {
                _rawRed = -1;
            }
            return _rawRed;
            break;
        case 1:
            if (_timerBeforeReadColor->timeIsUp())
            {
                digitalWrite(_s2Pin, HIGH);
                digitalWrite(_s3Pin, HIGH);
                _rawGreen = pulseIn(_outputPin, LOW);
                _timerBeforeReadColor->init();
            }
            else
            {
                _rawGreen = -1;
            }
            return _rawGreen;
            break;
        case 2:
            if (_timerBeforeReadColor->timeIsUp())
            {
                digitalWrite(_s2Pin, LOW);
                digitalWrite(_s3Pin, HIGH);
                _rawBlue = pulseIn(_outputPin, LOW);
                _timerBeforeReadColor->init();
            }
            else
            {
                _rawBlue = -1;
            }
            return _rawBlue;
            break;
    }
}

int ColorSensor::readColor(int rgbSelector)
{}

Array<int, 3> ColorSensor::readRawColors()
{
    for (int i = 0; i < 3; i++)
    {
        _rawColors[i] = readRawColor(i);
        delay(25);
    }
    return _rawColors;
}

Array<int, 3> ColorSensor::getRawColors()
{
    return _rawColors;
}

Array<int, 3> ColorSensor::readColors()
{
    for (int i = 0; i < 3; i++)
    {
        _colors[i] = readColor(i);
        delay(25);
    }
    return _colors;
}

Array<int, 3> ColorSensor::getColors()
{
    return _colors;
}

int ColorSensor::readValue()
{
    return _colorDetected;
}

int ColorSensor::getValue()
{
    return _colorDetected;
}

boolean ColorSensor::readState()
{
    return _lineDetected;
}

boolean ColorSensor::getState()
{
    return _lineDetected;
}