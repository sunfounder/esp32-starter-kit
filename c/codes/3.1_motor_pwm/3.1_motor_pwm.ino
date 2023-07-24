#define B_1A 13
#define B_1B 14

// PWM settings
const int freq = 500; // PWM frequency: 5000 Hz
const int resolution = 8; // PWM resolution: 8 bits
const int channelA = 0; // PWM channel for B_1A: 0
const int channelB = 1; // PWM channel for B_1B: 1


void setup() {
  // Set up PWM
  ledcSetup(channelA, freq, resolution);
  ledcSetup(channelB, freq, resolution);

  // Attach PWM channels to GPIO pins
  ledcAttachPin(B_1A, channelA);
  ledcAttachPin(B_1B, channelB);
}

void loop() {
  // Increase speed gradually
  for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
    ledcWrite(channelA, dutyCycle);
    ledcWrite(channelB, 0);
    delay(50);
  }

  delay(2000);

  // Decrease speed gradually
  for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
    ledcWrite(channelA, dutyCycle);
    ledcWrite(channelB, 0);
    delay(50);
  }
  
  delay(2000);
}
