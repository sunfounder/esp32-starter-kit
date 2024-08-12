.. note::

    Ciao, benvenuto nella Community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _iot_html_cam:


8.3 Server Web Personalizzato per lo Streaming Video
=========================================================

Il progetto del Server Web Personalizzato per lo Streaming Video ti offre l'opportunità di imparare come creare una pagina web da zero e personalizzarla per riprodurre flussi video. Inoltre, puoi incorporare pulsanti interattivi, come ON e OFF, per controllare la luminosità del LED.

Realizzando questo progetto, acquisirai esperienza pratica nello sviluppo web, HTML, CSS e JavaScript. Imparerai a creare una pagina web reattiva in grado di visualizzare flussi video in tempo reale. Inoltre, scoprirai come integrare pulsanti interattivi per controllare lo stato del LED, offrendo un'esperienza utente dinamica.

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

**Come fare?**

#. Prima collega la fotocamera.

    .. raw:: html

        <video loop autoplay muted style = "max-width:100%">
            <source src="../../_static/video/plugin_camera.mp4" type="video/mp4">
            Il tuo browser non supporta il tag video.
        </video>

#. Assembla il circuito.

    .. image:: ../../img/wiring/iot_3_html_led_bb.png

#. Poi, collega l'ESP32-WROOM-32E al computer utilizzando il cavo USB.

    .. image:: ../../img/plugin_esp32.png

#. Apri il codice.

    * Apri il file ``iot_3_html_cam_led.ino`` situato nella directory ``esp32-starter-kit-main\c\codes\iot_3_html_cam_led``, oppure copia il codice nell'IDE di Arduino.
    * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta appropriate, clicca sul pulsante **Upload**.
    * :ref:`unknown_com_port`
 
    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/a5e33c30-63dc-4987-94c3-89bc6a599e24/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Individua le seguenti righe e modificale con il tuo ``SSID`` e ``PASSWORD``.

    .. code-block::  Arduino

        // Sostituisci le prossime variabili con la combinazione SSID/Password
        const char* ssid = "SSID";
        const char* password = "PASSWORD";

#. Dopo aver selezionato la scheda corretta (ESP32 Dev Module) e la porta, clicca sul pulsante **Upload**.

#. Vedrai un messaggio di connessione WiFi avvenuta con successo e l'indirizzo IP assegnato nel Serial Monitor.

    .. code-block:: 

        WiFi connected
        Camera Stream Ready! Vai su: http://192.168.18.77

#. Inserisci l'indirizzo IP nel tuo browser. Sarai diretto alla pagina web mostrata qui sotto, dove potrai utilizzare i pulsanti personalizzati ON e OFF per controllare il LED.

    .. image:: img/sp230510_180503.png 

#. Inserisci una batteria nella scheda di espansione e rimuovi il cavo USB. Ora puoi posizionare il dispositivo ovunque desideri all'interno della portata del Wi-Fi.

    .. image:: ../../img/plugin_battery.png
