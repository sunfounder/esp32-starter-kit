.. note::

    Ciao, benvenuto nella community di SunFounder per appassionati di Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti Esclusivi**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Omaggi Festivi**: Partecipa a omaggi e promozioni durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _sh_breakout_clone:

2.16 GIOCO - Breakout Clone
=================================

In questo progetto, utilizziamo il potenziometro per giocare a Breakout Clone.

Dopo aver cliccato sulla bandiera verde, devi usare il potenziometro per controllare la paletta sullo schermo e catturare la pallina in modo che possa salire e colpire i mattoncini. Se tutti i mattoncini scompaiono, hai vinto il gioco; se non catturi la pallina, il gioco è perso.

.. image:: img/17_brick.png

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
    *   - :ref:`cpn_pot`
        - |link_potentiometer_buy|

Costruire il Circuito
-------------------------

Il potenziometro è un elemento resistivo con 3 terminali; i 2 pin laterali sono collegati a 5V e GND, mentre il pin centrale è collegato al pin35. Dopo la conversione tramite il convertitore ADC della scheda ESP32, l'intervallo dei valori è 0-4095.

.. image:: img/circuit/5_moving_mouse_bb.png

Programmazione
----------------------

Ci sono 3 sprite sullo schermo.

**1. Sprite Paddle**

L'effetto da ottenere con la sprite **Paddle** è che la posizione iniziale sia al centro della parte inferiore dello schermo, e venga controllata da un potenziometro per muoversi a sinistra o a destra.

* Elimina la sprite predefinita, usa il pulsante **Scegli una Sprite** per aggiungere la sprite **Paddle** e imposta le sue coordinate x e y su (0, -140).

    .. image:: img/17_padd1.png

* Vai alla pagina **Costumi**, rimuovi il contorno e cambia il colore in grigio scuro.

    .. image:: img/17_padd3.png

* Ora scrivi lo script per la sprite **Paddle** per impostare la sua posizione iniziale su (0, -140) quando si clicca sulla bandiera verde, e leggi il valore del pin35 (potenziometro) nella variabile **a0**. Poiché la sprite **Paddle** si muove da sinistra a destra sullo schermo con coordinate x comprese tra -195 e 195, è necessario utilizzare il blocco [map] per mappare l'intervallo della variabile **a0** da 0~4095 a -195~195. 

    .. image:: img/17_padd2.png

* Ora puoi ruotare il potenziometro per vedere se la sprite **Paddle** può muoversi a sinistra e a destra sullo schermo.

**2. Sprite Ball**

L'effetto della sprite **Ball** è che si muove intorno allo schermo e rimbalza quando tocca il bordo; rimbalza verso il basso se tocca il blocco sopra lo schermo; rimbalza verso l'alto se tocca la sprite Paddle durante la sua caduta; se non lo fa, lo script smette di funzionare e il gioco finisce.

* Aggiungi la sprite **Ball**.

    .. image:: img/17_ball1.png

* Quando si clicca sulla bandiera verde, imposta l'angolo della sprite **Ball** a 45° e la posizione iniziale su (0, -120).

    .. image:: img/17_ball2.png

* Ora lascia che la sprite **Ball** si muova intorno allo schermo e rimbalzi quando tocca il bordo; puoi cliccare sulla bandiera verde per vedere l'effetto.

    .. image:: img/17_ball3.png

* Quando la sprite **Ball** tocca la sprite **Paddle**, esegui una riflessione. Il modo più semplice per farlo è invertire direttamente l'angolo, ma noterai che il percorso della palla è completamente fisso, il che è troppo noioso. Pertanto, utilizziamo il centro delle due sprite per calcolare e far rimbalzare la palla nella direzione opposta al centro della paletta.

    .. image:: img/17_ball4.png

    .. image:: img/17_ball6.png

* Quando la sprite **Ball** cade al bordo dello schermo, lo script smette di funzionare e il gioco finisce.

    .. image:: img/17_ball5.png


**3. Sprite Block1**

L'effetto della sprite **Block1** è quello di clonare se stessa in una griglia di 4x8 nella parte superiore dello schermo con colori casuali, e di eliminare un clone se toccato dalla sprite **Ball**.

La sprite **Block1** non è disponibile nella libreria **PictoBlox**; devi disegnarla tu stesso o modificarla partendo da una sprite esistente. Qui la modificheremo partendo dalla sprite **Button3**.

* Dopo aver aggiunto la sprite **Button3**, vai alla pagina **Costumi**. Ora elimina **button-a**, poi riduci sia la larghezza che l'altezza di **button-b** e cambia il nome della sprite in **Block1**, come mostrato nell'immagine seguente.

    .. note::

        * Per la larghezza di **Block1**, puoi simulare lo schermo per vedere se riesci a metterne 8 in fila; in caso contrario, riduci opportunamente la larghezza.
        * Durante il processo di riduzione della sprite **Block1**, devi mantenere il punto centrale al centro della sprite.

    .. image:: img/17_bri2.png

* Ora crea prima 2 variabili, **block** per memorizzare il numero di blocchi e **roll** per memorizzare il numero di righe.

    .. image:: img/17_bri3.png

* Dobbiamo clonare la sprite **Block1** in modo che venga visualizzata da sinistra a destra, dall'alto verso il basso, una per una, in un totale di 4x8, con colori casuali.

    .. image:: img/17_bri4.png

* Dopo aver scritto lo script, clicca sulla bandiera verde e guarda la visualizzazione sullo schermo; se è troppo compatto o troppo piccolo, puoi cambiare la dimensione.

    .. image:: img/17_bri5.png

* Ora scrivi l'evento di trigger. Se la sprite clonata **Block1** tocca la sprite **Ball**, elimina il clone e trasmetti il messaggio **crush**.

    .. image:: img/17_bri6.png

* Torna alla sprite **Ball**; quando riceve la trasmissione **crush** (la sprite **Ball** tocca il clone della sprite **Block1**), la **Ball** rimbalza nella direzione opposta.

    .. image:: img/17_ball7.png
