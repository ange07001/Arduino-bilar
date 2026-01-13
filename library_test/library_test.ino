#include <Drive.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  carInit();
}

void loop() {
  // put your main code here, to run repeatedly:
  fwd(50);
}
