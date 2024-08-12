.. note::

    Ciao, benvenuto nella community di appassionati di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_soil_moisture:

Modulo di Umidità del Suolo
================================

.. image:: img/soil_mositure.png

* GND: Terra
* VCC: Alimentazione, 3.3v~5V
* AOUT: Uscita del valore di umidità del suolo, più il terreno è umido, più piccolo è il suo valore.

Questo sensore capacitivo di umidità del suolo è diverso dalla maggior parte dei sensori resistivi presenti sul mercato, utilizzando il principio dell'induzione capacitiva per rilevare l'umidità del suolo. Evita il problema che i sensori resistivi sono altamente suscettibili alla corrosione e prolunga notevolmente la sua vita operativa.


È realizzato con materiali resistenti alla corrosione e ha un'eccellente durata. Inseriscilo nel terreno attorno alle piante e monitora in tempo reale i dati di umidità del suolo. Il modulo include un regolatore di tensione integrato che gli consente di funzionare su un intervallo di tensione di 3.3 ~ 5.5 V. È ideale per microcontrollori a bassa tensione con alimentazione a 3.3 V e 5 V.

Lo schema hardware del sensore capacitivo di umidità del suolo è mostrato di seguito.

.. image:: img/solid_schematic.png

C'è un oscillatore a frequenza fissa, costruito con un IC timer 555. L'onda quadra generata viene quindi inviata al sensore come un condensatore. Tuttavia, per il segnale a onda quadra, il condensatore ha una certa reattanza o, per semplicità, una resistenza con un resistore puramente ohmico (resistenza da 10k sul pin 3) per formare un partitore di tensione.

Maggiore è l'umidità del suolo, maggiore è la capacità del sensore. Di conseguenza, l'onda quadra ha meno reattanza, il che riduce la tensione sulla linea del segnale, e minore sarà il valore dell'ingresso analogico attraverso il microcontrollore.


**Specifiche**

* Tensione di funzionamento: 3.3 ~ 5.5 VDC
* Tensione di uscita: 0 ~ 3.0VDC
* Corrente operativa: 5mA
* Interfaccia: PH2.0-3P
* Dimensioni: 3.86 x 0.905 pollici (L x P)
* Peso: 15g

**Esempio**

* :ref:`ar_moisture` (Progetto Arduino)
* :ref:`ar_plant_monitor` (Progetto Arduino)
* :ref:`py_moisture` (Progetto MicroPython)
* :ref:`py_plant_monitor` (Progetto MicroPython)

