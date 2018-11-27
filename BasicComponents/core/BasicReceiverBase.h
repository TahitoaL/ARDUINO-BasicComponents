const int[6] PWM_PINS = [3, 5, 6, 9, 10, 11];

class BasicReceiver {

    public:
        BasicReceiver(char pin, int id, string name);
        virtual void setUp();
        virtual void switchOn() = 0;
        virtual void switchOn(BasicDuration const& duration) = 0;
        virtual void switchOff() = 0;
        virtual boolean getState() = 0;
        void blink(int blinkPerMinute);
        void blink(BasicDuration const& blinkDuration);
        void blink(BasicDuration const& onDuration, BasicDuration const& offDuration);
        void stopBlink();
        void refresh();

    protected:
        int _id;
        string _name;
        char _pin;
        boolean _state;
        boolean _blinkActivated;
        BasicTimer* _timer; //May not work

};

//-------------------------------------------------------------------

class DigitalReceiver : public BasicReceiver {

    public:
        DigitalReceiver(char pin, int id, string name);
        virtual void switchOn();
        virtual void switchOn(BasicDuration const& duration);
        virtual void switchOff();  

};

//-------------------------------------------------------------------

class PwmReceiver : public BasicReceiver {
    
    public:
        PwmReceiver(char pin, int id, string name, int dutyCycleValue = 100);
        virtual void setUp();
        virtual boolean getState();
        virtual void switchOn();
        virtual void switchOn(BasicDuration const& duration);
        virtual void switchOff();
        void switchOn(int dutyCycleValue, boolean save = true);
        void setDutyCycleValue(int dutyCycleValue);

    protected:
        int _dutyCycleValue; //percentage

};