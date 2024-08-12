.. note::

    Ciao, benvenuto nella Community di Appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirsi a noi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e alle anteprime.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_fading:

2.2 Dissolvenza
======================

Nel progetto precedente, abbiamo controllato il LED accendendolo e spegnendolo utilizzando l'uscita digitale. In questo progetto, creeremo un effetto di respirazione sul LED utilizzando la modulazione di larghezza di impulso (PWM). La PWM è una tecnica che ci permette di controllare la luminosità di un LED o la velocità di un motore variando il ciclo di lavoro di un segnale a onda quadra.

Con la PWM, invece di accendere o spegnere semplicemente il LED, regoleremo il tempo in cui il LED è acceso rispetto al tempo in cui è spento in ogni ciclo. Commutando rapidamente il LED acceso e spento a intervalli variabili, possiamo creare l'illusione che il LED si illumini e si attenui gradualmente, simulando un effetto di respirazione.

Utilizzando le capacità PWM dell'ESP32 WROOM 32E, possiamo ottenere un controllo fluido e preciso sulla luminosità del LED. Questo effetto di respirazione aggiunge un elemento dinamico e visivamente accattivante ai tuoi progetti, creando un display o un'atmosfera che cattura l'attenzione.

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
    *   - :ref:`cpn_led`
        - |link_led_buy|

**Piedini Disponibili**

Ecco un elenco dei piedini disponibili sulla scheda ESP32 per questo progetto.

.. list-table::
    :widths: 5 20 

    * - Piedini Disponibili
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**Schema**

.. image:: ../../img/circuit/circuit_2.1_led.png

Questo progetto utilizza lo stesso circuito del primo progetto :ref:`ar_blink`, ma il tipo di segnale è diverso. Nel primo progetto si uscivano direttamente livelli digitali alti e bassi (0&1) dal pin26 per accendere o spegnere il LED, in questo progetto si esce un segnale PWM dal pin26 per controllare la luminosità del LED.



**Cablaggio**

.. image:: ../../img/wiring/2.1_hello_led_bb.png


**Codice**

.. note::

    * Puoi aprire il file ``2.2_fading_led.ino`` nel percorso ``esp32-starter-kit-main\c\codes\2.2_fading_led``. 
    * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta appropriata, clicca sul pulsante **Carica**.
    * :ref:`unknown_com_port`
   
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/aa898b09-be86-473b-9bfe-317556c696bb/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Dopo che il codice è stato caricato con successo, potrai vedere il LED respirare.

**Come funziona？**


#. Definisci costanti e variabili。

    .. code-block:: arduino

        const int ledPin = 26; // Il pin GPIO per il LED
        int brightness = 0;
        int fadeAmount = 5;
   
    * ``ledPin``: Il numero del pin GPIO a cui è collegato il LED (in questo caso, GPIO 26).
    * ``brightness``: Il livello di luminosità corrente del LED (inizialmente impostato a 0).
    * ``fadeAmount``: La quantità di variazione della luminosità del LED in ogni passaggio (impostata a 5).

#. Inizializza il canale PWM e configura il pin del LED.

    .. code-block:: arduino

        void setup() {
          ledcAttach(ledPin, 5000, 8);  // Collega il pin del LED
        }

    Qui utilizziamo la periferica |link_ledc| (controllo LED) progettata principalmente per controllare l'intensità dei LED, anche se può essere utilizzata anche per generare segnali PWM per altri scopi.

    * ``bool ledcAttach(uint8_t pin, uint32_t freq, uint8_t resolution);``: Questa funzione è usata per configurare il pin LEDC con la frequenza e la risoluzione specificate. Il canale LEDC sarà selezionato automaticamente.
            
        * ``pin`` seleziona il pin GPIO.
        * ``freq`` seleziona la frequenza del pwm.
        * ``resolution_bits`` seleziona la risoluzione per il canale ledc. Gamma da 1 a 14 bit (1-20 bit per ESP32).

#. La funzione ``loop()`` contiene la logica principale del programma e viene eseguita continuamente. Aggiorna la luminosità del LED, inverte la quantità di dissolvenza quando la luminosità raggiunge il valore minimo o massimo e introduce un ritardo.

    .. code-block:: arduino

        void loop() {
            ledcWrite(ledPin, brightness);  // Scrivi il nuovo valore di luminosità nel pin PWM
            brightness = brightness + fadeAmount;

            if (brightness <= 0 o brightness >= 255) {
                fadeAmount = -fadeAmount;
            }
            
            delay(50); // Aspetta 50 millisecondi
            }

    * ``bool ledcWrite(uint8_t pin, uint32_t duty);``: Questa funzione viene utilizzata per impostare il duty cycle per il pin LEDC.
        
        * ``pin`` seleziona il pin LEDC.
        * ``duty`` seleziona il duty cycle da impostare per il canale selezionato.

