#ifndef HCSR04_h
#define HCSR04_h

#include "Arduino.h"

class HCSR04 {
public:
  HCSR04(const unsigned int triggerPin, const unsigned int echoPin);
  void begin();
  unsigned int getDistanceInCm();

private:
  unsigned int _triggerPin;
  unsigned int _echoPin;
  long microsecondsToCentimeters(long microseconds);
};

#endif