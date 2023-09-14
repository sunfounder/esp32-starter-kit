# Import the necessary libraries
from machine import Pin, PWM
import time

# Create a PWM object
led = PWM(Pin(26), freq=1000)

while True:
    # Gradually increase brightness
    for duty_cycle in range(0, 1024, 2):
        led.duty(duty_cycle)
        time.sleep(0.01)

    # Gradually decrease brightness
    for duty_cycle in range(1023, -1, -2):
        led.duty(duty_cycle)
        time.sleep(0.01)