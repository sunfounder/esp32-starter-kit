const int ledPin = 26;  // The GPIO pin for the LED
int brightness = 0;
int fadeAmount = 5;

void setup() {
  ledcSetup(0, 5000, 8);     // Configure the PWM channel (0) with 5000Hz frequency and 8-bit resolution
  ledcAttachPin(ledPin, 0);  // Attach the LED pin to the PWM channel
}

void loop() {
  ledcWrite(0, brightness);  // Write the new brightness value to the PWM channel
  brightness = brightness + fadeAmount;

  if (brightness <= 0 || brightness >= 255) {
    fadeAmount = -fadeAmount;
  }

  delay(50);  // Wait for 20 milliseconds
}
