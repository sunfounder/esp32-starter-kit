.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime speciali.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Omaggi Festivi**: Partecipa a omaggi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _py_fruit_piano:

6.1 Pianoforte di Frutta
============================

Hai mai desiderato suonare il pianoforte ma non potevi permettertelo? O forse vuoi solo divertirti a creare un pianoforte di frutta fai-da-te? Bene, questo progetto fa per te!

Con solo alcuni sensori tattili sulla scheda ESP32, ora puoi suonare i tuoi brani preferiti e goderti l'esperienza di suonare il pianoforte senza spendere una fortuna.

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
        - |link_passive_buzzer_buy|
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|

**Informazioni sui Pin Touch**

Il microcontrollore ESP32 dispone di funzionalità touch integrata, che ti consente 
di utilizzare alcuni pin della scheda come ingressi sensibili al tocco. Il sensore 
touch funziona misurando le variazioni di capacità sui pin touch, causate dalle 
proprietà elettriche del corpo umano.

Ecco alcune caratteristiche principali del sensore touch sull'ESP32:

* **Numero di pin touch**

    L'ESP32 ha fino a 10 pin touch, a seconda della scheda specifica. I pin touch sono generalmente etichettati con una "T" seguita da un numero.

    * GPIO4: TOUCH0
    * GPIO0：TOUCH1
    * GPIO2: TOUCH2
    * GPIO15: TOUCH3
    * GPIO13: TOUCH4
    * GPIO12: TOUCH5
    * GPIO14: TOUCH6
    * GPIO27: TOUCH7
    * GPIO33: TOUCH8
    * GPIO32: TOUCH9

    .. note::
        I pin GPIO0 e GPIO2 sono utilizzati rispettivamente per il bootstrapping e il flashing del firmware sull'ESP32. Questi pin sono anche collegati al LED e al pulsante integrati. Pertanto, non è generalmente consigliato utilizzare questi pin per altri scopi, poiché potrebbe interferire con il normale funzionamento della scheda.

* **Sensibilità**

    Il sensore touch sull'ESP32 è molto sensibile e può rilevare anche piccoli cambiamenti di capacità. La sensibilità può essere regolata tramite impostazioni software.

* **Protezione ESD**

    I pin touch sull'ESP32 hanno una protezione ESD (Electrostatic Discharge) integrata, che aiuta a prevenire danni alla scheda dovuti all'elettricità statica.

* **Multitouch**

    Il sensore touch sull'ESP32 supporta il multitouch, il che significa che puoi rilevare più eventi di tocco contemporaneamente.


**Schema Elettrico**

.. image:: ../../img/circuit/circuit_6.1_fruit_piano.png

L'idea alla base di questo progetto è utilizzare i sensori touch per rilevare quando un utente tocca un pin specifico. 
Ogni pin touch è associato a una nota specifica e, quando l'utente tocca un pin, 
la nota corrispondente viene riprodotta sul buzzer passivo. 
Il risultato è un modo semplice ed economico per godersi l'esperienza di suonare il pianoforte.


**Cablaggio**

.. image:: ../../img/wiring/6.1_fruit_piano_bb.png

In questo progetto, è necessario rimuovere l'ESP32 WROOM 32E dalla scheda di espansione e inserirlo nella breadboard. Questo perché alcuni pin sulla scheda di espansione sono collegati a resistori, il che influirà sulla capacità dei pin.

**Codice**

.. note::

    * Apri il file ``6.1_fruit_piano.py`` situato nel percorso ``esp32-starter-kit-main\micropython\codes``, oppure copia e incolla il codice in Thonny. Poi, clicca su "Esegui Script Corrente" o premi F5 per eseguirlo.
    * Assicurati di selezionare l'interprete "MicroPython (ESP32).COMxx" nell'angolo in basso a destra. 

.. code-block:: python

    from machine import Pin, PWM, TouchPad
    import time

    # Definisci i pin touch e le loro note corrispondenti
    touch_pins = [4, 15, 13, 12, 14, 27, 33, 32]  # Usa pin validi con capacità touch
    notes = [262, 294, 330, 349, 392, 440, 494, 523]

    # Inizializza i sensori touch
    touch_sensors = [TouchPad(Pin(pin)) for pin in touch_pins]

    # Inizializza il buzzer
    buzzer = PWM(Pin(25), duty=0)

    # Funzione per riprodurre un tono
    def play_tone(frequency, duration):
        buzzer.freq(frequency)
        buzzer.duty(512)
        time.sleep_ms(duration)
        buzzer.duty(0)

    touch_threshold = 200

    # Loop principale per controllare gli input touch e riprodurre la nota corrispondente
    while True:
        for i, touch_sensor in enumerate(touch_sensors):
            value = touch_sensor.read()
            print(i,value)
            if value < touch_threshold:
                play_tone(notes[i], 100)
                time.sleep_ms(50)
            time.sleep(0.01)


Puoi collegare frutti a questi pin ESP32: 4, 15, 13, 12, 14, 27, 33, 32.

Quando lo script è in esecuzione, toccando questi frutti verranno riprodotte le note C, D, E, F, G, A, B e C5.

.. note::
    ``Touch_threshold`` deve essere regolato in base alla conduttività dei diversi frutti.
    
    Puoi eseguire prima lo script per vedere i valori stampati dalla shell.

    .. code-block::

        0 884
        1 801
        2 856
        3 964
        4 991
        5 989
        6 1072
        7 1058

    Dopo aver toccato i frutti sui pin 12, 14 e 27, i valori stampati sono i seguenti. Pertanto, ho impostato ``touch_threshold`` a 200, il che significa che quando viene rilevato un valore inferiore a 200, si considera che sia stato toccato, e il buzzer emetterà note diverse.
    
    .. code-block::

        0 882
        1 810
        2 799
        3 109
        4 122
        5 156
        6 1068
        7 1055

