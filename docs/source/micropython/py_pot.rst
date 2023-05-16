.. _py_pot:

5.8 Turn the Knob
===========================

In the previous projects, we have used the digital input on the Pico W.
For example, a button can change the pin from low level (off) to high level (on). This is a binary working state.

However, Pico W can receive another type of input signal: analog input.
It can be in any state from fully closed to fully open, and has a range of possible values.
The analog input allows the microcontroller to sense the light intensity, sound intensity, temperature, humidity, etc. of the physical world.

Usually, a microcontroller needs an additional hardware to implement analog input-the analogue-to-digital converter (ADC).
But Pico W itself has a built-in ADC for us to use directly.


|pin_adc|

Pico W has three GPIO pins that can use analog input, On the ESP32, ADC functionality is available on pins 32-39 (ADC block 1) and pins 0, 2, 4, 12-15 and 25-27 (ADC block 2).
In addition, there is a fourth analog channel, which is connected to the built-in temperature sensor and will not be introduced here.

In this project, we try to read the analog value of potentiometer.

* :ref:`cpn_pot`

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
        - Resistor
        - 1(220Ω)
        - |link_resistor_buy|
    *   - 6
        - LED
        - 1
        - |link_led_buy|
    *   - 7
        - Potentiometer
        - 1
        - |link_potentiometer_buy|


**Schematic**

|sch_pot|

The potentiometer is an analog device and when you turn it in 2 different directions.

Connect the middle pin of the potentiometer to the analog pin GP28. The Raspberry Pi Pico W wcontains a multi-channel, 16-bit analog-to-digital converter. This means that it maps the input voltage between 0 and the operating voltage (3.3V) to an integer value between 0 and 65535, so the GP28 value ranges from 0 to 65535.

The calculation formula is shown below.

    (Vp/3.3V) x 65535 = Ap

Then program the value of GP28 (potentiometer) as the PWM value of GP15 (LED).
This way you will find that by rotating the potentiometer, the brightness of the LED will change at the same time.

**Wiring**



|wiring_pot|


**Code**


.. note::

    * Open the ``5.8_turn_the_knob.py`` file located in the ``esp32-ultimate-kit\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 

    * For detailed tutorials, please refer to :ref:`open_run_code_py`.

.. code-block:: python

    from machine import ADC, Pin, PWM
    import time

    pot = ADC(Pin(35, Pin.IN)) # create an ADC object acting on a pin      

    # Configure the ADC attenuation to 11dB for full range
    pot.atten(pot.ATTN_11DB)

    # Create a PWM object
    led = PWM(Pin(26), freq=1000)

    while True:
        # Read a raw analog value in the range of 0-4095
        value = pot.read()

        # Scale the value to the range of 0-1023 for ESP32 PWM duty cycle
        pwm_value = int(value * 1023 / 4095)

        # Update the LED brightness based on the potentiometer value
        led.duty(pwm_value)

        # Read the voltage in microvolts and convert it to volts
        voltage = pot.read_uv() / 1000000

        # Print the raw value and the voltage
        print(f"value: {value}, Voltage: {voltage}V")

        # Wait for 0.5 seconds before taking the next reading
        time.sleep(0.5)

With this script run, the LED brightness changes as the potentiometer is rotated, while the analog value and voltage at this point are displayed in the Shell.

* `machine.ADC - MicroPython Docs <https://docs.micropython.org/en/latest/esp32/quickref.html#adc-analog-to-digital-conversion>`_

