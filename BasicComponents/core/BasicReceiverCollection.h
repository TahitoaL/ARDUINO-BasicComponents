class BasicReceiverCollection {

    public:
        BasicReceiverCollection(int id, string name);
        static const int MAX_RECEIVERS;
        const int getId();
        const string getName();
        int getSize();
        void addReceiver(BasicReceiver& receiver);
        BasicReceiver* getReceiver(int index);
        BasicReceiver* getReceiver(char pin);
        void removeSensor(int index);
        void removeSensor(char pin);
        void removeSensor(BasicReceiver& receiver);
        void refresh();
        void switchOn();
        void switchOn(BasicDuration const& duration);
        void switchOff();
        void blink(int blinkPerMinute);
        void blink(BasicDuration const& duration);

    protected:
        int _id;
        string _name;
        int _size;

};