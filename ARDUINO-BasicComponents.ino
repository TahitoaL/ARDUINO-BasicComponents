#include "Arduino.h"
#include "./src/BasicComponents.h"

BasicTimer timer1;
BasicDuration time1(4);
ColorSensor color1(8, 4, 5, 6, 7, 9, 0, "ColorSensor");

void setup()
{
    Serial.begin(9600);
    Serial.println("Lancement");
    timer1.setValue(time1);
    timer1.init();
    color1.setUp();
}

void loop()
{
    color1.switchOnLed();
    delay(2000);
    color1.switchOffLed();
    delay(2000);
}
