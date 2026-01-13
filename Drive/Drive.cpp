#include "Drive.h"

// Pin definitions
const int INPUT_REV  = 10;
const int INPUT_FWD  = 12;
const int ENABLE_PIN = 9;
const int SERVO_PIN  = 11;
const int PUSH_PIN   = 8;
const int MAX_TURN   = 33;

// Setup and initialization
Servo servo;

void carInit() {
  pinMode(INPUT_FWD, OUTPUT);
  pinMode(INPUT_REV, OUTPUT);
  pinMode(ENABLE_PIN, OUTPUT);
  pinMode(PUSH_PIN, INPUT_PULLUP);

  servo.attach(SERVO_PIN);
  turnS();
}


// Function definitions
void fwd(int speed) {
  speed = constrain(speed, 0, 100);
  speed = map(speed, 0, 100, 0, 255);

  Serial.print("Fwd speed: ");
  Serial.println(speed);

  analogWrite(ENABLE_PIN, speed);
  digitalWrite(INPUT_FWD, HIGH);
  digitalWrite(INPUT_REV, LOW);
}

void rev(int speed) {
  speed = constrain(speed, 0, 100);
  speed = map(speed, 0, 100, 0, 255);

  Serial.print("Rev speed: ");
  Serial.println(speed);

  analogWrite(ENABLE_PIN, speed);
  digitalWrite(INPUT_REV, HIGH);
  digitalWrite(INPUT_FWD, LOW);
}

void stopCar() {
  analogWrite(ENABLE_PIN, 0);
  digitalWrite(INPUT_FWD, LOW);
  digitalWrite(INPUT_REV, LOW);

  Serial.println("Speed: 0");
}

void turnR(int deg) {
  deg = constrain(deg, 0, 90);
  deg = map(deg, 0, 90, 0, MAX_TURN);
  deg = 90 - deg;

  servo.write(deg);

  Serial.println("Turning Right");
  Serial.print("Turn angle: ");
  Serial.println(deg);
}

void turnL(int deg) {
  deg = constrain(deg, 0, 90);
  deg = 90 + deg;
  deg = map(deg, 90, 180, 90, MAX_TURN + 90);

  servo.write(deg);

  Serial.println("Turning Left");
  Serial.print("Turn angle: ");
  Serial.println(deg);
}

void turnS() {
  servo.write(90);

  Serial.println("Wheels straight");
  Serial.print("Turn angle: ");
  Serial.println("90");
}

bool push() {
  return !digitalRead(PUSH_PIN);
}

void fwdUntilPush(int speed) {
  while (!push()) {
    fwd(speed);
  }
  Serial.println("Obstacle detected!");
  stopCar();
}

void stopIfPush() {
  if (push()) {
    stopCar();
    Serial.println("Obstacle detected!");
  }
}

void revIfPush(int speed) {
  if (push()) {
    stopCar();
    Serial.println("Obstacle detected!");
    delay(100);
    rev(speed);
    delay(1000);
  }
}

void delaySec(int sec) {
  delay(sec * 1000);
}
