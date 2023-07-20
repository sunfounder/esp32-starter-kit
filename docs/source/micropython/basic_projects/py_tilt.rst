.. _py_tilt:

4.2 Tilt It！
==========================
The tilt switch is a simple yet effective 2-pin device that contains a metal ball in its center. When the switch is in an upright position, the two pins are electrically connected, allowing current to flow through. However, when the switch is tilted or tilted at a certain angle, the metal ball moves and breaks the electrical connection between the pins.

In this project, we will utilize the tilt switch to control the illumination of an LED. By positioning the switch in a way that triggers the tilt action, we can toggle the LED on and off based on the switch's orientation. 


**Available Pins**

* **Available Pins**

    Here is a list of available pins on the ESP32 board for this project.

    .. list-table::
        :widths: 5 20

        *   - For Input
            - IO14, IO25, I35, I34, I39, I36, IO18, IO19, IO21, IO22, IO23
        *   - For Output
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23
    
* **Conditional Usage Pins (Input)**

    The following pins have built-in pull-up or pull-down resistors, so external resistors are not required when **using them as input pins**:


    .. list-table::
        :widths: 5 15
        :header-rows: 1

        *   - Conditional Usage Pins
            - Description
        *   - IO13, IO15, IO2, IO4
            - Pulling up with a 47K resistor defaults the value to high.
        *   - IO27, IO26, IO33
            - Pulling up with a 4.7K resistor defaults the value to high.
        *   - IO32
            - Pulling down with a 1K resistor defaults the value to low.

* **Strapping Pins (Input)**

    Strapping pins are a special set of pins that are used to determine specific boot modes during device startup 
    (i.e., power-on reset).

    
    .. list-table::
        :widths: 5 15

        *   - Strapping Pins
            - IO5, IO0, IO2, IO12, IO15 
    

    

    Generally, it is **not recommended to use them as input pins**. If you wish to use these pins, consider the potential impact on the booting process. For more details, please refer to the :ref:`esp32_strapping` section.


**Schematic**

.. image:: ../../img/circuit/circuit_5.2_tilt.png

When the tilt switch is in an upright position, IO14 will be set to high, resulting in the LED being lit. Conversely, when the tilt switch is tilted, IO14 will be set to low, causing the LED to turn off.

The purpose of the 10K resistor is to maintain a stable low state for IO14 when the tilt switch is in a tilted position.


**Wiring**

.. image:: ../../img/wiring/5.2_tilt_switch_bb.png

* :ref:`cpn_esp32_extension`
* :ref:`cpn_breadboard`
* :ref:`cpn_wires`
* :ref:`cpn_resistor`
* :ref:`cpn_led`
* :ref:`cpn_tilt`

**Code**

.. note::

    * Open the ``4.2_tilt_switch.py`` file located in the ``esp32-ultimate-kit-main\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 



.. code-block:: python

    import machine
    import time

    switch = machine.Pin(14, machine.Pin.IN) # Tilt switch pin
    led = machine.Pin(26, machine.Pin.OUT) # LED pin

    while True:
        # Check if the switch is tilted by reading its value
        if switch.value() == 1:
            # Turn on the LED by setting its value to 1
            led.value(1)
        else:
            # Turn off the LED
            led.value(0)

When the script is running, the LED will be turned on when the switch is upright, and turned off when the switch is tilted.


