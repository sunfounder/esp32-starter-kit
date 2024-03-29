from machine import ADC, Pin
import time
import dht
from lcd1602 import LCD

# DHT11
dht11 = dht.DHT11(Pin(13))

# Soil moisture
moisture_pin = ADC(Pin(14))
moisture_pin.atten(ADC.ATTN_11DB)

# Photoresistor
photoresistor = ADC(Pin(35))
photoresistor.atten(ADC.ATTN_11DB)

# Button and pump
button = Pin(32, Pin.IN)

motor1A = Pin(27, Pin.OUT)
motor2A = Pin(26, Pin.OUT)

# I2C LCD1602 setup
lcd = LCD()

# Rotate the pump
def rotate():
    motor1A.value(1)
    motor2A.value(0)

# Stop the pump
def stop():
    motor1A.value(0)
    motor2A.value(0)

button_state = False

# Define the button callback function to toggle the button state
def button_callback(pin):
    global button_state
    button_state = not button_state

# Attach the button callback function to the rising edge of the button pin
button.irq(trigger=Pin.IRQ_RISING, handler=button_callback)

page = 0
temp = 0
humi = 0
       
try:
    while True:
        
        # If the button is pressed and button state is True
        if button_state:
            print("rotate")
            rotate()

        # If the button is pressed again and button state is False
        if not button_state:
            print("stop")
            stop()
        time.sleep(2)

        # Clear the LCD display
        lcd.clear()
        
        # Toggle the value of the page variable between 0 and 1
        page=(page+1)%2
        
        # When page is 1, display temperature and humidity on the LCD1602
        if page is 1:
            try:
                # Measure temperature and humidity
                dht11.measure()

                # Get temperature and humidity values
                temp = dht11.temperature()
                humi = dht11.humidity()
            except Exception as e:
                print("Error: ", e)         

            # Display temperature and humidity
            lcd.write(0, 0, "Temp: {}\xDFC".format(temp))
            lcd.write(0, 1, "Humi: {}%".format(humi))

        # If page is 0, display the soil moisture and light
        else:
            light = photoresistor.read()
            moisture = moisture_pin.read()

            # Clear the LCD display
            lcd.clear()

            # Display the value of soil moisture and light
            lcd.write(0, 0, f"Moisture: {moisture}")
            lcd.write(0, 1, f"Light: {light}")

except KeyboardInterrupt:
    # Stop the motor when KeyboardInterrupt is caught
    stop()
