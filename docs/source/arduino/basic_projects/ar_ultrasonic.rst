.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e alle anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_ultrasonic:

5.12 Misurare la Distanza
======================================
Il modulo ultrasonico viene utilizzato per la misurazione della distanza o per il rilevamento degli oggetti. In questo progetto, programmeremo il modulo per ottenere le distanze degli ostacoli. Inviando impulsi ultrasonici e misurando il tempo necessario affinché questi rimbalzino, possiamo calcolare le distanze. Questo ci permette di implementare azioni basate sulla distanza o comportamenti di evitamento degli ostacoli.

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
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|

**Pin Disponibili**

* **Pin Disponibili**

    Ecco un elenco dei pin disponibili sulla scheda ESP32 per questo progetto.

    .. list-table::
        :widths: 5 20

        *   - Per Ingresso
            - IO13, IO14, IO27, IO26, IO25, IO33, IO32, I35, I34, I39, I36, IO4, IO18, IO19, IO21, IO22, IO23
        *   - Per Uscita
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**Schema**

.. image:: ../../img/circuit/circuit_5.12_ultrasonic.png

L'ESP32 invia una serie di segnali a onda quadra al pin Trig del sensore ultrasonico ogni 10 secondi. Questo induce il sensore ultrasonico a emettere un segnale ultrasonico a 40kHz verso l'esterno. Se c'è un ostacolo davanti, le onde ultrasoniche verranno riflesse.

Registrando il tempo che passa dall'invio alla ricezione del segnale, dividendo per 2 e moltiplicando per la velocità del suono, è possibile determinare la distanza dall'ostacolo.

**Collegamenti**

.. image:: ../../img/wiring/5.12_ultrasonic_bb.png

**Codice**

.. note::

    * Apri il file ``5.12_ultrasonic.ino`` nel percorso ``esp32-starter-kit-main\c\codes\5.12_ultrasonic``.
    * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta appropriata, fai clic sul pulsante **Upload**.
    * :ref:`unknown_com_port`
    
.. raw:: html
    
    <iframe src=https://create.arduino.cc/editor/sunfounder01/28ded128-62a8-4b2b-b21a-450f03323cd8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Ricorda di impostare la velocità di comunicazione seriale a 115200 baud.

Dopo che il codice è stato caricato con successo, il monitor seriale stamperà la distanza tra il sensore ultrasonico e l'ostacolo di fronte.

**Come funziona?**

Per l'applicazione del sensore ultrasonico, possiamo controllare direttamente la sottofunzione.

.. code-block:: arduino

    float readSensorData(){// ...}

* Il ``trigPin`` del modulo ultrasonico trasmette un segnale a onda quadra di 10us ogni 2us.

    .. code-block:: arduino

        // Invia un segnale basso prima di inviare un segnale alto
        digitalWrite(trigPin, LOW); 
        delayMicroseconds(2);
        // Invia un segnale alto di 10 microsecondi al trigPin
        digitalWrite(trigPin, HIGH); 
        delayMicroseconds(10);
        // Ritorna al segnale basso
        digitalWrite(trigPin, LOW);


* Il ``echoPin`` riceve un segnale di livello alto se c'è un ostacolo nel raggio e utilizza la funzione ``pulseIn()`` per registrare il tempo dall'invio alla ricezione.

    .. code-block:: arduino

        unsigned long microsecond = pulseIn(echoPin, HIGH);

* La velocità del suono è di 340 metri al secondo, equivalente a 29 microsecondi per centimetro. Misurando il tempo impiegato da un'onda quadra per raggiungere un ostacolo e tornare, possiamo calcolare la distanza percorsa dividendo il tempo totale per 2. Questo ci dà la distanza dell'ostacolo dalla sorgente dell'onda sonora.

    .. code-block:: arduino

        float distance = microsecond / 29.00 / 2;  


Nota che il sensore ultrasonico interromperà il programma quando è in funzione, il che potrebbe causare alcuni ritardi quando si scrivono progetti complessi.

