.. _py_ir_obstacle:

5.3 Detect the Obstacle
===================================

This module is commonly installed on the car and robot to judge the
existence of the obstacles ahead. Also it is widely used in hand held
device, water faucet and so on.

**Available Pins**

* **Available Pins**

    Here is a list of available pins on the ESP32 board for this project.

    .. list-table::
        :widths: 5 20

        *   - Available Pins
            - IO13, IO14, IO27, IO26, IO25, IO33, I35, I34, I39, I36, IO4, IO18, IO19, IO21, IO22, IO23

* **Strapping Pins (Input)**

    Strapping pins are a special set of pins that are used to determine specific boot modes during device startup 
    (i.e., power-on reset).
   
    .. list-table::
        :widths: 5 15

        *   - Strapping Pins
            - IO5, IO0, IO2, IO12, IO15 
    
    Generally, it is **not recommended to use them as input pins**. If you wish to use these pins, consider the potential impact on the booting process. For more details, please refer to the :ref:`esp32_strapping` section.

**Schematic**

.. image:: ../../img/circuit/circuit_5.3_avoid.png

When the obstacle avoidance module does not detect any obstacles, IO14 returns a high level. However, when it detects an obstacle, it returns a low level. You can adjust the blue potentiometer to modify the detection distance of this module.

**Wiring**


.. image:: ../../img/wiring/5.3_avoid_bb.png

* :ref:`cpn_esp32_wroom_32e`
* :ref:`cpn_esp32_camera_extension`
* :ref:`cpn_avoid`
* :ref:`cpn_wires`


**Code**

.. note::

    * Open the ``5.3_avoid.py`` file located in the ``esp32-ultimate-kit-main\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 



.. code-block:: python

    import machine
    import time

    ir_avoid = machine.Pin(14, machine.Pin.IN, machine.Pin.PULL_UP) # avoid module pin

    while True:

        # Print values of the obstacle avoidance module 
        print(ir_avoid.value()) 
        time.sleep(0.1)


While the program is running, if the IR obstacle avoidance module detects an obstacle in front of it, the value "0" will be shown on the Serial Monitor, otherwise, the value "1" will be shown.