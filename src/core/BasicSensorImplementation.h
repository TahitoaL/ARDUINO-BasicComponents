#ifndef BSI_H

#define BSI_H

class ColorSensor : public BasicSensor {

    public:
        ColorSensor(char pin, int id, String name);
        int readValue(boolean save = false);
        int readColor(int color);
        boolean lineDetected();


    protected:
        int _red;
        int _green;
        int _blue;
        int _clear;

};

#endif