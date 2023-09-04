#include "NSL_EPS.h"
#include "Energia.h"
#include <SoftwareSerial.h>
#include <stdio.h>

byte empty_payload[] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
byte heartbeat_payload[] = {0x50, 0x50, 0x50, 0x0B, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
byte sleep_payload[] = {0x50, 0x50, 0x50, 0x0B, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};
byte radio_payload[] = {0x50, 0x50, 0x50, 0x0C, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

SoftwareSerial eps_serial = SoftwareSerial(EPS_RX, EPS_TX, false);

void EPS::begin(int rx = EPS_RX, int tx = EPS_TX, bool inversion = false, int baud = 38400)
{
	eps_serial = SoftwareSerial(rx, tx, inversion);
	eps_serial.begin(baud);
}

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
