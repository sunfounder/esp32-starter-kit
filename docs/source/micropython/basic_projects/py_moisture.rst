.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _py_moisture:

5.9 Measure Soil Moisture
==========================

This capacitive soil moisture sensor is different from most of the resistive sensors on the market, using the principle of capacitive induction to detect soil moisture.

By visually reading the values from the soil moisture sensor, we can gather information about the moisture level in the soil. This information is useful for various applications, such as automatic irrigation systems, plant health monitoring, or environmental sensing projects.

**Required Components**

In this project, we need the following components. 

It's definitely convenient to buy a whole kit, here's the link: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

You can also buy them separately from the links below.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - COMPONENT INTRODUCTION
        - PURCHASE LINK

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|

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

**Code**

.. note::

    * Open the ``5.9_moisture.py`` file located in the ``esp32-starter-kit-main\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
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