.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _py_7_segment:

2.5 Ziffernanzeige
=======================

Willkommen zu diesem faszinierenden Projekt! In diesem Projekt werden wir die zauberhafte Welt der Anzeige von Zahlen von 0 bis 9 auf einem Siebensegment-Display erkunden.

Stellen Sie sich vor, dieses Projekt auszulösen und zu beobachten, wie ein kleines, kompaktes Display mit jeder Zahl von 0 bis 9 hell leuchtet. Es ist, als hätte man einen Miniaturbildschirm, der die Ziffern auf fesselnde Weise präsentiert. Durch Steuerung der Signalleitungen können Sie die angezeigte Zahl mühelos ändern und verschiedene ansprechende Effekte erzeugen.

Durch einfache Schaltungsverbindungen und Programmierung lernen Sie, wie Sie mit dem Siebensegment-Display interagieren und Ihre gewünschten Zahlen zum Leben erwecken. Ob es sich um einen Zähler, eine Uhr oder eine andere faszinierende Anwendung handelt, das Siebensegment-Display wird Ihr zuverlässiger Begleiter sein und Ihren Projekten einen Hauch von Brillanz verleihen.

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
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_7_segment`
        - |link_7segment_buy|
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|

**Verfügbare Pins**

Hier ist eine Liste der verfügbaren Pins auf dem ESP32-Board für dieses Projekt.

.. list-table::
    :widths: 5 20 

    * - Verfügbare Pins
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**Schaltplan**

.. image:: ../../img/circuit/circuit_2.5_74hc595_7_segment.png

Hier ist das Verdrahtungsprinzip im Grunde das gleiche wie bei :ref:`py_74hc595`, der einzige Unterschied ist, dass Q0-Q7 mit den a ~ g Pins des 7-Segment-Displays verbunden sind.

.. list-table:: Verdrahtung
    :widths: 15 25
    :header-rows: 1

    *   - 74HC595
        - LED-Segmentanzeige
    *   - Q0
        - a
    *   - Q1
        - b
    *   - Q2
        - c
    *   - Q3
        - d
    *   - Q4
        - e
    *   - Q5
        - f
    *   - Q6
        - g
    *   - Q7
        - dp

**Verdrahtung**

.. image:: ../../img/wiring/2.5_segment_bb.png

**Code**

.. note::

    * Öffnen Sie die Datei ``2.5_number_display.py``, die sich im Pfad ``esp32-starter-kit-main\micropython\codes`` befindet, oder kopieren und fügen Sie den Code in Thonny ein. Klicken Sie dann auf "Aktuelles Skript ausführen" oder drücken Sie F5, um es auszuführen.
    * Stellen Sie sicher, dass Sie den Interpreter "MicroPython (ESP32).COMxx" in der unteren rechten Ecke ausgewählt haben. 

.. code-block:: python

    import machine
    import time

    # Define the segment code for a common anode 7-segment display
    SEGCODE = [0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f]

    # Initialize the pins for the 74HC595 shift register
    sdi = machine.Pin(25, machine.Pin.OUT)  # DS
    rclk = machine.Pin(27, machine.Pin.OUT)  # STcp
    srclk = machine.Pin(26, machine.Pin.OUT)  # SHcp

    # Define the hc595_shift function to shift data into the 74HC595 shift register
    def hc595_shift(dat):
        # Set the RCLK pin to low
        rclk.off()
        
        # Iterate through each bit (from 7 to 0)
        for bit in range(7, -1, -1):
            # Extract the current bit from the input data
            value = 1 & (dat >> bit)
            
            # Set the SRCLK pin to low
            srclk.off()
            
            # Set the value of the SDI pin
            sdi.value(value)
            
            # Clock the current bit into the shift register by setting the SRCLK pin to high
            srclk.on()
            
        # Latch the data into the storage register by setting the RCLK pin to high
        rclk.on()

    # Continuously loop through the numbers 0 to 9 and display them on the 7-segment display
    while True:
        for num in range(10):
            hc595_shift(SEGCODE[num])  # Shift the segment code for the current number into the 74HC595
            time.sleep_ms(500)  # Wait 500 milliseconds before displaying the next number


    

Wenn das Skript läuft, können Sie sehen, wie das LED-Segmentdisplay nacheinander die Zahlen 0 bis 9 anzeigt.

**Wie funktioniert das?**

In diesem Projekt verwenden wir die Funktion ``hc595_shift()``, um die Binärzahl in das Schieberegister zu schreiben.

Angenommen, das 7-Segment-Display soll die Zahl "2" anzeigen. Dieses Bitmuster entspricht den Segmenten **f**, **c** und **dp**, die ausgeschaltet (niedrig) sind, während die Segmente **a**, **b**, **d**, **e** und **g** eingeschaltet (hoch) sind. Das entspricht "01011011" in Binär- und "0x5b" in hexadezimaler Schreibweise.

Daher müssten Sie **hc595_shift(0x5b)** aufrufen, um die Zahl "2" auf dem 7-Segment-Display anzuzeigen.

.. image:: img/7_segment2.png


* `Hexadezimal <https://en.wikipedia.org/wiki/Hexadecimal>`_

* `Binär-Hex-Konverter <https://www.binaryhexconverter.com/binary-to-hex-converter>`_

Die folgende Tabelle zeigt die hexadezimalen Muster, die in das Schieberegister geschrieben werden müssen, um die Zahlen 0 bis 9 auf einem 7-Segment-Display anzuzeigen.


.. list-table:: Glyph-Code
    :widths: 20 20 20
    :header-rows: 1

    *   - Zahlen	
        - Binärcode
        - Hexcode  
    *   - 0	
        - 00111111	
        - 0x3f
    *   - 1	
        - 00000110	
        - 0x06
    *   - 2	
        - 01011011	
        - 0x5b
    *   - 3	
        - 01001111	
        - 0x4f
    *   - 4	
        - 01100110	
        - 0x66
    *   - 5	
        - 01101101	
        - 0x6d
    *   - 6	
        - 01111101	
        - 0x7d
    *   - 7	
        - 00000111	
        - 0x07
    *   - 8	
        - 01111111	
        - 0x7f
    *   - 9	
        - 01101111	
        - 0x6f

Schreiben Sie diese Codes in ``hc595_shift()``, damit das LED-Segmentdisplay die entsprechenden Zahlen anzeigt.
