.. _py_pa_buz:

3.2 Custom Tone
==========================================


We have used active buzzer in the previous project, this time we will use passive buzzer.

Like the active buzzer, the passive buzzer also uses the phenomenon of electromagnetic induction to work. The difference is that a passive buzzer does not have oscillating source, so it will not beep if DC signals are used.
But this allows the passive buzzer to adjust its own oscillation frequency and can emit different notes such as "doh, re, mi, fa, sol, la, ti".

Let the passive buzzer emit a melody!

* :ref:`Buzzer`

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
        - Transistor
        - 1(S8050)
        - |link_transistor_buy|
    *   - 6
        - Resistor
        - 1(1KΩ)
        - |link_resistor_buy|
    *   - 7
        - Passive Buzzer
        - 1
        - |link_passive_buzzer_buy|

**Schematic**

|sch_buzzer|

When the GP15 output is high, after the 1K current limiting resistor (to protect the transistor), the S8050 (NPN transistor) will conduct, so that the buzzer will sound.

The role of S8050 (NPN transistor) is to amplify the current and make the buzzer sound louder. In fact, you can also connect the buzzer directly to GP15, but you will find that the buzzer sound is smaller.


**Wiring**

连接到pin14, 用s8050放大

|img_buzzer|

Two buzzers are included in the kit, we use a passive buzzer (one with an exposed PCB on the back).

The buzzer needs a transistor to work, here we use S8050.

|wiring_buzzer|



**Code**

.. note::

    * Open the ``3.2_custom_tone.py`` file located in the ``esp32-ultimate-kit\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 

    * For detailed tutorials, please refer to :ref:`open_run_code_py`.

.. code-block:: python

    import machine
    import time

    # Define the frequencies of several musical notes in Hz
    C4 = 262
    D4 = 294
    E4 = 330
    F4 = 349
    G4 = 392
    A4 = 440
    B4 = 494

    # Create a PWM object representing pin 14 and assign it to the buzzer variable
    buzzer = machine.PWM(machine.Pin(14))

    # Define a tone function that takes as input a Pin object representing the buzzer, a frequency in Hz, and a duration in milliseconds
    def tone(pin, frequency, duration):
        pin.freq(frequency) # Set the frequency
        pin.duty(512) # Set the duty cycle
        time.sleep_ms(duration) # Pause for the duration in milliseconds
        pin.duty(0) # Set the duty cycle to 0 to stop the tone

    # Play a sequence of notes with different frequency inputs and durations
    tone(buzzer, C4, 250)
    time.sleep_ms(500)
    tone(buzzer, D4, 250)
    time.sleep_ms(500)
    tone(buzzer, E4, 250)
    time.sleep_ms(500)
    tone(buzzer, F4, 250)
    time.sleep_ms(500)
    tone(buzzer, G4, 250)
    time.sleep_ms(500)
    tone(buzzer, A4, 250)
    time.sleep_ms(500)
    tone(buzzer, B4, 250)


**How it works?**

If the passive buzzer given a digital signal, it can only keep pushing the diaphragm without producing sound.

Therefore, we use the ``tone()`` function to generate the PWM signal to make the passive buzzer sound.

This function has three parameters:

* ``pin``: The pin that controls the buzzer.
* ``frequency``: The pitch of the buzzer is determined by the frequency, the higher the frequency, the higher the pitch.
* ``Duration``: The duration of the tone.

We use the ``duty()`` function to set the duty cycle to 512(about 50%). It can be other numbers, and it only needs to generate a discontinuous electrical signal to oscillate.



**Learn More**

We can simulate specific pitches and thus play a complete piece of music.


.. note::

    * Open the ``3.2_custom_tone_music.py`` file located in the ``esp32-ultimate-kit\micropython\codes`` path, or copy and paste the code into Thonny. Then, click "Run Current Script" or press F5 to execute it.
    * Make sure to select the "MicroPython (ESP32).COMxx" interpreter in the bottom right corner. 

    * For detailed tutorials, please refer to :ref:`open_run_code_py`.


.. code-block:: python

    import machine
    import time

    # Define the GPIO pin that is connected to the buzzer
    buzzer = machine.PWM(machine.Pin(14))

    # Define the frequencies of the notes in Hz
    C5 = 523
    D5 = 587
    E5 = 659
    F5 = 698
    G5 = 784
    A5 = 880
    B5 = 988

    # Define the durations of the notes in milliseconds
    quarter_note = 250
    half_note = 300
    whole_note = 1000

    # Define the melody as a list of tuples (note, duration)
    melody = [
        (E5, quarter_note),
        (E5, quarter_note),
        (F5, quarter_note),
        (G5, half_note),
        (G5, quarter_note),
        (F5, quarter_note),
        (E5, quarter_note),
        (D5, half_note),
        (C5, quarter_note),
        (C5, quarter_note),
        (D5, quarter_note),
        (E5, half_note),
        (E5, quarter_note),
        (D5, quarter_note),
        (D5, half_note),
        (E5, quarter_note),
        (E5, quarter_note),
        (F5, quarter_note),
        (G5, half_note),
        (G5, quarter_note),
        (F5, quarter_note),
        (E5, quarter_note),
        (D5, half_note),
        (C5, quarter_note),
        (C5, quarter_note),
        (D5, quarter_note),
        (E5, half_note),
        (D5, quarter_note),
        (C5, quarter_note),
        (C5, half_note),

    ]

    # Define a function to play a note with the given frequency and duration
    def tone(pin,frequency,duration):
        pin.freq(frequency)
        pin.duty(512)
        time.sleep_ms(duration)
        pin.duty(0)

    # Play the melody
    for note in melody:
        tone(buzzer, note[0], note[1])
        time.sleep_ms(50)


* The ``tone`` function sets the frequency of the pin to the value of ``frequency`` using the ``freq`` method of the ``pin`` object. 
* It then sets the duty cycle of the pin to 512 using the ``duty`` method of the ``pin`` object. 
* This will cause the pin to produce a tone with the specified frequency and volume for the duration of ``duration`` in milliseconds using the ``sleep_ms`` method of the time module.
* The code then plays a melody by iterating through a sequence called ``melody`` and calling the ``tone`` function for each note in the melody with the note's frequency and duration. 
* It also inserts a short pause of 50 milliseconds between each note using the ``sleep_ms`` method of the time module.
