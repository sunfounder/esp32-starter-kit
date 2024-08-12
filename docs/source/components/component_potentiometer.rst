.. note::

    Ciao, benvenuto nella community di appassionati di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_pot:

Potentiometro
==================

.. image:: img/potentiometer.png
    :align: center
    :width: 150

Il potenziometro è un componente resistivo con 3 terminali, il cui valore di resistenza può essere regolato secondo una variazione prestabilita.

I potenziometri sono disponibili in diverse forme, dimensioni e valori, ma tutti hanno in comune le seguenti caratteristiche:

* Hanno tre terminali (o punti di connessione).
* Hanno una manopola, una vite o un cursore che può essere spostato per variare la resistenza tra il terminale centrale e uno dei terminali esterni.
* La resistenza tra il terminale centrale e uno dei terminali esterni varia da 0 Ω alla resistenza massima del potenziometro man mano che la manopola, la vite o il cursore vengono spostati.

Ecco il simbolo del potenziometro nel circuito.

.. image:: img/potentiometer_symbol.png
    :align: center
    :width: 400

Le funzioni del potenziometro nel circuito sono le seguenti:

#. Funzionare come divisore di tensione

    Il potenziometro è una resistenza regolabile continuamente. Quando si regola l'asse o la maniglia scorrevole del potenziometro, il contatto mobile scivola sulla resistenza. A questo punto, è possibile ottenere una tensione in uscita a seconda della tensione applicata al potenziometro e dell'angolo al quale si è ruotato il braccio mobile o della distanza percorsa.

#. Funzionare come reostato

    Quando il potenziometro è utilizzato come reostato, collegare il pin centrale e uno degli altri due pin nel circuito. In questo modo, si ottiene un valore di resistenza che varia in modo fluido e continuo lungo il percorso del contatto mobile.

#. Funzionare come regolatore di corrente

    Quando il potenziometro agisce come regolatore di corrente, il terminale di contatto scorrevole deve essere collegato come uno dei terminali di uscita.

Se desideri saperne di più sul potenziometro, consulta: `Potentiometer - Wikipedia <https://en.wikipedia.org/wiki/Potentiometer>`_

**Esempio**

* :ref:`ar_potentiometer` (Progetto Arduino)
* :ref:`py_potentiometer` (Progetto MicroPython)
* :ref:`sh_moving_mouse` (Progetto Scratch)
* :ref:`sh_breakout_clone` (Progetto Scratch)
