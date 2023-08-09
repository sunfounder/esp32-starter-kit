.. _py_servo:

4.3 Swinging Servo
===================

A Servo is a type of position-based device known for its ability to maintain specific angles and deliver precise rotation. This makes it highly desirable for control systems that demand consistent angle adjustments. It's not surprising that Servos have found extensive use in high-end remote-controlled toys, from airplane models to submarine replicas and sophisticated remote-controlled robots.

In this intriguing adventure, we'll challenge ourselves to manipulate the Servo in a unique way - by making it sway! This project offers a brilliant opportunity to dive deeper into the dynamics of Servos, sharpening your skills in precise control systems and offering a deeper understanding of their operation.

Are you ready to make the Servo dance to your tunes? Let's embark on this exciting journey!


**Available Pins**

Here is a list of available pins on the ESP32 board for this project.

.. list-table::
    :widths: 5 20 

    * - Available Pins
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**Schematic**

.. image:: ../../img/circuit/circuit_4.3_servo.png

**Wiring**

* Orange wire is signal and connected to IO25.
* Red wire is VCC and connected to 5V.
* Brown wire is GND and connected to GND.

.. image:: ../../img/wiring/4.3_swinging_servo_bb.png


* :ref:`cpn_esp32_wroom_32e`
* :ref:`cpn_esp32_camera_extension`
* :ref:`cpn_wires`
* :ref:`cpn_servo`

**Code**

.. note::

    * Open the ``4.3_swinging_servo.py`` file located in the ``esp32-starter-kit-main\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 




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