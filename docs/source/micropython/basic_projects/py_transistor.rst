.. note::

    Ciao, benvenuto nella community SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché Unirsi?**

    - **Supporto Esperti**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara & Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa ai giveaway e alle promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _py_transistor:

5.6 Due Tipi di Transistori
==========================================
Questo kit è dotato di due tipi di transistori, S8550 e S8050, il primo è PNP e il secondo è NPN. Sono molto simili nell'aspetto, quindi è necessario controllare attentamente le loro etichette.
Quando un segnale ad alto livello passa attraverso un transistor NPN, esso si attiva. Ma un PNP richiede un segnale a basso livello per funzionare. Entrambi i tipi di transistor sono frequentemente utilizzati per interruttori senza contatto, proprio come in questo esperimento.

Utilizziamo LED e pulsante per comprendere come usare un transistor!

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
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_transistor`
        - |link_transistor_buy|

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


**Modo di Collegare il Transistor NPN (S8050)**

.. image:: ../../img/circuit/circuit_5.6_S8050.png

In questo circuito, quando il pulsante viene premuto, IO14 è alto.

Programmando IO26 per emettere un segnale **alto**, dopo un resistore di limitazione di corrente da 1k (per proteggere il transistor), l'S8050 (transistor NPN) è abilitato a condurre, permettendo così l'accensione del LED.

.. image:: ../../img/wiring/5.6_s8050_bb.png

**Modo di Collegare il Transistor PNP (S8550)**

.. image:: ../../img/circuit/circuit_5.6_S8550.png

In questo circuito, IO14 è basso di default e cambierà in alto quando il pulsante viene premuto.

Programmando IO26 per emettere un segnale **basso**, dopo un resistore di limitazione di corrente da 1k (per proteggere il transistor), l'S8550 (transistor PNP) è abilitato a condurre, permettendo così l'accensione del LED.

L'unica differenza che noterai tra questo circuito e il precedente è che nel circuito precedente il catodo del LED è collegato al **collettore** dell'**S8050 (transistor NPN)**, mentre in questo è collegato all'**emettitore** dell'**S8550 (transistor PNP)**.

.. image:: ../../img/wiring/5.6_s8550_bb.png

**Codice**

.. note::

    * Apri il file ``5.6_transistor.py`` situato nel percorso ``esp32-starter-kit-main\micropython\codes``, oppure copia e incolla il codice in Thonny. Successivamente, fai clic su "Esegui lo script corrente" o premi F5 per eseguirlo.
    * Assicurati di selezionare l'interprete "MicroPython (ESP32).COMxx" nell'angolo in basso a destra.

.. code-block:: python

    import machine 

    button = machine.Pin(14, machine.Pin.IN)   # Pulsante
    led = machine.Pin(26, machine.Pin.OUT)  # LED

    # Avvia un loop infinito
    while True:  
        # Leggi il valore corrente dell'oggetto 'button' (0 o 1) e memorizzalo nella variabile 'button_status'
        button_status = button.value() 
        # Se il pulsante è premuto (il valore è 1)
        if button_status == 1: 
            led.value(1) # Accendi il LED
        # Se il pulsante non è premuto (il valore è 0)
        else:       
            led.value(0)            # Spegni il LED


Entrambi i tipi di transistor possono essere controllati utilizzando lo stesso codice. 
Quando premiamo il pulsante, l'ESP32 invierà un segnale ad alto livello al transistor; 
quando lo rilasciamo, invierà un segnale a basso livello.

* Il circuito che utilizza l'S8050 (transistor NPN) si accenderà quando il pulsante viene premuto, indicando che è in uno stato di conduzione ad alto livello;
* Il circuito che utilizza l'S8550 (transistor PNP) si accenderà quando il pulsante viene rilasciato, indicando che è in uno stato di conduzione a basso livello.
