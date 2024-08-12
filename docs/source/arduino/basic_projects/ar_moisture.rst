.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e alle anteprime.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_moisture:

5.9 Misura dell'Umidità del Suolo
========================================
Questo sensore capacitivo di umidità del suolo è diverso dalla maggior parte dei sensori resistivi presenti sul mercato, utilizzando il principio dell'induzione capacitiva per rilevare l'umidità del suolo.

Leggendo visivamente i valori dal sensore di umidità del suolo, possiamo raccogliere informazioni sul livello di umidità nel terreno. Queste informazioni sono utili per diverse applicazioni, come i sistemi di irrigazione automatica, il monitoraggio della salute delle piante o i progetti di rilevamento ambientale.

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|

**Pin Disponibili**

* **Pin Disponibili**

    Ecco un elenco di pin disponibili sulla scheda ESP32 per questo progetto.

    .. list-table::
        :widths: 5 15

        *   - Pin Disponibili
            - IO14, IO25, I35, I34, I39, I36


* **Pin di Strapping**

    I seguenti pin sono pin di strapping, che influenzano il processo di avvio dell'ESP32 durante l'accensione o il reset. Tuttavia, una volta che l'ESP32 è avviato correttamente, possono essere utilizzati come pin normali.

    .. list-table::
        :widths: 5 15

        *   - Pin di Strapping
            - IO0, IO12

**Schema Elettrico**

.. image:: ../../img/circuit/circuit_5.9_soil_moisture.png

Inserendo il modulo nel terreno e annaffiandolo, il valore letto su I35 diminuirà.

**Cablaggio**

.. image:: ../../img/wiring/5.9_moisture_bb.png

**Codice**

.. note::

    * Apri il file ``5.9_moisture.ino`` nel percorso ``esp32-starter-kit-main\c\codes\5.9_moisture``.
    * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta appropriata, fai clic sul pulsante **Upload**.
    * :ref:`unknown_com_port`
    
    
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/431302c2-3579-4be6-8142-c91d28757004/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
Ricorda di impostare la velocità di comunicazione seriale a 115200 baud.

Una volta che il codice è stato caricato con successo, il monitor seriale stamperà il valore dell'umidità del suolo.

Inserendo il modulo nel terreno e annaffiandolo, il valore del sensore di umidità del suolo diminuirà.
