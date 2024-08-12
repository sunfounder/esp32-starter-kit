.. note::

    Ciao, benvenuto nella community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché Unirsi?**

    - **Supporto Esperti**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara & Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa ai giveaway e alle promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _py_rgb_strip:

2.7 Striscia LED RGB
========================

In questo progetto, esploreremo il mondo affascinante del controllo delle strisce LED WS2812, portando in vita una vivace esposizione di colori. Con la possibilità di controllare individualmente ogni LED della striscia, possiamo creare effetti di illuminazione avvincenti che catturano i sensi.

Inoltre, abbiamo incluso un'emozionante estensione di questo progetto, in cui esploreremo il mondo della casualità. Introducendo colori casuali e implementando un effetto di luce fluente, possiamo creare un'esperienza visiva ipnotica che cattura e incanta.

**Componenti Necessari**

In questo progetto, abbiamo bisogno dei seguenti componenti.

È sicuramente conveniente acquistare un kit completo, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - OGGETTI IN QUESTO KIT
        - LINK
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

Puoi anche acquistarli separatamente dai link qui sotto.

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

    La striscia LED WS2812 è un tipo di striscia LED che richiede un segnale di modulazione della larghezza di impulso (PWM) preciso. Il segnale PWM ha requisiti precisi sia in termini di tempo che di tensione. Ad esempio, un bit "0" per il WS2812 corrisponde a un impulso di livello alto di circa 0,4 microsecondi, mentre un bit "1" corrisponde a un impulso di livello alto di circa 0,8 microsecondi. Ciò significa che la striscia deve ricevere variazioni di tensione ad alta frequenza.

    Tuttavia, con una resistenza pull-up da 4,7K e un condensatore pull-down da 100nf su IO33, si crea un semplice filtro passa-basso. Questo tipo di circuito "leviga" i segnali ad alta frequenza, perché il condensatore ha bisogno di un po' di tempo per caricarsi e scaricarsi quando riceve variazioni di tensione. Pertanto, se il segnale cambia troppo velocemente (cioè è ad alta frequenza), il condensatore non sarà in grado di tenere il passo. Questo si traduce in un segnale di uscita sfocato e non riconoscibile dalla striscia.

**Cablatura**

.. image:: ../../img/wiring/2.7_rgb_strip_bb.png
    :width: 800

**Codice**

.. note::

    * Apri il file ``2.7_rgb_strip.py`` situato nel percorso ``esp32-starter-kit-main\micropython\codes``, oppure copia e incolla il codice in Thonny. Successivamente, fai clic su "Esegui lo script corrente" o premi F5 per eseguirlo.
    * Assicurati di selezionare l'interprete "MicroPython (ESP32).COMxx" nell'angolo in basso a destra. 

    
.. code-block:: python

    from machine import Pin
    from neopixel import NeoPixel

    pin = Pin(14, Pin.OUT)   # imposta un pin in output per pilotare NeoPixels
    pixels = NeoPixel(pin, 8)   # crea il driver NeoPixel su un pin per 8 pixel

    pixels[0] = [64,154,227]    # imposta il pixel 
    pixels[1] = [128,0,128]
    pixels[2] = [50,150,50]
    pixels[3] = [255,30,30]
    pixels[4] = [0,128,255]
    pixels[5] = [99,199,0]
    pixels[6] = [128,128,128]
    pixels[7] = [255,100,0]

    pixels.write()              # scrivi i dati su tutti i pixel


Scegliamo alcuni colori preferiti e visualizziamoli sulla striscia LED RGB!

**Come Funziona?**

#. Nel modulo ``neopixel``, abbiamo integrato le funzioni correlate nella classe ``NeoPixel``.

    .. code-block:: python

        from neopixel import NeoPixel

#. Usa la classe ``NeoPixel`` dal modulo ``neopixel`` per inizializzare l'oggetto ``pixels``, specificando il pin dei dati e il numero di LED.

    .. code-block:: python

        pixels = NeoPixel(pin, 8)   # crea il driver NeoPixel su un pin per 8 pixel

#. Imposta il colore di ciascun LED e usa il metodo ``write()`` per inviare i dati al LED WS2812 per aggiornare la visualizzazione.

    .. code-block:: python

        pixels[0] = [64,154,227]    # imposta il pixel 
        pixels[1] = [128,0,128]
        pixels[2] = [50,150,50]
        pixels[3] = [255,30,30]
        pixels[4] = [0,128,255]
        pixels[5] = [99,199,0]
        pixels[6] = [128,128,128]
        pixels[7] = [255,100,0]

        pixels.write()              # scrivi i dati su tutti i pixel

**Per Saperne di Più**

Possiamo generare colori casuali e creare una luce fluente colorata.

.. note::

    * Apri il file ``2.7_rgb_strip_random.py`` situato nel percorso ``esp32-starter-kit-main\micropython\codes``, oppure copia e incolla il codice in Thonny. Successivamente, fai clic su "Esegui lo script corrente" o premi F5 per eseguirlo.
    * Assicurati di selezionare l'interprete "MicroPython (ESP32).COMxx" nell'angolo in basso a destra. 


.. code-block:: python

    from machine import Pin
    import neopixel
    import time
    import random

    # Imposta il numero di pixel per la luce fluente
    num_pixels = 8

    # Imposta il pin dei dati per la striscia LED RGB
    data_pin = Pin(14, Pin.OUT)

    # Inizializza l'oggetto striscia LED RGB
    pixels = neopixel.NeoPixel(data_pin, num_pixels)

    # Ciclo continuo della luce fluente
    while True:
        for i in range(num_pixels):
            # Genera un colore casuale per il pixel corrente
            color = (random.randint(0, 255), random.randint(0, 255), random.randint(0, 255))
            
            # Accendi il pixel corrente con il colore casuale
            pixels[i] = color
            
            # Aggiorna la visualizzazione della striscia LED RGB
            pixels.write()
            
            # Spegni il pixel corrente
            pixels[i] = (0, 0, 0)
            
            # Attendi un periodo di tempo per controllare la velocità della luce fluente
            time.sleep_ms(100)


* Nel ciclo ``while``, utilizziamo un ciclo ``for`` per accendere ogni pixel della striscia LED RGB uno per uno. 
* Prima utilizziamo la funzione ``random.randint()`` per generare un colore casuale per il pixel corrente.
* Successivamente, accendiamo il pixel corrente con il colore casuale, utilizziamo il metodo ``write()`` dell'oggetto ``NeoPixel`` per inviare i dati del colore alla striscia LED RGB per aggiornare la visualizzazione.
* Infine, spegniamo il pixel corrente impostando il suo colore a (0, 0, 0) e attendiamo un periodo di tempo per controllare la velocità della luce fluente.

