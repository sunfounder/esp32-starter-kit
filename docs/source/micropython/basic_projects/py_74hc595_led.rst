.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime speciali.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Omaggi Festivi**: Partecipa a omaggi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _py_74hc595:

2.4 Microchip - 74HC595
===========================

Benvenuto in questo emozionante progetto! In questo progetto, utilizzeremo il chip 74HC595 per controllare un display fluente di 8 LED.

Immagina di avviare questo progetto e assistere a un flusso di luce ipnotico, come se un arcobaleno scintillante saltasse tra gli 8 LED. Ogni LED si accenderà uno dopo l'altro e si spegnerà rapidamente, mentre il LED successivo continua a brillare, creando un effetto splendido e dinamico.

Sfruttando abilmente il chip 74HC595, possiamo controllare gli stati di accensione e spegnimento di più LED per ottenere l'effetto di flusso. Questo chip ha più pin di uscita che possono essere collegati in serie per controllare la sequenza di illuminazione dei LED. Inoltre, grazie all'espandibilità del chip, possiamo facilmente aggiungere altri LED al display fluente, creando effetti ancora più spettacolari.

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
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|

**Pin Disponibili**

Ecco un elenco di pin disponibili sulla scheda ESP32 per questo progetto.

.. list-table::
    :widths: 5 20 

    * - Pin Disponibili
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**Schema Elettrico**

.. image:: ../../img/circuit/circuit_2.4_74hc595_led.png
    :width: 600

* Quando MR (pin10) è alto e CE (pin13) è basso, i dati vengono immessi nel fronte di salita di SHcp e vanno al registro di memoria attraverso il fronte di salita di SHcp.
* Se i due clock sono collegati insieme, il registro a scorrimento è sempre un impulso in anticipo rispetto al registro di memoria.
* Nel registro di memoria è presente un pin di ingresso seriale (DS), un pin di uscita seriale (Q7') e un pulsante di reset asincrono (basso livello).
* Il registro di memoria emette un bus parallelo a 8 bit in tre stati.
* Quando OE è abilitato (basso livello), i dati nel registro di memoria vengono emessi sul bus (Q0 ~ Q7).

**Cablaggio**

.. image:: ../../img/wiring/2.4_74hc595_bb.png
    :width: 800

**Codice**

.. note::

    * Apri il file ``2.4_microchip_74hc595.py`` situato nel percorso ``esp32-starter-kit-main\micropython\codes``, oppure copia e incolla il codice in Thonny. Poi, clicca su "Esegui Script Corrente" o premi F5 per eseguirlo.
    * Assicurati di selezionare l'interprete "MicroPython (ESP32).COMxx" nell'angolo in basso a destra. 



.. code-block:: python

    import machine
    import time

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

    num = 0

    # Trasferire i dati nel 74HC595 per creare un pattern LED in movimento
    for i in range(16):
        if i < 8:
            num = (num << 1) + 1  # Shift a sinistra e imposta il bit meno significativo su 1
        elif i >= 8:
            num = (num & 0b01111111) << 1  # Maschera il bit più significativo e shift a sinistra
        hc595_shift(num)  # Trasferire il valore corrente nel 74HC595
        print("{:0>8b}".format(num))  # Stampa il valore corrente in formato binario
        time.sleep_ms(200)  # Attendere 200 millisecondi prima di trasferire il valore successivo



Durante l'esecuzione dello script, vedrai che i LED si accendono uno ad uno e poi si spengono nell'ordine originale.

**Come funziona?**

Questo codice viene utilizzato per controllare un registro a scorrimento a 8 bit (74595), e inviare diversi valori binari al registro a scorrimento, con ciascun valore visualizzato su un LED per un certo periodo di tempo.

#. Il codice importa i moduli ``machine`` e ``time``, dove il modulo ``machine`` viene utilizzato per controllare l'I/O hardware, e il modulo ``time`` viene utilizzato per implementare ritardi temporali e altre funzioni.

    .. code-block:: python

        import machine
        import time

#. Vengono inizializzate tre porte di uscita utilizzando la funzione ``machine.Pin()``, corrispondenti alla porta dati (SDI), alla porta di clock di memorizzazione (RCLK) e alla porta di clock del registro a scorrimento (SRCLK) del registro a scorrimento.

    .. code-block:: python

        # Inizializzare i pin per il registro a scorrimento 74HC595
        sdi = machine.Pin(25, machine.Pin.OUT)  # DS
        rclk = machine.Pin(27, machine.Pin.OUT)  # STcp
        srclk = machine.Pin(26, machine.Pin.OUT)  # SHcp

#. Viene definita una funzione chiamata ``hc595_shift()`` per scrivere un dato a 8 bit nel registro a scorrimento.

    .. code-block:: python

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

#. Riguardo al ciclo ``for``.

    .. code-block:: python

        for i in range(16):
                if i < 8:
                    num = (num << 1) + 1  # Shift a sinistra e imposta il bit meno significativo su 1
                elif i >= 8:
                    num = (num & 0b01111111) << 1  # Maschera il bit più significativo e shift a sinistra
                hc595_shift(num)  # Trasferire il valore corrente nel 74HC595
                print("{:0>8b}".format(num))  # Stampa il valore corrente in formato binario
                time.sleep_ms(200)  # Attendere 200 millisecondi prima di trasferire il valore successivo

    * La variabile ``i`` viene utilizzata per controllare il valore binario in uscita. Nelle prime 8 iterazioni, il valore di num sarà successivamente 00000001, 00000011, 00000111, ..., 11111111, che viene shiftato a sinistra di un bit e poi incrementato di 1.
    * Nelle iterazioni dalla 9ª alla 16ª, il bit più alto di 1 viene prima cambiato a 0, e poi shiftato a sinistra di un bit, ottenendo i valori in uscita di 00000010, 00000100, 00001000, ..., 10000000.
    * In ogni iterazione, il valore di ``num`` viene passato alla funzione ``hc595_shift()`` per controllare il registro a scorrimento e emettere il valore binario corrispondente.
    * Contemporaneamente all'emissione del valore binario, la funzione ``print()`` stampa il valore binario come stringa nel terminale.
    * Dopo aver emesso il valore binario, il programma si interrompe per 200 millisecondi utilizzando la funzione ``time.sleep_ms()``, in modo che il valore sul LED rimanga visualizzato per un certo periodo di tempo.
