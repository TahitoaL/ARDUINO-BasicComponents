class BasicSensor {

    public:
        BasicSensor(int pin, char id, String name, int defaultValue);

        virtual void setUp();
        virtual int readValue() = 0;
        virtual boolean readState() = 0;
        virtual int getValue() = 0;
        virtual boolean getState() = 0;

        char getId() const;
        String getName() const;
        int getPin() const;
        void savePreviousData();
        boolean stateHasChanged();
        boolean stateHasRising();
        boolean stateHasFalling();


    protected:
        char _id;
        String _name;
        int _pin;
        int _value[2];
        int _state[2];
        int _defaultValue;

};

//-------------------------------------------------------------------

class DigitalSensor : public BasicSensor {

    public:
        DigitalSensor(int pin, boolean pullup, char* id, char* name);
        DigitalSensor(int pin, boolean pullup, char* id, char* name, int defaultValue);

        virtual void setUp();
        virtual int readValue();
        virtual boolean readState();
        virtual int getValue();
        virtual boolean getState();
    
    protected:
        boolean _pullup;

};

//-------------------------------------------------------------------

class AnalogSensor : public BasicSensor {

    public:
        AnalogSensor(int pin, char* id, char* name, int minValue, int maxValue, int thresholdValue, int hysteresisValue);
        AnalogSensor(int pin, char* id, char* name, int minValue, int maxValue, int thresholdValue, int hysteresisValue, int defaultValue);

        virtual void setUp();
        virtual boolean readState();
        virtual int readValue();
        virtual boolean getState();
        virtual int getValue();

    protected:
        void refreshValues();
        int _minValue;
        int _maxValue;
        int _thresholdValue;
        int _hysteresisValue;

};