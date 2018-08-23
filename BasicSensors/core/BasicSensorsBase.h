class BasicSensor {

    public:
        BasicSensor(int pin, char* id, char* name, int defaultValue);

        virtual void setUp();

        char* getId() const;
        char* getName() const;
        int getPin() const;


    protected:
        char* _id;
        char* _name;
        int _pin;
        int _value[2];
        int _defaultValue;

};

//-------------------------------------------------------------------

class DigitalSensor : public BasicSensor {

    public:
        DigitalSensor(int pin, boolean pullup, char* id, char* name);
        DigitalSensor(int pin, boolean pullup, char* id, char* name, int defaultValue);

        virtual void setUp();
        boolean readState();
    
    protected:
        boolean _pullup;
        int _state[2];

};

//-------------------------------------------------------------------

class AnalogSensor : public BasicSensor {

    public:
        AnalogSensor(int pin, char* id, char* name, int minValue, int maxValue, int thresholdValue, int hysteresisValue);
        AnalogSensor(int pin, char* id, char* name, int minValue, int maxValue, int thresholdValue, int hysteresisValue, int defaultValue);

        int readValue();
        int getValue();
        int readState();
        int getState();
        void savePreviousState();

    protected:
        void refreshValues();
        int _state[2];
        int _minValue;
        int _maxValue;
        int _thresholdValue;
        int _hysteresisValue;

};