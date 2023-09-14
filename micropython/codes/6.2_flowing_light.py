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

# Initialize the avoid sensor
avoid = Pin(25, Pin.IN)

# Continuously loop the running light
while True:
    
    # Read the input from the infrared sensor
    avoid_value = avoid.value()
    
    # Generate a random color for the current pixel
    color = (random.randint(0, 255), random.randint(0, 255), random.randint(0, 255))
            
    # If no obstacle is detected
    if avoid_value:
        for i in range(num_pixels):
            
            # Turn on the current pixel with the random color
            pixels[i] = color
            
            # Update the RGB LED strip display
            pixels.write()
            
            # Turn off the current pixel
            pixels[i] = (0, 0, 0)
            time.sleep_ms(100)
            
    # If detects an obstacle, change the direction of the LED strip
    else:
        for i in range(num_pixels-1, -1, -1):
            
            pixels[i] = color
            pixels.write()
            pixels[i] = (0, 0, 0)
            time.sleep_ms(100)