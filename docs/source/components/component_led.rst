.. note::

    Ciao, benvenuto nella community di appassionati di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_led:

LED
==========

**Cos'è un LED?**

.. image:: img/led_pin.jpg
    :width: 200

.. image:: img/led_polarity.jpg
    :width: 400

I LED sono dispositivi elettronici molto comuni che possono essere utilizzati per decorare la tua stanza durante le festività, oppure come indicatori per varie funzioni, come ad esempio indicare se un elettrodomestico è acceso o spento. Esistono in una vasta gamma di forme e dimensioni, ma i più comuni sono i LED con terminali a foro passante, che generalmente hanno gambe lunghe e possono essere inseriti in una breadboard.

Il nome completo del LED è diodo emettitore di luce, quindi ha le caratteristiche di un diodo, in cui la corrente fluisce in una sola direzione, dall'anodo (positivo) al catodo (negativo).

Ecco i simboli elettrici dei LED.

.. image:: img/led_symbol.png


**Varie dimensioni e colori**

.. image:: img/led_color.png

Rosso, giallo, blu, verde e bianco sono i colori più comuni dei LED, e la luce emessa solitamente corrisponde al colore dell'aspetto.

Raramente utilizziamo LED che sono trasparenti o opachi nell'aspetto, ma la luce emessa potrebbe essere di un colore diverso dal bianco.

I LED sono disponibili in quattro dimensioni: 3mm, 5mm, 8mm e 10mm, con 5mm come dimensione più comune.

.. image:: img/led_type.jpg

Di seguito è riportata la dimensione del LED da 5mm espressa in mm.

.. image:: img/led_size.png



**Tensione diretta**

La Tensione Diretta è un parametro molto importante da conoscere quando si utilizzano i LED, poiché determina quanta energia viene utilizzata e quanto deve essere grande la resistenza limitatrice di corrente.

La Tensione Diretta è la tensione che il LED richiede per accendersi. Per la maggior parte dei LED rossi, gialli, arancioni e verde chiaro, la tensione generalmente varia tra 1.9V e 2.1V.


.. image:: img/led_voltage.jpg
    :width: 400
    :align: center


Secondo la legge di Ohm, la corrente che attraversa questo circuito diminuisce man mano che aumenta la resistenza, il che provoca l'attenuazione della luminosità del LED.

    I = (Vp-Vl)/R

Per far accendere i LED in modo sicuro e con la giusta luminosità, quale resistenza dovremmo utilizzare nel circuito?

Per il 99% dei LED da 5mm, la corrente raccomandata è 20mA, come puoi vedere nella colonna Condizioni del suo datasheet.

.. image:: img/led_datasheet.png

Ora converti la formula sopra come mostrato di seguito.

    R = (Vp-Vl)/I


Se ``Vp`` è 5V, ``Vl`` (Tensione Diretta) è 2V e ``I`` è 20mA, allora ``R`` è 150Ω.

Quindi possiamo aumentare la luminosità del LED riducendo la resistenza del resistore, ma non è consigliabile scendere sotto i 150Ω (questa resistenza potrebbe non essere molto precisa, poiché diversi fornitori di LED possono avere differenze).

Di seguito sono riportate le tensioni dirette e le lunghezze d'onda dei diversi colori di LED che puoi utilizzare come riferimento.

.. list-table::
   :widths: 25 25 50
   :header-rows: 1

   * - Colore del LED
     - Tensione Diretta
     - Lunghezza d'onda
   * - Rosso
     - 1.8V ~ 2.1V
     - 620 ~ 625 nm
   * - Giallo
     - 1.9V ~ 2.2V
     - 580 ~ 590 nm
   * - Verde
     - 1.9V ~ 2.2V
     - 520 ~ 530 nm
   * - Blu
     - 3.0V ~ 3.2V
     - 460 ~ 465 nm
   * - Bianco
     - 3.0V ~ 3.2V
     - 8000 ~ 9000 K

**Esempio**

* :ref:`ar_blink` (Progetto Arduino)
* :ref:`ar_fading` (Progetto Arduino)
* :ref:`py_blink` (Progetto MicroPython)
* :ref:`py_fading` (Progetto MicroPython)
* :ref:`sh_breathing_led` (Progetto Scratch)
* :ref:`sh_table_lamp` (Progetto Scratch)

