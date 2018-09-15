class BasicTimer {

    public:
        Timer(Duration const& duration);
        void init();
        bool timeIsUp();
        Duration& getDuration();

    protected:
        Duration _duration;
    
};