.. _ar_ir_obstacle:

5.3 Detect the Obstacle
===================================

This module is commonly installed on the car and robot to judge the
existence of the obstacles ahead. Also it is widely used in hand held
device, water faucet and so on.


**Schematic**

.. image:: img/circuit_3.3_obstacle.png

The digital pin 14 is used to read the
signal of IR Obstacle Avoidance Module. We get the VCC of IR
Sensor Module connected to 5V, GND to GND, OUT to digital pin 2.

**Wiring**


.. image:: img/detect_the_obstacle_bb.jpg
    :width: 800
    :align: center

* :ref:`cpn_uno`
* :ref:`cpn_avoid`
* :ref:`cpn_wires`

**Adjust the Module**

Before starting the project, you need to adjust the detection distance of the module.

Connect the circuit and power on the ESP32 board (either by plugging in the USB cable directly or by using a battery), without running any code.

Place a flat object about 5cm in front of the IR obstacle avoidance module.

Then use a screwdriver to rotate the potentiometer on the module until the signal indicator on the module just lights up, so as to adjust its maximum detection distance to 5cm.


.. image:: img/ir_obs_cali.jpg


**Code**

.. note::

    * Open the ``5.3_avoid.py`` file located in the ``esp32-ultimate-kit\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 

    * For detailed tutorials, please refer to :ref:`open_run_code_py`.

.. code-block:: python

    import machine
    import time

    ir_avoid = machine.Pin(14, machine.Pin.IN) # avoid module pin

    while True:

        # Print values of the obstacle avoidance module 
        print(ir_avoid.value()) 
        time.sleep(0.1)


While the program is running, if the IR obstacle avoidance module detects an obstacle in front of it, the value "0" will be shown on the Serial Monitor, otherwise, the value "1" will be shown.