# Import the necessary libraries
import machine
import time

# Set up the LED on pin26 as an output pin
led = machine.Pin(26, machine.Pin.OUT)

# Start an infinite loop
while True:
    # Turn on the LED by setting its value to 1 (HIGH)
    led.value(1)
    # Wait for 1 second (1000 milliseconds) while the LED is on
    time.sleep(1)

    # Turn off the LED by setting its value to 0 (LOW)
    led.value(0)
    # Wait for 0.5 seconds (500 milliseconds) while the LED is off
    time.sleep(0.5)