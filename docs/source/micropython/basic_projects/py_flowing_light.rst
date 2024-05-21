.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _py_flowing_light:

6.2 Fließendes Licht
=================================

Haben Sie schon einmal daran gedacht, Ihrer Wohnfläche ein spaßiges und interaktives Element hinzuzufügen?
Dieses Projekt umfasst die Erstellung eines Lauflichts mit einem WS2812-LED-Streifen und einem Hindernisvermeidungsmodul.
Das Lauflicht ändert seine Richtung, wenn ein Hindernis erkannt wird, und wird so zu einer spannenden Ergänzung für Ihre Haus- oder Bürodekoration.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_avoid`
        - |link_avoid_buy|
    *   - :ref:`cpn_ws2812`
        - |link_ws2812_buy|

**Schaltplan**

.. image:: ../../img/circuit/circuit_6.2_flowing_led.png
    :align: center

Der WS2812-LED-Streifen besteht aus einer Reihe von einzelnen LEDs, die programmiert werden können, um verschiedene Farben und Muster anzuzeigen.
In diesem Projekt ist der Streifen so eingestellt, dass er ein Lauflicht anzeigt, das sich in eine bestimmte Richtung bewegt und 
seine Richtung ändert, wenn ein Hindernis vom Hindernisvermeidungsmodul erkannt wird.


**Verdrahtung**

.. image:: ../../img/wiring/6.2_flowing_light_bb.png
    :width: 800

**Code**

.. note::

    * Öffnen Sie die Datei ``6.2_flowing_led.py``, die sich im Pfad ``esp32-starter-kit-main\micropython\codes`` befindet, oder kopieren und fügen Sie den Code in Thonny ein. Klicken Sie dann auf "Run Current Script" oder drücken Sie F5, um ihn auszuführen.
    * Stellen Sie sicher, dass der Interpreter "MicroPython (ESP32).COMxx" in der unteren rechten Ecke ausgewählt ist. 

    
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

      # Initialize the avoid sensor
      avoid = Pin(25, Pin.IN)

      # Initialize the direction variable
      direction_forward = True

      # Initialize the reverse direction flag
      reverse_direction = False

      # Continuously loop the running light
      while True:
      
      # Read the input from the infrared sensor
      avoid_value = avoid.value()
      
      # Generate a random color for the current pixel
      color = (random.randint(0, 255), random.randint(0, 255), random.randint(0, 255))
                  
      # If no obstacle is detected
      if avoid_value:
            for i in range(num_pixels):
                  
                  # Turn on the current pixel with the random color
                  pixels[i] = color
                  
                  # Update the RGB LED strip display
                  pixels.write()
                  
                  # Turn off the current pixel
                  pixels[i] = (0, 0, 0)
                  time.sleep_ms(100)
                  
      # If detects an obstacle, change the direction of the LED strip
      else:
            for i in range(num_pixels-1, -1, -1):
                  
                  pixels[i] = color
                  pixels.write()
                  pixels[i] = (0, 0, 0)
                  time.sleep_ms(100)

Die LEDs auf dem RGB-Streifen leuchten nacheinander auf, wenn das Skript läuft. Sobald sich ein Objekt vor dem Hindernisvermeidungsmodul befindet, leuchten die LEDs auf dem RGB-Streifen nacheinander in die entgegengesetzte Richtung auf.