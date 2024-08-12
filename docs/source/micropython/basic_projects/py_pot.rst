.. note::

    Ciao, benvenuto nella community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché Unirsi?**

    - **Supporto Esperti**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara & Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa ai giveaway e alle promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _py_potentiometer:

5.8 Ruota la Manopola
===========================

Un potenziometro è un dispositivo a tre terminali comunemente utilizzato per regolare la resistenza in un circuito. Dispone di una manopola o di una leva scorrevole che può essere utilizzata per variare il valore di resistenza del potenziometro. In questo progetto, lo utilizzeremo per controllare la luminosità di un LED, simile a una lampada da scrivania nella nostra vita quotidiana. Regolando la posizione del potenziometro, possiamo modificare la resistenza nel circuito, regolando così la corrente che attraversa il LED e di conseguenza la sua luminosità. Questo ci consente di creare un'esperienza di illuminazione personalizzabile e regolabile, simile a quella di una lampada da scrivania.

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_pot`
        - |link_potentiometer_buy|

**Pin Disponibili**

* **Pin Disponibili**

    Ecco un elenco dei pin disponibili sulla scheda ESP32 per questo progetto.

    .. list-table::
        :widths: 5 15

        *   - Pin Disponibili
            - IO14, IO25, I35, I34, I39, I36

* **Pin di Strapping**

    I seguenti pin sono pin di strapping, che influenzano il processo di avvio dell'ESP32 durante l'accensione o il reset. Tuttavia, una volta che l'ESP32 è stato avviato correttamente, possono essere utilizzati come pin normali.

    .. list-table::
        :widths: 5 15

        *   - Pin di Strapping
            - IO0, IO12


**Schema**

.. image:: ../../img/circuit/circuit_5.8_potentiometer.png

Quando ruoti il potenziometro, il valore di I35 cambierà. Attraverso la programmazione, puoi utilizzare il valore di I35 per controllare la luminosità del LED. Pertanto, man mano che ruoti il potenziometro, anche la luminosità del LED cambierà di conseguenza.


**Cablatura**

.. image:: ../../img/wiring/5.8_potentiometer_bb.png

**Codice**

.. note::

    * Apri il file ``5.8_turn_the_knob.py`` situato nel percorso ``esp32-starter-kit-main\micropython\codes``, oppure copia e incolla il codice in Thonny. Successivamente, fai clic su "Esegui lo script corrente" o premi F5 per eseguirlo.
    * Assicurati di selezionare l'interprete "MicroPython (ESP32).COMxx" nell'angolo in basso a destra. 


.. code-block:: python

    from machine import ADC, Pin, PWM
    import time

    pot = ADC(Pin(35, Pin.IN)) # crea un oggetto ADC che agisce su un pin      

    # Configura l'attenuazione ADC a 11dB per l'intera gamma
    pot.atten(pot.ATTN_11DB)

    # Crea un oggetto PWM
    led = PWM(Pin(26), freq=1000)

    while True:
        # Leggi un valore analogico grezzo nell'intervallo 0-4095
        value = pot.read()

        # Scala il valore nell'intervallo 0-1023 per il ciclo di lavoro PWM dell'ESP32
        pwm_value = int(value * 1023 / 4095)

        # Aggiorna la luminosità del LED in base al valore del potenziometro
        led.duty(pwm_value)

        # Leggi la tensione in microvolt e converti in volt
        voltage = pot.read_uv() / 1000000

        # Stampa il valore grezzo e la tensione
        print(f"value: {value}, Voltage: {voltage}V")

        # Attendi 0,5 secondi prima di eseguire la lettura successiva
        time.sleep(0.5)

Quando esegui questo script, la luminosità del LED cambia man mano che il potenziometro viene ruotato, mentre il valore analogico e la tensione a questo punto vengono visualizzati nella Shell.

* `machine.ADC - MicroPython Docs <https://docs.micropython.org/en/latest/esp32/quickref.html#adc-analog-to-digital-conversion>`_

