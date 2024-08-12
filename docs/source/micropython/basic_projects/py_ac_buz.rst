.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime speciali.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Omaggi Festivi**: Partecipa a omaggi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _py_ac_buz:

3.1 Beep
==================
Questo è un progetto semplice per far suonare un buzzer attivo rapidamente quattro volte ogni secondo.

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
    *   - :ref:`cpn_buzzer`
        - \-
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|

**Pin Disponibili**

Ecco un elenco di pin disponibili sulla scheda ESP32 per questo progetto.

.. list-table::
    :widths: 5 20 

    * - Pin Disponibili
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**Schema Elettrico**

.. image:: ../../img/circuit/circuit_3.1_buzzer.png
    :width: 500
    :align: center

Quando l'uscita di IO14 è alta, dopo il resistore limitatore di corrente da 1K (per proteggere il transistor), l'S8050 (transistor NPN) condurrà, facendo suonare il buzzer.

Il ruolo dell'S8050 (transistor NPN) è di amplificare la corrente e rendere il suono del buzzer più forte. In realtà, puoi anche collegare il buzzer direttamente a IO14, ma noterai che il suono del buzzer sarà più debole.

**Cablaggio**

Nel kit sono inclusi due tipi di buzzer.
Dobbiamo utilizzare un buzzer attivo. Girateli, il retro sigillato (non il PCB esposto) è quello che ci serve.

.. image:: ../../components/img/buzzer.png
    :width: 500
    :align: center

Il buzzer deve utilizzare un transistor quando funziona, qui usiamo l'S8050 (Transistor NPN).

.. image:: ../../img/wiring/3.1_buzzer_bb.png

**Codice**

.. note::

    * Apri il file ``3.1_beep.py`` situato nel percorso ``esp32-starter-kit-main\micropython\codes``, oppure copia e incolla il codice in Thonny. Poi, clicca su "Esegui Script Corrente" o premi F5 per eseguirlo.
    * Assicurati di selezionare l'interprete "MicroPython (ESP32).COMxx" nell'angolo in basso a destra. 

.. code-block:: python

    import machine
    import time

    # Crea un oggetto Pin che rappresenta il pin 14 e impostalo in modalità output
    buzzer = machine.Pin(14, machine.Pin.OUT)

    # Entra in un ciclo infinito
    while True:
        # Itera sui valori da 0 a 3 utilizzando un ciclo for
        per i in range(4):
            # Accendi il buzzer impostando il suo valore a 1
            buzzer.value(1)
            # Pausa di 0,2 secondi
            time.sleep(0.2)
            # Spegni il buzzer
            buzzer.value(0)
            # Pausa di 0,2 secondi
            time.sleep(0.2)
        # Pausa di 1 secondo prima di riavviare il ciclo for
        time.sleep(1)

Quando lo script è in esecuzione, il buzzer emetterà un segnale acustico rapido quattro volte ogni secondo.
