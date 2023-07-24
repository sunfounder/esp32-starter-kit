import machine
import time

# Create a Pin object representing pin 14 and set it to output mode
buzzer = machine.Pin(14, machine.Pin.OUT)

# Enter an infinite loop
while True:
    # Iterate over the values 0 to 3 using a for loop
    for i in range(4):
        # Turn on the buzzer by setting its value to 1
        buzzer.value(1)
        # Pause for 0.2 seconds
        time.sleep(0.2)
        # Turn off the buzzer
        buzzer.value(0)
        # Pause for 0.2 seconds
        time.sleep(0.2)
    # Pause for 1 second before restarting the for loop
    time.sleep(1)
