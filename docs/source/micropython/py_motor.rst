.. _py_motor:

4.1 Small Fan
=======================


Now we use the L298N module to drive the DC motor to make it rotate clockwise and counterclockwise. 


* :ref:`cpn_motor`

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
        - TT Motor
        - 1
        - |link_motor_buy| 
    *   - 6
        - L298N Module
        - 1
        -  


**Schematic**

|sch_motor|



**Wiring**


|wiring_motor|


**Code**

.. note::

    * Open the ``4.1_motor_turn.py`` file located in the ``esp32-ultimate-kit\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 

    * For detailed tutorials, please refer to :ref:`open_run_code_py`.

.. code-block:: python

    import machine
    import time

    # Create Pin objects representing the motor control pins and set them to output mode
    B_1A = machine.Pin(13, machine.Pin.OUT)
    B_1B = machine.Pin(14, machine.Pin.OUT)

    # Define a function to rotate the motor clockwise
    def clockwise():
        B_1A.value(1)
        B_1B.value(0)

    # Define a function to rotate the motor anticlockwise
    def anticlockwise():
        B_1A.value(0)
        B_1B.value(1)

    # Define a function to stop the motor
    def stop():
        B_1A.value(0)
        B_1B.value(0)

    # Enter an infinite loop

    try:
        while True:
            clockwise() # Rotate the motor clockwise
            time.sleep(1) # Pause for 1 second
            anticlockwise() # Rotate the motor anticlockwise
            time.sleep(1)
            stop() # Stop the motor
            time.sleep(2)

    except KeyboardInterrupt:
        stop()  # Stop the motor when KeyboardInterrupt is caught



During script execution, you will see the motor alternately rotating clockwise and counterclockwise every second.


**Learn More**

In addition to simply making the motor rotate clockwise and counterclockwise, you can also control the speed of the motor's rotation by using pulse-width modulation (PWM) on the control pin, as shown below.

.. note::

    * Open the ``4.1_motor_turn_pwm.py`` file located in the ``esp32-ultimate-kit\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 

    * For detailed tutorials, please refer to :ref:`open_run_code_py`.

.. code-block:: python

    from machine import Pin, PWM
    import time

    # Create PWM objects representing the motor control pins and set their frequency to 1000 Hz
    B_1A = PWM(Pin(13, Pin.OUT))
    B_1B = PWM(Pin(14, Pin.OUT))
    B_1A.freq(1000)
    B_1B.freq(1000)

    # Enter an infinite loop
    while True:
        # Rotate the motor forward by gradually increasing the power on the B_1A pin
        for power in range(0, 1023, 20):
            B_1A.duty(power)
            B_1B.duty(0)
            time.sleep(0.1)
        # Decreasing the power on the B_1A pin
        for power in range(1023, 0, -20):
            B_1A.duty(power)
            B_1B.duty(0)
            time.sleep(0.1)
        # Rotate the motor in the opposite direction by gradually increasing the power on the B_1B pin
        for power in range(0, 1023, 20):
            B_1A.duty(0)
            B_1B.duty(power)
            time.sleep(0.1)
        # Decreasing the power on the B_1B pin
        for power in range(1023, 0, -20):
            B_1A.duty(0)
            B_1B.duty(power)
            time.sleep(0.1)






Unlike the previous script, here the motor is controlled by PWM signals with a frequency of 1000 Hz, which determines the speed of the motor.

* The code uses a ``while True`` loop to run continuously. Inside the loop, there are four ``for`` loops that control the motors in a sequence. 
* The first two ``for`` loops increase and decrease the speed of IN1 while keeping IN2 at 0 speed. 
* The next two ``for`` loops increase and decrease the speed of IN2 while keeping IN1 at 0 speed.
* The ``range`` function in each ``for`` loop produces a string of numbers that serves as the duty cycle of the PWM signal. This is then output to IN1 or IN2 via the ``duty`` method. The duty cycle determines the percentage of time that the PWM signal is high, which in turn determines the average voltage applied to the motor, and thus the motor speed.
* The ``time.sleep`` function is used to introduce a delay of 0.1 seconds between each step in the sequence, which allows the motor to change speed gradually, rather than jumping from one speed to another instantaneously.