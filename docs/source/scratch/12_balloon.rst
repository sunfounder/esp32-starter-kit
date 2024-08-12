.. note::

    Ciao, benvenuto nella community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a omaggi e promozioni durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _sh_balloon:

2.12 GIOCO - Gonfia il Palloncino
==========================================

In questo progetto, giocheremo a gonfiare un palloncino.

Dopo aver cliccato sulla bandiera verde, il palloncino diventerà sempre più grande. Se il palloncino è troppo grande, scoppierà; se è troppo piccolo, cadrà. Devi decidere quando premere il pulsante per farlo volare verso l'alto.

.. image:: img/13_balloon0.png

Componenti Necessari
-------------------------

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

Puoi anche acquistare i componenti separatamente dai link qui sotto.

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|

Cosa Imparerai
-----------------

- Dipingere un costume per la sprite


Costruire il Circuito
-------------------------

Il pulsante è un dispositivo a 4 pin: poiché il pin 1 è collegato al pin 2 e il pin 3 al pin 4, quando si preme il pulsante, i 4 pin vengono connessi, chiudendo così il circuito.

.. image:: img/5_buttonc.png

Costruisci il circuito secondo il diagramma seguente.

* Collega uno dei pin sul lato sinistro del pulsante al pin14, che è collegato a una resistenza pull-down e a un condensatore da 0,1uF (104) (per eliminare il jitter e fornire un livello stabile quando il pulsante è in funzione).
* Collega l'altra estremità della resistenza e del condensatore a GND, e uno dei pin sul lato destro del pulsante a 5V.

.. image:: img/circuit/6_doorbel_bb.png

Programmazione
-------------------

**1. Aggiungi una sprite e uno sfondo**

Elimina la sprite predefinita, clicca sul pulsante **Scegli una Sprite** nell'angolo in basso a destra dell'area delle sprite, quindi seleziona la sprite **Balloon1**.

.. image:: img/13_balloon1.png

Aggiungi uno sfondo **Boardwalk** tramite il pulsante **Scegli uno sfondo**, o altri sfondi che ti piacciono.

.. image:: img/13_balloon2.png

**2. Dipingi un costume per la sprite Balloon1**

Ora disegniamo un costume con l'effetto di esplosione per la sprite del palloncino.

Vai alla pagina **Costumi** della sprite **Balloon1**, clicca sul pulsante **Scegli un Costume** in basso a sinistra e seleziona **Dipingi** per creare un **Costume** vuoto.

.. image:: img/13_balloon7.png

Seleziona un colore e poi usa lo strumento **Pennello** per disegnare un motivo.

.. image:: img/13_balloon3.png

Seleziona nuovamente un colore, clicca sullo strumento Riempi e sposta il mouse all'interno del motivo per riempirlo con un colore.

.. image:: img/13_balloon4.png

Infine, scrivi il testo BOOM, in modo da completare un costume con effetto esplosione.

.. image:: img/13_balloon5.png

**3. Programmazione della sprite Balloon**

Imposta la posizione iniziale e la dimensione della sprite **Balloon1**.

.. image:: img/13_balloon6.png

Quindi, lascia che la sprite **Balloon** si ingrandisca lentamente.

.. image:: img/13_balloon8.png

Quando si preme il pulsante (valore è 1), la dimensione della sprite **Balloon1** smette di aumentare.

* Quando la dimensione è inferiore a 90, cadrà (la coordinata y diminuisce).
* Quando la dimensione è maggiore di 90 e inferiore a 120, volerà verso l'alto (la coordinata y aumenta).

.. image:: img/13_balloon9.png

Se il pulsante non è stato premuto, il palloncino si ingrandisce lentamente e quando la dimensione è maggiore di 120, esploderà (passerà al costume con effetto esplosione).

.. image:: img/13_balloon10.png
