.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _ar_rgb_strip:

2.7 RGB LED Strip
======================

In this project, we will delve into the mesmerizing world of driving WS2812 LED strips and bring a vibrant display of colors to life. With the ability to individually control each LED on the strip, we can create captivating lighting effects that will dazzle the senses.

Furthermore, we have included an exciting extension to this project, where we will explore the realm of randomness. By introducing random colors and implementing a flowing light effect, we can create a mesmerizing visual experience that captivates and enchants.

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
        - |link_esp32_extension_board|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_ws2812`
        - |link_ws2812_buy|

**Schematic**

.. image:: ../../img/circuit/circuit_2.7_ws2812.png
    :width: 500
    :align: center


**Available Pins**

Here is a list of available pins on the ESP32 board for this project.

.. list-table::
    :widths: 5 20 

    * - Available Pins
      - IO13, IO12, IO14, IO27, IO26, IO25, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


.. note::

    IO33 is not available for this project.

    The WS2812 LED strip is a type of LED strip that requires a precise pulse-width modulation (PWM) signal. The PWM signal has precise requirements in both time and voltage. For instance, a "0" bit for the WS2812 corresponds to a high-level pulse of about 0.4 microseconds, while a "1" bit corresponds to a high-level pulse of about 0.8 microseconds. This means the strip needs to receive high-frequency voltage changes.

    However, with a 4.7K pull-up resistor and a 100nf pull-down capacitor on IO33, a simple low-pass filter is created. This type of circuit "smooths out" high-frequency signals, because the capacitor needs some time to charge and discharge when it receives voltage changes. Therefore, if the signal changes too quickly (i.e., is high-frequency), the capacitor will not be able to keep up. This results in the output signal becoming blurred and unrecognizable to the strip.

**Wiring**

.. image:: ../../img/wiring/2.7_rgb_strip_bb.png
    :width: 800

**Code**

.. note::

    * You can open the file ``2.7_rgb_strip.ino`` under the path of ``esp32-starter-kit-main\c\codes\2.7_rgb_strip``. Or copy this code into **Arduino IDE**.
    * After selecting the board (ESP32 Dev Module) and the appropriate port, click the **Upload** button.
    * :ref:`unknown_com_port`
    * The ``Adafruit NeoPixel`` library is used here, you can install it from the **Library Manager**.

        .. image:: img/rgb_strip_lib.png

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/bccd25f6-4e3e-45e2-b9f5-76a1b0866794/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


When the code is successfully uploaded, the LEDs on the strip will sequentially turn on with a yellow color and then turn off, creating a simple chasing effect.


**How it works?**


#. Include the Adafruit NeoPixel library: This line imports the Adafruit NeoPixel library so that the sketch can use its functions and classes to control the LED strip.

    .. code-block:: arduino

        #include <Adafruit_NeoPixel.h> // Include the Adafruit NeoPixel library

#. Define constants for the LED strip.

    .. code-block:: arduino

        #define LED_PIN 13 // NeoPixel LED strip
        #define NUM_LEDS 8 // Number of LEDs

#. Create an instance of the Adafruit_NeoPixel class.

    .. code-block:: arduino

       // Create an instance of the Adafruit_NeoPixel class
        Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

    This line creates an instance of the ``Adafruit_NeoPixel`` class called ``strip`` and configures it with the number of LEDs, the pin connected to the LED strip, and the signal parameters (GRB color order and 800 kHz data rate).


    * ``Adafruit_NeoPixel (uint16_t n, int16_t p = 6, neoPixelType t = NEO_GRB + NEO_KHZ800)``	

    NeoPixel constructor when length, pin and pixel type are known at compile-time. Ruturn Adafruit_NeoPixel object. Call the ``begin()`` function before use.

        * ``n``: Number of NeoPixels in strand.
        * ``p``: Arduino pin number which will drive the NeoPixel data in.
        * ``t``: Pixel type - add together ``NEO_*`` constants defined in ``Adafruit_NeoPixel.h``, for example ``NEO_GRB+NEO_KHZ800`` for NeoPixels expecting an 800 KHz (vs 400 KHz) data stream with color bytes expressed in green, red, blue order per pixel.

#. Initialize the WS2812 RGB strip and sets the initial color of the strip to black (off).

    .. code-block:: arduino

        void setup() {
            strip.begin(); // Initialize the NeoPixel strip
            strip.show(); // Set initial color to black
        }

    * ``void begin (void)``: Configure NeoPixel pin for output.
    * ``void show (void)``: Transmit pixel data in RAM to NeoPixels.

#. In the ``loop()`` function, the LEDs on the strip will sequentially turn on with a yellow color and then turn off, creating a simple chasing effect.

    .. code-block:: arduino

        void loop() {
        // Turn on LEDs one by one
        for (int i = 0; i < NUM_LEDS; i++) {
            strip.setPixelColor(i, 100, 45, 0); // Set the color of the i-th LED to red
            strip.show(); // Update the LED strip with the new colors
            delay(100); // Wait for 100 milliseconds
        }
        
        // Turn off LEDs one by one
        for (int i = 0; i < NUM_LEDS; i++) {
            strip.setPixelColor(i, 0, 0, 0); // Set the color of the i-th LED to black (turn it off)
            strip.show(); // Update the LED strip with the new colors
            delay(100); // Wait for 100 milliseconds
        }
        }

    * ``void setPixelColor (uint16_t n, uint8_t r, uint8_t g, uint8_t b)``

    Set a pixel's color using separate red, green and blue components. If using RGBW pixels, white will be set to 0.

        * ``n``: Pixel index, starting from 0.
        * ``r``: Red brightness, 0 = minimum (off), 255 = maximum.
        * ``g``: Green brightness, 0 = minimum (off), 255 = maximum.
        * ``b``: Blue brightness, 0 = minimum (off), 255 = maximum.
