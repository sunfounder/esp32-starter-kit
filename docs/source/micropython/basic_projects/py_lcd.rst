.. note::

    Ciao, benvenuto nella comunità SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni per le festività.

    👉 Pronto per esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _py_lcd1602:

2.6 Visualizzare Caratteri
==================================================

Ora esploreremo il mondo affascinante della visualizzazione dei caratteri utilizzando il modulo LCD1602 con interfaccia I2C.

In questo progetto impareremo come inizializzare il modulo LCD, impostare i parametri di visualizzazione desiderati e inviare i dati dei caratteri da visualizzare sullo schermo. Possiamo mostrare messaggi personalizzati, visualizzare letture di sensori o creare menu interattivi. Le possibilità sono infinite!

Padroneggiando l'arte della visualizzazione dei caratteri sull'I2C LCD1602, sbloccheremo nuove vie per la comunicazione e la visualizzazione delle informazioni nei nostri progetti. Immergiamoci in questo emozionante viaggio e diamo vita ai nostri caratteri sullo schermo LCD!

**Componenti richiesti**

In questo progetto, abbiamo bisogno dei seguenti componenti.

È sicuramente conveniente acquistare un kit completo, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - COMPONENTI IN QUESTO KIT
        - LINK
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

Puoi anche acquistarli separatamente dai link qui sotto.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUZIONE COMPONENTE
        - LINK PER L'ACQUISTO

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - |link_esp32_extension_board|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_lcd`
        - |link_i2clcd1602_buy|

**Pin disponibili**

Ecco un elenco di pin disponibili sulla scheda ESP32 per questo progetto.

.. list-table::
    :widths: 5 15
    :header-rows: 1

    *   - Pin Disponibili
        - Descrizione Uso

    *   - IO21
        - SDA
    *   - IO22
        - SCL
    
**Schema**

.. image:: ../../img/circuit/circuit_2.6_lcd.png

**Collegamenti**

.. image:: ../../img/wiring/2.6_i2clcd1602_bb.png
    :width: 800

**Codice**

.. note::

    * Apri il file ``2.6_liquid_crystal_display.py`` situato nel percorso ``esp32-starter-kit-main\micropython\codes``, oppure copia e incolla il codice in Thonny. Quindi, fai clic su "Esegui script corrente" o premi F5 per eseguirlo.
    * Assicurati di selezionare l'interprete "MicroPython (ESP32).COMxx" nell'angolo in basso a destra. 
    * Qui viene utilizzata la libreria ``lcd1602.py``, verifica che sia stata caricata sull'ESP32. Per un tutorial completo, fai riferimento a :ref:`add_libraries_py`.

.. code-block:: python

    # Importa la classe LCD dal modulo lcd1602
    from lcd1602 import LCD

    import time

    # Crea un'istanza della classe LCD e assegnala alla variabile lcd
    lcd = LCD()
    # Imposta la stringa " Hello!\n"
    string = " Hello!\n"
    # Visualizza la stringa sullo schermo LCD
    lcd.message(string)

    time.sleep(2)
    # Imposta la stringa "    Sunfounder!"
    string = "    Sunfounder!"
    # Visualizza la stringa sullo schermo LCD
    lcd.message(string)

    time.sleep(2)
    # Cancella lo schermo LCD
    lcd.clear()

Dopo l'esecuzione dello script, vedrai apparire due righe di testo sullo schermo LCD a turno e poi scomparire.

.. note:: 

    Se il codice e i collegamenti sono corretti ma l'LCD non riesce ancora a visualizzare alcun contenuto, puoi regolare il potenziometro sul retro per aumentare il contrasto.

**Come funziona?**

Nella libreria ``lcd1602``, integriamo le funzioni rilevanti del display lcd1602 nella classe LCD.

#. Importa il modulo ``lcd1602``.

    .. code-block:: python

        from lcd1602 import LCD    

#. Dichiara un oggetto della classe ``LCD`` e chiamalo ``lcd``.

    .. code-block:: python

        lcd = LCD()

#. Questa istruzione visualizzerà il testo sul display LCD. È importante notare che l'argomento deve essere di tipo stringa. Se desideriamo passare un intero o un float, dobbiamo usare l'istruzione di conversione forzata ``str()``.

    .. code-block:: python

        lcd.message(string)


#. Se chiami questa istruzione più volte, lcd sovrapporrà i testi. Questo richiede l'uso dell'istruzione seguente per cancellare il display.

    .. code-block:: python

        lcd.clear()
