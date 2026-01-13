#ifndef DRIVE_H
#define DRIVE_H

#include <Arduino.h>
#include <Servo.h>

// Pin definitions
extern const int INPUT_REV;
extern const int INPUT_FWD;
extern const int ENABLE_PIN;
extern const int SERVO_PIN;
extern const int PUSH_PIN;
extern const int MAX_TURN;


void carInit();

// Movement
void fwd(int speed);
void rev(int speed);
void stopCar();

// Steering
void turnL(int deg);
void turnR(int deg);
void turnS();

// Button / obstacle
bool push();
void fwdUntilPush(int speed);
void stopIfPush();
void revIfPush(int speed);

// Utility
void delaySec(int sec);

#endif
