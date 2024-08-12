.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e alle anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_transistor:

5.6 Due Tipi di Transistor
==========================================
Questo kit è dotato di due tipi di transistor, l'S8550 e l'S8050; il primo è PNP, mentre il secondo è NPN. Sono molto simili tra loro, quindi dobbiamo controllare attentamente le etichette per distinguerli.
Quando un segnale di livello alto attraversa un transistor NPN, questo si attiva. Tuttavia, un transistor PNP necessita di un segnale di livello basso per funzionare. Entrambi i tipi di transistor sono spesso utilizzati come interruttori senza contatto, proprio come in questo esperimento.

Utilizziamo un LED e un pulsante per capire come utilizzare un transistor!

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


**Come collegare il transistor NPN (S8050)**

.. image:: ../../img/circuit/circuit_5.6_S8050.png

In questo circuito, quando si preme il pulsante, IO14 è alto.

Programmare IO26 per emettere un segnale **alto**, dopo un resistore limitatore di corrente da 1k (per proteggere il transistor), permette all'S8050 (transistor NPN) di condurre, accendendo così il LED.


.. image:: ../../img/wiring/5.6_s8050_bb.png

**Come collegare il transistor PNP (S8550)**

.. image:: ../../img/circuit/circuit_5.6_S8550.png

In questo circuito, IO14 è basso per impostazione predefinita e passerà a alto quando si preme il pulsante.

Programmare IO26 per emettere un segnale **basso**, dopo un resistore limitatore di corrente da 1k (per proteggere il transistor), permette all'S8550 (transistor PNP) di condurre, accendendo così il LED.

L'unica differenza che noterai tra questo circuito e il precedente è che nel circuito precedente il catodo del LED è collegato al **collettore** dell'**S8050 (transistor NPN)**, mentre in questo è collegato all'**emettitore** dell'**S8550 (transistor PNP)**.

.. image:: ../../img/wiring/5.6_s8550_bb.png

**Codice**

.. note::

    * Puoi aprire il file ``5.6_transistor.ino`` nel percorso ``esp32-starter-kit-main\c\codes\5.6_transistor``. 
    * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta appropriata, fai clic sul pulsante **Upload**.
    * :ref:`unknown_com_port`
   
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/3ab778b4-642d-4a5d-8b71-05bc089389e5/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Due tipi di transistor possono essere controllati utilizzando lo stesso codice. 
Quando premiamo il pulsante, l'ESP32 invierà un segnale di livello alto al transistor; 
quando lo rilasciamo, invierà un segnale di livello basso.

* Il circuito che utilizza l'S8050 (transistor NPN) si accenderà quando si preme il pulsante, indicando che è in uno stato di conduzione a livello alto;
* Il circuito che utilizza l'S8550 (transistor PNP) si accenderà quando si rilascia il pulsante, indicando che è in uno stato di conduzione a livello basso.
