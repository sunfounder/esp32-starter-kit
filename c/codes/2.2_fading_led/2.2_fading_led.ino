const int ledPin = 26;  // The GPIO pin for the LED
int brightness = 0;
int fadeAmount = 5;

void setup() {
  ledcAttach(ledPin, 5000, 8);  // Attach the LED pin
}

void loop() {
  ledcWrite(ledPin, brightness);  // Write the new brightness value to the PWM pin
  brightness = brightness + fadeAmount;
  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }
  delay(50);  // Wait for 50 milliseconds
}
