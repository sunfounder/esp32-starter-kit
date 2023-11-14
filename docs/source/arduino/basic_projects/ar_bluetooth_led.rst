7.2 Bluetooth-Steuerung RGB-LED
=================================

Dieses Projekt ist eine Erweiterung eines vorherigen Projekts (:ref:`ar_bluetooth`), bei dem RGB-LED-Konfigurationen und benutzerdefinierte Befehle wie "led_off", "rot", "grün" usw. hinzugefügt wurden. Diese Befehle ermöglichen die Steuerung der RGB-LED durch Senden von Befehlen von einem mobilen Gerät über LightBlue.

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

Sie können sie auch einzeln über die untenstehenden Links kaufen.

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
    *   - :ref:`cpn_rgb`
        - |link_rgb_led_buy|

**Betriebsschritte**

#. Bauen Sie den Schaltkreis auf.

    .. image:: ../../components/img/rgb_pin.jpg
        :width: 200
        :align: center

    Die RGB-LED hat 4 Pins: der längste Pin ist der gemeinsame Kathodenpin, der normalerweise mit GND verbunden ist; der linke Pin neben dem längsten Pin ist Rot; und die beiden Pins rechts sind Grün und Blau.

    .. image:: ../../img/wiring/2.3_color_light_bb.png

#. Öffnen Sie die Datei ``7.2_bluetooth_rgb_led.ino`` im Verzeichnis ``esp32-starter-kit-main\c\codes\7.2_bluetooth_rgb_led`` oder kopieren Sie den Code in die Arduino IDE.

    .. raw:: html
         
        <iframe src=https://create.arduino.cc/editor/sunfounder01/b9331c9d-e9ea-4970-87ce-bf2ca8c231b2/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Um UUID-Konflikte zu vermeiden, wird empfohlen, drei neue UUIDs mit dem |link_uuid|, bereitgestellt von der Bluetooth SIG, zufällig zu generieren und sie in den folgenden Codezeilen einzufügen.

    .. note::
        Wenn Sie bereits drei neue UUIDs im :ref:`ar_bluetooth` Projekt generiert haben, dann können Sie diese weiterhin verwenden.


    .. code-block:: arduino

        #define SERVICE_UUID           "your_service_uuid_here" 
        #define CHARACTERISTIC_UUID_RX "your_rx_characteristic_uuid_here"
        #define CHARACTERISTIC_UUID_TX "your_tx_characteristic_uuid_here"

    .. image:: img/uuid_generate.png

#. Wählen Sie das richtige Board und den richtigen Port aus, dann klicken Sie auf die **Upload**-Taste.

#. Nachdem der Code erfolgreich hochgeladen wurde, schalten Sie **Bluetooth** auf Ihrem mobilen Gerät ein und öffnen Sie die **LightBlue**-App.

    .. image:: img/bluetooth_open.png

#. Auf der **Scan**-Seite finden Sie **ESP32-Bluetooth** und klicken Sie auf **CONNECT**. Wenn Sie es nicht sehen, versuchen Sie, die Seite einige Male zu aktualisieren. Wenn **"Connected to device!"** erscheint, ist die Bluetooth-Verbindung erfolgreich. Scrollen Sie nach unten, um die drei im Code eingestellten UUIDs zu sehen.

    .. image:: img/bluetooth_connect.png
        :width: 800

#. Tippen Sie auf die Senden-UUID, dann stellen Sie das Datenformat auf "UTF-8-String" ein. Jetzt können Sie diese Befehle schreiben: "led_off", "rot", "grün", "blau", "gelb" und "lila", um zu sehen, ob die RGB-LED auf diese Anweisungen reagiert.

    .. image:: img/bluetooth_send_rgb.png
    

**Wie funktioniert das?**

Dieser Code ist eine Erweiterung eines vorherigen Projekts (:ref:`ar_bluetooth`), bei dem RGB-LED-Konfigurationen und benutzerdefinierte Befehle wie "led_off", "rot", "grün" usw. hinzugefügt wurden. Diese Befehle ermöglichen die Steuerung der RGB-LED durch Senden von Befehlen von einem mobilen Gerät über LightBlue.

Lassen Sie uns den Code Schritt für Schritt durchgehen:

* Fügen Sie neue globale Variablen für die RGB-LED-Pins, PWM-Kanäle, Frequenz und Auflösung hinzu.

    .. code-block:: arduino

        ...

        // Define RGB LED pins
        const int redPin = 27;
        const int greenPin = 26;
        const int bluePin = 25;

        // Define PWM channels
        const int redChannel = 0;
        const int greenChannel = 1;
        const int blueChannel = 2;

        ...

* Innerhalb der Funktion ``setup()`` werden die PWM-Kanäle mit der vordefinierten Frequenz und Auflösung initialisiert. Die RGB-LED-Pins werden dann ihren jeweiligen PWM-Kanälen zugeordnet.

    .. code-block:: arduino
        
        void setup() {
            ...

            // Set up PWM channels
            ledcSetup(redChannel, freq, resolution);
            ledcSetup(greenChannel, freq, resolution);
            ledcSetup(blueChannel, freq, resolution);
            
            // Attach pins to corresponding PWM channels
            ledcAttachPin(redPin, redChannel);
            ledcAttachPin(greenPin, greenChannel);
            ledcAttachPin(bluePin, blueChannel);

        }

* Modifizieren Sie die Methode ``onWrite`` in der Klasse ``MyCharacteristicCallbacks``. Diese Funktion hört auf Daten, die von der Bluetooth-Verbindung kommen. Basierend auf dem empfangenen String (wie ``"led_off"``, ``"red"``, ``"green"``, usw.) steuert sie die RGB-LED.

    .. code-block:: arduino

        // Define the BLE characteristic callbacks
        class MyCharacteristicCallbacks : public BLECharacteristicCallbacks {
            void onWrite(BLECharacteristic *pCharacteristic) {
                std::string value = pCharacteristic->getValue();
                if (value == "led_off") {
                    setColor(0, 0, 0); // turn the RGB LED off
                    Serial.println("RGB LED turned off");
                } else if (value == "red") {
                    setColor(255, 0, 0); // Red
                    Serial.println("red");
                }
                else if (value == "green") {
                    setColor(0, 255, 0); // green
                    Serial.println("green");
                }
                else if (value == "blue") {
                    setColor(0, 0, 255); // blue
                    Serial.println("blue");
                }
                else if (value == "yellow") {
                    setColor(255, 150, 0); // yellow
                    Serial.println("yellow");
                }
                else if (value == "purple") {
                    setColor(80, 0, 80); // purple
                    Serial.println("purple");
                }
            }
        };

* Schließlich wird eine Funktion hinzugefügt, um die Farbe der RGB-LED einzustellen.

    .. code-block:: arduino

        void setColor(int red, int green, int blue) {
            // For common-anode RGB LEDs, use 255 minus the color value
            ledcWrite(redChannel, red);
            ledcWrite(greenChannel, green);
            ledcWrite(blueChannel, blue);
        }

Zusammenfassend ermöglicht dieses Skript ein Fernsteuerungs-Interaktionsmodell, bei dem der ESP32 als Bluetooth Low Energy (BLE)-Server fungiert.

Der verbundene BLE-Client (wie ein Smartphone) kann String-Befehle senden, um die Farbe einer RGB-LED zu ändern. Der ESP32 gibt auch Feedback an den Client, indem er den empfangenen String zurücksendet, sodass der Client weiß, welche Operation durchgeführt wurde.

