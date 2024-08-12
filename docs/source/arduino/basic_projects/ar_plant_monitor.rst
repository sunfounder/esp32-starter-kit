.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_plant_monitor:

6.6 Monitoraggio delle Piante
==================================

Benvenuto nel progetto Monitoraggio delle Piante!

In questo progetto utilizzeremo una scheda ESP32 per creare un sistema che ci aiuti a prenderci cura delle nostre piante. Con questo sistema potremo monitorare la temperatura, l'umidità, l'umidità del suolo e i livelli di luce delle nostre piante, assicurandoci che ricevano le cure e l'attenzione necessarie per prosperare.

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
    *   - :ref:`cpn_dht11`
        - |link_dht11_buy|
    *   - :ref:`cpn_lcd`
        - |link_i2clcd1602_buy|
    *   - :ref:`cpn_pump`
        - \-
    *   - :ref:`cpn_l293d`
        - \-
    *   - :ref:`cpn_button`
        - |link_button_buy|
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_soil_moisture`
        - |link_soil_moisture_buy|

**Schema**

.. image:: ../../img/circuit/circuit_6.8_plant_monitor_l293d.png

Il sistema utilizza un sensore DHT11 per misurare la temperatura e il livello di 
umidità dell'ambiente circostante. Nel frattempo, un modulo di umidità del suolo 
viene utilizzato per misurare il livello di umidità del terreno e una fotoresistenza 
per misurare il livello di luce. Le letture di questi sensori vengono visualizzate 
su uno schermo LCD, e una pompa d'acqua può essere controllata tramite un pulsante 
per innaffiare la pianta quando necessario.

IO32 ha una resistenza di pull-down interna di 1K e, per impostazione predefinita, è a livello logico basso. Quando il pulsante viene premuto, si stabilisce una connessione a VCC (alta tensione), risultando in un livello logico alto su IO32.

**Cablatura**

.. note::

    Qui è consigliato inserire la batteria e poi spostare l'interruttore sulla 
    scheda di espansione in posizione ON per attivare l'alimentazione della batteria.

.. image:: ../../img/wiring/6.8_plant_monitor_l293d_bb.png
    :width: 800

**Codice**

.. note::

    * Puoi aprire il file ``6.6_plant_monitor.ino`` nel percorso ``esp32-starter-kit-main\c\codes\6.6_plant_monitor``.
    * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta appropriata, fai clic sul pulsante **Upload**.
    * :ref:`unknown_com_port`
    * Le librerie ``LiquidCrystal_I2C`` e ``DHT sensor library`` vengono utilizzate qui, puoi installarle dal **Library Manager**.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/52f54c4d-ad8c-49c4-816a-2a55a247d425/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>
    
* Dopo aver caricato il codice, l'I2C LCD1602 visualizzerà alternativamente temperatura e umidità, nonché i valori analogici dell'umidità del suolo e dell'intensità della luce, con un intervallo di 2 secondi.
* La pompa d'acqua è controllata tramite la pressione di un pulsante. Per innaffiare le piante, tieni premuto il pulsante e rilascia per fermare l'irrigazione.

.. note::

    Se il codice e la cablatura sono corretti, ma l'LCD non visualizza ancora alcun contenuto, puoi regolare il potenziometro sul retro per aumentare il contrasto.

