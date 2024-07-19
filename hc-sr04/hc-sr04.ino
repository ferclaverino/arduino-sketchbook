#include "HCSR04.h"

const int Trigger = 2;   //Pin digital 2 para el Trigger del sensor
const int Echo = 3;   //Pin digital 3 para el Echo del sensor

HCSR04 distanceSensor(2, 3);

void setup() {
  Serial.begin(9600);
  distanceSensor.begin();
}

void loop()
{

  unsigned int distance = distanceSensor.getDistanceInCm();

  Serial.print(" Distancia: ");
  Serial.print(distance);
  Serial.print(" cm");
  Serial.println();
  delay(500);          //Hacemos una pausa de 100ms
}