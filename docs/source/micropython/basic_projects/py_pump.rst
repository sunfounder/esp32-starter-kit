.. _py_pump:

4.2 Pumpen
=======================

In diesem faszinierenden Projekt werden wir uns damit beschäftigen, eine Wasserpumpe mit dem L293D zu steuern.

Bei der Steuerung von Wasserpumpen sind die Dinge im Vergleich zur Steuerung anderer Motoren etwas einfacher. Die Schönheit dieses Projekts liegt in seiner Einfachheit - es besteht keine Notwendigkeit, sich um die Drehrichtung zu kümmern. Unser Hauptziel ist es, die Wasserpumpe erfolgreich zu aktivieren und in Betrieb zu halten.

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
    *   - :ref:`cpn_pump`
        - \-
    *   - :ref:`cpn_l293d`
        - \-

**Verfügbare Pins**

Hier ist eine Liste der verfügbaren Pins auf dem ESP32-Board für dieses Projekt.

.. list-table::
    :widths: 5 20 

    * - Verfügbare Pins
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**Schaltplan**

.. image:: ../../img/circuit/circuit_4.1_motor_l293d.png


**Verdrahtung**

.. note::

    Hier wird empfohlen, zuerst die Batterie einzulegen und dann den Schalter auf dem Erweiterungsboard auf die Position ON zu schieben, um die Batterieversorgung zu aktivieren.


.. image:: ../../img/wiring/4.2_pump_l293d_bb.png

**Code**

.. note::

    * Öffnen Sie die Datei ``4.2_pumping.py``, die sich im Pfad ``esp32-starter-kit-main\micropython\codes`` befindet, oder kopieren und fügen Sie den Code in Thonny ein. Klicken Sie dann auf "Aktuelles Skript ausführen" oder drücken Sie F5, um es auszuführen.
    * Stellen Sie sicher, dass Sie den Interpreter "MicroPython (ESP32).COMxx" in der unteren rechten Ecke ausgewählt haben.



.. code-block:: python

    import machine
    import time

    # Create Pin objects representing the motor control pins and set them to output mode
    motor1A = machine.Pin(13, machine.Pin.OUT)
    motor2A = machine.Pin(14, machine.Pin.OUT)

    # Define a function to rotate the pump
    def rotate():
        motor1A.value(1)
        motor2A.value(0)

    # Define a function to stop the pump
    def stop():
        motor1A.value(0)
        motor2A.value(0)

    try:
        while True:
            rotate()  # Rotate the motor clockwise
            time.sleep(5)  # Pause for 5 seconds
            stop()  # Stop the motor
            time.sleep(2)

    except KeyboardInterrupt:
        stop()  # Stop the motor when KeyboardInterrupt is caught




Während der Skriptausführung werden Sie sehen, wie die Pumpe arbeitet und Wasser aus dem Schlauch kommt, dann für 2 Sekunden stoppt, bevor sie wieder zu arbeiten beginnt.

