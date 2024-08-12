.. note::

    Ciao, benvenuto nella Community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_iot_mqtt:

8.4 Comunicazione IoT con MQTT
=======================================

Questo progetto si concentra sull'utilizzo di MQTT, un popolare protocollo di comunicazione nel dominio dell'Internet of Things (IoT). MQTT consente ai dispositivi IoT di scambiarsi dati utilizzando un modello publish/subscribe, in cui i dispositivi comunicano attraverso argomenti (topics).

In questo progetto, esploreremo l'implementazione di MQTT costruendo un circuito che include un LED, un pulsante e un termistore. Il microcontrollore ESP32-WROOM-32E viene utilizzato per stabilire una connessione WiFi e comunicare con un broker MQTT. Il codice consente al microcontrollore di iscriversi a specifici argomenti, ricevere messaggi e controllare il LED in base alle informazioni ricevute. Inoltre, il progetto dimostra come pubblicare i dati di temperatura dal termistore a un argomento designato quando viene premuto il pulsante.

**Componenti Necessari**

Per questo progetto, avremo bisogno dei seguenti componenti.

È sicuramente conveniente acquistare un kit completo, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - ELEMENTI IN QUESTO KIT
        - LINK
    *   - Kit Iniziale ESP32
        - 320+
        - |link_esp32_starter_kit|

Puoi anche acquistarli separatamente dai link qui sotto.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUZIONE AI COMPONENTI
        - LINK PER L'ACQUISTO

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

**Caricamento del Codice**

#. Assembla il circuito.

    .. note:: 
        Durante la connessione al WiFi, solo i pin 36, 39, 34, 35, 32, 33 possono essere utilizzati per la lettura analogica. Assicurati che il termistore sia collegato a questi pin designati.

    .. image:: ../../img/wiring/iot_4_matt_bb.png

#. Poi, collega l'ESP32-WROOM-32E al computer utilizzando il cavo USB.

    .. image:: ../../img/plugin_esp32.png

#. Apri il codice.

    * Apri il file ``iot_4_mqtt.ino`` situato nella directory ``esp32-starter-kit-main\c\codes\iot_4_mqtt``, oppure copia il codice nell'IDE di Arduino.
    * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta appropriate, clicca sul pulsante **Upload**.
    * :ref:`unknown_com_port`
    * Qui viene utilizzata la libreria ``PubSubClient``, che puoi installare dal **Library Manager**.

        .. image:: img/mqtt_lib.png
 
    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/e45a4bd6-9b35-47f0-af5e-92d802004087/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Individua le seguenti righe e modificale con il tuo ``SSID`` e ``PASSWORD``.

    .. code-block::  Arduino

        // Sostituisci le prossime variabili con la combinazione SSID/Password
        const char* ssid = "SSID";
        const char* password = "PASSWORD";

#. Trova la seguente riga e modifica il tuo ``unique_identifier``. Assicurati che il tuo ``unique_identifier`` sia davvero unico, poiché qualsiasi ID identico che tenta di accedere allo stesso MQTT Broker potrebbe causare un fallimento del login.

    .. code-block::  Arduino

        // Aggiungi l'indirizzo del tuo Broker MQTT, esempio:
        const char* mqtt_server = "broker.hivemq.com";
        const char* unique_identifier = "sunfounder-client-sdgvsda";  

**Sottoscrizione a un Topic**

#. Per evitare interferenze con i messaggi inviati da altri partecipanti, puoi impostarlo come una stringa oscura o poco comune. Sostituisci semplicemente l'attuale topic ``SF/LED`` con il nome dell'argomento che desideri.

    .. note:: 
        Hai la libertà di impostare il Topic con qualsiasi carattere desideri. Qualsiasi dispositivo MQTT che si è iscritto allo stesso Topic sarà in grado di ricevere lo stesso messaggio. Puoi anche iscriverti contemporaneamente a più Topic.

    .. code-block::  Arduino
        :emphasize-lines: 9

        void reconnect() {
            // Cicla finché non siamo riconnessi
            while (!client.connected()) {
                Serial.print("Attempting MQTT connection...");
                // Tentativo di connessione
                if (client.connect(unique_identifier)) {
                    Serial.println("connected");
                    // Sottoscrizione
                    client.subscribe("SF/LED");
                } else {
                    Serial.print("failed, rc=");
                    Serial.print(client.state());
                    Serial.println(" try again in 5 seconds");
                    // Attendi 5 secondi prima di riprovare
                    delay(5000);
                }
            }
        }

#. Modifica la funzionalità per rispondere al topic sottoscritto. Nel codice fornito, se viene ricevuto un messaggio sul topic ``SF/LED``, verifica se il messaggio è ``on`` o ``off``. A seconda del messaggio ricevuto, cambia lo stato di output per controllare l'accensione o lo spegnimento del LED.

    .. note::
       Puoi modificarlo per qualsiasi topic a cui sei iscritto, e puoi scrivere più istruzioni if per rispondere a più topic.

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

            // Se viene ricevuto un messaggio sul topic "SF/LED", controlla se il messaggio è "on" o "off".
            // Cambia lo stato dell'output in base al messaggio
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

#. Dopo aver selezionato la scheda corretta (ESP32 Dev Module) e la porta, clicca sul pulsante **Upload**.

#. Apri il monitor seriale e se viene stampata la seguente informazione, indica che la connessione al server MQTT è avvenuta con successo.

    .. code-block:: 

        WiFi connesso
        Indirizzo IP: 
        192.168.18.77
        Tentativo di connessione MQTT...connesso

**Pubblicazione di Messaggi tramite HiveMQ**

HiveMQ è una piattaforma di messaggistica che funziona come un broker MQTT, facilitando un trasferimento dati veloce, efficiente e affidabile ai dispositivi IoT.

Il nostro codice utilizza specificamente il broker MQTT fornito da HiveMQ. Abbiamo incluso l'indirizzo del broker MQTT di HiveMQ nel codice come segue:

    .. code-block::  Arduino

        // Aggiungi l'indirizzo del tuo Broker MQTT, esempio:
        const char* mqtt_server = "broker.hivemq.com";

#. Ora, apri il |link_hivemq| nel tuo browser web.

#. Connetti il client al proxy pubblico di default.

    .. image:: img/sp230512_092258.png

#. Pubblica un messaggio nel Topic a cui ti sei iscritto. In questo progetto, puoi pubblicare ``on`` o ``off`` per controllare il tuo LED.

    .. image:: img/sp230512_140234.png

**Pubblicazione di Messaggi su MQTT**

Possiamo anche utilizzare il codice per pubblicare informazioni sul Topic. In questa dimostrazione, abbiamo codificato una funzione che invia la temperatura misurata dal termistore al Topic quando premi il pulsante.

#. Clicca su **Add New Topic Subscription**.

    .. image:: img/sp230512_092341.png

#. Compila i topic che desideri seguire e clicca su **Subscribe**. Nel codice, inviamo le informazioni sulla temperatura al topic ``SF/TEMP``.

    .. code-block::  Arduino
        :emphasize-lines: 14

        void loop() {
            if (!client.connected()) {
                reconnect();
            }
            client.loop();

            // se il pulsante è premuto, pubblica la temperatura sul topic "SF/TEMP"
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

#. Pertanto, possiamo monitorare questo Topic su HiveMQ, permettendoci di visualizzare le informazioni che hai pubblicato.

    .. image:: img/sp230512_154342.png

