.. note::

    Ciao, benvenuto nella Community di Appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirsi a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni l'accesso anticipato a nuovi annunci di prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _ar_7_segment:

2.5 Display a 7 Segmenti
==========================

Benvenuto in questo affascinante progetto! In questo progetto esploreremo il mondo incantevole della visualizzazione dei numeri da 0 a 9 su un display a sette segmenti.

Immagina di attivare questo progetto e vedere un piccolo, compatto display illuminarsi vivacemente con ciascun numero da 0 a 9. È come avere uno schermo in miniatura che mostra le cifre in modo coinvolgente. Controllando i pin di segnale, puoi cambiare facilmente il numero visualizzato e creare vari effetti accattivanti.

Attraverso semplici collegamenti di circuito e programmazione, imparerai come interagire con il display a sette segmenti e portare in vita i numeri desiderati. Che si tratti di un contatore, di un orologio, o di qualsiasi altra applicazione interessante, il display a sette segmenti sarà il tuo affidabile compagno, aggiungendo un tocco di brillantezza ai tuoi progetti.

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
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_7_segment`
        - |link_7segment_buy|
    *   - :ref:`cpn_74hc595`
        - |link_74hc595_buy|

**Pin Disponibili**

Ecco un elenco di pin disponibili sulla scheda ESP32 per questo progetto.

.. list-table::
    :widths: 5 20 

    * - Pin Disponibili
      - IO13, IO12, IO14, IO27, IO26, IO25, IO33, IO32, IO15, IO2, IO0, IO4, IO5, IO18, IO19, IO21, IO22, IO23

**Schema Elettrico**

.. image:: ../../img/circuit/circuit_2.5_74hc595_7_segment.png

Qui il principio del cablaggio è sostanzialmente lo stesso di :ref:`ar_74hc595`, l'unica differenza è che Q0-Q7 sono collegati ai pin a ~ g del Display a 7 Segmenti.

.. list-table:: Cablaggio
    :widths: 15 25
    :header-rows: 1

    *   - 74HC595
        - Display a Segmenti LED
    *   - Q0
        - a
    *   - Q1
        - b
    *   - Q2
        - c
    *   - Q3
        - d
    *   - Q4
        - e
    *   - Q5
        - f
    *   - Q6
        - g
    *   - Q7
        - dp

**Cablaggio**

.. image:: ../../img/wiring/2.5_segment_bb.png
    :width: 800

**Codice**

.. note::

    * Apri il file ``2.5_7segment.ino`` nel percorso ``esp32-starter-kit-main\c\codes\2.5_7segment``.
    * Dopo aver selezionato la scheda (ESP32 Dev Module) e la porta appropriata, clicca sul pulsante **Carica**.
    * :ref:`unknown_com_port`
    
.. raw:: html

    <iframe src=https://create.arduino.cc/editor/sunfounder01/937f5e3f-2d9e-4c75-8331-ace3c0876182/preview?embed style="height:510px;width:100%;margin:10px 0" frameborder=0></iframe>

Dopo che il codice è stato caricato con successo, vedrai il Display a Segmenti LED visualizzare i numeri da 0 a 9 in sequenza.

**Come funziona?**

In questo progetto, stiamo usando la funzione ``shiftOut()`` per scrivere il numero binario nel registro a scorrimento.

Supponiamo che il Display a 7 Segmenti visualizzi il numero "2". Questo schema di bit corrisponde ai segmenti **f**, **c** e **dp** spenti (low), mentre i segmenti **a**, **b**, **d**, **e** e **g** sono accesi (high). Questo è "01011011" in binario e "0x5b" in notazione esadecimale.

Pertanto, dovresti chiamare ``shiftOut(DS,SHcp,MSBFIRST,0x5b)`` per visualizzare il numero "2" sul display a 7 segmenti.

.. image:: img/7_segment2.png

* `Hexadecimal <https://en.wikipedia.org/wiki/Hexadecimal>`_

* `BinaryHex Converter <https://www.binaryhexconverter.com/binary-to-hex-converter>`_

La seguente tabella mostra gli schemi esadecimali che devono essere scritti nel registro a scorrimento per visualizzare i numeri da 0 a 9 su un display a 7 segmenti.

.. list-table:: Codice delle Cifre
    :widths: 20 20 20
    :header-rows: 1

    *   - Numeri	
        - Codice Binario
        - Codice Esadecimale  
    *   - 0	
        - 00111111	
        - 0x3f
    *   - 1	
        - 00000110	
        - 0x06
    *   - 2	
        - 01011011	
        - 0x5b
    *   - 3	
        - 01001111	
        - 0x4f
    *   - 4	
        - 01100110	
        - 0x66
    *   - 5	
        - 01101101	
        - 0x6d
    *   - 6	
        - 01111101	
        - 0x7d
    *   - 7	
        - 00000111	
        - 0x07
    *   - 8	
        - 01111111	
        - 0x7f
    *   - 9	
        - 01101111	
        - 0x6f

Scrivi questi codici in ``shiftOut()`` per far visualizzare al Display a Segmenti LED i numeri corrispondenti.
