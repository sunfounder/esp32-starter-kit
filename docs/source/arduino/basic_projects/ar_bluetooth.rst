.. _ar_bluetooth:

7.1 Bluetooth
===================

Dieses Projekt bietet eine Anleitung zur Entwicklung einer einfachen Bluetooth Low Energy (BLE) Seriellen Kommunikationsanwendung 
mit dem Mikrocontroller ESP32. Der ESP32 ist ein leistungsstarker Mikrocontroller, der Wi-Fi und Bluetooth 
Konnektivität integriert, was ihn zu einem idealen Kandidaten für die Entwicklung drahtloser Anwendungen macht. BLE ist 
ein energiesparendes drahtloses Kommunikationsprotokoll, das für die Nahbereichskommunikation konzipiert ist. 
Dieses Dokument beschreibt die Schritte zur Einrichtung des ESP32 als BLE-Server, um mit einem BLE-Client über eine serielle Verbindung zu kommunizieren.


**Über die Bluetooth-Funktion**

Das ESP32 WROOM 32E ist ein Modul, das Wi-Fi und Bluetooth Konnektivität in einem einzigen Chip integriert. 
Es unterstützt sowohl das Bluetooth Low Energy (BLE) als auch das klassische Bluetooth-Protokoll.

Das Modul kann sowohl als Bluetooth-Client als auch als Server verwendet werden. Als Bluetooth-Client kann das Modul sich mit 
anderen Bluetooth-Geräten verbinden und Daten mit ihnen austauschen. Als Bluetooth-Server kann das Modul 
Dienste für andere Bluetooth-Geräte bereitstellen.

Das ESP32 WROOM 32E unterstützt verschiedene Bluetooth-Profile, einschließlich des Generic Access Profile (GAP), Generic Attribute Profile (GATT) 
und Serial Port Profile (SPP). Das SPP-Profil ermöglicht es dem Modul, einen seriellen Port über Bluetooth zu emulieren, 
wodurch eine serielle Kommunikation mit anderen Bluetooth-Geräten ermöglicht wird.

Um die Bluetooth-Funktion des ESP32 WROOM 32E zu nutzen, muss es mit einem geeigneten Software 
Entwicklungskit (SDK) oder mit der Arduino IDE und der ESP32 BLE-Bibliothek programmiert werden. 
Die ESP32 BLE-Bibliothek bietet eine hochrangige Schnittstelle für die Arbeit mit BLE. Sie enthält Beispiele, die demonstrieren, 
wie man das Modul als BLE-Client und -Server verwendet.

Insgesamt bietet die Bluetooth-Funktion des ESP32 WROOM 32E eine bequeme und energiesparende Möglichkeit, drahtlose 
Kommunikation in Ihren Projekten zu ermöglichen.

**Bedienungsschritte**

Hier sind die schrittweisen Anweisungen zur Einrichtung der Bluetooth-Kommunikation zwischen Ihrem ESP32 und einem mobilen Gerät mit der LightBlue-App:

#. Laden Sie die LightBlue-App aus dem **App Store** (für iOS) oder **Google Play** (für Android) herunter.

    .. image:: img/bluetooth_lightblue.png

#. Öffnen Sie die Datei ``7.1_bluetooth.ino`` im Verzeichnis ``esp32-starter-kit-main\c\codes\7.1_bluetooth``, oder kopieren Sie den Code in die Arduino IDE.

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/388f6d9d-65bf-4eaa-b29a-7cebf0b92f74/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Um UUID-Konflikte zu vermeiden, wird empfohlen, drei neue UUIDs zufällig mit dem |link_uuid| zu generieren und sie in den folgenden Codezeilen einzufügen.

    .. code-block:: arduino

        #define SERVICE_UUID           "your_service_uuid_here" 
        #define CHARACTERISTIC_UUID_RX "your_rx_characteristic_uuid_here"
        #define CHARACTERISTIC_UUID_TX "your_tx_characteristic_uuid_here"

    .. image:: img/uuid_generate.png


#. Wählen Sie das richtige Board und den richtigen Port aus, dann klicken Sie auf die **Upload**-Taste.

    .. image:: img/bluetooth_upload.png

#. Nachdem der Code erfolgreich hochgeladen wurde, schalten Sie **Bluetooth** auf Ihrem mobilen Gerät ein und öffnen Sie die **LightBlue**-App.

    .. image:: img/bluetooth_open.png

