.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _py_button:

5.1 Lesen des Tastenwertes
==============================================

In diesem interaktiven Projekt wagen wir uns in die Welt der Tastensteuerung und LED-Manipulation.

Das Konzept ist unkompliziert, aber effektiv. Wir werden den Zustand einer Taste lesen. Wenn die Taste gedrückt wird, registriert sie ein hohes Spannungsniveau, oder einen 'hohen Zustand'. Diese Aktion wird dann dazu führen, dass eine LED aufleuchtet.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein komplettes Set zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

Sie können diese auch einzeln über die untenstehenden Links kaufen.

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
    *   - :ref:`cpn_button`
        - |link_button_buy|

**Verfügbare Pins**

* **Verfügbare Pins**

    Hier ist eine Liste der verfügbaren Pins auf dem ESP32-Board für dieses Projekt.

    .. list-table::
        :widths: 5 20

        *   - Für Eingang
            - IO14, IO25, I35, I34, I39, I36, IO18, IO19, IO21, IO22, IO23
        *   - Für Ausgang
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23
    
* **Bedingte Nutzung Pins (Eingang)**

    Die folgenden Pins haben eingebaute Pull-up- oder Pull-down-Widerstände, daher sind externe Widerstände nicht erforderlich, wenn **sie als Eingangspins verwendet werden**:


    .. list-table::
        :widths: 5 15
        :header-rows: 1

        *   - Bedingte Nutzung Pins
            - Beschreibung
        *   - IO13, IO15, IO2, IO4
            - Pull-up mit einem 47K-Widerstand setzt den Wert standardmäßig auf hoch.
        *   - IO27, IO26, IO33
            - Pull-up mit einem 4,7K-Widerstand setzt den Wert standardmäßig auf hoch.
        *   - IO32
            - Pull-down mit einem 1K-Widerstand setzt den Wert standardmäßig auf niedrig.


* **Strapping Pins (Eingang)**

    Strapping Pins sind eine spezielle Gruppe von Pins, die verwendet werden, um bestimmte Boot-Modi während des Startvorgangs des Geräts 
    (d. h. beim Einschalten) festzulegen.

        
    .. list-table::
        :widths: 5 15

        *   - Strapping Pins
            - IO5, IO0, IO2, IO12, IO15 
    
    Generell wird **nicht empfohlen, sie als Eingangspins zu verwenden**. Wenn Sie diese Pins verwenden möchten, bedenken Sie die möglichen Auswirkungen auf den Bootvorgang. Für weitere Details siehe den Abschnitt :ref:`esp32_strapping`.


**Schaltplan**

.. image:: ../../img/circuit/circuit_5.1_button.png

Um eine korrekte Funktionalität zu gewährleisten, verbinden Sie eine Seite des Tastenpins mit 3,3V und die andere Seite mit IO14. Wenn die Taste gedrückt wird, wird IO14 auf hoch gesetzt, was dazu führt, dass die LED aufleuchtet. Wenn die Taste losgelassen wird, kehrt IO14 in seinen schwebenden Zustand zurück, der entweder hoch oder niedrig sein kann. Um ein stabiles niedriges Niveau zu gewährleisten, wenn die Taste nicht gedrückt ist, sollte IO14 über einen 10K-Pull-down-Widerstand mit GND verbunden werden.

**Verdrahtung**

.. image:: ../../img/wiring/5.1_button_bb.png

.. note::
    
    Ein vierpoliger Taster ist in H-Form gestaltet. Wenn der Taster nicht gedrückt wird, sind die links und rechts Pins getrennt und der Strom kann zwischen ihnen nicht fließen. Wenn der Taster jedoch gedrückt wird, sind die links und rechts Pins verbunden, was einen Stromweg ermöglicht.

**Code**

.. note::

    * Öffnen Sie die Datei ``5.1_read_button_value.py``, die sich im Pfad ``esp32-starter-kit-main\micropython\codes`` befindet, oder kopieren und fügen Sie den Code in Thonny ein. Klicken Sie dann auf "Aktuelles Skript ausführen" oder drücken Sie F5, um es auszuführen.
    * Stellen Sie sicher, dass Sie den Interpreter "MicroPython (ESP32).COMxx" in der unteren rechten Ecke ausgewählt haben.



.. code-block:: python

    import machine
    import time

    button = machine.Pin(14, machine.Pin.IN) # Button pin
    led = machine.Pin(26, machine.Pin.OUT) # LED pin


    while True:
        # If the button is pressed by reading its value
        if button.value() == 1:
            # Turn on the LED by setting its value to 1
            led.value(1)
    #         time.sleep(0.5)
        else:
            # Turn off the LED
            led.value(0)

Während der Skriptausführung leuchtet die LED auf, wenn Sie den Taster drücken, und erlischt, wenn Sie ihn loslassen.

