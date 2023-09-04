#include "eps_radio.h"
#include "Energia.h"
#include <SoftwareSerial.h>

bool EPS::radio(void)
{
  int tries = EPS_TRIES;
  while (!eps_radio_send())
  {
    if (tries-- <= 0) return false;
  }
  return true;
}

bool EPS::eps_radio_send(void)
{
  eps_serial.write(radio_payload, EPS_BYTES);
  byte ack[EPS_BYTES];
  memset(ack, 0, EPS_BYTES);
  while (digitalRead(BUSY) == HIGH);
  eps_serial.readBytes(ack, EPS_BYTES);
  if (memcmp(empty_payload, ack, EPS_BYTES) != 0) return true;
  else return false;
}

bool EPS::sleep(void)
{
  int tries = EPS_TRIES;
  while (!eps_sleep_send())
  {
    if (tries-- <= 0) return false;
  }
  return true;
}

bool EPS::eps_sleep_send(void)
{
  eps_serial.write(sleep_payload, EPS_BYTES);
  byte ack[EPS_BYTES];
  memset(ack, 0, EPS_BYTES);
  while (digitalRead(BUSY) == HIGH);
  eps_serial.readBytes(ack, EPS_BYTES);
  if (memcmp(empty_payload, ack, EPS_BYTES) != 0) return true;
  else return false;
}

bool EPS::heartbeat(void)
{
  int tries = EPS_TRIES;
  while (!eps_heartbeat_send())
  {
    if (tries-- <= 0) return false;
  }
  return true;
}

bool EPS::eps_heartbeat_send(void)
{
  eps_serial.write(heartbeat_payload, EPS_BYTES);
  byte ack[EPS_BYTES];
  memset(ack, 0, EPS_BYTES);
  while (digitalRead(BUSY) == HIGH);
  eps_serial.readBytes(ack, EPS_BYTES);
  if (memcmp(empty_payload, ack, EPS_BYTES) != 0) return true;
  else return false;
}
