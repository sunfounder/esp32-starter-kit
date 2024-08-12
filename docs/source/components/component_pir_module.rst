.. note::

    Ciao, benvenuto nella community di appassionati di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_pir:

Modulo Sensore di Movimento PIR
=====================================

.. image:: img/pir_pic.png
    :width: 300
    :align: center

Il sensore PIR rileva la radiazione di calore infrarosso che può essere utilizzata per rilevare la presenza di organismi che emettono questa radiazione.

Il sensore PIR è diviso in due sezioni collegate a un amplificatore differenziale. Quando un oggetto stazionario si trova davanti al sensore, le due sezioni ricevono la stessa quantità di radiazione e l'uscita è pari a zero. Quando un oggetto in movimento si trova davanti al sensore, una delle sezioni riceve più radiazione rispetto all'altra, causando una fluttuazione dell'uscita in alto o in basso. Questo cambiamento nella tensione di uscita è il risultato del rilevamento del movimento.

.. image:: img/PIR_working_principle.jpg
    :width: 800

Dopo il cablaggio del modulo di rilevamento, vi è un'inizializzazione di un minuto. Durante l'inizializzazione, il modulo emetterà un segnale per 0~3 volte a intervalli. Successivamente, il modulo entrerà in modalità standby. Si consiglia di mantenere lontane le fonti di luce e altre fonti di interferenza dalla superficie del modulo per evitare errori di funzionamento causati da segnali di interferenza. È consigliabile utilizzare il modulo in un ambiente privo di vento, poiché anche il vento può interferire con il sensore.

.. image:: img/pir_back.png
    :width: 600
    :align: center

**Regolazione della Distanza**

Ruotando in senso orario il pomello del potenziometro di regolazione della distanza, il raggio di rilevamento aumenta, con una portata massima di circa 0-7 metri. Ruotandolo in senso antiorario, il raggio di rilevamento diminuisce, con una portata minima di circa 0-3 metri.

**Regolazione del Ritardo**

Ruotando in senso orario il pomello del potenziometro di regolazione del ritardo, si aumenta il ritardo di rilevamento. Il ritardo massimo può raggiungere fino a 300 secondi. Al contrario, ruotandolo in senso antiorario, si riduce il ritardo, con un minimo di 5 secondi.

**Due Modalità di Attivazione**

È possibile scegliere tra diverse modalità utilizzando il cappuccio del jumper.

* **H**: Modalità di attivazione ripetibile, dopo il rilevamento del corpo umano, il modulo emette un livello alto. Durante il successivo periodo di ritardo, se qualcuno entra nel raggio di rilevamento, l'uscita rimarrà a livello alto.

* **L**: Modalità di attivazione non ripetibile, emette un livello alto quando rileva il corpo umano. Dopo il ritardo, l'uscita passerà automaticamente da livello alto a livello basso.

**Esempio**

* :ref:`ar_pir` (Progetto Arduino)
* :ref:`iot_telegram` (Progetto Arduino)
* :ref:`py_pir` (Progetto MicroPython)
