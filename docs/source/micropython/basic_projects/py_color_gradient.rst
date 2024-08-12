.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime speciali.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Omaggi Festivi**: Partecipa a omaggi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _py_color_gradient:


6.5 Gradiente di Colore
===========================

Sei pronto a sperimentare un mondo di colori? Questo progetto ti porterà in 
un viaggio magico in cui potrai controllare una striscia LED e ottenere transizioni 
di colore fluide. Che tu voglia aggiungere un tocco di colore al tuo arredamento o 
stia cercando un progetto di programmazione divertente, questo progetto è quello che 
fa per te. Immergiamoci insieme in questo mondo colorato!

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
    *   - :ref:`cpn_pot`
        - |link_potentiometer_buy|
    *   - :ref:`cpn_ws2812`
        - |link_ws2812_buy|

**Schema Elettrico**

.. image:: ../../img/circuit/circuit_6.5_color_gradient.png

Questo progetto utilizza una striscia LED e un potenziometro per creare un effetto di miscelazione dei colori. Il potenziometro viene utilizzato per regolare il valore della tonalità dell'LED, che viene poi convertito in valori RGB utilizzando una funzione di conversione del colore. I valori RGB vengono quindi utilizzati per aggiornare il colore dell'LED.

**Cablaggio**

.. image:: ../../img/wiring/6.5_color_strip_bb.png
    :width: 800

**Codice**

.. note::

    * Apri il file ``6.5_color_gradient.py`` situato nel percorso ``esp32-starter-kit-main\micropython\codes``, oppure copia e incolla il codice in Thonny. Poi, clicca su "Esegui Script Corrente" o premi F5 per eseguirlo.
    * Assicurati di selezionare l'interprete "MicroPython (ESP32).COMxx" nell'angolo in basso a destra. 

.. code-block:: python
    
    from machine import Pin, ADC, PWM
    import neopixel
    import time

    NUM_LEDS = 8  # Numero di LED nella striscia
    PIN_NUM = 26  # Striscia LED
    POT_PIN = 14  # Potenziometro

    # Inizializza il potenziometro
    potentiometer = ADC(Pin(POT_PIN))
    potentiometer.atten(ADC.ATTN_11DB)

    # Inizializza la striscia LED NeoPixel
    np = neopixel.NeoPixel(Pin(PIN_NUM), NUM_LEDS)

    # Funzione per convertire lo spazio colore HSL in spazio colore RGB
    def hsl_to_rgb(h, s, l):
        # Funzione di supporto per convertire la tonalità in RGB
        def hue_to_rgb(p, q, t):
            if t < 0:
                t += 1
            if t > 1:
                t -= 1
            if t < 1/6:
                return p + (q - p) * 6 * t
            if t < 1/2:
                return q
            if t < 2/3:
                return p + (q - p) * (2/3 - t) * 6
            return p
        
        if s == 0:
            r = g = b = l
        else:
            q = l * (1 + s) if l < 0.5 else l + s - l * s
            p = 2 * l - q
            r = hue_to_rgb(p, q, h + 1/3)
            g = hue_to_rgb(p, q, h)
            b = hue_to_rgb(p, q, h - 1/3)
        
        return (int(r * 255), int(g * 255), int(b * 255))

    # Funzione per impostare il colore di tutti i LED nella striscia
    def set_color(np, color):
        for i in range(NUM_LEDS):
            np[i] = color
        np.write()

    # Ciclo principale
    while True:
        # Leggi il valore del potenziometro e normalizzalo nell'intervallo [0, 1]
        pot_value = potentiometer.read() / 4095.0
        hue = pot_value  # Imposta il valore della tonalità in base alla posizione del potenziometro
        saturation = 1  # Imposta la saturazione a 1 (completamente saturato)
        lightness = 0.5  # Imposta la luminosità a 0.5 (a metà tra nero e bianco)

        # Converti il colore HSL in RGB
        current_color = hsl_to_rgb(hue, saturation, lightness)
        
        # Imposta il colore della striscia LED in base al valore RGB convertito
        set_color(np, current_color)
        
        # Pausa per un breve periodo per consentire transizioni fluide
        time.sleep(0.1)

Mentre il codice è in esecuzione, ruota lentamente il potenziometro e vedrai il colore della striscia RGB sfumare dal rosso al viola.

