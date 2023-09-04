#include "NSL_EPS.h"

EPS eps;

void setup() {
  Serial.begin(9600);
  while (digitalRead(BUSY) == HIGH);
  eps.begin(EPS_RX, EPS_TX, false, 38400);
  pinMode(BUSY, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly: 
  if (!eps.heartbeat())
  {
    Serial.println("Heartbeat failed");
  }
  if (!eps.radio())
  {
    Serial.println("Radio send failed");
  }
  if (!eps.sleep())
  {
    Serial.println("Sleep failed");
  }
}
