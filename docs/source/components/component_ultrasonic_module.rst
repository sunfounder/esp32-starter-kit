.. note::

    Ciao, benvenuto nella community di appassionati di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_ultrasonic:

Modulo Ultrasonico
================================

.. image:: img/ultrasonic_pic.png
    :width: 400
    :align: center

* **TRIG**: Ingresso del segnale di attivazione
* **ECHO**: Uscita del segnale di eco
* **GND**: Massa
* **VCC**: Alimentazione 5V

Questo è il sensore di distanza ultrasonico HC-SR04, che fornisce misurazioni senza contatto da 2 cm a 400 cm con una precisione di circa 3 mm. Il modulo include un trasmettitore ultrasonico, un ricevitore e un circuito di controllo.

Basta collegare 4 pin: VCC (alimentazione), Trig (attivazione), Echo (ricezione) e GND (massa) per utilizzarlo facilmente nei tuoi progetti di misurazione.

**Caratteristiche**

* Tensione di lavoro: DC5V
* Corrente di lavoro: 16mA
* Frequenza di lavoro: 40Hz
* Gamma massima: 500cm
* Gamma minima: 2cm
* Segnale di ingresso Trigger: impulso TTL 10uS
* Segnale di uscita Echo: segnale di livello TTL proporzionale alla distanza
* Connettore: XH2.54-4P
* Dimensioni: 46x20.5x15 mm

**Principio**

I principi di base sono i seguenti:

* Utilizzare il trigger IO per almeno 10us di segnale di livello alto.

* Il modulo invia un impulso ultrasonico di 8 cicli a 40 kHz e rileva se un segnale di eco viene ricevuto.

* Echo emetterà un livello alto se un segnale viene restituito; la durata del livello alto è il tempo dall'emissione al ritorno.

* Distanza = (tempo di livello alto x velocità del suono (340M/S)) / 2

.. image:: img/ultrasonic_prin.jpg

Formula:

* us / 58 = distanza in centimetri
* us / 148 = distanza in pollici
* distanza = tempo di livello alto x velocità (340M/S) / 2

.. note::

    Questo modulo non dovrebbe essere collegato sotto alimentazione, se necessario, collegare prima il GND del modulo. Altrimenti, potrebbe influenzare il funzionamento del modulo.

    L'area dell'oggetto da misurare dovrebbe essere di almeno 0,5 metri quadrati e il più piatta possibile. Altrimenti, i risultati potrebbero essere influenzati.

**Esempio**

* :ref:`ar_ultrasonic` (Progetto Arduino)
* :ref:`ar_reversing_aid` (Progetto Arduino)
* :ref:`py_ultrasonic` (Progetto MicroPython)
* :ref:`py_reversing_aid` (Progetto MicroPython)
* :ref:`sh_parrot` (Progetto Scratch)

