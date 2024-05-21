.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _ar_blink:

2.1 Hello, LED! 
=======================================

Just as printing "Hello, world!" is the first step in learning to program, using a program to drive an LED is the traditional introduction to learning physical programming.

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


**Available Pins**

Here is a list of available pins on the ESP32 board for this project.

.. list-table::
    :widths: 5 20 

    * - Available Pins
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**Schematic**

.. image:: ../../img/circuit/circuit_2.1_led.png

This circuit works on a simple principle, and the current direction is shown in the figure. The LED will light up after the 220ohm current limiting resistor when pin26 outputs high level. The LED will turn off when pin26 outputs low level.

**Wiring**

.. image:: ../../img/wiring/2.1_hello_led_bb.png



**Upload Code**

#. You can open the file ``2.1_hello_led.ino`` under the path of ``esp32-starter-kit-main\c\codes\2.1_hello_led``. Or copy this code to the Arduino IDE directly .
    
    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/1bff2463-40ad-43c1-8815-9f448bab3735/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
#. Then connect the ESP32 WROOM 32E to your computer using a Micro USB cable. 

    * :ref:`unknown_com_port`

    .. image:: ../../img/plugin_esp32.png
        :width: 600
        :align: center

#. Select the board (ESP32 Dev Module) and the appropriate port.

    .. image:: img/choose_board.png

#. Now, click the **Upload** button to upload the code to the ESP32 board.
    
    .. image:: img/click_upload.png

#. After the code is uploaded successfully, you will see the LED blinking.

**How it works?**

#. Declare an integer constant named ``ledPin`` and assigns it the value 26. 

    .. code-block:: arduino

        const int ledPin = 26;  // The GPIO pin for the LED


#. Now, initialize the pin in the ``setup()`` function, where you need to initialize the pin to ``OUTPUT`` mode.

    .. code-block:: arduino

        void setup() {
            pinMode(ledPin, OUTPUT);
        }

    * ``void pinMode(uint8_t pin, uint8_t mode);``: This function is used to define the GPIO operation mode for a specific pin.

        * ``pin`` defines the GPIO pin number.
        * ``mode`` sets operation mode.

        The following modes are supported for the basic input and output:

        * ``INPUT`` sets the GPIO as input without pullup or pulldown (high impedance).
        * ``OUTPUT`` sets the GPIO as output/read mode.
        * ``INPUT_PULLDOWN`` sets the GPIO as input with the internal pulldown.
        * ``INPUT_PULLUP`` sets the GPIO as input with the internal pullup.

#. The ``loop()`` function contains the main logic of the program and runs continuously. It alternates between setting the pin high and low, with one-second intervals between the changes.

    .. code-block:: arduino

        void loop() {
            digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
            delay(1000);                       // wait for a second
            digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
            delay(1000);                       // wait for a second
        }

    * ``void digitalWrite(uint8_t pin, uint8_t val);``: This function sets the state of the selected GPIO to ``HIGH`` or ``LOW``. This function is only used if the ``pinMode`` was configured as ``OUTPUT``.
    
        * ``pin`` defines the GPIO pin number.
        * ``val`` set the output digital state to ``HIGH`` or ``LOW``.