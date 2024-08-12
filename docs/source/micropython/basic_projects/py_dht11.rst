.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime speciali.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Omaggi Festivi**: Partecipa a omaggi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _py_dht11:

5.13 Temperatura - Umidità
=======================================
Il DHT11 è un sensore di temperatura e umidità comunemente utilizzato per le misurazioni ambientali. Si tratta di un sensore digitale che comunica con un microcontrollore per fornire letture di temperatura e umidità.

In questo progetto, leggeremo il sensore DHT11 e stamperemo i valori di temperatura e umidità rilevati.

Leggendo i dati forniti dal sensore, possiamo ottenere i valori attuali di temperatura e umidità nell'ambiente. Questi valori possono essere utilizzati per il monitoraggio in tempo reale delle condizioni ambientali, osservazioni meteorologiche, controllo del clima interno, report sull'umidità e altro ancora.

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
    *   - :ref:`cpn_dht11`
        - |link_dht11_buy|

* **Pin Disponibili**

    Ecco un elenco di pin disponibili sulla scheda ESP32 per questo progetto.

    .. list-table::
        :widths: 5 20

        *   - Pin Disponibili
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**Schema Elettrico**

.. image:: ../../img/circuit/circuit_5.13_dht11.png


**Cablaggio**

.. image:: ../../img/wiring/5.13_dht11_bb.png

**Codice**

.. note::

    * Apri il file ``5.13_dht11.py`` situato nel percorso ``esp32-starter-kit-main\micropython\codes``, oppure copia e incolla il codice in Thonny. Poi, clicca su "Esegui Script Corrente" o premi F5 per eseguirlo.
    * Assicurati di selezionare l'interprete "MicroPython (ESP32).COMxx" nell'angolo in basso a destra. 

.. code-block:: python

    import dht
    import machine
    import time

    # Inizializza il sensore DHT11 e collegalo al pin 14
    sensor = dht.DHT11(machine.Pin(14))

    # Ciclo infinito per misurare continuamente temperatura e umidità
    while True:
        try:
            # Misura la temperatura e l'umidità
            sensor.measure()

            # Ottieni i valori di temperatura e umidità
            temp = sensor.temperature()
            humi = sensor.humidity()

            # Stampa la temperatura e l'umidità
            print("Temperature: {}, Humidity: {}".format(temp, humi))

            # Attendi 1 secondo tra una misurazione e l'altra
            time.sleep(1)
        except Exception as e:
            print("Error: ", e)
            time.sleep(1)


Quando il codice è in esecuzione, vedrai che la Shell stampa continuamente la temperatura e l'umidità, e man mano che il programma continua a funzionare, questi due valori diventeranno sempre più precisi.


**Approfondisci**

Puoi anche visualizzare la temperatura e l'umidità sul display LCD1602 I2C.

.. image:: ../../img/wiring/5.13_dht11_lcd_bb.png

.. note::

    * Apri il file ``5.13_dht11_lcd.py`` situato nel percorso ``esp32-starter-kit-main\micropython\codes``, oppure copia e incolla il codice in Thonny. Poi, clicca su "Esegui Script Corrente" o premi F5 per eseguirlo.
    * Assicurati di selezionare l'interprete "MicroPython (ESP32).COMxx" nell'angolo in basso a destra. 
    * Qui devi utilizzare la libreria chiamata ``lcd1602.py``, verifica se è stata caricata su ESP32, per un tutorial dettagliato fai riferimento a :ref:`add_libraries_py`.

.. code-block:: python

    import dht
    import machine
    import time
    from lcd1602 import LCD

    # Inizializza il sensore DHT11 e collegalo al pin 14
    sensor = dht.DHT11(machine.Pin(14))

    # Inizializza il display LCD1602
    lcd = LCD()

    # Ciclo per misurare temperatura e umidità
    while True:
        try:
            # Misura la temperatura e l'umidità
            sensor.measure()

            # Ottieni i valori di temperatura e umidità
            temp = sensor.temperature()
            humi = sensor.humidity()

            # Stampa la temperatura e l'umidità
            print("Temperature: {}, Humidity: {}".format(temp, humi))

            # Cancella il display LCD
            lcd.clear()

            # Visualizza la temperatura e l'umidità sullo schermo LCD1602
            lcd.write(0, 0, "Temp: {}\xDFC".format(temp))
            lcd.write(0, 1, "Humi: {}%".format(humi))

            # Attendi 2 secondi prima di misurare nuovamente
            time.sleep(2)

        except Exception as e:
            print("Error: ", e)
            time.sleep(2)

