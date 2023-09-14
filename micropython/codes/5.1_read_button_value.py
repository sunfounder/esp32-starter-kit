import machine
import time

button = machine.Pin(14, machine.Pin.IN) # Button pin
led = machine.Pin(26, machine.Pin.OUT) # LED pin


while True:
    
    print(button.value())
    time.sleep_ms(5)
    # If the button is pressed
    if button.value() == 1:
        # Turn on the LED by setting its value to 1
        led.value(1)
#         time.sleep(0.5)
    else:
        # Turn off the LED
        led.value(0)
