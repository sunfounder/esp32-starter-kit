

.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e alle anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _iot_intrusion_alert_system:

8.9 Sistema di Notifica di Intrusione basato su Blynk
=========================================================

Questo progetto dimostra un semplice sistema di rilevamento di intrusione domestica utilizzando un sensore di movimento PIR (HC-SR501).
Quando il sistema è impostato sulla modalità "Assente" tramite l'app Blynk, il sensore PIR monitora i movimenti.
Qualsiasi movimento rilevato attiverà una notifica sull'app Blynk, avvisando l'utente di una potenziale intrusione.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_pir`
        - |link_pir_buy|

1. Assemblaggio del Circuito
---------------------------------

.. image:: ../../img/wiring/iot_9_blynk_bb.png
    :width: 60%
    :align: center

2. Configurazione di Blynk
------------------------------

**2.1 Inizializzazione di Blynk**

1. Vai alla pagina |link_blynk| e seleziona **Sign Up FREE** o **Enterprise Solution**.

    .. image:: img/09_blynk_access.png
        :width: 600
        :align: center

2. Inserisci la tua email per avviare il processo di registrazione.

    .. image:: img/09_blynk_sign_in.png
        :align: center

3. Controlla la tua email per un prompt e clicca sul link **Create Password** nell'email per impostare la tua password.

    .. image:: img/09_blynk_password.png
        :align: center

4. Dopo la conferma, inizierà un **Tour di Blynk** dove potrai apprendere rapidamente alcune delle principali funzionalità di Blynk.

    .. image:: img/09_blynk_tour.png
        :width: 600
        :align: center

5. Al termine del Tour di Blynk, apparirà una finestra dove potrai scegliere di Esplorare i Blueprint o cliccare su Quick Start per connettere rapidamente il tuo dispositivo. Tuttavia, in questo caso, selezioneremo "Have a look around first".

    .. image:: img/09_blynk_skip.png
        :align: center

**2.2 Creazione del Template**

1. Inizia creando un template su Blynk. Segui i passaggi per configurare il template **Intrusion Alert System**.

    .. image:: img/09_create_template_1_shadow.png
        :width: 600
        :align: center

2. Assegna un nome al tuo template, scegli **ESP32** come Hardware, seleziona **WiFi** come **Connection Type**, e poi clicca su **Done**.

   .. image:: img/09_create_template_2_shadow.png
        :width: 600
        :align: center

3. Entra nel template, dove ti verranno presentati i passaggi successivi. Clicca su **Configure template** per caricare un'immagine di copertina, migliorare la descrizione e altro ancora. Segui i tre passaggi rimanenti per completare la configurazione.

    .. image:: img/09_blynk_temp_steps.png
        :width: 600
        :align: center

**2.3 Configurazione dei Datastream**

1. Apri il template appena creato e vai alla pagina di configurazione del datastream.

   .. image:: img/09_blynk_new_datastream.png
        :width: 600
        :align: center

2. Clicca su **New Datastream**, e nella finestra popup, seleziona **Virtual Pin**.

   .. image:: img/09_blynk_datastream_virtual.png
        :width: 600
        :align: center

3. Assegna al **Virtual Pin V0** il nome **AwayMode** e imposta il **DATA TYPE** su **Integer**, con valori **MIN** e **MAX** di **0** e **1**.

   .. image:: img/09_create_template_shadow.png
        :width: 600
        :align: center

4. Allo stesso modo, crea un altro **Virtual Pin** chiamato **Current Status** e imposta il **DATA TYPE** su **String**.

   .. image:: img/09_datastream_1_shadow.png
        :width: 600
        :align: center

**2.4 Configurazione del Web Dashboard**

1. Trascina e rilascia il **Switch widget** e il **Label widget** sul **Web Dashboard**.

   .. image:: img/09_web_dashboard_1_shadow.png
        :width: 600
        :align: center

2. Passa il mouse su un widget per visualizzare tre icone. Usa l'icona **Settings** per configurare le proprietà del widget.

   .. image:: img/09_blynk_dashboard_set.png
        :width: 600
        :align: center

3. Configura il **Switch widget** per collegarlo al datastream **AwayMode(V0)**, impostando le etichette **ONLABEL** e **OFFLABEL** per visualizzare rispettivamente **"away home"** e **"at home"**.

   .. image:: img/09_web_dashboard_2_shadow.png
        :width: 600
        :align: center

4. Nelle impostazioni del **Label widget**, collegalo al datastream **Current Status(V1)**.

   .. image:: img/09_web_dashboard_3_shadow.png
        :width: 600
        :align: center

**2.5 Impostazione di un Evento**

1. Clicca su **Events & Notifications** e poi su **Create Event**.

   .. image:: img/09_blynk_event_add.png
        :width: 600
        :align: center
    
2. Assegna un nome all'evento e specifica il suo codice. Scegli **Warning** per **TYPE** e fornisci una breve descrizione per l'email di notifica. Regola la frequenza delle notifiche secondo le tue preferenze.

   .. note::
   
      Assicurati che il **CODICE EVENTO** sia impostato su ``intrusion_detected``. Qualsiasi modifica qui richiede corrispondenti adattamenti nel codice.

   .. image:: img/09_event_1_shadow.png
        :width: 600
        :align: center

3. Vai alla sezione **Notifications** per abilitare le notifiche e configurare le impostazioni email.

   .. image:: img/09_event_2_shadow.png
        :width: 600
        :align: center

4. Sotto **Settings**, definisci con quale frequenza un evento attiverà le notifiche e imposta gli intervalli secondo le tue preferenze. Ricorda di cliccare su **Create** per salvare le impostazioni.

   .. image:: img/09_event_3_shadow.png
        :width: 600
        :align: center

**2.6 Salvataggio del Template**

1. Ricorda di salvare le modifiche apportate al template.

   .. image:: img/09_save_template_shadow.png
        :width: 600
        :align: center

**2.7 Creazione di un Dispositivo**

1. È il momento di creare un nuovo dispositivo dal template.

   .. image:: img/09_blynk_device_new.png
        :width: 600
        :align: center

2. Seleziona **From template** per iniziare.

   .. image:: img/09_blynk_device_template.png
        :width: 600
        :align: center

3. Scegli il template **Intrusion Alert System** e clicca su **Create**.

   .. image:: img/09_blynk_device_template2.png
        :width: 600
        :align: center

4. Annota il **Template ID**, il **Device Name** e l'**AuthToken** per l'integrazione con l'ESP32.

   .. image:: img/09_blynk_device_code.png
        :width: 600
        :align: center

3. Esecuzione del Codice
-----------------------------
#. Prima di eseguire il codice, assicurati di installare la libreria ``Blynk`` dal **Library Manager** nell'IDE di Arduino.

    .. image:: img/09_blynk_add_library.png
        :width: 700
        :align: center

#. Apri il file ``iot_9_intrusion_alert_system.ino``, che si trova nella directory ``esp32-starter-kit-main\c\codes\iot_9_intrusion_alert_system``. Puoi anche copiarne il contenuto nell'IDE di Arduino.

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/16bca228-64d7-4519-ac3b-833afecfcc65/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


#. Sostituisci i segnaposto per ``BLYNK_TEMPLATE_ID``, ``BLYNK_TEMPLATE_NAME`` e ``BLYNK_AUTH_TOKEN`` con i tuoi ID unici.

    .. code-block:: arduino
    
        #define BLYNK_TEMPLATE_ID "TMPxxxxxxx"
        #define BLYNK_TEMPLATE_NAME "Intrusion Alert System"
        #define BLYNK_AUTH_TOKEN "xxxxxxxxxxxxx"

#. Devi anche inserire il ``ssid`` e la ``password`` della tua rete WiFi.

   .. code-block:: arduino

        char ssid[] = "your_ssid";
        char pass[] = "your_password";

#. Scegli la scheda corretta (**ESP32 Dev Module**) e la porta, quindi clicca sul pulsante **Upload**.

#. Apri il Serial monitor (imposta la velocità di baud a 115200) e attendi un messaggio di connessione avvenuta con successo.

    .. image:: img/09_blynk_upload_code.png
        :align: center

#. Dopo una connessione avvenuta con successo, attivando l'interruttore su Blynk inizierà la sorveglianza del modulo PIR. Quando viene rilevato un movimento (stato di 1), verrà visualizzato "Somebody here!" e verrà inviato un avviso alla tua email.

    .. image:: img/09_blynk_code_alarm.png
        :width: 700
        :align: center

4. Spiegazione del Codice
-----------------------------

#. **Configurazione e Librerie**

   In questa sezione, configuri le costanti e le credenziali di Blynk. Includi anche le librerie necessarie per ESP32 e Blynk.

    .. code-block:: arduino

        /* Commenta questa riga per disabilitare le stampe e risparmiare spazio */
        #define BLYNK_PRINT Serial

        #define BLYNK_TEMPLATE_ID "xxxxxxxxxxx"
        #define BLYNK_TEMPLATE_NAME "Intrusion Alert System"
        #define BLYNK_AUTH_TOKEN "xxxxxxxxxxxxxxxxxxxxxxxxxxx"

        #include <WiFi.h>
        #include <WiFiClient.h>
        #include <BlynkSimpleEsp32.h>

#. **Configurazione del WiFi**

   Inserisci le credenziali della tua rete WiFi.

   .. code-block:: arduino

        char ssid[] = "your_ssid";
        char pass[] = "your_password";

#. **Configurazione del Sensore PIR**

   Imposta il pin a cui è collegato il sensore PIR e inizializza le variabili di stato.

   .. code-block:: arduino

      const int sensorPin = 14;
      int state = 0;
      int awayHomeMode = 0;
      BlynkTimer timer;

#. **Funzione setup()**

   Questa funzione inizializza il sensore PIR come input, configura la comunicazione seriale, si connette al WiFi e configura Blynk.

   - Usiamo ``timer.setInterval(1000L, myTimerEvent)`` per impostare l'intervallo del timer nel ``setup()``, qui è impostato per eseguire la funzione ``myTimerEvent()`` ogni **1000ms**. Puoi modificare il primo parametro di ``timer.setInterval(1000L, myTimerEvent)`` per cambiare l'intervallo tra le esecuzioni di ``myTimerEvent``.

   .. raw:: html
    
    <br/> 

   .. code-block:: arduino

        void setup() {

            pinMode(sensorPin, INPUT);  // Imposta il pin del sensore PIR come input
            Serial.begin(115200);       // Avvia la comunicazione seriale a 115200 baud per il debug
            
            // Configura Blynk e connettiti al WiFi
            Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);
            
            timer.setInterval(1000L, myTimerEvent);  // Imposta una funzione da chiamare ogni secondo
        }

#. **Funzione loop()**

   La funzione loop esegue continuamente Blynk e le funzioni del timer di Blynk.

   .. code-block:: arduino

        void loop() {
           Blynk.run();
           timer.run();
        }

#. **Interazione con l'App Blynk**

   Queste funzioni vengono chiamate quando il dispositivo si connette a Blynk e quando c'è un cambiamento nello stato del pin virtuale V0 sull'app Blynk.

   - Ogni volta che il dispositivo si connette al server Blynk, o si riconnette a causa di condizioni di rete scarse, viene chiamata la funzione ``BLYNK_CONNECTED()``. Il comando ``Blynk.syncVirtual()`` richiede il valore di un singolo Pin Virtuale. Il Pin Virtuale specificato eseguirà la chiamata ``BLYNK_WRITE()``. 

   - Ogni volta che il valore di un pin virtuale sul server BLYNK cambia, verrà attivata la funzione ``BLYNK_WRITE()``.

   .. raw:: html
    
    <br/> 

   .. code-block:: arduino
      
        // Questa funzione viene chiamata ogni volta che il dispositivo si connette a Blynk.Cloud
        BLYNK_CONNECTED() {
            Blynk.syncVirtual(V0);
        }
      
        // Questa funzione viene chiamata ogni volta che lo stato del Pin Virtuale 0 cambia
        BLYNK_WRITE(V0) {
            awayHomeMode = param.asInt();
            // logica aggiuntiva
        }

#. **Gestione dei Dati**

   Ogni secondo, la funzione ``myTimerEvent()`` chiama ``sendData()``. Se la modalità away è abilitata su Blynk, controlla il sensore PIR e invia una notifica a Blynk se viene rilevato un movimento.

   - Usiamo ``Blynk.virtualWrite(V1, "Qualcuno è in casa tua! Controlla!");`` per cambiare il testo di un'etichetta.

   - Usa ``Blynk.logEvent("intrusion_detected");`` per registrare un evento su Blynk.

   .. raw:: html
    
    <br/> 

   .. code-block:: arduino

        void myTimerEvent() {
           sendData();
        }

        void sendData() {
           if (awayHomeMode == 1) {
              state = digitalRead(sensorPin);  // Leggi lo stato del sensore PIR

              Serial.print("state:");
              Serial.println(state);

              // Se il sensore rileva un movimento, invia un allarme all'app Blynk
              if (state == HIGH) {
                Serial.println("Somebody here!");
                Blynk.virtualWrite(V1, "Somebody in your house! Please check!");
                Blynk.logEvent("intrusion_detected");
              }
           }
        }

**Riferimenti**

- |link_blynk_doc|
- |link_blynk_quickstart| 
- |link_blynk_virtualWrite|
- |link_blynk_logEvent|
- |link_blynk_timer_intro|
- |link_blynk_syncing| 
- |link_blynk_write|