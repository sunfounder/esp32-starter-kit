.. _ar_rgb_strip:

2.7 RGB LED Strip
======================

WS2812 is a intelligent control LED light source that the control circuit and RGB chip are integrated in a package of 5050 components. 
It internal include intelligent digital port data latch and signal reshaping amplification drive circuit. 
Also include a precision internal oscillator and a programmable constant current control part, 
effectively ensuring the pixel point light color height consistent.

The data transfer protocol use single NZR communication mode. 
After the pixel power-on reset, the DIN port receive data from controller, the first pixel collect initial 24bit data then sent to the internal data latch, the other data which reshaping by the internal signal reshaping amplification circuit sent to the next cascade pixel through the DO port. After transmission for each pixel，the signal to reduce 24bit. 
pixel adopt auto reshaping transmit technology, making the pixel cascade number is not limited the signal transmission, only depend on the speed of signal transmission.


* :ref:`cpn_ws2812`



**Schematic**

|sch_ws2812|


**Wiring**


|wiring_ws2812|


.. warning::
    One thing you need to pay attention to is current.

    Although the LED Strip with any number of LEDs can be used in ESP32, the power is limited.
    Here, we will use eight LEDs, which are safe.
    But if you want to use more LEDs, you need to add a separate power supply.
    

**Code**

.. note::

    * You can open the file ``2.7_rgb_strip.ino`` under the path of ``esp32-ultimate-kit\c\codes\2.analogWrite\2.7_rgb_strip``. 
    * Or copy this code into **Arduino IDE**.
    * The ``Adafruit_NeoPixel`` library is used here, refer to :ref:`install_libraries_ar` for a tutorial to install.


.. raw:: html
    

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
        * ``t``: Pixel type – add together ``NEO_*`` constants defined in ``Adafruit_NeoPixel.h``, for example ``NEO_GRB+NEO_KHZ800`` for NeoPixels expecting an 800 KHz (vs 400 KHz) data stream with color bytes expressed in green, red, blue order per pixel.

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
