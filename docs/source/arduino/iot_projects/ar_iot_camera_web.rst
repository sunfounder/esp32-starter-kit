.. note::

    Ciao, benvenuto nella Community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Esplora più a fondo Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirti?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e sbircia dietro le quinte.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _iot_camera_web:

8.2 Server Web per Fotocamera
=================================

Questo progetto combina la scheda ESP32 con un modulo fotocamera per trasmettere video di alta qualità su una rete locale. 
Configura facilmente il tuo sistema di sorveglianza e monitora qualsiasi luogo in tempo reale.

Grazie all'interfaccia web del progetto, puoi accedere e controllare il feed della fotocamera da qualsiasi dispositivo connesso alla rete. 
Personalizza le impostazioni della fotocamera per ottimizzare l'esperienza di streaming e regola facilmente le opzioni grazie all'interfaccia user-friendly.

Migliora le tue capacità di sorveglianza o live streaming con il versatile progetto di Streaming della Fotocamera ESP32. Monitora la tua casa, ufficio o qualsiasi luogo desiderato con facilità e affidabilità.

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

**Come procedere?**

#. Innanzitutto, collega la fotocamera.

    .. raw:: html

        <video loop autoplay muted style = "max-width:100%">
            <source src="../../_static/video/plugin_camera.mp4" type="video/mp4">
            Il tuo browser non supporta il tag video.
        </video>

#. Poi, collega l'ESP32-WROOM-32E al computer utilizzando il cavo USB.

    .. image:: ../../img/plugin_esp32.png

#. Apri il codice.

    * Apri il file ``iot_2_camera_server.ino`` situato nella directory ``esp32-starter-kit-main\c\codes\iot_2_camera_server``, o copia il codice nell'Arduino IDE.
    * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta corrette, clicca sul pulsante **Upload**.
    * :ref:`unknown_com_port`

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/15e00b39-34e1-49f9-b039-f10053d31407/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
        

#. Trova le seguenti righe e modificale con il tuo ``SSID`` e ``PASSWORD``.

    .. code-block::  Arduino

        // Sostituisci le prossime variabili con la tua combinazione SSID/Password
        const char* ssid = "SSID";
        const char* password = "PASSWORD";

#. Ora, abilita **PSRAM**.

    .. image:: img/sp230516_150554.png

#. Imposta lo schema di partizione su **Huge APP (3MB No OTA/1MB SPIFFS)**.

    .. image:: img/sp230516_150840.png

#. Dopo aver selezionato la scheda corretta (ESP32 Dev Module) e la porta, clicca sul pulsante "Upload".

#. Vedrai un messaggio di connessione WiFi riuscita e l'indirizzo IP assegnato nel Monitor Seriale.

    .. code-block::

        .....
        WiFi connesso
        Avvio del server web sulla porta: '80'
        Avvio del server di streaming sulla porta: '81'
        Fotocamera pronta! Usa 'http://192.168.18.77' per connetterti

#. Inserisci l'indirizzo IP nel tuo browser web. Vedrai un'interfaccia web dove potrai cliccare su **Start Stream** per visualizzare il feed della fotocamera.

    .. image:: img/sp230516_151521.png

#. Scorri verso l'alto della pagina, dove vedrai il feed live della fotocamera. Puoi regolare le impostazioni sul lato sinistro dell'interfaccia.

    .. image:: img/sp230516_180520.png

.. note:: 

    * Questo modulo ESP32 supporta il Rilevamento del Viso. Per abilitarlo, imposta la risoluzione su 240x240 e attiva l'opzione Rilevamento del Viso in fondo all'interfaccia.
    * Questo modulo ESP32 non supporta il Riconoscimento del Viso.
