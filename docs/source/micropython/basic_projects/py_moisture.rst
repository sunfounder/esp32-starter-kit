.. _py_moisture:

5.9 Measure Soil Moisture
==========================

This capacitive soil moisture sensor is different from most of the resistive sensors on the market, using the principle of capacitive induction to detect soil moisture.

By visually reading the values from the soil moisture sensor, we can gather information about the moisture level in the soil. This information is useful for various applications, such as automatic irrigation systems, plant health monitoring, or environmental sensing projects.


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

.. image:: ../../img/circuit/circuit_5.9_soil_moisture.png

By inserting the module into the soil and watering it, the value read on I35 will decrease.

**Wiring**

.. image:: ../../img/wiring/5.9_moisture_bb.png

* :ref:`cpn_esp32_wroom_32e`
* :ref:`cpn_esp32_camera_extension`
* :ref:`cpn_wires`
* :ref:`cpn_soil_moisture`


**Code**

.. note::

    * Open the ``5.9_moisture.py`` file located in the ``esp32-ultimate-kit-main\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 



.. code-block:: python


    from machine import ADC,Pin
    import time

    # create an ADC object acting on a pin
    moisture = ADC(Pin(35, Pin.IN))

    # Configure the ADC attenuation to 11dB for full range     
    moisture.atten(moisture.ATTN_11DB)

    while True:

        # read a raw analog value in the range 0-4095
        value = moisture.read()  
        print(value)
        time.sleep(0.05)



When the script runs, you will see the soil moisture value in the Shell.

By inserting the module into the soil and watering it, the value of the soil moisture sensor will become smaller.