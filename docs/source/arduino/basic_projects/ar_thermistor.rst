.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e alle anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_thermistor:

5.10 Termometro
===========================

Un termistore è un sensore di temperatura che mostra una forte dipendenza dalla temperatura e può essere classificato in due tipi: Coefficiente di Temperatura Negativo (NTC) e Coefficiente di Temperatura Positivo (PTC). La resistenza di un termistore NTC diminuisce con l'aumentare della temperatura, mentre quella di un termistore PTC aumenta con l'aumentare della temperatura.

In questo progetto, utilizzeremo un termistore NTC. Collegando il termistore NTC a un pin di ingresso analogico del microcontrollore ESP32, possiamo misurare la sua resistenza, che è direttamente proporzionale alla temperatura.

Incorporando il termistore NTC e eseguendo i calcoli necessari, possiamo misurare accuratamente la temperatura e visualizzarla sul modulo I2C LCD1602. Questo progetto consente il monitoraggio in tempo reale della temperatura e fornisce un'interfaccia visiva per la visualizzazione della temperatura.

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
    *   - :ref:`cpn_thermistor`
        - |link_thermistor_buy|


**Pin Disponibili**

* **Pin Disponibili**

    Ecco un elenco dei pin disponibili sulla scheda ESP32 per questo progetto.

    .. list-table::
        :widths: 5 15

        *   - Pin Disponibili
            - IO14, IO25, I35, I34, I39, I36


* **Pin di Strapping**

    I seguenti pin sono pin di strapping, che influenzano il processo di avvio dell'ESP32 durante l'accensione o il reset. Tuttavia, una volta avviato correttamente l'ESP32, possono essere utilizzati come pin regolari.

    .. list-table::
        :widths: 5 15

        *   - Pin di Strapping
            - IO0, IO12


**Schema**

.. image:: ../../img/circuit/circuit_5.10_thermistor.png

Quando la temperatura aumenta, la resistenza del termistore diminuisce, causando una diminuzione del valore letto su I35. Inoltre, utilizzando una formula, è possibile convertire il valore analogico in temperatura e stamparlo.

**Cablatura**

.. image:: ../../img/wiring/5.10_thermistor_bb.png


.. note::
    * Il termistore è nero e marcato 103.
    * L'anello colorato della resistenza da 10K ohm è rosso, nero, nero, rosso e marrone.

**Codice**

.. note::

    * Apri il file ``5.10_thermistor.ino`` nel percorso ``esp32-starter-kit-main\c\codes\5.10_thermistor``.
    * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta appropriata, fai clic sul pulsante **Upload**.
    * :ref:`unknown_com_port`

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/d0407e3b-cd1e-4f5e-a7b6-391da394339b/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>


Dopo che il codice è stato caricato con successo, il Serial Monitor stamperà le temperature in Celsius e Fahrenheit.

**Come funziona?**

Ogni termistore ha una resistenza normale. Qui è di 10k ohm, che viene misurata a 25 gradi Celsius. 

Quando la temperatura aumenta, la resistenza del termistore diminuisce. Quindi i dati di tensione vengono convertiti in quantità digitali dall'adattatore A/D. 

La temperatura in Celsius o Fahrenheit viene quindi visualizzata tramite programmazione. 

Ecco la relazione tra resistenza e temperatura:

    **RT =RN expB(1/TK - 1/TN)** 

    * **RT** è la resistenza del termistore NTC quando la temperatura è **TK**. 
    * **RN** è la resistenza del termistore NTC alla temperatura nominale TN. Qui, il valore numerico di RN è 10k. 
    * **TK** è una temperatura Kelvin e l'unità è K. Qui, il valore numerico di **TK** è ``273,15 + gradi Celsius``. 
    * **TN** è una temperatura nominale in Kelvin; anche l'unità è K. Qui, il valore numerico di TN è ``273,15+25``.
    * E **B(beta)**, la costante del materiale del termistore NTC, è anche chiamata indice di sensibilità al calore con un valore numerico ``3950``. 
    * **exp** è l'abbreviazione di esponenziale, e il numero base ``e`` è un numero naturale e uguale a 2,7 circa. 

    Converti questa formula ``TK=1/(ln(RT/RN)/B+1/TN)`` per ottenere la temperatura Kelvin che, sottraendo 273,15, equivale ai gradi Celsius. 

    Questa relazione è una formula empirica. È accurata solo quando la temperatura e la resistenza rientrano nell'intervallo efficace.

**Per Saperne di Più**

Puoi anche visualizzare le temperature calcolate in Celsius e Fahrenheit sull'I2C LCD1602.


.. note::

    * Puoi aprire il file ``5.10_thermistor_lcd.ino`` nel percorso ``euler-kit/arduino/5.10_thermistor_lcd``. 
    * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta appropriata, fai clic sul pulsante **Upload**.
    * :ref:`unknown_com_port`
    * Qui viene utilizzata la libreria ``LiquidCrystal I2C``, che puoi installare dal **Library Manager**.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/93344677-8c5d-41d7-a833-f6365495d344/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

