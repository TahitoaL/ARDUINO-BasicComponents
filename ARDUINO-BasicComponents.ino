#include "Arduino.h"
#include "./src/BasicComponents.h"
#include "Streaming.h"
#include <EEPROM.h>
#include <Servo.h>

BasicTimer timer1(0, 100);
BasicTimer timer2(2, 500);
BasicTimer timerObstacle(0, 500);
BasicTimer timerStop(2);
BasicTimer timerBuzzer(0, 200);
ColorSensor color1(37, 41, 45, 29, 33, 25, 0, "FrontRightColorSensor");
ColorSensor color2(36, 40, 44, 28, 32, 24, 10, "FrontLeftColorSensor");
BasicMotor motor1(11, 1, "RunBotMotor", 20);
BasicTimer timerSpeed(0, 500);
BasicTimer motorSpeed(0, 1000);
DigitalSensor speedMagnet(10, false, 2, "SpeedMagnet"); // Vérifier PIN & PULLUP
Servo servo1;
DistanceSensor frontCentralDistance(23, 22, 20, "FrontCentralDistanceSensor"); //CHANGER PIN
DistanceSensor frontRightDistance(17, 18, 21, "FrontRightDistanceSensor");
DistanceSensor frontLeftDistance(15, 16, 22, "FrontLeftDistanceSensor");


// <Servo>
int servo1__positionInitial = 95; // 92
int servo1__positionRight = 82; //88
int servo1__positionLeft = 113; //118
// </Servo>

int MAX_SPEED = 0;
int currentSpeed = 0;

bool error = false;
int i = 0;
int c = 0;

void estimateMaxSpeed()
{
    if (currentSpeed > MAX_SPEED)
    {
        MAX_SPEED = currentSpeed;
        EEPROM.write(0, MAX_SPEED);
        // Serial << "Write new max speed" << endl;
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
        // Serial << "currentSpeed : " << currentSpeed << endl;
        // Serial << "MaxSpeed : " << MAX_SPEED << endl;
        // Serial << "Nb de tour : " << c << endl << "Ditance : " << distance << endl << "Vitesse : " << vitesse  << endl;
        // Serial << "EEPROM written speed : " << EEPROM.read(0) << endl;
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
            color2.readColor();
            color1.readState();
            color2.readState();
            Serial << "R : " << color1.getRed() << " G : " << color1.getGreen() << " B : " << color1.getBlue() << endl;
            error = false;
            if (color1.getState() && color2.getState())
            {
                Serial << "OK : RunBot aligne" << endl;
                servo1.write(servo1__positionInitial);
            }
            else if (!color1.getState() && !color2.getState())
            {
                Serial << "STOP : Erreur" << endl;
                servo1.write(servo1__positionInitial);
                error = true;
            }
            else if (color1.getState() && !color2.getState())
            {
                Serial << "Tourner à gauche" << endl;
                servo1.write(servo1__positionLeft);
            }
            else if (!color1.getState() && color2.getState())
            {
                Serial << "Tourner à droite" << endl;
                servo1.write(servo1__positionRight);
            }
    }
}

void motor()
{
    if (error)
    {
        motor1.setSpeed(0);
    }
    else
    {
        motor1.setSpeed(13);
    }
}

void obstacles()
{
    if (timerObstacle.timeIsUp())
    {
        timerObstacle.init();
        frontCentralDistance.readState();
        frontRightDistance.readState();
        frontLeftDistance.readState();
        Serial << "FC : " << frontCentralDistance.getState() << " FR : " << frontRightDistance.getState() << " FL : " << frontLeftDistance.getState() << endl;
        if (frontCentralDistance.getState() || frontRightDistance.getState() || frontLeftDistance.getState())
        {
            if (frontCentralDistance.getLastState() || frontRightDistance.getLastState() || frontLeftDistance.getLastState())
            {
                if (frontCentralDistance.getValue() < 300)
                {
                    stopRunBot();
                }
                else if (frontCentralDistance.getValue() < frontCentralDistance.getLastValue() || frontRightDistance.getValue() < frontCentralDistance.getLastValue() || frontLeftDistance.getValue() < frontCentralDistance.getLastValue())
                {
                    stopRunBot();
                }
            }        
        }
    }
}

void stopRunBot()
{
    motor1.setSpeed(0);
    servo1.write(servo1__positionInitial);
    while (true)
    {
        Serial << "OBSTACLE" << endl;
        delay(5000);
    }
}

void setup()
{
    pinMode(13, OUTPUT);
    digitalWrite(13, HIGH);
    pinMode(19, OUTPUT);
    digitalWrite(19, HIGH);
    pinMode(20, OUTPUT);
    digitalWrite(20, HIGH);
    pinMode(21, OUTPUT);
    digitalWrite(21, HIGH);


    Serial.begin(9600);
    timer1.init();
    color1.setUp();
    color1.switchOnLed();
    color1.setReferenceColor(210,70,110);
    color2.setUp();
    color2.switchOnLed();
    color2.setReferenceColor(210,70,110);
    motor1.setUp();
    timerSpeed.init();
    motorSpeed.init();
    timerObstacle.init();

    servo1.attach(7);
    servo1.write(120);

    frontCentralDistance.setUp();
    frontRightDistance.setUp();
    frontLeftDistance.setUp();

    MAX_SPEED = EEPROM.read(0);
    // Serial << "Last Max Speed : " << MAX_SPEED << endl;
}

void loop()
{
    // estimateMaxSpeed();
    // speed();
    line();
    motor();
    // obstacles();
}
