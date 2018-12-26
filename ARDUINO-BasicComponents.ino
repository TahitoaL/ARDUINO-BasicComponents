#include "Arduino.h"
#include "./src/BasicComponents.h"

BasicTimer timer1;
BasicDuration time1(4);

void setup()
{
    Serial.begin(9600);
    Serial.println("Lancement");
    timer1.setValue(time1);
    timer1.init();
    Serial.println(timer1.getDuration().getDurationTime());
    Serial.println(timer1.getTime());
    Serial.println(timer1.getDurationValue());
}

void loop()
{
    if (timer1.timeIsUp())
    {
        Serial.println("Une boucle a ete faite");
        timer1.init();
    }
    // Serial.println(timer1.getTime());
    // Serial.println(timer1.timeIsUp());
}
