from machine import ADC,Pin
import time

xAxis = ADC(Pin(34, Pin.IN)) # create an ADC object acting on a pin      
xAxis.atten(xAxis.ATTN_11DB)
yAxis = ADC(Pin(35, Pin.IN)) # create an ADC object acting on a pin      
yAxis.atten(yAxis.ATTN_11DB)
button = Pin(33, Pin.IN, Pin.PULL_UP)

while True:
    xValue = xAxis.read()  # read a raw analog value in the range 0-4095
    yValue = yAxis.read()  # read a raw analog value in the range 0-4095
    btnValue = button.value()
    print(f"X:{xValue}, Y:{yValue}, Button:{btnValue}")
    time.sleep(0.1)





