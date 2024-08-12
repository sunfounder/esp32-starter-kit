.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a omaggi e promozioni durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _sh_breathing_led:

2.2 LED a Respirazione
==============================

Ora utilizziamo un altro metodo per controllare la luminosità del LED. A differenza del progetto precedente, qui la luminosità del LED diminuisce lentamente fino a scomparire.

Quando lo sprite sul palco viene cliccato, la luminosità del LED aumenta lentamente per poi spegnersi istantaneamente.

.. image:: img/3_ap.png

Componenti Necessari
----------------------------

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
---------------------



- Impostare il valore di uscita del pin PWM
- Creare variabili
- Cambiare la luminosità dello sprite



Costruire il Circuito
------------------------

Questo progetto utilizza lo stesso circuito del progetto precedente :ref:`sh_table_lamp`, ma invece di utilizzare HIGH/LOW per accendere o spegnere i LED, questo progetto utilizza il segnale `PWM - Wikipedia <https://en.wikipedia.org/wiki/Pulse-width_modulation>`_ per accendere lentamente o spegnere il LED.

L'intervallo del segnale PWM è 0-255, sulla scheda ESP32, i pin 2, 5, 12~15, 18, 19, 21, 22, 25, 26 e 27 possono emettere segnali PWM.

.. image:: img/circuit/1_hello_led_bb.png

Programmazione
--------------------

**1. Seleziona uno sprite**

Elimina lo sprite predefinito, fai clic sul pulsante **Scegli uno Sprite** nell'angolo in basso a destra dell'area degli sprite, inserisci **button3** nella casella di ricerca e poi clicca per aggiungerlo.

.. image:: img/3_sprite.png

**2. Creazione di una variabile**

Crea una variabile chiamata **pwm** per memorizzare il valore della modifica del pwm.

Clicca sulla tavolozza **Variabili** e seleziona **Crea una Variabile**.

.. image:: img/3_ap_va.png

Inserisci il nome della variabile, può essere qualsiasi nome, ma è consigliabile descrivere la sua funzione. Il tipo di dato è numero e per tutti gli sprite.

.. image:: img/3_ap_pwm.png

Una volta creata, vedrai **pwm** all'interno della tavolozza **Variabili** e in stato selezionato, il che significa che questa variabile apparirà sul palco. Puoi provare a deselezionarla per vedere se pwm è ancora presente sul palco.

.. image:: img/3_ap_0.png

**3. Impostare lo stato iniziale**

Quando lo sprite **button3** viene cliccato, passa al costume **button-b** (stato cliccato) e imposta il valore iniziale della variabile **pwm** a 0.

* [imposta pwm a 0]: dalla tavolozza **Variabili**, utilizzato per impostare il valore della variabile.

.. image:: img/3_ap_brightness.png

**4. Far diventare il LED sempre più luminoso**

Poiché l'intervallo di pwm è 255, quindi tramite il blocco [ripeti], la variabile **pwm** viene accumulata fino a 255 di 5 in 5, e poi inserita nel blocco [imposta pin PWM], in modo che il LED si accenda lentamente.

* [cambia pwm di 5]: dalla tavolozza **Variabili**, lascia che la variabile cambi di un numero specifico ogni volta. Può essere un numero positivo o negativo, positivo aumenta ogni volta, negativo diminuisce ogni volta, ad esempio, qui la variabile pwm aumenta di 5 ogni volta.
* [imposta pin PWM]: dalla tavolozza **ESP32**, utilizzato per impostare il valore di uscita del pin pwm.

.. image:: img/3_ap_1.png

Infine, cambia di nuovo il costume di button3 a **button-a** e imposta il valore del pin PWM a 0, in modo che il LED si accenda lentamente e poi si spenga di nuovo.

.. image:: img/3_ap_2.png
