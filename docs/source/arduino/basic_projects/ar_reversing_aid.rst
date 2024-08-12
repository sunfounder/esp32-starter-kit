.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_reversing_aid:

6.3 Sistema di Assistenza al Parcheggio
===============================================
Immagina questo: sei in auto, pronto per fare retromarcia in un parcheggio stretto. Con il nostro progetto, avrai un modulo ultrasonico montato sul retro del veicolo, che funge da occhio digitale. Quando inserisci la retromarcia, il modulo si attiva, emettendo impulsi ultrasonici che rimbalzano sugli ostacoli dietro di te.

La magia avviene quando questi impulsi tornano al modulo. Esso calcola rapidamente la distanza tra la tua auto e gli oggetti, trasformando questi dati in un feedback visivo in tempo reale visualizzato su un vivace schermo LCD. Potrai vedere indicatori dinamici a colori che rappresentano la vicinanza degli ostacoli, garantendoti una comprensione chiara dell'ambiente circostante.

Ma non ci siamo fermati qui. Per immergerti ulteriormente in questa esperienza di guida, abbiamo incorporato un cicalino. Man mano che la tua auto si avvicina a un ostacolo, il ritmo del cicalino si intensifica, creando una sinfonia sonora di avvertimenti. È come avere un'orchestra personale che ti guida nelle manovre di parcheggio in retromarcia.

Questo progetto innovativo combina tecnologia all'avanguardia con un'interfaccia utente interattiva, rendendo la tua esperienza di retromarcia sicura e senza stress. Con il modulo ultrasonico, il display LCD e il cicalino che lavorano armoniosamente, ti sentirai sicuro e fiducioso mentre manovri in spazi ristretti, lasciandoti libero di concentrarti sul piacere di guidare.

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
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|
    *   - :ref:`cpn_buzzer`
        - \-
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|
    *   - :ref:`cpn_lcd`
        - |link_i2clcd1602_buy|

**Schema**

.. image:: ../../img/circuit/circuit_6.4_reversing_aid.png
    :width: 800
    :align: center

Il sensore ultrasonico nel progetto emette onde sonore ad alta frequenza e misura il tempo necessario affinché le onde rimbalzino dopo aver colpito un oggetto. Analizzando questi dati, è possibile calcolare la distanza tra il sensore e l'oggetto. Per fornire un avviso quando l'oggetto è troppo vicino, viene utilizzato un cicalino per produrre un segnale acustico. Inoltre, la distanza misurata viene visualizzata su uno schermo LCD per una facile visualizzazione.


**Collegamento**

.. image:: ../../img/wiring/6.4_aid_ultrasonic_bb.png

**Codice**

.. note::

    * Puoi aprire direttamente il file ``6.3_reversing_aid.ino`` nel percorso ``esp32-starter-kit-main\c\codes\6.3_reversing_aid``.
    * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta appropriata, fai clic sul pulsante **Upload**.
    * La libreria ``LiquidCrystal I2C`` è utilizzata qui, puoi installarla dal **Library Manager**.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/c06deba0-36fd-4f17-8290-c7a39202e089/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Dopo che il codice è stato caricato con successo, la distanza rilevata attualmente verrà visualizzata sul display LCD. Il cicalino cambierà quindi la frequenza del suono in base alle diverse distanze.

.. note:: 

    Se il codice e i collegamenti sono corretti, ma l'LCD non visualizza ancora alcun contenuto, puoi regolare il potenziometro sul retro per aumentare il contrasto.


**Come funziona?**

Questo codice ci aiuta a creare un semplice dispositivo di misurazione della distanza che può misurare la distanza tra oggetti e fornire un feedback tramite un display LCD e un cicalino.

La funzione ``loop()`` contiene la logica principale del programma e viene eseguita continuamente. Diamo un'occhiata più da vicino alla funzione ``loop()``.

#. Ciclo per leggere la distanza e aggiornare i parametri

    Nel ``loop``, il codice legge prima la distanza misurata dal modulo ultrasonico e aggiorna il parametro dell'intervallo in base alla distanza.

    .. code-block:: arduino

        // Aggiorna la distanza
        distance = readDistance();

        // Aggiorna gli intervalli in base alla distanza
        if (distance <= 10) {
            intervals = 300;
        } else if (distance <= 20) {
            intervals = 500;
        } else if (distance <= 50) {
            intervals = 1000;
        } else {
            intervals = 2000;
        }

#. Verifica se è il momento di suonare il cicalino

    Il codice calcola la differenza tra l'ora corrente e l'ultima volta che il cicalino ha suonato e, se la differenza è maggiore o uguale al tempo dell'intervallo, attiva il cicalino e aggiorna l'ora precedente.

    .. code-block:: arduino

        unsigned long currentMillis = millis();
        if (currentMillis - previousMillis >= intervals) {
            Serial.println("Beeping!");
            beep();
            previousMillis = currentMillis;
        }

#. Aggiorna il display LCD

    Il codice cancella il display LCD e poi visualizza "Dis:" e la distanza corrente in centimetri sulla prima riga.

    .. code-block:: arduino

        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Dis: ");
        lcd.print(distance);
        lcd.print(" cm");

        delay(100);





