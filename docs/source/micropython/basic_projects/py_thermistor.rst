.. _py_temp:


4.10 Temperature Sensing
===========================

A thermistor is a temperature sensor that exhibits a strong dependence on temperature, and it can be classified into two types: Negative Temperature Coefficient (NTC) and Positive Temperature Coefficient (PTC). The resistance of an NTC thermistor decreases with increasing temperature, while the resistance of a PTC thermistor increases with increasing temperature.

In this project, we will be using an NTC thermistor. By connecting the NTC thermistor to an analog input pin of the ESP32 microcontroller, we can measure its resistance, which is directly proportional to the temperature.

By incorporating the NTC thermistor and performing the necessary calculations, we can accurately measure the temperature and display it on the I2C LCD1602 module. This project enables real-time temperature monitoring and provides a visual interface for temperature display.

**Available Pins**

* **Available Pins**

    Here is a list of available pins on the ESP32 board for this project.

    .. list-table::
        :widths: 5 15

        *   - Available Pins
            - IO14, IO25, I35, I34, I39, I36


* **Strapping Pins**

    The following pins are strapping pins, which affect the startup process of the ESP32 during power on or reset. However, once the ESP32 is booted up successfully, they can be used as regular pins.

    .. list-table::
        :widths: 5 15

        *   - Strapping Pins
            - IO0, IO12


**Schematic**

.. image:: ../../img/circuit/circuit_5.10_thermistor.png

When the temperature rises, the resistance of the thermistor decreases, causing the value read on I35 to decrease. Additionally, by using a formula, you can convert the analog value into temperature and then print it out.

**Wiring**

.. image:: ../../img/wiring/5.10_thermistor_bb.png


.. note::
    * The thermistor is black and marked 103.
    * The color ring of the 10K ohm resistor is red, black, black, red and brown.

* :ref:`cpn_esp32_extension`
* :ref:`cpn_breadboard`
* :ref:`cpn_wires`
* :ref:`cpn_resistor`
* :ref:`cpn_thermistor`

**Code**

.. note::

    * Open the ``4.10_thermistor.py`` file located in the ``esp32-ultimate-kit-main\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 




.. code-block:: python

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

When the code is run, the Shell will print out the Celsius and Fahrenheit temperatures.

**How it works?**

Each thermistor has a normal resistance. Here it is 10k ohm, which is measured under 25 degree Celsius. 

When the temperature gets higher, the resistance of the thermistor decreases. Then the voltage data is converted to digital quantities by the A/D adapter. 

The temperature in Celsius or Fahrenheit is output via programming. 

Here is the relation between the resistance and temperature: 

    **RT =RN expB(1/TK - 1/TN)** 

    * **RT** is the resistance of the NTC thermistor when the temperature is **TK**. 
    * **RN** is the resistance of the NTC thermistor under the rated temperature TN. Here, the numerical value of RN is 10k. 
    * **TK** is a Kelvin temperature and the unit is K. Here, the numerical value of **TK** is ``273.15 + degree Celsius``. 
    * **TN** is a rated Kelvin temperature; the unit is K too. Here, the numerical value of TN is ``273.15+25``.
    * And **B(beta)**, the material constant of NTC thermistor, is also called heat sensitivity index with a numerical value ``3950``. 
    * **exp** is the abbreviation of exponential, and the base number ``e`` is a natural number and equals 2.7 approximately. 

    Convert this formula ``TK=1/(ln(RT/RN)/B+1/TN)`` to get Kelvin temperature that minus 273.15 equals degree Celsius. 

    This relation is an empirical formula. It is accurate only when the temperature and resistance are within the effective range.


**Learn More**

You can also display the calculated Celsius and Fahrenheit temperatures on the I2C LCD1602.

.. image:: ../../img/wiring/5.10_thermistor_lcd_bb.png

.. note::

    * Open the ``4.10_thermistor_lcd.py`` file located in the ``esp32-ultimate-kit-main\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 

    * Here you need to use the library called ``lcd1602.py``, please check if it has been uploaded to ESP32, for a detailed tutorial refer to :ref:`add_libraries_py`.


.. code-block:: python

    # Import the necessary libraries
    from machine import ADC, Pin
    from lcd1602 import LCD
    import time
    import math

    # Define the beta value of the thermistor, typically provided in the datasheet
    beta = 3950

    # Create an ADC object (thermistor)
    thermistor = ADC(Pin(35, Pin.IN))

    # Set the attenuation
    thermistor.atten(thermistor.ATTN_11DB)

    lcd = LCD()

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

        # Clear the LCD screen
        lcd.clear()
        
        # Display the temperature values in both Celsius and Fahrenheit
        lcd.message('Cel: %.2f \xDFC \n' % Cel)
        lcd.message('Fah: %.2f \xDFF' % Fah)
        time.sleep(1)


