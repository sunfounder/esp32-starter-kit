# Import the necessary libraries
from machine import ADC, Pin
import time
import math

# Define the beta value of the thermistor, typically provided in the datasheet
beta = 3950

# Create an ADC object (thermistor)
thermistor = ADC(Pin(35, Pin.IN))

# Set the attenuation
thermistor.atten(thermistor.ATTN_11DB)

# Start an infinite loop to continuously monitor the temperature
while True:
    # Read the voltage in microvolts and convert it to volts
    Vr = thermistor.read_uv() / 1000000

    # Calculate the resistance of the thermistor based on the measured voltage
    Rt = 10000 * Vr / (3.3 - Vr)

    # Use the beta parameter and resistance value to calculate the temperature in Kelvin
    temp = 1 / (((math.log(Rt / 10000)) / beta) + (1 / (273.15 + 25)))

    # Convert to Celsius
    Cel = temp - 273.15

    # Convert to Fahrenheit
    Fah = Cel * 1.8 + 32

    # Print the temperature values in both Celsius and Fahrenheit
    print('Celsius: %.2f C  Fahrenheit: %.2f F' % (Cel, Fah))
    time.sleep(0.5)
