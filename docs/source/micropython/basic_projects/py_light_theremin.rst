.. note::

    Ciao, benvenuto nella community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e alle anteprime.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Sei pronto per esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _py_light_theremin:

6.3 Theremin di Luce
=========================

Il Theremin è uno strumento musicale elettronico che non richiede contatto fisico. In base alla posizione della mano del musicista, produce toni diversi.

La sua sezione di controllo è solitamente composta da due antenne metalliche che rilevano la posizione delle mani del thereminista e controllano gli oscillatori con una mano e il volume con l'altra. I segnali elettrici del Theremin vengono amplificati e inviati a un altoparlante.

Non possiamo riprodurre lo stesso strumento con ESP32, ma possiamo usare un fotoresistore e un buzzer passivo per ottenere un gameplay simile.

* `Theremin - Wikipedia <https://en.wikipedia.org/wiki/Theremin>`_

**Componenti Necessari**

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|

**Schema**

.. image:: ../../img/circuit/circuit_6.3_light_theremin.png

Prima di iniziare il progetto, calibra il range di intensità della luce muovendo la mano sopra il fotoresistore. Il LED collegato a IO26 viene utilizzato come indicatore durante il processo di calibrazione. Quando il LED si accende, significa che la calibrazione è iniziata, e quando si spegne, indica la fine della calibrazione.

Mentre muovi la mano sopra il fotoresistore, il valore del fotoresistore cambierà di conseguenza. 
Utilizza questo cambiamento per controllare il buzzer e suonare diverse note musicali. 
Ogni variazione del valore del fotoresistore può essere mappata su una specifica nota musicale, permettendo 
al buzzer di produrre una melodia mentre muovi la mano sopra il fotoresistore.

**Collegamenti**

.. image:: ../../img/wiring/6.3_theremin_bb.png

**Codice**

.. note::

    * Apri il file ``6.3_light_theremin.py`` situato nel percorso ``esp32-starter-kit-main\micropython\codes``, oppure copia e incolla il codice in Thonny. Poi clicca su "Run Current Script" o premi F5 per eseguirlo.
    * Assicurati di selezionare l'interprete "MicroPython (ESP32).COMxx" nell'angolo in basso a destra. 

.. code-block:: python

    from machine import Pin, PWM, ADC
    import time

    # Inizializza il pin del LED
    led = Pin(26, Pin.OUT)

    # Inizializza il sensore di luce
    sensore = ADC(Pin(35))
    sensore.atten(ADC.ATTN_11DB)

    # Inizializza il buzzer
    buzzer = PWM(Pin(13), freq=440, duty=0)

    luce_bassa = 4095
    luce_alta = 0

    # Mappa l'intervallo dei valori di input sui valori di output
    def mappatura_intervallo(x, in_min, in_max, out_min, out_max):
        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

    # Create a tone using the specified pin, frequency, and duration
    def tone(pin,frequency,duration):
        pin.freq(frequency)
        pin.duty(512)
        time.sleep_ms(duration)
        pin.duty(0)

    # Calibrate the photoresistor's maximum and minimum values in 5 seconds.
    timer_init_start = time.ticks_ms()
    led.value(1) # turn on the LED   
    while time.ticks_diff(time.ticks_ms(), timer_init_start)<5000:
        light_value = sensor.read()
        if light_value > light_high:
            light_high = light_value
        if light_value < light_low:
            light_low = light_value   
    led.value(0) # turn off the LED 

    # Suona i toni in base ai valori della luce
    while True:
        light_value  = sensor.read()
        pitch = int(interval_mapping(light_value,light_low,light_high,50,6000))
        if pitch > 50 :
            tone(buzzer,pitch,20)
        time.sleep_ms(10)

All'avvio del programma, il LED si accende, fornendo una finestra di cinque secondi per calibrare il range di rilevamento del fotoresistore.

La calibrazione è un passaggio cruciale perché tiene conto delle diverse condizioni di illuminazione che potremmo incontrare durante l'uso del dispositivo, 
come le varie intensità luminose durante i diversi momenti della giornata. 
Inoltre, il processo di calibrazione tiene conto della distanza tra le nostre mani 
e il fotoresistore, che determina il range suonabile dello strumento.

Una volta terminato il periodo di calibrazione, il LED si spegne, indicando che possiamo ora suonare lo strumento muovendo le mani sopra il fotoresistore. 
Questa configurazione ci permette di creare musica regolando l'altezza delle nostre mani, offrendo un'esperienza interattiva e piacevole.
