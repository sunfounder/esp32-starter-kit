.. _py_tilt:

5.2 Kippen Sie es!
==========================
Der Kippschalter ist ein einfaches, aber effektives 2-Pin-Gerät, das eine Metallkugel in seinem Zentrum enthält. Wenn der Schalter in einer aufrechten Position ist, sind die beiden Pins elektrisch verbunden, was den Stromfluss ermöglicht. Kippt der Schalter jedoch oder wird in einem bestimmten Winkel geneigt, bewegt sich die Metallkugel und unterbricht die elektrische Verbindung zwischen den Pins.

In diesem Projekt werden wir den Kippschalter nutzen, um die Beleuchtung einer LED zu steuern. Indem wir den Schalter so positionieren, dass die Kippaktion ausgelöst wird, können wir die LED basierend auf der Ausrichtung des Schalters ein- und ausschalten.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein komplettes Set zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ITEMS IN THIS KIT
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
    *   - :ref:`cpn_tilt`
        - \-

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
    (d.h. beim Einschalten) festzulegen.

    
    .. list-table::
        :widths: 5 15

        *   - Strapping Pins
            - IO5, IO0, IO2, IO12, IO15 
    

    

    Generell wird **nicht empfohlen, sie als Eingangspins zu verwenden**. Wenn Sie diese Pins verwenden möchten, bedenken Sie die möglichen Auswirkungen auf den Bootvorgang. Für weitere Details siehe den Abschnitt :ref:`esp32_strapping`.


**Schaltplan**

.. image:: ../../img/circuit/circuit_5.2_tilt.png

Wenn der Kippschalter in einer aufrechten Position ist, wird IO14 auf hoch gesetzt, was dazu führt, dass die LED leuchtet. Umgekehrt, wenn der Kippschalter gekippt ist, wird IO14 auf niedrig gesetzt, wodurch die LED erlischt.

Der Zweck des 10K-Widerstands besteht darin, einen stabilen niedrigen Zustand für IO14 aufrechtzuerhalten, wenn der Kippschalter in einer gekippten Position ist.


**Verdrahtung**

.. image:: ../../img/wiring/5.2_tilt_switch_bb.png

**Code**

.. note::

    * Öffnen Sie die Datei ``5.2_tilt_switch.py``, die sich im Pfad ``esp32-starter-kit-main\micropython\codes`` befindet, oder kopieren und fügen Sie den Code in Thonny ein. Klicken Sie dann auf "Aktuelles Skript ausführen" oder drücken Sie F5, um es auszuführen.
    * Stellen Sie sicher, dass Sie den Interpreter "MicroPython (ESP32).COMxx" in der unteren rechten Ecke ausgewählt haben.



.. code-block:: python

    import machine
    import time

    switch = machine.Pin(14, machine.Pin.IN) # Tilt switch pin
    led = machine.Pin(26, machine.Pin.OUT) # LED pin

    while True:
       # Check if the switch is tilted by reading its value
        if switch.value() == 1:
            # Turn on the LED by setting its value to 1
            led.value(1)
        else:
            # Turn off the LED
            led.value(0)

Wenn das Skript läuft, wird die LED eingeschaltet, wenn der Schalter aufrecht ist, und ausgeschaltet, wenn der Schalter gekippt ist.

