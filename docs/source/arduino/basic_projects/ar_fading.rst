.. _ar_fading:

2.2 Verblassen
=================

Im vorherigen Projekt haben wir die LED durch Ein- und Ausschalten mit digitaler Ausgabe gesteuert. In diesem Projekt werden wir einen Atemeffekt auf der LED erzeugen, indem wir Pulsweitenmodulation (PWM) verwenden. PWM ist eine Technik, die es uns ermöglicht, die Helligkeit einer LED oder die Geschwindigkeit eines Motors zu steuern, indem wir den Tastgrad eines Rechteckwellensignals variieren.

Mit PWM werden wir anstelle des einfachen Ein- oder Ausschaltens der LED die Dauer einstellen, während der die LED pro Zyklus eingeschaltet ist im Vergleich zur Dauer, während der sie ausgeschaltet ist. Durch schnelles Umschalten der LED ein und aus in variablen Intervallen können wir den Eindruck erwecken, dass die LED allmählich heller und dunkler wird und einen Atemeffekt simuliert.

Durch die Verwendung der PWM-Funktionen des ESP32 WROOM 32E können wir eine sanfte und präzise Kontrolle über die Helligkeit der LED erreichen. Dieser Atemeffekt verleiht Ihren Projekten eine dynamische und visuell ansprechende Komponente und schafft eine auffällige Anzeige oder Atmosphäre.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein ganzes Kit zu kaufen. Hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

Sie können sie auch einzeln über die folgenden Links kaufen.

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

Dieses Projekt ist der gleiche Schaltkreis wie das erste Projekt :ref:`ar_blink`, aber der Signaltyp ist unterschiedlich. Das erste Projekt gibt digitale High- und Low-Pegel (0&1) direkt von Pin26 aus, um die LED zum Leuchten oder Ausschalten zu bringen. Dieses Projekt gibt ein PWM-Signal von Pin26 aus, um die Helligkeit der LED zu steuern.


**Verdrahtung**

.. image:: ../../img/wiring/2.1_hello_led_bb.png


**Code**

.. note::

    * Sie können die Datei ``2.2_fading_led.ino`` im Pfad ``esp32-starter-kit-main\c\codes\2.2_fading_led`` öffnen.
    * Nachdem Sie das Board (ESP32 Dev Module) und den entsprechenden Port ausgewählt haben, klicken Sie auf die **Upload**-Schaltfläche.
    * :ref:`unknown_com_port`
   
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/aa898b09-be86-473b-9bfe-317556c696bb/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Nachdem der Code erfolgreich hochgeladen wurde, können Sie die LED atmen sehen.

**Wie funktioniert das?**


#. Definition von Konstanten und Variablen.

    .. code-block:: arduino

        const int ledPin = 26; // The GPIO pin for the LED
        int brightness = 0;
        int fadeAmount = 5;
   
    * ``ledPin``: Die GPIO-Pin-Nummer, an die die LED angeschlossen ist (in diesem Fall GPIO 26).
    * ``brightness``: Der aktuelle Helligkeitswert der LED (initial auf 0 gesetzt).
    * ``fadeAmount``: Die Menge, um die sich die Helligkeit der LED in jedem Schritt ändert (auf 5 gesetzt).

#. Initialisiert den PWM-Kanal und konfiguriert den LED-Pin.

    .. code-block:: arduino

         void setup() {
            ledcSetup(0, 5000, 8); // Configure the PWM channel (0) with 5000Hz frequency and 8-bit resolution
            ledcAttachPin(ledPin, 0); // Attach the LED pin to the PWM channel
        }

    Hier verwenden wir das |link_ledc| (LED-Steuerung) Peripheriegerät, das primär zur Steuerung der Intensität von LEDs entwickelt wurde, aber auch zur Erzeugung von PWM-Signalen für andere Zwecke verwendet werden kann.

    * ``uint32_t ledcSetup(uint8_t channel, uint32_t freq, uint8_t resolution_bits);``: Diese Funktion wird verwendet, um die Frequenz und Auflösung des LEDC-Kanals einzustellen. Sie gibt die konfigurierte ``frequency`` für den LEDC-Kanal zurück. Wenn 0 zurückgegeben wird, ist ein Fehler aufgetreten und der LEDC-Kanal wurde nicht konfiguriert.
            
        * ``channel``: Wählt den LEDC-Kanal zur Konfiguration aus.
        * ``freq``: Wählt die PWM-Frequenz aus.
        * ``resolution_bits``: Wählt die Auflösung für den LEDC-Kanal aus. Der Wertebereich liegt bei 1 bis 14 Bits (1 bis 20 Bits für ESP32).

    * ``void ledcAttachPin(uint8_t pin, uint8_t chan);``: Diese Funktion dient zum Anschließen des Pins an den LEDC-Kanal.

        * ``pin``: Wählt den GPIO-Pin aus.
        * ``chan``: Wählt den LEDC-Kanal aus.

#. Die Funktion ``loop()`` enthält die Hauptlogik des Programms und läuft kontinuierlich. Sie aktualisiert die Helligkeit der LED, invertiert die Helligkeitsänderung, wenn die Helligkeit den minimalen oder maximalen Wert erreicht, und führt eine Verzögerung durch.

    .. code-block:: arduino

        void loop() {
            ledcWrite(0, brightness); // Write the new brightness value to the PWM channel
            brightness = brightness + fadeAmount;

            if (brightness <= 0 || brightness >= 255) {
                fadeAmount = -fadeAmount;
            }
            
            delay(50); // Wait for 20 milliseconds
            }

    * ``void ledcWrite(uint8_t chan, uint32_t duty);``: Diese Funktion wird verwendet, um die Duty-Zyklus für den LEDC-Kanal festzulegen.
        
        * ``chan``: Wählt den LEDC-Kanal für das Schreiben des Duty-Zyklus aus.
        * ``duty``: Wählt den Duty-Zyklus für den ausgewählten Kanal aus.