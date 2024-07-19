#include "Arduino.h"
#include "Wait.h"

Wait::Wait(const unsigned int waitTimeInmillis) {
  _waitTimeInmillis = waitTimeInmillis;
  _lastTimestamp = 0;
}

const bool Wait::done() {
  const unsigned long nowTimestamp = millis();
  const unsigned long gap = nowTimestamp - _lastTimestamp;
  bool isDone = false;

  if (gap > _waitTimeInmillis) {
    isDone = true;

    // Update last timestamp so difference between calls is > waitTimeInmillis
    _lastTimestamp = nowTimestamp;
  }

  return isDone;
}
