.. _py_photoresistor:

5.7 Feel the Light
=============================

The photoresistor is a typical device for analog inputs and it is used in a very similar way to a potentiometer. Its resistance value depends on the intensity of the light, the stronger the irradiated light, the smaller its resistance value; conversely, it increases.


* :ref:`cpn_light`

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
        - Photoresistor
        - 1
        - |link_photoresistor_buy|


**Schematic**

|sch_photoresistor|



**Wiring**

|wiring_photoresistor|

**Code**

.. note::

    * Open the ``5.7_feel_the_light.py`` file located in the ``esp32-ultimate-kit\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 

    * For detailed tutorials, please refer to :ref:`open_run_code_py`.

.. code-block:: python

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


After the program runs, the Shell prints out the photoresistor values. You can shine a flashlight on it or cover it up with your hand to see how the value will change.


* ``atten(photoresistor.ATTN_11DB)``: Configure the ADC attenuation to 11dB for full range.

    To read voltages above the reference voltage, apply input attenuation with the atten keyword argument. 

    Valid values (and approximate linear measurement ranges) are:

    * ADC.ATTN_0DB: No attenuation (100mV - 950mV)
    * ADC.ATTN_2_5DB: 2.5dB attenuation (100mV - 1250mV)
    * ADC.ATTN_6DB: 6dB attenuation (150mV - 1750mV)
    * ADC.ATTN_11DB: 11dB attenuation (150mV - 2450mV)

* `machine.ADC - MicroPython Docs <https://docs.micropython.org/en/latest/esp32/quickref.html#adc-analog-to-digital-conversion>`_

