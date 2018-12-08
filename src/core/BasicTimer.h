#ifndef BT_H

#define BT_H

class BasicTimer {

    public:
        BasicTimer(int duration); //in milliseconds
        void init();
        bool timeIsUp();
        int getDuration();

    protected:
        int _duration;
        long _timeStart;
    
};

#endif