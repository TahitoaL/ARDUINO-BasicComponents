class BasicSensorCollection {

    public:
        BasicSensorCollection(int id, string name);
        static const int MAX_SENSORS = 50; 
        const int getId();
        const string getName();
        int getSize();
        boolean addSensor(BasicSensor& sensor);
        BasicSensor* getSensor(int index);
        BasicSensor* getSensor(char pin);
        void removeSensor(int index);
        void removeSensor(char pin);
        void removeSensor(BasicSensor& sensor);
        void setUp();
        void savePreviousData();

    protected:
        int _id;
        int _size;
        string _name;

};