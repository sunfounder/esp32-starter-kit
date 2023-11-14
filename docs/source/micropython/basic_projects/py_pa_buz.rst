.. _py_pa_buz:

3.2 Eigener Klang
==========================================

Im vorherigen Projekt haben wir einen aktiven Summer verwendet, dieses Mal benutzen wir einen passiven Summer.

Wie der aktive Summer nutzt auch der passive Summer das Phänomen der elektromagnetischen Induktion. Der Unterschied besteht darin, dass ein passiver Summer keine eigene Oszillationsquelle hat und daher nicht piept, wenn Gleichstromsignale verwendet werden.
Dies ermöglicht es dem passiven Summer jedoch, seine eigene Oszillationsfrequenz anzupassen und unterschiedliche Töne wie "do, re, mi, fa, sol, la, ti" zu erzeugen.

Lassen Sie den passiven Summer eine Melodie abspielen!

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
    *   - :ref:`cpn_buzzer`
        - \-
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|

**Verfügbare Pins**

Hier ist eine Liste der verfügbaren Pins auf dem ESP32-Board für dieses Projekt.

.. list-table::
    :widths: 5 20 

    * - Verfügbare Pins
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**Schaltplan**

.. image:: ../../img/circuit/circuit_3.1_buzzer.png
    :width: 500
    :align: center

Wenn der IO14-Ausgang hoch ist, leitet der S8050 (NPN-Transistor) nach dem 1K-Strombegrenzungswiderstand (zum Schutz des Transistors), sodass der Summer ertönt.

Die Rolle des S8050 (NPN-Transistor) ist es, den Strom zu verstärken und den Summer lauter klingen zu lassen. Tatsächlich können Sie den Summer auch direkt an IO14 anschließen, aber dann wird der Summer leiser klingen.

**Verdrahtung**

Im Set sind zwei Arten von Summern enthalten. 
Wir benötigen den passiven Summer. Drehen Sie ihn um, die versiegelte Rückseite (nicht die freiliegende Leiterplatte) ist die, die wir verwenden wollen.

.. image:: ../../components/img/buzzer.png
    :width: 500
    :align: center

Der Summer benötigt beim Betrieb einen Transistor, hier verwenden wir S8050 (NPN-Transistor).

.. image:: ../../img/wiring/3.1_buzzer_bb.png

**Code**

.. note::

    * Öffnen Sie die Datei ``3.2_custom_tone.py``, die sich im Pfad ``esp32-starter-kit-main\micropython\codes`` befindet, oder kopieren und fügen Sie den Code in Thonny ein. Klicken Sie dann auf "Aktuelles Skript ausführen" oder drücken Sie F5, um es auszuführen.
    * Stellen Sie sicher, dass Sie den Interpreter "MicroPython (ESP32).COMxx" in der unteren rechten Ecke ausgewählt haben.

.. code-block:: python

    import machine
    import time

    # Define the frequencies of several musical notes in Hz
    C4 = 262
    D4 = 294
    E4 = 330
    F4 = 349
    G4 = 392
    A4 = 440
    B4 = 494

    # Create a PWM object representing pin 14 and assign it to the buzzer variable
    buzzer = machine.PWM(machine.Pin(14))

    # Define a tone function that takes as input a Pin object representing the buzzer, a frequency in Hz, and a duration in milliseconds
    def tone(pin, frequency, duration):
        pin.freq(frequency) # Set the frequency
        pin.duty(512) # Set the duty cycle
        time.sleep_ms(duration) # Pause for the duration in milliseconds
        pin.duty(0) # Set the duty cycle to 0 to stop the tone

    # Play a sequence of notes with different frequency inputs and durations
    tone(buzzer, C4, 250)
    time.sleep_ms(500)
    tone(buzzer, D4, 250)
    time.sleep_ms(500)
    tone(buzzer, E4, 250)
    time.sleep_ms(500)
    tone(buzzer, F4, 250)
    time.sleep_ms(500)
    tone(buzzer, G4, 250)
    time.sleep_ms(500)
    tone(buzzer, A4, 250)
    time.sleep_ms(500)
    tone(buzzer, B4, 250)


**Wie funktioniert das?**

