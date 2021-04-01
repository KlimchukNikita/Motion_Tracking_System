/*
  Project Motion_Tracking_System
  Copyright (c) 2021 Electronic Device Development Club
  https://github.com/KlimchukNikita

  Development: <EDDC> 2021
  Example Demo: Button-Keyboard
*/

#include "Keyboard.h"

#define Q_PIN 4
#define E_PIN 5

#define W_PIN 6
#define S_PIN 7
#define A_PIN 8
#define D_PIN 9

#define Z_PIN 14
#define X_PIN 15

void setup()
{
    Serial.begin(9600);

    Keyboard.begin();
}

void loop()
{
    if (digitalRead(Q_PIN) == HIGH)
    {
        Keyboard.write('q');
    }

    if (digitalRead(E_PIN) == HIGH)
    {
        Keyboard.write('e');
    }

    if (digitalRead(W_PIN) == HIGH)
    {
        Keyboard.write('w');
    }

    if (digitalRead(S_PIN) == HIGH)
    {
        Keyboard.write('s');
    }

    if (digitalRead(A_PIN) == HIGH)
    {
        Keyboard.write('a');
    }

    if (digitalRead(D_PIN) == HIGH)
    {
        Keyboard.write('d');
    }

    if (digitalRead(Z_PIN) == HIGH)
    {
        Keyboard.write('z');
    }

    if (digitalRead(X_PIN) == HIGH)
    {
        Keyboard.write('x');
    }
}
