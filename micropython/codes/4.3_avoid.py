import machine
import time

ir_avoid = machine.Pin(14, machine.Pin.IN, machine.Pin.PULL_UP) # avoid module pin

while True:

    # Print values of the obstacle avoidance module 
    print(ir_avoid.value()) 
    time.sleep(0.1)
