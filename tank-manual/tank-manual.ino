// Control a solenoid and pump
// with buttons using attachInterrupt 

#define SOLENOID_BUTTON_PIN 2
#define SOLENOID_RELAY_PIN 6
#define PUMP_BUTTON_PIN 3
#define PUMP_RELAY_PIN 7

bool volatile isSolenoidOpen = false;
unsigned long volatile lastSolenoidPush;

bool volatile isPumpWorking = false;
unsigned long volatile lastPumpPush;

const int debounceTime = 500;

void toggleSolenoid() {
  unsigned long nowPush = millis();
  unsigned long pushGap = nowPush - lastSolenoidPush;

  if (pushGap > debounceTime) {
    isSolenoidOpen = !isSolenoidOpen;
  }
  lastSolenoidPush = nowPush;
}

void togglePump() {
  unsigned long nowPush = millis();
  unsigned long pushGap = nowPush - lastPumpPush;

  if (pushGap > debounceTime) {
    isPumpWorking = !isPumpWorking;
  }
  lastPumpPush = nowPush;
}

void setup() {
  Serial.begin(9600);

  pinMode(SOLENOID_BUTTON_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(SOLENOID_BUTTON_PIN), toggleSolenoid, FALLING);
  pinMode(SOLENOID_RELAY_PIN, OUTPUT);
  digitalWrite(SOLENOID_RELAY_PIN, HIGH);

  pinMode(PUMP_BUTTON_PIN, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PUMP_BUTTON_PIN), togglePump, FALLING);
  pinMode(PUMP_RELAY_PIN, OUTPUT);
  digitalWrite(PUMP_RELAY_PIN, HIGH);
}

void loop()
{
  interrupts();

  if (isSolenoidOpen) {
    digitalWrite(SOLENOID_RELAY_PIN, LOW);
  }
  else {
    digitalWrite(SOLENOID_RELAY_PIN, HIGH);
  }

  if (isPumpWorking) {
    digitalWrite(PUMP_RELAY_PIN, LOW);
  }
  else {
    digitalWrite(PUMP_RELAY_PIN, HIGH);
  }

  delay(500);

  noInterrupts();

  Serial.print("solenoid: ");
  Serial.print(isSolenoidOpen);

  Serial.print(" pump: ");
  Serial.println(isPumpWorking);
}