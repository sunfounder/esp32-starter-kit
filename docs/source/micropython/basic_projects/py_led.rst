.. note::

    Ciao, benvenuto nella comunità SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni per le festività.

    👉 Pronto per esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _py_blink:

2.1 Ciao, LED! 
=======================================

Così come stampare "Ciao, mondo!" è il primo passo per imparare a programmare, usare un programma per accendere un LED è l'introduzione tradizionale alla programmazione fisica.

**Componenti necessari**

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

**Pin disponibili**

Ecco un elenco di pin disponibili sulla scheda ESP32 per questo progetto.

.. list-table::
    :widths: 5 20 

    * - Pin Disponibili
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**Schema**

.. image:: ../../img/circuit/circuit_2.1_led.png

Questo circuito funziona su un principio semplice, e la direzione della corrente è mostrata nella figura. Il LED si accenderà dopo il resistore limitatore di corrente da 220ohm quando il pin26 emetterà un livello alto. Il LED si spegnerà quando il pin26 emetterà un livello basso.

**Collegamenti**

.. image:: ../../img/wiring/2.1_hello_led_bb.png

**Esegui il codice**

#. Apri il file ``2.1_hello_led.py`` situato nel percorso ``esp32-starter-kit-main\micropython\codes``, oppure copia e incolla il codice in Thonny. 

    .. code-block:: python

        # Importa le librerie necessarie
        import machine
        import time

        # Configura il LED sul pin 26 come pin di uscita
        led = machine.Pin(26, machine.Pin.OUT)

        # Avvia un ciclo infinito
        while True:
            # Accendi il LED impostando il suo valore a 1 (HIGH)
            led.value(1)
            # Attendi 1 secondo (1000 millisecondi) mentre il LED è acceso
            time.sleep(1)

            # Spegni il LED impostando il suo valore a 0 (LOW)
            led.value(0)
            # Attendi 0,5 secondi (500 millisecondi) mentre il LED è spento
            time.sleep(0.5)

#. Collega l'ESP32 WROOM 32E al tuo computer utilizzando un cavo Micro USB.

    .. image:: ../../img/plugin_esp32.png
        :width: 600
        :align: center

#. Quindi, fai clic sull'interprete "MicroPython (ESP32).COMXX" nell'angolo in basso a destra.

    .. image:: ../python_start/img/sec_inter.png

#. Infine, fai clic su "Esegui script corrente" o premi F5 per eseguirlo.

    .. image:: ../python_start/img/quick_guide2.png

#. Dopo l'esecuzione del codice, vedrai il LED lampeggiare.


**Come funziona?**

#. Importa due moduli, ``machine`` e ``time``. Il modulo ``machine`` fornisce l'accesso a basso livello all'hardware del microcontrollore, mentre il modulo ``time`` fornisce funzioni per le operazioni relative al tempo.

    .. code-block:: python

        import machine
        import time

#. Configura il pin26 come pin di uscita utilizzando la funzione ``machine.Pin()`` con l'argomento ``machine.Pin.OUT``.

    .. code-block:: python

        led = machine.Pin(26, machine.Pin.OUT)

#. Nel ciclo ``While True``, il LED viene acceso per un secondo impostando il valore del pin26 a 1 utilizzando ``led.value(1)`` e poi impostato a 0 (``led.value(0)``) per spegnerlo per un secondo, e così via in un ciclo infinito.

    .. code-block:: python
        
        while True:
            # Accendi il LED impostando il suo valore a 1 (HIGH)
            led.value(1)
            # Attendi 1 secondo (1000 millisecondi) mentre il LED è acceso
            time.sleep(1)

            # Spegni il LED impostando il suo valore a 0 (LOW)
            led.value(0)
            # Attendi 0,5 secondi (500 millisecondi) mentre il LED è spento
            time.sleep(0.5)

**Per saperne di più**

In questo progetto, abbiamo utilizzato i moduli ``machine`` e ``time`` di MicroPython, possiamo trovare altri modi per usarli qui.

* `machine.Pin <https://docs.micropython.org/en/latest/library/machine.Pin.html>`_

* `time <https://docs.micropython.org/en/latest/library/time.html>`_



