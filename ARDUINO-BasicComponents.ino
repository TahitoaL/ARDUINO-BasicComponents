#include "Arduino.h"
#include "./src/BasicComponents.h"

BasicTimer timer1(1000);

void setup()
{
    Serial.begin(9600);
    Serial.println("Lancement");
    timer1.init();
}

void loop()
{
    if (timer1.timeIsUp())
    {
      Serial.println("Une boucle a ete faite");
    }
}
