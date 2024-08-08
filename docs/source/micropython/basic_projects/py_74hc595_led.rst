.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _py_74hc595:

2.4 Microchip - 74HC595
===========================

Welcome to this exciting project! In this project, we will be using the 74HC595 chip to control a flowing display of 8 LEDs.

Imagine triggering this project and witnessing a mesmerizing flow of light, as if a sparkling rainbow is jumping between the 8 LEDs. Each LED will light up one by one and quickly fade away, while the next LED continues to shine, creating a gorgeous and dynamic effect.

By cleverly utilizing the 74HC595 chip, we can control the on and off states of multiple LEDs to achieve the flowing effect. This chip has multiple output pins that can be connected in series to control the sequence of LED illumination. Moreover, thanks to the chip's expandability, we can easily add more LEDs to the flowing display, creating even more spectacular effects.

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
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|

**Available Pins**

Here is a list of available pins on the ESP32 board for this project.

.. list-table::
    :widths: 5 20 

    * - Available Pins
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**Schematic**

.. image:: ../../img/circuit/circuit_2.4_74hc595_led.png
    :width: 600

* When MR (pin10) is high level and CE (pin13) is low level, data is input in the rising edge of SHcp and goes to the memory register through the rising edge of SHcp. 
* If the two clocks are connected together, the shift register is always one pulse earlier than the memory register. 
* There is a serial shift input pin (DS), a serial output pin (Q7') and an asynchronous reset button (low level) in the memory register. 
* The memory register outputs a Bus with a parallel 8-bit and in three states. 
* When OE is enabled (low level), the data in memory register is output to the bus(Q0 ~ Q7).

**Wiring**

.. image:: ../../img/wiring/2.4_74hc595_bb.png
    :width: 800

**Code**

.. note::

    * Open the ``2.4_microchip_74hc595.py`` file located in the ``esp32-starter-kit-main\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 



.. code-block:: python

    import machine
    import time

    # Initialize the pins for the 74HC595 shift register
    sdi = machine.Pin(25, machine.Pin.OUT)  # DS
    rclk = machine.Pin(27, machine.Pin.OUT)  # STcp
    srclk = machine.Pin(26, machine.Pin.OUT)  # SHcp

    # Define the hc595_shift function to shift data into the 74HC595 shift register
    def hc595_shift(dat):
        # Set the RCLK pin to low
        rclk.off()
        
        # Iterate through each bit (from 7 to 0)
        for bit in range(7, -1, -1):
            # Extract the current bit from the input data
            value = 1 & (dat >> bit)
            
            # Set the SRCLK pin to low
            srclk.off()
            
            # Set the value of the SDI pin
            sdi.value(value)
            
            # Clock the current bit into the shift register by setting the SRCLK pin to high
            srclk.on()
            
        # Latch the data into the storage register by setting the RCLK pin to high
        rclk.on()

    num = 0

    # Shift data into the 74HC595 to create a moving LED pattern
    for i in range(16):
        if i < 8:
            num = (num << 1) + 1  # Shift left and set the least significant bit to 1
        elif i >= 8:
            num = (num & 0b01111111) << 1  # Mask the most significant bit and shift left
        hc595_shift(num)  # Shift the current value into the 74HC595
        print("{:0>8b}".format(num))  # Print the current value in binary format
        time.sleep_ms(200)  # Wait 200 milliseconds before shifting the next value




During script execution, you will see the LED light up one by one, and then turn off in the original order.

**How it works?**

This code is used to control an 8-bit shift register (74595), and output different binary values to the shift register, with each value displayed on an LED for a certain period of time.

#. The code imports the ``machine`` and ``time`` modules, where the ``machine`` module is used to control hardware I/O, and the ``time`` module is used for implementing time delays and other functions.

    .. code-block:: python

        import machine
        import time

#. Three output ports are initialized using the ``machine.Pin()`` function, corresponding to the data port (SDI), storage clock port (RCLK), and shift register clock port (SRCLK) of the shift register.

    .. code-block:: python

        # Initialize the pins for the 74HC595 shift register
        sdi = machine.Pin(25, machine.Pin.OUT)  # DS
        rclk = machine.Pin(27, machine.Pin.OUT)  # STcp
        srclk = machine.Pin(26, machine.Pin.OUT)  # SHcp

#. A function called ``hc595_shift()`` is defined to write an 8-bit data to the shift register.

    .. code-block:: python

        def hc595_shift(dat):
            # Set the RCLK pin to low
            rclk.off()
            
            # Iterate through each bit (from 7 to 0)
            for bit in range(7, -1, -1):
                # Extract the current bit from the input data
                value = 1 & (dat >> bit)
                
                # Set the SRCLK pin to low
                srclk.off()
                
                # Set the value of the SDI pin
                sdi.value(value)
                
                # Clock the current bit into the shift register by setting the SRCLK pin to high
                srclk.on()
                
            # Latch the data into the storage register by setting the RCLK pin to high
            rclk.on()

#. About the ``for`` loop.

    .. code-block:: python

        for i in range(16):
                if i < 8:
                    num = (num << 1) + 1  # Shift left and set the least significant bit to 1
                elif i >= 8:
                    num = (num & 0b01111111) << 1  # Mask the most significant bit and shift left
                hc595_shift(num)  # Shift the current value into the 74HC595
                print("{:0>8b}".format(num))  # Print the current value in binary format
                time.sleep_ms(200)  # Wait 200 milliseconds before shifting the next value

    * The variable ``i`` is used to control the output binary value. In the first 8 iterations, the value of num will be successively 00000001, 00000011, 00000111, ..., 11111111, which is left-shifted by one bit and then added by 1.
    * In the 9th to 16th iterations, the highest bit of 1 is first changed to 0, and then left-shifted by one bit, resulting in the output values of 00000010, 00000100, 00001000, ..., 10000000.
    * In each iteration, the value of ``num`` is passed to the ``hc595_shift()`` function to control the shift register to output the corresponding binary value.
    * At the same time as outputting the binary value, the ``print()`` function outputs the binary value as a string to the terminal.
    * After outputting the binary value, the program pauses for 200 milliseconds using the ``time.sleep_ms()`` function, so that the value on the LED remains displayed for a certain period of time.