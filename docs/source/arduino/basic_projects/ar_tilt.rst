.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e alle anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_tilt:

5.2 Tilt It！
==========================

Il tilt switch è un dispositivo semplice ma efficace a 2 pin che contiene una sfera metallica al centro. Quando l'interruttore è in posizione verticale, i due pin sono elettricamente collegati, permettendo il passaggio della corrente. Tuttavia, quando l'interruttore è inclinato o si trova ad un certo angolo, la sfera metallica si muove e interrompe la connessione elettrica tra i pin.

In questo progetto, utilizzeremo il tilt switch per controllare l'illuminazione di un LED. Posizionando l'interruttore in modo da attivare l'azione di inclinazione, possiamo accendere e spegnere il LED in base all'orientamento dell'interruttore. 

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

    I seguenti pin hanno resistori di pull-up o pull-down integrati, quindi non sono necessari resistori esterni quando **usati come pin di ingresso**:


    .. list-table::
        :widths: 5 15
        :header-rows: 1

        *   - Pin a Uso Condizionale
            - Descrizione
        *   - IO13, IO15, IO2, IO4
            - La resistenza di pull-up da 47K preimposta il valore su alto.
        *   - IO27, IO26, IO33
            - La resistenza di pull-up da 4.7K preimposta il valore su alto.
        *   - IO32
            - La resistenza di pull-down da 1K preimposta il valore su basso.

* **Pin di Strapping (Ingresso)**

    I pin di strapping sono un insieme speciale di pin utilizzati per determinare specifiche modalità di avvio durante l'accensione del dispositivo (es. reset di accensione).

    
    .. list-table::
        :widths: 5 15

        *   - Pin di Strapping
            - IO5, IO0, IO2, IO12, IO15 
    

    

    In generale, **non è consigliato utilizzarli come pin di ingresso**. Se si desidera utilizzare questi pin, considerare l'impatto potenziale sul processo di avvio. Per maggiori dettagli, fare riferimento alla sezione :ref:`esp32_strapping`.


**Schema**

.. image:: ../../img/circuit/circuit_5.2_tilt.png

Quando il tilt switch è in posizione verticale, IO14 sarà impostato su alto, facendo accendere il LED. Al contrario, quando il tilt switch è inclinato, IO14 sarà impostato su basso, spegnendo il LED.

Lo scopo del resistore da 10K è mantenere uno stato basso stabile per IO14 quando il tilt switch è in posizione inclinata.


**Cablatura**

.. image:: ../../img/wiring/5.2_tilt_switch_bb.png

**Codice**

.. note::

    * Puoi aprire il file ``5.2_tilt_switch.ino`` nel percorso ``esp32-starter-kit-main\c\codes\5.2_tilt_switch``. 
    * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta appropriata, fai clic sul pulsante **Upload**.
    * :ref:`unknown_com_port`

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/5ed2406f-185c-407c-ac29-42036f174a5d/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    


Dopo aver caricato con successo il codice, il LED si accenderà quando l'interruttore è in posizione verticale e si spegnerà quando l'interruttore è inclinato.


