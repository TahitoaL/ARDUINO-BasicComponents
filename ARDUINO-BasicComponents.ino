#include "./BasicComponents/BasicComponents.h"

void setup()
{
    Serial.begin(9600);
    Serial.println("Bonjour je fonctionne");
}

void loop()
{
    Serial.println("On a fait une boucle");
    delay(1000);
}
