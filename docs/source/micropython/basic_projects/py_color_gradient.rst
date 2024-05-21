.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _py_color_gradient:

6.5 Color Gradient
=====================

Are you ready to experience a world of color? This project will take you on a magical journey where you can control an 
LED strip and achieve smooth color transitions. Whether you're looking to add some color to your home decor or 
seeking a fun programming project, this project has got you covered. Let's dive into this colorful world together!

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
    *   - :ref:`cpn_pot`
        - |link_potentiometer_buy|
    *   - :ref:`cpn_ws2812`
        - |link_ws2812_buy|

**Schematic**

.. image:: ../../img/circuit/circuit_6.5_color_gradient.png

This project uses an LED strip and a potentiometer to create a color mixing effect. The potentiometer is used to adjust the hue value of the LED, which is then converted into RGB values using a color conversion function. The RGB values are then used to update the color of the LED.

**Wiring**

.. image:: ../../img/wiring/6.5_color_strip_bb.png
    :width: 800

**Code**

.. note::

    * Open the ``6.5_color_gradient.py`` file located in the ``esp32-starter-kit-main\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 

.. code-block:: python
    
    from machine import Pin, ADC, PWM
    import neopixel
    import time

    NUM_LEDS = 8  # Number of LEDs in the strip
    PIN_NUM = 26  # LED strip
    POT_PIN = 14  # Potentiometer

    # Initialize the potentiometer
    potentiometer = ADC(Pin(POT_PIN))
    potentiometer.atten(ADC.ATTN_11DB)

    # Initialize the NeoPixel LED strip
    np = neopixel.NeoPixel(Pin(PIN_NUM), NUM_LEDS)

    # Function to convert HSL color space to RGB color space
    def hsl_to_rgb(h, s, l):
        # Helper function to convert hue to RGB
        def hue_to_rgb(p, q, t):
            if t < 0:
                t += 1
            if t > 1:
                t -= 1
            if t < 1/6:
                return p + (q - p) * 6 * t
            if t < 1/2:
                return q
            if t < 2/3:
                return p + (q - p) * (2/3 - t) * 6
            return p
        
        if s == 0:
            r = g = b = l
        else:
            q = l * (1 + s) if l < 0.5 else l + s - l * s
            p = 2 * l - q
            r = hue_to_rgb(p, q, h + 1/3)
            g = hue_to_rgb(p, q, h)
            b = hue_to_rgb(p, q, h - 1/3)
        
        return (int(r * 255), int(g * 255), int(b * 255))

    # Function to set the color of all LEDs in the strip
    def set_color(np, color):
        for i in range(NUM_LEDS):
            np[i] = color
        np.write()

    # Main loop
    while True:
        # Read the potentiometer value and normalize it to the range [0, 1]
        pot_value = potentiometer.read() / 4095.0
        hue = pot_value  # Set hue value based on the potentiometer's position
        saturation = 1  # Set saturation to 1 (fully saturated)
        lightness = 0.5  # Set lightness to 0.5 (halfway between black and white)

        # Convert the HSL color to RGB
        current_color = hsl_to_rgb(hue, saturation, lightness)
        
        # Set the LED strip color based on the converted RGB value
        set_color(np, current_color)
        
        # Sleep for a short period to allow for smooth transitions
        time.sleep(0.1)



As the code runs, slowly rotate the potentiometer and you will see the color of the RGB Strip fade from red to purple.
