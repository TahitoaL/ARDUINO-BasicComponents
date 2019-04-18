#include "./BasicDuration.h"
#ifndef BT_H

#define BT_H

class BasicTimer {

    public:
        BasicTimer(int seconds, int milliseconds = 0);
        BasicTimer(BasicDuration const& duration);
        void init();
        boolean timeIsUp();
        long getTime();
        long getDurationValue();

    protected:
        long _milliseconds;
        long _durationValue;
        long _timeStart;
    
};

#endif