#include "./BasicDuration.h"
#ifndef BT_H

#define BT_H

class BasicTimer {

    public:
        BasicTimer();
        void setValue(BasicDuration const& duration);
        void setValue(int seconds, int milliseconds = 0);
        void init();
        boolean timeIsUp();
        long getTime();
        long getDurationValue();
        BasicDuration& getDuration();

    protected:
        BasicDuration& _duration;
        long _durationValue;
        long _timeStart;
    
};

#endif