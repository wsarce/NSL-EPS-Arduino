#ifndef EPS_RADIO_H
#define EPS_RADIO_H

#include "Energia.h"

#define EPS_BYTES 21
#define EPS_BUSY HIGH
#define EPS_READY LOW
#define EPS_TRIES 5


class EPS
{
  public:
	void begin(int rx, int tx, bool inversion, int baud);
    bool radio(void);
    bool heartbeat(void);
    bool sleep(void);

  private:
    bool eps_sleep_send(void);
    bool eps_heartbeat_send(void);
    bool eps_radio_send(void);
};
#endif 
