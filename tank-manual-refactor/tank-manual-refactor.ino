// Control a solenoid and pump
// but refactored to objects
// buttons are implemented with 2 strategies: attach interrupt and digital read

#include "PushButtonDigitalRead.h"
#include "Relay.h"
#include "HCSR04.h"
#include "Wait.h"

#define SOLENOID_BUTTON_PIN 2
#define SOLENOID_RELAY_PIN 6
#define PUMP_BUTTON_PIN 3
#define PUMP_RELAY_PIN 7
#define WATER_DISTANCE_TRIGGER_PIN 8
#define WATER_DISTANCE_ECHO_PIN 9

#define DEBOUNCE_TIME 50
#define WAIT_FOR_LOG_TIME 1000
#define TANK_WAIT_FOR_READ_DISTANCE 500

//PushButtonInterrupt solenoidButton(SOLENOID_BUTTON_PIN, DEBOUNCE_TIME);
PushButtonDigitalRead solenoidButton(SOLENOID_BUTTON_PIN, DEBOUNCE_TIME);
Relay solenoidRelay(SOLENOID_RELAY_PIN);

//PushButtonInterrupt pumpButton(PUMP_BUTTON_PIN, DEBOUNCE_TIME);
PushButtonDigitalRead pumpButton(PUMP_BUTTON_PIN, DEBOUNCE_TIME);
Relay pumpRelay(PUMP_RELAY_PIN);

HCSR04 waterDistance(WATER_DISTANCE_TRIGGER_PIN, WATER_DISTANCE_ECHO_PIN);

Wait waitforLog(WAIT_FOR_LOG_TIME);
Wait waitforReadDistance(TANK_WAIT_FOR_READ_DISTANCE);

unsigned int waterDistanceInCm;

// void solenoidButtonToggle() {
//   solenoidButton.toggle();
// }

// void pumpButtonToggle() {
//   pumpButton.toggle();
// }

void setup() {
  Serial.begin(9600);

  // solenoidButton.begin(solenoidButtonToggle);
  solenoidButton.begin();
  solenoidRelay.begin();

  // pumpButton.begin(pumpButtonToggle);
  pumpButton.begin();
  pumpRelay.begin();

  waterDistance.begin();
}

void loop()
{

  if (waitforReadDistance.done()) {
    waterDistanceInCm = waterDistance.getDistanceInCm();

    if (waterDistanceInCm >= 19) {
      pumpRelay.on();
    }

    if (waterDistanceInCm <= 3) {
      pumpRelay.off();
    }

  }

  // if (solenoidButton.isPush()) {
  //   solenoidRelay.on();
  // }
  // else {
  //   solenoidRelay.off();
  // }

  // if (pumpButton.isPush()) {
  //   pumpRelay.on();
  // }
  // else {
  //   pumpRelay.off();
  // }

  if (waitforLog.done()) {
    noInterrupts();

    // Serial.print("solenoid: ");
    // Serial.print(solenoidButton.isPush());

    Serial.print("distance: ");
    Serial.print(waterDistanceInCm);

    Serial.print(" pump: ");
    Serial.println(pumpRelay.isOn());

    interrupts();
  }

}
