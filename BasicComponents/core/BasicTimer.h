class BasicTimer {

    public:
        BasicTimer(BasicDuration const& duration);
        void init();
        bool timeIsUp();
        BasicDuration& getDuration();

    protected:
        BasicDuration _duration;
    
};