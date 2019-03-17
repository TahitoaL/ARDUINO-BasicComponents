#ifndef BSI_H

#include <Array.h>

#define BSI_H

class ColorSensor : public BasicSensor {

    public:
        ColorSensor(char outputPin, char s0Pin, char s1Pin, char s2Pin, char s3Pin, char ledPin, int id, String name);
        virtual void setUp();
        void switchOnLed();
        void switchOffLed();
        int readRawColor(int rgbSelector);
        int readColor(int rgbSelector);
        Array<int, 3> readRawColors();
        Array<int, 3> getRawColors();
        Array<int, 3> readColors();
        Array<int, 3> getColors();
        virtual int readValue(); //return an int that correspond to the id of the detected color
        virtual int getValue();
        virtual boolean readState(); // = lineDetected()
        virtual boolean getState();


    protected:
        char _outputPin;
        char _s3Pin;
        char _s0Pin;
        char _s1Pin;
        char _s2Pin;
        char _ledPin;
        BasicTimer* _timerBeforeReadColor;
        int _rawRed;
        int _rawGreen;
        int _rawBlue;
        Array<int, 3> _rawColors;
        Array<int, 3> _colors;
        int _colorDetected;
        boolean _lineDetected;

};

#endif