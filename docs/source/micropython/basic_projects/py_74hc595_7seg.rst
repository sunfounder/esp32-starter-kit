.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime speciali.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Omaggi Festivi**: Partecipa a omaggi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _py_7_segment:

2.5 Display Numerico
==========================

Benvenuto in questo affascinante progetto! In questo progetto, esploreremo il mondo incantevole della visualizzazione dei numeri da 0 a 9 su un display a sette segmenti.

Immagina di avviare questo progetto e vedere un piccolo e compatto display illuminarsi brillantemente con ogni numero da 0 a 9. È come avere un mini schermo che mostra le cifre in modo accattivante. Controllando i pin di segnale, puoi facilmente cambiare il numero visualizzato e creare vari effetti coinvolgenti.

Attraverso semplici collegamenti circuitali e programmazione, imparerai a interagire con il display a sette segmenti e a dare vita ai numeri desiderati. Che si tratti di un contatore, di un orologio o di qualsiasi altra applicazione intrigante, il display a sette segmenti sarà il tuo affidabile compagno, aggiungendo un tocco di brillantezza ai tuoi progetti.

**Componenti Necessari**

In questo progetto, abbiamo bisogno dei seguenti componenti.

È sicuramente conveniente acquistare un intero kit, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - ELEMENTI IN QUESTO KIT
        - LINK
    *   - Kit di Partenza ESP32
        - 320+
        - |link_esp32_starter_kit|

Puoi anche acquistarli separatamente dai link sottostanti.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUZIONE AI COMPONENTI
        - LINK DI ACQUISTO

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
    *   - :ref:`cpn_7_segment`
        - |link_7segment_buy|
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|

**Pin Disponibili**

Ecco un elenco di pin disponibili sulla scheda ESP32 per questo progetto.

.. list-table::
    :widths: 5 20 

    * - Pin Disponibili
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**Schema Elettrico**

.. image:: ../../img/circuit/circuit_2.5_74hc595_7_segment.png

Il principio di collegamento è sostanzialmente lo stesso di :ref:`py_74hc595`, l'unica differenza è che Q0-Q7 sono collegati ai pin a ~ g del display a 7 segmenti.

.. list-table:: Cablaggio
    :widths: 15 25
    :header-rows: 1

    *   - 74HC595
        - Display a Segmenti LED
    *   - Q0
        - a
    *   - Q1
        - b
    *   - Q2
        - c
    *   - Q3
        - d
    *   - Q4
        - e
    *   - Q5
        - f
    *   - Q6
        - g
    *   - Q7
        - dp

**Cablaggio**

.. image:: ../../img/wiring/2.5_segment_bb.png

**Codice**

.. note::

    * Apri il file ``2.5_number_display.py`` situato nel percorso ``esp32-starter-kit-main\micropython\codes``, oppure copia e incolla il codice in Thonny. Poi, clicca su "Esegui Script Corrente" o premi F5 per eseguirlo.
    * Assicurati di selezionare l'interprete "MicroPython (ESP32).COMxx" nell'angolo in basso a destra. 

.. code-block:: python

    import machine
    import time

    # Definire il codice segmento per un display a 7 segmenti con anodo comune
    SEGCODE = [0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f]

    # Inizializzare i pin per il registro a scorrimento 74HC595
    sdi = machine.Pin(25, machine.Pin.OUT)  # DS
    rclk = machine.Pin(27, machine.Pin.OUT)  # STcp
    srclk = machine.Pin(26, machine.Pin.OUT)  # SHcp

    # Definire la funzione hc595_shift per trasferire i dati nel registro a scorrimento 74HC595
    def hc595_shift(dat):
        # Impostare il pin RCLK su basso
        rclk.off()
        
        # Iterare attraverso ciascun bit (da 7 a 0)
        for bit in range(7, -1, -1):
            # Estrarre il bit corrente dai dati di input
            value = 1 & (dat >> bit)
            
            # Impostare il pin SRCLK su basso
            srclk.off()
            
            # Impostare il valore del pin SDI
            sdi.value(value)
            
            # Trasferire il bit corrente nel registro a scorrimento impostando il pin SRCLK su alto
            srclk.on()
            
        # Latchare i dati nel registro di memoria impostando il pin RCLK su alto
        rclk.on()

    # Ciclo continuo attraverso i numeri da 0 a 9 e visualizzarli sul display a 7 segmenti
    while True:
        for num in range(10):
            hc595_shift(SEGCODE[num])  # Trasferire il codice segmento per il numero corrente nel 74HC595
            time.sleep_ms(500)  # Attendere 500 millisecondi prima di visualizzare il numero successivo


    

Quando lo script è in esecuzione, vedrai il display a segmenti LED visualizzare i numeri da 0 a 9 in sequenza.

**Come funziona?**

In questo progetto, utilizziamo la funzione ``hc595_shift()`` per scrivere il numero binario nel registro a scorrimento.

Supponiamo che il display a 7 segmenti visualizzi il numero "2". Questo schema di bit corrisponde ai segmenti **f**, **c** e **dp** spenti (basso), mentre i segmenti **a**, **b**, **d**, **e** e **g** sono accesi (alto). Questo è "01011011" in binario e "0x5b" in notazione esadecimale.

Pertanto, dovresti chiamare **hc595_shift(0x5b)** per visualizzare il numero "2" sul display a 7 segmenti.

.. image:: img/7_segment2.png


* `Hexadecimal <https://en.wikipedia.org/wiki/Hexadecimal>`_

* `BinaryHex Converter <https://www.binaryhexconverter.com/binary-to-hex-converter>`_

La seguente tabella mostra gli schemi esadecimali che devono essere scritti nel registro a scorrimento per visualizzare i numeri da 0 a 9 su un display a 7 segmenti.

.. list-table:: Codice Glifo
    :widths: 20 20 20
    :header-rows: 1

    *   - Numeri	
        - Codice Binario
        - Codice Esadecimale  
    *   - 0	
        - 00111111	
        - 0x3f
    *   - 1	
        - 00000110	
        - 0x06
    *   - 2	
        - 01011011	
        - 0x5b
    *   - 3	
        - 01001111	
        - 0x4f
    *   - 4	
        - 01100110	
        - 0x66
    *   - 5	
        - 01101101	
        - 0x6d
    *   - 6	
        - 01111101	
        - 0x7d
    *   - 7	
        - 00000111	
        - 0x07
    *   - 8	
        - 01111111	
        - 0x7f
    *   - 9	
        - 01101111	
        - 0x6f

Scrivi questi codici in ``hc595_shift()`` per far visualizzare al display a segmenti LED i numeri corrispondenti.
