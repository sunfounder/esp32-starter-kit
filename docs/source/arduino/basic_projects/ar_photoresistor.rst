.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_photoresistor:

5.7 Rileva la Luce
===========================

Il fotorilevatore è un dispositivo comunemente utilizzato per gli ingressi analogici, simile a un potenziometro. Il suo valore di resistenza cambia in base all'intensità della luce che riceve. Quando esposto a luce intensa, la resistenza del fotorilevatore diminuisce, mentre con una minore intensità luminosa, la resistenza aumenta.

Leggendo il valore del fotorilevatore, possiamo ottenere informazioni sulle condizioni di illuminazione ambientale. Queste informazioni possono essere utilizzate per compiti come il controllo della luminosità di un LED, la regolazione della sensibilità di un sensore o l'implementazione di azioni dipendenti dalla luce in un progetto.

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
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

**Pin Disponibili**

* **Pin Disponibili**

    Ecco un elenco dei pin disponibili sulla scheda ESP32 per questo progetto.

    .. list-table::
        :widths: 5 15

        *   - Pin Disponibili
            - IO14, IO25, I35, I34, I39, I36


* **Pin Strapping**

    I seguenti pin sono pin strapping, che influenzano il processo di avvio dell'ESP32 durante l'accensione o il reset. Tuttavia, una volta che l'ESP32 è stato avviato con successo, possono essere utilizzati come pin normali.

    .. list-table::
        :widths: 5 15

        *   - Pin Strapping
            - IO0, IO12

**Schema**

.. image:: ../../img/circuit/circuit_5.7_photoresistor.png

Con l'aumentare dell'intensità luminosa, la resistenza del fotorilevatore (LDR) diminuisce, comportando una diminuzione del valore letto su I35.

**Cablatura**

.. image:: ../../img/wiring/5.7_photoresistor_bb.png

**Codice**

.. note::

    * Apri il file ``5.7_feel_the_light.ino`` nel percorso ``esp32-starter-kit-main\c\codes\5.7_feel_the_light``.
    * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta appropriata, fai clic sul pulsante **Upload**.
    * :ref:`unknown_com_port`
    
    
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/58b494c7-eef4-4476-af65-4823cef13f90/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Dopo che il codice è stato caricato con successo, il Monitor Seriale stamperà i valori del fotorilevatore da 0 a 4095. 
Maggiore è la luminosità ambientale, maggiore sarà il valore visualizzato nel monitor seriale.

.. note::
    Per l'ESP32, la risoluzione è compresa tra 9 e 12 bit e cambierà la risoluzione hardware dell'ADC. In caso contrario, il valore verrà spostato.

    Il valore predefinito è di 12 bit (intervallo da 0 a 4096) per tutti i chip tranne ESP32S3, dove il valore predefinito è di 13 bit (intervallo da 0 a 8192).

    Puoi aggiungere ``analogReadResolution(10);`` alla funzione ``setup()`` per impostare una risoluzione diversa, come ad esempio ``10``.

