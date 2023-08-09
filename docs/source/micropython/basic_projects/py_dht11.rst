.. _py_dht11:

5.13 Temperature - Humidity
=======================================
The DHT11 is a temperature and humidity sensor commonly used for environmental measurements. It is a digital sensor that communicates with a microcontroller to provide temperature and humidity readings.

In this project, we will be reading the DHT11 sensor and printing out the temperature and humidity values it detects.

By reading the data provided by the sensor, we can obtain the current temperature and humidity values in the environment. These values can be used for real-time monitoring of environmental conditions, weather observations, indoor climate control, humidity reports, and more.


* **Available Pins**

    Here is a list of available pins on the ESP32 board for this project.

    .. list-table::
        :widths: 5 20

        *   - Available Pins
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**Schematic**

.. image:: ../../img/circuit/circuit_5.13_dht11.png


**Wiring**

.. image:: ../../img/wiring/5.13_dht11_bb.png

* :ref:`cpn_esp32_wroom_32e`
* :ref:`cpn_esp32_camera_extension`
* :ref:`cpn_breadboard`
* :ref:`cpn_wires`
* :ref:`cpn_dht11`

**Code**

.. note::

    * Open the ``5.13_dht11.py`` file located in the ``esp32-starter-kit-main\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 

.. code-block:: python

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


When the code is running, you will see the Shell continuously print out the temperature and humidity, and as the program runs steadily, these two values will become more and more accurate.


**Learn More**

You can also display the temperature and humidity on the I2C LCD1602.

.. image:: ../../img/wiring/5.13_dht11_lcd_bb.png

.. note::

    * Open the ``5.13_dht11_lcd.py`` file located in the ``esp32-starter-kit-main\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 
    * Here you need to use the library called ``lcd1602.py``, please check if it has been uploaded to ESP32, for a detailed tutorial refer to :ref:`add_libraries_py`.


.. code-block:: python

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

