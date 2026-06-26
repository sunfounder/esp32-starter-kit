.. note::

    Ciao, benvenuto nella community di appassionati di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_motor:

Motore DC
===================

.. image:: img/image114.jpeg
    :align: center

Questo è un motore DC da 3V. Quando si applica un livello alto e un livello basso ai due terminali, il motore inizierà a ruotare.

* **Lunghezza**: 25mm
* **Diametro**: 21mm
* **Diametro dell'albero**: 2mm
* **Lunghezza dell'albero**: 8mm
* **Tensione**: 3-6V
* **Corrente**: 0.35-0.4A
* **Velocità a 3V**: 19000 RPM (rotazioni per minuto)
* **Peso**: Circa 14g (per unità)

Il motore a corrente continua (DC) è un attuatore continuo che converte l'energia elettrica in energia meccanica. I motori DC fanno funzionare pompe rotative, ventilatori, compressori, giranti e altri dispositivi producendo una rotazione angolare continua.

Un motore DC è costituito da due parti: la parte fissa del motore chiamata **statore** e la parte interna del motore chiamata **rotore** (o **ancora** di un motore DC) che ruota per produrre movimento.
Il segreto per generare movimento è posizionare l'armatura all'interno del campo magnetico del magnete permanente (il cui campo si estende dal polo nord al polo sud). L'interazione tra il campo magnetico e le particelle cariche in movimento (il filo che trasporta corrente genera il campo magnetico) produce la coppia che fa ruotare l'armatura.

.. image:: img/motor_sche.png
    :align: center

La corrente fluisce dal terminale positivo del Power Pack attraverso il circuito, passando attraverso le spazzole di rame fino al commutatore, e poi all'armatura.
Ma a causa delle due interruzioni nel commutatore, questo flusso si inverte a metà di ogni rotazione completa.

Questa continua inversione essenzialmente converte la corrente continua del Power Pack in corrente alternata, permettendo all'armatura di sperimentare la coppia nella direzione giusta al momento giusto per mantenere la rotazione.

.. image:: img/motor_rotate.gif
    :align: center

**Esempio**

* :ref:`ar_motor` (Progetto Arduino)
* :ref:`py_motor` (Progetto MicroPython)
* :ref:`sh_rotating_fan` (Progetto Scratch)
