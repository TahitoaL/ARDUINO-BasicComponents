#ifndef BD_H

#define BD_H

class BasicDuration {

    public:
        BasicDuration();
        BasicDuration(const BasicDuration& duration);
        BasicDuration(int seconds, int milliseconds = 0);
        BasicDuration(int minutes, int seconds, int milliseconds);
        BasicDuration& operator+=(BasicDuration const& duration);
        bool isEqual(BasicDuration const& b);
        bool isInferiorTo(BasicDuration const& b);
        int getHours();
        int getMinutes();
        int getSeconds();
        int getMilliseconds();
        long getDurationTime(); //in milliseconds
        void reset();

    protected:
        int _hours;
        int _minutes;
        int _seconds;
        int _milliseconds;

};

#endif BD_H