Wenn der passive Summer ein digitales Signal erhält, kann er nur das Zwerchfell bewegen, ohne einen Ton zu erzeugen.

Deshalb verwenden wir die Funktion ``tone()``, um das PWM-Signal zu erzeugen, damit der passive Summer klingt.

Diese Funktion hat drei Parameter:

* ``pin``: Der Pin, der den Summer steuert.
* ``frequency``: Die Tonhöhe des Summers wird durch die Frequenz bestimmt, je höher die Frequenz, desto höher die Tonhöhe.
* ``Duration``: Die Dauer des Tons.

Wir verwenden die Funktion ``duty()`` um den Tastgrad auf 512 (etwa 50%) einzustellen. Es können auch andere Zahlen sein, es muss nur ein diskontinuierliches elektrisches Signal erzeugt werden, um zu oszillieren.



**Mehr erfahren**

Wir können bestimmte Tonhöhen simulieren und so ein komplettes Musikstück spielen.


.. note::

    * Öffnen Sie die Datei ``3.2_custom_tone_music.py``, die sich im Pfad ``esp32-starter-kit-main\micropython\codes`` befindet, oder kopieren und fügen Sie den Code in Thonny ein. Klicken Sie dann auf "Aktuelles Skript ausführen" oder drücken Sie F5, um es auszuführen.
    * Stellen Sie sicher, dass Sie den Interpreter "MicroPython (ESP32).COMxx" in der unteren rechten Ecke ausgewählt haben. 

.. code-block:: python

    import machine
    import time

    # Define the GPIO pin that is connected to the buzzer
    buzzer = machine.PWM(machine.Pin(14))

    # Define the frequencies of the notes in Hz
    C5 = 523
    D5 = 587
    E5 = 659
    F5 = 698
    G5 = 784
    A5 = 880
    B5 = 988

    # Define the durations of the notes in milliseconds
    quarter_note = 250
    half_note = 300
    whole_note = 1000

    # Define the melody as a list of tuples (note, duration)
    melody = [
        (E5, quarter_note),
        (E5, quarter_note),
        (F5, quarter_note),
        (G5, half_note),
        (G5, quarter_note),
        (F5, quarter_note),
        (E5, quarter_note),
        (D5, half_note),
        (C5, quarter_note),
        (C5, quarter_note),
        (D5, quarter_note),
        (E5, half_note),
        (E5, quarter_note),
        (D5, quarter_note),
        (D5, half_note),
        (E5, quarter_note),
        (E5, quarter_note),
        (F5, quarter_note),
        (G5, half_note),
        (G5, quarter_note),
        (F5, quarter_note),
        (E5, quarter_note),
        (D5, half_note),
        (C5, quarter_note),
        (C5, quarter_note),
        (D5, quarter_note),
        (E5, half_note),
        (D5, quarter_note),
        (C5, quarter_note),
        (C5, half_note),

    ]

    # Define a function to play a note with the given frequency and duration
    def tone(pin,frequency,duration):
        pin.freq(frequency)
        pin.duty(512)
        time.sleep_ms(duration)
        pin.duty(0)

    # Play the melody
    for note in melody:
        tone(buzzer, note[0], note[1])
        time.sleep_ms(50)


* Die Funktion ``tone`` setzt die Frequenz des Pins auf den Wert von ``frequency`` unter Verwendung der ``freq``-Methode des ``pin``-Objekts.
* Anschließend setzt sie den Tastgrad des Pins auf 512 unter Verwendung der ``duty``-Methode des ``pin``-Objekts.
* Dadurch erzeugt der Pin einen Ton mit der angegebenen Frequenz und Lautstärke für die Dauer von ``duration`` in Millisekunden unter Verwendung der ``sleep_ms``-Methode des Zeitmoduls.
* Der Code spielt dann eine Melodie ab, indem er durch eine Sequenz namens ``melody`` iteriert und für jede Note in der Melodie die Funktion ``tone`` mit der Frequenz und Dauer der Note aufruft.
* Zwischen jeder Note wird auch eine kurze Pause von 50 Millisekunden unter Verwendung der ``sleep_ms``-Methode des Zeitmoduls eingefügt.

