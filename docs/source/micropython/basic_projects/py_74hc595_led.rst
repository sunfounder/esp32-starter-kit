.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _py_74hc595:

2.4 Mikrochip - 74HC595
===========================

Willkommen zu diesem spannenden Projekt! In diesem Projekt werden wir den 74HC595-Chip verwenden, um eine fließende Anzeige von 8 LEDs zu steuern.

Stellen Sie sich vor, dieses Projekt auszulösen und einen faszinierenden Lichtfluss zu beobachten, als ob ein funkelnder Regenbogen zwischen den 8 LEDs hin und her springt. Jede LED wird nacheinander aufleuchten und schnell verblassen, während die nächste LED weiterhin strahlt und einen wunderschönen und dynamischen Effekt erzeugt.

Durch die clevere Nutzung des 74HC595-Chips können wir die Ein- und Ausschaltzustände mehrerer LEDs steuern, um den fließenden Effekt zu erreichen. Dieser Chip verfügt über mehrere Ausgangspins, die in Serie geschaltet werden können, um die Reihenfolge der LED-Beleuchtung zu steuern. Darüber hinaus ermöglicht die Erweiterbarkeit des Chips, problemlos mehr LEDs zur fließenden Anzeige hinzuzufügen und noch spektakulärere Effekte zu erzeugen.

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
        - |link_esp32_extension_board|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|

**Verfügbare Pins**

Hier ist eine Liste der verfügbaren Pins auf dem ESP32-Board für dieses Projekt.

.. list-table::
    :widths: 5 20 

    * - Verfügbare Pins
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**Schaltplan**

.. image:: ../../img/circuit/circuit_2.4_74hc595_led.png
    :width: 600

