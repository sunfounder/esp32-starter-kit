.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a omaggi e promozioni durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _sh_light_alarm:

2.7 Sveglia a Luce
=======================

Nella vita, esistono vari tipi di sveglie. Ora realizziamo una sveglia controllata dalla luce. Quando arriva la mattina, l'intensità della luce aumenta e questa sveglia controllata dalla luce ti ricorderà che è ora di alzarsi.

.. image:: img/10_clock.png

Componenti Necessari
--------------------------

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
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

Cosa Imparerai
---------------------

- Principio di funzionamento del fotoresistore
- Interruzione della riproduzione del suono e arresto degli script

Costruire il Circuito
-------------------------------

Un fotoresistore o cellula fotoelettrica è un resistore variabile controllato dalla luce. La resistenza di un fotoresistore diminuisce con l'aumentare dell'intensità della luce incidente.

Costruisci il circuito seguendo il diagramma seguente.

Collega un'estremità del fotoresistore a 5V, l'altra estremità al pin 35, e collega una resistenza da 10K in serie con GND a questa estremità.

Quindi, quando l'intensità della luce aumenta, la resistenza di un fotoresistore diminuisce, la divisione di tensione della resistenza da 10K aumenta e il valore ottenuto dal pin 35 diventa più grande.

.. image:: img/circuit/8_light_alarm_bb.png

Programmazione
------------------------

**1. Seleziona uno sprite**

Elimina lo sprite predefinito, fai clic sul pulsante **Scegli uno Sprite** nell'angolo in basso a destra dell'area degli sprite, inserisci **campanella** nella casella di ricerca e poi clicca per aggiungerlo.

.. image:: img/10_sprite.png

**2. Leggi il valore del pin 35**

Crea due variabili **prima** e **attuale**. Quando viene cliccata la bandiera verde, leggi il valore del pin 35 e memorizzalo nella variabile **prima** come valore di riferimento. In [per sempre], leggi di nuovo il valore del pin 35 e memorizzalo nella variabile **attuale**.

.. image:: img/10_reada0.png

**3. Emetti un suono**

Quando il valore del pin 35 attuale è superiore di 50 rispetto a quello precedente, il che rappresenta un'intensità di luce maggiore della soglia, allora fai emettere un suono allo sprite.

.. image:: img/10_sound.png

**4. Ruota lo sprite**

Usa il blocco [gira] per far girare lo sprite **campanella** a sinistra e a destra per ottenere l'effetto sveglia.

.. image:: img/10_turn.png

**5. Ferma tutto**

Ferma l'allarme dopo che ha suonato per un po'.

.. image:: img/10_stop.png
