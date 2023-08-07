.. _cpn_led:

LED
==========

**What's LED?**

.. image:: img/led_pin.jpg
    :width: 200

.. image:: img/led_polarity.jpg
    :width: 400

LEDs are very common electronic devices that can be used to decorate your room during the festival, and you can also use them as indicators for various things, such as whether the power to your home appliances is on or off. They come in dozens of different shapes and sizes, and the most common are LEDs with through hole LEDs, which generally have long leads and can be plugged into a breadboard.

The full name of LED is light-emitting diode, so it has the characteristics of a diode, where current flows in one direction, from the anode (positive) to the cathode (negative).

Here are the electrical symbols for LEDs.

.. image:: img/led_symbol.png


**Various sizes and colors**

.. image:: img/led_color.png

Red, yellow, blue, green, and white are the most common LED colors, and the light emitted is usually the same color as the appearance.

We rarely use LEDs that are transparent or matte in appearance, but the light emitted may be a color other than white.

LEDs come in four sizes: 3mm, 5mm, 8mm and 10mm, with 5mm being the most common size.

.. image:: img/led_type.jpg

Below is the LED size of 5mm in mm.

.. image:: img/led_size.png



**Forward Voltage**

The Forward Voltage is a very important parameter to know when using LEDs, as it determines how much power you use and how large the current limiting resistor should be.

The Forward Voltage is the voltage that the LED needs to use when it lights up. For most red, yellow, orange and light green LEDs, they generally use a voltage between 1.9V and 2.1V.


.. image:: img/led_voltage.jpg
    :width: 400
    :align: center


According to Ohm's law, the current through this circuit decreases as the resistance increases, which causes the LED to dim.

    I = (Vp-Vl)/R

To get the LEDs to light up safely and with the right brightness, how much resistance should we use in the circuit?

For 99% of 5mm LEDs, the recommended current is 20mA, as you can see from the Conditions column of its data sheet.

.. image:: img/led_datasheet.png

Now convert the above formula as shown below.

    R = (Vp-Vl)/I


If ``Vp`` is 5V, ``Vl`` (Forward Voltage) is 2V, and ``I`` is 20mA, then ``R`` is 150Ω.

So we can make the LED brighter by reducing the resistance of the resistor, but it is not recommended to go below 150Ω (this resistance may not be very accurate, because different suppliers provide LEDs have differences).

Below are the forward voltages and wavelengths of different color LEDs that you can use as reference.

.. list-table::
   :widths: 25 25 50
   :header-rows: 1

   * - LED Color
     - Forward Voltage
     - Wavelength
   * - Red
     - 1.8V ~ 2.1V
     - 620 ~ 625
   * - Yellow
     - 1.9V ~ 2.2V
     - 580 ~ 590
   * - Green
     - 1.9V ~ 2.2V
     - 520 ~ 530
   * - Blue
     - 3.0V ~ 3.2V
     - 460 ~ 465
   * - White
     - 3.0V ~ 3.2V
     - 8000 ~ 9000

**Example**

* :ref:`ar_blink` (Arduino Project)
* :ref:`ar_fading` (Arduino Project)
* :ref:`py_blink` (MicroPython Project)
* :ref:`py_fading` (MicroPython Project)
* :ref:`sh_breathing_led` (Scratch Project)
* :ref:`sh_table_lamp` (Scratch Project)
