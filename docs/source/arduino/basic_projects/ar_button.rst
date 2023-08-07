.. _ar_button:

5.1 Reading Button Value
==============================================
In this interactive project, we'll venture into the realm of button controls and LED manipulation.

The concept is straightforward yet effective. We'll be reading the state of a button. When the button is pressed down, it registers a high voltage level, or 'high state'. This action will then trigger an LED to light up.

**Available Pins**

* **Available Pins**

    Here is a list of available pins on the ESP32 board for this project.

    .. list-table::
        :widths: 5 20

        *   - For Input
            - IO14, IO25, I35, I34, I39, I36, IO18, IO19, IO21, IO22, IO23
        *   - For Output
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23
    
* **Conditional Usage Pins (Input)**

    The following pins have built-in pull-up or pull-down resistors, so external resistors are not required when **using them as input pins**:


    .. list-table::
        :widths: 5 15
        :header-rows: 1

        *   - Conditional Usage Pins
            - Description
        *   - IO13, IO15, IO2, IO4
            - Pulling up with a 47K resistor defaults the value to high.
        *   - IO27, IO26, IO33
            - Pulling up with a 4.7K resistor defaults the value to high.
        *   - IO32
            - Pulling down with a 1K resistor defaults the value to low.

* **Strapping Pins (Input)**

    Strapping pins are a special set of pins that are used to determine specific boot modes during device startup 
    (i.e., power-on reset).
     
    .. list-table::
        :widths: 5 15

        *   - Strapping Pins
            - IO5, IO0, IO2, IO12, IO15 
    
    Generally, it is **not recommended to use them as input pins**. If you wish to use these pins, consider the potential impact on the booting process. For more details, please refer to the :ref:`esp32_strapping` section.


**Schematic**

.. image:: ../../img/circuit/circuit_5.1_button.png

To ensure proper functionality, connect one side of the button pin to 3.3V and the other side to IO14. When the button is pressed, IO14 will be set to high, causing the LED to light up. When the button is released, IO14 will return to its suspended state, which may be either high or low. To ensure a stable low level when the button is not pressed, IO14 should be connected to GND through a 10K pull-down resistor.

**Wiring**

.. image:: ../../img/wiring/5.1_button_bb.png

.. note::
    
    A four-pin button is designed in an H shape. When the button is not pressed, the left and right pins are disconnected, and current cannot flow between them. However, when the button is pressed, the left and right pins are connected, creating a pathway for current to flow.

* :ref:`cpn_esp32_wroom_32e`
* :ref:`cpn_esp32_camera_extension`
* :ref:`cpn_breadboard`
* :ref:`cpn_wires`
* :ref:`cpn_resistor`
* :ref:`cpn_led`
* :ref:`cpn_button`

**Code**

.. note::

   * You can open the file ``5.1_button.ino`` under the path of ``esp32-ultimate-kit-main\c\codes\5.1_button``. 
   * After selecting the board (ESP32 Dev Module) and the appropriate port, click the **Upload** button.
   
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/702c5a70-78e7-4a8b-a0c7-10c0acebfc12/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Once the code is uploaded successfully, the LED lights up when you press the button and goes off when you release it.

At the same time you can open the Serial Monitor in the upper right corner to observe the value of the button, when the button is pressed, "1" will be printed, otherwise "0" will be printed.

.. image:: img/button_serial.png


**How it works**

The previous projects all involved outputting signals, either in the form of digital or PWM signals.

This project involves receiving input signals from external component to the ESP32 board. You can view the input signal through the Serial Monitor in Arduino IDE.


#. In the ``setup()`` function, the button pin is initialized as an ``input`` and the LED pin is initialized as an ``output``. The Serial communication is also initiated with a baud rate of 115200.

    .. code-block:: arduino

        void setup() {
            Serial.begin(115200);
            // initialize the button pin as an input
            pinMode(buttonPin, INPUT);
            // initialize the LED pin as an output
            pinMode(ledPin, OUTPUT);
        }
    
    * ``Serial.begin(speed)``: Sets the data rate in bits per second (baud) for serial data transmission.

        * ``speed``: in bits per second (baud). Allowed data types: ``long``.

#. In the ``loop()`` function, the state of the button is read and stored in the variable ``buttonState``. The value of ``buttonState`` is printed to the Serial Monitor using ``Serial.println()``.

    .. code-block:: arduino

        void loop() {
            // read the state of the button value
            buttonState = digitalRead(buttonPin);
            Serial.println(buttonState);
            delay(100);
            // if the button is pressed, the buttonState is HIGH
            if (buttonState == HIGH) {
                // turn LED on
                digitalWrite(ledPin, HIGH);

            } else {
                // turn LED off
                digitalWrite(ledPin, LOW);
            }
        }

    If the button is pressed and the ``buttonState`` is HIGH, the LED is turned on by setting the ``ledPin`` to ``HIGH``. Else, turn the LED off.

    * ``int digitalRead(uint8_t pin);``: To read the state of a given pin configured as INPUT, the function digitalRead is used. This function will return the logical state of the selected pin as ``HIGH`` or ``LOW``.

        * ``pin`` select GPIO

    * ``Serial.println()``: Prints data to the serial port as human-readable ASCII text followed by a carriage return character (ASCII 13, or '\r') and a newline character (ASCII 10, or '\n').









