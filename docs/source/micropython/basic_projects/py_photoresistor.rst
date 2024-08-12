.. note::

    Ciao, benvenuto nella community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci il mondo di Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché Unirsi?**

    - **Supporto Esperti**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara & Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa ai giveaway e alle promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _py_photoresistor:

5.7 Sentire la Luce
=============================

Il fotoresistore è un dispositivo comunemente utilizzato per gli input analogici, simile a un potenziometro. Il suo valore di resistenza cambia in base all'intensità della luce che riceve. Quando esposto a luce intensa, la resistenza del fotoresistore diminuisce, mentre con l'abbassarsi dell'intensità luminosa, la resistenza aumenta.

Leggendo il valore del fotoresistore, possiamo raccogliere informazioni sulle condizioni di luce ambientale. Queste informazioni possono essere utilizzate per compiti come controllare la luminosità di un LED, regolare la sensibilità di un sensore o implementare azioni dipendenti dalla luce in un progetto.

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
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

**Pin Disponibili**

* **Pin Disponibili**

    Ecco un elenco dei pin disponibili sulla scheda ESP32 per questo progetto.

    .. list-table::
        :widths: 5 15

        *   - Pin Disponibili
            - IO14, IO25, I35, I34, I39, I36


* **Pin di Strapping**

    I seguenti pin sono pin di strapping, che influenzano il processo di avvio dell'ESP32 durante l'accensione o il reset. Tuttavia, una volta che l'ESP32 è stato avviato correttamente, possono essere utilizzati come pin regolari.

    .. list-table::
        :widths: 5 15

        *   - Pin di Strapping
            - IO0, IO12

**Schema**

.. image:: ../../img/circuit/circuit_5.7_photoresistor.png

All'aumentare dell'intensità della luce, la resistenza del fotoresistore (LDR) diminuisce, provocando una diminuzione del valore letto su I35.

**Cablatura**

.. image:: ../../img/wiring/5.7_photoresistor_bb.png

**Codice**

.. note::

    * Apri il file ``5.7_feel_the_light.py`` situato nel percorso ``esp32-starter-kit-main\micropython\codes``, oppure copia e incolla il codice in Thonny. Successivamente, fai clic su "Esegui lo script corrente" o premi F5 per eseguirlo.
    * Assicurati di selezionare l'interprete "MicroPython (ESP32).COMxx" nell'angolo in basso a destra.

.. code-block:: python

    from machine import ADC,Pin
    import time

    # crea un oggetto ADC che opera su un pin
    photoresistor = ADC(Pin(35, Pin.IN))

    # Configura l'attenuazione dell'ADC a 11dB per l'intera gamma     
    photoresistor.atten(photoresistor.ATTN_11DB)

    while True:

        # leggi un valore analogico grezzo nell'intervallo 0-4095
        value = photoresistor.read()  
        print(value)
        time.sleep(0.05)

Dopo l'esecuzione del programma, la Shell stamperà i valori del fotoresistore. Puoi illuminare il sensore con una torcia o coprirlo con la mano per vedere come cambia il valore.

* ``atten(photoresistor.ATTN_11DB)``: Configura l'attenuazione dell'ADC a 11dB per l'intera gamma.

    Per leggere tensioni superiori alla tensione di riferimento, applica l'attenuazione dell'ingresso con l'argomento chiave atten.

    Valori validi (e intervalli di misurazione lineari approssimativi) sono:

    * ADC.ATTN_0DB: Nessuna attenuazione (100mV - 950mV)
    * ADC.ATTN_2_5DB: Attenuazione di 2,5dB (100mV - 1250mV)
    * ADC.ATTN_6DB: Attenuazione di 6dB (150mV - 1750mV)
    * ADC.ATTN_11DB: Attenuazione di 11dB (150mV - 2450mV)

* `machine.ADC - MicroPython Docs <https://docs.micropython.org/en/latest/esp32/quickref.html#adc-analog-to-digital-conversion>`_

