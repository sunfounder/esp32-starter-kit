.. note::

    Ciao, benvenuto nella community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a omaggi e promozioni durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _sh_light_ball:

2.10 Palla Sensibile alla Luce
=================================

In questo progetto, utilizziamo un fotoresistore per far volare la palla sullo schermo verso l'alto. Posiziona la mano sopra il fotoresistore per controllare l'intensità della luce che riceve. Più la tua mano è vicina al fotoresistore, minore sarà il suo valore e più la palla volerà in alto sullo schermo; altrimenti cadrà. Quando la palla tocca la linea, emette un piacevole suono e un bagliore stellare scintillante.

.. image:: img/18_ball.png

Componenti Necessari
----------------------

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
    *   - :ref:`cpn_photoresistor`
        - |link_photoresistor_buy|

Cosa Imparerai
-------------------

- Riempire la sprite con colori
- Riconoscere il tocco tra le sprite

Costruire il Circuito
---------------------------

Un fotoresistore o fotocellula è un resistore variabile controllato dalla luce. La resistenza di un fotoresistore diminuisce con l'aumentare dell'intensità della luce incidente.

Costruisci il circuito seguendo lo schema seguente.

Collega un'estremità del fotoresistore a 5V, l'altra estremità al pin 35, e collega un resistore da 10K in serie con il GND a questa estremità.

Quando l'intensità della luce aumenta, la resistenza del fotoresistore diminuisce, la divisione della tensione del resistore da 10K aumenta e il valore ottenuto dal pin 35 diventa maggiore.

.. image:: img/circuit/8_light_alarm_bb.png

Programmazione
--------------------

L'effetto che vogliamo ottenere è che più la tua mano è vicina al fotoresistore, più la sprite a forma di palla sullo schermo continuerà a salire; altrimenti cadrà sulla sprite a forma di ciotola. Se tocca la sprite Line mentre sale o scende, emetterà un suono musicale e spruzzerà sprite stellari in tutte le direzioni.


**1. Selezionare sprite e sfondo**

Elimina la sprite predefinita, seleziona le sprite **Palla**, **Ciotola** e **Stella**.

.. image:: img/18_ball1.png

Sposta la sprite **Ciotola** al centro inferiore dello schermo e ingrandisci le sue dimensioni.

.. image:: img/18_ball3.png

Poiché dobbiamo spostarla verso l'alto, imposta la direzione della sprite **Palla** su 0.

.. image:: img/18_ball4.png

Imposta la dimensione e la direzione della sprite **Stella** su 180 perché dobbiamo farla cadere, oppure puoi cambiarla in un altro angolo.

.. image:: img/18_ball12.png

Ora aggiungi lo sfondo **Stelle**.

.. image:: img/18_ball2.png

**2. Disegna una sprite Linea**

Aggiungi una sprite Linea.

.. image:: img/18_ball7.png

Vai alla pagina **Costumi** della sprite **Linea**, riduci leggermente la larghezza della linea rossa sulla tela, quindi copiala 5 volte e allinea le linee.

.. image:: img/18_ball8.png

Ora riempi le linee con colori diversi. Scegli prima un colore che ti piace, quindi clicca sullo strumento **Riempimento** e sposta il mouse sulla linea per riempirla di colore.

.. image:: img/18_ball9.png

Segui lo stesso metodo per cambiare il colore delle altre linee.

.. image:: img/18_ball10.png


**3. Scrivere lo script per la sprite Palla**

Imposta la posizione iniziale della sprite **Palla**, poi quando il valore della luce è inferiore a 1500 (può essere qualsiasi altro valore, a seconda del tuo ambiente attuale), fai in modo che la Palla si muova verso l'alto.

Puoi fare in modo che la variabile light_value appaia sullo schermo per osservare il cambiamento dell'intensità della luce in qualsiasi momento.

.. image:: img/18_ball5.png

Altrimenti, la sprite **Palla** cadrà e limiterà la sua coordinata Y a un minimo di -100. Questo può essere modificato per farla sembrare che cada sulla sprite **Ciotola**.

.. image:: img/18_ball6.png

Quando la sprite **Linea** viene colpita, la coordinata Y corrente viene salvata nella variabile **ball_coor** e viene trasmesso un messaggio **Bling**.

.. image:: img/18_ball11.png

**4. Scrivere lo script per la sprite Stella**

Quando lo script inizia, nascondi la sprite **Stella**. Quando viene ricevuto il messaggio **Bling**, clona la sprite **Stella**.

.. image:: img/18_ball13.png

Quando la sprite **Stella** appare come clone, riproduci l'effetto sonoro e imposta le sue coordinate per sincronizzarle con la sprite **Palla**.

.. image:: img/18_ball14.png

Crea l'effetto della sprite **Stella** che appare e regola come necessario.

.. image:: img/18_ball15.png
