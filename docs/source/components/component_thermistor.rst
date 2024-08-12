.. note::

    Ciao, benvenuto nella community di appassionati di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_thermistor:

Termistore
===============

.. image:: img/thermistor.png
    :width: 150
    :align: center

Un termistore è un tipo di resistore la cui resistenza dipende fortemente dalla temperatura, più di quanto accade nei resistori standard. La parola è una combinazione di "termico" e "resistore". I termistori sono ampiamente utilizzati come limitatori di corrente di spunto, sensori di temperatura (tipicamente di tipo NTC, coefficiente di temperatura negativo), protettori da sovracorrente autoregolanti e elementi riscaldanti autoregolanti (tipicamente di tipo PTC, coefficiente di temperatura positivo).

* `Thermistor - Wikipedia <https://en.wikipedia.org/wiki/Thermistor>`_

Ecco il simbolo elettronico del termistore.

.. image:: img/thermistor_symbol.png
    :width: 300
    :align: center

I termistori si dividono in due tipi fondamentali opposti:

* Con i termistori NTC, la resistenza diminuisce all'aumentare della temperatura, solitamente a causa di un aumento degli elettroni di conduzione che vengono spostati dalla banda di valenza per agitazione termica. Un NTC è comunemente utilizzato come sensore di temperatura o in serie con un circuito come limitatore di corrente di spunto.
* Con i termistori PTC, la resistenza aumenta all'aumentare della temperatura, solitamente a causa dell'aumento delle agitazioni del reticolo termico, in particolare quelle delle impurità e delle imperfezioni. I termistori PTC sono comunemente installati in serie con un circuito e utilizzati per proteggere da condizioni di sovracorrente, come fusibili ripristinabili.

In questo kit utilizziamo un NTC. Ogni termistore ha una resistenza normale. In questo caso, è di 10k ohm, misurata a 25 gradi Celsius.

Ecco la relazione tra resistenza e temperatura:

    RT = RN * expB(1/TK - 1/TN)   

* **RT** è la resistenza del termistore NTC quando la temperatura è TK. 
* **RN** è la resistenza del termistore NTC alla temperatura nominale TN. In questo caso, il valore numerico di RN è 10k.
* **TK** è la temperatura in Kelvin e l'unità di misura è K. In questo caso, il valore numerico di TK è 273,15 + gradi Celsius.
* **TN** è la temperatura nominale in Kelvin; l'unità di misura è sempre K. In questo caso, il valore numerico di TN è 273,15 + 25.
* **B(beta)**, la costante di materiale del termistore NTC, è anche chiamata indice di sensibilità termica con un valore numerico di 3950.
* **exp** è l'abbreviazione di esponenziale, e il numero base e è un numero naturale e vale circa 2,7.

Converti questa formula TK=1/(ln(RT/RN)/B+1/TN) per ottenere la temperatura in Kelvin, che sottratta di 273,15 dà la temperatura in gradi Celsius.

Questa relazione è una formula empirica. È accurata solo quando la temperatura e la resistenza sono all'interno del range efficace.

**Esempio**

* :ref:`ar_thermistor` (Progetto Arduino)
* :ref:`ar_iot_mqtt` (Progetto Arduino)
* :ref:`py_thermistor` (Progetto MicroPython)
* :ref:`sh_low_temperature` (Progetto Scratch)
