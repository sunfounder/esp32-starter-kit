#include <Adafruit_NeoPixel.h> // Include the Adafruit NeoPixel library

#define LED_PIN 14 // NeoPixel LED strip
#define NUM_LEDS 8 // Number of LEDs

// Create an instance of the Adafruit_NeoPixel class
Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800); 

void setup() {
  strip.begin(); // Initialize the NeoPixel strip
  strip.show(); // Set initial color to black
}

void loop() {
  // Turn on LEDs one by one
  for (int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, 100, 45, 0); // Set the color of the i-th LED to red
    strip.show(); // Update the LED strip with the new colors
    delay(100); // Wait for 100 milliseconds
  }
  
  // Turn off LEDs one by one
  for (int i = 0; i < NUM_LEDS; i++) {
    strip.setPixelColor(i, 0, 0, 0); // Set the color of the i-th LED to black (turn it off)
    strip.show(); // Update the LED strip with the new colors
    delay(100); // Wait for 100 milliseconds
  }
}
