#include <mySensor.h>

void MY_SENSOR::init(uint8_t pin) {
  this->_pin = pin;
  if (digitalRead(this->_pin) == HIGH) {
    this->_activeLow = true;
  } else {
    this->_activeLow = false;
  }
}

bool MY_SENSOR::read_state(void) {
  static bool result = false;
  if (digitalRead(this->_pin) == LOW) {
    if (this->_activeLow) {
      /* sensor is active */
      result = true;
    } else {
      result = false;
    }
  } else {
    if (this->_activeLow) {
      result = false;
    } else {
      /* sensor is active */
      result = true;
    }
  }
  return result;
}

bool MY_SENSOR::state_changed(bool state) {
  bool ret = false;
  if (this->_prevResult != state) {
    this->_prevResult = state;
    if (state == true) {
      ret = true;
    }
  }
  return ret;
}