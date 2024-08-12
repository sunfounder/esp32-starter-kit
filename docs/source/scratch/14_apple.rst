.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a omaggi e promozioni durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _sh_eat_apple:

2.14 GIOCO - Mangiare la Mela
==================================

In questo progetto, giocheremo a un gioco in cui si utilizza un pulsante per controllare lo Scarabeo e fargli mangiare una mela.

Quando si clicca sulla bandiera verde, premi il pulsante e lo Scarabeo ruoterà; premi nuovamente il pulsante e lo Scarabeo smetterà di ruotare e si muoverà in avanti con quell'angolazione. Devi controllare l'angolo dello Scarabeo in modo che si muova in avanti senza toccare la linea nera sulla mappa fino a mangiare la mela. Se tocca la linea nera, il gioco finisce.

.. image:: img/14_apple.png

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
---------------------------

Il pulsante è un dispositivo a 4 pin; poiché il pin 1 è collegato al pin 2 e il pin 3 al pin 4, quando il pulsante viene premuto, i 4 pin sono collegati, chiudendo così il circuito.

.. image:: img/5_buttonc.png

Costruisci il circuito secondo il diagramma seguente.

* Collega uno dei pin sul lato sinistro del pulsante al pin 14, che è collegato a una resistenza pull-down e a un condensatore da 0,1uF (104) (per eliminare il jitter e fornire un livello stabile quando il pulsante è in funzione).
* Collega l'altro capo della resistenza e del condensatore a GND e uno dei pin sul lato destro del pulsante a 5V.

.. image:: img/circuit/6_doorbel_bb.png

Programmazione
-------------------
L'effetto che vogliamo ottenere è utilizzare il pulsante per controllare la direzione della sprite **Scarabeo** affinché si muova in avanti e mangi la mela senza toccare la linea nera sullo sfondo **Labirinto**; una volta mangiata la mela, lo sfondo cambierà.

Ora aggiungi gli sfondi e le sprite pertinenti.

**1. Aggiungere sfondi e sprite**

Aggiungi uno sfondo **Labirinto** tramite il pulsante **Scegli uno sfondo**.

.. image:: img/14_backdrop.png

Elimina la sprite predefinita, quindi seleziona la sprite **Scarabeo**.

.. image:: img/14_sprite.png

Posiziona la sprite **Scarabeo** all'ingresso dello sfondo **Labirinto**, ricordando i valori delle coordinate x,y a questo punto, e ridimensiona la sprite al 40%.

.. image:: img/14_sprite1.png

**2. Disegna uno sfondo**

Ora è il momento di disegnare semplicemente uno sfondo con il carattere WIN! che appare su di esso.

Per prima cosa, clicca sulla miniatura dello sfondo per accedere alla pagina **Sfondi** e clicca sullo sfondo vuoto 1.

.. image:: img/14_paint_back.png
    :width: 800

Ora inizia a disegnare; puoi fare riferimento all'immagine qui sotto o disegnare uno sfondo tuo, purché esprima la vittoria.

* Usa lo strumento **Cerchio** per disegnare un'ellisse con il colore impostato su rosso e senza contorno.
* Poi usa lo strumento **Testo**, scrivi il carattere "WIN!", imposta il colore del carattere su nero e regola la dimensione e la posizione del carattere.
* Nomina lo sfondo come **Win**.

.. image:: img/14_win.png

**3. Programmare lo sfondo**

Lo sfondo deve essere cambiato su **Labirinto** ogni volta che il gioco inizia.

.. image:: img/14_switchback.png

**4. Scrivere gli script per la sprite Scarabeo**

Ora scrivi uno script per la sprite **Scarabeo** affinché possa muoversi in avanti e cambiare direzione sotto il controllo di un pulsante. Il flusso di lavoro è il seguente.

* Quando si clicca sulla bandiera verde, imposta l'angolo dello **Scarabeo** a 90 e la posizione a (-134, -134), oppure sostituiscila con il valore delle coordinate della tua posizione. Crea la variabile **flag** e imposta il valore iniziale a -1.

.. image:: img/14_bee1.png

Successivamente, nel blocco [per sempre], vengono utilizzati quattro blocchi [se] per determinare vari possibili scenari.

* Se il pulsante è 1 (premuto), usa il blocco [`mod <https://en.scratch-wiki.info/wiki/Boolean_Block>`_] per alternare il valore della variabile **flag** tra 0 e 1 (alternando tra 0 per questa pressione e 1 per la prossima pressione).

.. image:: img/14_bee2.png

* Se flag=0 (questa pressione del pulsante), fai ruotare la sprite **Scarabeo** in senso orario. Poi determina se flag è uguale a 1 (pulsante premuto di nuovo), la sprite **Scarabeo** si muove in avanti. Altrimenti, continua a ruotare in senso orario.

.. image:: img/14_bee3.png

* Se la sprite Scarabeo tocca il nero (la linea nera sullo sfondo **Labirinto**), il gioco finisce e lo script smette di funzionare.

.. note::
    
    Devi cliccare sull'area colore nel blocco [Tocca colore], e poi selezionare lo strumento contagocce per prelevare il colore della linea nera sul palco. Se scegli un nero a caso, questo blocco [Tocca colore] non funzionerà.

.. image:: img/14_bee5.png

* Se Scarabeo tocca il rosso (utilizza anche lo strumento contagocce per prelevare il colore rosso della mela), lo sfondo verrà cambiato in **Win**, il che significa che il gioco ha successo e lo script smette di funzionare.

.. image:: img/14_bee4.png
