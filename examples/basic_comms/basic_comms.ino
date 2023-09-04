#include "NSL_EPS.h"

EPS eps(EPS_RX, EPS_TX);

void setup() {
  Serial.begin(9600);
  pinMode(BUSY, INPUT);
  while (digitalRead(BUSY) == HIGH)
  {
    Serial.println("Waiting to start");
    delay(1000);
  }
  eps.begin();
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
