.. _py_light_theremin:

6.3 Light Theremin
=========================

Theremin is an electronic musical instrument that does not require physical contact. Based on the position of the player's hand, it produces different tones.

Its controlling section is usually made up of two metal antennas that sense the position of the thereminist's hands and control oscillators with one hand and volume with the other. The electric signals from the theremin are amplified and sent to a loudspeaker.

We cannot reproduce the same instrument through Pico W, but we can use photoresistor and passive buzzer to achieve similar gameplay.

* `Theremin - Wikipedia <https://en.wikipedia.org/wiki/Theremin>`_

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
        - LED
        - 1
        - |link_led_buy|
    *   - 6
        - Transistor
        - 1(S8050)
        - |link_transistor_buy|
    *   - 7
        - Resistor
        - 3(1KΩ, 220Ω, 10KΩ)
        - |link_resistor_buy|
    *   - 8
        - Active Buzzer
        - 1
        - 
    *   - 9
        - Photoresistor
        - 1
        - |link_photoresistor_buy|

**Schematic**

|sch_light_theremin|

Before starting the project, wave your hand up and down over the photoresistor to calibrate the range of light intensity. The LED connected in GP16 is used to indicate the debugging time, and the LED is lit to indicate the start of debugging and off to indicate the end of debugging.

When GP15 outputs high level, S8050 (NPN transistor) conducts and the passive buzzer starts to sound.

When the light is stronger, GP28's value is smaller; vice versa, it is larger when the light is weaker.
By programming the value of the photoresistor to affect the frequency of the passive buzzer, a photosensitive device can be simulated.


**Wiring**

|wiring_light_theremin|


**Code**

.. note::

    * Open the ``6.3_light_theremin.py`` file located in the ``esp32-ultimate-kit\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 
    * For detailed tutorials, please refer to :ref:`open_run_code_py`.

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