.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _py_rgb:

2.3 Farbiges Licht
==============================================

In diesem Projekt werden wir in die faszinierende Welt der additiven Farbmischung mit einer RGB-LED eintauchen.

Eine RGB-LED kombiniert die drei Grundfarben Rot, Grün und Blau in einem einzigen Gehäuse. Diese drei LEDs teilen sich eine gemeinsame Kathoden-Pin, während jeder Anoden-Pin die Intensität der entsprechenden Farbe steuert.

Durch Variieren der elektrischen Signalintensität, die an jede Anode angelegt wird, können wir eine breite Palette von Farben erzeugen. Zum Beispiel ergibt die Mischung von hochintensivem rotem und grünem Licht gelbes Licht, während die Kombination von blauem und grünem Licht Cyan erzeugt.

Durch dieses Projekt werden wir die Prinzipien der additiven Farbmischung erkunden und unsere Kreativität entfesseln, indem wir die RGB-LED manipulieren, um fesselnde und lebendige Farben anzuzeigen.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein ganzes Set zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

Sie können sie auch separat über die unten stehenden Links kaufen.

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_rgb`
        - |link_rgb_led_buy|


**Verfügbare Pins**

Hier ist eine Liste der verfügbaren Pins auf dem ESP32-Board für dieses Projekt.

.. list-table::
    :widths: 5 20 

    * - Verfügbare Pins
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**Schaltplan**

.. image:: ../../img/circuit/circuit_2.3_rgb.png

Die PWM-Pins Pin27, Pin26 und Pin25 steuern die Rot-, Grün- und Blau-Pins der RGB-LED und verbinden den gemeinsamen Kathoden-Pin mit GND. Dies ermöglicht es der RGB-LED, eine bestimmte Farbe anzuzeigen, indem Licht auf diesen Pins mit unterschiedlichen PWM-Werten überlagert wird.


**Verdrahtung**

.. image:: ../../components/img/rgb_pin.jpg
    :width: 200
    :align: center

Die RGB-LED hat 4 Pins: der längste Pin ist der gemeinsame Kathoden-Pin, der normalerweise mit GND verbunden wird; der linke Pin neben dem längsten Pin ist Rot; und die beiden Pins auf der rechten Seite sind Grün und Blau.

.. image:: ../../img/wiring/2.3_color_light_bb.png

**Code**

.. note::

    * Öffnen Sie die Datei ``2.3_colorful_light.py``, die sich im Pfad ``esp32-starter-kit-main\micropython\codes`` befindet, oder kopieren und fügen Sie den Code in Thonny ein. Klicken Sie dann auf "Aktuelles Skript ausführen" oder drücken Sie F5, um es auszuführen.
    * Stellen Sie sicher, dass Sie den Interpreter "MicroPython (ESP32).COMxx" in der unteren rechten Ecke ausgewählt haben. 

.. code-block:: python

    from machine import Pin, PWM
    import time

    # Define the GPIO pins for the RGB LED
    RED_PIN = 27
    GREEN_PIN = 26
    BLUE_PIN = 25


    # Set up the PWM channels
    red = PWM(Pin(RED_PIN))
    green = PWM(Pin(GREEN_PIN))
    blue = PWM(Pin(BLUE_PIN))

    # Set the PWM frequency
    red.freq(1000)
    green.freq(1000)
    blue.freq(1000)

    def set_color(r, g, b):
        red.duty(r)
        green.duty(g)
        blue.duty(b)

    while True:
        # Set different colors and wait for a while
        set_color(1023, 0, 0) # Red
        time.sleep(1)
        set_color(0, 1023, 0) # Green
        time.sleep(1)
        set_color(0, 0, 1023) # Blue
        time.sleep(1)
        set_color(1023, 0, 1023) # purple
        time.sleep(1)

Wenn das Skript ausgeführt wird, sehen Sie, wie die RGB-LEDs Rot, Grün, Blau und Lila sowie andere Farben anzeigen.

**Mehr erfahren**

Sie können auch die gewünschte Farbe mit dem folgenden Code und den bekannten Farbwerten von 0 bis 255 einstellen.

.. note::

    * Öffnen Sie die Datei ``2.3_colorful_light_rgb.py``, die sich im Pfad ``esp32-starter-kit-main\micropython\codes`` befindet, oder kopieren und fügen Sie den Code in Thonny ein. Klicken Sie dann auf "Aktuelles Skript ausführen" oder drücken Sie F5, um es auszuführen.
    * Stellen Sie sicher, dass Sie den Interpreter "MicroPython (ESP32).COMxx" in der unteren rechten Ecke ausgewählt haben. 



.. code-block:: python

    from machine import Pin, PWM
    import time

    # Define the GPIO pins for the RGB LED
    RED_PIN = 27
    GREEN_PIN = 26
    BLUE_PIN = 25

    # Set up the PWM channels
    red = PWM(Pin(RED_PIN))
    green = PWM(Pin(GREEN_PIN))
    blue = PWM(Pin(BLUE_PIN))

    # Set the PWM frequency
    red.freq(1000)
    green.freq(1000)
    blue.freq(1000)

    # Map input values from one range to another
    def interval_mapping(x, in_min, in_max, out_min, out_max):
        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

    # Convert color values (0-255) to duty cycle values (0-1023)
    def color_to_duty(rgb_value):
        rgb_value = int(interval_mapping(rgb_value,0,255,0,1023))
        return rgb_value

    def set_color(red_value,green_value,blue_value):
        red.duty(color_to_duty(red_value))
        green.duty(color_to_duty(green_value))
        blue.duty(color_to_duty(blue_value))

    while True:
        # Set different colors and wait for a while
        set_color(255, 0, 0) # Red
        time.sleep(1)
        set_color(0, 255, 0) # Green
        time.sleep(1)
        set_color(0, 0, 255) # Blue
        time.sleep(1)
        set_color(255, 0, 255) # purple
        time.sleep(1)

Dieser Code basiert auf dem vorherigen Beispiel, bildet jedoch Farbwerte von 0 bis 255 auf einen Tastgradbereich von 0 bis 1023 ab.

* Die Funktion ``interval_mapping`` ist eine Hilfsfunktion, die einen Wert von einem Bereich in einen anderen abbildet. Sie nimmt fünf Argumente an: den Eingabewert, die minimalen und maximalen Werte des Eingabebereichs und die minimalen und maximalen Werte des Ausgabebereichs. Sie gibt den Eingabewert, abgebildet auf den Ausgabebereich, zurück.

    .. code-block:: python

        def color_to_duty(rgb_value):
            rgb_value = int(interval_mapping(rgb_value,0,255,0,1023))
            return rgb_value

* Die Funktion ``color_to_duty`` nimmt einen ganzzahligen RGB-Wert (z.B. 255,0,255) entgegen und bildet ihn auf einen Tastgradwert, der für die PWM-Pins geeignet ist. Der Eingabe-RGB-Wert wird zunächst von 0-255 auf 0-1023 mit der Funktion ``interval_mapping`` abgebildet. Der Ausgabewert von ``interval_mapping`` wird dann als Tastgradwert zurückgegeben.

    .. code-block:: python

        def farbe_zu_tastgrad(rgb_wert):
            rgb_wert = int(bereichsabbildung(rgb_wert,0,255,0,1023))
            return rgb_wert

* Die Funktion ``color_set`` nimmt drei ganzzahlige Argumente an: die Rot-, Grün- und Blauwerte für die LED. Diese Werte werden an ``color_to_duty`` übergeben, um die Tastgradwerte für die PWM-Pins zu erhalten. Die Tastgradwerte werden dann mit der Methode ``duty`` für die entsprechenden Pins eingestellt.

    .. code-block:: python

        def set_color(red_value,green_value,blue_value):
            red.duty(color_to_duty(red_value))
            green.duty(color_to_duty(green_value))
            blue.duty(color_to_duty(blue_value))



