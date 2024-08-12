.. note::

    Ciao, benvenuto nella Community di Appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirsi a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni l'accesso anticipato a nuovi annunci di prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_bluetooth:

7.1 Bluetooth
===================

Questo progetto fornisce una guida per sviluppare una semplice applicazione di comunicazione seriale Bluetooth Low Energy (BLE) 
utilizzando il microcontrollore ESP32. L'ESP32 è un potente microcontrollore che integra connettività Wi-Fi e Bluetooth, 
rendendolo un candidato ideale per sviluppare applicazioni wireless. BLE è un protocollo di comunicazione wireless a basso consumo energetico progettato per la comunicazione a corto raggio. 
Questo documento coprirà i passaggi per configurare l'ESP32 affinché agisca come server BLE e comunichi con un client BLE tramite una connessione seriale.


**Funzione Bluetooth**

L'ESP32 WROOM 32E è un modulo che integra connettività Wi-Fi e Bluetooth in un singolo chip. 
Supporta i protocolli Bluetooth Low Energy (BLE) e Classic Bluetooth.

Il modulo può essere utilizzato come client o server Bluetooth. Come client Bluetooth, 
il modulo può connettersi ad altri dispositivi Bluetooth e scambiare dati con essi. 
Come server Bluetooth, il modulo può fornire servizi ad altri dispositivi Bluetooth.

L'ESP32 WROOM 32E supporta vari profili Bluetooth, tra cui il Generic Access Profile
 (GAP), il Generic Attribute Profile (GATT) e il Serial Port Profile (SPP). Il profilo 
 SPP consente al modulo di emulare una porta seriale tramite Bluetooth, abilitando la comunicazione seriale con altri dispositivi Bluetooth.

Per utilizzare la funzione Bluetooth dell'ESP32 WROOM 32E, è necessario programmarlo 
utilizzando un kit di sviluppo software (SDK) appropriato o utilizzando l'IDE di 
Arduino con la libreria ESP32 BLE. 
La libreria ESP32 BLE fornisce un'interfaccia ad alto livello per lavorare con BLE. 
Include esempi che dimostrano 
come utilizzare il modulo come client e server BLE.

In generale, la funzione Bluetooth dell'ESP32 WROOM 32E offre un modo conveniente e a 
basso consumo per abilitare la comunicazione wireless nei tuoi progetti.

**Passaggi Operativi**

Ecco le istruzioni passo passo per configurare la comunicazione Bluetooth tra il tuo 
ESP32 e un dispositivo mobile utilizzando l'app LightBlue:

#. Scarica l'app LightBlue dall'**App Store** (per iOS) o da **Google Play** (per Android).

    .. image:: img/bluetooth_lightblue.png

#. Apri il file ``7.1_bluetooth.ino`` situato nella directory ``esp32-starter-kit-main\c\codes\7.1_bluetooth``, o copia il codice nell'IDE di Arduino.

    .. raw:: html
        
        <iframe src=https://create.arduino.cc/editor/sunfounder01/388f6d9d-65bf-4eaa-b29a-7cebf0b92f74/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Per evitare conflitti di UUID, si consiglia di generare casualmente tre nuovi UUID utilizzando il |link_uuid|, e di inserirli nelle seguenti righe di codice.

    .. code-block:: arduino

        #define SERVICE_UUID           "your_service_uuid_here" 
        #define CHARACTERISTIC_UUID_RX "your_rx_characteristic_uuid_here"
        #define CHARACTERISTIC_UUID_TX "your_tx_characteristic_uuid_here"

    .. image:: img/uuid_generate.png


#. Seleziona la scheda e la porta corrette, quindi clicca sul pulsante **Carica**.

    .. image:: img/bluetooth_upload.png

#. Dopo che il codice è stato caricato con successo, attiva il **Bluetooth** sul tuo dispositivo mobile e apri l'app **LightBlue**.

    .. image:: img/bluetooth_open.png

#. Nella pagina **Scan**, trova **ESP32-Bluetooth** e clicca su **CONNECT**. Se non lo vedi, prova a ricaricare la pagina alcune volte. Quando appare **"Connected to device!"**, la connessione Bluetooth è avvenuta con successo. Scorri verso il basso per vedere i tre UUID impostati nel codice.

    .. image:: img/bluetooth_connect.png
        :width: 800

