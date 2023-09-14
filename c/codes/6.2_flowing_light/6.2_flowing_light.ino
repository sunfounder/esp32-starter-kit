#include <Adafruit_NeoPixel.h>

// Set the number of pixels for the running light
#define NUM_PIXELS 8

// Set the data pin for the RGB LED strip
#define DATA_PIN 14

// Initialize the RGB LED strip object
Adafruit_NeoPixel pixels(NUM_PIXELS, DATA_PIN, NEO_GRB + NEO_KHZ800);

// Initialize the avoid sensor
#define AVOID_PIN 25

void setup() {
  // Initialize the RGB LED strip
  pixels.begin();

  // Initialize the avoid sensor
  pinMode(AVOID_PIN, INPUT_PULLUP);

  // Set the initial LED color
  uint32_t color = pixels.Color(random(256), random(256), random(256));
  pixels.fill(color);
  pixels.show();
}

void loop() {
  // Read the input from the infrared sensor
  bool avoid_value = digitalRead(AVOID_PIN);

  // Generate a random color for the current pixel
  uint32_t color = pixels.Color(random(256), random(256), random(256));

  // If no obstacle is detected
  if (avoid_value) {
    for (int i = 0; i < NUM_PIXELS; i++) {
      // Turn on the current pixel with the random color
      pixels.setPixelColor(i, color);

      // Update the RGB LED strip display
      pixels.show();

      // Turn off the current pixel
      pixels.setPixelColor(i, 0);
      delay(100);
    }
  }
  // If detects an obstacle, change the direction of the LED strip
  else {
    for (int i = NUM_PIXELS - 1; i >= 0; i--) {
      pixels.setPixelColor(i, color);
      pixels.show();
      pixels.setPixelColor(i, 0);
      delay(100);
    }
  }
}