#. Auf der **Scan**-Seite finden Sie **ESP32-Bluetooth** und klicken Sie auf **CONNECT**. Wenn Sie es nicht sehen, versuchen Sie, die Seite einige Male zu aktualisieren. Wenn **"Connected to device!"** erscheint, ist die Bluetooth-Verbindung erfolgreich. Scrollen Sie nach unten, um die drei im Code eingestellten UUIDs zu sehen.

    .. image:: img/bluetooth_connect.png
        :width: 800

#. Klicken Sie auf die UUID **Receive**. Wählen Sie das entsprechende Datenformat im Kasten rechts neben **Data Format** aus, wie z.B. "HEX" für Hexadezimal, "UTF-8-String" für Zeichen oder "Binär" für binäre Daten usw. Dann klicken Sie auf **SUBSCRIBE**.

    .. image:: img/bluetooth_read.png
        :width: 300

#. Gehen Sie zurück zur Arduino IDE, öffnen Sie den Seriellen Monitor, stellen Sie die Baudrate auf 115200 ein, tippen Sie "welcome" und drücken Sie die Eingabetaste.

    .. image:: img/bluetooth_serial.png

#. Sie sollten jetzt die "Willkommen"-Nachricht in der LightBlue-App sehen.

    .. image:: img/bluetooth_welcome.png
        :width: 400

#. Um Informationen vom mobilen Gerät zum Seriellen Monitor zu senden, klicken Sie auf die UUID Senden, stellen Sie das Datenformat auf "UTF-8-String" ein und schreiben Sie eine Nachricht.

    .. image:: img/bluetooth_send.png


#. Sie sollten die Nachricht im Seriellen Monitor sehen.

    .. image:: img/bluetooth_receive.png

**Wie funktioniert das?**

Dieser Arduino-Code ist für den Mikrocontroller ESP32 geschrieben und richtet ihn für die Kommunikation mit einem Bluetooth Low Energy (BLE) Gerät ein.

Hier eine kurze Zusammenfassung des Codes:

* **Include necessary libraries**: Der Code beginnt mit dem Einbinden der notwendigen Bibliotheken für die Arbeit mit Bluetooth Low Energy (BLE) auf dem ESP32.

    .. code-block:: arduino

        #include "BLEDevice.h"
        #include "BLEServer.h"
        #include "BLEUtils.h"
        #include "BLE2902.h"

* **Global Variables**: Der Code definiert eine Reihe von globalen Variablen, einschließlich des Bluetooth-Gerätenamens (``bleName``), Variablen zur Überwachung empfangener Texte und der Zeit der letzten Nachricht, UUIDs für den Dienst und die Merkmale sowie ein ``BLECharacteristic``-Objekt (``pCharacteristic``).

    .. code-block:: arduino

        // Define the Bluetooth device name
        const char *bleName = "ESP32_Bluetooth";

        // Define the received text and the time of the last message
        String receivedText = "";
        unsigned long lastMessageTime = 0;

        // Define the UUIDs of the service and characteristics
        #define SERVICE_UUID           "your_service_uuid_here"
        #define CHARACTERISTIC_UUID_RX "your_rx_characteristic_uuid_here"
        #define CHARACTERISTIC_UUID_TX "your_tx_characteristic_uuid_here"

        // Define the Bluetooth characteristic
        BLECharacteristic *pCharacteristic;

* **Setup**: In der Funktion ``setup()`` wird der serielle Port mit einer Baudrate von 115200 initialisiert und die Funktion ``setupBLE()`` aufgerufen, um das Bluetooth BLE einzurichten.

    .. code-block:: arduino
    
        void setup() {
           Serial.begin(115200);  // Initialize the serial port
            setupBLE();            // Initialize the Bluetooth BLE
        }

* **Main Loop**: In der Funktion ``loop()`` wird, wenn ein String über BLE empfangen wurde (d.h. ``receivedText`` ist nicht leer) und seit der letzten Nachricht mindestens 1 Sekunde vergangen ist, der empfangene String im seriellen Monitor ausgegeben, der Merkmalswert auf den empfangenen String gesetzt, eine Benachrichtigung gesendet und dann der empfangene String gelöscht. Wenn Daten auf dem seriellen Port verfügbar sind, liest es den String bis zu einem Zeilenumbruch, setzt den Merkmalswert auf diesen String und sendet eine Benachrichtigung.

    .. code-block:: arduino

        void loop() {
            // When the received text is not empty and the time since the last message is over 1 second
            // Send a notification and print the received text
            if (receivedText.length() > 0 && millis() - lastMessageTime > 1000) {
                Serial.print("Received message: ");
                Serial.println(receivedText);
                pCharacteristic->setValue(receivedText.c_str());
                pCharacteristic->notify();
                receivedText = "";
            }

            // Read data from the serial port and send it to BLE characteristic
            if (Serial.available() > 0) {
                String str = Serial.readStringUntil('\n');
                const char *newValue = str.c_str();
                pCharacteristic->setValue(newValue);
                pCharacteristic->notify();
            }
        }

