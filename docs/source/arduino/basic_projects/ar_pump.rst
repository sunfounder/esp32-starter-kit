.. note::

    Ciao, benvenuto nella Community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato ai nuovi annunci di prodotti e anteprime.
    - **Sconti Speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_pump:

4.2 Pompa dell'acqua
============================

In questo interessante progetto, ci immergeremo nel controllo di una pompa dell'acqua utilizzando il L293D.

Nel controllo delle pompe dell'acqua, le cose sono un po' più semplici rispetto al controllo di altri motori. La bellezza di questo progetto risiede nella sua semplicità: non è necessario preoccuparsi della direzione di rotazione. Il nostro obiettivo principale è attivare con successo la pompa dell'acqua e mantenerla in funzione.

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
    *   - :ref:`cpn_pump`
        - \-
    *   - :ref:`cpn_l293d`
        - \-

**Pin Disponibili**

Ecco un elenco dei pin disponibili sulla scheda ESP32 per questo progetto.

.. list-table::
    :widths: 5 20 

    * - Pin Disponibili
      - IO13, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23


**Schema**

.. image:: ../../img/circuit/circuit_4.1_motor_l293d.png


**Collegamento**

.. note::

    È consigliato inserire la batteria e poi far scorrere l'interruttore sulla scheda di espansione in posizione ON per attivare l'alimentazione della batteria.

.. image:: ../../img/wiring/4.2_pump_l293d_bb.png

**Codice**

.. note::

  * Puoi aprire il file ``4.2_pump.ino`` nel percorso ``esp32-starter-kit-main\c\codes\4.2_pump``. 
  * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta appropriata, fai clic sul pulsante **Upload**.
  * :ref:`unknown_com_port`
   
.. raw:: html

  <iframe src=https://create.arduino.cc/editor/sunfounder01/a56216f9-eba8-4fdc-8bbb-91337095e543/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Collega il tubo alla pompa e posizionalo all'interno del contenitore riempito d'acqua. Una volta caricato con successo il codice, vedrai l'acqua nel contenitore drenarsi gradualmente. Durante questo esperimento, assicurati che il circuito elettrico sia tenuto lontano dall'acqua per evitare cortocircuiti!

