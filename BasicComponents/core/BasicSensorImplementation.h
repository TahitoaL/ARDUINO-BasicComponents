#ifndef BSI_H

#define BSI_H

class SpeedSensor : public DigitalSensor {

    public:
        SpeedSensor(char pin, int id, String name, float wheelDiameter);
        int readValue(boolean save = false);
        float readRawValue(boolean save = false);
        boolean isStop();

    protected:
        float _wheelDiameter;
        boolean _stop;
        BasicDuration _detectionDuration;

};

class ColorSensor : public BasicSensor {

    public:
        ColorSensor(char pin, int id, String name);
        int readValue(boolean save = false);
        int readColor(int color);
        boolean lineDetected();


    protected:
        int _red;
        int _green;
        int _blue;
        int _clear;

};

#endif