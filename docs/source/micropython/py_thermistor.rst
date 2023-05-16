.. _py_temp:


5.10 Thermometer
===========================

A thermometer is a device that measures temperature or a temperature gradient (the degree of hotness or coldness of an object). 
A thermometer has two important elements: (1) a temperature sensor (e.g. the bulb of a mercury-in-glass thermometer or the pyrometric sensor in an infrared thermometer) in which some change occurs with a change in temperature; 
and (2) some means of converting this change into a numerical value (e.g. the visible scale that is marked on a mercury-in-glass thermometer or the digital readout on an infrared model). 
Thermometers are widely used in technology and industry to monitor processes, in meteorology, in medicine, and in scientific research.



A thermistor is a type of temperature sensor whose resistance is strongly dependent on temperature, and it has two types: 
Negative Temperature Coefficient (NTC) and Positive Temperature Coefficient (PTC), 
also known as NTC and PTC. The resistance of PTC thermistor increases with temperature, while the condition of NTC is opposite to the former.

In this experiment we use an **NTC thermistor** to make a thermometer.


* :ref:`cpn_temp`

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
        - Resistor
        - 1(10KΩ)
        - |link_resistor_buy|
    *   - 6
        - Thermistor
        - 1
        - |link_thermistor_buy|


**Schematic**

|sch_temp|

In this circuit, the 10K resistor and the thermistor are connected in series, and the current passing through them is the same. The 10K resistor acts as a protection, and the GP28 reads the value after the voltage conversion of the thermistor.

When the temperature increases, the resistance value of NTC thermistor decreases, then its voltage decreases, so the value from GP28 will decrease; If the temperature is high enough, the resistance of the thermistor will be close to 0, and the value of GP28 will be close to 0. At this time, the 10K resistor plays a protective role, so that 3.3V and GND are not connected together, resulting in a short circuit.

When the temperature drops, the value of GP28 will increase. When the temperature is low enough, the resistance of the thermistor will be infinite, and its voltage will be close to 3.3v (the 10K resistor is negligible), and the value of GP28 will be close to the maximum value of 65535.


The calculation formula is shown below.

    (Vp/3.3V) x 65535 = Ap


**Wiring**

热敏电阻接GND, 10K电阻接3.3v
|wiring_temp|


.. note::
    * The thermistor is black and marked 103.
    * The color ring of the 10K ohm resistor is red, black, black, red and brown.

**Code**

.. note::

    * Open the ``5.10_thermistor.py`` file located in the ``esp32-ultimate-kit\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 

    * For detailed tutorials, please refer to :ref:`open_run_code_py`.


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

    **RT =RN expB(1/TK – 1/TN)** 

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

.. note::

    * Open the ``5.10_thermistor_lcd.py`` file located in the ``esp32-ultimate-kit\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 
    * For detailed tutorials, please refer to :ref:`open_run_code_py`.
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


