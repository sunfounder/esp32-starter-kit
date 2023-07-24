import dht
import machine
import time

# Initialize the DHT11 sensor and connect it to pin 14
sensor = dht.DHT11(machine.Pin(14))

# Loop indefinitely to continuously measure temperature and humidity
while True:
    try:
        # Measure temperature and humidity
        sensor.measure()

        # Get temperature and humidity values
        temp = sensor.temperature()
        humi = sensor.humidity()

        # Print temperature and humidity
        print("Temperature: {}, Humidity: {}".format(temp, humi))

        # Wait for 1 second between measurements
        time.sleep(1)
        
    except Exception as e:
        print("Error: ", e)
        time.sleep(1)
