.. note::

    Ciao, benvenuto nella community di appassionati di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_l9110:

Modulo Driver Motore L9110
=============================

Il modulo driver motore L9110 è ideale per controllare due motori in tandem. Al suo interno ospita una coppia di chip driver L9110S indipendenti, 
ciascun canale offre una corrente di uscita stabile fino a 800mA.

Con una gamma di tensione che va da 2.5V a 12V, il modulo si abbina facilmente sia a microcontrollori a 3.3V che a 5V.

Il modulo driver motore L9110 è una soluzione semplificata che facilita il controllo dei motori in una varietà di applicazioni. 
Grazie alla sua architettura a due canali, consente l'azionamento indipendente di due motori, ideale per progetti in cui l'operazione simultanea di due motori è fondamentale.

Grazie alla sua potente corrente continua in uscita, questo modulo alimenta con sicurezza motori di piccole e medie dimensioni, 
aprendo la strada a numerosi progetti di robotica, automazione e motori. La sua ampia gamma di tensione aggiunge ulteriore flessibilità, adattandosi a diverse configurazioni di alimentazione.

Progettato pensando alla facilità d'uso, il modulo offre terminali di ingresso e uscita intuitivi, semplificando le connessioni ai microcontrollori 
o ad altri dispositivi di controllo simili. Inoltre, non manca di sicurezza: le protezioni integrate contro sovracorrente e surriscaldamento migliorano l'affidabilità 
e la sicurezza delle operazioni del motore.

.. image:: img/l9110s.jpg
    :width: 600
    :align: center

* **B-1A & B-1B**: Pin di ingresso per controllare la direzione di rotazione del Motore B.
* **A-1A & A-1B**: Pin di ingresso per controllare la direzione di rotazione del Motore A.
* **0A & OB(A)**: Pin di uscita del Motore A.
* **0A & OB(B)**: Pin di uscita del Motore B.
* **VCC**: Pin di ingresso per l'alimentazione (2.5V-12V).
* **GND**: Pin di massa.

**Caratteristiche**

* 2 chip di controllo motore L9110S integrati
* Controllo a due canali per motori.
* Controllo indipendente della direzione di rotazione dei motori.
* Alta corrente di uscita (800mA per canale).
* Ampia gamma di tensione (2.5V-12V).
* Design compatto.
* Terminali di ingresso e uscita convenienti.
* Funzionalità di protezione integrate.
* Applicazioni versatili.
* Dimensioni PCB: 29.2mm x 23mm
* Temperatura di esercizio: -20°C ~ 80°C
* Indicatore LED di alimentazione

**Principio di funzionamento**

Ecco la tabella della verità per il Motore B:

Questa tabella della verità mostra i diversi stati del Motore B in base ai valori dei pin di ingresso B-1A e B-1B. Indica la direzione di rotazione (in senso orario o antiorario), la frenata o l'arresto del Motore B.

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - B-1A
      - B-1B
      - Stato del Motore B
    * - 1
      - 0
      - Rotazione in senso orario
    * - 0
      - 1
      - Rotazione in senso antiorario
    * - 0
      - 0
      - Freno
    * - 1
      - 1
      - Stop

Ecco la tabella della verità per il Motore A:

Questa tabella della verità mostra i diversi stati del Motore A in base ai valori dei pin di ingresso A-1A e A-1B. Indica la direzione di rotazione (in senso orario o antiorario), la frenata o l'arresto del Motore A.

.. list-table:: 
    :widths: 25 25 50
    :header-rows: 1

    * - A-1A
      - A-1B
      - Stato del Motore A
    * - 1
      - 0
      - Rotazione in senso orario
    * - 0
      - 1
      - Rotazione in senso antiorario
    * - 0
      - 0
      - Freno
    * - 1
      - 1
      - Stop

**Esempio**

* :ref:`ar_motor` (Progetto Arduino)
* :ref:`ar_pump` (Progetto Arduino)
* :ref:`py_motor` (Progetto MicroPython)
* :ref:`py_pump` (Progetto MicroPython)
* :ref:`sh_rotating_fan` (Progetto Scratch)
