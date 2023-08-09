.. _py_light_theremin:

6.3 Light Theremin
=========================

Theremin is an electronic musical instrument that does not require physical contact. Based on the position of the player's hand, it produces different tones.

Its controlling section is usually made up of two metal antennas that sense the position of the thereminist's hands and control oscillators with one hand and volume with the other. The electric signals from the theremin are amplified and sent to a loudspeaker.

We cannot reproduce the same instrument through ESP32, but we can use photoresistor and passive buzzer to achieve similar gameplay.

* `Theremin - Wikipedia <https://en.wikipedia.org/wiki/Theremin>`_


**Schematic**

.. image:: ../../img/circuit/circuit_6.3_light_theremin.png

Before starting the project, calibrate the range of light intensity by waving your hand over the photoresistor. The LED connected to IO26 is used as an indicator during the calibration process. When the LED is lit, it signifies the start of calibration, and when it is turned off, it indicates the end of calibration.

As you wave your hand over the photoresistor, the value of the photoresistor will change accordingly. 
Utilize this change to control the buzzer and play different musical notes. 
Each variation in the photoresistor's value can be mapped to a specific musical note, allowing 
the buzzer to produce a melody as you wave your hand over the photoresistor.


**Wiring**

.. image:: ../../img/wiring/6.3_theremin_bb.png

* :ref:`cpn_esp32_wroom_32e`
* :ref:`cpn_esp32_camera_extension`
* :ref:`cpn_breadboard`
* :ref:`cpn_resistor`
* :ref:`cpn_wires`
* :ref:`cpn_photoresistor`
* :ref:`cpn_led`
* :ref:`cpn_buzzer`
* :ref:`cpn_transistor`

**Code**

.. note::

    * Open the ``6.3_light_theremin.py`` file located in the ``esp32-starter-kit-main\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 


.. code-block:: python

    from machine import Pin, PWM, ADC
    import time

    # Initialize LED pin
    led = Pin(26, Pin.OUT)

    # Initialize light sensor
    sensor = ADC(Pin(35))
    sensor.atten(ADC.ATTN_11DB)

    # Initialize buzzer
    buzzer = PWM(Pin(13), freq=440, duty=0)

    light_low=4095
    light_high=0

    # Map the interval of input values to output values
    def interval_mapping(x, in_min, in_max, out_min, out_max):
        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

    # Create a tone using the specified pin, frequency, and duration
    def tone(pin,frequency,duration):
        pin.freq(frequency)
        pin.duty(512)
        time.sleep_ms(duration)
        pin.duty(0)

    # Calibrate the photoresistor's maximum and minimum values in 5 seconds.
    timer_init_start = time.ticks_ms()
    led.value(1) # turn on the LED   
    while time.ticks_diff(time.ticks_ms(), timer_init_start)<5000:
        light_value = sensor.read()
        if light_value > light_high:
            light_high = light_value
        if light_value < light_low:
            light_low = light_value   
    led.value(0) # turn off the LED 

    # Play the tones based on the light values
    while True:
        light_value  = sensor.read()
        pitch = int(interval_mapping(light_value,light_low,light_high,50,6000))
        if pitch > 50 :
            tone(buzzer,pitch,20)
        time.sleep_ms(10)


Upon starting the program, the LED turns on, providing us with a five-second window to calibrate the photoresistor's detection range.

Calibration is a crucial step as it accounts for various lighting conditions that we may encounter while using the device, 
such as varying light intensities during different times of the day. 
Additionally, the calibration process takes into account the distance between our hands 
and the photoresistor, which determines the playable range of the instrument.

Once the calibration period is over, the LED turns off, indicating that we can now play the instrument by waving our hands over the photoresistor. 
This setup enables us to create music by adjusting the height of our hands, providing an interactive and enjoyable experience.