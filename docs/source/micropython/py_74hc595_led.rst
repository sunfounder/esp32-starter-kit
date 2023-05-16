.. _py_74hc_led:

2.4 Microchip - 74HC595
===========================

Integrated circuit (integrated circuit) is a kind of miniature electronic device or component, which is represented by the letter "IC" in the circuit.

A certain process is used to interconnect the transistors, resistors, capacitors, inductors and other components and wiring required in a circuit, fabricate on a small or several small semiconductor wafers or dielectric substrates, and then package them in a package , it has become a micro-structure with the required circuit functions; all of the components have been structured as a whole, making electronic components a big step towards micro-miniaturization, low power consumption, intelligence and high reliability.

The inventors of integrated circuits are Jack Kilby (integrated circuits based on germanium (Ge)) and Robert Norton Noyce (integrated circuits based on silicon (Si)).

This kit is equipped with an IC, 74HC595, which can greatly save the use of GPIO pins.
Specifically, it can replace 8 pins for digital signal output by writing an 8-bit binary number.

* `Binary number - Wikipedia <https://en.wikipedia.org/wiki/Binary_number>`_

* :ref:`74HC595`

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
        - 8(220Ω)
        - |link_resistor_buy|
    *   - 6
        - LED
        - 8
        - |link_led_buy|
    *   - 7
        - 74HC595
        - 1
        - |link_74hc595_buy|

**Schematic**

|sch_74hc_led|

* When MR (pin10) is high level and OE (pin13) is low level, data is input in the rising edge of SHcp and goes to the memory register through the rising edge of SHcp. 
* If the two clocks are connected together, the shift register is always one pulse earlier than the memory register. 
* There is a serial shift input pin (Ds), a serial output pin (Q) and an asynchronous reset button (low level) in the memory register. 
* The memory register outputs a Bus with a parallel 8-bit and in three states. 
* When OE is enabled (low level), the data in memory register is output to the bus(Q0 ~ Q7).

**Wiring**

.. The 74HC595 is a 16-pin IC with a semi-circular notch on one side (usually the left side of the label). With the notch facing upwards, its pins are shown in the diagram below.


.. Refer to the figure below to build the circuit.


|wiring_74hc_led|



**Code**

.. note::

    * Open the ``2.4_microchip_74hc595.py`` file located in the ``esp32-ultimate-kit\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 
    * For detailed tutorials, please refer to :ref:`open_run_code_py`.


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