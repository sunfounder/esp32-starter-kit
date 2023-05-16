.. _py_moisture:

5.9 Measure Soil Moisture
==========================

In the planting industry, the crops themselves cannot directly obtain the inorganic elements in the soil,
Water in the soil acts as a solvent for dissolving these inorganic elements.

Crops absorb soil moisture through the root system, obtain nutrients, and promote growth.

In the process of crop growth and development, the requirements for soil temperature are also different.
Therefore, a soil moisture sensor is required.


**Schematic**

.. image:: img/circuit_5.4_soil.png

**Wiring**



.. image:: img/measure_the_moisture_bb.jpg
    :width: 800
    :align: center

* :ref:`cpn_uno`
* :ref:`cpn_wires`
* :ref:`cpn_soil_moisture`

**Code**

.. note::

    * Open the ``5.9_moisture.py`` file located in the ``esp32-ultimate-kit\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 

    * For detailed tutorials, please refer to :ref:`open_run_code_py`.

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