#include <Servo.h>

int inputRev = 3;
int inputFwd = 4;
int enable = 5;
int servoPin = 10;
int maxTurn = 90;

Servo servo;

void fwd(int speed) {
  speed = constrain(speed, 0, 100);
  speed = map(speed,0,100,0,255);

  Serial.print("Fwd speed: ");
  Serial.println(speed);
  analogWrite(enable, speed);
  digitalWrite(inputFwd,HIGH);
  digitalWrite(inputRev, 0);
}

void rev(int speed) {
  speed = constrain(speed, 0, 100);
  speed = map(speed,0,100,0,255);

  analogWrite(enable, speed);
  Serial.print("Rev speed: ");
  Serial.println(speed);
  digitalWrite(inputRev, HIGH);
  digitalWrite(inputFwd, 0);
}

void turnL(int deg) {
  deg = constrain(deg, 0, 90);
  deg = 90 - deg;
  deg = map(deg, 0, 90, 0, maxTurn);
  servo.write(deg);
}

void turnR(int deg) {
  deg = constrain(deg, 0, 90);
  deg = 90 + deg;
  deg = map(deg, 90, 180, 90, maxTurn+90);
  servo.write(deg);
}

void turnS(){
  servo.write(90);
}
void stop() {
  analogWrite(enable, 0);
  digitalWrite(inputFwd, LOW);
  digitalWrite(inputRev, LOW);
  Serial.println("Speed: 0");
}

void delaySec(int sec) {
  delay(sec*1000);
}



void setup() {
  // put your setup code here, to run once:
  pinMode(inputFwd, OUTPUT);
  pinMode(inputRev, OUTPUT);
  pinMode(enable, OUTPUT);
  Serial.begin(115200);
  servo.attach(servoPin);
  turnS();
  

}

void loop() {
  // put your main code here, to run repeatedly:
  fwd(100);
  
}


