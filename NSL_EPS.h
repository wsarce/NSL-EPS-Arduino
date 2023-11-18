#ifndef EPS_RADIO_H
#define EPS_RADIO_H

#include "Energia.h"
#include <SoftwareSerial.h>

#define EPS_BYTES 21
#define EPS_BUSY HIGH
#define EPS_READY LOW
#define EPS_TRIES 5


class EPS
{
  public:
	EPS(uint8_t rx_pin, uint8_t tx_pin);
	~EPS();
	void begin(void);
    bool radio(byte *packet);
    bool heartbeat(byte *packet);
    bool sleep(void);

  private:
	SoftwareSerial eps_serial;
    bool eps_sleep_send(void);
    bool eps_heartbeat_send(byte *packet);
    bool eps_radio_send(byte *packet);
};
#endif 
