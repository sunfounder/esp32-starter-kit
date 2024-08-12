.. note::

    Ciao, benvenuto nella Community di Appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirsi a noi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato a nuovi annunci di prodotti e anteprime.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_dht11:

5.13 Temperatura - Umidità
=======================================

Il DHT11 è un sensore di temperatura e umidità comunemente utilizzato per misurazioni ambientali. Si tratta di un sensore digitale che comunica con un microcontrollore per fornire letture di temperatura e umidità.

In questo progetto, leggeremo i dati del sensore DHT11 e stamperemo i valori di temperatura e umidità che rileva.

Leggendo i dati forniti dal sensore, possiamo ottenere i valori attuali di temperatura e umidità nell'ambiente. Questi valori possono essere utilizzati per il monitoraggio in tempo reale delle condizioni ambientali, osservazioni meteorologiche, controllo del clima interno, report di umidità e altro ancora.

**Componenti Necessari**

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
    *   - :ref:`cpn_dht11`
        - |link_dht11_buy|

* **Pin Disponibili**

    Ecco un elenco dei pin disponibili sulla scheda ESP32 per questo progetto.

    .. list-table::
        :widths: 5 20

        *   - Pin Disponibili
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**Schema**

.. image:: ../../img/circuit/circuit_5.13_dht11.png


**Cablaggio**

.. image:: ../../img/wiring/5.13_dht11_bb.png

**Codice**

.. note::

    * Apri il file ``5.13_dht11.ino`` nel percorso ``esp32-starter-kit-main\c\codes\5.13_dht11``.
    * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta appropriata, clicca sul pulsante **Carica**.
    * :ref:`unknown_com_port`
    * Qui viene utilizzata la libreria ``DHT sensor library``, che puoi installare dal **Library Manager**.

        .. image:: img/dht_lib.png

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/95bef6dc-a4db-4315-9308-6663b77ddfa0/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Ricorda di impostare la velocità di comunicazione seriale a 115200 baud.

Dopo che il codice è stato caricato con successo, vedrai il Serial Monitor stampare continuamente la temperatura e l'umidità, e man mano che il programma prosegue, questi due valori diventeranno sempre più accurati.

**Come funziona?**

#.  Include la libreria ``DHT.h``, che fornisce funzioni per interagire con i sensori DHT. Poi, imposta il pin e il tipo per il sensore DHT.

    .. code-block:: arduino

        #include "DHT.h"

        #define DHTPIN 14  // Imposta il pin collegato al pin dati del DHT11
        #define DHTTYPE DHT11 // DHT 11 

        DHT dht(DHTPIN, DHTTYPE);

#. Inizializza la comunicazione seriale a una velocità di 115200 baud e inizializza il sensore DHT.

    .. code-block:: arduino

        void setup() {
            Serial.begin(115200);
            Serial.println("DHT11 test!");
            dht.begin();
        }

#. Nella funzione ``loop()``, leggi i valori di temperatura e umidità dal sensore DHT11, e stampali sul monitor seriale.

    .. code-block:: arduino

        void loop() {
            // Attendi qualche secondo tra le misurazioni.
            delay(2000);

            // La lettura di temperatura o umidità richiede circa 250 millisecondi!
            // Le letture del sensore possono essere anche vecchie di 2 secondi (è un sensore molto lento)
            float humidity = dht.readHumidity();
            // Leggi la temperatura in Celsius (impostazione predefinita)
            float temperature = dht.readTemperature();

            // Controlla se una delle letture è fallita ed esci (per riprovare).
            if (isnan(humidity) || isnan(temperature)) {
                Serial.println("Failed to read from DHT sensor!");
                return;
            }
            // Stampa l'umidità e la temperatura
            Serial.print("Humidity: "); 
            Serial.print(humidity);
            Serial.print(" %\t");
            Serial.print("Temperature: "); 
            Serial.print(temperture);
            Serial.println(" *C");
        }

    * La funzione ``dht.readHumidity()`` viene chiamata per leggere il valore di umidità dal sensore DHT.
    * La funzione ``dht.readTemperature()`` viene chiamata per leggere il valore di temperatura dal sensore DHT.
    * La funzione ``isnan()`` viene utilizzata per verificare se le letture sono valide. Se uno dei valori di umidità o temperatura è NaN (non un numero), indica una lettura fallita dal sensore, e viene stampato un messaggio di errore.

**Per Saperne di Più**

Puoi anche visualizzare la temperatura e l'umidità su un LCD I2C 1602.


.. note::

    * Puoi aprire il file ``5.10_thermistor_lcd.ino`` nel percorso ``euler-kit/arduino/5.10_thermistor_lcd``.
    * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta appropriata, clicca sul pulsante **Carica**.
    * Qui vengono utilizzate le librerie ``LiquidCrystal_I2C`` e ``DHT sensor library``, che puoi installare dal **Library Manager**.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/fb46ba7e-0a09-4805-87ab-f733e23eb920/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
