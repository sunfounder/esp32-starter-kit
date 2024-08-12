.. note::

    Ciao, benvenuto nella community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e alle anteprime.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Sei pronto per esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _py_line_track:

5.4 Rilevamento della Linea
===================================

Il modulo di tracciamento delle linee viene utilizzato per rilevare la presenza di aree nere sul terreno, come linee nere nastrate con nastro isolante.

Il suo emettitore emette luce infrarossa appropriata verso il terreno, che viene relativamente assorbita e debolmente riflessa dalle superfici nere. L'opposto avviene per le superfici bianche. Se viene rilevata luce riflessa, il terreno è attualmente indicato come bianco. Se non viene rilevata, è indicato come nero.

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
    *   - :ref:`cpn_line_track`
        - |link_line_track_buy|

**Pin Disponibili**

* **Pin Disponibili**

    Ecco un elenco dei pin disponibili sulla scheda ESP32 per questo progetto.

    .. list-table::
        :widths: 5 20

        *   - Pin Disponibili
            - IO13, IO14, IO27, IO26, IO25, IO33, I35, I34, I39, I36, IO4, IO18, IO19, IO21, IO22, IO23

* **Pin di Strapping (Input)**

    I pin di strapping sono un insieme speciale di pin che vengono utilizzati per determinare specifiche modalità di avvio durante l'avvio del dispositivo 
    (cioè, il reset all'accensione).

    .. list-table::
        :widths: 5 15

        *   - Pin di Strapping
            - IO5, IO0, IO2, IO12, IO15 
    
    In generale, non è **raccomandato usarli come pin di input**. Se desideri utilizzare questi pin, considera l'impatto potenziale sul processo di avvio. Per ulteriori dettagli, fai riferimento alla sezione :ref:`esp32_strapping`.

**Schema**

.. image:: ../../img/circuit/circuit_5.4_line.png

Quando il modulo di tracciamento delle linee rileva una linea nera, IO14 restituisce un livello alto. D'altra parte, quando rileva una linea bianca, IO14 restituisce un livello basso. Puoi regolare il potenziometro blu per modificare la sensibilità della rilevazione di questo modulo.

**Collegamenti**

.. image:: ../../img/wiring/5.4_line_bb.png
    :align: center
    :width: 600

**Codice**

.. note::

    * Apri il file ``5.4_detect_the_line.py`` situato nel percorso ``esp32-starter-kit-main\micropython\codes``, oppure copia e incolla il codice in Thonny. Poi clicca su "Run Current Script" o premi F5 per eseguirlo.
    * Assicurati di selezionare l'interprete "MicroPython (ESP32).COMxx" nell'angolo in basso a destra. 

.. code-block:: python

    import machine
    import time

    # Crea un oggetto pin chiamato line, imposta il pin numero 14 come input
    line = machine.Pin(14, machine.Pin.IN)

    while True:
        # Controlla se il valore è 1 (nero)
        if line.value() == 1:
            # Stampa "nero"
            print("black")
            time.sleep(0.5)
        # Se il valore non è 1 (è 0, il che significa bianco)
        else :
            # Stampa "bianco"
            print("white")
            time.sleep(0.5)

Quando il modulo di tracciamento delle linee rileva una linea nera, appare "nero" nella Shell; altrimenti, viene visualizzato "bianco".