* **Callbacks**: Zwei Callback-Klassen (``MyServerCallbacks`` und ``MyCharacteristicCallbacks``) sind definiert, um Ereignisse im Zusammenhang mit der Bluetooth-Kommunikation zu behandeln. ``MyServerCallbacks`` wird verwendet, um Ereignisse im Zusammenhang mit dem Verbindungsstatus (verbunden oder getrennt) des BLE-Servers zu handhaben. ``MyCharacteristicCallbacks`` dient zur Behandlung von Schreibereignissen auf dem BLE-Merkmal, d.h., wenn ein verbundenes Gerät einen String über BLE an den ESP32 sendet, wird dieser erfasst und in ``receivedText`` gespeichert, und die aktuelle Zeit wird in ``lastMessageTime`` aufgezeichnet.

    .. code-block:: arduino

        // Define the BLE server callbacks
        class MyServerCallbacks : public BLEServerCallbacks {
            // Print the connection message when a client is connected
            void onConnect(BLEServer *pServer) {
            Serial.println("Connected");
            }
            // Print the disconnection message when a client is disconnected
            void onDisconnect(BLEServer *pServer) {
            Serial.println("Disconnected");
            }
        };

        // Define the BLE characteristic callbacks
        class MyCharacteristicCallbacks : public BLECharacteristicCallbacks {
            void onWrite(BLECharacteristic *pCharacteristic) {
                // When data is received, get the data and save it to receivedText, and record the time
                std::string value = pCharacteristic->getValue();
                receivedText = String(value.c_str());
                lastMessageTime = millis();
                Serial.print("Received: ");
                Serial.println(receivedText);
            }
        };

* **Setup BLE**: In der Funktion ``setupBLE()`` werden das BLE-Gerät und der Server initialisiert, die Server-Callbacks eingestellt, der BLE-Dienst mit der definierten UUID erstellt, Merkmale zum Senden von Benachrichtigungen und zum Empfangen von Daten erstellt und zum Dienst hinzugefügt, und die Merkmal-Callbacks eingestellt. Schließlich wird der Dienst gestartet und der Server beginnt mit der Werbung.

    .. code-block:: arduino

        // Initialize the Bluetooth BLE
        void setupBLE() {
            BLEDevice::init(bleName);                        // Initialize the BLE device
            BLEServer *pServer = BLEDevice::createServer();  // Create the BLE server
            // Print the error message if the BLE server creation fails
            if (pServer == nullptr) {
                Serial.println("Error creating BLE server");
                return;
            }
            pServer->setCallbacks(new MyServerCallbacks());  // Set the BLE server callbacks

            // Create the BLE service
            BLEService *pService = pServer->createService(SERVICE_UUID);
            // Print the error message if the BLE service creation fails
            if (pService == nullptr) {
                Serial.println("Error creating BLE service");
                return;
            }
            // Create the BLE characteristic for sending notifications
            pCharacteristic = pService->createCharacteristic(CHARACTERISTIC_UUID_TX, BLECharacteristic::PROPERTY_NOTIFY);
            pCharacteristic->addDecodeor(new BLE2902());  // Add the decodeor
            // Create the BLE characteristic for receiving data
            BLECharacteristic *pCharacteristicRX = pService->createCharacteristic(CHARACTERISTIC_UUID_RX, BLECharacteristic::PROPERTY_WRITE);
            pCharacteristicRX->setCallbacks(new MyCharacteristicCallbacks());  // Set the BLE characteristic callbacks
            pService->start();                                                 // Start the BLE service
            pServer->getAdvertising()->start();                                // Start advertising
            Serial.println("Waiting for a client connection...");              // Wait for a client connection
        }

Bitte beachten Sie, dass dieser Code eine bidirektionale Kommunikation ermöglicht - er kann Daten über BLE senden und empfangen. 
Um jedoch mit spezifischer Hardware wie dem Ein- und Ausschalten einer LED zu interagieren, sollte zusätzlicher Code hinzugefügt werden, um 
die empfangenen Strings zu verarbeiten und entsprechend zu handeln.


