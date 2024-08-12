.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e alle anteprime.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_lcd1602:

2.6 Visualizzazione dei Caratteri
=========================================

Ora esploreremo il mondo affascinante della visualizzazione dei caratteri utilizzando il modulo I2C LCD1602.

Attraverso questo progetto, impareremo come inizializzare il modulo LCD, impostare i parametri di visualizzazione desiderati e inviare dati di caratteri da visualizzare sullo schermo. Potremo mostrare messaggi personalizzati, visualizzare le letture dei sensori o creare menu interattivi. Le possibilità sono infinite!

Padroneggiando l'arte della visualizzazione dei caratteri sul I2C LCD1602, apriremo nuove strade per la comunicazione e la visualizzazione delle informazioni nei nostri progetti. Iniziamo questo emozionante viaggio e diamo vita ai nostri caratteri sullo schermo LCD.

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
    *   - :ref:`cpn_lcd`
        - |link_i2clcd1602_buy|


**Pin Disponibili**

Ecco un elenco di pin disponibili sulla scheda ESP32 per questo progetto.

.. list-table::
    :widths: 5 15
    :header-rows: 1

    *   - Pin Disponibili
        - Descrizione dell'Uso

    *   - IO21
        - SDA
    *   - IO22
        - SCL
    
**Schema Elettrico**

.. image:: ../../img/circuit/circuit_2.6_lcd.png

**Cablaggio**

.. image:: ../../img/wiring/2.6_i2clcd1602_bb.png
    :width: 800

**Codice**

.. note::

    * Apri il file ``2.6_lcd1602.ino`` nel percorso ``esp32-starter-kit-main\c\codes\2.6_lcd1602``.
    * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta appropriata, fai clic sul pulsante **Upload**.
    * :ref:`unknown_com_port`
    * La libreria ``LiquidCrystal I2C`` viene utilizzata qui, puoi installarla dal **Library Manager**.

        .. image:: img/lcd_lib.png

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/31e33e53-67b2-4e29-b78b-f647fd45fb0b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Quando questo programma viene caricato, l'I2C LCD1602 visualizzerà il messaggio di benvenuto, "Hello, Sunfounder!", per 3 secondi. Dopodiché, lo schermo mostrerà un'etichetta "COUNT:" e il valore del conteggio, che si incrementa ogni secondo.


.. note:: 

    Se il codice e il cablaggio sono corretti, ma l'LCD non riesce a visualizzare alcun contenuto, puoi regolare il potenziometro sul retro per aumentare il contrasto.

**Come funziona?**

Richiamando la libreria ``LiquidCrystal_I2C.h``, puoi facilmente pilotare l'LCD. 

.. code-block:: arduino

    #include <LiquidCrystal_I2C.h>

Funzioni della Libreria：


* Crea una nuova istanza della classe ``LiquidCrystal_I2C`` che rappresenta un particolare LCD collegato alla tua scheda Arduino.

    .. code-block:: arduino

        LiquidCrystal_I2C(uint8_t lcd_Addr,uint8_t lcd_cols,uint8_t lcd_rows)

    * ``lcd_AddR``: L'indirizzo dell'LCD è di default 0x27.
    * ``lcd_cols``: L'LCD1602 ha 16 colonne.
    * ``lcd_rows``: L'LCD1602 ha 2 righe.

* Inizializza l'LCD.

    .. code-block:: arduino

        void init()

* Accende la retroilluminazione (opzionale).

    .. code-block:: arduino

        void backlight()

* Spegne la retroilluminazione (opzionale).

    .. code-block:: arduino

        void nobacklight()

* Accende rapidamente il display LCD.

    .. code-block:: arduino

        void display()

* Spegne rapidamente il display LCD.

    .. code-block:: arduino

        void nodisplay()

* Cancella il display, imposta la posizione del cursore su zero.

    .. code-block:: arduino

        void clear()

* Imposta la posizione del cursore su colonna, riga.

    .. code-block:: arduino

        void setCursor(uint8_t col,uint8_t row)

* Stampa il testo sull'LCD.

    .. code-block:: arduino

        void print(data,BASE)

    * ``data``: I dati da stampare (char, byte, int, long, o stringa).
    * ``BASE (optional)``: La base in cui stampare i numeri.

        * ``BIN`` per binario (base 2)
        * ``DEC`` per decimale (base 10)
        * ``OCT`` per ottale (base 8)
        * ``HEX`` per esadecimale (base 16).
