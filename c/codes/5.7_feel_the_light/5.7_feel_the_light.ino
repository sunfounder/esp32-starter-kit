
void setup() {
  // initialize serial communication at 115200 bits per second:
  Serial.begin(115200);

}

void loop() {
  // read the analog value
  int analogValue = analogRead(35);
  
  // print out the values you read:
  Serial.printf("ADC analog value = %d\n",analogValue);
  
  delay(100);  // delay in between reads for clear read from serial
}