#. Clicca sull'UUID **Receive**. Seleziona il formato dati appropriato nel riquadro a destra di **Data Format**, come "HEX" per esadecimale, "UTF-8 String" per carattere, o "Binary" per binario, ecc. Poi clicca su **SUBSCRIBE**.

    .. image:: img/bluetooth_read.png
        :width: 300

#. Torna all'IDE di Arduino, apri il Monitor Seriale, imposta il baud rate a 115200, poi digita "welcome" e premi Invio.

    .. image:: img/bluetooth_serial.png

#. Ora dovresti vedere il messaggio "welcome" nell'app LightBlue.

    .. image:: img/bluetooth_welcome.png
        :width: 400

#. Per inviare informazioni dal dispositivo mobile al Monitor Seriale, clicca sull'UUID Send, imposta il formato dati su "UTF-8 String" e scrivi un messaggio.

    .. image:: img/bluetooth_send.png


#. Dovresti vedere il messaggio nel Monitor Seriale.

    .. image:: img/bluetooth_receive.png

**Come funziona?**

Questo codice Arduino è scritto per il microcontrollore ESP32 e lo configura per comunicare con un dispositivo Bluetooth Low Energy (BLE).

Di seguito è riportato un breve riassunto del codice:

* **Includere le librerie necessarie**: Il codice inizia includendo le librerie necessarie per lavorare con Bluetooth Low Energy (BLE) sull'ESP32.

    .. code-block:: arduino

        #include "BLEDevice.h"
        #include "BLEServer.h"
        #include "BLEUtils.h"
        #include "BLE2902.h"

* **Variabili Globali**: Il codice definisce un set di variabili globali tra cui il nome del dispositivo Bluetooth (``bleName``), variabili per tenere traccia del testo ricevuto e del tempo dell'ultimo messaggio, UUID per il servizio e le caratteristiche, e un oggetto ``BLECharacteristic`` (``pCharacteristic``).
    
    .. code-block:: arduino

        // Definire il nome del dispositivo Bluetooth
        const char *bleName = "ESP32_Bluetooth";

        // Definire il testo ricevuto e il tempo dell'ultimo messaggio
        String receivedText = "";
        unsigned long lastMessageTime = 0;

        // Definire gli UUID del servizio e delle caratteristiche
        #define SERVICE_UUID           "your_service_uuid_here"
        #define CHARACTERISTIC_UUID_RX "your_rx_characteristic_uuid_here"
        #define CHARACTERISTIC_UUID_TX "your_tx_characteristic_uuid_here"

        // Definire la caratteristica Bluetooth
        BLECharacteristic *pCharacteristic;

* **Setup**: Nella funzione ``setup()``, la porta seriale viene inizializzata con una velocità in baud di 115200 e viene chiamata la funzione ``setupBLE()`` per configurare il Bluetooth BLE.

    .. code-block:: arduino
    
        void setup() {
            Serial.begin(115200);  // Inizializzare la porta seriale
            setupBLE();            // Inizializzare il Bluetooth BLE
        }

* **Loop Principale**: Nella funzione ``loop()``, se una stringa è stata ricevuta tramite BLE (cioè ``receivedText`` non è vuota) e sono passati almeno 1 secondo dall'ultimo messaggio, il codice stampa la stringa ricevuta sul monitor seriale, imposta il valore della caratteristica sulla stringa ricevuta, invia una notifica e poi svuota la stringa ricevuta. Se sono disponibili dati sulla porta seriale, legge la stringa fino a quando non viene incontrato un carattere di nuova linea, imposta il valore della caratteristica su questa stringa e invia una notifica.

    .. code-block:: arduino

        void loop() {
            // Quando il testo ricevuto non è vuoto e il tempo dall'ultimo messaggio è superiore a 1 secondo
            // Invia una notifica e stampa il testo ricevuto
            if (receivedText.length() > 0 && millis() - lastMessageTime > 1000) {
                Serial.print("Received message: ");
                Serial.println(receivedText);
                pCharacteristic->setValue(receivedText.c_str());
                pCharacteristic->notify();
                receivedText = "";
            }

            // Legge i dati dalla porta seriale e li invia alla caratteristica BLE
            if (Serial.available() > 0) {
                String str = Serial.readStringUntil('\n');
                const char *newValue = str.c_str();
                pCharacteristic->setValue(newValue);
                pCharacteristic->notify();
            }
        }

