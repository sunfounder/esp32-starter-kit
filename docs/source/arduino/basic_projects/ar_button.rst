.. note::

    Ciao, benvenuto nella Community di Appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirsi a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni l'accesso anticipato a nuovi annunci di prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_button:

5.1 Lettura del Valore del Pulsante
==============================================
In questo progetto interattivo, esploreremo il mondo dei controlli tramite pulsanti e la manipolazione di LED.

Il concetto è semplice ma efficace. Leggeremo lo stato di un pulsante. Quando il pulsante viene premuto, registra un livello di tensione alto, o 'stato alto'. Questa azione farà accendere un LED.

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
    *   - :ref:`cpn_button`
        - |link_button_buy|

**Pin Disponibili**

* **Pin Disponibili**

    Ecco un elenco dei pin disponibili sulla scheda ESP32 per questo progetto.

    .. list-table::
        :widths: 5 20

        *   - Per Input
            - IO14, IO25, I35, I34, I39, I36, IO18, IO19, IO21, IO22, IO23
        *   - Per Output
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23
    
* **Pin a Uso Condizionato (Input)**

    I seguenti pin hanno resistori pull-up o pull-down integrati, quindi non sono necessari resistori esterni quando **utilizzati come pin di ingresso**:


    .. list-table::
        :widths: 5 15
        :header-rows: 1

        *   - Pin a Uso Condizionato
            - Descrizione
        *   - IO13, IO15, IO2, IO4
            - Il pull-up con un resistore da 47K imposta il valore su alto per impostazione predefinita.
        *   - IO27, IO26, IO33
            - Il pull-up con un resistore da 4.7K imposta il valore su alto per impostazione predefinita.
        *   - IO32
            - Il pull-down con un resistore da 1K imposta il valore su basso per impostazione predefinita.

* **Pin di Strapping (Input)**

    I pin di strapping sono un insieme speciale di pin utilizzati per determinare modalità di avvio specifiche durante l'avvio del dispositivo 
    (ad esempio, reset all'accensione).
     
    .. list-table::
        :widths: 5 15

        *   - Pin di Strapping
            - IO5, IO0, IO2, IO12, IO15 
    
    Generalmente, **non è raccomandato utilizzarli come pin di ingresso**. Se desideri utilizzare questi pin, considera l'impatto potenziale sul processo di avvio. Per maggiori dettagli, consulta la sezione :ref:`esp32_strapping`.


**Schema**

.. image:: ../../img/circuit/circuit_5.1_button.png

Per garantire il corretto funzionamento, collega un lato del pin del pulsante a 3.3V e l'altro lato a IO14. Quando il pulsante viene premuto, IO14 sarà impostato su alto, causando l'accensione del LED. Quando il pulsante viene rilasciato, IO14 tornerà al suo stato sospeso, che potrebbe essere alto o basso. Per garantire un livello basso stabile quando il pulsante non è premuto, IO14 dovrebbe essere collegato a GND tramite un resistore pull-down da 10K.

**Cablaggio**

.. image:: ../../img/wiring/5.1_button_bb.png

.. note::
    
    Un pulsante a quattro pin è progettato in forma di H. Quando il pulsante non è premuto, i pin sinistro e destro sono disconnessi e la corrente non può fluire tra di essi. Tuttavia, quando il pulsante viene premuto, i pin sinistro e destro sono collegati, creando un percorso per il flusso di corrente.

**Codice**

.. note::

    * Puoi aprire il file ``5.1_button.ino`` sotto il percorso ``esp32-starter-kit-main\c\codes\5.1_button``. 
    * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta appropriata, clicca sul pulsante **Carica**.
    * :ref:`unknown_com_port`
   
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/702c5a70-78e7-4a8b-a0c7-10c0acebfc12/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Ricorda di impostare la velocità di comunicazione seriale a 115200.

Una volta che il codice è stato caricato con successo, il LED si accenderà quando premi il pulsante e si spegnerà quando lo rilasci.

Allo stesso tempo, puoi aprire il Monitor Seriale nell'angolo in alto a destra per osservare il valore del pulsante: quando il pulsante viene premuto, verrà stampato "1", altrimenti verrà stampato "0".

.. image:: img/button_serial.png


**Come funziona**

I progetti precedenti coinvolgevano l'output di segnali, sia sotto forma di segnali digitali che PWM.

Questo progetto implica la ricezione di segnali di input da un componente esterno alla scheda ESP32. Puoi visualizzare il segnale di input tramite il Monitor Seriale nell'IDE di Arduino.


#. Nella funzione ``setup()``, il pin del pulsante viene inizializzato come ``input`` e il pin del LED viene inizializzato come ``output``. La comunicazione seriale viene anche avviata con una velocità di baud di 115200.

    .. code-block:: arduino

        void setup() {
            Serial.begin(115200);
            // inizializza il pin del pulsante come input
            pinMode(buttonPin, INPUT);
            // inizializza il pin del LED come output
            pinMode(ledPin, OUTPUT);
        }
    
    * ``Serial.begin(speed)``: Imposta la velocità di trasmissione dei dati in bit per secondo (baud) per la trasmissione dei dati seriali.

        * ``speed``: in bit per secondo (baud). Tipi di dati ammessi: ``long``.

#. Nella funzione ``loop()``, lo stato del pulsante viene letto e memorizzato nella variabile ``buttonState``. Il valore di ``buttonState`` viene stampato nel Monitor Seriale utilizzando ``Serial.println()``.

    .. code-block:: arduino

        void loop() {
            // leggi lo stato del valore del pulsante
            buttonState = digitalRead(buttonPin);
            Serial.println(buttonState);
            delay(100);
            // se il pulsante è premuto, buttonState è HIGH
            if (buttonState == HIGH) {
                // accendi il LED
                digitalWrite(ledPin, HIGH);

            } else {
                // spegni il LED
                digitalWrite(ledPin, LOW);
            }
        }

    Se il pulsante è premuto e ``buttonState`` è HIGH, il LED si accende impostando ``ledPin`` su ``HIGH``. Altrimenti, spegni il LED.

    * ``int digitalRead(uint8_t pin);``: Per leggere lo stato di un determinato pin configurato come INPUT, viene utilizzata la funzione digitalRead. Questa funzione restituirà lo stato logico del pin selezionato come ``HIGH`` o ``LOW``.

        * ``pin`` seleziona il GPIO

    * ``Serial.println()``: Stampa i dati sulla porta seriale come testo ASCII leggibile dall'uomo seguito da un carattere di ritorno a capo (ASCII 13, o '\r') e un carattere di nuova linea (ASCII 10, o '\n').
