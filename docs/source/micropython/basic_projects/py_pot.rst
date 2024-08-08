.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _py_potentiometer:

5.8 Turn the Knob
===========================
A potentiometer is a three-terminal device that is commonly used to adjust the resistance in a circuit. It features a knob or a sliding lever that can be used to vary the resistance value of the potentiometer. In this project, we will utilize it to control the brightness of an LED, similar to a desk lamp in our daily life. By adjusting the position of the potentiometer, we can change the resistance in the circuit, thereby regulating the current flowing through the LED and adjusting its brightness accordingly. This allows us to create a customizable and adjustable lighting experience, similar to that of a desk lamp.

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
        - |link_esp32_extension_board|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_pot`
        - |link_potentiometer_buy|

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

.. image:: ../../img/circuit/circuit_5.8_potentiometer.png

When you rotate the potentiometer, the value of I35 will change. By programming, you can use the value of I35 to control the brightness of the LED. Therefore, as you rotate the potentiometer, the brightness of the LED will also change accordingly.


**Wiring**

.. image:: ../../img/wiring/5.8_potentiometer_bb.png

**Code**


.. note::

    * Open the ``5.8_turn_the_knob.py`` file located in the ``esp32-starter-kit-main\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 



.. code-block:: python

    from machine import ADC, Pin, PWM
    import time

    pot = ADC(Pin(35, Pin.IN)) # create an ADC object acting on a pin      

    # Configure the ADC attenuation to 11dB for full range
    pot.atten(pot.ATTN_11DB)

    # Create a PWM object
    led = PWM(Pin(26), freq=1000)

    while True:
        # Read a raw analog value in the range of 0-4095
        value = pot.read()

        # Scale the value to the range of 0-1023 for ESP32 PWM duty cycle
        pwm_value = int(value * 1023 / 4095)

        # Update the LED brightness based on the potentiometer value
        led.duty(pwm_value)

        # Read the voltage in microvolts and convert it to volts
        voltage = pot.read_uv() / 1000000

        # Print the raw value and the voltage
        print(f"value: {value}, Voltage: {voltage}V")

        # Wait for 0.5 seconds before taking the next reading
        time.sleep(0.5)

With this script run, the LED brightness changes as the potentiometer is rotated, while the analog value and voltage at this point are displayed in the Shell.

* `machine.ADC - MicroPython Docs <https://docs.micropython.org/en/latest/esp32/quickref.html#adc-analog-to-digital-conversion>`_

