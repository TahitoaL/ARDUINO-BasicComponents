#ifndef BD_H

#define BD_H

class BasicDuration {

    public:
        BasicDuration(int hours = 0, int minutes = 0, int seconds = 0, int milliseconds = 0);
        BasicDuration& operator+=(BasicDuration const& duration);
        bool isEqual(BasicDuration const& b);
        bool isInferiorTo(BasicDuration const& b);
        int getHours();
        int getMinutes();
        int getSeconds();
        int getMilliseconds();
        int getDurationTime(); //in milliseconds
        void reset();
        static const int MAX_HOURS = 72;

    protected:
        int _hours;
        int _minutes;
        int _seconds;
        int _milliseconds;

};

#endif BD_H