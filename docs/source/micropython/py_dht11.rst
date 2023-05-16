.. _py_dht11:

5.13 Temperature - Humidity
=======================================


Humidity and temperature are closely related from the physical quantity itself to the actual people's life.
The temperature and humidity of human environment will directly affect the thermoregulatory function and heat transfer effect of human body.
It will further affect the thinking activity and mental state, thus affecting the efficiency of our study and work.

Temperature is one of the seven basic physical quantities in the International System of Units, which is used to measure the degree of hot and cold of an object.
Celsius is one of the more widely used temperature scales in the world, expressed by the symbol "℃".

Humidity is the concentration of water vapor present in the air.
The relative humidity of air is commonly used in life and is expressed in %RH. Relative humidity is closely related to temperature.
For a certain volume of sealed gas, the higher the temperature, the lower the relative humidity, and the lower the temperature, the higher the relative humidity.

|img_Dht11|

A basic digital temperature and humidity sensor, the **DHT11**, is provided in this kit.
It uses a capacitive humidity sensor and thermistor to measure the surrounding air and outputs a digital signal on the data pins (no analog input pins are required).

* :ref:`cpn_dht11`

**Bill of Materials**

In this project, we need the following components. 

It's definitely convenient to buy a whole kit, here's the link: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - Kepler Kit	
        - 450+
        - |link_kepler_kit|

You can also buy them separately from the links below.


.. list-table::
    :widths: 5 20 5 20
    :header-rows: 1

    *   - SN
        - COMPONENT	
        - QUANTITY
        - LINK

    *   - 1
        - Raspberry Pi Pico W
        - 1
        - |link_picow_buy|
    *   - 2
        - Micro USB Cable
        - 1
        - 
    *   - 3
        - Breadboard
        - 1
        - |link_breadboard_buy|
    *   - 4
        - Wires
        - Several
        - |link_wires_buy|
    *   - 5
        - Temperature and Humidity Sensor
        - 1
        - |link_dht22_buy|

**Schematic**

|sch_dht11|


**Wiring**


|wiring_dht11|

**Code**

.. note::

    * Open the ``5.13_dht11.py`` file located in the ``esp32-ultimate-kit\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 

    * For detailed tutorials, please refer to :ref:`open_run_code_py`. 
    
    * Here you need to use the library called ``dht.py``, please check if it has been uploaded to Pico W, for a detailed tutorial refer to :ref:`add_libraries_py`.

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

.. note::

    * Open the ``5.13_dht11_lcd.py`` file located in the ``esp32-ultimate-kit\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
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

