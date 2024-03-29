import machine
import time

# Create Pin objects representing the motor control pins and set them to output mode
motor1A = machine.Pin(13, machine.Pin.OUT)
motor2A = machine.Pin(14, machine.Pin.OUT)

# Define a function to rotate the pump
def rotate():
    motor1A.value(1)
    motor2A.value(0)

# Define a function to stop the pump
def stop():
    motor1A.value(0)
    motor2A.value(0)

try:
    while True:
        rotate()  # Rotate the motor clockwise
        time.sleep(5)  # Pause for 5 seconds
        stop()  # Stop the motor
        time.sleep(2)

except KeyboardInterrupt:
    stop()  # Stop the motor when KeyboardInterrupt is caught