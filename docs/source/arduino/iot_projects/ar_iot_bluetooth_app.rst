.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e alle anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _iot_bluetooth_app:

8.10 Applicazione Android - Controllo di un LED RGB tramite Arduino e Bluetooth
==================================================================================

L'obiettivo di questo progetto è sviluppare un'applicazione Android in grado di manipolare la tonalità di un LED RGB tramite uno smartphone utilizzando la tecnologia Bluetooth.

Questa applicazione Android verrà creata utilizzando una piattaforma web gratuita chiamata MIT App Inventor 2. Il progetto rappresenta un'ottima opportunità per familiarizzare con l'interfacciamento tra un Arduino e uno smartphone.

.. raw:: html

   <video loop autoplay muted style = "max-width:100%">
      <source src="../../_static/video/10_ble_app.mp4" type="video/mp4">
      Il tuo browser non supporta il tag video.
   </video>

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
    *   - :ref:`cpn_rgb`
        - |link_rgb_led_buy|

**1. Creazione dell'Applicazione Android**

L'applicazione Android sarà creata utilizzando una web application gratuita chiamata |link_appinventor|. 
MIT App Inventor è un eccellente punto di partenza per lo sviluppo Android, grazie alle sue funzionalità intuitive di drag-and-drop che permettono la creazione di applicazioni semplici.

Iniziamo.

#. Ecco la pagina di accesso: http://ai2.appinventor.mit.edu. Avrai bisogno di un account Google per registrarti a MIT App Inventor.

#. Dopo aver effettuato l'accesso, vai su **Projects** -> **Import project (.aia) from my computer**. Successivamente, carica il file ``control_rgb_led.aia`` che si trova nel percorso ``esp32-starter-kit-main\c\codes\iot_10_bluetooth_app_inventor``.

   .. image:: img/10_ble_app_inventor1.png

#. Una volta caricato il file ``.aia``, vedrai l'applicazione nel software **MIT App Inventor**. Questo è un template preconfigurato. Potrai modificare questo template dopo aver familiarizzato con **MIT App Inventor** attraverso i seguenti passaggi.

   .. image:: img/10_ble_app_inventor2.png

#. In **MIT App Inventor**, hai 2 sezioni principali: il **Designer** e i **Blocks**.

   .. image:: img/10_ble_app_inventor3.png

#. Il **Designer** ti permette di aggiungere pulsanti, testi, schermate e di modificare l'estetica generale della tua applicazione.

   .. image:: img/10_ble_app_inventor2.png
   

#. Successivamente, hai la sezione **Blocks**. La sezione **Blocks** facilita la creazione di funzioni personalizzate per la tua applicazione.

   .. image:: img/10_ble_app_inventor5.png

#. Per installare l'applicazione su uno smartphone, vai sulla scheda **Build**.

   .. image:: img/10_ble_app_inventor6.png

   * Puoi generare un file ``.apk``. Dopo aver selezionato questa opzione, apparirà una pagina che ti permetterà di scegliere tra il download di un file ``.apk`` o la scansione di un codice QR per l'installazione. Segui la guida di installazione per completare l'installazione dell'applicazione.
   * Se desideri caricare questa app su **Google Play** o su un altro marketplace di app, puoi generare un file ``.aab``.

**2. Caricare il codice**

#. Costruisci il circuito.

   .. image:: ../../components/img/rgb_pin.jpg
      :width: 200
      :align: center

   Il LED RGB è composto da 4 pin: il pin allungato è il pin del catodo comune, tipicamente collegato a GND; il pin a sinistra del pin più lungo rappresenta il Rosso; e i due pin a destra simboleggiano il Verde e il Blu.

   .. image:: ../../img/wiring/2.3_color_light_bb.png

#. Successivamente, collega l'ESP32-WROOM-32E al tuo computer utilizzando un cavo USB.

   .. image:: ../../img/plugin_esp32.png

#. Apri il file ``iot_10_bluetooth_app_inventor.ino`` situato nella directory ``esp32-starter-kit-main\c\codes\iot_10_bluetooth_app_inventor``, o copia il codice nell'IDE di Arduino.

   .. raw:: html

      <iframe src=https://create.arduino.cc/editor/sunfounder01/07622bb5-31eb-4a89-b6f2-085f3332051f/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

#. Dopo aver selezionato la scheda appropriata (**ESP32 Dev Module**) e la porta, fai clic sul pulsante **Upload**.

**3. Connessione tra App e ESP32**

Assicurati che l'applicazione creata in precedenza sia installata sul tuo smartphone.

#. Inizialmente, attiva il **Bluetooth** sul tuo smartphone.

   .. image:: img/10_ble_mobile1.png
      :width: 500
      :align: center

#. Vai alle **impostazioni Bluetooth** sul tuo smartphone e trova **ESP32RGB**.

   .. image:: img/10_ble_mobile2.png
      :width: 500
      :align: center

#. Dopo aver cliccato su di esso, accetta la richiesta di **Accoppiamento** nella finestra pop-up.

   .. image:: img/10_ble_mobile3.png
      :width: 500
      :align: center

#. Ora apri l'APP **Control_RGB_LED** appena installata.

   .. image:: img/10_ble_mobile4.png
      :align: center

#. Nell'APP, clicca su **Connect Bluetooth** per stabilire una connessione tra l'APP e ESP32.

   .. image:: img/10_ble_mobile5.png
      :width: 500
      :align: center

#. Seleziona l'opzione ``xx.xx.xx.xx.xx.xx ESP32RGB`` che appare. Se hai modificato ``SerialBT.begin("ESP32RGB");`` nel codice, seleziona semplicemente il nome impostato.

   .. image:: img/10_ble_mobile6.png
      :width: 500
      :align: center

#. Se hai aspettato per un po' e ancora non riesci a vedere nessun nome di dispositivo, potrebbe essere che questa APP non è autorizzata a scansionare i dispositivi circostanti. In questo caso, devi regolare manualmente le impostazioni.

   * Premi a lungo l'icona dell'APP e clicca su **Info APP**. Se hai un altro metodo per accedere a questa pagina, segui quello.

      .. image:: img/10_ble_mobile8.png
         :width: 500
         :align: center

   * Vai alla pagina **Autorizzazioni**.

      .. image:: img/10_ble_mobile9.png
         :width: 500
         :align: center

   * Trova **Dispositivi nelle vicinanze** e seleziona **Sempre** per consentire a questa APP di scansionare i dispositivi nelle vicinanze.

      .. image:: img/10_ble_mobile10.png
         :width: 500
         :align: center

   * Ora, riavvia l'APP e ripeti i passaggi 5 e 6 per connetterti con successo al Bluetooth.

#. Dopo la connessione avvenuta con successo, verrai automaticamente riportato alla pagina principale, dove verrà visualizzata la connessione stabilita. Ora puoi regolare i valori RGB e cambiare il colore del display RGB premendo il pulsante **Cambia Colore**.

   .. image:: img/10_ble_mobile7.png
      :width: 500
      :align: center

