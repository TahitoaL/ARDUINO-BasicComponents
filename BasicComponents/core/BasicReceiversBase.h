class BasicReceiver {

    public:
        BasicReceiver(char pin, int id, string name);
        void setUp();
        virtual void switchOn() = 0;
        virtual void switchOn(Duration const& duration) = 0;
        virtual void switchOff() = 0;
        void blink(int blinkPerMinute);
        void blink(Duration const& blinkDuration);
        void blink(Duration const& onDuration, Duration const& offDuration);
        void refresh();

    protected:
        int _id;
        string _name;
        char _pin;

}

//-------------------------------------------------------------------

class DigitalReceiver : public BasicReceiver {

    public:
        DigitalReceiver(char pin, int id, string name);
        virtual void switchOn();
        virtual void switchOn(Duration const& duration);
        virtual void switchOff();

    protected:
        boolean _state;    

}

//-------------------------------------------------------------------

class PwmReceiver : public BasicReceiver {
    
    public:
        PwmReceiver(char pin, int id, string name, int dutyCycleValue = 100);
        virtual void switchOn();
        virtual void switchOn(Duration const& duration);
        virtual void switchOff();
        void switchOn(int dutyCycleValue, boolean save = true);
        void setDutyCycleValue(int dutyCycleValue);

    protected:
        int _dutyCycleValue; //percentage
        
}