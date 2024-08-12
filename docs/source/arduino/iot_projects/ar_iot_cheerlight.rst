.. note::

    Ciao, benvenuto nella Community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Esplora più a fondo Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirti?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e sbircia dietro le quinte.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _iot_cheerlights:


8.5 CheerLights
===============================
CheerLights è una rete globale di luci sincronizzate che possono essere controllate da chiunque.

Unisciti alla comunità |link_cheerlights| per cambiare il colore dei LED, consentendo alle luci LED di tutto il mondo di cambiare colore simultaneamente.

Puoi posizionare i tuoi LED in un angolo del tuo ufficio per ricordarti che non sei solo.

In questo progetto utilizziamo anche MQTT, ma invece di pubblicare i nostri messaggi, ci iscriviamo al topic "cheerlights". Questo ci permette di ricevere i messaggi inviati da altri al topic "cheerlights" e utilizzare queste informazioni per cambiare il colore della nostra striscia LED di conseguenza.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_ws2812`
        - |link_ws2812_buy|


**Procedura**

#. Assembla il circuito.

    .. image:: ../../img/wiring/iot_5_cheerlight_bb.png

#. Poi, collega l'ESP32-WROOM-32E al computer utilizzando il cavo USB.

    .. image:: ../../img/plugin_esp32.png

#. Apri il codice.

    * Apri il file ``iot_5_cheerlights.ino`` situato nella directory ``esp32-starter-kit-main\c\codes\iot_5_cheerlights``, o copia il codice nell'Arduino IDE.
    * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta corretti, clicca sul pulsante **Upload**.
    * :ref:`unknown_com_port`
    * Le librerie ``PubSubClient`` e ``Adafruit_NeoPixel`` vengono utilizzate qui, puoi installarle dal **Library Manager**.

        .. image:: img/mqtt_lib.png

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/4fc7b0ff-db8e-4bf3-ad34-d68c1857794b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Trova le seguenti righe e modificale con il tuo ``SSID`` e ``PASSWORD``.

    .. code-block::  Arduino

        // Sostituisci le prossime variabili con la tua combinazione SSID/Password
        const char* ssid = "SSID";
        const char* password = "PASSWORD";

#. Trova la riga successiva e modifica il tuo ``unique_identifier``. Assicurati che il tuo ``unique_identifier`` sia veramente unico, poiché qualsiasi ID identico che tenta di accedere allo stesso **MQTT Broker** può causare un fallimento di accesso.

    .. code-block::  Arduino

        // Aggiungi l'indirizzo del tuo MQTT Broker:
        const char* mqtt_server = "mqtt.cheerlights.com";
        const char* unique_identifier = "sunfounder-client-sdgvsasdda";    

#. Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta corretti, clicca sul pulsante **Upload**.

#. A questo punto, puoi vedere che la tua striscia RGB sta mostrando un certo colore. Posizionala sulla tua scrivania e noterai che cambia colore periodicamente. Questo perché altri follower di @CheerLights stanno cambiando il colore delle tue luci!

#. Apri il Monitor Seriale. Vedrai messaggi simili ai seguenti:

.. code-block:: 
  
    WiFi connesso
    Indirizzo IP: 
    192.168.18.77
    Tentativo di connessione MQTT...connesso
    Messaggio arrivato sul topic: cheerlights. 
    Messaggio: oldlace
    Cambio colore in oldlace

**Controlla i dispositivi globali @CheerLights**

#. Unisciti al |link_discord_server| e utilizza il bot CheerLights per impostare il colore. Basta digitare ``/cheerlights`` in uno qualsiasi dei canali sul **CheerLights Discord Server** per attivare il bot.

    .. image:: img/sp230511_163558.png

#. Segui le istruzioni fornite dal bot per impostare il colore. Questo ti permetterà di controllare i dispositivi CheerLights a livello globale.

    .. image:: img/sp230511_163849.png
