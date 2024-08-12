.. note::

    Ciao, benvenuto nella comunità SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 con altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni per le festività.

    👉 Pronto per esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

.. _py_joystick:

5.11 Attivare il Joystick
================================

Se giochi molto ai videogiochi, dovresti essere molto familiare con il joystick. 
Viene solitamente utilizzato per muovere il personaggio, ruotare lo schermo, ecc.

Il principio che permette al joystick di consentire al computer di leggere le 
nostre azioni è molto semplice. Può essere pensato come composto da due potenziometri 
perpendicolari tra loro. Questi due potenziometri misurano il valore analogico del 
joystick verticalmente e orizzontalmente, risultando in un valore (x,y) in un sistema 
di coordinate ortogonale.

Il joystick di questo kit ha anche un input digitale, che viene attivato quando il 
joystick viene premuto.

**Componenti richiesti**

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_joystick`
        - |link_joystick_buy|

* **Pin disponibili**

    Ecco un elenco di pin disponibili sulla scheda ESP32 per questo progetto.

    .. list-table::
        :widths: 5 15

        *   - Per ingresso analogico
            - IO14, IO25, I35, I34, I39, I36
        *   - Per ingresso digitale
            - IO13, IO14, IO27, IO26, IO25, IO33, IO4, IO18, IO19, IO21, IO22, IO23

* **Pin di strap (Ingresso)**

    I pin di strap sono un set speciale di pin che vengono utilizzati per determinare specifiche modalità di avvio durante l'avvio del dispositivo (ad esempio, il reset di accensione).

        
    .. list-table::
        :widths: 5 15

        *   - Pin di strap
            - IO5, IO0, IO2, IO12, IO15 
    
    In generale, **non è raccomandato utilizzarli come pin di ingresso**. Se desideri utilizzare questi pin, considera il potenziale impatto sul processo di avvio. Per ulteriori dettagli, fai riferimento alla sezione :ref:`esp32_strapping`.

**Schema**

.. image:: ../../img/circuit/circuit_5.11_joystick.png

Il pin SW (asse Z) è collegato a IO33, che ha una resistenza pull-up interna da 4,7K. Pertanto, quando il pulsante SW non è premuto, uscirà un livello alto. Quando il pulsante viene premuto, uscirà un livello basso.

I34 e I35 cambieranno i loro valori man mano che si manipola il joystick. L'intervallo di valori è da 0 a 4095.

**Collegamenti**

.. image:: ../../img/wiring/5.11_joystick_bb.png

**Codice**

.. note::

    * Apri il file ``5.11_joystick.py`` situato nel percorso ``esp32-starter-kit-main\micropython\codes``, oppure copia e incolla il codice in Thonny. Quindi, fai clic su "Esegui script corrente" o premi F5 per eseguirlo.
    * Assicurati di selezionare l'interprete "MicroPython (ESP32).COMxx" nell'angolo in basso a destra.

.. code-block:: python

    from machine import ADC,Pin
    import time

    xAxis = ADC(Pin(34, Pin.IN)) # crea un oggetto ADC che agisce su un pin      
    xAxis.atten(xAxis.ATTN_11DB)
    yAxis = ADC(Pin(35, Pin.IN)) # crea un oggetto ADC che agisce su un pin      
    yAxis.atten(yAxis.ATTN_11DB)
    button = Pin(33, Pin.IN, Pin.PULL_UP)

    while True:
        xValue = xAxis.read()  # legge un valore analogico grezzo nell'intervallo 0-4095
        yValue = yAxis.read()  # legge un valore analogico grezzo nell'intervallo 0-4095
        btnValue = button.value()
        print(f"X:{xValue}, Y:{yValue}, Button:{btnValue}")
        time.sleep(0.1)

Quando il programma è in esecuzione, la Shell stampa i valori di x, y e del pulsante del joystick.

.. code-block:: 

    X:1921, Y:1775, Button:0
    X:1921, Y:1775, Button:0
    X:1923, Y:1775, Button:0
    X:1924, Y:1776, Button:0
    X:1926, Y:1777, Button:0
    X:1925, Y:1776, Button:0
    X:1924, Y:1776, Button:0


* I valori dell'asse x e dell'asse y sono valori analogici che variano da 0 a 4095.
* Il pulsante è un valore digitale con uno stato di 1 (rilasciato) o 0 (premuto).

    .. image:: img/joystick_direction.png
