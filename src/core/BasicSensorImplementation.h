#ifndef BSI_H

#include <Array.h>

#define BSI_H

class Color {
    public:
        Color(int red, int green, int blue, String name);
        void setColor(int red, int green, int blue);
        int getRed();
        int getGreen();
        int getBlue();
        String getName();
        String display();
        int compare(Color color);
    protected:
        int _colors[3];
        String _name;
};

class ColorSensor : public BasicSensor {

    public:
        ColorSensor(char outputPin, char s0Pin, char s1Pin, char s2Pin, char s3Pin, char ledPin, int id, String name);
        virtual void setUp();
        void switchOnLed();
        void switchOffLed();
        void setReferenceColor(int red, int green, int blue);
        void readRawColor();
        void readColor();
        int getRed();
        int getGreen();
        int getBlue();
        int getGap();
        virtual int readValue(); //return 0 or 1
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
        int _referenceRed;
        int _referenceGreen;
        int _referenceBlue;
        int _rawRed;
        int _rawGreen;
        int _rawBlue;
        int _Red;
        int _Green;
        int _Blue;
        int _Red_0;
        int _Green_0;
        int _Blue_0;
        int _Red_1;
        int _Green_1;
        int _Blue_1;
        int _Red_2;
        int _Green_2;
        int _Blue_2;
        int _averageRed;
        int _averageGreen;
        int _averageBlue;
        int _min;
        int _max;

        int _colorGap;
        int _colorGapMax;
        int _colorGapHysteresis;

        boolean _lineDetected;
};

class DistanceSensor : public BasicSensor {

    public:
        DistanceSensor(int echoPin, int triggerPin, char id);

        virtual void setUp();
        virtual int readValue();
        virtual boolean readState();
        virtual int getValue();
        virtual boolean getState();
    
    protected:
        int _echoPin;
        int _triggerPin;
        int _distance;

        static const unsigned long MEASURE_TIMEOUT = 25000UL;
        static const float SOUND_SPEED = 340.0;

};

#endif