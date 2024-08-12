.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e alle anteprime.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_receiver:

5.14 Ricevitore IR
=========================
Un ricevitore a infrarossi è un componente che riceve segnali infrarossi e può rilevare e uscire autonomamente segnali compatibili con il livello TTL. È simile per dimensioni a un transistor in confezione di plastica ed è comunemente utilizzato in varie applicazioni come il telecomando a infrarossi e la trasmissione a infrarossi.

In questo progetto, utilizzeremo un ricevitore a infrarossi per rilevare segnali da un telecomando. Quando viene premuto un pulsante sul telecomando e il ricevitore a infrarossi riceve il segnale corrispondente, può decodificare il segnale per determinare quale pulsante è stato premuto. Decodificando il segnale ricevuto, possiamo identificare il tasto o il comando specifico associato.

Il ricevitore a infrarossi ci consente di incorporare funzionalità di controllo remoto nel nostro progetto, permettendoci di interagire e controllare i dispositivi utilizzando segnali infrarossi.

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
    *   - :ref:`cpn_receiver`
        - |link_receiver_buy|


**Pin Disponibili**

    Ecco un elenco di pin disponibili sulla scheda ESP32 per questo progetto.

    .. list-table::
        :widths: 5 20

        *   - Pin Disponibili
            - IO13, IO12, IO14, IO27, IO26, IO25, IO15, IO0, IO5, IO18, IO19, IO21, IO22, IO23

**Schema Elettrico**

.. image:: ../../img/circuit/circuit_5.14_receiver.png

Quando premi un pulsante sul telecomando, il ricevitore a infrarossi rileva il segnale e puoi utilizzare una libreria a infrarossi per decodificarlo. Questo processo di decodifica ti consente di ottenere il valore del tasto associato alla pressione del pulsante.

**Cablaggio**

.. image:: ../../img/wiring/5.14_ir_receiver_bb.png

**Codice**

.. note::

    * Apri il file ``5.14_ir_receiver.ino`` nel percorso ``esp32-starter-kit-main\c\codes\5.14_ir_receiver``.
    * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta appropriata, fai clic sul pulsante **Upload**.
    * :ref:`unknown_com_port`
    * Qui viene utilizzata la libreria ``IRremoteESP8266``, puoi installarla dal **Library Manager**.

        .. image:: img/receiver_lib.png


.. warning::

    Se stai utilizzando una scheda di sviluppo ESP32 versione 3.0.0 o superiore, potresti incontrare errori durante il processo di compilazione.
    Questo problema è generalmente dovuto al fatto che le versioni più recenti della scheda non supportano più la libreria ``IRremoteESP8266``.
    Per eseguire correttamente questo esempio, si consiglia di effettuare il downgrade del firmware della tua scheda ESP32 alla versione 2.0.17. 
    Dopo aver completato questo esempio, aggiorna nuovamente all'ultima versione.

    .. image:: ../../faq/img/version_2.0.17.png



.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/463c8894-00bd-4035-a81c-cad99a7f3731/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Ricorda di impostare la velocità di comunicazione seriale a 115200 baud.

Dopo che il codice è stato caricato con successo, premi i diversi tasti sul telecomando e vedrai i nomi di questi tasti apparire nel monitor seriale.

.. note::
    * La libreria ``IRremoteESP8266`` include implementazioni per molti protocolli e dispositivi a infrarossi diversi, quindi la dimensione della libreria è relativamente grande. Quando il compilatore deve elaborare più codice, il tempo di compilazione aumenterà di conseguenza. Abbi pazienza e attendi che la compilazione sia completata.
    * Il nuovo telecomando presenta una linguetta di plastica all'estremità per isolare la batteria all'interno. Per accendere il telecomando durante l'uso, basta rimuovere questo pezzo di plastica.


**Come funziona?**

#. Questo codice utilizza la libreria ``IRremoteESP8266`` per ricevere segnali infrarossi (IR) utilizzando un modulo ricevitore IR.

    .. code-block:: arduino

        #include <IRremoteESP8266.h>
        #include <IRrecv.h>

        // Definisci il pin del ricevitore IR
        const uint16_t IR_RECEIVE_PIN = 14;

        // Crea un oggetto IRrecv
        IRrecv irrecv(IR_RECEIVE_PIN);

        // Crea un oggetto decode_results
        decode_results results;
    
#. Nella funzione ``setup()``, viene avviata la comunicazione seriale a una velocità di 115200 baud e il ricevitore IR viene abilitato utilizzando ``irrecv.enableIRIn()``.

    .. code-block:: arduino

        void setup() {
            // Avvia la comunicazione seriale
            Serial.begin(115200);
            
            // Avvia il ricevitore IR
            irrecv.enableIRIn();
        }

#. Quando premi un tasto sul telecomando, il monitor seriale stamperà il nome del tasto se viene ricevuto dal ricevitore IR.

    .. code-block:: arduino

        void loop() {
            // Se viene ricevuto un segnale IR
            if (irrecv.decode(&results)) {
                String key = decodeKeyValue(results.value);
                if (key != "ERROR") {
                    // Stampa il valore del segnale nel monitor seriale
                    Serial.println(key);
                }
                irrecv.resume(); // Continua a ricevere il prossimo segnale
            }
        }

    * Per prima cosa, controlla se viene ricevuto un segnale IR utilizzando la funzione ``irrecv.decode()``. 
    * Se viene ricevuto un segnale, chiama la funzione ``decodeKeyValue()`` per decodificare il valore del segnale. 
    * Se il segnale viene decodificato con successo, il valore decodificato viene stampato nel monitor seriale utilizzando ``Serial.println()``.
    * Infine, viene chiamato ``irrecv.resume()`` per continuare a ricevere il prossimo segnale.

#. La funzione ``decodeKeyValue()`` prende il valore decodificato del segnale IR come argomento e restituisce una stringa che rappresenta il tasto premuto sul telecomando.

    .. code-block:: arduino

        String decodeKeyValue(long result)
        {
            switch(result){
                case 0xFF6897:
                return "0";
                case 0xFF30CF:
                return "1"; 
                case 0xFF18E7:
                return "2"; 
                case 0xFF7A85:
                ...

    * La funzione utilizza un'istruzione switch per abbinare il valore decodificato al tasto corrispondente e restituisce la rappresentazione in stringa del tasto. 
    * Se il valore decodificato non corrisponde a nessun tasto noto, la funzione restituisce la stringa "ERROR".
