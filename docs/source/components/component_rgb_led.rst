.. note::

    Ciao, benvenuto nella community di appassionati di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_rgb:

LED RGB
=================

.. image:: img/rgb_led.png
    :width: 200
    :align: center

I LED RGB emettono luce in vari colori. Un LED RGB racchiude tre LED di colore rosso, verde e blu in un involucro di plastica trasparente o semitrasparente. Può mostrare vari colori modificando la tensione di ingresso dei tre pin e sovrapponendoli, il che, secondo le statistiche, può creare 16.777.216 colori diversi.

**Caratteristiche**

* Colore: Tri-Color (Rosso/Verde/Blu)
* Catodo Comune
* Lente Tonda Chiara da 5mm
* Tensione Diretta: Rosso: DC 2.0 - 2.2V; Blu&Verde: DC 3.0 - 3.2V (IF=20mA)
* 0.06 Watt DIP RGB LED
* Luminosità Aumentata Fino al +20%
* Angolo di Visione: 30°

**Anodo Comune e Catodo Comune**

I LED RGB possono essere classificati in LED ad anodo comune e a catodo comune.

* In un LED RGB a catodo comune, tutti e tre i LED condividono una connessione negativa (catodo).
* In un LED RGB ad anodo comune, i tre LED condividono una connessione positiva (anodo).

.. image:: img/rgb_cc_ca.jpg

.. note::
    Utilizziamo il tipo a catodo comune.

**Pin del LED RGB**

Un LED RGB ha 4 pin: il più lungo è il GND; gli altri sono Rosso, Verde e Blu. Posiziona i LED RGB come mostrato, in modo che il terminale più lungo sia il secondo da sinistra. Quindi, i pin del LED RGB dovrebbero essere Rosso, GND, Verde e Blu.

.. image:: img/rgb_pin.jpg
    :width: 200

Puoi anche utilizzare il multimetro impostato in modalità di test del diodo e quindi collegarlo come mostrato di seguito per misurare il colore di ciascun pin.

.. image:: img/rgb_test.png

**Miscelare i colori**

Per generare altri colori, puoi combinare i tre colori a diverse intensità. Per regolare l'intensità di ciascun LED, puoi utilizzare un segnale PWM.

Poiché i LED sono così vicini tra loro, i nostri occhi vedono il risultato della combinazione dei colori piuttosto che i tre colori singolarmente.

Guarda la tabella qui sotto per vedere come vengono combinati i colori. Ti darà un'idea di come funziona la tabella di miscelazione dei colori e di come vengono prodotti i colori diversi.

.. image:: img/rgb_mix.png

**Esempio**

* :ref:`ar_rgb` (Progetto Arduino)
* :ref:`ar_color_gradient` (Progetto Arduino)
* :ref:`py_rgb` (Progetto MicroPython)
* :ref:`sh_colorful_ball` (Progetto Scratch)
