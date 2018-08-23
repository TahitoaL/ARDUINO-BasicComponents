class BasicSensor {

    public:
        BasicSensor(int pin, char* id, char* name);
        BasicSensor(int pin, char* id, char* name, int defaultValue);

        void setUp();
        virtual int readValue();

        char* getId() const;
        char* getName() const;
        int getPin() const;


    protected:
        char* _id;
        char* _name;
        int _pin;
        int _value[2];

};

//-------------------------------------------------------------------

class DigitalSensor : public BasicSensor {

    public:
        DigitalSensor(int pin, char* id, char* name);
        DigitalSensor(int pin, char* id, char* name, int defaultValue);

        int readState();
    
    protected:
        int _state[2];

};

//-------------------------------------------------------------------

class AnalogSensor : public BasicSensor {

    public:
        AnalogSensor(int pin, char* id, char* name, int minValue, int maxValue, int thresholdValue, int hysteresisValue);
        AnalogSensor(int pin, char* id, char* name, int minValue, int maxValue, int thresholdValue, int hysteresisValue, int defaultValue);

        int readState();

    protected:
        int _state[2];
        int _minValue;
        int _maxValue;
        int _thresholdValue;
        int _hysteresisValue;

};