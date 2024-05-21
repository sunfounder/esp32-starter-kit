.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _ar_7_segment:

2.5 7-Segment-Anzeige
===================================

Willkommen bei diesem faszinierenden Projekt! In diesem Projekt werden wir die bezaubernde Welt der Anzeige von Zahlen von 0 bis 9 auf einer Siebensegmentanzeige erkunden.

Stellen Sie sich vor, dieses Projekt zu starten und zu beobachten, wie ein kleines, kompaktes Display hell mit jeder Zahl von 0 bis 9 leuchtet. Es ist, als hätte man einen Miniaturbildschirm, der die Ziffern auf fesselnde Weise präsentiert. Durch die Steuerung der Signalpins können Sie mühelos die angezeigte Zahl ändern und verschiedene ansprechende Effekte erzeugen.

Durch einfache Schaltungsverbindungen und Programmierung lernen Sie, wie Sie mit der Siebensegmentanzeige interagieren und Ihre gewünschten Zahlen zum Leben erwecken können. Ob als Zähler, Uhr oder jede andere faszinierende Anwendung, die Siebensegmentanzeige wird Ihr zuverlässiger Begleiter sein und Ihren Projekten einen Hauch von Brillanz verleihen.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

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

Sie können sie auch separat über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENVORSTELLUNG
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

Hier ist das Verkabelungsprinzip im Wesentlichen das gleiche wie bei :ref:`ar_74hc595`, der einzige Unterschied ist, dass Q0-Q7 mit den a ~ g Pins der 7-Segment-Anzeige verbunden sind.

.. list-table:: Verkabelung
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
    :width: 800

**Code**

.. note::

    * Öffnen Sie die Datei ``2.5_7segment.ino`` unter dem Pfad ``esp32-starter-kit-main\c\codes\2.5_7segment``.
    * Nachdem Sie das Board (ESP32 Dev Module) und den entsprechenden Port ausgewählt haben, klicken Sie auf den **Upload**-Knopf.
    * :ref:`unknown_com_port`
    
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/937f5e3f-2d9e-4c75-8331-ace3c0876182/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nachdem der Code erfolgreich hochgeladen wurde, können Sie sehen, wie das LED-Segmentdisplay die Zahlen 0~9 nacheinander anzeigt.

**Wie funktioniert das?**

In diesem Projekt verwenden wir die Funktion ``shiftOut()``, um die Binärzahl in das Schieberegister zu schreiben.

Angenommen, das 7-Segment-Display zeigt die Zahl "2" an. Dieses Bitmuster entspricht den Segmenten **f**, **c** und **dp**, die ausgeschaltet (niedrig) sind, während die Segmente **a**, **b**, **d**, **e** und **g** eingeschaltet (hoch) sind. Das ist "01011011" in Binär und "0x5b" in hexadezimaler Schreibweise.

Daher müssten Sie ``shiftOut(DS,SHcp,MSBFIRST,0x5b)`` aufrufen, um die Zahl "2" auf dem 7-Segment-Display anzuzeigen.

.. image:: img/7_segment2.png

* `Hexadezimal <https://en.wikipedia.org/wiki/Hexadecimal>`_

* `Binär-Hex-Konverter <https://www.binaryhexconverter.com/binary-to-hex-converter>`_

Die folgende Tabelle zeigt die hexadezimalen Muster, die in das Schieberegister geschrieben werden müssen, um die Zahlen 0 bis 9 auf einem 7-Segment-Display anzuzeigen.


.. list-table:: Glyphen-Code
    :widths: 20 20 20
    :header-rows: 1

    *   - Zahlen
        - Binärcode
        - Hex-Code  
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

Schreiben Sie diese Codes in ``shiftOut()``, um das LED-Segmentdisplay die entsprechenden Zahlen anzeigen zu lassen.
