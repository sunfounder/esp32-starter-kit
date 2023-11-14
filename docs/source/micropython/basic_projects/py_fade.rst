.. _py_fading:

2.2 Abblendende LED
===================================

Im vorherigen Projekt steuerten wir die LED, indem wir sie durch digitalen Ausgang ein- und ausschalteten. In diesem Projekt werden wir einen Atmungseffekt an der LED erzeugen, indem wir die Pulsweitenmodulation (PWM) nutzen. PWM ist eine Technik, die es uns ermöglicht, die Helligkeit einer LED oder die Geschwindigkeit eines Motors zu steuern, indem wir den Tastgrad eines Rechtecksignals variieren.

Mit PWM wird die LED nicht einfach ein- oder ausgeschaltet, sondern wir passen die Zeit an, in der die LED eingeschaltet ist, im Vergleich zur Zeit, in der sie ausgeschaltet ist, innerhalb jedes Zyklus an. Durch schnelles Ein- und Ausschalten der LED in unterschiedlichen Intervallen können wir die Illusion erzeugen, dass die LED allmählich heller und dunkler wird, was einen Atmungseffekt simuliert.

Durch die Nutzung der PWM-Fähigkeiten des ESP32 WROOM 32E können wir eine reibungslose und präzise Steuerung der LED-Helligkeit erreichen. Dieser Atmungseffekt fügt Ihren Projekten ein dynamisches und visuell ansprechendes Element hinzu und schafft ein auffälliges Display oder Ambiente.

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

Dieses Projekt ist der gleiche Schaltkreis wie das erste Projekt :ref:`py_blink`, aber der Signaltyp ist unterschiedlich. Im ersten Projekt wird digitaler High- und Low-Level (0&1) direkt von Pin26 ausgegeben, um die LED aufleuchten oder ausschalten zu lassen, dieses Projekt gibt ein PWM-Signal von Pin26 aus, um die Helligkeit der LED zu steuern.

**Verdrahtung**

.. image:: ../../img/wiring/2.1_hello_led_bb.png

**Code**

.. note::

    * Öffnen Sie die Datei ``2.2_fading_led.py``, die sich im Pfad ``esp32-starter-kit-main\micropython\codes`` befindet, oder kopieren und fügen Sie den Code in Thonny ein. Klicken Sie dann auf "Aktuelles Skript ausführen" oder drücken Sie F5, um es auszuführen.
    * Stellen Sie sicher, dass Sie den Interpreter "MicroPython (ESP32).COMxx" in der unteren rechten Ecke ausgewählt haben. 

.. code-block:: python

    # Import the necessary libraries
    from machine import Pin, PWM
    import time

    # Create a PWM object
    led = PWM(Pin(26), freq=1000)

    while True:
        # Gradually increase brightness
        for duty_cycle in range(0, 1024, 1):
            led.duty(duty_cycle)
            time.sleep(0.01)

        # Gradually decrease brightness
        for duty_cycle in range(1023, -1, -1):
            led.duty(duty_cycle)
            time.sleep(0.01)


Die LED wird allmählich heller, während der Code läuft.

**Wie funktioniert das?**

Insgesamt demonstriert dieser Code, wie man PWM-Signale verwendet, um die Helligkeit einer LED zu steuern.


#. Es importiert zwei Module, ``machine`` und ``time``. Das Modul ``machine`` bietet Zugriff auf die Hardware des Mikrocontrollers auf niedriger Ebene, während das Modul ``time`` Funktionen für zeitbezogene Operationen bereitstellt.

    .. code-block:: python

        import machine
        import time

#. Dann wird ein ``PWM``-Objekt zur Steuerung der an Pin 26 angeschlossenen LED initialisiert und die Frequenz des PWM-Signals auf 1000 Hz eingestellt.

    .. code-block:: python

        led = PWM(Pin(26), freq=1000)

#. Die LED wird mit einer Schleife ein- und ausgeblendet: Die äußere ``while True``-Schleife läuft unendlich. Zwei verschachtelte ``for``-Schleifen werden verwendet, um die Helligkeit der LED allmählich zu erhöhen und zu verringern. Der Tastgrad reicht von 0 bis 1023, was einen Tastgrad von 0% bis 100% darstellt.

    .. code-block:: python

        # Import the necessary libraries
        from machine import Pin, PWM
        import time

        # Create a PWM object
        led = PWM(Pin(26), freq=1000)

        while True:
            # Gradually increase brightness
            for duty_cycle in range(0, 1024, 2):
                led.duty(duty_cycle)
                time.sleep(0.01)

            # Gradually decrease brightness
            for duty_cycle in range(1023, -1, -2):
                led.duty(duty_cycle)
                time.sleep(0.01)


    * ``range()``: Erstellt eine Folge von ganzen Zahlen von 0 bis 1023. 
    * Der Tastgrad des PWM-Signals wird für jeden Wert in der Sequenz mit der ``duty()``-Methode des ``PWM``-Objekts eingestellt. 
    * ``time.sleep()``: Pausiert die Ausführung des Programms für 10 Millisekunden zwischen jeder Iteration der Schleife und erzeugt so eine allmähliche Erhöhung der Helligkeit über die Zeit.
    
