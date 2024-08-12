.. note::

    Ciao, benvenuto nella community di appassionati di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_dht11:

Sensore di Temperatura e Umidità DHT11
============================================

Il sensore digitale di temperatura e umidità DHT11 è un sensore composito che contiene un'uscita di segnale digitale calibrata per temperatura e umidità. 
Viene applicata la tecnologia di raccolta dei moduli digitali dedicati insieme alla tecnologia di rilevamento della temperatura e dell'umidità per garantire alta affidabilità ed eccellente stabilità a lungo termine del prodotto.

Il sensore include un componente resistivo per il rilevamento dell'umidità e un dispositivo di misurazione della temperatura NTC, ed è collegato a un microcontrollore ad alte prestazioni a 8 bit.

Sono disponibili solo tre pin per l'uso: VCC, GND e DATA.
Il processo di comunicazione inizia con la linea DATA che invia segnali di avvio al DHT11, e il DHT11 riceve i segnali e restituisce un segnale di risposta. 
Successivamente l'host riceve il segnale di risposta e inizia a ricevere 40 bit di dati di umidità e temperatura (8 bit intero umidità + 8 bit decimale umidità + 8 bit intero temperatura + 8 bit decimale temperatura + 8 bit checksum).

.. image:: img/dht11.png

**Caratteristiche**

    #. Intervallo di misurazione dell'umidità: 20 - 90%RH
    #. Intervallo di misurazione della temperatura: 0 - 60℃
    #. Segnali digitali in uscita che indicano temperatura e umidità
    #. Tensione di lavoro: DC 5V; Dimensioni PCB: 2,0 x 2,0 cm
    #. Precisione di misurazione dell'umidità: ±5%RH
    #. Precisione di misurazione della temperatura: ±2℃

* `DHT11 Datasheet <http://wiki.sunfounder.cc/images/c/c7/DHT11_datasheet.pdf>`_

**Esempi**

* :ref:`ar_dht11` (Progetto Arduino)
* :ref:`ar_plant_monitor` (Progetto Arduino)
* :ref:`ar_adafruit_io` (Progetto Arduino)
* :ref:`py_dht11` (Progetto MicroPython)
* :ref:`py_plant_monitor` (Progetto MicroPython)

