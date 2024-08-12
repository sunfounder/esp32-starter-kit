.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime speciali.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Omaggi Festivi**: Partecipa a omaggi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _py_dice:

6.6 Dado Digitale
================================

Questo progetto si basa sul progetto :ref:`py_7_segment`, aggiungendo un pulsante per controllare la cifra visualizzata sul display a sette segmenti.

Quando il pulsante viene premuto, il display a 7 segmenti scorre attraverso i numeri da 1 a 6 e, quando il pulsante viene rilasciato, visualizza un numero casuale.

Questo ciclo si ripete ogni volta che il pulsante viene premuto.

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
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|
    *   - :ref:`cpn_7_segment`
        - |link_7segment_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|

**Schema Elettrico**

.. image:: ../../img/circuit/circuit_6.6_electronic_dice.png

Questo progetto si basa sul progetto :ref:`py_7_segment`, aggiungendo un pulsante per controllare la cifra visualizzata sul display a sette segmenti.

Il pulsante è collegato direttamente a IO13 senza un resistore di pull-up o pull-down esterno perché IO13 ha un resistore di pull-up interno di 47K, eliminando la necessità di un resistore esterno aggiuntivo.


**Cablaggio**

.. image:: ../../img/wiring/6.6_DICE_bb.png

**Codice**

.. note::

    * Apri il file ``6.6_digital_dice.py`` situato nel percorso ``esp32-starter-kit-main\micropython\codes``, oppure copia e incolla il codice in Thonny. Poi, clicca su "Esegui Script Corrente" o premi F5 per eseguirlo.
    * Assicurati di selezionare l'interprete "MicroPython (ESP32).COMxx" nell'angolo in basso a destra. 

.. code-block:: python

    import machine
    import time
    import random

    # Definisci il codice del segmento per un display a 7 segmenti a anodo comune
    SEGCODE = [0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7d, 0x07, 0x7f, 0x6f]

    # Inizializza i pin per il registro a scorrimento 74HC595
    sdi = machine.Pin(25, machine.Pin.OUT)  # DS
    rclk = machine.Pin(27, machine.Pin.OUT)  # STcp
    srclk = machine.Pin(26, machine.Pin.OUT)  # SHcp

    button = machine.Pin(13, machine.Pin.IN) # Pin del pulsante

    # Definisci la funzione hc595_shift per trasferire i dati nel registro a scorrimento 74HC595
    def hc595_shift(dat):
        # Imposta il pin RCLK su basso
        rclk.off()
        
        # Itera attraverso ciascun bit (da 7 a 0)
        for bit in range(7, -1, -1):
            # Estrai il bit corrente dai dati di input
            value = 1 & (dat >> bit)
            
            # Imposta il pin SRCLK su basso
            srclk.off()
            
            # Imposta il valore del pin SDI
            sdi.value(value)
            
            # Trasferisci il bit corrente nel registro a scorrimento impostando il pin SRCLK su alto
            srclk.on()
            
        # Latch i dati nel registro di memoria impostando il pin RCLK su alto
        rclk.on()

    # Inizializza il seme casuale
    random.seed(time.ticks_us())


    num = 1
    button_state = False

    # Definisci la funzione di callback del pulsante per attivare/disattivare lo stato del pulsante
    def button_callback(pin):
        global button_state
        button_state = not button_state

    # Collega la funzione di callback del pulsante al bordo discendente del pin del pulsante
    button.irq(trigger=machine.Pin.IRQ_FALLING, handler=button_callback)

    # Visualizza continuamente la cifra corrente sul display a 7 segmenti, scorrendo se il pulsante non è premuto
    while True:
        
        # Visualizza la cifra corrente sul display a 7 segmenti
        hc595_shift(SEGCODE[num])
        
        # Se il pulsante è premuto e lo stato del pulsante è True
        if button_state:
            pass

        # Se il pulsante viene premuto di nuovo e lo stato del pulsante è False, genera una nuova cifra casuale
        if not button_state:
            num = random.randint(1, 6)
            time.sleep_ms(10) # Regola questo valore per controllare la frequenza di aggiornamento del display
        
Durante l'esecuzione del programma, premendo il pulsante, il display a 7 segmenti scorrerà e visualizzerà casualmente un numero compreso tra 1 e 6.

Premendo nuovamente il pulsante, il display a 7 segmenti si fermerà e mostrerà un numero specifico. Premi il pulsante un'altra volta e il display a 7 segmenti riprenderà a scorrere tra le cifre.

