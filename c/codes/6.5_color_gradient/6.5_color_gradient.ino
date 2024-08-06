// Define RGB LED pins
const int redPin = 27;
const int greenPin = 26;
const int bluePin = 25;

// Define PWM frequency and resolution
const int freq = 5000;
const int resolution = 8;

// Define the pin for the knob
#define KNOB_PIN 14

void setup() {
  Serial.begin(115200);
  ledcAttach(redPin, freq, resolution);
  ledcAttach(greenPin, freq, resolution);
  ledcAttach(bluePin, freq, resolution);
}

void loop() {
  // Read the value of the knob
  int knobValue = analogRead(KNOB_PIN);
  Serial.println(knobValue);
  // Normalize the knob value to the range 0-1
  float hueValue = (float)knobValue / 4095.0;

  // Convert the normalized value to a HUE value (0-360)
  int hue = (int)(hueValue * 360);

  // Convert the HUE value to RGB values
  int red, green, blue;
  HUEtoRGB(hue, &red, &green, &blue);

  // Update the RGB LED with the new color values
  setColor(red, green, blue);
}

void setColor(int red, int green, int blue) {
  ledcWrite(redPin, red);
  ledcWrite(greenPin, green);
  ledcWrite(bluePin, blue);
}

// Convert a HUE value to RGB values
void HUEtoRGB(int hue, int* red, int* green, int* blue) {
  float h = (float)hue / 60.0;
  float c = 1.0;
  float x = c * (1.0 - fabs(fmod(h, 2.0) - 1.0));
  float r, g, b;
  if (h < 1.0) {
    r = c;
    g = x;
    b = 0;
  } else if (h < 2.0) {
    r = x;
    g = c;
    b = 0;
  } else if (h < 3.0) {
    r = 0;
    g = c;
    b = x;
  } else if (h < 4.0) {
    r = 0;
    g = x;
    b = c;
  } else if (h < 5.0) {
    r = x;
    g = 0;
    b = c;
  } else {
    r = c;
    g = 0;
    b = x;
  }
  float m = 1.0 - c;
  *red = (int)((r + m) * 255);
  *green = (int)((g + m) * 255);
  *blue = (int)((b + m) * 255);
}
