.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_rgb_strip:

2.7 Striscia LED RGB
======================

In questo progetto, esploreremo il mondo affascinante delle strisce LED WS2812 e daremo vita a un vivace spettacolo di colori. Con la capacità di controllare individualmente ciascun LED sulla striscia, possiamo creare effetti luminosi accattivanti che incanteranno i sensi.

Inoltre, abbiamo incluso un'estensione entusiasmante a questo progetto, dove esploreremo il mondo della casualità. Introducendo colori casuali e implementando un effetto di luce fluente, possiamo creare un'esperienza visiva ipnotica che catturerà e incanterà.

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
    *   - :ref:`cpn_ws2812`
        - |link_ws2812_buy|

**Schema**

.. image:: ../../img/circuit/circuit_2.7_ws2812.png
    :width: 500
    :align: center


**Pin Disponibili**

Ecco un elenco dei pin disponibili sulla scheda ESP32 per questo progetto.

.. list-table::
    :widths: 5 20 

    * - Pin Disponibili
      - IO13, IO12, IO14, IO27, IO26, IO25, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


.. note::

    IO33 non è disponibile per questo progetto.

    La striscia LED WS2812 richiede un segnale di modulazione a larghezza di impulso (PWM) preciso. Il segnale PWM ha requisiti precisi sia in termini di tempo che di tensione. Ad esempio, un bit "0" per il WS2812 corrisponde a un impulso di livello alto di circa 0,4 microsecondi, mentre un bit "1" corrisponde a un impulso di livello alto di circa 0,8 microsecondi. Ciò significa che la striscia ha bisogno di ricevere variazioni di tensione ad alta frequenza.

    Tuttavia, con una resistenza pull-up di 4,7K e un condensatore pull-down di 100nf su IO33, viene creato un semplice filtro passa-basso. Questo tipo di circuito "ammorbidisce" i segnali ad alta frequenza, poiché il condensatore ha bisogno di un po' di tempo per caricarsi e scaricarsi quando riceve variazioni di tensione. Pertanto, se il segnale cambia troppo rapidamente (cioè è ad alta frequenza), il condensatore non sarà in grado di tenere il passo. Ciò si traduce in un segnale di uscita che diventa sfocato e non riconoscibile dalla striscia.

**Collegamento**

.. image:: ../../img/wiring/2.7_rgb_strip_bb.png
    :width: 800

**Codice**

.. note::

    * Puoi aprire il file ``2.7_rgb_strip.ino`` nel percorso ``esp32-starter-kit-main\c\codes\2.7_rgb_strip``. Oppure copia questo codice nell'**Arduino IDE**.
    * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta appropriata, fai clic sul pulsante **Upload**.
    * La libreria ``Adafruit NeoPixel`` è utilizzata qui, puoi installarla dal **Library Manager**.

        .. image:: img/rgb_strip_lib.png

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/bccd25f6-4e3e-45e2-b9f5-76a1b0866794/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Quando il codice è stato caricato con successo, i LED sulla striscia si accenderanno sequenzialmente con un colore giallo e poi si spegneranno, creando un semplice effetto di inseguimento.


**Come funziona?**

#. Includi la libreria Adafruit NeoPixel: Questa riga importa la libreria Adafruit NeoPixel in modo che lo sketch possa utilizzare le sue funzioni e classi per controllare la striscia LED.

    .. code-block:: arduino

        #include <Adafruit_NeoPixel.h> // Includi la libreria Adafruit NeoPixel

#. Definisci le costanti per la striscia LED.

    .. code-block:: arduino

        #define LED_PIN 13 // Striscia LED NeoPixel
        #define NUM_LEDS 8 // Numero di LED

#. Crea un'istanza della classe Adafruit_NeoPixel.

    .. code-block:: arduino

       // Crea un'istanza della classe Adafruit_NeoPixel
        Adafruit_NeoPixel strip = Adafruit_NeoPixel(NUM_LEDS, LED_PIN, NEO_GRB + NEO_KHZ800);

    Questa riga crea un'istanza della classe ``Adafruit_NeoPixel`` chiamata ``strip`` e la configura con il numero di LED, il pin collegato alla striscia LED e i parametri del segnale (ordine dei colori GRB e velocità di trasmissione dati di 800 kHz).


    * ``Adafruit_NeoPixel (uint16_t n, int16_t p = 6, neoPixelType t = NEO_GRB + NEO_KHZ800)``	

    Costruttore NeoPixel quando lunghezza, pin e tipo di pixel sono noti in fase di compilazione. Restituisce un oggetto Adafruit_NeoPixel. Chiama la funzione ``begin()`` prima dell'uso.

        * ``n``: Numero di NeoPixel nella striscia.
        * ``p``: Numero del pin Arduino che gestirà i dati NeoPixel.
        * ``t``: Tipo di pixel - somma i costanti ``NEO_*`` definiti in ``Adafruit_NeoPixel.h``, ad esempio ``NEO_GRB+NEO_KHZ800`` per NeoPixel che si aspettano un flusso dati di 800 KHz (anziché 400 KHz) con i byte di colore espressi in ordine verde, rosso, blu per pixel.

#. Inizializza la striscia RGB WS2812 e imposta il colore iniziale della striscia su nero (spento).

    .. code-block:: arduino

        void setup() {
            strip.begin(); // Inizializza la striscia NeoPixel
            strip.show(); // Imposta il colore iniziale su nero
        }

    * ``void begin (void)``: Configura il pin NeoPixel per l'output.
    * ``void show (void)``: Trasmette i dati dei pixel in RAM ai NeoPixel.

#. Nella funzione ``loop()``, i LED sulla striscia si accenderanno sequenzialmente con un colore giallo e poi si spegneranno, creando un semplice effetto di inseguimento.

    .. code-block:: arduino

        void loop() {
        // Accendi i LED uno alla volta
        for (int i = 0; i < NUM_LEDS; i++) {
            strip.setPixelColor(i, 100, 45, 0); // Imposta il colore del i-esimo LED su giallo
            strip.show(); // Aggiorna la striscia LED con i nuovi colori
            delay(100); // Attendi 100 millisecondi
        }
        
        // Spegni i LED uno alla volta
        for (int i = 0; i < NUM_LEDS; i++) {
            strip.setPixelColor(i, 0, 0, 0); // Imposta il colore del i-esimo LED su nero (spento)
            strip.show(); // Aggiorna la striscia LED con i nuovi colori
            delay(100); // Attendi 100 millisecondi
        }
        }

    * ``void setPixelColor (uint16_t n, uint8_t r, uint8_t g, uint8_t b)``

    Imposta il colore di un pixel utilizzando componenti rosso, verde e blu separati. Se si utilizzano pixel RGBW, il bianco sarà impostato su 0.

        * ``n``: Indice del pixel, a partire da 0.
        * ``r``: Luminosità del rosso, 0 = minimo (spento), 255 = massimo.
        * ``g``: Luminosità del verde, 0 = minimo (spento), 255 = massimo.
        * ``b``: Luminosità del blu, 0 = minimo (spento), 255 = massimo.