* Wenn MR (Pin10) High-Level und CE (Pin13) Low-Level ist, werden Daten im ansteigenden Flanken von SHcp eingegeben und gehen durch die ansteigende Flanke von SHcp ins Speicherregister.
* Wenn die beiden Uhren miteinander verbunden sind, ist das Schieberegister immer einen Puls früher als das Speicherregister.
* Es gibt einen seriellen Schiebeeingang (DS), einen seriellen Ausgang (Q7') und einen asynchronen Reset-Knopf (niedriges Niveau) im Speicherregister.
* Das Speicherregister gibt einen Bus mit einem parallelen 8-Bit und in drei Zuständen aus.
* Wenn OE aktiviert ist (niedriges Niveau), werden die Daten im Speicherregister auf den Bus(Q0 ~ Q7) ausgegeben.

**Verdrahtung**

.. image:: ../../img/wiring/2.4_74hc595_bb.png
    :width: 800

**Code**

.. note::

    * Öffnen Sie die Datei ``2.4_microchip_74hc595.py``, die sich im Pfad ``esp32-starter-kit-main\micropython\codes`` befindet, oder kopieren und fügen Sie den Code in Thonny ein. Klicken Sie dann auf "Aktuelles Skript ausführen" oder drücken Sie F5, um es auszuführen.
    * Stellen Sie sicher, dass Sie den Interpreter "MicroPython (ESP32).COMxx" in der unteren rechten Ecke ausgewählt haben. 

.. code-block:: python

    import machine
    import time

    # Initialize the pins for the 74HC595 shift register
    sdi = machine.Pin(25, machine.Pin.OUT)  # DS
    rclk = machine.Pin(27, machine.Pin.OUT)  # STcp
    srclk = machine.Pin(26, machine.Pin.OUT)  # SHcp

    # Define the hc595_shift function to shift data into the 74HC595 shift register
    def hc595_shift(dat):
        # Set the RCLK pin to low
        rclk.off()
        
        # Iterate through each bit (from 7 to 0)
        for bit in range(7, -1, -1):
            # Extract the current bit from the input data
            value = 1 & (dat >> bit)
            
            # Set the SRCLK pin to low
            srclk.off()
            
            # Set the value of the SDI pin
            sdi.value(value)
            
            # Clock the current bit into the shift register by setting the SRCLK pin to high
            srclk.on()
            
        # Latch the data into the storage register by setting the RCLK pin to high
        rclk.on()

    num = 0

    # Shift data into the 74HC595 to create a moving LED pattern
    for i in range(16):
        if i < 8:
            num = (num << 1) + 1  # Shift left and set the least significant bit to 1
        elif i >= 8:
            num = (num & 0b01111111) << 1  # Mask the most significant bit and shift left
        hc595_shift(num)  # Shift the current value into the 74HC595
        print("{:0>8b}".format(num))  # Print the current value in binary format
        time.sleep_ms(200)  # Wait 200 milliseconds before shifting the next value




Während der Ausführung des Skripts sehen Sie, wie die LEDs nacheinander aufleuchten und dann in der ursprünglichen Reihenfolge ausschalten.

**Wie funktioniert das?**

Dieser Code wird verwendet, um ein 8-Bit-Schieberegister (74595) zu steuern und verschiedene binäre Werte an das Schieberegister auszugeben, wobei jeder Wert für eine bestimmte Zeit auf einer LED angezeigt wird.

#. Der Code importiert die Module ``machine`` und ``time``, wobei das Modul ``machine`` zur Steuerung der Hardware-I/O und das Modul ``time`` für die Implementierung von Zeitverzögerungen und anderen Funktionen verwendet wird.

    .. code-block:: python

        import machine
        import time

#. Drei Ausgangsports werden mit der Funktion ``machine.Pin()`` initialisiert und entsprechen dem Datenport (SDI), Speichertaktport (RCLK) und Schieberegistertaktport (SRCLK) des Schieberegisters.

    .. code-block:: python

        # Initialize the pins for the 74HC595 shift register
        sdi = machine.Pin(25, machine.Pin.OUT)  # DS
        rclk = machine.Pin(27, machine.Pin.OUT)  # STcp
        srclk = machine.Pin(26, machine.Pin.OUT)  # SHcp

#. Eine Funktion namens ``hc595_shift()`` wird definiert, um ein 8-Bit-Daten an das Schieberegister zu schreiben.

    .. code-block:: python

        def hc595_shift(dat):
            # Set the RCLK pin to low
            rclk.off()
            
            # Iterate through each bit (from 7 to 0)
            for bit in range(7, -1, -1):
                # Extract the current bit from the input data
                value = 1 & (dat >> bit)
                
                # Set the SRCLK pin to low
                srclk.off()
                
                # Set the value of the SDI pin
                sdi.value(value)
                
                # Clock the current bit into the shift register by setting the SRCLK pin to high
                srclk.on()
                
            # Latch the data into the storage register by setting the RCLK pin to high
            rclk.on()

#. Über die ``for``-Schleife.

    .. code-block:: python

        for i in range(16):
                if i < 8:
                   num = (num << 1) + 1  # Shift left and set the least significant bit to 1
                elif i >= 8:
                    num = (num & 0b01111111) << 1  # Mask the most significant bit and shift left
                hc595_shift(num)  # Shift the current value into the 74HC595
                print("{:0>8b}".format(num))  # Print the current value in binary format
                time.sleep_ms(200)  # Wait 200 milliseconds before shifting the next value

    * Die Variable ``i`` wird verwendet, um den Ausgabebinärwert zu steuern. In den ersten 8 Iterationen wird der Wert von num sukzessive 00000001, 00000011, 00000111, ..., 11111111 sein, der um ein Bit nach links verschoben und dann um 1 erhöht wird.
    * In den 9. bis 16. Iterationen wird das höchste Bit von 1 zuerst in 0 geändert und dann um ein Bit nach links verschoben, was zu den Ausgabewerten 00000010, 00000100, 00001000, ..., 10000000 führt.
    * In jeder Iteration wird der Wert von ``num`` an die Funktion ``hc595_shift()`` übergeben, um das Schieberegister zu steuern, um den entsprechenden Binärwert auszugeben.
    * Gleichzeitig mit dem Ausgeben des Binärwerts gibt die Funktion ``print()`` den Binärwert als Zeichenkette an das Terminal aus.
    * Nach dem Ausgeben des Binärwerts pausiert das Programm 200 Millisekunden mit der Funktion ``time.sleep_ms()``, damit der Wert auf der LED für eine bestimmte Zeit angezeigt bleibt.
