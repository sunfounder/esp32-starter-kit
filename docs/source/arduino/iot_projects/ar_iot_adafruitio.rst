.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e alle anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_adafruit_io:

8.6 Monitoraggio di Temperatura e Umidità con Adafruit IO
=============================================================

In questo progetto, ti guideremo su come utilizzare una piattaforma IoT popolare. Esistono molte piattaforme gratuite (o a basso costo) disponibili online per gli appassionati di programmazione. Alcuni esempi sono Adafruit IO, Blynk, Arduino Cloud, ThingSpeak e così via. L'uso di queste piattaforme è piuttosto simile. Qui ci concentreremo su Adafruit IO.

Scriveremo un programma Arduino che utilizza il sensore DHT11 per inviare le letture di temperatura e umidità al dashboard di Adafruit IO. Puoi anche controllare un LED nel circuito tramite un interruttore sul dashboard.

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_dht11`
        - |link_dht11_buy|

**Configurazione del Dashboard**

#. Visita |link_adafruit_io|, quindi clicca su **Start for free** per creare un account gratuito.

    .. image:: img/sp230516_102503.png

#. Compila il modulo per creare un account.

    .. image:: img/sp230516_102629.png

#. Dopo aver creato un account Adafruit, dovrai riaprire Adafruit IO. Clicca su **Dashboards**, quindi clicca su **New Dashboard**.

    .. image:: img/sp230516_103347.png

#. Crea una **Nuova Dashboard**.

    .. image:: img/sp230516_103744.png

#. Accedi alla nuova **Dashboard** creata e crea un nuovo blocco.

    .. image:: img/sp230516_104234.png

#. Crea un blocco **Toggle**.

    .. image:: img/sp230516_105727.png

#. Successivamente, dovrai creare un nuovo feed qui. Questo toggle sarà utilizzato per controllare il LED, e chiameremo questo feed "LED".

    .. image:: img/sp230516_105641.png

#. Seleziona il feed **LED**, quindi passa al passaggio successivo.

    .. image:: img/sp230516_105925.png

#. Completa le impostazioni del blocco (principalmente Titolo del Blocco, Testo On e Testo Off), quindi clicca sul pulsante **Crea blocco** in basso a destra per terminare.

    .. image:: img/sp230516_110124.png

#. Successivamente, dobbiamo creare due blocchi **Text**. Saranno utilizzati per visualizzare temperatura e umidità. Quindi, crea due feed chiamati **temperature** e **humidity**.

    .. image:: img/sp230516_110657.png

#. Dopo la creazione, la tua Dashboard dovrebbe apparire così:

    .. image:: img/sp230516_111134.png

#. Puoi regolare il layout utilizzando l'opzione **Edit Layout** sulla Dashboard.

    .. image:: img/sp230516_111240.png

#. Clicca su **API KEY**, e vedrai visualizzati il tuo nome utente e la **API KEY**. Prendi nota di questi dati poiché ti serviranno per il tuo codice.

    .. image:: img/sp230516_111641.png

**Esecuzione del Codice**

#. Costruisci il circuito. 

    .. image:: ../../img/wiring/iot_6_adafruit_io_bb.png

#. Quindi, collega ESP32-WROOM-32E al computer utilizzando il cavo USB.

    .. image:: ../../img/plugin_esp32.png

#. Apri il codice.

    * Apri il file ``iot_6_adafruit_io.ino`` situato nella directory ``esp32-starter-kit-main\c\codes\iot_6_adafruit_io``, o copia il codice nell'IDE di Arduino.
    * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta appropriata, fai clic sul pulsante **Upload**.
    * :ref:`unknown_com_port`
    * Le librerie ``Adafruit_MQTT Library`` e ``DHT sensor library`` vengono utilizzate qui, puoi installarle dal **Library Manager**.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/4cf6ad03-250e-4fe9-aa04-0ca73b997843/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


#. Trova le seguenti righe e sostituisci ``SSID`` e ``PASSWORD`` con i dettagli specifici della tua rete WiFi.

    .. code-block::  Arduino

        /************************* Access Point WiFi *********************************/

        #define WLAN_SSID "SSID"
        #define WLAN_PASS "PASSWORD"

#. Poi sostituisci ``YOUR_ADAFRUIT_IO_USERNAME`` con il tuo nome utente Adafruit IO e ``YOUR_ADAFRUIT_IO_KEY`` con la **API KEY** che hai appena copiato.

    .. code-block::  Arduino

        // Configurazione Account Adafruit IO
        // (per ottenere questi valori, visita https://io.adafruit.com e clicca su Active Key)
        #define AIO_USERNAME "YOUR_ADAFRUIT_IO_USERNAME"
        #define AIO_KEY      "YOUR_ADAFRUIT_IO_KEY"

#. Dopo aver selezionato la scheda corretta (ESP32 Dev Module) e la porta, clicca sul pulsante **Upload**.

#. Una volta che il codice è stato caricato con successo, vedrai apparire il seguente messaggio nel monitor seriale, che indica la comunicazione avvenuta con successo con Adafruit IO.
    
    .. code-block::

        Esempio Adafruit IO MQTTS (SSL/TLS)


        Connessione a xxxxx
        WiFi connesso
        Indirizzo IP: 
        192.168.18.76
        Connessione a MQTT... Connessione a MQTT riuscita!
        Temperatura: 27.10
        Umidità: 61.00

#. Torna su Adafruit IO. Ora puoi osservare le letture di temperatura e umidità sul dashboard, oppure utilizzare l'interruttore toggle per controllare lo stato on/off del LED esterno collegato al circuito.

    .. image:: img/sp230516_143220.png

