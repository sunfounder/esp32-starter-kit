.. _py_rgb_strip:

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
        - WS2812 RGB Strip
        - 1
        - |link_ws2812_buy|


**Schematic**

|sch_ws2812|


**Wiring**


|wiring_ws2812|

33由于同时接了4.7K上拉电阻和滤波电容，不能驱动WS2812灯条


.. warning::
    One thing you need to pay attention to is current.

    Although the LED Strip with any number of LEDs can be used in ESP32, the power is limited.
    Here, we will use eight LEDs, which are safe.
    But if you want to use more LEDs, you need to add a separate power supply.
    

**Code**

.. note::

    * Open the ``2.7_rgb_strip.py`` file located in the ``esp32-ultimate-kit\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 
    * For detailed tutorials, please refer to :ref:`open_run_code_py`. 
    
.. code-block:: python

    from machine import Pin
    from neopixel import NeoPixel

    pin = Pin(14, Pin.OUT)   # set a pin to output to drive NeoPixels
    pixels = NeoPixel(pin, 8)   # create NeoPixel driver on pin25 for 8 pixels

    pixels[0] = [64,154,227]    # set the pixel 
    pixels[1] = [128,0,128]
    pixels[2] = [50,150,50]
    pixels[3] = [255,30,30]
    pixels[4] = [0,128,255]
    pixels[5] = [99,199,0]
    pixels[6] = [128,128,128]
    pixels[7] = [255,100,0]

    pixels.write()              # write data to all pixels


Let's select some favorite colors and display them on the RGB LED Strip!

**How it works?**

#. In the ``neopixel`` module, we have integrated related functions into the ``NeoPixel`` class.

    .. code-block:: python

        from neopixel import NeoPixel

#. Use the ``NeoPixel`` class from the ``neopixel`` module to initialize the  ``pixels`` object, specifying the data pin and the number of LEDs.

    .. code-block:: python

        pixels = NeoPixel(pin, 8)   # create NeoPixel driver on pin25 for 8 pixels

#. Set the color of each LED and use the ``write()`` method to send the data to the WS2812 LED to update its display.

    .. code-block:: python

        pixels[0] = [64,154,227]    # set the pixel 
        pixels[1] = [128,0,128]
        pixels[2] = [50,150,50]
        pixels[3] = [255,30,30]
        pixels[4] = [0,128,255]
        pixels[5] = [99,199,0]
        pixels[6] = [128,128,128]
        pixels[7] = [255,100,0]

        pixels.write()              # write data to all pixels

**Learn More**

We can randomly generate colors and make a colorful flowing light.

.. note::

    * Open the ``2.7_rgb_strip_random.py`` file located in the ``esp32-ultimate-kit\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 
    * For detailed tutorials, please refer to :ref:`open_run_code_py`.

.. code-block:: python

    from machine import Pin
    import neopixel
    import time
    import random

    # Set the number of pixels for the running light
    num_pixels = 8

    # Set the data pin for the RGB LED strip
    data_pin = Pin(14, Pin.OUT)

    # Initialize the RGB LED strip object
    pixels = neopixel.NeoPixel(data_pin, num_pixels)

    # Continuously loop the running light
    while True:
        for i in range(num_pixels):
            # Generate a random color for the current pixel
            color = (random.randint(0, 255), random.randint(0, 255), random.randint(0, 255))
            
            # Turn on the current pixel with the random color
            pixels[i] = color
            
            # Update the RGB LED strip display
            pixels.write()
            
            # Turn off the current pixel
            pixels[i] = (0, 0, 0)
            
            # Wait for a period of time to control the speed of the running light
            time.sleep_ms(100)


* In the ``while`` loop, we use a ``for`` loop to turn on each pixel of the RGB LED strip one by one. 
* First use the ``random.randint()`` function to generate a random color for the current pixel.
* Then turn on the current pixel with the random color, use the ``write()`` method of the ``NeoPixel`` object to send the color data to the RGB LED strip to update its display
* Finally, turn off the current pixel by setting its color to (0, 0, 0), and wait for a period of time to control the speed of the running light.

