.. _py_blink:

2.1 Hallo, LED!
=======================================

Genau wie das Ausdrucken von "Hallo, Welt!" der erste Schritt beim Erlernen der Programmierung ist, so ist die Verwendung eines Programms zum Ansteuern einer LED die traditionelle Einführung in das Erlernen der physischen Programmierung.

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
    *   - :ref:`cpn_led`
        - |link_led_buy|

**Verfügbare Pins**

Hier ist eine Liste der verfügbaren Pins auf dem ESP32-Board für dieses Projekt.

.. list-table::
    :widths: 5 20 

    * - Verfügbare Pins
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**Schaltplan**

.. image:: ../../img/circuit/circuit_2.1_led.png

Dieser Schaltkreis funktioniert nach einem einfachen Prinzip, und die Stromrichtung ist in der Abbildung dargestellt. Die LED leuchtet auf, nachdem der 220-Ohm-Strombegrenzungswiderstand eingeschaltet wurde, wenn Pin26 High-Level ausgibt. Die LED schaltet sich aus, wenn Pin26 Low-Level ausgibt.

**Verdrahtung**

.. image:: ../../img/wiring/2.1_hello_led_bb.png

**Code**

.. note::

    * Öffnen Sie die Datei ``2.1_hello_led.py``, die sich im Pfad ``esp32-starter-kit-main\micropython\codes`` befindet, oder kopieren und fügen Sie den Code in Thonny ein. Klicken Sie dann auf "Aktuelles Skript ausführen" oder drücken Sie F5, um es auszuführen.
    * Stellen Sie sicher, dass Sie den Interpreter "MicroPython (ESP32).COMxx" in der unteren rechten Ecke ausgewählt haben. 



.. code-block:: python

    # Import the necessary libraries
    import machine
    import time

    # Set up the LED on pin 26 as an output pin
    led = machine.Pin(26, machine.Pin.OUT)

    # Start an infinite loop
    while True:
        # Turn on the LED by setting its value to 1 (HIGH)
        led.value(1)
        # Wait for 1 second (1000 milliseconds) while the LED is on
        time.sleep(1)

        # Turn off the LED by setting its value to 0 (LOW)
        led.value(0)
        # Wait for 0.5 seconds (500 milliseconds) while the LED is off
        time.sleep(0.5)

Nachdem der Code ausgeführt wurde, sehen Sie das Blinken der LED.


**Wie funktioniert das?**

#. Es importiert zwei Module, ``machine`` und ``time``. Das Modul ``machine`` bietet Zugriff auf die Hardware des Mikrocontrollers auf niedriger Ebene, während das Modul ``time`` Funktionen für zeitbezogene Operationen bereitstellt.

    .. code-block:: python

        import machine
        import time

#. Dann wird Pin26 als Ausgangspin mit der Funktion ``machine.Pin()`` und dem Argument ``machine.Pin.OUT`` eingerichtet. 

    .. code-block:: python

        led = machine.Pin(26, machine.Pin.OUT)

#. In der Schleife ``While True`` wird die LED für eine Sekunde eingeschaltet, indem der Wert des Pin26 auf 1 gesetzt wird (``led.value(1)``), dann wird er auf 0 gesetzt (``led.value(0)``), um sie für eine Sekunde auszuschalten, und so weiter in einer unendlichen Schleife.

    .. code-block:: python
        
        while True:
            # Turn on the LED by setting its value to 1 (HIGH)
            led.value(1)
            # Wait for 1 second (1000 milliseconds) while the LED is on
            time.sleep(1)

            # Turn off the LED by setting its value to 0 (LOW)
            led.value(0)
            # Wait for 0.5 seconds (500 milliseconds) while the LED is off
            time.sleep(0.5)




**Mehr erfahren**

In diesem Projekt haben wir die Module ``machine`` und ``time`` von MicroPython verwendet, wir können hier mehr Möglichkeiten finden, sie zu verwenden.

* `machine.Pin <https://docs.micropython.org/en/latest/library/machine.Pin.html>`_

* `time <https://docs.micropython.org/en/latest/library/time.html>`_




