.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime speciali.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Omaggi Festivi**: Partecipa a omaggi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _py_button:

5.1 Lettura del Valore del Pulsante
==============================================

In questo progetto interattivo, esploreremo il controllo dei pulsanti e la manipolazione degli LED.

Il concetto è semplice ma efficace. Leggeremo lo stato di un pulsante. Quando il pulsante viene premuto, registra un livello di tensione alto, o 'stato alto'. Questa azione attiverà l'accensione di un LED.

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
    *   - :ref:`cpn_button`
        - |link_button_buy|

**Pin Disponibili**

* **Pin Disponibili**

    Ecco un elenco di pin disponibili sulla scheda ESP32 per questo progetto.

    .. list-table::
        :widths: 5 20

        *   - Per Input
            - IO14, IO25, I35, I34, I39, I36, IO18, IO19, IO21, IO22, IO23
        *   - Per Output
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23
    
* **Pin ad Uso Condizionale (Input)**

    I seguenti pin hanno resistori di pull-up o pull-down integrati, quindi non sono necessari resistori esterni quando **vengono utilizzati come pin di ingresso**:


    .. list-table::
        :widths: 5 15
        :header-rows: 1

        *   - Pin ad Uso Condizionale
            - Descrizione
        *   - IO13, IO15, IO2, IO4
            - Il pull-up con un resistore da 47K imposta il valore su alto di default.
        *   - IO27, IO26, IO33
            - Il pull-up con un resistore da 4.7K imposta il valore su alto di default.
        *   - IO32
            - Il pull-down con un resistore da 1K imposta il valore su basso di default.

* **Pin Strapping (Input)**

    I pin Strapping sono un set speciale di pin utilizzati per determinare specifiche modalità di avvio durante l'accensione del dispositivo 
    (ad es. reset all'accensione).

        
    .. list-table::
        :widths: 5 15

        *   - Pin Strapping
            - IO5, IO0, IO2, IO12, IO15 
    
    In generale, **non è consigliato utilizzarli come pin di ingresso**. Se desideri utilizzare questi pin, considera il potenziale impatto sul processo di avvio. Per ulteriori dettagli, consulta la sezione :ref:`esp32_strapping`.


**Schema Elettrico**

.. image:: ../../img/circuit/circuit_5.1_button.png

Per garantire un funzionamento corretto, collega un lato del pin del pulsante a 3.3V e l'altro lato a IO14. Quando il pulsante viene premuto, IO14 verrà impostato su alto, facendo accendere il LED. Quando il pulsante viene rilasciato, IO14 tornerà al suo stato sospeso, che può essere alto o basso. Per garantire un livello basso stabile quando il pulsante non è premuto, IO14 dovrebbe essere collegato a GND tramite un resistore pull-down da 10K.

**Cablaggio**

.. image:: ../../img/wiring/5.1_button_bb.png

.. note::
    
    Un pulsante a quattro pin è progettato a forma di H. Quando il pulsante non viene premuto, i pin sinistro e destro sono scollegati e la corrente non può fluire tra di essi. Tuttavia, quando il pulsante viene premuto, i pin sinistro e destro sono collegati, creando un percorso per il flusso di corrente.

**Codice**

.. note::

    * Apri il file ``5.1_read_button_value.py`` situato nel percorso ``esp32-starter-kit-main\micropython\codes``, oppure copia e incolla il codice in Thonny. Poi, clicca su "Esegui Script Corrente" o premi F5 per eseguirlo.
    * Assicurati di selezionare l'interprete "MicroPython (ESP32).COMxx" nell'angolo in basso a destra. 



.. code-block:: python

    import machine
    import time

    button = machine.Pin(14, machine.Pin.IN) # Pin del pulsante
    led = machine.Pin(26, machine.Pin.OUT) # Pin del LED


    while True:
        # Se il pulsante viene premuto leggendo il suo valore
        if button.value() == 1:
            # Accendi il LED impostando il suo valore a 1
            led.value(1)
    #         time.sleep(0.5)
        else:
            # Spegni il LED
            led.value(0)

Durante l'esecuzione dello script, il LED si accende quando premi il pulsante e si spegne quando lo rilasci.

