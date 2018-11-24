class BasicChronometer {

    public:
        BasicChronometer();
        void start();
        void stop();
        void init();
        BasicDuration& getDurationSinceStart();

    protected:
        long _durationSinceStart;
        long _startMillis;

};