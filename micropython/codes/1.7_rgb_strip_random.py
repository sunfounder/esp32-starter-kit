from machine import Pin
import neopixel
import time
import random

# Set the number of pixels for the running light
num_pixels = 8

# Set the data pin for the RGB LED strip
data_pin = Pin(14, Pin.OUT)

# Initialize the RGB LED strip object
pixels = neopixel.NeoPixel(data_pin, num_pixels)

# Continuously loop the running light
while True:
    for i in range(num_pixels):
        # Generate a random color for the current pixel
        color = (random.randint(0, 255), random.randint(0, 255), random.randint(0, 255))
        
        # Turn on the current pixel with the random color
        pixels[i] = color
        
        # Update the RGB LED strip display
        pixels.write()
        
        # Turn off the current pixel
        pixels[i] = (0, 0, 0)
        
        # Wait for a period of time to control the speed of the running light
        time.sleep_ms(100)