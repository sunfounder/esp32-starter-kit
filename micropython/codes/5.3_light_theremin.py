from machine import Pin, PWM, ADC
import time

# Initialize LED pin
led = Pin(26, Pin.OUT)

# Initialize light sensor
sensor = ADC(Pin(35))
sensor.atten(ADC.ATTN_11DB)

# Initialize buzzer
buzzer = PWM(Pin(13), freq=440, duty=0)

light_low=4095
light_high=0

# Map the interval of input values to output values
def interval_mapping(x, in_min, in_max, out_min, out_max):
    return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

# Create a tone using the specified pin, frequency, and duration
def tone(pin,frequency,duration):
    pin.freq(frequency)
    pin.duty(512)
    time.sleep_ms(duration)
    pin.duty(0)

# Calibrate the photoresistor's maximum and minimum values in 5 seconds.
timer_init_start = time.ticks_ms()
led.value(1) # turn on the LED   
while time.ticks_diff(time.ticks_ms(), timer_init_start)<5000:
    light_value = sensor.read()
    if light_value > light_high:
        light_high = light_value
    if light_value < light_low:
        light_low = light_value   
led.value(0) # turn off the LED 

# Play the tones based on the light values
while True:
    light_value  = sensor.read()
    pitch = int(interval_mapping(light_value,light_low,light_high,50,6000))
    if pitch > 50 :
        tone(buzzer,pitch,20)
    time.sleep_ms(10)
