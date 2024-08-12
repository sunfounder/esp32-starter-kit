.. note::

    Ciao, benvenuto nella community SunFounder per appassionati di Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti Esclusivi**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e Omaggi Festivi**: Partecipa a omaggi e promozioni durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _sh_fishing:

2.17 GIOCO - Pesca
=============================

In questo progetto, giochiamo a un gioco di pesca usando un pulsante.

Quando lo script è in esecuzione, i pesci nuotano a sinistra e a destra sullo schermo; devi premere il pulsante quando il pesce è quasi vicino all'amo (è consigliabile tenerlo premuto più a lungo) per catturare il pesce, e il numero di pesci catturati verrà registrato automaticamente.

.. image:: img/18_fish.png

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

Costruire il Circuito
----------------------------

Il pulsante è un dispositivo a 4 pin; poiché il pin 1 è collegato al pin 2 e il pin 3 al pin 4, quando si preme il pulsante, i 4 pin vengono collegati, chiudendo così il circuito.

.. image:: img/5_buttonc.png

Costruisci il circuito secondo lo schema seguente.

* Collega uno dei pin sul lato sinistro del pulsante al pin14, che è collegato a una resistenza di pull-down e a un condensatore da 0,1uF (104) (per eliminare i disturbi e fornire un livello stabile quando il pulsante è in funzione).
* Collega l'altro terminale della resistenza e del condensatore a GND e uno dei pin sul lato destro del pulsante a 5V.

.. image:: img/circuit/6_doorbel_bb.png

Programmazione
----------------------

Dobbiamo prima selezionare uno sfondo **Underwater**, quindi aggiungere uno sprite **Fish** e farlo nuotare avanti e indietro sullo schermo. Poi disegniamo uno sprite **Fishhook** e lo controlliamo con un pulsante per iniziare a pescare. Quando lo sprite **Fish** tocca lo sprite **Fishhook** in stato di cattura (diventa rosso), sarà catturato.

**1. Aggiungere uno sfondo**

Usa il pulsante **Scegli uno Sfondo** per aggiungere uno sfondo **Underwater**.

.. image:: img/18_under.png

**2. Sprite Fishhook**

Lo sprite **Fishhook** di solito rimane sott'acqua in stato giallo; quando si preme il pulsante, passa allo stato di pesca (rosso) e si muove sopra lo schermo.

Non c'è uno sprite **Fishhook** in Pictoblox, possiamo modificare lo sprite **Glow-J** per farlo sembrare un amo.

* Aggiungi lo sprite **Glow-J** tramite **Scegli uno Sprite**.

.. image:: img/18_hook.png

* Ora vai alla pagina **Costumi** dello sprite **Glow-J**, seleziona il riempimento ciano sullo schermo e rimuovilo. Poi cambia il colore della J in rosso e riduci anche la sua larghezza. Il punto più importante da notare è che la parte superiore deve trovarsi esattamente al centro.

.. image:: img/18_hook1.png

* Usa lo **Strumento Linea** per tracciare una linea il più lunga possibile dal punto centrale verso l'alto (la linea esce dal palco). Ora che lo sprite è disegnato, imposta il nome dello sprite su **Fishhook** e spostalo nella posizione corretta.

.. image:: img/18_hook2.png

* Quando si clicca sulla bandiera verde, imposta l'effetto colore dello sprite a 30 (giallo) e imposta la sua posizione iniziale.

.. image:: img/18_hook3.png


* Se il pulsante viene premuto, imposta l'effetto colore a 0 (rosso, stato di pesca), aspetta 0,1 secondi e poi sposta lo sprite **Fishhook** nella parte superiore dello schermo. Rilascia il pulsante e lascia che il **Fishhook** ritorni alla sua posizione iniziale.

.. image:: img/18_hook4.png

**3. Sprite Fish**

L'effetto da ottenere con lo sprite **Fish** è che si muove a sinistra e a destra sullo schermo, e quando incontra uno sprite **Fishhook** in stato di pesca, si rimpicciolisce, si sposta in una posizione specifica e poi scompare, clonando un nuovo sprite **Fish**.

* Ora aggiungi lo sprite **Fish** e regola la sua dimensione e posizione.

.. image:: img/18_fish1.png

* Crea una variabile **score** per memorizzare il numero di pesci catturati, nascondi questo sprite e clonalo.

.. image:: img/18_fish2.png


* Mostra il clone dello sprite **Fish**, cambia il suo costume e infine imposta la posizione iniziale.

.. image:: img/18_fish3.png


* Fai muovere il clone dello sprite **Fish** a sinistra e a destra, facendolo rimbalzare quando tocca il bordo.

.. image:: img/18_fish4.png


* Lo sprite **Fish** (del clone) non reagirà quando passerà vicino allo sprite **Fishhook**; quando toccherà lo sprite **Fishhook** in stato di pesca (diventa rosso), sarà catturato, a questo punto il punteggio (variabile score) aumenterà di 1, e verrà visualizzata anche un'animazione di punteggio (rimpicciolimento del 40%, rapido spostamento nella posizione del punteggio e scomparsa). Contemporaneamente, verrà creato un nuovo pesce (un nuovo clone dello sprite Fish) e il gioco continuerà.

.. note::
    
    Devi cliccare sull'area colore nel blocco [Tocca colore], quindi selezionare lo strumento contagocce per raccogliere il colore rosso dello sprite **Fishhook** sul palco. Se scegli un colore arbitrariamente, questo blocco [Tocca colore] non funzionerà.


.. image:: img/18_fish5.png
