.. _py_ultrasonic:

5.12 Measuring Distance
======================================

The ultrasonic sensor module works on the principle of sonar and radar systems for determining the distance to an object.

* :ref:`cpn_ultrasonic`

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
        - Ultrasonic Sensor Module
        - 1
        - |link_ultrasonic_buy|


**Schematic**

|sch_ultrasonic|

**Wiring**

|wiring_ultrasonic|

**Code**

.. note::

    * Open the ``5.12_ultrasonic.py`` file located in the ``esp32-ultimate-kit\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 

    * For detailed tutorials, please refer to :ref:`open_run_code_py`.

.. code-block:: python

    import machine
    import time

    # Define the trigger and echo pins for the distance sensor
    TRIG = machine.Pin(26, machine.Pin.OUT)
    ECHO = machine.Pin(25, machine.Pin.IN)

    # Calculate the distance using the ultrasonic sensor
    def distance():
        # Ensure trigger is off initially
        TRIG.off()
        time.sleep_us(2)  # Wait for 2 microseconds

        # Send a 10-microsecond pulse to the trigger pin
        TRIG.on()
        time.sleep_us(10)
        TRIG.off()

        # Wait for the echo pin to go high
        while not ECHO.value():
            pass

        # Record the time when the echo pin goes high
        time1 = time.ticks_us()

        # Wait for the echo pin to go low
        while ECHO.value():
            pass

        # Record the time when the echo pin goes low
        time2 = time.ticks_us()

        # Calculate the time difference between the two recorded times
        during = time.ticks_diff(time2, time1)

        # Calculate and return the distance (in cm) using the speed of sound (340 m/s)
        return during * 340 / 2 / 10000

    # Continuously measure and print the distance
    while True:
        dis = distance()
        print('Distance: %.2f' % dis)
        time.sleep_ms(300)  # Wait for 300 milliseconds before repeating


Once the program is running, the Shell will print out the distance of the ultrasonic sensor from the obstacle ahead.

