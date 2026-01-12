#include <Servo.h>

// Define pin numbers for motor and servo control
int inputRev = 10;
int inputFwd = 12;
int enable = 9;
int servoPin = 11;
int maxTurn = 33;
int pushPin = 8;

Servo servo;

// Move the car forward at a specified speed
void fwd(int speed) {
  speed = constrain(speed, 0, 100);
  speed = map(speed, 0, 100, 0, 255);
  Serial.print("Fwd speed: ");
  Serial.println(speed);
  analogWrite(enable, speed);
  digitalWrite(inputFwd, HIGH);
  digitalWrite(inputRev, LOW);
}

// Move the car backward at a specified speed
void rev(int speed) {
  speed = constrain(speed, 0, 100);
  speed = map(speed, 0, 100, 0, 255);
  analogWrite(enable, speed);
  Serial.print("Rev speed: ");
  Serial.println(speed);
  digitalWrite(inputRev, HIGH);
  digitalWrite(inputFwd, LOW);
}

// Turn the car left by a specified degree
void turnR(int deg) {
  deg = constrain(deg, 0, 90);
  deg = map(deg, 0, 90, 0, maxTurn);
  deg = 90 - deg;
  servo.write(deg);
  Serial.print("Turn angle: ");
  Serial.println(deg);
}

// Turn the car right by a specified degree
void turnL(int deg) {
  deg = constrain(deg, 0, 90);
  deg = 90 + deg;
  deg = map(deg, 90, 180, 90, maxTurn + 90);
  servo.write(deg);
  Serial.print("Turn angle: ");
  Serial.println(deg);
}

// Center the steering
void turnS() {
  servo.write(90);
  Serial.println("90");
}

// Stop the car
void stop() {
  analogWrite(enable, 0);
  digitalWrite(inputFwd, LOW);
  digitalWrite(inputRev, LOW);
  Serial.println("Speed: 0");
}

// Delay execution for a specified number of seconds
void delaySec(int sec) {
  delay(sec * 1000);
}

// Check if the push button is pressed
bool push() {
  return !digitalRead(pushPin);
}

// Move forward until the push button is pressed
void fwdUntilPush(int speed) {
  while (!push()) {
    fwd(speed);
  }
  Serial.println("Obstacle detected!");
  stop();
}

// Stop the car if the push button is pressed
void stopIfPush() {
  if (push()) {
    stop();
  }
  Serial.println("Obstacle detected!");
}

// Move backward if the push button is pressed
void revIfPush(int speed) {
  if (push()) {
    stop();
    Serial.println("Obstacle detected!");
    delay(100);
    rev(speed);
    delay(1000);
  }
}

void setup() {
  // Initialize pins and serial communication
  pinMode(inputFwd, OUTPUT);
  pinMode(inputRev, OUTPUT);
  pinMode(enable, OUTPUT);
  pinMode(pushPin, INPUT_PULLUP);
  Serial.begin(115200);
  servo.attach(servoPin);
  turnS();
}

void loop() {
  // Main loop (currently empty)
  fwd(100);
  delaySec(2);
  rev(100);
  delaySec(2);
  stop();
  delaySec(1);
  turnR(90);
  delaySec(2);
  turnL(90);
  delaySec(2);
  turnS();
  delaySec(1);
  fwdUntilPush(75);
  delaySec(1);
}