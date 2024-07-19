int sensorPin = A0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  int level = analogRead(sensorPin); //Read data from analog pin and store it to resval variable
   
  Serial.println(level); 

  delay(1000); 
}
