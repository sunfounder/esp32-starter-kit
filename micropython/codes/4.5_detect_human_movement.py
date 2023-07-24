import machine
import time

# Define pins
PIR_PIN = 14    # PIR sensor
LED_PIN = 26    # LED

# Initialize the PIR sensor pin as an input pin
pir_sensor = machine.Pin(PIR_PIN, machine.Pin.IN, machine.Pin.PULL_DOWN)
# Initialize the LED pin as an output pin
led = machine.Pin(LED_PIN, machine.Pin.OUT)

# Global flag to indicate motion detected
motion_detected_flag = False

# Function to handle the interrupt
def motion_detected(pin):
    global motion_detected_flag
    print("Motion detected!")
    motion_detected_flag = True

# Attach the interrupt to the PIR sensor pin
pir_sensor.irq(trigger=machine.Pin.IRQ_RISING, handler=motion_detected)

# Main loop
while True:
    if motion_detected_flag:
        led.value(1)  # Turn on the LED
        time.sleep(5)  # Keep the LED on for 5 seconds
        led.value(0)  # Turn off the LED
        motion_detected_flag = False
