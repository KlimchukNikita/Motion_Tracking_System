/*
  Project Motion_Tracking_System
  Copyright (c) 2021 Electronic Device Development Club
  https://github.com/KlimchukNikita

  Development: <EDDC> 2021
  Example Demo: Joystick-Keyboard
*/

#include "Keyboard.h"

#define X_AXIS A2
#define Y_AXIS A3

void setup()
{
    Serial.begin(9600);

    Keyboard.begin();
}

void loop()
{
    int rotationX;
    rotationX = analogRead (X_AXIS);

    if ((rotationX >= 0) && (rotationX < 341))
    {
        Keyboard.write('w');
    }

    if ((rotationX >= 682) && (rotationX < 1023))
    {
        Keyboard.write('s');
    }

    int rotationY;
    rotationY = analogRead (Y_AXIS);

    if ((rotationY >= 0) && (rotationY < 341))
    {
        Keyboard.write('a');
    }

    if ((rotationY >= 682) && (rotationY < 1023))
    {
        Keyboard.write('d');
    }
}
