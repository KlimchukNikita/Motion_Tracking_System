/*
  Project Motion_Tracking_System
  Copyright (c) 2021 Electronic Device Development Club
  https://github.com/KlimchukNikita

  Development: <EDDC> 2021
  Example Demo: Button-Keyboard-Motor
*/

#include "Keyboard.h"

#define MOTOR1_PIN 18
#define MOTOR2_PIN 19
#define MOTOR3_PIN 20
#define MOTOR4_PIN 21

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

    pinMode (MOTOR1_PIN, OUTPUT);
    pinMode (MOTOR2_PIN, OUTPUT);
    pinMode (MOTOR3_PIN, OUTPUT);
    pinMode (MOTOR4_PIN, OUTPUT);
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

        digitalWrite(MOTOR1_PIN, HIGH);
        digitalWrite(MOTOR3_PIN, HIGH);
        delay(50);
        digitalWrite(MOTOR1_PIN, LOW);
        digitalWrite(MOTOR3_PIN, LOW);
    }

    if (digitalRead(S_PIN) == HIGH)
    {
        Keyboard.write('s');

        digitalWrite(MOTOR2_PIN, HIGH);
        digitalWrite(MOTOR4_PIN, HIGH);
        delay(50);
        digitalWrite(MOTOR2_PIN, LOW);
        digitalWrite(MOTOR4_PIN, LOW);
    }

    if (digitalRead(A_PIN) == HIGH)
    {
        Keyboard.write('a');

        digitalWrite(MOTOR1_PIN, HIGH);
        digitalWrite(MOTOR2_PIN, HIGH);
        delay(50);
        digitalWrite(MOTOR1_PIN, LOW);
        digitalWrite(MOTOR2_PIN, LOW);
    }

    if (digitalRead(D_PIN) == HIGH)
    {
        Keyboard.write('d');

        digitalWrite(MOTOR3_PIN, HIGH);
        digitalWrite(MOTOR4_PIN, HIGH);
        delay(50);
        digitalWrite(MOTOR3_PIN, LOW);
        digitalWrite(MOTOR4_PIN, LOW);
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
