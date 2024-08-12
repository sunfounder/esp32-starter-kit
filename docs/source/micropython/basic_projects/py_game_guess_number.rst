.. note::

    Ciao, benvenuto nella Community di SunFounder per appassionati di Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime speciali.
    - **Sconti Speciali**: Godi di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Omaggi Festivi**: Partecipa a omaggi e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _py_guess_number:

6.7 Indovina il Numero
==============================

Ti senti fortunato? Vuoi mettere alla prova la tua intuizione e vedere 
se riesci a indovinare il numero giusto? Allora non cercare oltre: 
il gioco "Indovina il Numero" è quello che fa per te!

Con questo progetto, puoi giocare a un divertente e appassionante gioco di fortuna.

Usando un telecomando IR, i giocatori inseriscono numeri tra 0 e 99 cercando 
di indovinare il numero fortunato generato casualmente. 
Il sistema visualizza il numero inserito dal giocatore su uno schermo LCD, 
insieme a suggerimenti sul limite superiore e inferiore per aiutare il giocatore 
ad avvicinarsi alla risposta giusta. Con ogni tentativo, i giocatori si avvicinano 
sempre di più al numero fortunato, fino a quando qualcuno azzecca il numero e vince il gioco!

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
    *   - :ref:`cpn_receiver`
        - |link_receiver_buy|
    *   - :ref:`cpn_lcd`
        - |link_i2clcd1602_buy|


**Schema Elettrico**

.. image:: ../../img/circuit/circuit_6.7_guess_number.png

**Cablaggio**

.. image:: ../../img/wiring/6.7_guess_receiver_bb.png
    :width: 800

**Codice**

.. note::

    * Apri il file ``6.7_game_guess_number.py`` situato nel percorso ``esp32-starter-kit-main\micropython\codes``, oppure copia e incolla il codice in Thonny. Poi, clicca su "Esegui Script Corrente" o premi F5 per eseguirlo.
    * Le librerie ``lcd1602.py`` e ``ir_rx`` sono utilizzate qui; verifica se sono caricate su ESP32. Consulta la sezione :ref:`add_libraries_py` per un tutorial.

.. code-block:: python

    from lcd1602 import LCD
    import machine
    import time
    import urandom
    from machine import Pin
    from ir_rx.print_error import print_error
    from ir_rx.nec import NEC_8

    # Configurazione del ricevitore IR
    pin_ir = Pin(14, Pin.IN)

    # Inizializza le variabili del gioco
    lower = 0
    upper = 99
    pointValue = int(urandom.uniform(lower, upper))
    count = 0

    # Inizializza il display LCD1602
    lcd = LCD()

    # Inizializza un nuovo valore casuale per il gioco
    def init_new_value():
        global pointValue, upper, lower, count
        pointValue = int(urandom.uniform(lower, upper))
        print(pointValue)
        upper = 99
        lower = 0
        count = 0
        return False

    # Mostra messaggi sul display LCD in base allo stato del gioco
    def lcd_show(result):
        global count
        lcd.clear()
        if result == True: 
            string = "GAME OVER!\n"
            string += "Point is " + str(pointValue)
        else: 
            string = "Enter number: " + str(count) + "\n"
            string += str(lower) + " < Point < " + str(upper)
        lcd.message(string)
        return

    # Elabora il numero inserito e aggiorna lo stato del gioco
    def number_processing():
        global upper, count, lower
        if count > pointValue:
            if count < upper:
                upper = count
        elif count < pointValue:
            if count > lower:
                lower = count
        elif count == pointValue:
            return True
        count = 0
        return False

    # Elabora gli input dei tasti del telecomando IR
    def process_key(key):
        global count, lower, upper, pointValue, result
        if key == "Power":
            init_new_value()
            lcd_show(False)
        elif key == "+":
            result = number_processing()
            lcd_show(result)
            if result:
                time.sleep(5)
                init_new_value()
                lcd_show(False)
            else:
                lcd_show(False)
        elif key.isdigit():
            count = count * 10 + int(key) if count * 10 + int(key) <= 99 else count
            lcd_show(False)
    # Decodifica i dati ricevuti e restituisce il nome del tasto corrispondente
    def decodeKeyValue(data):       
        if data == 0x16:
            return "0"
        if data == 0x0C:
            return "1"
        if data == 0x18:
            return "2"
        if data == 0x5E:
            return "3"
        if data == 0x08:
            return "4"
        if data == 0x1C:
            return "5"
        if data == 0x5A:
            return "6"
        if data == 0x42:
            return "7"
        if data == 0x52:
            return "8"
        if data == 0x4A:
            return "9"
        if data == 0x09:
            return "+"
        if data == 0x15:
            return "-"
        if data == 0x7:
            return "EQ"
        if data == 0x0D:
            return "U/SD"
        if data == 0x19:
            return "CYCLE"
        if data == 0x44:
            return "PLAY/PAUSE"
        if data == 0x43:
            return "FORWARD"
        if data == 0x40:
            return "BACKWARD"
        if data == 0x45:
            return "POWER"
        if data == 0x47:
            return "MUTE"
        if data == 0x46:
            return "MODE"
        return "ERROR"

    def callback(data, addr, ctrl):
        if data < 0:
            pass
        else:
            key = decodeKeyValue(data)
            if key != "ERROR":
                process_key(key)

    # Inizializza l'oggetto ricevitore IR con la funzione di callback
    ir = NEC_8(pin_ir, callback)

    # ir.error_function(print_error)

    # Inizializza il gioco con un nuovo valore casuale
    init_new_value()

    # Mostra lo stato iniziale del gioco sul LCD
    lcd_show(False)

    try:
        while True:
            pass
    except KeyboardInterrupt:
        ir.close()



