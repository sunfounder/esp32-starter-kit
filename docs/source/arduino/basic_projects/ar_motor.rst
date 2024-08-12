.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e alle anteprime.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_motor:

4.1 Motore
===========================

In questo entusiasmante progetto, esploreremo come pilotare un motore utilizzando l'integrato L293D.

L'L293D è un circuito integrato versatile, comunemente utilizzato per il controllo dei motori in progetti di elettronica e robotica. È in grado di pilotare due motori in entrambe le direzioni, rendendolo una scelta popolare per applicazioni che richiedono un controllo preciso del motore.

Alla fine di questo avvincente progetto, avrai acquisito una solida comprensione di come i segnali digitali e i segnali PWM possono essere utilizzati efficacemente per controllare i motori. Questa conoscenza inestimabile costituirà una solida base per i tuoi futuri progetti in robotica e meccatronica. Preparati a immergerti nel mondo affascinante del controllo dei motori con l'L293D!

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
    *   - :ref:`cpn_motor`
        - |link_motor_buy|
    *   - :ref:`cpn_l293d`
        - \-

**Pin Disponibili**

Ecco un elenco di pin disponibili sulla scheda ESP32 per questo progetto.

.. list-table::
    :widths: 5 20 

    * - Pin Disponibili
      - IO13, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**Schema Elettrico**

.. image:: ../../img/circuit/circuit_4.1_motor_l293d.png


    
**Cablaggio**

.. note:: 

  Poiché il motore richiede una corrente relativamente alta, è necessario inserire prima la batteria e quindi far scorrere l'interruttore sulla scheda di espansione in posizione ON per attivare l'alimentazione della batteria.

.. image:: ../../img/wiring/4.1_motor_l293d_bb.png



**Codice**

.. note::

    * Apri il file ``4.1_motor.ino`` nel percorso ``esp32-starter-kit-main\c\codes\4.1_motor``.
    * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta appropriata, fai clic sul pulsante **Upload**.
    * :ref:`unknown_com_port`
    
    
.. raw:: html
    
  <iframe src=https://create.arduino.cc/editor/sunfounder01/13364fc5-5094-4a84-90ce-07a5f85556dc/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>



Una volta che il codice è stato caricato con successo, osserverai il motore ruotare in senso orario per un secondo, poi in senso antiorario per un secondo, seguito da una pausa di due secondi. Questa sequenza di azioni continuerà in un ciclo infinito.


**Scopri di più**

Oltre a far semplicemente ruotare il motore in senso orario e antiorario, puoi anche controllare la velocità di rotazione del motore utilizzando la modulazione della larghezza di impulso (PWM) sul pin di controllo, come mostrato di seguito.

.. note::

    * Apri il file ``4.1_motor_pwm.ino`` nel percorso ``esp32-starter-kit-main\c\codes\4.1_motor_pwm``.
    * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta appropriata, fai clic sul pulsante **Upload**.
    * :ref:`unknown_com_port`
    
    
.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/32c262fd-9975-4137-9973-8b62d7240fee/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Il codice precedente imposta direttamente i due pin del motore su livelli di tensione alti o bassi per controllare la rotazione e l'arresto del motore.

Qui utilizziamo la periferica |link_ledc| (controllo LED) per generare segnali PWM e controllare la velocità del motore. Attraverso due cicli ``for``, il ciclo di lavoro del canale A viene aumentato o diminuito da 0 a 255 mentre il canale B rimane a 0.

In questo modo, puoi osservare il motore aumentare gradualmente la sua velocità fino a 255, poi diminuire a 0, continuando a ciclo infinito in questo modo.

Se vuoi che il motore ruoti in direzione opposta, basta scambiare i valori dei canali A e B.
