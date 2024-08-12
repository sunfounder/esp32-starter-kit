.. note::

    Ciao, benvenuto nella community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché Unirsi?**

    - **Supporto Esperti**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara & Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa ai giveaway e alle promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _py_servo:

4.3 Servo in Movimento
=============================

Un Servo è un dispositivo basato sulla posizione noto per la sua capacità di mantenere angoli specifici e fornire una rotazione precisa. Questo lo rende molto desiderabile per i sistemi di controllo che richiedono regolazioni angolari costanti. Non sorprende che i Servo abbiano trovato ampio impiego in giocattoli radiocomandati di fascia alta, dai modelli di aeroplani alle repliche di sottomarini e ai sofisticati robot radiocomandati.

In questa intrigante avventura, ci sfideremo a manipolare il Servo in un modo unico: facendolo oscillare! Questo progetto offre una brillante opportunità per approfondire le dinamiche dei Servo, affinare le tue abilità nei sistemi di controllo precisi e acquisire una comprensione più profonda del loro funzionamento.

Sei pronto a far danzare il Servo al tuo ritmo? Iniziamo questo emozionante viaggio!

**Componenti Necessari**

In questo progetto, abbiamo bisogno dei seguenti componenti. 

È sicuramente conveniente acquistare un kit completo, ecco il link: 

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - OGGETTI IN QUESTO KIT
        - LINK
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

Puoi anche acquistarli separatamente dai link qui sotto.

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
    *   - :ref:`cpn_servo`
        - |link_servo_buy|

**Pin Disponibili**

Ecco un elenco dei pin disponibili sulla scheda ESP32 per questo progetto.

.. list-table::
    :widths: 5 20 

    * - Pin Disponibili
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**Schema**

.. image:: ../../img/circuit/circuit_4.3_servo.png

**Cablaggio**

* Il filo arancione è il segnale ed è collegato a IO25.
* Il filo rosso è VCC ed è collegato a 5V.
* Il filo marrone è GND ed è collegato a GND.

.. image:: ../../img/wiring/4.3_swinging_servo_bb.png

**Codice**

.. note::

    * Apri il file ``4.3_swinging_servo.py`` situato nel percorso ``esp32-starter-kit-main\micropython\codes``, oppure copia e incolla il codice in Thonny. Successivamente, fai clic su "Esegui lo script corrente" o premi F5 per eseguirlo.
    * Assicurati di selezionare l'interprete "MicroPython (ESP32).COMxx" nell'angolo in basso a destra. 




.. code-block:: python

    import machine
    import time

    # Crea un oggetto PWM (Pulse Width Modulation) sul pin 25
    servo = machine.PWM(machine.Pin(25))

    # Imposta la frequenza del segnale PWM a 50 Hz, comune per i servomotori
    servo.freq(50)

    # Definisci una funzione per la mappatura degli intervalli
    def interval_mapping(x, in_min, in_max, out_min, out_max):
        return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

    # Definisci una funzione per impostare un angolo al servo
    def servo_write(pin, angle):
        
        pulse_width = interval_mapping(angle, 0, 180, 0.5, 2.5) # Calcola la larghezza dell'impulso
        duty = int(interval_mapping(pulse_width, 0, 20, 0, 1023))     # Calcola il ciclo di lavoro
        pin.duty(duty) # Imposta il ciclo di lavoro del segnale PWM

    # Create an infinite loop
    while True:
        # Loop through angles from 0 to 180 degrees
        for angle in range(180):
            servo_write(servo, angle)
            time.sleep_ms(20)

        # Loop through angles from 180 to 0 degrees in reverse
        for angle in range(180, -1, -1):
            servo_write(servo, angle)
            time.sleep_ms(20)


Quando esegui questo codice, il servo si muoverà continuamente avanti e indietro tra 0 e 180 gradi.


**Come funziona?**


#. Importa le librerie necessarie: ``machine`` per controllare l'hardware del microcontrollore e ``time`` per aggiungere ritardi.


    .. code-block:: python

        import machine
        import time

#. Crea un oggetto PWM (Pulse Width Modulation) sul pin 25 e imposta la sua frequenza a 50 Hz, comune per i servomotori.

    .. code-block:: python

        # Crea un oggetto PWM (Pulse Width Modulation) sul pin 25
        servo = machine.PWM(machine.Pin(25))

        # Imposta la frequenza del segnale PWM a 50 Hz, comune per i servomotori
        servo.freq(50)

#. Definisci una funzione ``interval_mapping`` per mappare i valori da un intervallo a un altro. Questa sarà utilizzata per convertire l'angolo nella corrispondente larghezza dell'impulso e ciclo di lavoro.

    .. code-block:: python

        def interval_mapping(x, in_min, in_max, out_min, out_max):
            return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min

#. Definisci una funzione ``servo_write`` che prende un oggetto PWM e un angolo come input. Calcola la larghezza dell'impulso e il ciclo di lavoro in base all'angolo dato, e quindi imposta l'uscita PWM di conseguenza.

    .. code-block:: python
        
        def servo_write(pin, angolo):
            
            pulse_width = interval_mapping(angolo, 0, 180, 0.5, 2.5) # Calcola la larghezza dell'impulso
            duty = int(interval_mapping(pulse_width, 0, 20, 0, 1023))     # Calcola il ciclo di lavoro
            pin.duty(duty) # Imposta il ciclo di lavoro del segnale PWM

    * In questa funzione, viene chiamata ``interval_mapping()`` per mappare l'intervallo di angoli 0 ~ 180 all'intervallo di larghezza dell'impulso 0,5 ~ 2,5ms.
    * Perché è 0,5~2,5? Questo è determinato dal modo di funzionamento del :ref:`Servo`. 
    * Successivamente, converti la larghezza dell'impulso da periodo a duty.
    * Poiché ``duty()`` non può avere decimali quando utilizzato (il valore non può essere di tipo float), abbiamo utilizzato ``int()`` per forzare il duty ad essere convertito in un tipo int.

#. Crea un ciclo infinito con due loop annidati.

    .. code-block:: python

        while True:
            # Loop through angles from 0 to 180 degrees
            for angle in range(180):
                servo_write(servo, angle)
                time.sleep_ms(20)

            # Loop through angles from 180 to 0 degrees in reverse
            for angle in range(180, -1, -1):
                servo_write(servo, angle)
                time.sleep_ms(20)
    
    * Il primo loop annidato itera attraverso gli angoli da 0 a 180 gradi, e il secondo loop annidato itera attraverso gli angoli da 180 a 0 gradi al contrario.
    * In ogni iterazione, la funzione ``servo_write`` viene chiamata con l'angolo corrente e viene aggiunto un ritardo di 20 millisecondi.
