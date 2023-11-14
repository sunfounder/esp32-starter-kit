.. _ar_guess_number:

6.7 Zahlenraten
==================
Fühlst du dich glücklich? Möchtest du deine Intuition testen und herausfinden, ob du die richtige Zahl erraten kannst? Dann ist das Spiel "Zahlenraten" genau das Richtige für dich!

Mit diesem Projekt kannst du ein spannendes und unterhaltsames Glücksspiel erleben.

Die Spieler geben über eine IR-Fernbedienung Zahlen zwischen 0 und 99 ein, um die zufällig generierte Glückszahl zu erraten. 
Das System zeigt die eingegebene Zahl des Spielers auf einem LCD-Bildschirm an, zusammen mit Tipps für die obere und untere Grenze, 
um den Spieler zur richtigen Antwort zu führen. Mit jedem Versuch nähern sich die Spieler der Glückszahl, 
bis schließlich jemand den Jackpot knackt und das Spiel gewinnt!

**Benötigte Komponenten**

Für dieses Projekt benötigen wir folgende Komponenten.

Es ist definitiv praktisch, ein komplettes Set zu kaufen. Hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

Du kannst sie auch einzeln über die unten stehenden Links kaufen.

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
    *   - :ref:`cpn_receiver`
        - |link_receiver_buy|
    *   - :ref:`cpn_lcd`
        - |link_i2clcd1602_buy|

**Schaltplan**

.. image:: ../../img/circuit/circuit_6.7_guess_number.png

**Verdrahtung**

.. image:: ../../img/wiring/6.7_guess_receiver_bb.png
    :width: 800

**Code**

.. note::

    * Du kannst die Datei ``6.7_guess_number.ino`` direkt unter dem Pfad ``esp32-starter-kit-main\c\codes\6.7_guess_number`` öffnen.
    * Hier werden die Bibliotheken ``LiquidCrystal_I2C`` und ``IRremoteESP8266`` verwendet, siehe :ref:`install_lib_man` für eine Anleitung zur Installation.


.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/2e4217f5-c1b7-4859-a34d-d791bbc5e57a/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

    
* Nachdem der Code erfolgreich hochgeladen wurde, drücke irgendeine Zahlentaste auf der Fernbedienung, um das Spiel zu starten.
* Gib eine Zahl mit den Zahlentasten auf der Fernbedienung ein. Um eine einzelne Ziffer einzugeben, musst du die **cycle**-Taste zum Bestätigen drücken.
* Das System zeigt die eingegebene Zahl und die Tipps für die obere und untere Grenze auf dem LCD-Bildschirm an.
* Rate weiter, bis du die Glückszahl richtig erraten hast.
* Nach einem erfolgreichen Versuch zeigt das System eine Erfolgsmeldung an und generiert eine neue Glückszahl.

.. note:: 

    Wenn der Code und die Verkabelung korrekt sind, das LCD aber dennoch keine Inhalte anzeigt, kannst du das Potentiometer auf der Rückseite justieren, um den Kontrast zu erhöhen.



**Wie funktioniert das?**

#. In der Funktion ``setup()`` werden der I2C-LCD-Bildschirm und der IR-Empfänger initialisiert. Dann wird die Funktion ``initNewValue()`` aufgerufen, um eine neue zufällige Glückszahl zu generieren, und eine Willkommensnachricht wird auf dem LCD-Bildschirm angezeigt.

    .. code-block:: arduino

        void setup() {
            // Initialize the LCD screen
            lcd.init();
            lcd.backlight();

            // Start the serial communication
            Serial.begin(9600);

            // Enable the IR receiver
            irrecv.enableIRIn();

            // Initialize a new lucky point value
            initNewValue();
        }

#. In der Funktion ``loop`` wartet der Code auf ein Signal vom IR-Empfänger. Wenn ein Signal empfangen wird, wird die Funktion ``decodeKeyValue`` aufgerufen, um das Signal zu dekodieren und den entsprechenden Tastenwert zu erhalten.

    .. code-block:: arduino

        void loop() {
            // If a signal is received from the IR receiver
            if (irrecv.decode(&results)) {
                bool result = 0;
                String num = decodeKeyValue(results.value);

                // If the POWER button is pressed
                if (num == "POWER") {
                    initNewValue(); // Initialize a new lucky point value
                }

                // If the CYCLE button is pressed
                else if (num == "CYCLE") {
                    result = detectPoint(); // Detect the input number
                    lcdShowInput(result); // Show the result on the LCD screen
                }

                // If a number button (0-9) is pressed, 
                //add the digit to the input number 
                //and detect the number if it is greater than or equal to 10
                else if (num >= "0" && num <= "9") {
                    count = count * 10;
                    count += num.toInt();
                    if (count >= 10) {
                        result = detectPoint();
                    }
                    lcdShowInput(result);
                }
                irrecv.resume();
            }
        }

    * Abhängig vom Tastenwert wird die entsprechende Funktion aufgerufen. Wenn eine Zahlentaste gedrückt wird, wird die Variable ``count`` aktualisiert und die Funktion ``detectPoint`` aufgerufen, um zu prüfen, ob die eingegebene Zahl korrekt ist. Die Funktion ``lcdShowInput`` wird aufgerufen, um die eingegebene Zahl und die Tipps für die obere und untere Grenze auf dem LCD-Bildschirm anzuzeigen.
    * Wenn die ``POWER``-Taste gedrückt wird, wird die Funktion ``initNewValue`` aufgerufen, um eine neue Glückspunkt-Zahl zu generieren und die Willkommensnachricht auf dem LCD-Bildschirm anzuzeigen.
    * Wenn die ``CYCLE``-Taste gedrückt wird, wird die Funktion ``detectPoint`` aufgerufen, um zu prüfen, ob die eingegebene Zahl korrekt ist. Die Funktion ``lcdShowInput`` wird aufgerufen, um die eingegebene Zahl und die Tipps für die obere und untere Grenze auf dem LCD-Bildschirm anzuzeigen.
