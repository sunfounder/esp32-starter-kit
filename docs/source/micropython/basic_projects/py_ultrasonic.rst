.. note::

    Ciao, benvenuto nella community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché Unirsi?**

    - **Supporto da Esperti**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara & Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _py_ultrasonic:

5.12 Misurazione della Distanza
======================================

Il modulo ultrasonico viene utilizzato per la misurazione della distanza o per il rilevamento di oggetti. In questo progetto, programmeremo il modulo per ottenere le distanze dagli ostacoli. Inviando impulsi ultrasonici e misurando il tempo necessario affinché rimbalzino indietro, possiamo calcolare le distanze. Questo ci consente di implementare azioni basate sulla distanza o comportamenti di evitamento degli ostacoli.

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

L'ESP32 invia un set di segnali a onda quadra al pin Trig del sensore ultrasonico ogni 10 secondi. Questo provoca l'emissione di un segnale ultrasonico a 40kHz. Se c'è un ostacolo davanti, le onde ultrasoniche verranno riflesse indietro.

Registrando il tempo che intercorre tra l'invio e la ricezione del segnale, dividendo per 2 e moltiplicando per la velocità della luce, è possibile determinare la distanza dall'ostacolo.

**Cablaggio**

.. image:: ../../img/wiring/5.12_ultrasonic_bb.png

**Codice**

.. note::

    * Apri il file ``5.12_ultrasonic.py`` situato nel percorso ``esp32-starter-kit-main\micropython\codes``, oppure copia e incolla il codice in Thonny. Successivamente, fai clic su "Esegui lo script corrente" o premi F5 per eseguirlo.
    * Assicurati di selezionare l'interprete "MicroPython (ESP32).COMxx" nell'angolo in basso a destra.

.. code-block:: python

    import machine
    import time

    # Definisci i pin di trigger ed echo per il sensore di distanza
    TRIG = machine.Pin(26, machine.Pin.OUT)
    ECHO = machine.Pin(25, machine.Pin.IN)

    # Calcola la distanza utilizzando il sensore ultrasonico
    def distance():
        # Assicurati che il trigger sia inizialmente spento
        TRIG.off()
        time.sleep_us(2)  # Attendi 2 microsecondi

        # Invia un impulso di 10 microsecondi al pin di trigger
        TRIG.on()
        time.sleep_us(10)
        TRIG.off()

        # Attendi che il pin di echo diventi alto
        while not ECHO.value():
            pass

        # Registra il tempo in cui il pin di echo diventa alto
        time1 = time.ticks_us()

        # Attendi che il pin di echo diventi basso
        while ECHO.value():
            pass

        # Registra il tempo in cui il pin di echo diventa basso
        time2 = time.ticks_us()

        # Calcola la differenza di tempo tra i due tempi registrati
        during = time.ticks_diff(time2, time1)

        # Calcola e restituisci la distanza (in cm) utilizzando la velocità del suono (340 m/s)
        return during * 340 / 2 / 10000

    # Misura e stampa continuamente la distanza
    while True:
        dis = distance()
        print('Distance: %.2f' % dis)
        time.sleep_ms(300)  # Attendi 300 millisecondi prima di ripetere


Una volta che il programma è in esecuzione, la Shell stamperà la distanza rilevata dal sensore ultrasonico dall'ostacolo davanti.
