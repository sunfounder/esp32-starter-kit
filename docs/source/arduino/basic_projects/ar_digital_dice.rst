.. note::

    Ciao, benvenuto nella Community di Appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirsi a noi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato a nuovi annunci di prodotti e anteprime.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_dice:

6.4 Dado Digitale
=============================

Questo progetto si basa sul progetto :ref:`py_7_segment`, aggiungendo un pulsante per controllare il numero visualizzato sul display a sette segmenti.

In questo progetto, viene generato un numero casuale e visualizzato sul display a sette segmenti per simulare il lancio di un dado. Quando il pulsante viene premuto, viene visualizzato un numero stabile (selezionato casualmente tra 1 e 6) sul display a sette segmenti. Premendo nuovamente il pulsante, si avvia la simulazione del lancio del dado, generando numeri casuali come in precedenza. Questo ciclo continua ogni volta che il pulsante viene premuto.

**Componenti Necessari**

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
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|
    *   - :ref:`cpn_7_segment`
        - |link_7segment_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|

**Schema**

.. image:: ../../img/circuit/circuit_6.6_electronic_dice.png

Questo progetto si basa sul progetto :ref:`ar_7_segment`, aggiungendo un pulsante per controllare il numero visualizzato sul display a sette segmenti.

Il pulsante è direttamente collegato a IO13 senza un resistore di pull-up o pull-down esterno perché IO13 ha un resistore di pull-up interno da 47K, eliminando la necessità di un resistore esterno aggiuntivo.


**Cablaggio**

.. image:: ../../img/wiring/6.6_DICE_bb.png

**Codice**

.. note::

    * Apri il file ``6.4_digital_dice.ino`` nel percorso ``esp32-starter-kit-main\c\codes\6.4_digital_dice``.
    * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta appropriata, clicca sul pulsante **Carica**.
    * :ref:`unknown_com_port`
    
    
.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/ad904f48-cd24-49ce-ad92-91b1fb76364d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Questo progetto si basa su :ref:`ar_7_segment` con un pulsante per avviare/fermare la visualizzazione a scorrimento sul display a 7 segmenti.

Quando il pulsante viene premuto, il display a 7 segmenti scorre i numeri da 1 a 6, e quando il pulsante viene rilasciato, viene visualizzato un numero casuale.
