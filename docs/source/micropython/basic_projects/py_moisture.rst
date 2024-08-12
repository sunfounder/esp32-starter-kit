.. note::

    Ciao, benvenuto nella community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e alle anteprime.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Sei pronto per esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _py_moisture:

5.9 Misurare l'Umidità del Terreno
=====================================

Questo sensore capacitivo di umidità del terreno è diverso dalla maggior parte dei sensori resistivi presenti sul mercato, utilizzando il principio dell'induzione capacitiva per rilevare l'umidità del terreno.

Leggendo visivamente i valori dal sensore di umidità del terreno, possiamo raccogliere informazioni sul livello di umidità del suolo. Queste informazioni sono utili per varie applicazioni, come sistemi di irrigazione automatica, monitoraggio della salute delle piante o progetti di rilevamento ambientale.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|

**Pin Disponibili**

* **Pin Disponibili**

    Ecco un elenco dei pin disponibili sulla scheda ESP32 per questo progetto.

    .. list-table::
        :widths: 5 15

        *   - Pin Disponibili
            - IO14, IO25, I35, I34, I39, I36


* **Pin di Strapping**

    I seguenti pin sono pin di strapping, che influenzano il processo di avvio dell'ESP32 durante l'accensione o il reset. Tuttavia, una volta che l'ESP32 è avviato correttamente, possono essere utilizzati come pin normali.

    .. list-table::
        :widths: 5 15

        *   - Pin di Strapping
            - IO0, IO12

**Schema**

.. image:: ../../img/circuit/circuit_5.9_soil_moisture.png

Inserendo il modulo nel terreno e annaffiandolo, il valore letto su I35 diminuirà.

**Collegamenti**

.. image:: ../../img/wiring/5.9_moisture_bb.png

**Codice**

.. note::

    * Apri il file ``5.9_moisture.py`` situato nel percorso ``esp32-starter-kit-main\micropython\codes``, oppure copia e incolla il codice in Thonny. Poi clicca su "Run Current Script" o premi F5 per eseguirlo.
    * Assicurati di selezionare l'interprete "MicroPython (ESP32).COMxx" nell'angolo in basso a destra. 


.. code-block:: python


    from machine import ADC, Pin
    import time

    # crea un oggetto ADC su un pin
    moisture = ADC(Pin(35, Pin.IN))

    # Configura l'attenuazione ADC a 11dB per il range completo     
    moisture.atten(moisture.ATTN_11DB)

    while True:

        # leggi un valore analogico grezzo nell'intervallo 0-4095
        value = moisture.read()  
        print(value)
        time.sleep(0.05)


Quando il programma viene eseguito, vedrai il valore dell'umidità del suolo nella Shell.

Inserendo il modulo nel terreno e annaffiandolo, il valore del sensore di umidità del suolo diminuirà.
