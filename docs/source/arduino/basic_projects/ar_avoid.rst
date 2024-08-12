.. note::

    Ciao, benvenuto nella Community di Appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirsi a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni l'accesso anticipato a nuovi annunci di prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_ir_obstacle:

5.3 Rilevamento Ostacoli
=============================

Questo modulo è comunemente installato su automobili e robot per rilevare la presenza di ostacoli davanti. È anche ampiamente utilizzato in dispositivi portatili, rubinetti e così via.

**Componenti necessari**

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_avoid`
        - |link_avoid_buy|

**Pin Disponibili**

* **Pin Disponibili**

    Ecco un elenco di pin disponibili sulla scheda ESP32 per questo progetto.

    .. list-table::
        :widths: 5 20

        *   - Pin Disponibili
            - IO13, IO14, IO27, IO26, IO25, IO33, I35, I34, I39, I36, IO4, IO18, IO19, IO21, IO22, IO23

* **Pin di Strapping (Input)**

    I pin di strapping sono un set speciale di pin utilizzati per determinare modalità di avvio specifiche durante l'avvio del dispositivo 
    (cioè, reset all'accensione).
        
    .. list-table::
        :widths: 5 15

        *   - Pin di Strapping
            - IO5, IO0, IO2, IO12, IO15 
    
    In generale, **non è consigliabile utilizzarli come pin di input**. Se desideri utilizzare questi pin, considera l'impatto potenziale sul processo di avvio. Per maggiori dettagli, consulta la sezione :ref:`esp32_strapping`.

**Schema Elettrico**

.. image:: ../../img/circuit/circuit_5.3_avoid.png

Quando il modulo di evitamento ostacoli non rileva alcun ostacolo, IO14 ritorna a livello alto. Tuttavia, quando rileva un ostacolo, ritorna a livello basso. Puoi regolare il potenziometro blu per modificare la distanza di rilevamento di questo modulo.

**Cablaggio**

.. image:: ../../img/wiring/5.3_avoid_bb.png

**Codice**

.. note::

    * Puoi aprire il file ``5.3.detect_the_obstacle.ino`` nel percorso ``esp32-starter-kit-main\c\codes\5.3.detect_the_obstacle``. 
    * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta appropriata, clicca sul pulsante **Carica**.
    * :ref:`unknown_com_port`

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/b0f22caa-3c77-4dc1-9a33-20ff23d04a5e/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Imposta la velocità di comunicazione seriale a 115200 baud.
Dopo che il codice è stato caricato con successo, se il modulo di evitamento ostacoli IR rileva qualcosa che blocca davanti a sé, sul monitor seriale apparirà "0", altrimenti verrà visualizzato "1".
