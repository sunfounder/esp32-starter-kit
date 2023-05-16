.. _py_pump:

4.2 Pumping
=======================


Small centrifugal pumps are suitable for projects with automatic plant watering.
It can also be used to make tiny smart water features.

Its power component is an electric motor, driven in exactly the same way as a normal motor.

.. image:: img/pump_use.gif

* :ref:`cpn_pump`
* :ref:`cpn_motor`
* :ref:`cpn_ta6586`
* :ref:`cpn_power_module`

.. note::

    #. Connect the tube to the motor outlet, submerge the pump in water, and then power it on.
    #. You need to make sure that the water level is always higher than the motor. Idling may damage the motor due to heat generation and will also generate noise.
    #. If you are watering plants, you need to avoid soil being drawn in, as this can clog the pump.
    #. If water does not come out of the tube, there may be residual water in the tube blocking the air flow and needs to be drained first.


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
        - TA6586
        - 1
        - 
    *   - 6
        - Li-po Charger Module
        - 1
        -  
    *   - 7
        - 18650 Battery
        - 1
        -  
    *   - 8
        - Battery Holder
        - 1
        -  
    *   - 9
        - Micro Water Pump
        - 1
        -  


**Schematic**

|sch_pump|


**Wiring**


|wiring_pump|

**Code**

.. note::

    * Open the ``4.2_pumping.py`` file located in the ``esp32-ultimate-kit\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 
    * For detailed tutorials, please refer to :ref:`open_run_code_py`.


.. code-block:: python

    import machine
    import time

    # Create Pin objects representing the motor control pins and set them to output mode
    B_1A = machine.Pin(13, machine.Pin.OUT)
    B_1B = machine.Pin(14, machine.Pin.OUT)

    # Define a function to rotate the pump
    def rotate():
        B_1A.value(1)
        B_1B.value(0)

    # Define a function to stop the pump
    def stop():
        B_1A.value(0)
        B_1B.value(0)

    try:
        while True:
            rotate()  # Rotate the motor clockwise
            time.sleep(5)  # Pause for 5 seconds
            stop()  # Stop the motor
            time.sleep(2)

    except KeyboardInterrupt:
        stop()  # Stop the motor when KeyboardInterrupt is caught




During the script execution, you will see the pump working and water coming out of the tube, then stopping for 2 seconds before starting to work again.
