.. _py_servo:

4.3 Swinging Servo
===================

In this kit, in addition to LED and passive buzzer, there is also a device controlled by PWM signal, Servo.

Servo is a position (angle) servo device, which is suitable for those control systems that require constant angle changes and can be maintained. It has been widely used in high-end remote control toys, such as airplanes, submarine models, and remote control robots.

Now, try to make the servo sway!

* :ref:`cpn_servo`

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
        - Servo
        - 1
        - |link_servo_buy|


**Schematic**

|sch_servo|

**Wiring**

|wiring_servo|

* Orange wire is signal and connected to pin25.
* Red wire is VCC and connected to Vin(5V).
* Brown wire is GND and connected to GND.



**Code**

.. note::

    * Open the ``4.3_swinging_servo.py`` file located in the ``esp32-ultimate-kit\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 
    * For detailed tutorials, please refer to :ref:`open_run_code_py`.



.. code-block:: python

    import machine
    import time

    # Create a PWM (Pulse Width Modulation) object on Pin 25
    servo = machine.PWM(machine.Pin(25))

    # Set the frequency of the PWM signal to 50 Hz, common for servos
    servo.freq(50)

    # Define a function for interval mapping
    def interval_mapping(x, in_min, in_max, out_min, out_max):
        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

    # Define a function to write an angle to the servo
    def servo_write(pin, angle):
        
        pulse_width = interval_mapping(angle, 0, 180, 0.5, 2.5) # Calculate the pulse width
        duty = int(interval_mapping(pulse_width, 0, 20, 0, 1023))     # Calculate the duty cycle
        pin.duty(duty) # Set the duty cycle of the PWM signal

    # Create an infinite loop
    while True:
        # Loop through angles from 0 to 180 degrees
        for angle in range(180):
            servo_write(servo, angle)
            time.sleep_ms(20)

        # Loop through angles from 180 to 0 degrees in reverse
        for angle in range(180, -1, -1):
            servo_write(servo, angle)
            time.sleep_ms(20)


When running this code, the servo will continuously sweep back and forth between 0 and 180 degrees.


**How it works?**


#. Import the necessary libraries: ``machine`` for controlling the microcontroller's hardware, and ``time`` for adding delays.


    .. code-block:: python

        import machine
        import time

#. Create a PWM (Pulse Width Modulation) object on Pin 25 and set its frequency to 50 Hz, which is common for servo.

    .. code-block:: python

        # Create a PWM (Pulse Width Modulation) object on Pin 25
        servo = machine.PWM(machine.Pin(25))

        # Set the frequency of the PWM signal to 50 Hz, common for servos
        servo.freq(50)

#. Define an ``interval_mapping`` function to map values from one range to another. This will be used to convert the angle to the appropriate pulse width and duty cycle.

    .. code-block:: python

        def interval_mapping(x, in_min, in_max, out_min, out_max):
            return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

#. Define a ``servo_write`` function that takes a PWM object and an angle as inputs. It calculates the pulse width and duty cycle based on the given angle, and then sets the PWM output accordingly.

    .. code-block:: python
        
        def servo_write(pin, angle):
            
            pulse_width = interval_mapping(angle, 0, 180, 0.5, 2.5) # Calculate the pulse width
            duty = int(interval_mapping(pulse_width, 0, 20, 0, 1023))     # Calculate the duty cycle
            pin.duty(duty) # Set the duty cycle of the PWM signal

    * In this function, ``interval_mapping()`` is called to map the angle range 0 ~ 180 to the pulse width range 0.5 ~ 2.5ms.
    * Why is it 0.5~2.5? This is determined by the working mode of the :ref:`Servo`. 
    * Next, convert the pulse width from period to duty. 
    * Since ``duty()`` cannot have decimals when used (the value cannot be a float type), we used ``int()`` to force the duty to be converted to an int type.

#. Create an infinite loop with two nested loops.

    .. code-block:: python

        while True:
            # Loop through angles from 0 to 180 degrees
            for angle in range(180):
                servo_write(servo, angle)
                time.sleep_ms(20)

            # Loop through angles from 180 to 0 degrees in reverse
            for angle in range(180, -1, -1):
                servo_write(servo, angle)
                time.sleep_ms(20)
    
    * The first nested loop iterates through angles from 0 to 180 degrees, and the second nested loop iterates through angles from 180 to 0 degrees in reverse.
    * In each iteration, the ``servo_write`` function is called with the current angle, and a delay of 20 milliseconds is added.