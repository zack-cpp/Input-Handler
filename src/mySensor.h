#ifndef MY_SENSOR_H
#define MY_SENSOR_H

#include <Arduino.h>

class MY_SENSOR {
public:
  void init(uint8_t pin);
  bool read_state(void);
  bool state_changed(bool state);
private:
  uint8_t _pin;
  bool _activeLow = false;
  bool _prevResult = false;
};

#endif