.. _py_photoresistor:

5.7 Feel the Light
=============================

The photoresistor is a commonly used device for analog inputs, similar to a potentiometer. Its resistance value changes based on the intensity of the light it receives. When exposed to strong light, the resistance of the photoresistor decreases, and as the light intensity decreases, the resistance increases.

By reading the value of the photoresistor, we can gather information about the ambient light conditions. This information can be used for tasks such as controlling the brightness of an LED, adjusting the sensitivity of a sensor, or implementing light-dependent actions in a project.

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

.. image:: ../../img/circuit/circuit_5.7_photoresistor.png

As the light intensity increases, the resistance of the light-dependent resistor (LDR) decreases, resulting in a decrease in the value read on I35.

**Wiring**

.. image:: ../../img/wiring/5.7_photoresistor_bb.png

* :ref:`cpn_esp32_wroom_32e`
* :ref:`cpn_esp32_camera_extension`
* :ref:`cpn_breadboard`
* :ref:`cpn_wires`
* :ref:`cpn_resistor`
* :ref:`cpn_photoresistor`


**Code**

.. note::

    * Open the ``5.7_feel_the_light.py`` file located in the ``esp32-ultimate-kit-main\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 



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

