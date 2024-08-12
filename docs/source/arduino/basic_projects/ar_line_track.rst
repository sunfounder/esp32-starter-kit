.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e alle anteprime.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_line_track:

5.4 Rilevamento della Linea
===================================

Il modulo di tracciamento delle linee viene utilizzato per rilevare la presenza di aree nere sul terreno, come ad esempio linee nere tracciate con del nastro isolante.

Il suo emettitore emette una luce infrarossa appropriata verso il suolo, che viene assorbita e debolmente riflessa dalle superfici nere. L'opposto avviene per le superfici bianche. Se viene rilevata la luce riflessa, il terreno è indicato come bianco. Se non viene rilevata, è indicato come nero.

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
    *   - :ref:`cpn_line_track`
        - |link_line_track_buy|

**Pin Disponibili**

* **Pin Disponibili**

    Ecco un elenco di pin disponibili sulla scheda ESP32 per questo progetto.

    .. list-table::
        :widths: 5 20

        *   - Pin Disponibili
            - IO13, IO14, IO27, IO26, IO25, IO33, I35, I34, I39, I36, IO4, IO18, IO19, IO21, IO22, IO23

* **Pin di Strapping (Input)**

    I pin di strapping sono un insieme speciale di pin utilizzati per determinare specifiche modalità di avvio durante l'accensione del dispositivo (ad es., reset all'accensione).

        
    .. list-table::
        :widths: 5 15

        *   - Pin di Strapping
            - IO5, IO0, IO2, IO12, IO15 
    

    

    In generale, **non è consigliato utilizzarli come pin di input**. Se si desidera utilizzare questi pin, considerare il potenziale impatto sul processo di avvio. Per ulteriori dettagli, fare riferimento alla sezione :ref:`esp32_strapping`.


**Schema Elettrico**

.. image:: ../../img/circuit/circuit_5.4_line.png

Quando il modulo di tracciamento delle linee rileva una linea nera, IO14 restituisce un livello alto. Al contrario, quando rileva una linea bianca, IO14 restituisce un livello basso. Puoi regolare il potenziometro blu per modificare la sensibilità del rilevamento di questo modulo.


**Cablaggio**

.. image:: ../../img/wiring/5.4_line_bb.png
    :align: center
    :width: 600

**Codice**

.. note::

    * Puoi aprire il file ``5.4_detect_the_line.ino`` nel percorso ``esp32-starter-kit-main\c\codes\5.4_detect_the_line``. 
    * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta appropriata, fai clic sul pulsante **Upload**.
    * :ref:`unknown_com_port`
   
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/fc7f3fe9-179a-4a3a-acbf-a4014faf3920/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Imposta la velocità di comunicazione seriale a 115200 baud.

Se, dopo che il codice è stato caricato correttamente, il modulo di tracciamento delle linee rileva una linea nera, verrà mostrato "Black" nel Monitor Seriale. In caso contrario, verrà stampato "White".
