int ledPin = 2;
int objectSensorPin = 4;
int potholeSensorPin = 6;

void setup() {
  // Set the LED pin as an output
  pinMode(ledPin, OUTPUT);
  
  // Set the sensors as inputs
  pinMode(objectSensorPin, INPUT);
  pinMode(potholeSensorPin, INPUT);
  
  // Start the serial communication
  Serial.begin(9600);
}

void loop() {
  // Read the values of the sensors
  int objectSensorValue = digitalRead(objectSensorPin);
  int potholeSensorValue = analogRead(potholeSensorPin);
  
  // If an object is detected, turn on the LED
  if (objectSensorValue == HIGH) {
    digitalWrite(ledPin, HIGH);
    Serial.println("Object detected");
  } 
  
  // If a pothole is detected, turn on the LED and print a message to the serial monitor
  if (potholeSensorValue < 500) {
    digitalWrite(ledPin, HIGH);
    Serial.println("Pothole detected");
  } 
  
  // If neither an object nor a pothole is detected, turn off the LED
  if (objectSensorValue == LOW && potholeSensorValue >= 500) {
    digitalWrite(ledPin, LOW);
    Serial.println("No object or pothole detected");
  }
  
  // Wait for 100ms before checking the sensors again
  delay(100);
}