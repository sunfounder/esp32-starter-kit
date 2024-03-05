.. _py_fruit_piano:

6.1 Fruit Piano
============================

Have you ever wanted to play the piano but couldn't afford one? Or maybe you just want to have some fun with diy a fruit piano? Well, this project is for you! 

With just a few touch sensors on the ESP32 board, you can now play your favorite tunes and enjoy the experience of playing the piano without breaking the bank.

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
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|

**About the Touch Pins**

The ESP32 microcontroller has built-in touch sensor functionality, which allows you to use certain pins on the board 
as touch-sensitive inputs. The touch sensor works by measuring changes in capacitance on the touch pins, 
which are caused by the electrical properties of the human body.

Here are some key features of the touch sensor on the ESP32:

* **Number of touch pins**

    The ESP32 has up to 10 touch pins, depending on the specific board. The touch pins are typically labeled with a "T" followed by a number.

    * GPIO4: TOUCH0
    * GPIO0：TOUCH1
    * GPIO2: TOUCH2
    * GPIO15: TOUCH3
    * GPIO13: TOUCH4
    * GPIO12: TOUCH5
    * GPIO14: TOUCH6
    * GPIO27: TOUCH7
    * GPIO33: TOUCH8
    * GPIO32: TOUCH9

    .. note::
        The GPIO0 and GPIO2 pins are used for bootstrapping and flashing firmware to the ESP32, respectively. These pins are also connected to the onboard LED and button. Therefore, it is generally not recommended to use these pins for other purposes, as it could interfere with the normal operation of the board.

* **Sensitivity**

    The touch sensor on the ESP32 is very sensitive and can detect even small changes in capacitance. The sensitivity can be adjusted using software settings.

* **ESD Protection**

    The touch pins on the ESP32 have built-in ESD (Electrostatic Discharge) protection, which helps to prevent damage to the board from static electricity.

* **Multitouch**

    The touch sensor on the ESP32 supports multitouch, which means that you can detect multiple touch events simultaneously.


**Schematic**

.. image:: ../../img/circuit/circuit_6.1_fruit_piano.png

The idea behind this project is to use touch sensors to detect when a user touches a specific pin. 
Each touch pin is associated with a specific note, and when the user touches a pin, 
the corresponding note is played on the passive buzzer. 
The result is a simple and affordable way to enjoy the experience of playing the piano.


**Wiring**

.. image:: ../../img/wiring/6.1_fruit_piano_bb.png

In this project, you need to remove the ESP32 WROOM 32E from the expansion board and then insert it into the breadboard. This is because some pins on the expansion board are connected to resistors, which will affect the capacitance of the pins.

**Code**

.. note::

    * Open the ``6.1_fruit_piano.py`` file located in the ``esp32-starter-kit-main\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 

.. code-block:: python

    from machine import Pin, PWM, TouchPad
    import time

    # Define the touch pins and their corresponding notes
    touch_pins = [4, 15, 13, 12, 14, 27, 33, 32]  # Use valid touch-capable pins
    notes = [262, 294, 330, 349, 392, 440, 494, 523]

    # Initialize the touch sensors
    touch_sensors = [TouchPad(Pin(pin)) for pin in touch_pins]

    # Initialize the buzzer
    buzzer = PWM(Pin(25), duty=0)

    # Function to play a tone
    def play_tone(frequency, duration):
        buzzer.freq(frequency)
        buzzer.duty(512)
        time.sleep_ms(duration)
        buzzer.duty(0)

    touch_threshold = 200

    # Main loop to check for touch inputs and play the corresponding note
    while True:
        for i, touch_sensor in enumerate(touch_sensors):
            value = touch_sensor.read()
            print(i,value)
            if value < touch_threshold:
                play_tone(notes[i], 100)
                time.sleep_ms(50)
            time.sleep(0.01)


You can connect fruits to these ESP32 pins: 4, 15, 13, 12, 14, 27, 33, 32.

When the script runs, touching these fruits will play the notes C, D, E, F, G, A, B and C5.

.. note::
    ``Touch_threshold`` needs to be adjusted based on the conductivity of different fruits. 
    
    You can run the script first to see the values printed by the shell.

    .. code-block::

        0 884
        1 801
        2 856
        3 964
        4 991
        5 989
        6 1072
        7 1058

    After touching the fruits on pins 12, 14, and 27, the printed values are as follows. Therefore, I set the ``touch_threshold`` to 200, which means that when a value less than 200 is detected, it is considered to be touched, and the buzzer will emit different notes.
    
    .. code-block::

        0 882
        1 810
        2 799
        3 109
        4 122
        5 156
        6 1068
        7 1055

