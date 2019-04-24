#include "Arduino.h"
#include "./src/BasicComponents.h"
#include "Streaming.h"
#include <EEPROM.h>

BasicTimer timer1(0, 100);
BasicTimer timer2(2, 500);
ColorSensor color1(36, 28, 30, 32, 34, 26, 0, "FrontRightColorSensor");
BasicMotor motor1(11, 1, "RunBotMotor", 20);
BasicTimer timerSpeed(0, 500);
DigitalSensor speedMagnet(10, false, 2, "SpeedMagnet"); // Vérifier PIN & PULLUP

int MAX_SPEED = 0;
int currentSpeed = 0;

int i = 0;
int c = 0;

void estimateMaxSpeed()
{
    if (currentSpeed > MAX_SPEED)
    {
        MAX_SPEED = currentSpeed;
        EEPROM.write(0, MAX_SPEED);
        Serial << "Write new max speed" << endl;
    }
}

void speed()
{
    speedMagnet.savePreviousData();
    if (timerSpeed.timeIsUp())
    {
        timerSpeed.init();
        float distance = c * 0.24 * 2;
        float vitesse = distance * 3.6;
        currentSpeed = int(vitesse * 10);
        Serial << "currentSpeed : " << currentSpeed << endl;
        Serial << "MaxSpeed : " << MAX_SPEED << endl;
        Serial << "Nb de tour : " << c << endl << "Ditance : " << distance << endl << "Vitesse : " << vitesse  << endl;
        Serial << "EEPROM written speed : " << EEPROM.read(0) << endl;
        c = 0;
    }
    else
    {
        if (speedMagnet.stateHasRising())
        {
            c++;
        }
    }
    
}

void line()
{
    if (timer1.timeIsUp())
    {
            timer1.init();
            color1.readColor();
            if(color1.readState())
            {
                Serial << "ligne DETECTE" << endl;
            }
            else
            {
                Serial << "ligne NON DETECTE" << endl;
            }
    }
}

void motor()
{
    if (timer2.timeIsUp())
    {
            timer2.init();
            motor1.setSpeed(100);
            // if (Serial.available() > 0)
            // {
            //     i++;
            //     // incomingByte = Serial.read();
            //     // Serial.print("I received: ");
            //     // Serial.println(incomingByte, DEC);
            // }
            i++;
            if (i > 100)
            {
                i = 0;
            }
            Serial << "Speed : " << i << endl;
    }
}

void setup()
{
    pinMode(22, OUTPUT);
    digitalWrite(22, HIGH);
    Serial.begin(9600);
    timer1.init();
    color1.setUp();
    color1.switchOnLed();
    color1.setReferenceColor(239, 145, 14);
    motor1.setUp();
    timerSpeed.init();

    //
    MAX_SPEED = EEPROM.read(0);
    Serial << "Last Max Speed : " << MAX_SPEED << endl;
}

void loop()
{
    estimateMaxSpeed();
    speed();
    // line();
    motor();
}
