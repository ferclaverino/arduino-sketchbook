const byte sensorPin = 2;
volatile int count = 0;

void incrementCounter() {
  count++;
}

void setup() {
  Serial.begin(9600);

  // pull up works with falling
  pinMode(sensorPin, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(sensorPin), incrementCounter, FALLING);

  // normal works with rising
  // pinMode(sensorPin, INPUT);
  // attachInterrupt(digitalPinToInterrupt(sensorPin), incrementCounter, RISING);

}

void loop() {
  delay(1000);

  Serial.print(count, DEC);
  Serial.println(" vueltas ");
}
