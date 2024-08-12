.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a omaggi e promozioni durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _sh_moving_mouse:

2.4 Topolino in Movimento
=============================

Oggi realizzeremo un giocattolo a forma di topolino controllato da un potenziometro.

Quando viene cliccata la bandiera verde, il topolino sul palco si muove in avanti e, ruotando il potenziometro, il topolino cambierà direzione di movimento.

.. image:: img/6_mouse.png

Componenti Necessari
-----------------------

In questo progetto, avremo bisogno dei seguenti componenti.

È sicuramente conveniente acquistare un kit completo, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome	
        - ELEMENTI IN QUESTO KIT
        - LINK
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

Puoi anche acquistarli separatamente dai link qui sotto.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUZIONE AI COMPONENTI
        - LINK PER L'ACQUISTO

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - |link_esp32_extension_board|
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_pot`
        - |link_potentiometer_buy|

Cosa Imparerai
---------------------

- Principio del potenziometro
- Lettura del pin analogico e intervalli
- Mappatura di un intervallo su un altro
- Movimento e cambio di direzione dello sprite

Costruire il Circuito
-------------------------

Il potenziometro è un elemento resistivo con 3 terminali: i 2 pin laterali sono collegati a 5V e GND, mentre il pin centrale è collegato al pin 35. Dopo la conversione tramite il convertitore ADC dell'ESP32, l'intervallo di valori è 0-4095.

.. image:: img/circuit/5_moving_mouse_bb.png

Programmazione
------------------

**1. Scegli uno sprite**

Elimina lo sprite predefinito, fai clic sul pulsante **Scegli uno Sprite** nell'angolo in basso a destra dell'area degli sprite, inserisci **mouse** nella casella di ricerca e poi clicca per aggiungerlo.

.. image:: img/6_sprite.png

**2. Creazione di una variabile**

Crea una variabile chiamata **value** per memorizzare il valore letto dal potenziometro.

Una volta creata, vedrai **value** apparire all'interno della tavolozza **Variabili** e in stato selezionato, il che significa che questa variabile apparirà sul palco.

.. image:: img/6_value.png

**3. Leggere il valore del pin 35**

Memorizza il valore letto dal pin 35 nella variabile **value**.

* [imposta la mia variabile a 0]: Imposta il valore della variabile.
* [leggi pin analogico ()]: Legge il valore dei pin nell'intervallo 0-4095.

.. image:: img/6_read_a0.png

Per poter leggere in modo continuo, è necessario utilizzare il blocco [per sempre]. Clicca su questo script per eseguirlo, ruota il potenziometro in entrambe le direzioni e vedrai che l'intervallo di valori è 0-1023.

.. image:: img/6_1023.png

**4. Muovi lo sprite**

Usa il blocco [muovi passi] per muovere lo sprite, esegui lo script e vedrai lo sprite muoversi dal centro verso destra.

.. image:: img/6_move.png

**5. Cambiare la direzione dello sprite**

Ora cambia la direzione di movimento dello sprite in base al valore del pin 35. Poiché il valore del pin 35 varia da 0 a 4095, mentre la direzione di rotazione dello sprite va da -180 a 180, è necessario utilizzare un blocco [mappa].

Aggiungi anche [quando si clicca la bandiera verde] all'inizio per avviare lo script.

* [`point in direction <https://en.scratch-wiki.info/wiki/Point_in_Direction_()_(block)>`_]: Imposta l'angolo di rotazione dello sprite, dalla tavolozza **Movimento**.
* [mappa da a]: Mappa un intervallo su un altro intervallo.

.. image:: img/6_direction.png
