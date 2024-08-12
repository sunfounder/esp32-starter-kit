.. note::

    Ciao, benvenuto nella community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché Unirsi?**

    - **Supporto Esperti**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara & Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa ai giveaway e alle promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _py_pump:

4.2 Pompa
=======================

In questo interessante progetto, ci addentreremo nel controllo di una pompa d'acqua utilizzando il L293D.

Nel campo del controllo delle pompe d'acqua, le cose sono un po' più semplici rispetto al controllo di altri motori. La bellezza di questo progetto risiede nella sua semplicità: non c'è bisogno di preoccuparsi della direzione di rotazione. Il nostro obiettivo principale è attivare con successo la pompa d'acqua e mantenerla in funzione.

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_pump`
        - \-
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


**Cablatura**

.. note::

    È consigliabile inserire la batteria e poi spostare l'interruttore sulla scheda di espansione in posizione ON per attivare l'alimentazione della batteria.


.. image:: ../../img/wiring/4.2_pump_l293d_bb.png

**Codice**

.. note::

    * Apri il file ``4.2_pumping.py`` situato nel percorso ``esp32-starter-kit-main\micropython\codes``, oppure copia e incolla il codice in Thonny. Successivamente, fai clic su "Esegui lo script corrente" o premi F5 per eseguirlo.
    * Assicurati di selezionare l'interprete "MicroPython (ESP32).COMxx" nell'angolo in basso a destra.


.. code-block:: python

    import machine
    import time

    # Crea oggetti Pin che rappresentano i pin di controllo del motore e impostali in modalità output
    motor1A = machine.Pin(13, machine.Pin.OUT)
    motor2A = machine.Pin(14, machine.Pin.OUT)

    # Definisci una funzione per attivare la pompa
    def rotate():
        motor1A.value(1)
        motor2A.value(0)

    # Definisci una funzione per fermare la pompa
    def stop():
        motor1A.value(0)
        motor2A.value(0)

    try:
        while True:
            rotate()  # Attiva la pompa
            time.sleep(5)  # Pausa di 5 secondi
            stop()  # Ferma la pompa
            time.sleep(2)

    except KeyboardInterrupt:
        stop()  # Ferma la pompa quando viene catturata una KeyboardInterrupt



Durante l'esecuzione dello script, vedrai la pompa in funzione con l'acqua che esce dal tubo, quindi si fermerà per 2 secondi prima di iniziare a funzionare nuovamente.

