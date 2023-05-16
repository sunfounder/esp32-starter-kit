.. _py_button:

5.1 Reading Button Value
==============================================

These pins have both input and output functions, as indicated by their name GPIO (General-purpose input/output). Previously, we used the output function; in this chapter, we will use the input function to input the button value.

* :ref:`cpn_button`

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
        - Button
        - 1
        - |link_button_buy|
    *   - 7
        - LED
        - 1
        - |link_led_buy|

**Schematic**

|sch_button|

As long as one side of the button pin is connected to 3.3v, and the other side pin is connected to pin14, then when the button is pressed, pin14 will be high. However, when the button is not pressed, pin14 is in a suspended state and may be high or low. In order to get a stable low level when the button is not pressed, pin14 needs to be reconnected to GND through a 10K pull-down resistor.


**Wiring**

|wiring_button|

按键引脚接14，同侧引脚接10K电阻之后接GND，另外一侧接3.3V.
LED接26.

.. note::
    A four-pin button is shaped like an H. Its left two pins or right two pins are connected, which means that when it crosses the central gap, it connects two half rows with the same row number. (For example, in my circuit, E23 and F23 are already connected, as are E25 and F25).

    Until the button is pressed, the left and right pins are independent of each other and current cannot flow from one side to the other.



**Code**

.. note::

    * Open the ``5.1_read_button_value.py`` file located in the ``esp32-ultimate-kit\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 

    * For detailed tutorials, please refer to :ref:`open_run_code_py`.

.. code-block:: python

    import machine
    import time

    button = machine.Pin(14, machine.Pin.IN) # Button pin
    led = machine.Pin(26, machine.Pin.OUT) # LED pin


    while True:
        # If the button is pressed by reading its value
        if button.value() == 1:
            # Turn on the LED by setting its value to 1
            led.value(1)
    #         time.sleep(0.5)
        else:
            # Turn off the LED
            led.value(0)

During script execution, the LED lights up when you press the button and goes out when you release it.
