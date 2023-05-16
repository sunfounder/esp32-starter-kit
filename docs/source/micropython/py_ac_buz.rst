.. _py_ac_buz:

3.1 Beep
==================


The active buzzer is a typical digital output device that is as easy to use as lighting up an LED!

* :ref:`Buzzer`

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
        - Transistor
        - 1(S8050)
        - |link_transistor_buy|
    *   - 6
        - Resistor
        - 1(1KΩ)
        - |link_resistor_buy|
    *   - 7
        - Active Buzzer
        - 1
        - 

**Schematic**

|sch_buzzer|

When the GP15 output is high, after the 1K current limiting resistor (to protect the transistor), the S8050 (NPN transistor) will conduct, so that the buzzer will sound.

The role of S8050 (NPN transistor) is to amplify the current and make the buzzer sound louder. In fact, you can also connect the buzzer directly to GP15, but you will find that the buzzer sound is smaller.

**Wiring**

连接到pin14, 用s8050放大

Two types of buzzers are included in the kit. 
We need to use active buzzer. Turn them around, the sealed back (not the exposed PCB) is the one we want.

|img_buzzer|

The buzzer needs to use a transistor when working, here we use S8050 (NPN Transistor).


|wiring_beep|


**Code**

.. note::

    * Open the ``3.1_beep.py`` file located in the ``esp32-ultimate-kit\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 

    * For detailed tutorials, please refer to :ref:`open_run_code_py`.


.. code-block:: python

    import machine
    import time

    # Create a Pin object representing pin 14 and set it to output mode
    buzzer = machine.Pin(14, machine.Pin.OUT)

    # Enter an infinite loop
    while True:
        # Iterate over the values 0 to 3 using a for loop
        for i in range(4):
            # Turn on the buzzer by setting its value to 1
            buzzer.value(1)
            # Pause for 0.2 seconds
            time.sleep(0.2)
            # Turn off the buzzer
            buzzer.value(0)
            # Pause for 0.2 seconds
            time.sleep(0.2)
        # Pause for 1 second before restarting the for loop
        time.sleep(1)



When the script is running, the buzzer will beep quickly four times every second.

