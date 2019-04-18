#include "Arduino.h"
#include "Streaming.h"
#include "./../BasicComponents.h"
#include <Array.h>

Color::Color(int red, int green, int blue, String name)
{
    _colors[0] = red;
    _colors[1] = green;
    _colors[2] = blue;
    _name = name;
}

void Color::setColor(int red, int green, int blue)
{
    _colors[0] = red;
    _colors[1] = green;
    _colors[2] = blue;
}

String Color::display()
{
    return "rgb(" + String(_colors[0]) + "," + String(_colors[1]) + "," + String(_colors[2]) + ")";
}

int Color::getRed()
{
    return _colors[0];
}

int Color::getGreen()
{
    return _colors[1];
}

int Color::getBlue()
{
    return _colors[2];
}

String Color::getName()
{
    return _name;
}

int Color::compare(Color color)
{
    // return (abs(_colors[0] - color.getRed())^2) + (abs(_colors[1] - color.getGreen())^2) + (abs(_colors[2] - color.getBlue()));
    return abs(color.getRed() - _colors[0])*3 + abs(color.getGreen() - _colors[1])*3 + abs(color.getBlue() - _colors[2])*3;
}

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

    _colorGapMax = 100000;
    _colorGapHysteresis = 25000;
}

void ColorSensor::setUp()
{
    pinMode(_outputPin, INPUT);
    pinMode(_s0Pin, OUTPUT);
    pinMode(_s1Pin, OUTPUT);
    pinMode(_s2Pin, OUTPUT);
    pinMode(_s3Pin, OUTPUT);    
    pinMode(_ledPin, OUTPUT);

    digitalWrite(_s0Pin, HIGH);
    digitalWrite(_s1Pin, HIGH);

    _lineDetected = false;

    _Red_1 = 0;
    _Green_1 = 0;
    _Blue_1 = 0;
    _Red_2 = 0;
    _Green_2 = 0;
    _Blue_2 = 0;
}

void ColorSensor::switchOnLed()
{
    digitalWrite(_ledPin, HIGH);
}

void ColorSensor::switchOffLed()
{
    digitalWrite(_ledPin, LOW);
}

void ColorSensor::setReferenceColor(int red, int green, int blue)
{
    _referenceRed = red;
    _referenceGreen = green;
    _referenceBlue = blue;
}

void ColorSensor::readRawColor() //0 => Red ; 1 => Green, 2 => Blue
{
    digitalWrite(_s2Pin, LOW);
    digitalWrite(_s3Pin, LOW);
    _rawRed = pulseIn(_outputPin, LOW);
    delay(5);

    digitalWrite(_s2Pin, HIGH);
    digitalWrite(_s3Pin, HIGH);
    _rawGreen = pulseIn(_outputPin, LOW);
    delay(5);

    digitalWrite(_s2Pin, LOW);
    digitalWrite(_s3Pin, HIGH);
    _rawBlue = pulseIn(_outputPin, LOW);
}

void ColorSensor::readColor()
{
    readRawColor();

    //redressement des valeurs
    _Red = map(_rawRed, 25, 72, 255, 0);
    _Green = map(_rawGreen, 30, 90, 255, 0);
    _Blue = map(_rawBlue, 25, 70, 255, 0);

    _max = max(_Red, max(_Green, _Blue));
    _min = min(_Red, min(_Green, _Blue));
    
    if (_max - _min < 100)
    {
        _max = _max + (_max - _min) / 2;
        _min = _min - (_max - _min) / 2;
    }

    _Red_0 = map(_Red, _min, _max, 0, 255);
    _Green_0 = map(_Green, _min, _max, 0, 255);
    _Blue_0 = map(_Blue, _min, _max, 0, 255);

    _Red_1 = _Red_0;
    _Green_1 = _Green_0;
    _Blue_1 = _Blue_0;
    _Red_2 = _Red_1;
    _Green_2 = _Green_1;
    _Blue_2 = _Blue_1;

    if (_max <= 20)
    {
        _max = 20;
    }

    _averageRed = (_Red_0 + _Red_1 + _Red_2) / 3;
    _averageGreen = (_Green_0 + _Green_1 + _Green_2) / 3;
    _averageBlue = (_Blue_0 + _Blue_1 + _Blue_2) / 3;
}

// Color ColorSensor::getColor()
// {
//     return Color(_averageRed, _averageGreen, _averageBlue, "Detected Color");
// }

int ColorSensor::readValue()
{
    return readState() ? 1 : 0;
}

int ColorSensor::getValue()
{
    return _lineDetected ? 1 : 0;
}

boolean ColorSensor::readState()
{
    _colorGap = abs(_referenceRed - _averageRed)*abs(_referenceRed - _averageRed) + abs(_referenceGreen - _averageGreen)*abs(_referenceGreen - _averageGreen) + abs(_referenceBlue - _averageBlue)*abs(_referenceBlue - _averageBlue);

    if(!_lineDetected && _colorGap < (_colorGapMax - _colorGapHysteresis))
    {
        _lineDetected = true;
    }
    if(_lineDetected && _colorGap > (_colorGapMax + _colorGapHysteresis))
    {
        _lineDetected = false;
    }

    return _lineDetected;
}

boolean ColorSensor::getState()
{
    return _lineDetected;
}