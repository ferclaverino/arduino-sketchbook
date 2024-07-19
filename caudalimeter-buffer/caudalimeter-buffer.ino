#include "Caudalimeter.h"
#include "CaudalimeterSampler.h"

#define CAUDALIMETER_PIN 2
#define WAIT_FOR_LOG_TIME 1000
#define CAUDALIMETER_BUFFER_SIZE 60
#define CAUDALIMETER_SAMPLE_RATE 1000

Caudalimeter caudalimeter(CAUDALIMETER_PIN);
CaudalimeterSampler caudalimeterSampler(&caudalimeter, CAUDALIMETER_BUFFER_SIZE, CAUDALIMETER_SAMPLE_RATE);
Wait waitforLog(WAIT_FOR_LOG_TIME);

void caudalimeterTick() {
  caudalimeter.tick();
}

void setup() {
  Serial.begin(9600);

  caudalimeter.begin(caudalimeterTick);
}

void loop() {

  caudalimeterSampler.sample();

  if (waitforLog.done()) {
    noInterrupts();

    Serial.print(" count: ");
    Serial.print(caudalimeter.getTickCount());

    Serial.print(" freqPerMinute: ");
    Serial.print(caudalimeterSampler.getFrequency());

    Serial.println();

    interrupts();
  }

}
