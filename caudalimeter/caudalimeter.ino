#include "Caudalimeter.h"
#include "Wait.h"

#define CAUDALIMETER_PIN 2
#define WAIT_FOR_LOG_TIME 1000

Caudalimeter caudalimeter(CAUDALIMETER_PIN);
Wait waitforLog(WAIT_FOR_LOG_TIME);

unsigned long startTimestamp;
unsigned int freqPerMinute = 0;
unsigned int startTickCount = 0;

void caudalimeterTick() {
  caudalimeter.tick();
}

void setup() {
  Serial.begin(9600);

  caudalimeter.begin(caudalimeterTick);
  startTimestamp = millis();
}

void loop() {

  const unsigned long endTimestamp = millis();
  const unsigned long timeSpan = endTimestamp - startTimestamp;
  if (timeSpan >= 10 * 1000) {
    const unsigned int endTickCount = caudalimeter.getTickCount();
    freqPerMinute = endTickCount - startTickCount;
    startTickCount = endTickCount;
    startTimestamp = endTimestamp;
  }

  if (waitforLog.done()) {
    noInterrupts();

    Serial.print(" count: ");
    Serial.print(caudalimeter.getTickCount());

    Serial.print(" startTimestamp: ");
    Serial.print(startTimestamp);

    Serial.print(" endTimestamp: ");
    Serial.print(endTimestamp);

    Serial.print(" timeSpan: ");
    Serial.print(timeSpan);

    Serial.print(" startTickCount: ");
    Serial.print(startTickCount);

    Serial.print(" freqPerMinute: ");
    Serial.print(freqPerMinute);

    Serial.println();

    interrupts();
  }

}
