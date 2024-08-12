.. note::

    Ciao, benvenuto nella community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e alle anteprime.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Sei pronto per esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi!

.. _py_motor:

4.1 Piccolo Ventilatore
===========================

In questo interessante progetto, esploreremo come controllare un motore utilizzando l'L293D.

L'L293D è un circuito integrato versatile comunemente utilizzato per il controllo dei motori in progetti di elettronica e robotica. Può pilotare due motori in entrambe le direzioni, rendendolo una scelta popolare per applicazioni che richiedono un controllo preciso del motore.

Al termine di questo affascinante progetto, avrai acquisito una comprensione approfondita di come i segnali digitali e i segnali PWM possano essere utilizzati efficacemente per controllare i motori. Questa conoscenza inestimabile sarà una solida base per le tue future imprese in robotica e meccatronica. Preparati a immergerti nel mondo entusiasmante del controllo dei motori con l'L293D!

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_motor`
        - |link_motor_buy|
    *   - :ref:`cpn_l293d`
        - \-

**Pin Disponibili**

Ecco un elenco dei pin disponibili sulla scheda ESP32 per questo progetto.

.. list-table::
    :widths: 5 20 

    * - Pin Disponibili
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**Schema**

.. image:: ../../img/circuit/circuit_4.1_motor_l293d.png

**Collegamenti**

.. note:: 

    Poiché il motore richiede una corrente relativamente alta, è necessario prima inserire la batteria e poi spostare l'interruttore sulla scheda di espansione in posizione ON per attivare l'alimentazione della batteria.

.. image:: ../../img/wiring/4.1_motor_l293d_bb.png

**Codice**

.. note::

    * Apri il file ``4.1_motor_turn.py`` situato nel percorso ``esp32-starter-kit-main\micropython\codes``, oppure copia e incolla il codice in Thonny. Poi clicca su "Run Current Script" o premi F5 per eseguirlo.
    * Assicurati di selezionare l'interprete "MicroPython (ESP32).COMxx" nell'angolo in basso a destra. 

.. code-block:: python

    import machine
    import time

    # Crea oggetti Pin che rappresentano i pin di controllo del motore e impostali in modalità output
    motor1A = machine.Pin(13, machine.Pin.OUT)
    motor2A = machine.Pin(14, machine.Pin.OUT)

    # Definisci una funzione per ruotare il motore in senso orario
    def clockwise():
        motor1A.value(1)
        motor2A.value(0)

    # Definisci una funzione per ruotare il motore in senso antiorario
    def anticlockwise():
        motor1A.value(0)
        motor2A.value(1)

    # Definisci una funzione per fermare il motore
    def stop():
        motor1A.value(0)
        motor2A.value(0)

    # Entra in un loop infinito

    try:
        while True:
            clockwise() # Ruota il motore in senso orario
            time.sleep(1) # Pausa di 1 secondo
            anticlockwise() # Ruota il motore in senso antiorario
            time.sleep(1)
            stop() # Ferma il motore
            time.sleep(2)

    except KeyboardInterrupt:
        stop()  # Ferma il motore quando viene rilevato un KeyboardInterrupt


Durante l'esecuzione dello script, vedrai il motore alternare la rotazione in senso orario e antiorario ogni secondo.

**Per Saperne di Più**

Oltre a far ruotare semplicemente il motore in senso orario e antiorario, puoi anche controllare la velocità di rotazione del motore utilizzando la modulazione di larghezza di impulso (PWM) sul pin di controllo, come mostrato di seguito.

.. note::

    * Apri il file ``4.1_motor_turn_pwm.py`` situato nel percorso ``esp32-starter-kit-main\micropython\codes``, oppure copia e incolla il codice in Thonny. Poi clicca su "Run Current Script" o premi F5 per eseguirlo.
    * Assicurati di selezionare l'interprete "MicroPython (ESP32).COMxx" nell'angolo in basso a destra. 

.. code-block:: python

    from machine import Pin, PWM
    import time

    # Crea oggetti PWM che rappresentano i pin di controllo del motore e imposta la loro frequenza a 1000 Hz
    motor1A = PWM(Pin(13, Pin.OUT))
    motor2A = PWM(Pin(14, Pin.OUT))
    motor1A.freq(500)
    motor2A.freq(500)

    # Entra in un loop infinito
    while True:
        # Ruota il motore in avanti aumentando gradualmente la potenza sul pin motor1A
        for power in range(0, 1023, 20):
            motor1A.duty(power)
            motor2A.duty(0)
            time.sleep(0.1)
        # Diminuisce la potenza sul pin motor1A
        for power in range(1023, 0, -20):
            motor1A.duty(power)
            motor2A.duty(0)
            time.sleep(0.1)
        # Ruota il motore nella direzione opposta aumentando gradualmente la potenza sul pin motor2A
        for power in range(0, 1023, 20):
            motor1A.duty(0)
            motor2A.duty(power)
            time.sleep(0.1)
        # Diminuisce la potenza sul pin motor2A
        for power in range(1023, 0, -20):
            motor1A.duty(0)
            motor2A.duty(power)
            time.sleep(0.1)


A differenza dello script precedente, qui il motore è controllato da segnali PWM con una frequenza di 1000 Hz, che determina la velocità del motore.

* Il codice utilizza un ciclo ``while True`` per funzionare continuamente. All'interno del ciclo, ci sono quattro cicli ``for`` che controllano i motori in sequenza.
* I primi due cicli ``for`` aumentano e diminuiscono la velocità di IN1 mantenendo IN2 a velocità 0.
* I successivi due cicli ``for`` aumentano e diminuiscono la velocità di IN2 mantenendo IN1 a velocità 0.
* La funzione ``range`` in ogni ciclo ``for`` produce una sequenza di numeri che serve come ciclo di lavoro del segnale PWM. Questo viene quindi inviato a IN1 o IN2 tramite il metodo ``duty``. Il ciclo di lavoro determina la percentuale di tempo in cui il segnale PWM è alto, che a sua volta determina la tensione media applicata al motore e quindi la velocità del motore.
* La funzione ``time.sleep`` viene utilizzata per introdurre un ritardo di 0,1 secondi tra ogni passo della sequenza, permettendo al motore di cambiare velocità gradualmente, piuttosto che passare da una velocità all'altra istantaneamente.
