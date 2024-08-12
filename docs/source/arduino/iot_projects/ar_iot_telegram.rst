.. note::

    Ciao, benvenuto nella Community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _iot_telegram:

8.7 ESP Camera con Bot Telegram
====================================

In questo progetto, ti mostreremo come integrare l'ESP32 con la tua applicazione di messaggistica preferita. Per questa dimostrazione, utilizziamo Telegram.

Crea un Bot Telegram che ti permetta di controllare il tuo circuito da qualsiasi luogo, catturare foto e gestire il flash. Inoltre, ogni volta che qualcuno passa davanti al tuo dispositivo, scatterà una nuova foto e invierà una notifica al tuo account Telegram.

**Componenti Necessari**

In questo progetto, avremo bisogno dei seguenti componenti.

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
    *   - :ref:`cpn_pir`
        - |link_pir_buy|

**Creazione di un Bot Telegram**

#. Vai su **Google Play** o sull'**App Store** e scarica e installa **Telegram**.

#. Cerca ``botfather`` nell'app **Telegram** e, una volta apparso, clicca su di esso per aprirlo. Oppure puoi accedere direttamente a questo link: t.me/botfather.

    .. image:: img/sp230515_135927.png

#. Una volta aperto, ti verrà presentata una finestra di chat. Invia il comando ``/start``.

    .. image:: img/sp230515_140149.png

#. Inserisci ``/newbot`` e segui le istruzioni fornite per creare il tuo bot. Una volta completato, BotFather ti fornirà il link di accesso e l'API per il tuo nuovo bot.

    .. image:: img/sp230515_140830.png

**Autorizzazione degli Utenti di Telegram**

Poiché chiunque può interagire con il bot che hai creato, esiste il rischio di perdita di informazioni. Per affrontare questo problema, vogliamo che il bot risponda solo agli utenti autorizzati.

#. Nel tuo account **Telegram**, cerca ``IDBot`` o apri il link: t.me/myidbot.

    .. image:: img/sp230515_144241.png

#. Invia il comando ``/getid``. Salva l'ID fornito per un uso successivo nel nostro programma.

    .. image:: img/sp230515_144614.png

**Caricamento del Codice**

#. Prima collega la fotocamera.

    .. raw:: html

        <video loop autoplay muted style = "max-width:100%">
            <source src="../../_static/video/plugin_camera.mp4" type="video/mp4">
            Your browser does not support the video tag.
        </video>

#. Assembla il circuito.

    .. image:: ../../img/wiring/iot_7_cam_telegram_bb.png
        
#. Apri il codice.

    * Apri il file ``iot_7_cam_telegram.ino`` situato nella directory ``esp32-starter-kit-main\c\codes\iot_7_cam_telegram``, oppure copia il codice nell'IDE di Arduino.
    * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta appropriate, clicca sul pulsante **Upload**.
    * :ref:`unknown_com_port`
    * Le librerie ``UniversalTelegramBot`` e ``ArduinoJson`` sono utilizzate qui, puoi installarle dal **Library Manager**.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/d7c439b0-fca3-4648-9714-900a2859740c/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


#. Individua e modifica le seguenti righe con i dettagli del tuo WiFi, sostituendo ``SSID`` e ``PASSWORD``:

    .. code-block::  Arduino

        // Sostituisci le prossime variabili con la combinazione SSID/Password
        const char* ssid = "SSID";
        const char* password = "PASSWORD";

#. Aggiorna la riga successiva, sostituendo ``CHATID`` con il tuo ID Telegram, ottenuto da @IDBot.

    .. code-block:: Arduino

        // Usa @myidbot per trovare l'ID chat di un individuo o di un gruppo
        // Nota anche che è necessario fare clic su "start" su un bot prima che possa
        // inviarti messaggi
        String chatId = "CHATID";

#. Aggiorna la riga successiva, sostituendo ``BOTTOKEN`` con il token del tuo bot Telegram, fornito da @BotFather.

    .. code-block:: Arduino

        // Inizializza il Bot Telegram
        String BOTtoken = "BOTTOKEN";

#. Dopo aver selezionato la scheda corretta (ESP32 Dev Module) e la porta, clicca sul pulsante **Upload**.
#. Apri il Monitor Seriale. Se viene stampato un indirizzo IP, ciò indica un'esecuzione corretta.

    .. code-block::

        Connecting to xxxx
        ESP32-CAM IP Address: 192.168.18.76
        Init Done!

#. Ora puoi interagire con il tuo ESP32 tramite Telegram.

    .. image:: img/sp230515_161237.png

