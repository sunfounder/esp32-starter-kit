import dht
import machine
import time
from lcd1602 import LCD

# Initialize the DHT11 sensor and connect it to pin 14
sensor = dht.DHT11(machine.Pin(14))

# Initialize the LCD1602 display
lcd = LCD()

# Loop to measure temperature and humidity
while True:
    try:
        # Measure temperature and humidity
        sensor.measure()

        # Get temperature and humidity values
        temp = sensor.temperature()
        humi = sensor.humidity()

        # Print temperature and humidity
        print("Temperature: {}, Humidity: {}".format(temp, humi))

        # Clear the LCD display
        lcd.clear()

        # Display temperature and humidity on the LCD1602 screen
        lcd.write(0, 0, "Temp: {}\xDFC".format(temp))
        lcd.write(0, 1, "Humi: {}%".format(humi))

        # Wait for 2 seconds before measuring again
        time.sleep(2)

    except Exception as e:
        print("Error: ", e)
        time.sleep(2)
