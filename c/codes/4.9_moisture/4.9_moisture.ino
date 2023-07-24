void setup() {
  // Initialize serial communication at 115200 bits per second:
  Serial.begin(115200);
}

void loop() {
  // Read the analog value
  int analogValue = analogRead(35);
  
  // Print out the values
  Serial.printf("Analog value = %d\n",analogValue);
  
  delay(300);  // delay between reads for clear read from serial monitor
}
