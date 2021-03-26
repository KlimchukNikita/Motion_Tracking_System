/*
  Project Motion_Tracking_System
  Copyright (c) 2021 Electronic Device Development Club
  https://github.com/KlimchukNikita

  Development: <EDDC> 2021
  Example Demo: Sebastian Madgwick's Filter
*/

#include "I2Cdev.h"
#include "MPU6050.h"
#include "MadgwickAHRS.h"

#define TO_RAD 0.01745329252f

MPU6050 accelgyro;

unsigned long tm, imu_t, prn_t;

const unsigned int imu_to = 20;
const unsigned int prn_to = 100;

float tdelta;

int16_t ax, ay, az;
int16_t gx_raw, gy_raw, gz_raw;

float imu[3];
float quat[4];
float e[3];

void setup()
{
    Serial.begin(9600);

    accelgyro.initialize();
}

void loop()
{
    tm = millis();

    if (imu_t + imu_to < tm)
    {
        tdelta = tm - imu_t;
        imu_t = tm;

        accelgyro.getMotion6(&ax, &ay, &az, &gx_raw, &gy_raw, &gz_raw);

        float gx = gx_raw * TO_RAD / 131.0;
        float gy = gy_raw * TO_RAD / 131.0;
        float gz = gz_raw * TO_RAD / 131.0;

        MadgwickAHRSupdateIMU(tdelta / 1000.0, gx, gy, gz, (float) ax, (float) ay, (float) az);

        quat[0] = q0; quat[1] = q1; quat[2] = q2; quat[3] = q3;

        quat2Euler(&quat[0], &imu[0]);
    }

    tm = millis();

    if (prn_t + prn_to < tm)
    {
        prn_t = tm;

        Serial.print(imu[0] / TO_RAD); Serial.print("\t");
        Serial.print(imu[1] / TO_RAD); Serial.print("\t");
        Serial.println(imu[2] / TO_RAD);
    }
}
