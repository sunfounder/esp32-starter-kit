from machine import ADC, Pin, PWM
import time

pot = ADC(Pin(35, Pin.IN)) # create an ADC object acting on a pin      

# Configure the ADC attenuation to 11dB for full range
pot.atten(pot.ATTN_11DB)

# Create a PWM object
led = PWM(Pin(26), freq=1000)

while True:
    # Read a raw analog value in the range of 0-4095
    value = pot.read()

    # Scale the value to the range of 0-1023 for ESP32 PWM duty cycle
    pwm_value = int(value * 1023 / 4095)

    # Update the LED brightness based on the potentiometer value
    led.duty(pwm_value)

    # Read the voltage in microvolts and convert it to volts
    voltage = pot.read_uv() / 1000000

    # Print the raw value and the voltage
    print(f"value: {value}, Voltage: {voltage}V")

    # Wait for 0.5 seconds before taking the next reading
    time.sleep(0.5)