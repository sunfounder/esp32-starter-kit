.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _py_rgb_strip:

2.7 RGB-LED-Streifen
=========================

In diesem Projekt werden wir uns in die faszinierende Welt der Steuerung von WS2812-LED-Streifen vertiefen und eine lebendige Farbdisplay zum Leben erwecken. Mit der Möglichkeit, jede LED auf dem Streifen einzeln zu steuern, können wir fesselnde Beleuchtungseffekte erzeugen, die die Sinne verzaubern.

Darüber hinaus haben wir eine spannende Erweiterung zu diesem Projekt hinzugefügt, in der wir das Reich der Zufälligkeit erkunden werden. Indem wir zufällige Farben einführen und einen fließenden Lichteffekt implementieren, können wir ein faszinierendes visuelles Erlebnis schaffen, das fesselt und verzaubert.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_ws2812`
        - |link_ws2812_buy|

**Schaltplan**

.. image:: ../../img/circuit/circuit_2.7_ws2812.png
    :width: 500
    :align: center


**Verfügbare Pins**

Hier ist eine Liste der verfügbaren Pins auf dem ESP32-Board für dieses Projekt.

.. list-table::
    :widths: 5 20 

    * - Verfügbare Pins
      - IO13, IO12, IO14, IO27, IO26, IO25, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


.. note::

    IO33 ist für dieses Projekt nicht verfügbar.

    Der WS2812-LED-Streifen ist eine Art LED-Streifen, der ein präzises Pulsbreitenmodulations-(PWM-)Signal benötigt. Das PWM-Signal hat genaue Anforderungen sowohl in der Zeit als auch in der Spannung. Zum Beispiel entspricht ein "0"-Bit für den WS2812 einem High-Level-Puls von etwa 0,4 Mikrosekunden, während ein "1"-Bit einem High-Level-Puls von etwa 0,8 Mikrosekunden entspricht. Das bedeutet, dass der Streifen Hochfrequenzspannungsänderungen empfangen muss.

    Jedoch wird mit einem 4,7K-Pull-up-Widerstand und einem 100nf-Pull-down-Kondensator an IO33 ein einfacher Tiefpassfilter erstellt. Diese Art von Schaltung "glättet" Hochfrequenzsignale, da der Kondensator einige Zeit benötigt, um sich aufzuladen und zu entladen, wenn er Spannungsänderungen erhält. Wenn das Signal also zu schnell wechselt (d.h. hochfrequent ist), kann der Kondensator nicht mithalten. Dies führt dazu, dass das Ausgangssignal verwischt und für den Streifen unerkennbar wird.

**Verdrahtung**

.. image:: ../../img/wiring/2.7_rgb_strip_bb.png
    :width: 800

**Code**

.. note::

    * Öffnen Sie die Datei ``2.7_rgb_strip.py``, die sich im Pfad ``esp32-starter-kit-main\micropython\codes`` befindet, oder kopieren und fügen Sie den Code in Thonny ein. Klicken Sie dann auf "Aktuelles Skript ausführen" oder drücken Sie F5, um es auszuführen.
    * Stellen Sie sicher, dass Sie den Interpreter "MicroPython (ESP32).COMxx" in der unteren rechten Ecke ausgewählt haben. 

.. code-block:: python

    from machine import Pin
    from neopixel import NeoPixel

    pin = Pin(14, Pin.OUT)   # set a pin to output to drive NeoPixels
    pixels = NeoPixel(pin, 8)   # create NeoPixel driver on pin for 8 pixels

    pixels[0] = [64,154,227]    # set the pixel 
    pixels[1] = [128,0,128]
    pixels[2] = [50,150,50]
    pixels[3] = [255,30,30]
    pixels[4] = [0,128,255]
    pixels[5] = [99,199,0]
    pixels[6] = [128,128,128]
    pixels[7] = [255,100,0]

    pixels.write()              # write data to all pixels


Lassen Sie uns einige Lieblingsfarben auswählen und sie auf dem RGB-LED-Streifen anzeigen!

**Wie funktioniert das?**

#. Im Modul ``neopixel`` haben wir verwandte Funktionen in die Klasse ``NeoPixel`` integriert.

    .. code-block:: python

        from neopixel import NeoPixel

#. Verwenden Sie die Klasse ``NeoPixel`` aus dem Modul ``neopixel``, um das Objekt ``pixels`` zu initialisieren, wobei Sie den Datenpin und die Anzahl der LEDs angeben.

    .. code-block:: python

        pixels = NeoPixel(pin, 8)   # create NeoPixel driver on pin for 8 pixels

#. Stellen Sie die Farbe jeder LED ein und verwenden Sie die Methode ``write()``, um die Daten an den WS2812-LED zu senden und seine Anzeige zu aktualisieren.

    .. code-block:: python

        pixels[0] = [64,154,227]    # set the pixel 
        pixels[1] = [128,0,128]
        pixels[2] = [50,150,50]
        pixels[3] = [255,30,30]
        pixels[4] = [0,128,255]
        pixels[5] = [99,199,0]
        pixels[6] = [128,128,128]
        pixels[7] = [255,100,0]

        pixels.write()              # write data to all pixels

**Mehr erfahren**

Wir können zufällig Farben generieren und ein buntes fließendes Licht machen.

.. note::

    * Öffnen Sie die Datei ``2.7_rgb_strip_random.py``, die sich im Pfad ``esp32-starter-kit-main\micropython\codes`` befindet, oder kopieren und fügen Sie den Code in Thonny ein. Klicken Sie dann auf "Aktuelles Skript ausführen" oder drücken Sie F5, um es auszuführen.    * Stellen Sie sicher, dass Sie den Interpreter "MicroPython (ESP32).COMxx" in der unteren rechten Ecke ausgewählt haben. 


.. code-block:: python

    from machine import Pin
    import neopixel
    import time
    import random

    # Set the number of pixels for the running light
    num_pixels = 8

    # Set the data pin for the RGB LED strip
    data_pin = Pin(14, Pin.OUT)

    # Initialize the RGB LED strip object
    pixels = neopixel.NeoPixel(data_pin, num_pixels)

    # Continuously loop the running light
    while True:
        for i in range(num_pixels):
            # Generate a random color for the current pixel
            color = (random.randint(0, 255), random.randint(0, 255), random.randint(0, 255))
            
            # Turn on the current pixel with the random color
            pixels[i] = color
            
            # Update the RGB LED strip display
            pixels.write()
            
            # Turn off the current pixel
            pixels[i] = (0, 0, 0)
            
            # Wait for a period of time to control the speed of the running light
            time.sleep_ms(100)


* In der ``while``-Schleife verwenden wir eine ``for``-Schleife, um jedes Pixel des RGB-LED-Streifens nacheinander einzuschalten.
* Zuerst verwenden wir die Funktion ``random.randint()``, um eine zufällige Farbe für das aktuelle Pixel zu generieren.
* Dann schalten wir das aktuelle Pixel mit der zufälligen Farbe ein, verwenden die Methode ``write()`` des ``NeoPixel``-Objekts, um die Farbdaten an den RGB-LED-Streifen zu senden und seine Anzeige zu aktualisieren.
* Schließlich schalten wir das aktuelle Pixel aus, indem wir seine Farbe auf (0, 0, 0) einstellen, und warten eine Zeit lang, um die Geschwindigkeit des Lauflichts zu steuern.


