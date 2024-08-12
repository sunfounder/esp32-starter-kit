.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirsi a noi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e alle anteprime.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_flowing_light:

6.2 Luce Scorrevole
=======================

Hai mai desiderato aggiungere un elemento divertente e interattivo al tuo spazio abitativo? 
Questo progetto consiste nella creazione di una luce scorrevole utilizzando una striscia LED WS2812 e un modulo di evitamento ostacoli. 
La luce scorrevole cambia direzione quando viene rilevato un ostacolo, rendendola un'aggiunta entusiasmante alla decorazione della tua casa o del tuo ufficio.

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
    *   - :ref:`cpn_avoid`
        - |link_avoid_buy|
    *   - :ref:`cpn_ws2812`
        - |link_ws2812_buy|

**Schema Elettrico**

.. image:: ../../img/circuit/circuit_6.2_flowing_led.png
    :align: center

La striscia LED WS2812 è composta da una serie di LED individuali che possono essere programmati per visualizzare colori e pattern diversi. 
In questo progetto, la striscia è configurata per mostrare una luce scorrevole che si muove in una determinata direzione e 
cambia direzione quando un ostacolo viene rilevato dal modulo di evitamento ostacoli.


**Cablaggio**

.. image:: ../../img/wiring/6.2_flowing_light_bb.png
    

**Codice**

.. note::

    * Puoi aprire direttamente il file ``6.2_flowing_led.ino`` nel percorso ``esp32-starter-kit-main\c\codes\6.2_flowing_led``.
    * Oppure copia questo codice nell'IDE Arduino.

.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/ff625cb6-2efd-436a-9b59-5dd967191338/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Questo progetto estende la funzionalità del progetto :ref:`ar_rgb_strip` aggiungendo la capacità di visualizzare colori casuali sulla striscia LED. 
Inoltre, è stato incluso un modulo di evitamento ostacoli per cambiare dinamicamente la direzione della luce scorrevole.

