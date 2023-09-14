from machine import Pin, PWM
import time

# Define the GPIO pins for the RGB LED
RED_PIN = 27
GREEN_PIN = 26
BLUE_PIN = 25

# Set up the PWM channels
red = PWM(Pin(RED_PIN))
green = PWM(Pin(GREEN_PIN))
blue = PWM(Pin(BLUE_PIN))

# Set the PWM frequency
red.freq(1000)
green.freq(1000)
blue.freq(1000)

def set_color(r, g, b):
    red.duty(r)
    green.duty(g)
    blue.duty(b)

while True:
    # Set different colors and wait for a while
    set_color(1023, 0, 0) # Red
    time.sleep(1)
    set_color(0, 1023, 0) # Green
    time.sleep(1)
    set_color(0, 0, 1023) # Blue
    time.sleep(1)
    set_color(1023, 0, 1023) # purple
    time.sleep(1)
