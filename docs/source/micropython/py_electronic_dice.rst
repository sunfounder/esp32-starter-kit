6.6 Electronic Dice
================================





7 Segment Display can be seen everywhere in life.
For example, on an air conditioner, it can be used to display temperature; on a traffic indicator, it can be used to display a timer.

The 7 Segment Display is essentially a device packaged by 8 LEDs, of which 7 strip-shaped LEDs form an "8" shape, and there is a slightly smaller dotted LED as a decimal point. These LEDs are marked as a, b, c, d, e, f, g, and dp. They have their own anode pins and share cathodes. Their pin locations are shown in the figure below.

|img_7seg_cathode|

This means that it needs to be controlled by 8 digital signals at the same time to fully work and the 74HC595 can do this.

* :ref:`cpn_7-seg`

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
        - 1(220Ω)
        - |link_resistor_buy|
    *   - 6
        - 7 Segment Display
        - 1
        - |link_7segment_buy|
    *   - 7
        - 74HC595
        - 1
        - |link_74hc595_buy|


**Schematic**

|sch_74hc_7seg|

Here the wiring principle is basically the same as :ref:`py_74hc_led`, the only difference is that Q0-Q7 are connected to the a ~ g pins of the 7 Segment Display.

.. list-table:: Wiring
    :widths: 15 25
    :header-rows: 1

    *   - 74HC595
        - LED Segment Display
    *   - Q0
        - a
    *   - Q1
        - b
    *   - Q2
        - c
    *   - Q3
        - d
    *   - Q4
        - e
    *   - Q5
        - f
    *   - Q6
        - g
    *   - Q7
        - dp

**Wiring**
STcp = 25
SHcp = 27
DS = 26
buttonPin = 14，同侧接10K电阻接GND, 另外一侧接3V3

|wiring_74hc_7seg|



**Code**

.. note::

    * Open the ``6.6_electronic_dice.py`` file located in the ``esp32-ultimate-kit\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 

    * For detailed tutorials, please refer to :ref:`open_run_code_py`.


.. code-block:: python

    import machine
    import time
    import random

    # Define the segment code for a common anode 7-segment display
    SEGCODE = [0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f]

    # Initialize the pins for the 74HC595 shift register
    sdi = machine.Pin(25, machine.Pin.OUT)  # DS
    rclk = machine.Pin(27, machine.Pin.OUT)  # STcp
    srclk = machine.Pin(26, machine.Pin.OUT)  # SHcp

    button = machine.Pin(13, machine.Pin.IN) # Button pin

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

    # Initialize the random seed
    random.seed(time.ticks_us())


    num = 1
    button_state = False

    # Define the button callback function to toggle the button state
    def button_callback(pin):
        global button_state
        button_state = not button_state

    # Attach the button callback function to the falling edge of the button pin
    button.irq(trigger=machine.Pin.IRQ_FALLING, handler=button_callback)

    # Continuously display the current digit on the 7-segment display, scrolling if button is not pressed
    while True:
        
        # Display the current digit on the 7-segment display
        hc595_shift(SEGCODE[num])
        
        # If the button is pressed and button state is True
        if button_state:
            pass

        # If the button is pressed again and button state is False, generate a new random digit
        if not button_state:
            num = random.randint(1, 6)
            time.sleep_ms(10) # Adjust this value to control the display refresh rate
        
While the program is running, pressing the button will make the 7-segment display scroll and randomly display a number between 1 and 6. 

Upon pressing the button again, the 7-segment display will stop and reveal a specific number. Press the button once more, and the 7-segment display will resume scrolling through the digits.



