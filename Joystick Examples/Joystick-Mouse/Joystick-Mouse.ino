/*
  Project Motion_Tracking_System
  Copyright (c) 2021 Electronic Device Development Club
  https://github.com/KlimchukNikita

  Development: <EDDC> 2021
  Example Demo: Joystick-Mouse
*/

#include "Mouse.h"

#define X_AXIS A2
#define Y_AXIS A3

#define L_PIN 14
#define R_PIN 15

int range = 12;
int responseDelay = 5;
int threshold = range / 4;
int center = range / 2;

void setup()
{
    Serial.begin(9600);

    Mouse.begin();
}

void loop()
{
    int xReading = readAxis(X_AXIS);
    int yReading = readAxis(Y_AXIS);

    Mouse.move(xReading, yReading, 0);

    if (digitalRead(L_PIN) == HIGH)
    {
        if (!Mouse.isPressed(MOUSE_LEFT))
        {
            Mouse.press(MOUSE_LEFT);
        }
    }

    else
    {
        if (Mouse.isPressed(MOUSE_LEFT))
        {
            Mouse.release(MOUSE_LEFT);
        }
    }

    delay(responseDelay);

    if (digitalRead(R_PIN) == HIGH)
    {
        if (!Mouse.isPressed(MOUSE_RIGHT))
        {
            Mouse.press(MOUSE_RIGHT);
        }
    }

    else
    {
        if (Mouse.isPressed(MOUSE_RIGHT))
        {
            Mouse.release(MOUSE_RIGHT);
        }
    }

    delay(responseDelay);
}

int readAxis(int thisAxis)
{
    int reading = analogRead(thisAxis);
    reading = map(reading, 0, 1023, 0, range);

    int distance = reading - center;
    if (abs(distance) < threshold)
    {
        distance = 0;
    }

    return distance;
}
