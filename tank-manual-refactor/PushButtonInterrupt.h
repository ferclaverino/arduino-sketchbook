#ifndef PushButtonInterrupt_h
#define PushButtonInterrupt_h

#include "Arduino.h"
#include "Debounce.h"

typedef void(*ToggleCallback)();

class PushButtonInterrupt {
public:
  PushButtonInterrupt(const unsigned int pin, const unsigned int debounceTime);
  void begin(const ToggleCallback toggleCalback);
  boolean isPush();
  void toggle();

private:
  unsigned int _pin;
  bool volatile _isPush = false;
  Debounce* _debounce;
};

#endif