* Quando il codice viene eseguito, viene generato un numero segreto che non viene mostrato sul LCD, e quello che devi fare è indovinarlo. 
* Premi il numero che hai indovinato sul telecomando, quindi premi il tasto ``+`` per confermare.
* Contemporaneamente, l'intervallo mostrato sull'I2C LCD1602 si ridurrà e dovrai premere il numero corretto basandoti su questo nuovo intervallo.
* Se indovini il numero fortunato, comparirà ``GAME OVER!``.

.. note:: 

    Se il codice e il cablaggio sono corretti, ma il LCD non mostra comunque alcun contenuto, puoi regolare il potenziometro sul retro per aumentare il contrasto.

**Come funziona?**

Di seguito è riportata un'analisi dettagliata di una parte del codice.

#. Inizializza le variabili del gioco.

    .. code-block:: python
    
        lower = 0
        upper = 99
        pointValue = int(urandom.uniform(lower, upper))
        count = 0


    * ``lower`` e ``upper`` sono i limiti per il numero segreto.
    * Il numero segreto (``pointValue``) è generato casualmente tra i limiti ``lower`` e ``upper``.
    * L'attuale tentativo dell'utente (``count``).

#. Questa funzione reimposta i valori del gioco e genera un nuovo numero segreto.

    .. code-block:: python
    
        def init_new_value():
            global pointValue, upper, lower, count
            pointValue = int(urandom.uniform(lower, upper))
            print(pointValue)
            upper = 99
            lower = 0
            count = 0
            return False

#. Questa funzione mostra lo stato attuale del gioco sullo schermo LCD.

    .. code-block:: python

        def lcd_show(result):
            global count
            lcd.clear()
            if result == True: 
                string = "GAME OVER!\n"
                string += "Point is " + str(pointValue)
            else: 
                string = "Enter number: " + str(count) + "\n"
                string += str(lower) + " < Point < " + str(upper)
            lcd.message(string)
            return

    * Se il gioco è finito (``result=True``), viene mostrato ``GAME OVER!`` e il numero segreto.
    * Altrimenti, viene mostrato il tentativo corrente (``count``) e l'intervallo di tentativi attuale (``lower`` a ``upper``).

#. Questa funzione elabora il tentativo corrente dell'utente (``count``) e aggiorna l'intervallo dei tentativi.

    .. code-block:: python

        def number_processing():
            global upper, count, lower
            if count > pointValue:
                if count < upper:
                    upper = count
            elif count < pointValue:
                if count > lower:
                    lower = count
            elif count == pointValue:
                return True
            count = 0
            return False
    
    * Se il tentativo corrente (``count``) è superiore al numero segreto, il limite superiore viene aggiornato.
    * Se il tentativo corrente (``count``) è inferiore al numero segreto, il limite inferiore viene aggiornato.
    * Se il tentativo corrente (``count``) è uguale al numero segreto, la funzione restituisce ``True`` (gioco finito).

#. Questa funzione elabora gli eventi di pressione dei tasti ricevuti dal telecomando IR.

    .. code-block:: python

        def process_key(key):
            global count, lower, upper, pointValue, result
            if key == "Power":
                init_new_value()
                lcd_show(False)
            elif key == "+":
                result = number_processing()
                lcd_show(result)
                if result:
                    time.sleep(5)
                    init_new_value()
                    lcd_show(False)
                else:
                    lcd_show(False)
            elif key.isdigit():
                count = count * 10 + int(key) if count * 10 + int(key) <= 99 else count
                lcd_show(False)

    * Se viene premuto il tasto ``Power``, il gioco viene reimpostato.
    * Se viene premuto il tasto ``+``, il tentativo corrente (``count``) viene elaborato e lo stato del gioco viene aggiornato.
    * Se viene premuto un tasto numerico, il tentativo corrente (``count``) viene aggiornato con la nuova cifra.

#. Questa funzione di callback viene attivata quando il ricevitore IR riceve

    .. code-block:: python

        def callback(data, addr, ctrl):
            if data < 0:
                pass
            else:
                key = decodeKeyValue(data)
                if key != "ERROR":
                    process_key(key)
