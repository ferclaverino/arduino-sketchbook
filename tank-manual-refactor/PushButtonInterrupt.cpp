#include "Arduino.h"
#include "PushButtonInterrupt.h"
#include "Debounce.h"

PushButtonInterrupt::PushButtonInterrupt(const unsigned int pin, const  unsigned int debounceTimeInMillis) {
  _pin = pin;
  _debounce = new Debounce(debounceTimeInMillis);
}

void PushButtonInterrupt::begin(const ToggleCallback toggleCalback) {
  pinMode(_pin, INPUT_PULLUP);

  // The only way to pass pointer to member function as pointer to functiosn 
  // https://isocpp.org/wiki/faq/pointers-to-members#fnptr-vs-memfnptr-types
  attachInterrupt(digitalPinToInterrupt(_pin), toggleCalback, FALLING);
}

bool PushButtonInterrupt::isPush() {
  return _isPush;
}

void PushButtonInterrupt::toggle() {
  if (_debounce->done()) {
    _isPush = !_isPush;
  }
}
