import machine
import time

# Create a pin object named line, set pin number 14 as input
line = machine.Pin(14, machine.Pin.IN)


while True:
    # Check if the value is 1 (black)
    if line.value() == 1:
        # Print "black"
        print("black")
        time.sleep(0.5)
    # If the value is not 1 (it's 0, which means white)
    else :
        # Print "white"
        print("white")
        time.sleep(0.5)
