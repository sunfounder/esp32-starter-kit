.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _py_pir:

5.5 Menschliche Bewegungen erkennen
========================================

Ein Passiv-Infrarotsensor (PIR-Sensor) ist ein verbreiteter Sensor, der Infrarotstrahlung (IR), die von Objekten in seinem Sichtfeld emittiert wird, messen kann.
Einfach ausgedrückt empfängt er die von menschlichen Körpern ausgehende Infrarotstrahlung und erkennt somit die Bewegung von Personen und anderen Lebewesen.
Genauer gesagt signalisiert er der Hauptsteuerplatine, dass jemand Ihren Raum betreten hat.

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

Sie können diese auch separat über die untenstehenden Links kaufen.

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
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_pir`
        - |link_pir_buy|

**Verfügbare Pins**

* **Verfügbare Pins**

    Hier ist eine Liste der verfügbaren Pins auf dem ESP32-Board für dieses Projekt.

    .. list-table::
        :widths: 5 20

        *   - Für Eingang
            - IO13, IO14, IO27, IO26, IO25, IO33, I35, I34, I39, I36, IO4, IO18, IO19, IO21, IO22, IO23
        *   - Für Ausgang
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

.. note::
    
    IO32 kann in diesem Projekt **nicht als Eingangspin verwendet werden**, da er intern mit einem 1K-Pulldown-Widerstand verbunden ist, was seinen Standardwert auf 0 setzt.

* **Strapping Pins (Eingang)**

    Strapping-Pins sind eine spezielle Gruppe von Pins, die verwendet werden, um spezifische Boot-Modi während des Gerätestarts zu bestimmen
    (d.h. Power-On-Reset).

    
    .. list-table::
        :widths: 5 15

        *   - Strapping Pins
            - IO5, IO0, IO2, IO12, IO15 
    

    

    Generell wird **nicht empfohlen, sie als Eingangspins zu verwenden**. Wenn Sie diese Pins verwenden möchten, bedenken Sie die potenziellen Auswirkungen auf den Bootvorgang. Für weitere Details, siehe Abschnitt :ref:`esp32_strapping`.


**Schaltplan**

.. image:: ../../img/circuit/circuit_5.5_pir.png

Wenn das PIR-Modul eine Bewegung erkennt, wird IO14 hochschalten und die LED leuchtet auf. Andernfalls, wenn keine Bewegung erkannt wird, bleibt IO14 niedrig und die LED erlischt.

.. note::
    Das PIR-Modul verfügt über zwei Potentiometer: eines zur Einstellung der Empfindlichkeit und das andere zur Einstellung der Erfassungsdistanz. Um das PIR-Modul besser zu nutzen, sollten Sie beide gegen den Uhrzeigersinn bis zum Anschlag drehen.

    .. image:: ../../components/img/PIR_TTE.png
        :width: 300
        :align: center

**Verdrahtung**

.. image:: ../../img/wiring/5.5_pir_bb.png

**Code**

.. note::

    * Öffnen Sie die Datei ``5.5_detect_human_movement.py``, die sich im Pfad ``esp32-starter-kit-main\micropython\codes`` befindet, oder kopieren Sie den Code in Thonny. Klicken Sie dann auf "Aktuelles Skript ausführen" oder drücken Sie F5, um es auszuführen.
    * Stellen Sie sicher, dass Sie den Interpreter "MicroPython (ESP32).COMxx" in der unteren rechten Ecke auswählen.

.. code-block:: python

    import machine
    import time

    # Define pins
    PIR_PIN = 14    # PIR sensor
    LED_PIN = 26    # LED

    # Initialize the PIR sensor pin as an input pin
    pir_sensor = machine.Pin(PIR_PIN, machine.Pin.IN, machine.Pin.PULL_DOWN)
    # Initialize the LED pin as an output pin
    led = machine.Pin(LED_PIN, machine.Pin.OUT)

    # Global flag to indicate motion detected
    motion_detected_flag = False

    # Function to handle the interrupt
    def motion_detected(pin):
        global motion_detected_flag
        print("Motion detected!")
        motion_detected_flag = True

    # Attach the interrupt to the PIR sensor pin
    pir_sensor.irq(trigger=machine.Pin.IRQ_RISING, handler=motion_detected)

    # Main loop
    while True:
        if motion_detected_flag:
            led.value(1)  # Turn on the LED
            time.sleep(5)  # Keep the LED on for 5 seconds
            led.value(0)  # Turn off the LED
            motion_detected_flag = False

Wenn das Skript läuft, leuchtet die LED für 5 Sekunden auf und geht dann aus, wenn das PIR-Modul jemanden erfasst, der vorbeigeht.

.. note::

    Das PIR-Modul verfügt über zwei Potentiometer: eines zur Einstellung der Empfindlichkeit und das andere zur Einstellung der Erfassungsdistanz. Um das PIR-Modul besser zu nutzen, sollten Sie beide gegen den Uhrzeigersinn bis zum Anschlag drehen.

    .. image:: ../../components/img/PIR_TTE.png
        :width: 300
        :align: center

**Wie funktioniert das?**


Dieser Code richtet ein einfaches Bewegungserkennungssystem mit einem PIR-Sensor und einer LED ein. Wenn eine Bewegung erkannt wird, leuchtet die LED für 5 Sekunden auf.

Hier ist eine Aufschlüsselung des Codes:

#. Definieren Sie die Interrupt-Handler-Funktion, die ausgeführt wird, wenn eine Bewegung erkannt wird:

    .. code-block:: python

        def motion_detected(pin):
            global motion_detected_flag
            print("Motion detected!")
            motion_detected_flag = True

#. Verknüpfen Sie den Interrupt mit dem PIR-Sensor-Pin, wobei der Auslöser auf "steigend" eingestellt ist (d.h., wenn der Pin von niedriger auf hohe Spannung wechselt):

    .. code-block:: python

        pir_sensor.irq(trigger=machine.Pin.IRQ_RISING, handler=motion_detected)

    Dies richtet einen Interrupt am ``pir_sensor``-Pin ein, der mit dem PIR-Bewegungssensor verbunden ist.

    Hier ist eine detaillierte Erklärung der Parameter:

    * ``trigger=machine.Pin.IRQ_RISING``: Dieser Parameter legt die Auslösebedingung für den Interrupt fest. In diesem Fall wird der Interrupt bei einer steigenden Flanke ausgelöst. Eine steigende Flanke tritt auf, wenn sich die Spannung am Pin von einem niedrigen Zustand (0V) auf einen hohen Zustand (typischerweise 3,3V oder 5V, abhängig von Ihrer Hardware) ändert. Bei einem PIR-Bewegungssensor wechselt der Ausgangspin normalerweise bei einer erkannten Bewegung von niedrig nach hoch, was die steigende Flanke zu einer geeigneten Auslösebedingung macht.

    * ``handler=motion_detected``: Dieser Parameter gibt die Funktion an, die ausgeführt wird, wenn der Interrupt ausgelöst wird. In diesem Fall wird die Funktion ``motion_detected`` als Interrupt-Handler bereitgestellt. Diese Funktion wird automatisch aufgerufen, wenn die Interruptbedingung (steigende Flanke) am ``pir_sensor``-Pin erkannt wird.

    Mit dieser Codezeile wird der PIR-Sensor so konfiguriert, dass er die Funktion ``motion_detected`` aufruft, wann immer Bewegung durch den Sensor erkannt wird, da der Ausgangspin von einem niedrigen zu einem hohen Zustand wechselt.

#. In der Hauptschleife, wenn das ``motion_detected_flag`` auf ``True`` gesetzt ist, wird die LED für 5 Sekunden eingeschaltet und dann ausgeschaltet. Das Flag wird dann auf ``False`` zurückgesetzt, um auf das nächste Bewegungsereignis zu warten.


    .. code-block:: python

        while True:
            if motion_detected_flag:
                led.value(1)  # Turn on the LED
                time.sleep(5)  # Keep the LED on for 5 seconds
                led.value(0)  # Turn off the LED
                motion_detected_flag = False
