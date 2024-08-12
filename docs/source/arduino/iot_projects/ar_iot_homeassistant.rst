.. note::

    Ciao, benvenuto nella Community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirti?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e sbircia dietro le quinte.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

8.8 Telecamera con Home Assistant
======================================

Questo progetto ti guiderà nella configurazione di un server web per lo streaming video con la fotocamera ESP32 e nell'integrazione con la popolare piattaforma di automazione domestica, Home Assistant. Questa integrazione ti permetterà di accedere al server da qualsiasi dispositivo sulla tua rete.

.. note::
    
    Prima di iniziare questo progetto, devi avere un sistema operativo con Home Assistant installato.
        
    Ti consigliamo di installare Home Assistant OS su un Raspberry Pi.
        
    Se non hai un Raspberry Pi, puoi anche installarlo su una macchina virtuale che gira su Windows, macOS o Linux.
        
    Per le istruzioni di installazione, fai riferimento al sito web ufficiale: https://www.home-assistant.io/installation/
        
    Procedi con questo progetto solo dopo aver completato l'installazione con successo.

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


**1. Configurazione in ESP Home**

#. Prima collega la fotocamera.

    .. raw:: html

        <video loop autoplay muted style = "max-width:100%">
            <source src="../../_static/video/plugin_camera.mp4" type="video/mp4">
            Il tuo browser non supporta il tag video.
        </video>

#. Collega il tuo ESP32 all'host su cui hai installato il sistema Home Assistant (ad esempio, se installato su un Raspberry Pi, collegalo al Pi).

    .. image:: ../../img/plugin_esp32.png

#. Installa il componente aggiuntivo ESPHome.

    .. image:: img/sp230629_145928.png

#. Clicca su **START**, poi su **OPEN WEB UI**.

    .. image:: img/sp230629_172645.png
        :width: 700
        :align: center

#. Aggiungi nuovi dispositivi.

    .. image:: img/sp230629_172733.png

#. Potrebbe apparire un messaggio. Clicca su **CONTINUE**.

    .. image:: img/sp230629_172816.png
        :align: center


#. Crea una configurazione. Qui puoi inserire un nome a tua scelta per **Name**. Per WiFi, inserisci i dettagli della rete su cui è presente il sistema Home Assistant.

    .. image:: img/sp230629_172926.png

#. Seleziona **ESP32** come tipo di dispositivo.

    .. image:: img/sp230629_173043.png

#. Quando vedi un'icona di celebrazione con i fuochi d'artificio, significa che hai creato correttamente il dispositivo. Clicca su skip (NON cliccare su **INSTALL**).

    .. image:: img/sp230629_173151.png

    A questo punto, hai solo aggiunto il dispositivo in ESPHome. Per integrare il modulo ESP32 in Home Assistant, sono necessarie configurazioni aggiuntive:

#. Clicca su **EDIT**.

    .. image:: img/sp230629_173322.png

#. Dopo essere entrato nell'interfaccia ``.yaml``, modifica ``ssid`` e ``password`` con i dettagli del tuo WiFi.

    .. image:: img/sp230629_174301.png

#. Nella sezione ``captive_portal``, incolla il seguente codice:

    .. code-block::

        # Esempio di configurazione
        esp32_camera:
            external_clock:
                pin: GPIO0
                frequency: 20MHz
            i2c_pins:
                sda: GPIO26
                scl: GPIO27
            data_pins: [GPIO5, GPIO18, GPIO19, GPIO21, GPIO36, GPIO39, GPIO34, GPIO35]
            vsync_pin: GPIO25
            href_pin: GPIO23
            pixel_clock_pin: GPIO22
            power_down_pin: GPIO32

            # Impostazioni immagine
            name: My Camera
            # ...

    .. note:: 
        
        Per maggiori dettagli sulla configurazione ``.yaml`` per ESP32, puoi fare riferimento a `ESP32 Camera - ESPHome <https://esphome.io/components/esp32_camera.html>`_.

#. **Salva**, poi clicca su **INSTALL**.

    .. image:: img/sp230629_174447.png

#. Scegli il metodo di installazione tramite porta USB.

    .. image:: img/sp230629_174852.png

    .. note:: 
        
        La compilazione iniziale scaricherà i pacchetti di dipendenze, il che potrebbe richiedere circa 10 minuti. Per favore, sii paziente. Se il processo si blocca per un lungo periodo, controlla se c'è abbastanza spazio su disco nel tuo sistema.

#. Attendi il messaggio ``INFO Successfully compiled program.``, che indica che la compilazione del firmware è completata.

    .. image:: img/sp230630_115109.png

    .. sp230630_114902.png

    .. note::

        A questo punto, dovresti vedere il nodo come **ONLINE**. In caso contrario, assicurati che il tuo ESP32 sia sullo stesso segmento di rete o prova a riavviare il dispositivo.

        .. image:: img/sp230630_153024.png

**2. Configurazione in Home Assistant**

Dopo aver integrato con Esphome, è necessario configurare la fotocamera in Home Assistant.

#. Vai su **Settings** > **Devices & Services**.

    .. image:: img/sp230630_155917.png

#. Ora dovresti vedere la scheda esphome. Clicca su **CONFIGURE**.

    .. image:: img/sp230630_155736.png

#. Clicca su **SUBMIT**.

    .. image:: img/sp230630_162218.png

#. Attendi il messaggio **Success**.

    .. image:: img/sp230630_162311.png

#. In **Overview**, clicca sul menu in alto a destra e seleziona **Edit Dashboard**.

    .. image:: img/sp230630_164745.png

#. Clicca su **ADD CARD**.

    .. image:: img/sp230630_164850.png

#. Scegli **Picture entity**.

    .. image:: img/sp230630_164935.png

#. Nel campo dell'entità, seleziona l'ESP32 che hai appena aggiunto. Poi **salva**.

    .. image:: img/sp230630_165019.png

#. Infine, clicca su **DONE** per uscire dall'interfaccia **EDIT**.

    .. image:: img/sp230630_165235.png

Ora puoi visualizzare il feed della tua fotocamera su Home Assistant.
