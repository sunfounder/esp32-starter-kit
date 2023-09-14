#define motor1A 13
#define motor2A 14

// PWM settings
const int freq = 500; // PWM frequency: 500 Hz
const int resolution = 8; // PWM resolution: 8 bits
const int channelA = 0; // PWM channel for motor1A: 0
const int channelB = 1; // PWM channel for motor2A: 1


void setup() {
  // Set up PWM
  ledcSetup(channelA, freq, resolution);
  ledcSetup(channelB, freq, resolution);

  // Attach PWM channels to GPIO pins
  ledcAttachPin(motor1A, channelA);
  ledcAttachPin(motor2A, channelB);

  Serial.begin(115200);
}

void loop() {
  // Increase speed gradually
  for (int dutyCycle = 0; dutyCycle <= 255; dutyCycle++) {
    Serial.println(dutyCycle);
    ledcWrite(channelA, dutyCycle);
    ledcWrite(channelB, 0);
    delay(50);
  }

  delay(2000);

  // Decrease speed gradually
  for (int dutyCycle = 255; dutyCycle >= 0; dutyCycle--) {
    Serial.println(dutyCycle);
    ledcWrite(channelA, dutyCycle);
    ledcWrite(channelB, 0);
    delay(50);
  }
  
  delay(2000);
}
