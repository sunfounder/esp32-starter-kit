.. _ar_pa_buz:

3.2 Eigene Töne
==========================================

Wir haben im vorherigen Projekt einen aktiven Summer verwendet, dieses Mal werden wir einen passiven Summer benutzen.

Wie der aktive Summer nutzt auch der passive Summer das Phänomen der elektromagnetischen Induktion, um zu funktionieren. Der Unterschied besteht darin, dass ein passiver Summer keine eigene Oszillationsquelle hat, daher wird er bei Verwendung von Gleichstromsignalen nicht piepen.
Aber das ermöglicht es dem passiven Summer, seine eigene Oszillationsfrequenz anzupassen und verschiedene Noten wie "doh, re, mi, fa, sol, la, ti" zu erzeugen.

Lassen Sie den passiven Summer eine Melodie spielen!

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

Sie können sie auch separat über die untenstehenden Links kaufen.

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

Wenn der IO14-Ausgang hoch ist, wird nach dem 1K-Strombegrenzungswiderstand (zum Schutz des Transistors) der S8050 (NPN-Transistor) leiten, so dass der Summer ertönt.

Die Rolle des S8050 (NPN-Transistor) besteht darin, den Strom zu verstärken und den Summer lauter klingen zu lassen. Tatsächlich können Sie den Summer auch direkt an IO14 anschließen, aber Sie werden feststellen, dass der Summer leiser klingt.

**Verdrahtung**

Im Kit sind zwei Arten von Summern enthalten.
Wir müssen den passiven Summer verwenden. Drehen Sie sie um, die versiegelte Rückseite (nicht die freiliegende PCB) ist die, die wir wollen.

.. image:: ../../components/img/buzzer.png
    :width: 500
    :align: center

Der Summer benötigt beim Arbeiten einen Transistor, hier verwenden wir S8050 (NPN-Transistor).

.. image:: ../../img/wiring/3.1_buzzer_bb.png

**Code**

.. note::

    * Öffnen Sie die Datei ``3.2_custom_tone.ino`` unter dem Pfad ``esp32-starter-kit-main\c\codes\3.2_custom_tone``.
    * Nachdem Sie das Board (ESP32 Dev Module) und den entsprechenden Port ausgewählt haben, klicken Sie auf den **Upload**-Knopf.
    * :ref:`unknown_com_port`
    
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/09a319a6-6861-40e1-ba1b-e7027bc0383d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nachdem der Code erfolgreich hochgeladen wurde, hören Sie, wie der passive Summer eine Folge von 7 Musiknoten abspielt.


**Wie funktioniert das?**

#. Definieren Sie Konstanten für den Summer-Pin und die PWM-Auflösung.

    .. code-block:: arduino

        const int buzzerPin = 14; //buzzer pin
        const int resolution = 8; 

#. Definieren Sie ein Array mit den Frequenzen der 7 Musiknoten in Hz.

    .. code-block:: arduino

        int frequencies[] = {262, 294, 330, 349, 392, 440, 494};

#. Erstellen Sie eine Funktion, um eine gegebene Frequenz für eine bestimmte Dauer am Summer abzuspielen.

    .. code-block:: arduino

        void playFrequency(int frequency, int duration) {
            ledcWriteTone(0, frequency); // Start the tone
            delay(duration); // Wait for the specified duration
            ledcWriteTone(0, 0); // Stop the buzzer
        }
    
    * ``uint32_t ledcWriteTone(uint8_t chan, uint32_t freq);``: Diese Funktion wird verwendet, um den LEDC-Kanal auf 50 % PWM-Ton bei ausgewählter Frequenz einzustellen.

        * ``chan`` wählt LEDC-Kanal aus.
        * ``freq`` wählt Frequenz des PWM-Signals aus.

    Diese Funktion gibt die ``frequency`` für den Kanal zurück. Wenn ``0`` zurückgegeben wird, ist ein Fehler aufgetreten und der LEDC-Kanal wurde nicht konfiguriert.

#. Konfigurieren Sie den PWM-Kanal und verbinden Sie den Summer-Pin in der Funktion ``setup()``.

    .. code-block:: arduino

        void setup() {
            ledcSetup(0, 2000, resolution); // Set up the PWM channel
            ledcAttachPin(buzzerPin, 0); // Attach the buzzer pin to the PWM channel
        }

    * ``uint32_t ledcSetup(uint8_t channel, uint32_t freq, uint8_t resolution_bits);``: Diese Funktion wird verwendet, um die Frequenz und Auflösung des LEDC-Kanals einzurichten. Sie gibt die für den LEDC-Kanal konfigurierte ``frequency`` zurück. Wenn 0 zurückgegeben wird, ist ein Fehler aufgetreten und der LEDC-Kanal wurde nicht konfiguriert.
            
        * ``channel`` wählt LEDC-Kanal aus.
        * ``freq`` wählt Frequenz des PWM aus.
        * ``resolution_bits`` wählt Auflösung für LEDC-Kanal aus. Bereich ist 1-14 Bits (1-20 Bits für ESP32).


    * ``void ledcAttachPin(uint8_t pin, uint8_t chan);``: Diese Funktion wird verwendet, um den Pin an den LEDC-Kanal anzuschließen.

        * ``pin`` wählt GPIO-Pin aus.
        * ``chan`` wählt LEDC-Kanal aus.

#. In der Funktion ``loop()`` spielen Sie die Sequenz von 7 Noten mit einer kurzen Pause zwischen jeder Note und einer 1-sekündigen Pause vor der Wiederholung der Sequenz ab.

    .. code-block:: arduino

        void loop() {
            for (int i = 0; i < 7; i++) {
                playFrequency(frequencies[i], 300); // Play each note for 300ms
                delay(50); // Add a brief pause between the notes
            }
            delay(1000); // Wait for 1 second before replaying the sequence
        }