* **Callbacks**: Vengono definite due classi di callback (``MyServerCallbacks`` e ``MyCharacteristicCallbacks``) per gestire eventi relativi alla comunicazione Bluetooth. ``MyServerCallbacks`` viene utilizzata per gestire eventi relativi allo stato di connessione (connesso o disconnesso) del server BLE. ``MyCharacteristicCallbacks`` viene utilizzata per gestire eventi di scrittura sulla caratteristica BLE, cioè quando un dispositivo connesso invia una stringa all'ESP32 tramite BLE, questa viene catturata e memorizzata in ``receivedText``, e l'ora corrente viene registrata in ``lastMessageTime``.

    .. code-block:: arduino

        // Definire i callback del server BLE
        class MyServerCallbacks : public BLEServerCallbacks {
            // Stampa il messaggio di connessione quando un client è connesso
            void onConnect(BLEServer *pServer) {
            Serial.println("Connected");
            }
            // Stampa il messaggio di disconnessione quando un client è disconnesso
            void onDisconnect(BLEServer *pServer) {
            Serial.println("Disconnected");
            }
        };

        // Definire i callback della caratteristica BLE
        class MyCharacteristicCallbacks : public BLECharacteristicCallbacks {
            void onWrite(BLECharacteristic *pCharacteristic) {
                // Quando i dati vengono ricevuti, ottieni i dati e salvali in receivedText, e registra il tempo
                std::string value = std::string(pCharacteristic->getValue().c_str());
                receivedText = String(value.c_str());
                lastMessageTime = millis();
                Serial.print("Received: ");
                Serial.println(receivedText);
            }
        };

* **Setup BLE**: Nella funzione ``setupBLE()``, il dispositivo e il server BLE vengono inizializzati, vengono impostati i callback del server, viene creato il servizio BLE utilizzando l'UUID definito, vengono create e aggiunte al servizio le caratteristiche per l'invio di notifiche e la ricezione di dati, e vengono impostati i callback delle caratteristiche. Infine, il servizio viene avviato e il server inizia a pubblicizzare.

    .. code-block:: arduino

        // Inizializzare il Bluetooth BLE
        void setupBLE() {
            BLEDevice::init(bleName);                        // Inizializzare il dispositivo BLE
            BLEServer *pServer = BLEDevice::createServer();  // Creare il server BLE
            // Stampa il messaggio di errore se la creazione del server BLE fallisce
            if (pServer == nullptr) {
                Serial.println("Errore nella creazione del server BLE");
                return;
            }
            pServer->setCallbacks(new MyServerCallbacks());  // Imposta i callback del server BLE

            // Creare il servizio BLE
            BLEService *pService = pServer->createService(SERVICE_UUID);
            // Stampa il messaggio di errore se la creazione del servizio BLE fallisce
            if (pService == nullptr) {
                Serial.println("Error creating BLE service");
                return;
            }
            // Creare la caratteristica BLE per inviare notifiche
            pCharacteristic = pService->createCharacteristic(CHARACTERISTIC_UUID_TX, BLECharacteristic::PROPERTY_NOTIFY);
            pCharacteristic->addDecodeor(new BLE2902());  // Add the decodeor
            // Create the BLE characteristic for receiving data
            BLECharacteristic *pCharacteristicRX = pService->createCharacteristic(CHARACTERISTIC_UUID_RX, BLECharacteristic::PROPERTY_WRITE);
            pCharacteristicRX->setCallbacks(new MyCharacteristicCallbacks());  // Imposta i callback della caratteristica BLE
            pService->start();                                                 // Avvia il servizio BLE
            pServer->getAdvertising()->start();                                // Inizia a pubblicizzare
            Serial.println("Waiting for a client connection...");          // Attendi una connessione client
        }


Si noti che questo codice consente una comunicazione bidirezionale: può inviare e ricevere dati tramite BLE. 
Tuttavia, per interagire con hardware specifico, come accendere/spegnere un LED, è necessario aggiungere codice aggiuntivo per elaborare le stringhe ricevute e agire di conseguenza.

