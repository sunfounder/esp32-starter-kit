.. _py_pir:

5.5 Detect Human Movement
========================================

Passive infrared sensor (PIR sensor) is a common sensor that can measure infrared (IR) light emitted by objects in its field of view.
Simply put, it will receive infrared radiation emitted from the body, thereby detecting the movement of people and other animals.
More specifically, it tells the main control board that someone has entered your room.

:ref:`cpn_pir`

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
        - PIR Module
        - 1
        - |link_pir_buy|
    *   - 6
        - LED
        - 1
        - |link_led_buy|


**Schematic**

|sch_pir|

When the PIR module detects someone passing by, pin14 will be high, otherwise it will be low.

.. note::
    The PIR module has two potentiometers: one adjusts sensitivity, the other adjusts detection distance. To make the PIR module work better, you need to turn both of them counterclockwise to the end.

    |img_PIR_TTE|

**Wiring**

PIR连接到14引脚，LED连接到26引脚

|wiring_pir|

**Code**

.. note::

    * Open the ``5.5_detect_human_movement.py`` file located in the ``esp32-ultimate-kit\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 

    * For detailed tutorials, please refer to :ref:`open_run_code_py`.

.. code-block:: python

    import machine
    import time

    # Define pins
    PIR_PIN = 14    # PIR sensor
    LED_PIN = 26    # LED

    # Initialize the PIR sensor pin as an input pin
    pir_sensor = machine.Pin(PIR_PIN, machine.Pin.IN, machine.Pin.PULL_DOWN)
    # Initialize the LED pin as an output pin
    led = machine.Pin(LED_PIN, machine.Pin.OUT)

    # Global flag to indicate motion detected
    motion_detected_flag = False

    # Function to handle the interrupt
    def motion_detected(pin):
        global motion_detected_flag
        print("Motion detected!")
        motion_detected_flag = True

    # Attach the interrupt to the PIR sensor pin
    pir_sensor.irq(trigger=machine.Pin.IRQ_RISING, handler=motion_detected)

    # Main loop
    while True:
        if motion_detected_flag:
            led.value(1)  # Turn on the LED
            time.sleep(5)  # Keep the LED on for 5 seconds
            led.value(0)  # Turn off the LED
            motion_detected_flag = False

When the script is running, the LED will light up for 5 seconds and then go off when the PIR module detects someone passing.

.. note::
    The PIR module has two potentiometers: one adjusts sensitivity, the other adjusts detection distance. To make the PIR module work better, you need to turn both of them counterclockwise to the end.

    |img_PIR_TTE|


**How it work?**


This code sets up a simple motion detection system using a PIR sensor and an LED. When motion is detected, the LED will turn on for 5 seconds. 

Here's a breakdown of the code:

#. Define the interrupt handler function that will be executed when motion is detected:

    .. code-block:: python

        def motion_detected(pin):
            global motion_detected_flag
            print("Motion detected!")
            motion_detected_flag = True

#. Attach the interrupt to the PIR sensor pin, with the trigger set to "rising" (i.e., when the pin goes from low to high voltage):

    .. code-block:: python

        pir_sensor.irq(trigger=machine.Pin.IRQ_RISING, handler=motion_detected)

    This sets up an interrupt on the ``pir_sensor`` pin, which is connected to the PIR motion sensor.

    Here's a detailed explanation of the parameters:

    * ``trigger=machine.Pin.IRQ_RISING``: This parameter sets the trigger condition for the interrupt. In this case, the interrupt will be triggered on a rising edge. A rising edge is when the voltage on the pin changes from a low state (0V) to a high state (typically 3.3V or 5V, depending on your hardware). For a PIR motion sensor, when motion is detected, the output pin usually goes from low to high, making the rising edge an appropriate trigger condition.

    * ``handler=motion_detected``: This parameter specifies the function that will be executed when the interrupt is triggered. In this case, the ``motion_detected`` function is provided as the interrupt handler. This function will be called automatically when the interrupt condition (rising edge) is detected on the ``pir_sensor`` pin.

    So, this line of code configures the PIR sensor to call the ``motion_detected`` function whenever motion is detected by the sensor, due to the output pin going from a low to a high state.



#. In the main loop, if the ``motion_detected_flag`` is set to ``True``, the LED will be turned on for 5 seconds and then turned off. The flag is then reset to ``False`` to wait for the next motion event.

    .. code-block:: python

        while True:
            if motion_detected_flag:
                led.value(1)  # Turn on the LED
                time.sleep(5)  # Keep the LED on for 5 seconds
                led.value(0)  # Turn off the LED
                motion_detected_flag = False
