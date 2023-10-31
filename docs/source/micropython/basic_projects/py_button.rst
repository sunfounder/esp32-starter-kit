.. _py_button:

5.1 Reading Button Value
==============================================

In this interactive project, we'll venture into the realm of button controls and LED manipulation.

The concept is straightforward yet effective. We'll be reading the state of a button. When the button is pressed down, it registers a high voltage level, or 'high state'. This action will then trigger an LED to light up.

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
    *   - :ref:`cpn_button`
        - |link_button_buy|

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

.. image:: ../../img/circuit/circuit_5.1_button.png

To ensure proper functionality, connect one side of the button pin to 3.3V and the other side to IO14. When the button is pressed, IO14 will be set to high, causing the LED to light up. When the button is released, IO14 will return to its suspended state, which may be either high or low. To ensure a stable low level when the button is not pressed, IO14 should be connected to GND through a 10K pull-down resistor.

**Wiring**

.. image:: ../../img/wiring/5.1_button_bb.png

.. note::
    
    A four-pin button is designed in an H shape. When the button is not pressed, the left and right pins are disconnected, and current cannot flow between them. However, when the button is pressed, the left and right pins are connected, creating a pathway for current to flow.

**Code**

.. note::

    * Open the ``5.1_read_button_value.py`` file located in the ``esp32-starter-kit-main\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 



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
