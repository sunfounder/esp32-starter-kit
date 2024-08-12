.. note::

    Ciao, benvenuto nella Community di Appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirsi a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni l'accesso anticipato a nuovi annunci di prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_ac_buz:

3.1 Beep
==================
Questo è un semplice progetto per far emettere un bip rapido a un buzzer attivo quattro volte al secondo.

**Componenti necessari**

In questo progetto, avremo bisogno dei seguenti componenti.

È sicuramente conveniente acquistare un kit completo, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - ELEMENTI IN QUESTO KIT
        - LINK
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

Puoi anche acquistarli separatamente dai link sottostanti.

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

Quando l'uscita IO14 è a livello alto, dopo il resistore limitatore di corrente da 1K (per proteggere il transistor), il S8050 (transistor NPN) condurrà, facendo suonare il buzzer.

Il ruolo del S8050 (transistor NPN) è quello di amplificare la corrente e rendere il suono del buzzer più forte. In realtà, puoi anche collegare il buzzer direttamente a IO14, ma noterai che il suono del buzzer sarà più debole.


**Cablaggio**

Il kit include due tipi di buzzer.
Dobbiamo utilizzare un buzzer attivo. Giralo, il retro sigillato (non il PCB esposto) è quello che vogliamo usare.

.. image:: ../../components/img/buzzer.png
    :width: 500
    :align: center

Il buzzer necessita di un transistor per funzionare, qui utilizziamo l'S8050 (Transistor NPN).

.. image:: ../../img/wiring/3.1_buzzer_bb.png

**Codice**

.. note::

    * Puoi aprire il file ``3.1_beep.ino`` nel percorso ``esp32-starter-kit-main\c\codes\3.1_beep``.
    * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta appropriata, clicca sul pulsante **Carica**.
    * :ref:`unknown_com_port`

.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/f17a663c-2941-407e-9137-6f6eacd28c23/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Dopo che il codice è stato caricato con successo, sentirai un bip ogni secondo.
