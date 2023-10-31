.. _py_blink:

2.1 Hello, LED! 
=======================================

Just as printing "Hello, world!" is the first step in learning to program, using a program to drive an LED is the traditional introduction to learning physical programming.

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|

**Available Pins**

Here is a list of available pins on the ESP32 board for this project.

.. list-table::
    :widths: 5 20 

    * - Available Pins
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**Schematic**

.. image:: ../../img/circuit/circuit_2.1_led.png

This circuit works on a simple principle, and the current direction is shown in the figure. The LED will light up after the 220ohm current limiting resistor when pin26 outputs high level. The LED will turn off when pin26 outputs low level.

**Wiring**

.. image:: ../../img/wiring/2.1_hello_led_bb.png

**Code**

.. note::

    * Open the ``2.1_hello_led.py`` file located in the ``esp32-starter-kit-main\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 



.. code-block:: python

    # Import the necessary libraries
    import machine
    import time

    # Set up the LED on pin 26 as an output pin
    led = machine.Pin(26, machine.Pin.OUT)

    # Start an infinite loop
    while True:
        # Turn on the LED by setting its value to 1 (HIGH)
        led.value(1)
        # Wait for 1 second (1000 milliseconds) while the LED is on
        time.sleep(1)

        # Turn off the LED by setting its value to 0 (LOW)
        led.value(0)
        # Wait for 0.5 seconds (500 milliseconds) while the LED is off
        time.sleep(0.5)

After the code runs, you will see the LED blinking.


**How it works?**

#. It imports two modules, ``machine`` and ``time``. The ``machine`` module provides low-level access to the microcontroller's hardware, while the ``time`` module provides functions for time-related operations.

    .. code-block:: python

        import machine
        import time

#. Then set up the pin26 as an output pin using the ``machine.Pin()`` function with the ``machine.Pin.OUT`` argument. 

    .. code-block:: python

        led = machine.Pin(26, machine.Pin.OUT)

#. In the ``While True`` loop, the LED is turned on for one second by setting the value of the pin26 to 1 using ``led.value(1)`` and then set to 0(``led.value(0)``) to turn it off for one second, and so on in an infinite loop.

    .. code-block:: python
        
        while True:
            # Turn on the LED by setting its value to 1 (HIGH)
            led.value(1)
            # Wait for 1 second (1000 milliseconds) while the LED is on
            time.sleep(1)

            # Turn off the LED by setting its value to 0 (LOW)
            led.value(0)
            # Wait for 0.5 seconds (500 milliseconds) while the LED is off
            time.sleep(0.5)




**Learn More**

In this project, we used MicroPython's ``machine`` and ``time`` module, we can find more ways to use them here.

* `machine.Pin <https://docs.micropython.org/en/latest/library/machine.Pin.html>`_

* `time <https://docs.micropython.org/en/latest/library/time.html>`_



