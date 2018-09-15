class BasicChronometer {

    public:
        BasicChronometer();
        void start();
        void stop();
        void init();
        BasicDuration& getDurationSinceStart();

    protected:
        BasicDuration _durationSinceStart();

};