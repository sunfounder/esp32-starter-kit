.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_pir:

5.5 Rileva il Movimento Umano
========================================

Il sensore a infrarossi passivo (sensore PIR) è un sensore comune che può misurare 
la luce infrarossa (IR) emessa dagli oggetti nel suo campo visivo. In poche parole, 
riceve la radiazione infrarossa emessa dal corpo, rilevando così il movimento di 
persone e altri animali. Più specificamente, informa la scheda di controllo principale 
che qualcuno è entrato nella stanza.

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
    *   - :ref:`cpn_pir`
        - |link_pir_buy|

**Pin Disponibili**

* **Pin Disponibili**

    Ecco un elenco dei pin disponibili sulla scheda ESP32 per questo progetto.

    .. list-table::
        :widths: 5 20

        *   - Per Ingresso
            - IO13, IO14, IO27, IO26, IO25, IO33, I35, I34, I39, I36, IO4, IO18, IO19, IO21, IO22, IO23
        *   - Per Uscita
            - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

.. note::

    IO32 non può essere utilizzato **come pin di ingresso** in questo progetto perché è internamente collegato a una resistenza di pull-down da 1K, che imposta il suo valore predefinito a 0.

* **Pin Strapping (Ingresso)**

    I pin strapping sono un insieme speciale di pin utilizzati per determinare specifiche modalità di avvio durante l'accensione del dispositivo (reset).

    
    .. list-table::
        :widths: 5 15

        *   - Pin Strapping
            - IO5, IO0, IO2, IO12, IO15


    

    Generalmente, **non è consigliato utilizzarli come pin di ingresso**. Se desideri utilizzare questi pin, considera il potenziale impatto sul processo di avvio. Per ulteriori dettagli, consulta la sezione :ref:`esp32_strapping`.

**Schema**

.. image:: ../../img/circuit/circuit_5.5_pir.png

Quando il modulo PIR rileva un movimento, IO14 passerà a livello alto e il LED si accenderà. Altrimenti, quando non viene rilevato alcun movimento, IO14 rimarrà basso e il LED si spegnerà.

.. note::
    Il modulo PIR ha due potenziometri: uno regola la sensibilità, l'altro la distanza di rilevamento. Per far funzionare meglio il modulo PIR, è necessario ruotarli entrambi completamente in senso antiorario.

    .. image:: ../../components/img/PIR_TTE.png
        :width: 300
        :align: center

**Cablatura**

.. image:: ../../img/wiring/5.5_pir_bb.png

**Codice**

.. note::

    * Puoi aprire il file ``5.5_pir.ino`` nel percorso ``esp32-starter-kit-main\c\codes\5.5_pir``.
    * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta appropriata, fai clic sul pulsante **Upload**.
    * :ref:`unknown_com_port`

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/8b5f0cc8-b732-4ed2-b68e-bb7d0a73a1b8/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Dopo che il codice è stato caricato correttamente, il LED si accenderà e poi si spegnerà quando il modulo PIR rileva il passaggio di qualcuno.

.. note::
    Il modulo PIR ha due potenziometri: uno regola la sensibilità, l'altro la distanza di rilevamento. Per far funzionare meglio il modulo PIR, è necessario ruotarli entrambi completamente in senso antiorario.

    .. image:: img/pir_back.png

