.. _py_pir:

5.5 Detect Human Movement
========================================

Passive infrared sensor (PIR sensor) is a common sensor that can measure infrared (IR) light emitted by objects in its field of view.
Simply put, it will receive infrared radiation emitted from the body, thereby detecting the movement of people and other animals.
More specifically, it tells the main control board that someone has entered your room.

**Required Components**

In this project, we need the following components. 

It's definitely convenient to buy a whole kit, here's the link: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
        - LINK
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

You can also buy them separately from the links below.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - COMPONENT INTRODUCTION
        - PURCHASE LINK

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_pir`
        - |link_pir_buy|

**Available Pins**

* **Available Pins**

    Here is a list of available pins on the ESP32 board for this project.

    .. list-table::
        :widths: 5 20

        *   - For Input
            - IO13, IO14, IO27, IO26, IO25, IO33, I35, I34, I39, I36, IO4, IO18, IO19, IO21, IO22, IO23
        *   - For Output
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

.. note::
    
    IO32 cannot be used **as input pin** in this project because it is internally connected to a 1K pull-down resistor, which sets its default value to 0.

* **Strapping Pins (Input)**

    Strapping pins are a special set of pins that are used to determine specific boot modes during device startup 
    (i.e., power-on reset).

    
    .. list-table::
        :widths: 5 15

        *   - Strapping Pins
            - IO5, IO0, IO2, IO12, IO15 
    

    

    Generally, it is **not recommended to use them as input pins**. If you wish to use these pins, consider the potential impact on the booting process. For more details, please refer to the :ref:`esp32_strapping` section.


**Schematic**

.. image:: ../../img/circuit/circuit_5.5_pir.png

When the PIR module detects motion, IO14 will go high, and the LED will be lit. Otherwise, when no motion is detected, IO14 will be low, and the LED will turn off.

.. note::
    The PIR module has two potentiometers: one adjusts sensitivity, the other adjusts detection distance. To make the PIR module work better, you need to turn both of them counterclockwise to the end.

    .. image:: ../../components/img/PIR_TTE.png
        :width: 300
        :align: center

**Wiring**

.. image:: ../../img/wiring/5.5_pir_bb.png

**Code**

.. note::

    * Open the ``5.5_detect_human_movement.py`` file located in the ``esp32-starter-kit-main\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 



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

    .. image:: ../../components/img/PIR_TTE.png
        :width: 300
        :align: center




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
