from machine import Pin, PWM
import time

# Create PWM objects representing the motor control pins and set their frequency to 1000 Hz
motor1A = PWM(Pin(13, Pin.OUT))
motor2A = PWM(Pin(14, Pin.OUT))
motor1A.freq(500)
motor2A.freq(500)

# Enter an infinite loop
while True:
    # Rotate the motor forward by gradually increasing the power on the motor1A pin
    for power in range(0, 1023, 20):
        print(power)
        motor1A.duty(power)
        motor2A.duty(0)
        time.sleep(0.1)
    # Decreasing the power on the motor1A pin
    for power in range(1023, 0, -20):
        print(power)
        motor1A.duty(power)
        motor2A.duty(0)
        time.sleep(0.1)
    # Rotate the motor in the opposite direction by gradually increasing the power on the motor2A pin
    for power in range(0, 1023, 20):
        motor1A.duty(0)
        motor2A.duty(power)
        time.sleep(0.1)
    # Decreasing the power on the motor2A pin
    for power in range(1023, 0, -20):
        motor1A.duty(0)
        motor2A.duty(power)
        time.sleep(0.1)
