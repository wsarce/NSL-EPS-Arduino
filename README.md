# NSL EPS Arduino

### Parties Involved
Group: UNL Aerospace Club - Aerospace eXperimental Payloads<br>
Developer: Walker Arce<br>

### Motivation
This Arduino library was written to facilitate communication with Near Space Launch's Electrical Power System for Big Red Sat-1.

### Installation
Export a zip file of this repository and load into your Arduino or Energia environment.

### Usage
```
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
```

### Citation
```
@misc{Arce_NSL_EPS_Arduino_2023,
      author = {Arce, Walker},
      month = {11},
      title = {{NSL EPS Arduino}},
      url = {https://github.com/wsarce/NSL-EPS-Arduino},
      year = {2023}
}
```
