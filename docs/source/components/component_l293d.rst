.. note::

    Ciao, benvenuto nella community di appassionati di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_l293d:

L293D 
=================

L293D è un driver motore a 4 canali integrato da un chip ad alta tensione e alta corrente. 
È progettato per collegarsi ai livelli logici standard DTL e TTL e per pilotare carichi induttivi (come bobine di relè, motori DC, motori passo-passo) e transistor di commutazione di potenza, ecc. 
I motori DC sono dispositivi che trasformano l'energia elettrica continua in energia meccanica. Sono ampiamente utilizzati nelle applicazioni di azionamento elettrico grazie alle loro eccellenti prestazioni di regolazione della velocità.

Di seguito è riportata la figura dei pin. L293D ha due pin (Vcc1 e Vcc2) per l'alimentazione. 
Vcc2 è utilizzato per alimentare il motore, mentre Vcc1 per alimentare il chip. Poiché qui viene utilizzato un motore DC di piccole dimensioni, collega entrambi i pin a +5V.

.. image:: img/l293d111.png

Di seguito è riportata la struttura interna di L293D. 
Il pin EN è un pin di abilitazione e funziona solo con livello alto; A rappresenta l'ingresso e Y l'uscita. 
Puoi vedere la relazione tra di loro in basso a destra. 
Quando il pin EN è a livello alto, se A è alto, Y emette un livello alto; se A è basso, Y emette un livello basso. Quando il pin EN è a livello basso, il L293D non funziona.

.. image:: img/l293d334.png

* `L293D Datasheet <https://www.ti.com/lit/ds/symlink/l293d.pdf?ts=1627004062301&ref_url=https%253A%252F%252Fwww.ti.com%252Fproduct%252FL293D>`_


**Esempio**

* :ref:`ar_motor` (Progetto Arduino)
* :ref:`ar_pump` (Progetto Arduino)
* :ref:`py_motor` (Progetto MicroPython)
* :ref:`py_pump` (Progetto MicroPython)
* :ref:`sh_rotating_fan` (Progetto Scratch)
