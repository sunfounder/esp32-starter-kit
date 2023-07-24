import machine
import time

switch = machine.Pin(14, machine.Pin.IN) # Tilt switch pin
led = machine.Pin(26, machine.Pin.OUT) # LED pin

while True:
    # If the switch is upright
    if switch.value() == 1:
        # Turn on the LED
        led.value(1)
    else:
        # Turn off the LED
        led.value(0)

