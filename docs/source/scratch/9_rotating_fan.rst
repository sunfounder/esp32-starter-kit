.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a omaggi e promozioni durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _sh_rotating_fan:

2.9 Ventilatore Rotante
==========================

In questo progetto, realizzeremo una sprite a forma di stella rotante e un ventilatore.

Cliccando sulle sprite a forma di freccia sinistra e destra sulla scena, si controllerà la rotazione oraria e antioraria del motore e della sprite a stella; cliccando sulla sprite a stella, si fermerà la rotazione.

.. image:: img/13_fan.png

Componenti Necessari
-------------------------

In questo progetto, avremo bisogno dei seguenti componenti.

Per comodità, puoi acquistare un kit completo, ecco il link:

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
    *   - :ref:`cpn_motor`
        - |link_motor_buy|
    *   - :ref:`cpn_l293d`
        - \-

Cosa Imparerai
-------------------

- Principio di funzionamento del motore
- Funzione di broadcast
- Bloccare altri script in una sprite

Costruire il Circuito
-------------------------

.. image:: img/circuit/10_rotaing_fan_bb.png

Programmazione
-------------------

L'effetto che vogliamo ottenere è utilizzare 2 sprite a forma di freccia per controllare rispettivamente la rotazione oraria e antioraria del motore e della sprite a stella; cliccando sulla sprite a stella, si fermerà la rotazione del motore.

**1. Aggiungere sprite**

Elimina lo sprite predefinito, quindi seleziona la sprite **Stella** e la sprite **Freccia1**, e duplica **Freccia1** una volta.

.. image:: img/13_star.png

Nell'opzione **Costumi**, cambia il costume della sprite **Freccia1** in una direzione diversa.

.. image:: img/13_star1.png

Regola le dimensioni e la posizione della sprite in modo appropriato.

.. image:: img/13_star2.png

**2. Sprite freccia sinistra**

Quando questa sprite viene cliccata, trasmette un messaggio - turn, quindi imposta il pin digitale 12 su low e il pin 14 su high, e imposta la variabile **flag** su 1. Se clicchi sulla sprite freccia sinistra, il motore ruoterà in senso antiorario; se la rotazione è oraria, scambia le posizioni dei pin 12 e 14.

Ci sono 2 punti da notare qui.

* `[broadcast <https://en.scratch-wiki.info/wiki/Broadcast>`_]: dalla tavolozza **Eventi**, utilizzato per trasmettere un messaggio alle altre sprite; quando le altre sprite ricevono questo messaggio, eseguiranno un evento specifico. Ad esempio, qui è **turn**, quando la sprite **stella** riceve questo messaggio, esegue lo script di rotazione.
* variabile flag: La direzione di rotazione della sprite stella è determinata dal valore di flag. Quindi, quando crei la variabile **flag**, devi farla applicare a tutte le sprite.

.. image:: img/13_left.png
    :width: 600

**3. Sprite freccia destra**

Quando questa sprite viene cliccata, trasmette un messaggio turn, quindi imposta il pin digitale 12 su high e il pin 14 su low per far ruotare il motore in senso orario e imposta la variabile **flag** su 0.

.. image:: img/13_right.png

**4. Sprite stella**

Qui sono inclusi 2 eventi.

* Quando la sprite **stella** riceve il messaggio trasmesso turn, determina il valore di flag; se flag è 1, ruota di 10 gradi a sinistra, altrimenti ruota al contrario. Poiché è in [PER SEMPRE], continuerà a ruotare.
* Quando questa sprite viene cliccata, imposta entrambi i pin del motore su high per farlo smettere di ruotare e blocca gli altri script in questa sprite.

.. image:: img/13_broadcast.png
