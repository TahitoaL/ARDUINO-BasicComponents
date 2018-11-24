class SpeedSensor : public DigitalSensor {

    public:
        SpeedSensor(char pin, int id, string name, float wheelDiameter);
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
        ColorSensor(char pin, int id, string name);
        int readValue(boolean save = false);
        int readColor(int color);
        boolean lineDetected();


    protected:
        int _red;
        int _green;
        int _blue;
        int _clear;

};