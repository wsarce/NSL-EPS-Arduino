#ifndef EPS_RADIO_H
#define EPS_RADIO_H

#define EPS_BYTES 21
#define EPS_BUSY HIGH
#define EPS_READY LOW
#define EPS_TRIES 5


class EPS
{
  private:
    bool radio(void);
    bool heartbeat(void);
    bool sleep(void);

  public:
    bool eps_sleep_send(void);
    bool eps_heartbeat_send(void);
    bool eps_radio_send(void);
}
#endif 