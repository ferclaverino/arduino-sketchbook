#include "HCSR04.h"

#define TRIGGER_PIN 8
#define ECHO_PIN 9

HCSR04 distanceSensor(TRIGGER_PIN, ECHO_PIN);

void setup() {
  Serial.begin(9600);
  distanceSensor.begin();
}

void loop()
{

  Serial.print(" Distance: ");
  Serial.print(getDistance());
  Serial.print(" cm, ");

  Serial.print(" Distance avg: ");
  Serial.print(getDistanceAvg());
  Serial.print(" cm, ");

  Serial.println();
  delay(1000);
}

float getDistance() {
  return distanceSensor.getDistanceInCm();
}

float getDistanceAvg() {
  float distanceSum = 0;
  unsigned int sampleCount = 10;

  for (unsigned int i = 0; i < sampleCount; i++) {
    float distance = getDistance();
    distanceSum += distance;

    // Serial.print(" (distance: ");
    // Serial.print(distance);
    // Serial.print(")");
  }
  float avg = distanceSum / (float)sampleCount;
  return avg;
}