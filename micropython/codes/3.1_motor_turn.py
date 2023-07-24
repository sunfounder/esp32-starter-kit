import machine
import time

# Create Pin objects representing the motor control pins and set them to output mode
B_1A = machine.Pin(13, machine.Pin.OUT)
B_1B = machine.Pin(14, machine.Pin.OUT)

# Define a function to rotate the motor clockwise
def clockwise():
    B_1A.value(1)
    B_1B.value(0)

# Define a function to rotate the motor anticlockwise
def anticlockwise():
    B_1A.value(0)
    B_1B.value(1)

# Define a function to stop the motor
def stop():
    B_1A.value(0)
    B_1B.value(0)

# Enter an infinite loop

try:
    while True:
        clockwise() # Rotate the motor clockwise
        time.sleep(1) # Pause for 1 second
        anticlockwise() # Rotate the motor anticlockwise
        time.sleep(1)
        stop() # Stop the motor
        time.sleep(2)

except KeyboardInterrupt:
    stop()  # Stop the motor when KeyboardInterrupt is caught