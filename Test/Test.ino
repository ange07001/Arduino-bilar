#include <Drive.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  carInit();
}

void loop() {
  // put your main code here, to run repeatedly:
  fwdUntilPush(75);
  delaySec(5);
  turnL(90);
  delaySec(3);
  turnR(90);
  delaySec(3);
  turnS();
  delaySec(2);
}
