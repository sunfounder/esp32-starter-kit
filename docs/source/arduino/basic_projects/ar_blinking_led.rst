.. note::

    Ciao, benvenuto nella Community di Appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirsi a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni l'accesso anticipato a nuovi annunci di prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_blink:

2.1 Ciao, LED!
=======================================

Proprio come scrivere "Hello, world!" è il primo passo nell'apprendimento della programmazione, usare un programma per accendere un LED è la tradizionale introduzione alla programmazione fisica.

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
    *   - :ref:`cpn_led`
        - |link_led_buy|


**Pin Disponibili**


Ecco un elenco di pin disponibili sulla scheda ESP32 per questo progetto.

.. list-table::
    :widths: 5 20 

    * - Pin Disponibili
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**Schema Elettrico**

.. image:: ../../img/circuit/circuit_2.1_led.png

Questo circuito funziona su un principio semplice, e la direzione della corrente è mostrata nella figura. Il LED si accenderà dopo il resistore limitatore di corrente da 220 ohm quando il pin 26 emette un livello alto. Il LED si spegnerà quando il pin 26 emette un livello basso.

**Cablaggio**

.. image:: ../../img/wiring/2.1_hello_led_bb.png



**Caricamento del Codice**

#. Puoi aprire il file ``2.1_hello_led.ino`` nel percorso ``esp32-starter-kit-main\c\codes\2.1_hello_led``. Oppure copia direttamente questo codice nell'IDE di Arduino.
    
    .. raw:: html

        <iframe src=https://create.arduino.cc/editor/sunfounder01/1bff2463-40ad-43c1-8815-9f448bab3735/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
#. Poi collega l'ESP32 WROOM 32E al tuo computer utilizzando un cavo Micro USB.

    * :ref:`unknown_com_port`

    .. image:: ../../img/plugin_esp32.png
        :width: 600
        :align: center

#. Seleziona la scheda (ESP32 Dev Module) e la porta appropriata.

    .. image:: img/choose_board.png

#. Ora, clicca sul pulsante **Carica** per caricare il codice sulla scheda ESP32.
    
    .. image:: img/click_upload.png

#. Dopo che il codice è stato caricato con successo, vedrai il LED lampeggiare.

**Come funziona?**

#. Dichiarare una costante intera chiamata ``ledPin`` e assegnarle il valore 26.

    .. code-block:: arduino

        const int ledPin = 26;  // Il pin GPIO per il LED

#. Ora, inizializza il pin nella funzione ``setup()``, dove devi inizializzare il pin in modalità ``OUTPUT``.

    .. code-block:: arduino

        void setup() {
            pinMode(ledPin, OUTPUT);
        }

    * ``void pinMode(uint8_t pin, uint8_t mode);``: Questa funzione viene utilizzata per definire la modalità di funzionamento del GPIO per un pin specifico.

        * ``pin`` definisce il numero del pin GPIO.
        * ``mode`` imposta la modalità di funzionamento.

        Le seguenti modalità sono supportate per l'input e l'output di base:

        * ``INPUT`` imposta il GPIO come input senza pullup o pulldown (alta impedenza).
        * ``OUTPUT`` imposta il GPIO come modalità di output/lettura.
        * ``INPUT_PULLDOWN`` imposta il GPIO come input con il pulldown interno.
        * ``INPUT_PULLUP`` imposta il GPIO come input con il pullup interno.

#. La funzione ``loop()`` contiene la logica principale del programma e viene eseguita continuamente. Alterna tra l'impostazione del pin ad alto e basso livello, con intervalli di un secondo tra i cambiamenti.

    .. code-block:: arduino

        void loop() {
            digitalWrite(ledPin, HIGH);   // accendi il LED (HIGH è il livello di tensione)
            delay(1000);                  // aspetta un secondo
            digitalWrite(ledPin, LOW);    // spegni il LED abbassando la tensione
            delay(1000);                  // aspetta un secondo
        }

    * ``void digitalWrite(uint8_t pin, uint8_t val);``: Questa funzione imposta lo stato del GPIO selezionato su ``HIGH`` o ``LOW``. Questa funzione viene utilizzata solo se la ``pinMode`` è configurata come ``OUTPUT``.
    
        * ``pin`` definisce il numero del pin GPIO.
        * ``val`` imposta lo stato digitale di uscita su ``HIGH`` o ``LOW``.
