.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato a nuovi annunci di prodotti e anteprime.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_pa_buz:

3.2 Tono Personalizzato
==========================================

Abbiamo utilizzato il buzzer attivo nel progetto precedente, questa volta useremo un buzzer passivo.

Come il buzzer attivo, anche il buzzer passivo utilizza il fenomeno dell'induzione elettromagnetica per funzionare. La differenza è che un buzzer passivo non ha una sorgente oscillante, quindi non emette suoni se vengono utilizzati segnali DC.
Ma questo permette al buzzer passivo di regolare la propria frequenza di oscillazione e può emettere diverse note come "doh, re, mi, fa, sol, la, ti".

Facciamo emettere una melodia al buzzer passivo!

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
    *   - :ref:`cpn_buzzer`
        - \-
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|

**Pin Disponibili**

Ecco un elenco dei pin disponibili sulla scheda ESP32 per questo progetto.

.. list-table::
    :widths: 5 20 

    * - Pin Disponibili
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**Schema**

.. image:: ../../img/circuit/circuit_3.1_buzzer.png
    :width: 500
    :align: center

Quando l'uscita di IO14 è alta, dopo la resistenza di limitazione della corrente da 1K (per proteggere il transistor), il transistor S8050 (NPN) condurrà, permettendo così al buzzer di emettere un suono.

Il ruolo del transistor S8050 (NPN) è di amplificare la corrente e rendere il suono del buzzer più forte. Infatti, puoi anche collegare direttamente il buzzer a IO14, ma noterai che il suono del buzzer sarà più debole.

**Cablatura**

Nel kit sono inclusi due tipi di buzzer. 
Dobbiamo utilizzare il buzzer passivo. Girali e noterai che il PCB esposto è quello che vogliamo usare.

.. image:: ../../components/img/buzzer.png
    :width: 500
    :align: center

Il buzzer necessita di un transistor per funzionare, qui utilizziamo l'S8050 (Transistor NPN).

.. image:: ../../img/wiring/3.1_buzzer_bb.png

**Codice**

.. note::

    * Apri il file ``3.2_custom_tone.ino`` nel percorso ``esp32-starter-kit-main\c\codes\3.2_custom_tone``.
    * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta appropriata, fai clic sul pulsante **Upload**.
    * :ref:`unknown_com_port`
    
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/09a319a6-6861-40e1-ba1b-e7027bc0383d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Dopo che il codice è stato caricato con successo, sentirai il buzzer passivo suonare una sequenza di 7 note musicali.


**Come funziona?**

#. Definisci costanti per il pin del buzzer e la risoluzione PWM.

    .. code-block:: arduino

        const int buzzerPin = 14; //pin del buzzer
        const int resolution = 8; 

#. Definisci un array contenente le frequenze delle 7 note musicali in Hz.

    .. code-block:: arduino

        int frequencies[] = {262, 294, 330, 349, 392, 440, 494};

#. Crea una funzione per suonare una data frequenza sul buzzer per una durata specificata.

    .. code-block:: arduino

        void playFrequency(int frequency, int duration) {
            ledcWriteTone(buzzerPin, frequency); // Avvia la tonalità
            delay(duration); // Attendi per la durata specificata
            ledcWriteTone(buzzerPin, 0); // Ferma il buzzer
        }

    * ``uint32_t ledcWriteTone(uint8_t pin, uint32_t freq);``: Questa funzione è utilizzata per impostare il pin a un tono PWM del 50% sulla frequenza selezionata.

        * ``pin`` seleziona il pin LEDC.
        * ``freq`` seleziona la frequenza del segnale pwm.

    Questa funzione restituirà la ``frequency`` impostata per il canale. Se viene restituito ``0``, si è verificato un errore e il canale ledc non è stato configurato.

#. Configura il canale PWM e collega il pin del buzzer nella funzione ``setup()``.

    .. code-block:: arduino

        void setup() {
            ledcAttach(buzzerPin, 2000, resolution); // Configura il pin PWM
        }

    * ``bool ledcAttach(uint8_t pin, uint32_t freq, uint8_t resolution);``: Questa funzione è utilizzata per configurare il pin LEDC con la frequenza e la risoluzione desiderate. Il canale LEDC sarà selezionato automaticamente.
            
        * ``pin`` seleziona il pin GPIO.
        * ``freq`` seleziona la frequenza del pwm.
        * ``resolution_bits`` seleziona la risoluzione per il canale ledc. L'intervallo è 1-14 bit (1-20 bit per ESP32).


#. Nella funzione ``loop()``, suona la sequenza delle 7 note con una breve pausa tra ciascuna nota e una pausa di 1 secondo prima di ripetere la sequenza.

    .. code-block:: arduino

        void loop() {
            for (int i = 0; i < 7; i++) {
                playFrequency(frequencies[i], 300); // Suona ogni nota per 300ms
                delay(50); // Aggiungi una breve pausa tra le note
            }
            delay(1000); // Attendi 1 secondo prima di ripetere la sequenza
        }
