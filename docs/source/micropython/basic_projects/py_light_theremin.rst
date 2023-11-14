.. _py_light_theremin:

6.3 Licht-Theremin
=========================

Das Theremin ist ein elektronisches Musikinstrument, das keinen physischen Kontakt erfordert. Je nach Position der Hand des Spielers erzeugt es verschiedene Töne.

Sein Steuerungsteil besteht normalerweise aus zwei Metallantennen, die die Position der Hände des Thereministen erfassen und Oszillatoren mit einer Hand und die Lautstärke mit der anderen steuern. Die elektrischen Signale des Theremins werden verstärkt und an einen Lautsprecher gesendet.

Wir können das gleiche Instrument nicht mit dem ESP32 reproduzieren, aber wir können einen Fotowiderstand und einen passiven Summer verwenden, um ein ähnliches Spielgefühl zu erreichen.

* `Theremin - Wikipedia <https://en.wikipedia.org/wiki/Theremin>`_

**Benötigte Komponenten**

Für dieses Projekt benötigen wir folgende Komponenten.

Es ist definitiv praktisch, ein ganzes Kit zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

Sie können sie auch einzeln über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
        - KAUF-LINK

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|

**Schaltplan**

.. image:: ../../img/circuit/circuit_6.3_light_theremin.png

Vor dem Start des Projekts kalibrieren Sie den Bereich der Lichtintensität, indem Sie Ihre Hand über den Fotowiderstand bewegen. Die an IO26 angeschlossene LED dient während des Kalibrierungsprozesses als Indikator. Wenn die LED leuchtet, signalisiert dies den Beginn der Kalibrierung, und wenn sie ausgeschaltet ist, zeigt sie das Ende der Kalibrierung an.

Wenn Sie Ihre Hand über den Fotowiderstand bewegen, ändert sich dessen Wert entsprechend.
Nutzen Sie diese Änderung, um den Summer zu steuern und verschiedene musikalische Noten zu spielen.
Jede Variation im Wert des Fotowiderstands kann einer bestimmten musikalischen Note zugeordnet werden, wodurch 
der Summer eine Melodie erzeugt, während Sie Ihre Hand über den Fotowiderstand bewegen.


**Verdrahtung**

.. image:: ../../img/wiring/6.3_theremin_bb.png

**Code**

.. note::

    * Öffnen Sie die Datei ``6.3_light_theremin.py``, die sich im Pfad ``esp32-starter-kit-main\micropython\codes`` befindet, oder kopieren und fügen Sie den Code in Thonny ein. Klicken Sie dann auf "Run Current Script" oder drücken Sie F5, um ihn auszuführen.
    * Stellen Sie sicher, dass der Interpreter "MicroPython (ESP32).COMxx" in der unteren rechten Ecke ausgewählt ist. 

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


Nach dem Start des Programms schaltet sich die LED ein und bietet uns ein fünfsekündiges Fenster, um den Erkennungsbereich des Fotowiderstands zu kalibrieren.

Die Kalibrierung ist ein entscheidender Schritt, da sie verschiedene Lichtbedingungen berücksichtigt, auf die wir bei der Verwendung des Geräts stoßen können, 
wie unterschiedliche Lichtintensitäten zu verschiedenen Tageszeiten.
Darüber hinaus berücksichtigt der Kalibrierungsprozess die Entfernung zwischen unseren Händen 
und dem Fotowiderstand, die den spielbaren Bereich des Instruments bestimmt.

Sobald die Kalibrierungsphase beendet ist, schaltet sich die LED aus und signalisiert, dass wir das Instrument jetzt spielen können, indem wir unsere Hände über den Fotowiderstand bewegen. 
Diese Einrichtung ermöglicht es uns, Musik zu erzeugen, indem wir die Höhe unserer Hände anpassen, was ein interaktives und unterhaltsames Erlebnis bietet.
