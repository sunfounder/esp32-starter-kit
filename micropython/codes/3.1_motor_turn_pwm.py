from machine import Pin, PWM
import time

# Create PWM objects representing the motor control pins and set their frequency to 1000 Hz
B_1A = PWM(Pin(13, Pin.OUT))
B_1B = PWM(Pin(14, Pin.OUT))
B_1A.freq(500)
B_1B.freq(500)

# Enter an infinite loop
while True:
    # Rotate the motor forward by gradually increasing the power on the B_1A pin
    for power in range(0, 1023, 20):
        print(power)
        B_1A.duty(power)
        B_1B.duty(0)
        time.sleep(0.1)
    # Decreasing the power on the B_1A pin
    for power in range(1023, 0, -20):
        print(power)
        B_1A.duty(power)
        B_1B.duty(0)
        time.sleep(0.1)
    # Rotate the motor in the opposite direction by gradually increasing the power on the B_1B pin
    for power in range(0, 1023, 20):
        B_1A.duty(0)
        B_1B.duty(power)
        time.sleep(0.1)
    # Decreasing the power on the B_1B pin
    for power in range(1023, 0, -20):
        B_1A.duty(0)
        B_1B.duty(power)
        time.sleep(0.1)
