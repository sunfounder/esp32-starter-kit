.. note::

    Ciao, benvenuto nella Community di Appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirsi a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni l'accesso anticipato a nuovi annunci di prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _bluetooth_audio_player:

7.3 Lettore Audio Bluetooth
==============================

L'obiettivo del progetto è fornire una soluzione semplice per riprodurre audio 
da un dispositivo con Bluetooth utilizzando il DAC integrato dell'ESP32.

Il progetto prevede l'uso della libreria ``ESP32-A2DP`` per ricevere dati audio 
da un dispositivo Bluetooth. I dati audio ricevuti vengono poi trasmessi al DAC 
interno dell'ESP32 tramite l'interfaccia I2S. L'interfaccia I2S è configurata 
per operare in modalità master, modalità trasmissione e modalità DAC integrata. 
I dati audio vengono poi riprodotti attraverso l'altoparlante collegato al DAC.

Quando si utilizza il DAC interno dell'ESP32, è importante notare che il livello 
di tensione in uscita è limitato a 1,1 V. Pertanto, si consiglia di utilizzare un 
amplificatore esterno per aumentare il livello di tensione di uscita al livello 
desiderato. È inoltre importante assicurarsi che i dati audio siano nel formato 
corretto e con la frequenza di campionamento adeguata per evitare distorsioni o 
rumori durante la riproduzione.

**Componenti necessari**

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

#. Costruisci il circuito.

    Poiché questo è un amplificatore mono, puoi collegare IO25 al pin L o R del modulo amplificatore audio.

    Il resistore da 10K viene utilizzato per ridurre il rumore ad alta frequenza e abbassare il volume audio. Forma un filtro passa-basso RC con la capacità parassita del DAC e dell'amplificatore audio. Questo filtro diminuisce l'ampiezza dei segnali ad alta frequenza, riducendo efficacemente il rumore ad alta frequenza. Quindi, aggiungere il resistore da 10K rende la musica più morbida ed elimina i rumori indesiderati ad alta frequenza.

    Se la musica della tua scheda SD è già morbida, puoi rimuovere o sostituire il resistore con un valore più basso.

    .. image:: ../../img/wiring/7.3_bluetooth_audio_player_bb.png

#. Apri il codice.

    * Apri il file ``7.3_bluetooth_audio_player.ino`` nel percorso ``esp32-starter-kit-main\c\codes\7.3_bluetooth_audio_player``.
    * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta appropriata, clicca sul pulsante **Carica**.
    * :ref:`unknown_com_port`
    * Qui viene utilizzata la libreria ``ESP32-A2DP``, fai riferimento a :ref:`install_lib_man` per un tutorial sull'installazione.

    .. warning::

        Se stai usando una scheda di sviluppo ESP32 versione 3.0.0 o superiore, potresti riscontrare errori durante il processo di compilazione.
        Questo problema è di solito dovuto al fatto che le versioni più recenti della scheda non supportano più la libreria ``ESP32-A2DP``.
        Per eseguire correttamente questo esempio, si consiglia di eseguire il downgrade del firmware della tua scheda ESP32 alla versione 2.0.17. 
        Dopo aver completato questo esempio, aggiorna nuovamente all'ultima versione.

        .. image:: ../../faq/img/version_2.0.17.png

    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/7bb7d6dd-72d4-4529-bb42-033b38558347/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
        
#. Dopo aver selezionato la scheda e la porta corrette, clicca sul pulsante Carica.

#. Una volta che il codice è stato caricato con successo, accendi il dispositivo con Bluetooth e cerca i dispositivi disponibili, quindi connettiti a ``ESP32_Bluetooth``.

    .. image:: img/connect_bluetooth.png

#. Riproduci audio sul dispositivo e l'audio dovrebbe essere riprodotto attraverso l'altoparlante collegato all'ESP32.


**Spiegazione del Codice**

#. Il codice inizia includendo la libreria ``BluetoothA2DPSink.h``, che viene utilizzata per ricevere dati audio dal dispositivo Bluetooth. L'oggetto ``BluetoothA2DPSink`` viene poi creato e configurato con le impostazioni dell'interfaccia I2S.

    .. code-block:: arduino

        #include "BluetoothA2DPSink.h"

        BluetoothA2DPSink a2dp_sink;


#. Nella funzione setup, il codice inizializza una ``struct i2s_config_t`` con la configurazione desiderata per l'interfaccia I2S (Inter-IC Sound).

    .. code-block:: arduino

        void setup() {
        const i2s_config_t i2s_config = {
            .mode = (i2s_mode_t) (I2S_MODE_MASTER | I2S_MODE_TX | I2S_MODE_DAC_BUILT_IN),
            .sample_rate = 44100, // corretto dall'informazione dal bluetooth
            .bits_per_sample = (i2s_bits_per_sample_t) 16, // il modulo DAC prenderà solo gli 8 bit dal MSB
            .channel_format =  I2S_CHANNEL_FMT_RIGHT_LEFT,
            .communication_format = (i2s_comm_format_t)I2S_COMM_FORMAT_STAND_MSB,
            .intr_alloc_flags = 0, // priorità interrupt predefinita
            .dma_buf_count = 8,
            .dma_buf_len = 64,
            .use_apll = false
        };

        a2dp_sink.set_i2s_config(i2s_config);  
        a2dp_sink.start("ESP32_Bluetooth");  

        }

    * L'interfaccia I2S viene utilizzata per trasferire dati audio digitali tra dispositivi.
    * La configurazione include ``modalità I2S``, ``frequenza di campionamento``, ``bit per campione``, ``formato del canale``, ``formato di comunicazione``, ``flag di allocazione degli interrupt``, ``conteggio buffer DMA``, ``lunghezza buffer DMA`` e se usare o meno l'APLL (Audio PLL).
    * La ``struct i2s_config_t`` viene poi passata come argomento alla funzione ``set_i2s_config`` dell'oggetto ``BluetoothA2DPSink`` per configurare l'interfaccia I2S per la riproduzione audio.
    * La funzione ``start`` dell'oggetto ``BluetoothA2DPSink`` viene chiamata per avviare il sink audio Bluetooth e iniziare a riprodurre audio tramite il DAC integrato.
