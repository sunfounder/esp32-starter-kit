.. note::

    Ciao, benvenuto nella community di appassionati di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_audio_speaker:

Modulo Amplificatore Audio e Altoparlante
==============================================

**Modulo Amplificatore Audio**

.. image:: img/audio_module.jpg
    :width: 500
    :align: center

Il modulo Amplificatore Audio contiene un chip amplificatore di potenza audio HXJ8002. Questo chip è un amplificatore di potenza a basso consumo che può fornire 3W di potenza audio media per un carico BTL di 3Ω con bassa distorsione armonica (sotto la soglia del 10% di distorsione a 1KHz) da un'alimentazione a 5V DC. Questo chip può amplificare segnali audio senza l'uso di condensatori di accoppiamento o condensatori bootstrap.

Il modulo può essere alimentato con una tensione DC da 2,0V fino a 5,5V con una corrente operativa di 10mA (0,6uA per la corrente tipica in standby) e produrre un suono amplificato potente in un altoparlante con impedenza di 3Ω, 4Ω o 8Ω. Questo modulo ha un circuito migliorato per ridurre significativamente il rumore di transizione all'accensione e spegnimento. Le dimensioni ridotte, unite all'alta efficienza e al basso consumo di energia, lo rendono applicabile in una vasta gamma di progetti portatili e alimentati a batteria con microcontrollori.

* **IC**: HXJ8002
* **Tensione di ingresso**: 2V ~ 5.5V
* **Corrente in modalità standby**: 0.6uA (valore tipico)
* **Potenza in uscita**: 3W (carico da 3Ω), 2.5W (carico da 4Ω), 1.5W (carico da 8Ω)
* **Impedenza di uscita dell'altoparlante**: 3Ω, 4Ω, 8Ω
* **Dimensioni**: 19.8mm x 14.2mm

**Altoparlante**

.. image:: img/speaker_pic.png
    :width: 300
    :align: center

* **Dimensioni**: 20x30x7mm
* **Impedenza**: 8ohm
* **Potenza di ingresso nominale**: 1.5W 
* **Potenza massima di ingresso**: 2.0W
* **Lunghezza del cavo**: 10cm

.. image:: img/2030_speaker.png

Le dimensioni sono le seguenti：

* :download:`2030 Speaker Datasheet <https://github.com/sunfounder/sf-pdf/raw/master/datasheet/2030-speaker-datasheet.pdf>`


**Esempio**

* :ref:`ar_mp3_player_sd` (Progetto Arduino)
* :ref:`bluetooth_audio_player` (Progetto Arduino)

