.. note::

    Ciao, benvenuto nella community di appassionati di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_line_track:

Modulo di Tracciamento Linea
================================

.. image:: img/line_track.png
    :width: 400
    :align: center

* S: Solitamente livello basso, livello alto quando viene rilevata la linea nera.
* V+: Alimentazione, 3.3v~5V
* G: Terra

Questo è un modulo di tracciamento linea a 1 canale che, come suggerisce il nome, traccia linee nere su uno sfondo bianco o linee bianche su uno sfondo nero.

.. image:: img/tcrt5000.jpg
    :width: 200
    :align: center

Il modulo utilizza un sensore a infrarossi TCRT5000, che è composto da un LED a infrarossi (blu) e un triplet fotosensibile (nero).

* Il LED a infrarossi blu, quando alimentato, emette luce infrarossa che è invisibile all'occhio umano.
* Il fototransistor nero, che viene utilizzato per ricevere la luce infrarossa, ha una resistenza interna che varia con la luce infrarossa ricevuta; più luce infrarossa riceve, più la sua resistenza diminuisce e viceversa.

Sul modulo è presente un comparatore LM393, che viene utilizzato per confrontare la tensione del fototransistor con la tensione impostata (regolata tramite potenziometro); se è superiore alla tensione impostata, l'uscita è 1; altrimenti l'uscita è 0.

Pertanto, quando il tubo emettitore a infrarossi illumina una superficie nera, poiché il nero assorbe la luce, il transistor fotosensibile riceve meno luce infrarossa, la sua resistenza aumenterà (aumento della tensione), e dopo il comparatore LM393, l'uscita sarà a livello alto.

Analogamente, quando illumina una superficie bianca, la luce riflessa aumenterà e la resistenza del transistor fotosensibile diminuirà (diminuzione della tensione); quindi, il comparatore emette un livello basso e il LED indicatore si accende.



* `TCRT5000 <https://www.vishay.com/docs/83760/tcrt5000.pdf>`_

**Caratteristiche**

* Utilizzo del sensore di emissione a infrarossi TCRT5000
* Distanza di rilevamento: 1-8mm, lunghezza focale di 2.5mm
* Segnale di uscita del comparatore pulito, buona forma d'onda, capacità di pilotaggio superiore a 15mA
* Regolazione della sensibilità tramite potenziometro
* Tensione di funzionamento: 3.3V-5V
* Uscita digitale: 0 (bianco) e 1 (nero)
* Utilizzo del comparatore LM393 a larga tensione.
* Dimensioni: 42mmx10mm


**Esempio**

* :ref:`ar_line_track` (Progetto Arduino)
* :ref:`py_line_track` (Progetto MicroPython)
* :ref:`sh_protect_heart` (Progetto Scratch)

