const int potPin = 35; // Potentiometer connected to GPIO14
const int ledPin = 26; // LED connected to GPIO26

// PWM settings
const int freq = 5000; // PWM frequency
const int resolution = 12; // PWM resolution (bits)
const int channel = 0; // PWM channel

void setup() {
  Serial.begin(115200);

  // Configure PWM
  ledcAttach(ledPin, freq, resolution);
}

void loop() {

  int potValue = analogRead(potPin); // read the value of the potentiometer
  uint32_t voltage_mV = analogReadMilliVolts(potPin); // Read the voltage in millivolts

  ledcWrite(ledPin, potValue);

  Serial.print("Potentiometer Value: ");
  Serial.print(potValue);
  Serial.print(", Voltage: ");
  Serial.print(voltage_mV / 1000.0); // Convert millivolts to volts
  Serial.println(" V");

  delay(100);
}
