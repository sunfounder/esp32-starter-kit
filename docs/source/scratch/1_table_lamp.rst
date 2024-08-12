.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a omaggi e promozioni durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _sh_table_lamp:

2.1 Lampada da Tavolo
============================

Qui colleghiamo un LED sulla breadboard e facciamo in modo che lo sprite controlli il lampeggiamento di questo LED.

Quando il pulsante sprite sul palco viene cliccato, il LED lampeggerà 5 volte e poi si fermerà.

.. image:: img/2_button.png

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
    *   - :ref:`cpn_led`
        - |link_led_buy|

Cosa Imparerai
-------------------

- Breadboard, LED e Resistenze
- Costruire un circuito su una breadboard
- Eliminare e selezionare sprite
- Cambiare i costumi


- Impostare un numero limitato di cicli ripetuti

Costruire il Circuito
--------------------------

Segui lo schema qui sotto per costruire il circuito sulla breadboard.

Poiché l'anodo del LED (il pin più lungo) è collegato al pin 26 tramite una resistenza da 220Ω, e il catodo del LED è collegato a GND, puoi accendere il LED dando al pin 9 un livello alto.

.. image:: img/circuit/1_hello_led_bb.png

Programmazione
-------------------

L'intera programmazione è divisa in 3 parti: la prima parte consiste nella selezione dello sprite desiderato, la seconda parte riguarda il cambio del costume dello sprite per renderlo cliccabile, e la terza parte consiste nel far lampeggiare il LED.

**1. Selezionare lo sprite Button3**

Elimina lo sprite Tobi esistente utilizzando il pulsante Elimina nell'angolo in alto a destra e seleziona di nuovo uno sprite.

.. image:: img/2_tobi.png

Qui, selezioniamo lo sprite **Button3**.

.. image:: img/2_button3.png

Clicca su Costumi nell'angolo in alto a destra e vedrai che lo sprite Button3 ha 2 costumi, impostiamo **button3-a** come rilasciato e **button3-b** come premuto.

.. image:: img/2_button3_2.png

**2. Cambiare i costumi**.

Quando lo sprite viene cliccato (**tavolozza Eventi**), passa al costume **button3-b** (**tavolozza Aspetto**).

.. image:: img/2_switch.png

**3. Far lampeggiare il LED 5 volte**

Usa il blocco [Ripeti] per far lampeggiare il LED 5 volte (ciclo Alto->Basso) e infine cambia di nuovo il costume a **button3-a**.

* [Ripeti 10]: numero limitato di cicli ripetuti, puoi impostare il numero di ripetizioni tu stesso, dalla tavolozza **Controllo**.

.. image:: img/2_led_on_off.png
