#ifndef DRIVE_H
#define DRIVE_H

#include <Arduino.h>
#include <Servo.h>

// Pin definitions

// Revese input pin
extern const int INPUT_REV;
// Forward input pin
extern const int INPUT_FWD;
// Enable pin for speed control
extern const int ENABLE_PIN;
// Servo pin for steering
extern const int SERVO_PIN;
// Push button pin for obstacle detection
extern const int PUSH_PIN;
// Maximum turn angle for the servo
extern const int MAX_TURN;

// Setup and initialization for the car
void carInit();

// Movement

// Moves forward at int speed (0-100)
void fwd(int speed);
// Moves reverse at int speed (0-100)
void rev(int speed);
// Stops the car
void stopCar();

// Steering

// Turns left by int degrees (0-90)
void turnL(int deg);
// Turns right by int degrees (0-90)
void turnR(int deg);
// Centers the steering
void turnS();

// Button / obstacle

// Returns true if the push button is pressed
bool push();
// Moves forward until the push button is pressed at int speed (0-100)
void fwdUntilPush(int speed);
// Stops the car if the push button is pressed
void stopIfPush();
// Reverses the car at int speed if the push button is pressed at int speed (0-100)
void revIfPush(int speed);

// Utility

// Delay in seconds
void delaySec(int sec);

#endif
