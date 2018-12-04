class BasicSensorCollection {

    public:
        BasicSensorCollection(int id, String name);
        static const int MAX_SENSORS = 50; 
        const int getId();
        const String getName();
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
        BasicSensor* _sensors[MAX_SENSORS];
        int _id;
        int _size;
        String _name;

};