.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _ar_iot_mqtt:

8.4 IoT-Kommunikation mit MQTT
=======================================

Dieses Projekt konzentriert sich auf die Nutzung von MQTT, einem beliebten Kommunikationsprotokoll im Bereich des Internets der Dinge (IoT). MQTT ermöglicht es IoT-Geräten, Daten über ein Publish/Subscribe-Modell auszutauschen, bei dem Geräte über Themen kommunizieren.

In diesem Projekt erforschen wir die Implementierung von MQTT, indem wir einen Schaltkreis aufbauen, der eine LED, einen Knopf und einen Thermistor umfasst. Der ESP32-WROOM-32E-Mikrocontroller wird verwendet, um eine Verbindung zum WLAN herzustellen und mit einem MQTT-Broker zu kommunizieren. Der Code ermöglicht es dem Mikrocontroller, sich für bestimmte Themen zu abonnieren, Nachrichten zu empfangen und die LED basierend auf den empfangenen Informationen zu steuern. Zusätzlich demonstriert das Projekt das Veröffentlichen von Temperaturdaten vom Thermistor zu einem festgelegten Thema, wenn der Knopf gedrückt wird.

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
        - |link_esp32_extension_board|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_thermistor`
        - |link_thermistor_buy|

**Code hochladen**

#. Bauen Sie den Schaltkreis.

    .. note:: 
        Bei der Herstellung einer Verbindung zum WLAN können nur die Pins 36, 39, 34, 35, 32, 33 für die Analogmessung verwendet werden. Bitte stellen Sie sicher, dass der Thermistor mit diesen festgelegten Pins verbunden ist.

    .. image:: ../../img/wiring/iot_4_matt_bb.png

#. Verbinden Sie dann ESP32-WROOM-32E mit dem Computer über das USB-Kabel.

    .. image:: ../../img/plugin_esp32.png

#. Öffnen Sie den Code.

    * Öffnen Sie die Datei ``iot_4_mqtt.ino``, die sich im Verzeichnis ``esp32-starter-kit-main\c\codes\iot_4_mqtt`` befindet, oder kopieren Sie den Code in die Arduino IDE.
    * Nachdem Sie das Board (ESP32 Dev Module) und den passenden Port ausgewählt haben, klicken Sie auf den **Upload**-Knopf.
    * :ref:`unknown_com_port`
    * Hier wird die Bibliothek ``PubSubClient`` verwendet, die Sie über den **Library Manager** installieren können.

        .. image:: img/mqtt_lib.png
 
    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/e45a4bd6-9b35-47f0-af5e-92d802004087/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Suchen Sie die folgenden Zeilen und ändern Sie sie mit Ihrem ``SSID`` und ``PASSWORD``.

    .. code-block::  Arduino

        // Replace the next variables with your SSID/Password combination
        const char* ssid = "SSID";
        const char* password = "PASSWORD";

#. Finden Sie die nächste Zeile und ändern Sie Ihren ``unique_identifier``. Stellen Sie sicher, dass Ihr ``unique_identifier`` wirklich einzigartig ist, da identische IDs, die versuchen, sich bei demselben MQTT-Broker anzumelden, zu einem Anmeldefehler führen können.

    .. code-block::  Arduino

        // Add your MQTT Broker address, example:
        const char* mqtt_server = "broker.hivemq.com";
        const char* unique_identifier = "sunfounder-client-sdgvsda";  

**Themenabonnement**

#. Um Störungen durch Nachrichten anderer Teilnehmer zu vermeiden, können Sie es als obskuren oder ungewöhnlichen String setzen. Ersetzen Sie einfach das aktuelle Thema ``SF/LED`` mit Ihrem gewünschten Themennamen.

    .. note:: 
        Sie haben die Freiheit, das Thema als jeden beliebigen Charakter festzulegen. Jedes MQTT-Gerät, das das gleiche Thema abonniert hat, kann dieselbe Nachricht empfangen. Sie können auch gleichzeitig mehrere Themen abonnieren.

    .. code-block::  Arduino
        :emphasize-lines: 9

        void reconnect() {
            // Loop until we're reconnected
            while (!client.connected()) {
                Serial.print("Attempting MQTT connection...");
                // Attempt to connect
                if (client.connect(unique_identifier)) {
                    Serial.println("connected");
                    // Subscribe
                    client.subscribe("SF/LED");
                } else {
                    Serial.print("failed, rc=");
                    Serial.print(client.state());
                    Serial.println(" try again in 5 seconds");
                    // Wait 5 seconds before retrying
                    delay(5000);
                }
            }
        }

#. Ändern Sie die Funktionalität, um auf das abonnierte Thema zu reagieren. Im bereitgestellten Code wird geprüft, ob eine Nachricht zum Thema ``SF/LED`` empfangen wurde und ob die Nachricht ``on`` oder ``off`` ist. Abhängig von der empfangenen Nachricht ändert es den Ausgabestatus, um den LED-Zustand zu steuern.

    .. note::
       Sie können es für jedes Thema, das Sie abonniert haben, anpassen und Sie können mehrere if-Anweisungen schreiben, um auf mehrere Themen zu reagieren.

    .. code-block::  arduino
        :emphasize-lines: 15

        void callback(char* topic, byte* message, unsigned int length) {
            Serial.print("Message arrived on topic: ");
            Serial.print(topic);
            Serial.print(". Message: ");
            String messageTemp;

            for (int i = 0; i < length; i++) {
                Serial.print((char)message[i]);
                messageTemp += (char)message[i];
            }
            Serial.println();

            // If a message is received on the topic "SF/LED", you check if the message is either "on" or "off".
            // Changes the output state according to the message
            if (String(topic) == "SF/LED") {
                Serial.print("Changing state to ");
                if (messageTemp == "on") {
                    Serial.println("on");
                    digitalWrite(ledPin, HIGH);
                } else if (messageTemp == "off") {
                    Serial.println("off");
                    digitalWrite(ledPin, LOW);
                }
            }
        }

#. Nachdem Sie das richtige Board (ESP32 Dev Module) und den Port ausgewählt haben, klicken Sie auf den **Upload**-Knopf.

#. Öffnen Sie den seriellen Monitor und wenn die folgenden Informationen gedruckt werden, zeigt dies eine erfolgreiche Verbindung zum MQTT-Server an.

    .. code-block:: 

        WiFi connected
        IP address: 
        192.168.18.77
        Attempting MQTT connection...connected

**Nachrichtenpublikation über HiveMQ**

HiveMQ ist eine Messaging-Plattform, die als MQTT-Broker fungiert und schnellen, effizienten und zuverlässigen Datentransfer zu IoT-Geräten ermöglicht.

Unser Code nutzt speziell den MQTT-Broker von HiveMQ. Wir haben die Adresse des HiveMQ MQTT-Brokers im Code wie folgt aufgenommen:


    .. code-block::  Arduino

        // Add your MQTT Broker address, example:
        const char* mqtt_server = "broker.hivemq.com";

#. Öffnen Sie jetzt |link_hivemq| in Ihrem Webbrowser.

#. Verbinden Sie den Client mit dem Standard-öffentlichen Proxy.

    .. image:: img/sp230512_092258.png

#. Veröffentlichen Sie eine Nachricht im Thema, das Sie abonniert haben. In diesem Projekt können Sie ``on`` oder ``off`` veröffentlichen, um Ihre LED zu steuern.

    .. image:: img/sp230512_140234.png

**Nachrichtenpublikation an MQTT**

Wir können den Code auch nutzen, um Informationen an das Thema zu senden. In dieser Demonstration haben wir eine Funktion codiert, die die von dem Thermistor gemessene Temperatur an das Thema sendet, wenn Sie den Knopf drücken.

#. Klicken Sie auf **Add New Topic Subscription**.

    .. image:: img/sp230512_092341.png

#. Geben Sie die Themen ein, denen Sie folgen möchten, und klicken Sie auf **Subscribe**. Im Code senden wir Temperaturinformationen an das Thema ``SF/TEMP``.

    .. code-block::  Arduino
        :emphasize-lines: 14

        void loop() {
            if (!client.connected()) {
                reconnect();
            }
            client.loop();

            // if the button pressed, publish the temperature to topic "SF/TEMP"
            if (digitalRead(buttonPin)) {
                    long now = millis();
                    if (now - lastMsg > 5000) {
                    lastMsg = now;
                    char tempString[8];
                    dtostrf(thermistor(), 1, 2, tempString);
                    client.publish("SF/TEMP", tempString);
                }
            }
        }

#. Daher können wir dieses Thema auf HiveMQ überwachen und die von Ihnen veröffentlichten Informationen einsehen.

    .. image:: img/sp230512_154342.png

