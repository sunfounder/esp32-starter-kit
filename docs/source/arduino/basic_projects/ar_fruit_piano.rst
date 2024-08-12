.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirsi a noi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e alle anteprime.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_fruit_piano:

6.1 Piano con la Frutta
==========================

Hai mai desiderato suonare il piano ma non potevi permettertelo? O forse vuoi semplicemente divertirti costruendo un piano di frutta fai-da-te? Bene, questo progetto fa per te! 

Con solo alcuni sensori tattili sulla scheda ESP32, ora puoi suonare le tue melodie preferite e goderti l'esperienza di suonare il piano senza spendere una fortuna.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_buzzer`
        - |link_passive_buzzer_buy|
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|

**Informazioni sui Pin Tattili**

Il microcontrollore ESP32 ha una funzionalità integrata di sensore tattile, che consente di utilizzare determinati pin sulla scheda 
come ingressi sensibili al tocco. Il sensore tattile funziona misurando i cambiamenti di capacità sui pin tattili, 
causati dalle proprietà elettriche del corpo umano.

Ecco alcune caratteristiche chiave del sensore tattile sull'ESP32:

* **Numero di pin tattili**

    L'ESP32 ha fino a 10 pin tattili, a seconda della scheda specifica. I pin tattili sono generalmente etichettati con una "T" seguita da un numero.

    * GPIO4: TOUCH0
    * GPIO0: TOUCH1
    * GPIO2: TOUCH2
    * GPIO15: TOUCH3
    * GPIO13: TOUCH4
    * GPIO12: TOUCH5
    * GPIO14: TOUCH6
    * GPIO27: TOUCH7
    * GPIO33: TOUCH8
    * GPIO32: TOUCH9

    .. note::
        I pin GPIO0 e GPIO2 sono utilizzati per il bootstrap e il flashing del firmware sull'ESP32, rispettivamente. Questi pin sono anche collegati al LED e al pulsante a bordo. Pertanto, generalmente non è consigliato utilizzare questi pin per altri scopi, poiché potrebbe interferire con il normale funzionamento della scheda.

* **Sensibilità**

    Il sensore tattile sull'ESP32 è molto sensibile e può rilevare anche piccoli cambiamenti di capacità. La sensibilità può essere regolata utilizzando le impostazioni software.

* **Protezione ESD**

    I pin tattili sull'ESP32 hanno una protezione integrata contro le scariche elettrostatiche (ESD), che aiuta a prevenire danni alla scheda dovuti all'elettricità statica.

* **Multitouch**

    Il sensore tattile sull'ESP32 supporta il multitouch, il che significa che puoi rilevare più eventi tattili contemporaneamente.


**Schema Elettrico**

.. image:: ../../img/circuit/circuit_6.1_fruit_piano.png

L'idea alla base di questo progetto è di utilizzare sensori tattili per rilevare quando un utente tocca un pin specifico. 
Ogni pin tattile è associato a una nota specifica, e quando l'utente tocca un pin, 
la nota corrispondente viene riprodotta sul buzzer passivo. 
Il risultato è un modo semplice ed economico per godersi l'esperienza di suonare il piano.


**Cablaggio**

.. image:: ../../img/wiring/6.1_fruit_piano_bb.png

In questo progetto, è necessario rimuovere l'ESP32 WROOM 32E dalla scheda di espansione e poi inserirlo nella breadboard. Questo perché alcuni pin sulla scheda di espansione sono collegati a resistori, che influenzeranno la capacità dei pin.

**Codice**


.. note::

    * Puoi aprire direttamente il file ``6.1_fruit_piano.ino`` nel percorso ``esp32-starter-kit-main\c\codes\6.1_fruit_piano``.
    * Oppure copia questo codice nell'IDE Arduino.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/3e06ce6c-268a-4fdc-99d0-6d74f68265e2/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    

Puoi collegare dei frutti a questi pin ESP32: 4, 15, 13, 12, 14, 27, 33, 32.

Quando lo script è in esecuzione, toccando questi frutti verranno riprodotte le note C, D, E, F, G, A, B e C5.

**Come funziona?**

* ``touchRead(uint8_t pin);``

    Questa funzione ottiene i dati del sensore tattile. Ogni sensore tattile ha un contatore per contare il numero di cicli di carica/scarica. 
    Quando il pad viene **toccato**, il valore nel contatore cambierà a causa della maggiore capacità equivalente. 
    La variazione dei dati determina se il pad è stato toccato o meno.

    * ``pin`` GPIO pin per leggere il valore TOUCH

    Questa funzione restituisce un valore compreso tra 0 e 4095, con un valore più basso che indica un ingresso tattile più forte.

.. note::
    Il ``threshold`` deve essere regolato in base alla conduttività dei diversi frutti. 
    
    Puoi eseguire lo script per vedere i valori stampati dalla shell.

    .. code-block::

      0: 60
      1: 62
      2: 71
      3: 74
      4: 73
      5: 78
      6: 80
      7: 82


    Dopo aver toccato i frutti sui pin 12, 14 e 27, i valori stampati sono i seguenti. Pertanto, ho impostato il ``threshold`` a 30, il che significa che quando viene rilevato un valore inferiore a 30, si considera che il pad sia stato toccato e il buzzer emetterà note diverse.
    
    .. code-block::

      0: 60
      1: 62
      2: 71
      3: 9
      4: 12
      5: 14
      6: 75
      7: 78

