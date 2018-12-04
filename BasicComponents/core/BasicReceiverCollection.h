class BasicReceiverCollection {

    public:
        BasicReceiverCollection(int id, String name);
        static const int MAX_RECEIVERS = 50;
        const int getId();
        const String getName();
        int getSize();
        boolean addReceiver(BasicReceiver& receiver);
        BasicReceiver* getReceiver(int index);
        BasicReceiver* getReceiver(char pin);
        void removeSensor(int index);
        void removeSensor(char pin);
        void removeSensor(BasicReceiver& receiver);
        void setUp();
        void refresh();
        void switchOn();
        void switchOn(BasicDuration const& duration);
        void switchOff();
        void blink(int blinkPerMinute);
        void blink(BasicDuration const& duration);

    protected:
        BasicReceiver* _receivers[MAX_RECEIVERS];
        int _id;
        String _name;
        int _size;

};