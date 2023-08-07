.. _py_ultrasonic:

5.12 Measuring Distance
======================================

The ultrasonic module is used for distance measurement or object detection. In this project, we will program the module to obtain obstacle distances. By sending ultrasonic pulses and measuring the time it takes for them to bounce back, we can calculate distances. This enables us to implement distance-based actions or obstacle avoidance behaviors.

**Available Pins**

* **Available Pins**

    Here is a list of available pins on the ESP32 board for this project.

    .. list-table::
        :widths: 5 20

        *   - For Input
            - IO13, IO14, IO27, IO26, IO25, IO33, IO32, I35, I34, I39, I36, IO4, IO18, IO19, IO21, IO22, IO23
        *   - For Output
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**Schematic**

.. image:: ../../img/circuit/circuit_5.12_ultrasonic.png

The ESP32 sends a set of square wave signals to the Trig pin of the ultrasonic sensor every 10 seconds. This prompts the ultrasonic sensor to emit a 40kHz ultrasound signal outward. If there is an obstacle in front, the ultrasound waves will be reflected back.

By recording the time it takes from sending to receiving the signal, dividing it by 2, and multiplying it by the speed of light, you can determine the distance to the obstacle.

**Wiring**

.. image:: ../../img/wiring/5.12_ultrasonic_bb.png

* :ref:`cpn_esp32_wroom_32e`
* :ref:`cpn_esp32_camera_extension`
* :ref:`cpn_wires`
* :ref:`cpn_ultrasonic`

**Code**

.. note::

    * Open the ``5.12_ultrasonic.py`` file located in the ``esp32-ultimate-kit-main\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 



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

