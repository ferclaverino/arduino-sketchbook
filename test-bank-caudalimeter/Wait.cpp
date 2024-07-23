#include "Arduino.h"
#include "Wait.h"

Wait::Wait(const unsigned int waitTimeInmillis) {
  _waitTimeForLoopInmillis = waitTimeInmillis;
  _lastLoopTimestamp = 0;
}

const bool Wait::done() {
  const unsigned long nowTimestamp = millis();
  const unsigned long gap = nowTimestamp - _lastLoopTimestamp;
  bool isDone = false;

  if (gap > _waitTimeForLoopInmillis) {
    isDone = true;

    // Update last timestamp so difference between calls is > waitTimeInmillis
    _lastLoopTimestamp = nowTimestamp;
  }

  return isDone;
}
