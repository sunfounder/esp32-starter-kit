.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato a nuovi annunci di prodotti e anteprime.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_mp3_player_sd:

7.5 Lettore MP3 con Supporto per Scheda SD
===============================================

Benvenuto nel mondo entusiasmante della musica con il tuo ESP32! Questo progetto porta la potenza dell'elaborazione audio a portata di mano, trasformando il tuo ESP32 non solo in un incredibile microcontrollore, ma anche nel tuo lettore musicale personalizzato. Immagina di entrare nella tua stanza e ascoltare il tuo brano preferito suonato direttamente da questo minuscolo dispositivo. Questa è la potenza che oggi ti mettiamo a disposizione.

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
    *   - :ref:`cpn_audio_speaker`
        - \-

**Passaggi Operativi**

#. Inserisci la tua scheda SD nel computer utilizzando un lettore di schede, quindi formattala. Puoi fare riferimento al tutorial su :ref:`format_sd_card`.

#. Copia il tuo file MP3 preferito sulla scheda SD.

    .. image:: img/mp3_music.png

#. Inserisci la scheda SD nello slot della scheda di espansione.

    .. image:: ../../img/insert_sd.png

#. Costruisci il circuito.

    Poiché si tratta di un amplificatore mono, puoi collegare IO25 al pin L o R del modulo amplificatore audio.

    La resistenza da 10K è utilizzata per ridurre il rumore ad alta frequenza e abbassare il volume audio. Forma un filtro passa-basso RC con la capacità parassita del DAC e dell'amplificatore audio. Questo filtro riduce l'ampiezza dei segnali ad alta frequenza, diminuendo efficacemente il rumore ad alta frequenza. Quindi, aggiungendo la resistenza da 10K, la musica risulterà più morbida ed eliminerà il rumore ad alta frequenza indesiderato.

    Se la musica sulla tua scheda SD è già morbida, puoi rimuovere o sostituire la resistenza con un valore inferiore.

    .. image:: ../../img/wiring/7.3_bluetooth_audio_player_bb.png

#. Collega l'ESP32-WROOM-32E al computer utilizzando il cavo USB.

    .. image:: ../../img/plugin_esp32.png

#. Modifica il codice.

    Modifica la riga di codice ``file = new AudioFileSourceSD_MMC("/To Alice.mp3")``; per riflettere il nome e il percorso del tuo file.

    .. note::

        * Apri il file ``7.5_mp3_player_sd.ino`` nel percorso ``esp32-starter-kit-main\c\codes\7.5_mp3_player_sd``. Oppure copia questo codice nell'**Arduino IDE**.
        * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta appropriata, fai clic sul pulsante **Upload**.
        * :ref:`unknown_com_port`
        * La libreria ``ESP8266Audio`` è utilizzata qui, fai riferimento a :ref:`install_lib_man` per un tutorial sull'installazione.
        
    .. warning::

        Se stai utilizzando una scheda di sviluppo ESP32 versione 3.0.0 o superiore, potresti incontrare errori durante il processo di compilazione.
        Questo problema è solitamente dovuto al fatto che le versioni più recenti della scheda non supportano più la libreria ``ESP8266Audio``.
        Per eseguire correttamente questo esempio, si consiglia di eseguire il downgrade del firmware della tua scheda ESP32 alla versione 2.0.17. 
        Dopo aver completato questo esempio, esegui l'aggiornamento all'ultima versione.

        .. image:: ../../faq/img/version_2.0.17.png


    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/13f5c757-9622-4735-aa1a-fdbe6fc46273/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
        
#. Seleziona la porta e la scheda appropriate nell'Arduino IDE e carica il codice sul tuo ESP32.

#. Dopo aver caricato correttamente il codice, sentirai suonare la tua musica preferita.


**Come funziona?**

* Il codice utilizza diverse classi dalla libreria ``ESP8266Audio`` per riprodurre un file MP3 da una scheda SD tramite I2S:

    .. code-block:: arduino

        #include "AudioFileSourceSD_MMC.h"
        #include "AudioOutputI2S.h"
        #include "AudioGeneratorMP3.h"
        #include "SD_MMC.h"
        #include "FS.h"

    * ``AudioGeneratorMP3`` è una classe che decodifica l'audio MP3.
    * ``AudioFileSourceSD_MMC`` è una classe che legge i dati audio da una scheda SD.
    * ``AudioOutputI2S`` è una classe che invia i dati audio all'interfaccia I2S.

* Nella funzione ``setup()``, inizializziamo la scheda SD, apriamo il file MP3 dalla scheda SD, configuriamo l'uscita I2S sul DAC interno dell'ESP32, impostiamo l'uscita su mono e avviamo il generatore MP3.

    .. code-block:: arduino

        void setup() {
            // Avvia la comunicazione seriale.
            Serial.begin(115200);
            delay(1000);

            // Inizializza la scheda SD. Se fallisce, stampa un messaggio di errore.
            if (!SD_MMC.begin()) {
                Serial.println("SD card mount failed!");
            }

            // Apri il file MP3 dalla scheda SD. Sostituisci "/To Alice.mp3" con il nome del tuo file MP3.
            file = new AudioFileSourceSD_MMC("/To Alice.mp3");
            
            // Configura l'uscita I2S sul DAC interno dell'ESP32.
            out = new AudioOutputI2S(0, 1);
            
            // Imposta l'uscita su mono.
            out->SetOutputModeMono(true);

            // Inizializza il generatore MP3 con il file e l'uscita.
            mp3 = new AudioGeneratorMP3();
            mp3->begin(file, out);
        }


* Nella funzione ``loop()``, controlliamo se il generatore MP3 è in esecuzione. Se lo è, continuiamo a farlo funzionare; altrimenti, lo fermiamo e stampiamo "MP3 done" sul monitor seriale.

    .. code-block:: arduino

        void loop() {
            // Se l'MP3 è in esecuzione, continua a looparlo. Altrimenti, fermalo.
            if (mp3->isRunning()) {
                if (!mp3->loop()) mp3->stop();
            } 
            // Se l'MP3 non è in esecuzione, stampa un messaggio e attendi 1 secondo.
            else {
                Serial.println("MP3 done");
                delay(1000);
            }
        }


