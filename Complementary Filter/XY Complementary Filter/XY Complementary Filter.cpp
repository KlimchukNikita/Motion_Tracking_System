/*
  Project Motion_Tracking_System
  Copyright (c) 2021 Electronic Device Development Club
  https://github.com/KlimchukNikita

  Development: <EDDC> 2021
  Example Demo: XY Complementary Filter
*/

#include "I2Cdev.h"
#include "MPU6050.h"

#define TO_DEG 57.29577951308232087679815481410517033f
#define T_OUT 20
#define P_OUT 50
#define FK 0.1

MPU6050 accelgyro;

float angle_ax, angle_ay, angle_gx, angle_gy, angle_cpl;
int dt = 0;
long int t_next, p_next;

float clamp(float v, float minv, float maxv)
{
    if (v > maxv)
        return maxv;

    else if(v < minv)
        return minv;

    return v;
}

void setup()
{
    Serial.begin(9600);

    accelgyro.initialize();
}

void loop()
{
    long int t = millis();

    if (t_next < t)
    {
        int16_t ax_raw, ay_raw, az_raw, gx_raw, gy_raw, gz_raw;
        float ax, ay, gx, gy;

        t_next = t + T_OUT;

        accelgyro.getMotion6(&ax_raw, &ay_raw, &az_raw, &gx_raw, &gy_raw, &gz_raw);

        gx = gx_raw / 16.4;
        ay = ay_raw / 4096.0;
        ay = clamp(ay, -1.0, 1.0);

        gy = gy_raw / 16.4;
        ax = ax_raw / 4096.0;
        ax = clamp(ax, -1.0, 1.0);

        angle_ax = 90 - TO_DEG * acos(ay);
        angle_gx = angle_gx + gx * T_OUT / 1000.0;
        angle_gx = angle_gx * (1 - FK) + angle_ax * FK;

        angle_ay = 90 - TO_DEG * acos(ax);
        angle_gy = angle_gy + gy * T_OUT / 1000.0;
        angle_gy = angle_gy * (1 - FK) - angle_ay * FK;
    }

    t = millis();

    if (p_next < t)
    {
        p_next = t + P_OUT;

        Serial.print(angle_gx); Serial.print("\t");
        Serial.println(angle_gy);
    }
}
