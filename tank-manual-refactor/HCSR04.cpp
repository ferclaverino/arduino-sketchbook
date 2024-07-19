#include "Arduino.h"
#include "HCSR04.h"

HCSR04::HCSR04(const unsigned int triggerPin, const unsigned int echoPin) {
  _triggerPin = triggerPin;
  _echoPin = echoPin;
}

void HCSR04::begin() {
  pinMode(_triggerPin, OUTPUT);
  pinMode(_echoPin, INPUT);
}

unsigned int HCSR04::getDistanceInCm() {
  digitalWrite(_triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(_triggerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(_echoPin, LOW);
  noInterrupts();
  long pulseLengthInMicroseconds = pulseIn(this->_echoPin, HIGH, 23529.4); // max sensor dist ~4m
  // long pulseLengthInMicroseconds = pulseIn(this->_echoPin, HIGH); // max sensor dist ~4m
  interrupts();
  return microsecondsToCentimeters(pulseLengthInMicroseconds);
}

long HCSR04::microsecondsToCentimeters(long microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the object we
  // take half of the distance travelled.
  return microseconds / 29 / 2;
}