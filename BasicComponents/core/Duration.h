class Duration {

    public:
        Duration(int hours = 0, int minutes = 0, int seconds = 0, int milliseconds = 0);
        Duration& operator+=(Duration const& duration);
        bool isEqual(Duration const& b);
        bool isInferiorTo(Duration const& b);
        int getHours();
        int getMinutes();
        int getSeconds();
        int getMilliseconds();
        int getDurationTime(); //in milliseconds
        static const int MAX_HOURS = 24;

    protected:
        int _hours;
        int _minutes;
        int _seconds;
        int _milliseconds;

}