.. note::

    Ciao, benvenuto nella community di appassionati di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_servo:

Servo
===========

.. image:: img/servo.png
    :align: center

Un servo è generalmente composto dalle seguenti parti: cassa, albero, sistema di ingranaggi, potenziometro, motore DC e scheda integrata.

Funziona così: Il microcontrollore invia segnali PWM al servo, e poi la scheda integrata nel servo riceve i segnali attraverso il pin del segnale e controlla il motore interno per farlo girare. Di conseguenza, il motore aziona il sistema di ingranaggi che, dopo la decelerazione, muove l'albero. L'albero e il potenziometro del servo sono collegati insieme. Quando l'albero ruota, fa muovere il potenziometro, che a sua volta invia un segnale di tensione alla scheda integrata. Successivamente, la scheda determina la direzione e la velocità di rotazione in base alla posizione corrente, in modo da poter fermare esattamente l'albero nella posizione definita e mantenerlo lì.

.. image:: img/servo_internal.png
    :align: center

L'angolo è determinato dalla durata di un impulso applicato al filo di controllo. Questo si chiama modulazione di larghezza di impulso (PWM). Il servo si aspetta di ricevere un impulso ogni 20 ms. La lunghezza dell'impulso determina quanto gira il motore. Per esempio, un impulso di 1,5 ms farà girare il motore alla posizione di 90 gradi (posizione neutrale).
Quando un impulso inviato a un servo è inferiore a 1,5 ms, il servo ruota in una posizione e mantiene l'albero di uscita a un certo numero di gradi in senso antiorario rispetto al punto neutro. Quando l'impulso è più lungo di 1,5 ms, accade il contrario. La larghezza minima e massima dell'impulso che comanda al servo di girare verso una posizione valida è una funzione di ogni servo. Generalmente, l'impulso minimo sarà di circa 0,5 ms e l'impulso massimo sarà di 2,5 ms.

.. image:: img/servo_duty.png
    :width: 600
    :align: center

**Esempio**

* :ref:`ar_servo` (Progetto Arduino)
* :ref:`py_servo` (Progetto MicroPython)
