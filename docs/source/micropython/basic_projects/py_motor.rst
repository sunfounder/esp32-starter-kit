.. _py_motor:

4.1 Kleiner Ventilator
=======================

In diesem spannenden Projekt werden wir erforschen, wie man einen Motor mit dem L293D steuert.

Der L293D ist ein vielseitiger integrierter Schaltkreis (IC), der häufig für die Motorsteuerung in Elektronik- und Robotikprojekten verwendet wird. Er kann zwei Motoren in Vorwärts- und Rückwärtsrichtung antreiben, was ihn zu einer beliebten Wahl für Anwendungen macht, die eine präzise Motorsteuerung erfordern.

Am Ende dieses fesselnden Projekts werden Sie ein gründliches Verständnis dafür haben, wie digitale Signale und PWM-Signale effektiv genutzt werden können, um Motoren zu steuern. Dieses wertvolle Wissen wird eine solide Grundlage für Ihre zukünftigen Unternehmungen in der Robotik und Mechatronik sein. Schnallen Sie sich an und machen Sie sich bereit, in die aufregende Welt der Motorsteuerung mit dem L293D einzutauchen!

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
    *   - :ref:`cpn_motor`
        - |link_motor_buy|
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

    Da der Motor einen relativ hohen Strom benötigt, ist es notwendig, zuerst die Batterie einzulegen und dann den Schalter auf dem Erweiterungsboard auf die Position ON zu schieben, um die Batterieversorgung zu aktivieren.

.. image:: ../../img/wiring/4.1_motor_l293d_bb.png

**Code**

.. note::

    * Öffnen Sie die Datei ``4.1_motor_turn.py``, die sich im Pfad ``esp32-starter-kit-main\micropython\codes`` befindet, oder kopieren und fügen Sie den Code in Thonny ein. Klicken Sie dann auf "Aktuelles Skript ausführen" oder drücken Sie F5, um es auszuführen.
    * Stellen Sie sicher, dass Sie den Interpreter "MicroPython (ESP32).COMxx" in der unteren rechten Ecke ausgewählt haben.

.. code-block:: python

    import machine
    import time

    # Create Pin objects representing the motor control pins and set them to output mode
    motor1A = machine.Pin(13, machine.Pin.OUT)
    motor2A = machine.Pin(14, machine.Pin.OUT)

    # Define a function to rotate the motor clockwise
    def clockwise():
        motor1A.value(1)
        motor2A.value(0)

    # Define a function to rotate the motor anticlockwise
    def anticlockwise():
        motor1A.value(0)
        motor2A.value(1)

    # Define a function to stop the motor
    def stop():
        motor1A.value(0)
        motor2A.value(0)

    # Enter an infinite loop

    try:
        while True:
            clockwise() # Rotate the motor clockwise
            time.sleep(1) # Pause for 1 second
            anticlockwise() # Rotate the motor anticlockwise
            time.sleep(1)
            stop() # Stop the motor
            time.sleep(2)

    except KeyboardInterrupt:
        stop()  # Stop the motor when KeyboardInterrupt is caught



Während der Skriptausführung werden Sie sehen, wie der Motor abwechselnd jede Sekunde im Uhrzeigersinn und gegen den Uhrzeigersinn dreht.


**Mehr erfahren**

Zusätzlich zum einfachen Drehen des Motors im Uhrzeigersinn und gegen den Uhrzeigersinn können Sie auch die Geschwindigkeit der Motorrotation steuern, indem Sie die Pulsbreitenmodulation (PWM) am Steuerpin verwenden, wie unten gezeigt.

.. note::

    * Öffnen Sie die Datei ``4.1_motor_turn_pwm.py``, die sich im Pfad ``esp32-starter-kit-main\micropython\codes`` befindet, oder kopieren und fügen Sie den Code in Thonny ein. Klicken Sie dann auf "Aktuelles Skript ausführen" oder drücken Sie F5, um es auszuführen.
    * Stellen Sie sicher, dass Sie den Interpreter "MicroPython (ESP32).COMxx" in der unteren rechten Ecke ausgewählt haben.



.. code-block:: python

    from machine import Pin, PWM
    import time

    # Create PWM objects representing the motor control pins and set their frequency to 1000 Hz
    motor1A = PWM(Pin(13, Pin.OUT))
    motor2A = PWM(Pin(14, Pin.OUT))
    motor1A.freq(500)
    motor2A.freq(500)

    # Enter an infinite loop
    while True:
        # Rotate the motor forward by gradually increasing the power on the motor1A pin
        for power in range(0, 1023, 20):
            motor1A.duty(power)
            motor2A.duty(0)
            time.sleep(0.1)
        # Decreasing the power on the motor1A pin
        for power in range(1023, 0, -20):
            motor1A.duty(power)
            motor2A.duty(0)
            time.sleep(0.1)
        # Rotate the motor in the opposite direction by gradually increasing the power on the motor2A pin
        for power in range(0, 1023, 20):
            motor1A.duty(0)
            motor2A.duty(power)
            time.sleep(0.1)
        # Decreasing the power on the motor2A pin
        for power in range(1023, 0, -20):
            motor1A.duty(0)
            motor2A.duty(power)
            time.sleep(0.1)


Im Gegensatz zum vorherigen Skript wird hier der Motor durch PWM-Signale mit einer Frequenz von 1000 Hz gesteuert, die die Geschwindigkeit des Motors bestimmt.

* Der Code verwendet eine ``while True``-Schleife, um kontinuierlich zu laufen. Innerhalb der Schleife gibt es vier ``for``-Schleifen, die die Motoren in einer Sequenz steuern.
* Die ersten beiden ``for``-Schleifen erhöhen und verringern die Geschwindigkeit von IN1, während IN2 auf 0 Geschwindigkeit gehalten wird.
* Die nächsten beiden ``for``-Schleifen erhöhen und verringern die Geschwindigkeit von IN2, während IN1 auf 0 Geschwindigkeit gehalten wird.
* Die ``range``-Funktion in jeder ``for``-Schleife erzeugt eine Reihe von Zahlen, die als Tastgrad des PWM-Signals dient. Dies wird dann über die ``duty``-Methode an IN1 oder IN2 ausgegeben. Der Tastgrad bestimmt den Prozentsatz der Zeit, in der das PWM-Signal hoch ist, was wiederum die durchschnittliche Spannung bestimmt, die am Motor anliegt, und damit die Motorgeschwindigkeit.
* Die Funktion ``time.sleep`` wird verwendet, um eine Verzögerung von 0,1 Sekunden zwischen jedem Schritt in der Sequenz einzuführen, was es dem Motor ermöglicht, die Geschwindigkeit allmählich zu ändern, anstatt sofort von einer Geschwindigkeit zur anderen zu springen.
