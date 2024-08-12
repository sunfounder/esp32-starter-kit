.. note::

    Ciao, benvenuto nella community di appassionati di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_avoid:

Modulo di Evitamento Ostacoli
===========================================

.. image:: img/IR_Obstacle.png
   :width: 400
   :align: center

* **VCC**: Alimentazione, 3.3 ~ 5V DC.
* **GND**: Massa
* **OUT**: Pin di segnale, solitamente a livello alto, e a livello basso quando viene rilevato un ostacolo.

Il modulo a infrarossi per l'evitamento ostacoli ha una forte adattabilità alla luce ambientale, è dotato di una coppia di tubi trasmettitori e ricevitori a infrarossi.

Il tubo trasmettitore emette una frequenza a infrarossi e, quando la direzione di rilevamento incontra un ostacolo, la radiazione infrarossa viene ricevuta dal tubo ricevitore. 
Dopo l'elaborazione del circuito comparatore, l'indicatore si accenderà e verrà emesso un segnale a basso livello.

La distanza di rilevamento può essere regolata tramite un potenziometro, con una portata effettiva di 2-30 cm.

.. image:: img/IR_module.png
    :width: 600
    :align: center

**Esempio**

* :ref:`ar_ir_obstacle` (Progetto Arduino)
* :ref:`py_ir_obstacle` (Progetto MicroPython)
* :ref:`sh_shooting` (Progetto Scratch)
* :ref:`sh_tap_tile` (Progetto Scratch)
