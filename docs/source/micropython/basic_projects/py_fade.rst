.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime speciali.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Omaggi Festivi**: Partecipa a omaggi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _py_fading:

2.2 LED con Effetto Fading
===================================

Nel progetto precedente, abbiamo controllato l'accensione e lo spegnimento del LED utilizzando l'uscita digitale. In questo progetto, creeremo un effetto di respirazione sul LED utilizzando la modulazione di larghezza di impulso (PWM). La PWM è una tecnica che ci permette di controllare la luminosità di un LED o la velocità di un motore variando il ciclo di lavoro di un segnale a onda quadra.

Con la PWM, invece di accendere o spegnere semplicemente il LED, regoleremo la quantità di tempo in cui il LED è acceso rispetto al tempo in cui è spento all'interno di ciascun ciclo. Commutando rapidamente il LED tra acceso e spento a intervalli variabili, possiamo creare l'illusione che il LED si illumini e si attenui gradualmente, simulando un effetto di respirazione.

Utilizzando le capacità PWM dell'ESP32 WROOM 32E, possiamo ottenere un controllo fluido e preciso sulla luminosità del LED. Questo effetto di respirazione aggiunge un elemento dinamico e visivamente accattivante ai tuoi progetti, creando un display o un'atmosfera coinvolgente.

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

**Pin Disponibili**

Ecco un elenco di pin disponibili sulla scheda ESP32 per questo progetto.

.. list-table::
    :widths: 5 20 

    * - Pin Disponibili
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**Schema Elettrico**

.. image:: ../../img/circuit/circuit_2.1_led.png

Questo progetto utilizza lo stesso circuito del primo progetto :ref:`py_blink`, ma il tipo di segnale è diverso. Nel primo progetto, il segnale digitale ad alta e bassa tensione (0&1) viene emesso direttamente dal pin 26 per accendere o spegnere il LED, mentre in questo progetto viene emesso un segnale PWM dal pin 26 per controllare la luminosità del LED.

**Cablaggio**

.. image:: ../../img/wiring/2.1_hello_led_bb.png

**Codice**

.. note::

    * Apri il file ``2.2_fading_led.py`` situato nel percorso ``esp32-starter-kit-main\micropython\codes``, oppure copia e incolla il codice in Thonny. Poi, clicca su "Esegui Script Corrente" o premi F5 per eseguirlo.
    * Assicurati di selezionare l'interprete "MicroPython (ESP32).COMxx" nell'angolo in basso a destra. 

.. code-block:: python

    # Importa le librerie necessarie
    from machine import Pin, PWM
    import time

    # Crea un oggetto PWM
    led = PWM(Pin(26), freq=1000)

    while True:
        # Aumenta gradualmente la luminosità
        for duty_cycle in range(0, 1024, 1):
            led.duty(duty_cycle)
            time.sleep(0.01)

        # Riduci gradualmente la luminosità
        for duty_cycle in range(1023, -1, -1):
            led.duty(duty_cycle)
            time.sleep(0.01)


Il LED si illuminerà gradualmente man mano che il codice viene eseguito.

**Come funziona?**

In generale, questo codice dimostra come utilizzare i segnali PWM per controllare la luminosità di un LED.


#. Importa due moduli, ``machine`` e ``time``. Il modulo ``machine`` fornisce l'accesso a basso livello all'hardware del microcontrollore, mentre il modulo ``time`` fornisce funzioni per le operazioni correlate al tempo.

    .. code-block:: python

        import machine
        import time

#. Quindi, inizializza un oggetto ``PWM`` per controllare il LED collegato al pin 26 e imposta la frequenza del segnale PWM a 1000 Hz.

    .. code-block:: python

        led = PWM(Pin(26), freq=1000)

#. Sfuma il LED dentro e fuori utilizzando un ciclo: il ciclo esterno ``while True`` viene eseguito indefinitamente. Due cicli ``for`` nidificati vengono utilizzati per aumentare e diminuire gradualmente la luminosità del LED. Il ciclo di lavoro varia da 0 a 1023, rappresentando un ciclo di lavoro dal 0% al 100%.

    .. code-block:: python

        # Importa le librerie necessarie
        from machine import Pin, PWM
        import time

        # Crea un oggetto PWM
        led = PWM(Pin(26), freq=1000)

        while True:
            # Aumenta gradualmente la luminosità
            for duty_cycle in range(0, 1024, 2):
                led.duty(duty_cycle)
                time.sleep(0.01)

            # Riduci gradualmente la luminosità
            for duty_cycle in range(1023, -1, -2):
                led.duty(duty_cycle)
                time.sleep(0.01)


    * ``range()``: Crea una sequenza di numeri interi da 0 a 1023. 
    * Il ciclo di lavoro del segnale PWM è impostato su ciascun valore nella sequenza utilizzando il metodo ``duty()`` dell'oggetto ``PWM``. 
    * ``time.sleep()``: Interrompe l'esecuzione del programma per 10 millisecondi tra ogni iterazione del ciclo, creando un aumento graduale della luminosità nel tempo.

    
