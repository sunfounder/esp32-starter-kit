.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _py_color_gradient:

6.5 Farbverlauf
=====================

Sind Sie bereit, eine Welt voller Farben zu erleben? Dieses Projekt nimmt Sie mit auf eine magische Reise, bei der Sie einen LED-Streifen steuern und sanfte Farbübergänge erzielen können. Egal, ob Sie etwas Farbe in Ihre Raumdekoration bringen oder ein spannendes Programmierprojekt suchen – dieses Projekt hat für jeden etwas zu bieten. Lassen Sie uns gemeinsam in diese farbenfrohe Welt eintauchen!

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
        - |link_esp32_extension_board|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_pot`
        - |link_potentiometer_buy|
    *   - :ref:`cpn_ws2812`
        - |link_ws2812_buy|

**Schaltplan**

.. image:: ../../img/circuit/circuit_6.5_color_gradient.png

Dieses Projekt verwendet einen LED-Streifen und ein Potentiometer, um einen Farbmischeffekt zu erzeugen. Das Potentiometer wird verwendet, um den Farbwert der LED anzupassen, der dann mit einer Farbumwandlungsfunktion in RGB-Werte umgewandelt wird. Die RGB-Werte werden dann verwendet, um die Farbe der LED zu aktualisieren.

**Verdrahtung**

.. image:: ../../img/wiring/6.5_color_strip_bb.png
    :width: 800

**Code**

.. note::

    * Öffnen Sie die Datei ``6.5_color_gradient.py``, die sich im Pfad ``esp32-starter-kit-main\micropython\codes`` befindet, oder kopieren und fügen Sie den Code in Thonny ein. Klicken Sie dann auf "Run Current Script" oder drücken Sie F5, um ihn auszuführen.
    * Stellen Sie sicher, dass der Interpreter "MicroPython (ESP32).COMxx" in der unteren rechten Ecke ausgewählt ist. 

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



Während der Code läuft, drehen Sie langsam das Potentiometer und Sie werden sehen, wie die Farbe des RGB-Streifens von Rot zu Lila übergeht.
