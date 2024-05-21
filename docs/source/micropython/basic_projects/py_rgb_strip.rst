.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _py_rgb_strip:

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
        - \-
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

    * Open the ``2.7_rgb_strip.py`` file located in the ``esp32-starter-kit-main\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 

    
.. code-block:: python

    from machine import Pin
    from neopixel import NeoPixel

    pin = Pin(14, Pin.OUT)   # set a pin to output to drive NeoPixels
    pixels = NeoPixel(pin, 8)   # create NeoPixel driver on pin for 8 pixels

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

        pixels = NeoPixel(pin, 8)   # create NeoPixel driver on pin for 8 pixels

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

    * Open the ``2.7_rgb_strip_random.py`` file located in the ``esp32-starter-kit-main\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 


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

