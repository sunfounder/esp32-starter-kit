.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a omaggi e promozioni durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _sh_colorful_ball:

2.3 Palline Colorate
========================

In questo progetto, faremo in modo che i LED RGB visualizzino diversi colori.

Cliccando sulle diverse palline colorate nell'area del palco, il LED RGB si illuminerà in colori differenti.

.. image:: img/4_color.png

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
    *   - :ref:`cpn_rgb`
        - |link_rgb_led_buy|

Cosa Imparerai
------------------

- Il principio del LED RGB
- Copiare sprite e selezionare diversi costumi
- Sovrapposizione dei tre colori primari


Costruire il Circuito
----------------------------

Un LED RGB racchiude tre LED di colore rosso, verde e blu in un involucro di plastica trasparente o semitrasparente. Può visualizzare vari colori cambiando la tensione di ingresso dei tre pin e sovrapponendoli, il che, secondo le statistiche, può creare 16.777.216 colori diversi.

.. image:: img/4_rgb.png
    :width: 300

.. image:: img/circuit/3_color_ball_bb.png

Programmazione
-------------------

**1. Seleziona uno sprite**

Elimina lo sprite predefinito, quindi scegli lo sprite **Pallina**.

.. image:: img/4_ball.png

E duplicalo 5 volte.

.. image:: img/4_duplicate_ball.png

Scegli costumi diversi per questi 5 sprite **Pallina** e spostali nelle posizioni corrispondenti.

.. note::

    Il colore del costume dello sprite **Pallina3** deve essere cambiato manualmente in rosso.

.. image:: img/4_rgb1.png
    :width: 800

**2. Fai in modo che i LED RGB si accendano nel colore appropriato**

Prima di comprendere il codice, dobbiamo capire il `RGB color model <https://en.wikipedia.org/wiki/RGB_color_model>`_.

Il modello di colore RGB è un modello di colore additivo in cui la luce rossa, verde e blu viene aggiunta in vari modi per riprodurre una vasta gamma di colori.

Miscelazione di colori additivi: aggiungendo il rosso al verde si ottiene il giallo; aggiungendo il verde al blu si ottiene il ciano; aggiungendo il blu al rosso si ottiene il magenta; aggiungendo tutti e tre i colori primari insieme si ottiene il bianco.

.. image:: img/4_rgb_addition.png
  :width: 400

Quindi, il codice per far accendere il LED RGB in giallo è il seguente.

.. image:: img/4_yellow.png

Quando lo sprite Pallina (pallina gialla) viene cliccato, impostiamo il pin 27 su alto (LED rosso acceso), il pin 26 su alto (LED verde acceso) e il pin 25 su basso (LED blu spento) in modo che il LED RGB si illumini di giallo.

Puoi scrivere codici per gli altri sprite nello stesso modo per far sì che i LED RGB si accendano nei colori corrispondenti.

**3. Sprite Pallina2 (azzurro)**

.. image:: img/4_blue.png

**4. Sprite Pallina3 (rosso)**

.. image:: img/4_red.png

**5. Sprite Pallina4 (verde)**

.. image:: img/4_green.png

**6. Sprite Pallina5 (viola)**

.. image:: img/4_purple.png
