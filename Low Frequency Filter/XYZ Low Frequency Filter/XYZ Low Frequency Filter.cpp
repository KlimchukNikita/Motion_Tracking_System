/*
  Project Motion_Tracking_System
  Copyright (c) 2021 Electronic Device Development Club
  https://github.com/KlimchukNikita

  Development: <EDDC> 2021
  Example Demo: XYZ Low Frequency Filter
*/

const byte pinX = A0;
const byte pinY = A1;
const byte pinZ = A2;

const float K = 0.1;

float val = 0;

void setup()
{
    Serial.begin(9600);
}

void loop()
{
    int x = analogRead(pinX);
    int y = analogRead(pinY);
    int z = analogRead(pinZ);

    int val_1 = val * (1 - K) + x * K;
    int val_2 = val * (1 - K) + y * K;
    int val_3 = val * (1 - K) + z * K;

    Serial.print(int(val_1));
    Serial.print("  ");

    Serial.print(int(val_2));
    Serial.print("  ");

    Serial.print(int(val_3));
    Serial.println();

    delay(20);
}
