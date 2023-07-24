from machine import ADC,Pin
import time

# create an ADC object acting on a pin
photoresistor = ADC(Pin(35, Pin.IN))

# Configure the ADC attenuation to 11dB for full range     
photoresistor.atten(photoresistor.ATTN_11DB)

while True:

    # read a raw analog value in the range 0-4095
    value = photoresistor.read()  
    print(value)
    time.sleep(0.05)