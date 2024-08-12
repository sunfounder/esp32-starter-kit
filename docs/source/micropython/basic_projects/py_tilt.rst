.. note::

    Ciao, benvenuto nella community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché Unirsi?**

    - **Supporto Esperti**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara & Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa ai giveaway e alle promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _py_tilt:

5.2 Inclinazione！
==========================
L'interruttore a inclinazione è un dispositivo semplice ma efficace a 2 pin che contiene una sfera metallica al centro. Quando l'interruttore è in posizione verticale, i due pin sono elettricamente collegati, consentendo il flusso di corrente. Tuttavia, quando l'interruttore è inclinato o inclinato a un certo angolo, la sfera metallica si sposta e interrompe la connessione elettrica tra i pin.

In questo progetto, utilizzeremo l'interruttore a inclinazione per controllare l'illuminazione di un LED. Posizionando l'interruttore in modo da attivare l'azione di inclinazione, possiamo accendere e spegnere il LED in base all'orientamento dell'interruttore.

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_led`
        - |link_led_buy|
    *   - :ref:`cpn_tilt`
        - \-

**Pin Disponibili**

* **Pin Disponibili**

    Ecco un elenco dei pin disponibili sulla scheda ESP32 per questo progetto.

    .. list-table::
        :widths: 5 20

        *   - Per Ingresso
            - IO14, IO25, I35, I34, I39, I36, IO18, IO19, IO21, IO22, IO23
        *   - Per Uscita
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23
    
* **Pin a Uso Condizionale (Ingresso)**

    I seguenti pin hanno resistori pull-up o pull-down integrati, quindi non sono necessari resistori esterni quando **utilizzati come pin di ingresso**:

    .. list-table::
        :widths: 5 15
        :header-rows: 1

        *   - Pin a Uso Condizionale
            - Descrizione
        *   - IO13, IO15, IO2, IO4
            - Pull-up con resistore da 47K, valore predefinito su alto.
        *   - IO27, IO26, IO33
            - Pull-up con resistore da 4.7K, valore predefinito su alto.
        *   - IO32
            - Pull-down con resistore da 1K, valore predefinito su basso.

* **Pin di Strapping (Ingresso)**

    I pin di strapping sono un insieme speciale di pin utilizzati per determinare modalità di avvio specifiche durante l'avvio del dispositivo 
    (cioè, reset all'accensione).

    .. list-table::
        :widths: 5 15

        *   - Pin di Strapping
            - IO5, IO0, IO2, IO12, IO15
    

    Generalmente, **non è consigliato utilizzarli come pin di ingresso**. Se desideri utilizzare questi pin, considera l'impatto potenziale sul processo di avvio. Per maggiori dettagli, fai riferimento alla sezione :ref:`esp32_strapping`.

**Schema**

.. image:: ../../img/circuit/circuit_5.2_tilt.png

Quando l'interruttore a inclinazione è in posizione verticale, IO14 sarà impostato su alto, facendo accendere il LED. Al contrario, quando l'interruttore è inclinato, IO14 sarà impostato su basso, facendo spegnere il LED.

Lo scopo del resistore da 10K è di mantenere uno stato basso stabile per IO14 quando l'interruttore a inclinazione è in posizione inclinata.

**Cablaggio**

.. image:: ../../img/wiring/5.2_tilt_switch_bb.png

**Codice**

.. note::

    * Apri il file ``5.2_tilt_switch.py`` situato nel percorso ``esp32-starter-kit-main\micropython\codes``, oppure copia e incolla il codice in Thonny. Successivamente, fai clic su "Esegui lo script corrente" o premi F5 per eseguirlo.
    * Assicurati di selezionare l'interprete "MicroPython (ESP32).COMxx" nell'angolo in basso a destra.

.. code-block:: python

    import machine
    import time

    switch = machine.Pin(14, machine.Pin.IN) # Pin interruttore a inclinazione
    led = machine.Pin(26, machine.Pin.OUT) # Pin LED

    while True:
        # Verifica se l'interruttore è inclinato leggendo il suo valore
        if switch.value() == 1:
            # Accendi il LED impostando il suo valore su 1
            led.value(1)
        else:
            # Spegni il LED
            led.value(0)

Quando lo script è in esecuzione, il LED si accenderà quando l'interruttore è in posizione verticale e si spegnerà quando l'interruttore è inclinato.
