#include "ArduinoJson-v7.1.0.h"
#include "Wait.h"

#define WAIT_FOR_PUBLISH 1000

Wait waitforPublish(WAIT_FOR_PUBLISH);

void setup() {
  Serial.begin(9600);
  randomSeed(analogRead(0));
}

void loop() {

  if (waitforPublish.done()) {
    long flow1 = random(1000, 3000);
    long turnsCount = random(0, 10);

    JsonDocument doc;
    doc["flow"] = flow1;
    doc["turnsCount"] = turnsCount;

    serializeJson(doc, Serial);
    Serial.println();
  }
}