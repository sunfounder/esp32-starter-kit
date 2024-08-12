.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a omaggi e promozioni durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _sh_doorbell:

2.5 Campanello
====================

Qui utilizzeremo il pulsante e la campanella sul palco per creare un campanello.

Dopo aver cliccato sulla bandiera verde, puoi premere il pulsante e la campanella sul palco emetterà un suono.

.. image:: img/7_doorbell.png

Componenti Necessari
------------------------

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
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|

Cosa Imparerai
---------------------

- Come funziona il pulsante
- Lettura del pin digitale e intervalli
- Creazione di un ciclo condizionale
- Aggiunta di uno sfondo
- Riproduzione del suono

Costruire il Circuito
---------------------------

Il pulsante è un dispositivo a 4 pin: poiché il pin 1 è collegato al pin 2, e il pin 3 al pin 4, quando il pulsante viene premuto, i 4 pin sono collegati, chiudendo così il circuito.

.. image:: img/5_buttonc.png

Costruisci il circuito seguendo il diagramma seguente.

* Collega uno dei pin sul lato sinistro del pulsante al pin 14, che è collegato a una resistenza pull-down e a un condensatore da 0,1uF (104) (per eliminare il jitter e ottenere un livello stabile quando il pulsante è in funzione).
* Collega l'altra estremità della resistenza e del condensatore a GND e uno dei pin sul lato destro del pulsante a 5V.

.. image:: img/circuit/6_doorbel_bb.png

Programmazione
-----------------

**1. Aggiungi uno Sfondo**

Clicca sul pulsante **Scegli uno Sfondo** nell'angolo in basso a destra.

.. image:: img/7_backdrop.png

Scegli **Camera da Letto 1**.

.. image:: img/7_bedroom2.png

**2. Seleziona lo sprite**

Elimina lo sprite predefinito, fai clic sul pulsante **Scegli uno Sprite** nell'angolo in basso a destra dell'area degli sprite, inserisci **campanella** nella casella di ricerca e poi clicca per aggiungerla.

.. image:: img/7_sprite.png

Quindi seleziona lo sprite **campanella** sul palco e spostalo nella posizione corretta.

.. image:: img/7_doorbell.png

**3. Premi il pulsante e la campanella emette un suono**

Usa [se allora] per creare una dichiarazione condizionale che, quando il valore letto dal pin 14 è uguale a 1 (il pulsante è premuto), verrà riprodotto il suono **xylo1**.

* [leggi stato del pin digitale]: Questo blocco è dalla tavolozza **ESP32** ed è utilizzato per leggere il valore di un pin digitale, il risultato è 0 o 1.
* [`if then <https://en.scratch-wiki.info/wiki/If_()_Then_(block)>`_]: Questo blocco è un blocco di controllo e proviene dalla tavolozza **Controllo**. Se la sua condizione booleana è vera, i blocchi contenuti al suo interno verranno eseguiti, e poi lo script coinvolto continuerà. Se la condizione è falsa, gli script all'interno del blocco verranno ignorati. La condizione viene verificata una sola volta; se la condizione diventa falsa mentre lo script all'interno del blocco è in esecuzione, continuerà a funzionare fino al termine.
* [riproduci suono fino al termine]: Questo blocco è dalla tavolozza Suono, utilizzato per riprodurre suoni specifici.

.. image:: img/7_bell.png
