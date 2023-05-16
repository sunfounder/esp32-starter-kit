.. _py_color_gradient:

6.5 Color Gradient
=====================

Are you ready to experience a world of color? This project will take you on a magical journey where you can control an 
LED strip and achieve smooth color transitions. Whether you're looking to add some color to your home decor or 
seeking a fun programming project, this project has got you covered. Let's dive into this colorful world together!


**Schematic**


This project uses an LED strip and a potentiometer to create a color mixing effect. The potentiometer is used to adjust the hue value of the LED, which is then converted into RGB values using a color conversion function. The RGB values are then used to update the color of the LED.

**Wiring**




**Code**


.. note::

    * Open the ``6.5_color_gradient.py`` file located in the ``esp32-ultimate-kit\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 

    * For detailed tutorials, please refer to :ref:`open_run_code_py`.

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
