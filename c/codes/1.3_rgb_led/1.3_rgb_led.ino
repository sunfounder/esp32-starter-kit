// Define RGB LED pins
const int redPin = 27;
const int greenPin = 26;
const int bluePin = 25;

// Define PWM channels
const int redChannel = 0;
const int greenChannel = 1;
const int blueChannel = 2;

// Define PWM frequency and resolution
const int freq = 5000;
const int resolution = 8;

void setup() {
  // Set up PWM channels
  ledcSetup(redChannel, freq, resolution);
  ledcSetup(greenChannel, freq, resolution);
  ledcSetup(blueChannel, freq, resolution);

  // Attach pins to corresponding PWM channels
  ledcAttachPin(redPin, redChannel);
  ledcAttachPin(greenPin, greenChannel);
  ledcAttachPin(bluePin, blueChannel);
}

void loop() {
  setColor(255, 0, 0); // Red
  delay(1000);
  setColor(0, 255, 0); // Green
  delay(1000);
  setColor(0, 0, 255); // Blue
  delay(1000);
  setColor(255, 255, 0); // Yellow
  delay(1000);
  setColor(80, 0, 80); // Purple
  delay(1000);
  setColor(0, 255, 255); // Cyan
  delay(1000);
}

void setColor(int red, int green, int blue) {
  // For common-anode RGB LEDs, use 255 minus the color value
  ledcWrite(redChannel, red);
  ledcWrite(greenChannel, green);
  ledcWrite(blueChannel, blue);
}
