.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime speciali.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Omaggi Festivi**: Partecipa a omaggi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _py_ir_obstacle:

5.3 Rileva l'Ostacolo
===================================

Questo modulo è comunemente installato su automobili e robot per rilevare
la presenza di ostacoli davanti a loro. È anche ampiamente utilizzato in dispositivi portatili, rubinetti d'acqua e altro ancora.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_avoid`
        - |link_avoid_buy|

**Pin Disponibili**

* **Pin Disponibili**

    Ecco un elenco di pin disponibili sulla scheda ESP32 per questo progetto.

    .. list-table::
        :widths: 5 20

        *   - Pin Disponibili
            - IO13, IO14, IO27, IO26, IO25, IO33, I35, I34, I39, I36, IO4, IO18, IO19, IO21, IO22, IO23

* **Pin Strapping (Input)**

    I pin Strapping sono un set speciale di pin utilizzati per determinare specifiche modalità di avvio durante l'accensione del dispositivo 
    (ad es. reset all'accensione).
   
    .. list-table::
        :widths: 5 15

        *   - Pin Strapping
            - IO5, IO0, IO2, IO12, IO15 
    
    In generale, **non è consigliato utilizzarli come pin di ingresso**. Se desideri utilizzare questi pin, considera il potenziale impatto sul processo di avvio. Per ulteriori dettagli, consulta la sezione :ref:`esp32_strapping`.

**Schema Elettrico**

.. image:: ../../img/circuit/circuit_5.3_avoid.png

Quando il modulo di evitamento degli ostacoli non rileva alcun ostacolo, IO14 restituisce un livello alto. Tuttavia, quando rileva un ostacolo, restituisce un livello basso. Puoi regolare il potenziometro blu per modificare la distanza di rilevamento di questo modulo.

**Cablaggio**

.. image:: ../../img/wiring/5.3_avoid_bb.png

**Codice**

.. note::

    * Apri il file ``5.3_avoid.py`` situato nel percorso ``esp32-starter-kit-main\micropython\codes``, oppure copia e incolla il codice in Thonny. Poi, clicca su "Esegui Script Corrente" o premi F5 per eseguirlo.
    * Assicurati di selezionare l'interprete "MicroPython (ESP32).COMxx" nell'angolo in basso a destra. 

.. code-block:: python

    import machine
    import time

    ir_avoid = machine.Pin(14, machine.Pin.IN, machine.Pin.PULL_UP) # pin modulo evitamento ostacoli

    while True:

        # Stampa i valori del modulo di evitamento degli ostacoli 
        print(ir_avoid.value()) 
        time.sleep(0.1)

Durante l'esecuzione del programma, se il modulo di evitamento degli ostacoli IR rileva un ostacolo di fronte a sé, il valore "0" verrà mostrato sul Serial Monitor, altrimenti verrà mostrato il valore "1".
