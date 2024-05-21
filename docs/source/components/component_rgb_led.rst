.. note::

    Hello, welcome to the SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community on Facebook! Dive deeper into Raspberry Pi, Arduino, and ESP32 with fellow enthusiasts.

    **Why Join?**

    - **Expert Support**: Solve post-sale issues and technical challenges with help from our community and team.
    - **Learn & Share**: Exchange tips and tutorials to enhance your skills.
    - **Exclusive Previews**: Get early access to new product announcements and sneak peeks.
    - **Special Discounts**: Enjoy exclusive discounts on our newest products.
    - **Festive Promotions and Giveaways**: Take part in giveaways and holiday promotions.

    👉 Ready to explore and create with us? Click [|link_sf_facebook|] and join today!

.. _cpn_rgb:

RGB LED
=================

.. image:: img/rgb_led.png
    :width: 200
    :align: center

RGB LEDs emit light in various colors. An RGB LED packages three LEDs of red, green, and blue into a transparent or semitransparent plastic shell. It can display various colors by changing the input voltage of the three pins and superimpose them, which, according to statistics, can create 16,777,216 different colors. 

**Features**

* Color: Tri-Color (Red/Green/Blue)
* Common Cathode
* 5mm Clear Round Lens
* Forward Voltage: Red: DC 2.0 - 2.2V; Blue&Green: DC 3.0 - 3.2V (IF=20mA) 
* 0.06 Watts DIP RGB LED
* Luminance Brighter Up To +20%
* Viewing Angle: 30°

**Common Anode and Common Cathode**

RGB LEDs can be categorized into common anode and common cathode ones. 

* In a common cathode RGB LED, all three LEDs share a negative connection (cathode).
* In a common anode RGB LED, the three LEDs share a positive connection (anode).

.. image:: img/rgb_cc_ca.jpg

.. note::
    We use the common cathode one.

**RGB LED Pins**

An RGB LED has 4 pins: the longest one is GND; the others are Red, Green and Blue. Place the RGB LEDs as shown, so that the longest lead is second from the left. Then the pin numbers of the RGB LEDs should be Red, GND, Green and Blue.

.. image:: img/rgb_pin.jpg
    :width: 200

You can also use the multimeter to select Diode Test mode, and then connect as shown below to measure the color of each pin.

.. image:: img/rgb_test.png

**Mix colors**

To generate additional colors, you can combine the three colors at different intensities. To adjust the intensity of each LED, you can use a PWM signal.

Because the LEDs are so close to each other, our eyes see the result of the color combination rather than the three colors individually.

Check out the table below to see how the colors are combined. It will give you an idea of how the color mixing chart works and how different colors are produced.

.. image:: img/rgb_mix.png



**Example**

* :ref:`ar_rgb` (Arduino Project)
* :ref:`ar_color_gradient` (Arduino Project)
* :ref:`py_rgb` (MicroPython Project)
* :ref:`sh_colorful_ball` (Scratch Project)

