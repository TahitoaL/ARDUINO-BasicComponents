class SpeedSensor : public DigitalSensor {

    public:
        SpeedSensor(char pin, int id, string name, float wheelDiameter);
        int readValue(boolean save = false);
        float readRawValue(boolean save = false);
        boolean isStop();

    protected:
        _wheelDiameter;
        boolean _stop;
        BasicDuration _detectionDuration;

};