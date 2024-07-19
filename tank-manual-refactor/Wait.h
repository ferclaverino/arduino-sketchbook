#ifndef Wait_h
#define Wait_h

#include "Arduino.h"

class Wait {
public:
  Wait(const unsigned int waitTimeInmillis);
  bool done();

private:
  unsigned int _waitTimeInmillis;
  unsigned long _lastTimestamp;
};

#endif