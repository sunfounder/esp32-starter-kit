.. note::

    Ciao, benvenuto nella Community di Appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirsi a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni l'accesso anticipato a nuovi annunci di prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_bluetooth_led:


7.2 Controllo LED RGB via Bluetooth
==========================================

Questo progetto è un'estensione di un progetto precedente (:ref:`ar_bluetooth`), aggiungendo configurazioni per LED RGB e comandi personalizzati come "led_off", "red", "green", ecc. Questi comandi permettono di controllare il LED RGB inviando comandi da un dispositivo mobile utilizzando LightBlue.

**Componenti necessari**

In questo progetto, avremo bisogno dei seguenti componenti.

È sicuramente conveniente acquistare un kit completo, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - ELEMENTI IN QUESTO KIT
        - LINK
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

Puoi anche acquistarli separatamente dai link sottostanti.

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
    *   - :ref:`cpn_rgb`
        - |link_rgb_led_buy|

**Passaggi Operativi**

#. Costruisci il circuito.

    .. image:: ../../components/img/rgb_pin.jpg
        :width: 200
        :align: center

    Il LED RGB ha 4 pin: il pin lungo è il catodo comune, che di solito è collegato a GND; il pin a sinistra accanto al pin più lungo è Rosso; e i due pin a destra sono Verde e Blu.

    .. image:: ../../img/wiring/2.3_color_light_bb.png

#. Apri il file ``7.2_bluetooth_rgb_led.ino`` che si trova nella directory ``esp32-starter-kit-main\c\codes\7.2_bluetooth_rgb_led`` o copia il codice nell'IDE di Arduino.

    .. raw:: html
         
        <iframe src=https://create.arduino.cc/editor/sunfounder01/b9331c9d-e9ea-4970-87ce-bf2ca8c231b2/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Per evitare conflitti di UUID, si consiglia di generare casualmente tre nuovi UUID utilizzando il |link_uuid| fornito dal Bluetooth SIG, e di inserirli nelle seguenti righe di codice.

    .. note::
        Se hai già generato tre nuovi UUID nel progetto :ref:`ar_bluetooth`, puoi continuare a utilizzarli.


    .. code-block:: arduino

        #define SERVICE_UUID           "your_service_uuid_here" 
        #define CHARACTERISTIC_UUID_RX "your_rx_characteristic_uuid_here"
        #define CHARACTERISTIC_UUID_TX "your_tx_characteristic_uuid_here"

    .. image:: img/uuid_generate.png

#. Seleziona la scheda e la porta corrette, quindi clicca sul pulsante **Carica**.

#. Dopo che il codice è stato caricato con successo, attiva il **Bluetooth** sul tuo dispositivo mobile e apri l'app **LightBlue**.

    .. image:: img/bluetooth_open.png

#. Nella pagina **Scan**, trova **ESP32-Bluetooth** e clicca su **CONNECT**. Se non lo vedi, prova a ricaricare la pagina alcune volte. Quando appare **"Connected to device!"**, la connessione Bluetooth è avvenuta con successo. Scorri verso il basso per vedere i tre UUID impostati nel codice.

    .. image:: img/bluetooth_connect.png
        :width: 800

#. Tocca l'UUID Send, poi imposta il formato dati su "UTF-8 String". Ora puoi scrivere questi comandi: "led_off", "red", "green", "blue", "yellow" e "purple" per vedere se il LED RGB risponde a queste istruzioni.

    .. image:: img/bluetooth_send_rgb.png
    

**Come funziona?**

Questo codice è un'estensione di un progetto precedente (:ref:`ar_bluetooth`), aggiungendo configurazioni per LED RGB e comandi personalizzati come "led_off", "red", "green", ecc. Questi comandi permettono di controllare il LED RGB inviando comandi da un dispositivo mobile utilizzando LightBlue.

Vediamo il codice passo dopo passo:

* Aggiungi nuove variabili globali per i pin del LED RGB, i canali PWM, la frequenza e la risoluzione.

    .. code-block:: arduino

        ...

        // Definisci i pin del LED RGB
        const int redPin = 27;
        const int greenPin = 26;
        const int bluePin = 25;

        ...

* All'interno della funzione ``setup()``, i canali PWM vengono inizializzati con la frequenza e la risoluzione predefinite. I pin del LED RGB vengono poi collegati ai rispettivi canali PWM.

    .. code-block:: arduino
        
        void setup() {
            ...

            ledcAttach(redPin, freq, resolution);
            ledcAttach(greenPin, freq, resolution);
            ledcAttach(bluePin, freq, resolution);
        }

* Modifica il metodo ``onWrite`` nella classe ``MyCharacteristicCallbacks``. Questa funzione ascolta i dati provenienti dalla connessione Bluetooth. In base alla stringa ricevuta (come ``"led_off"``, ``"red"``, ``"green"``, ecc.), controlla il LED RGB.

    .. code-block:: arduino

        // Definisci i callback della caratteristica BLE
        class MyCharacteristicCallbacks : public BLECharacteristicCallbacks {
            void onWrite(BLECharacteristic *pCharacteristic) {
                std::string value = std::string(pCharacteristic->getValue().c_str());
                if (value == "led_off") {
                    setColor(0, 0, 0); // spegne il LED RGB
                    Serial.println("RGB LED spento");
                } else if (value == "red") {
                    setColor(255, 0, 0); // Rosso
                    Serial.println("red");
                }
                else if (value == "green") {
                    setColor(0, 255, 0); // Verde
                    Serial.println("green");
                }
                else if (value == "blue") {
                    setColor(0, 0, 255); // Blu
                    Serial.println("blue");
                }
                else if (value == "yellow") {
                    setColor(255, 150, 0); // Giallo
                    Serial.println("yellow");
                }
                else if (value == "purple") {
                    setColor(80, 0, 80); // Viola
                    Serial.println("purple");
                }
            }
        };

* Infine, viene aggiunta una funzione per impostare il colore del LED RGB.

    .. code-block:: arduino

        void setColor(int red, int green, int blue) {
            // Per i LED RGB a catodo comune, usa 255 meno il valore del colore
            ledcWrite(redPin, red);
            ledcWrite(greenPin, green);
            ledcWrite(bluePin, blue);
        }


In sintesi, questo script abilita un modello di interazione di controllo remoto, dove l'ESP32 opera come server Bluetooth Low Energy (BLE).

Il client BLE connesso (come uno smartphone) può inviare comandi sotto forma di stringhe per cambiare il colore di un LED RGB. L'ESP32 fornisce anche un feedback al client inviando indietro la stringa ricevuta, permettendo al client di sapere quale operazione è stata eseguita.

