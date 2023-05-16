.. _py_line_track:

5.4 Detect the Line
===================================

The line tracking module is used to detect whether there are black areas on the ground, such as black lines pasted with electrical tape.

One of its LEDs emits appropriate infrared light to the ground, and the black surface has a relatively strong ability to absorb light and a weaker reflection ability. White surfaces are the opposite.
If it detects reflected light, it means the ground is currently white. If not detected, it means black.

That's how it works.




**Schematic**

.. image:: img/circuit_3.4_line.png

The digital pin 2 is used to read the
signal of line track module. We get the VCC of the module connected to 5V, 
GND to GND, OUT to digital pin 2.

**Wiring**



.. image:: img/detect_the_line_bb.jpg
    :width: 500
    :align: center


* :ref:`cpn_uno`
* :ref:`cpn_track`
* :ref:`cpn_wires`


**Adjust the Module**

Before beginning the project, it is necessary to adjust the sensitivity of the module.

Wire the components according to the provided diagram, and power on the ESP32 (either by plugging it directly into a USB cable or connecting it to a battery), without executing any code.

Place a strip of black electrical tape on the table, and position the line-tracking module on top of it.

Monitor the signal LED on the module to ensure that it illuminates when placed on the white table and turns off when on the black tape.

If this effect is not achieved, adjust the potentiometer on the module until the desired behavior is observed.



.. image:: img/line_track_cali.JPG


**Code**

.. note::

    * Open the ``5.4_detect_the_line.py`` file located in the ``esp32-ultimate-kit\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 
    * For detailed tutorials, please refer to :ref:`open_run_code_py`.

.. code-block:: python

    import machine
    import time

    # Create a pin object named greyscale, set pin number 14 as input
    line = machine.Pin(14, machine.Pin.IN)


    while True:
        # Check if the value is 1 (black)
        if line.value() == 1:
            # Print "black"
            print("black")
            time.sleep(0.5)
        # If the value is not 1 (it's 0, which means white)
        else :
            # Print "white"
            print("white")
            time.sleep(0.5)



When the line tracking module detects there is black line, there appears "black" on the Shell; otherwise, "white" is displayed.
