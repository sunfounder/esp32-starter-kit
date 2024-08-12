.. note::

    Ciao, benvenuto nella community di appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci dei nuovi prodotti e alle anticipazioni.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e giveaway festivi**: Partecipa a giveaway e promozioni festive.

    👉 Pronto per esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _sh_protect_heart:

2.19 GIOCO - Proteggi il tuo Cuore
=========================================

In questo progetto, realizziamo un gioco che testa la velocità di reazione.

Sul palco, c'è un cuore protetto in una scatola rettangolare, e ci sono frecce che volano verso questo cuore da qualsiasi posizione sul palco. Il colore della freccia alterna casualmente tra nero e bianco e la freccia volerà sempre più velocemente.

Se il colore della scatola rettangolare e il colore della freccia sono gli stessi, la freccia viene bloccata all'esterno e il livello aumenta di 1; se i colori sono diversi, la freccia attraverserà il cuore e il gioco è finito.

Qui il colore della scatola rettangolare è controllato dal modulo Line Tracking. Quando il modulo viene posizionato su una superficie nera (una superficie riflettente), il colore della scatola rettangolare è nero, altrimenti è bianco.

Quindi devi decidere se posizionare il modulo Line Tracking su una superficie bianca o su una superficie nera in base al colore della freccia.

.. image:: img/22_heart.png

Componenti Necessari
--------------------------

In questo progetto, abbiamo bisogno dei seguenti componenti.

È sicuramente conveniente acquistare un kit completo, ecco il link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Nome
        - OGGETTI IN QUESTO KIT
        - LINK
    *   - Kit di avvio ESP32
        - 320+
        - |link_esp32_starter_kit|

Puoi anche acquistarli separatamente dai link qui sotto.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - INTRODUZIONE AL COMPONENTE
        - LINK PER L'ACQUISTO

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - |link_esp32_extension_board|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_line_track`
        - |link_line_track_buy|

Costruisci il Circuito
-----------------------------

Questo è un modulo Line Tracking digitale, quando rileva una linea nera, emette 1; quando rileva una linea bianca, emette un valore di 0. Inoltre, puoi regolare la sua distanza di rilevamento tramite il potenziometro sul modulo.

Ora costruisci il circuito secondo lo schema sotto.

.. image:: img/circuit/20_protect_heart_bb.png

.. note::

    Prima di iniziare il progetto, devi regolare la sensibilità del modulo.

    Collega i cavi secondo lo schema sopra, quindi alimenta la scheda R3 (inserendo direttamente il cavo USB o il cavo con pulsante della batteria da 9V), senza caricare il codice.

    Ora incolla un nastro elettrico nero sulla scrivania, posiziona il modulo Line Track a un'altezza di 2 cm dalla scrivania.

    Con il sensore rivolto verso il basso, osserva il LED di segnalazione sul modulo per assicurarti che si accenda sul tavolo bianco e si spenga sul nastro nero.

    In caso contrario, è necessario regolare il potenziometro sul modulo in modo che possa ottenere l'effetto sopra descritto.

Programmazione
-------------------

Qui dobbiamo creare 3 sprite: **Cuore**, **Scatola Rettangolare** e **Freccia1**.

* **Cuore**: resta fermo al centro del palco, se viene toccato dallo sprite **Freccia1**, il gioco è finito.
* **Scatola Rettangolare**: Ha due tipi di costumi, nero e bianco, e cambierà costume in base al valore del modulo Line Tracking.
* **Freccia**: vola verso il centro del palco da qualsiasi posizione in nero/bianco; se il suo colore corrisponde al colore dello sprite **Scatola Rettangolare**, viene bloccato e ri-vola verso il centro del palco da una posizione casuale; se il suo colore non corrisponde al colore dello sprite **Scatola Rettangolare**, passa attraverso lo sprite **Cuore** e il gioco è finito.

**1. Aggiungi lo sprite Scatola Rettangolare**

Poiché lo sprite Freccia1 e lo sprite Scatola Rettangolare hanno entrambi costumi bianchi, per farli apparire sul palco, ora riempi lo sfondo con un colore che può essere qualsiasi colore tranne nero, bianco e rosso.

* Clicca su **Backdrop1** per andare alla sua pagina **Backdrops**.
* Seleziona il colore che vuoi riempire.
* Usa lo strumento **Rettangolo** per disegnare un rettangolo delle stesse dimensioni della tavola da disegno.

.. image:: img/22_heart0.png

Elimina lo sprite predefinito, usa il pulsante **Scegli uno Sprite** per aggiungere lo sprite **Scatola Rettangolare** e imposta le sue coordinate x e y su (0, 0).

.. image:: img/22_heart1.png

Vai alla pagina **Costumi** dello sprite **Scatola Rettangolare** e imposta i costumi nero e bianco.

* Clicca sullo strumento selezione
* Seleziona il rettangolo sulla tela
* Seleziona il colore di riempimento come nero
* e nomina il costume **Nero**

.. image:: img/22_heart2.png

Seleziona il secondo costume, imposta il colore di riempimento su bianco, nomina il costume **Bianco** ed elimina il resto dei costumi.

.. image:: img/22_heart3.png

**2. Aggiungi lo sprite Cuore**

Aggiungi anche uno sprite **Cuore**, imposta la sua posizione su (0, 0) e riduci le sue dimensioni in modo che appaia situato all'interno della Scatola Rettangolare.

.. image:: img/22_heart5.png

Nella pagina **Costumi**, modifica il costume viola del cuore in modo che appaia spezzato.

.. image:: img/22_heart6.png

**3. Aggiungi lo sprite Freccia1**

Aggiungi uno sprite **Freccia1**.

.. image:: img/22_heart7.png

Nella pagina **Costumi**, conserva e copia il costume rivolto verso destra e imposta il suo colore su nero e bianco.

.. image:: img/22_heart8.png

**4. Script per lo sprite Scatola Rettangolare**

Torna alla pagina **Blocks** e scrivi lo script per lo sprite **Scatola Rettangolare**.

* Quindi, quando il valore del pin digitale 2 (modulo Line Tracking) è 1 (linea nera rilevata), cambia il costume in **Nero**.
* Altrimenti, cambia il costume in **Bianco**.

.. image:: img/22_heart4.png


**5. Script per lo sprite Cuore**

Lo sprite **Cuore** è protetto all'interno della **Scatola Rettangolare** e di default ha un costume rosso. Quando lo sprite Freccia1 viene toccato, il gioco finisce.

.. image:: img/22_heart9.png

**6. Script per lo sprite Freccia1**

Fai nascondere lo sprite **Freccia1** e crea un clone quando viene cliccata la bandiera verde.

.. image:: img/22_heart10.png

Crea un blocco [init] per inizializzare la posizione, l'orientamento e il colore dello sprite **Freccia1**.

Appare in una posizione casuale, e se la distanza tra esso e lo sprite **Cuore** è inferiore a 200, si muove verso l'esterno fino a quando la distanza non supera i 200.

.. image:: img/22_heart11.png

Imposta la sua direzione per affrontare lo sprite **Cuore**.

.. image:: img/22_heart12.png

Fai in modo che il suo colore alterni casualmente tra nero e bianco.

* La variabile color è 0, cambia il costume in **Bianco**.
* La variabile color è 1, cambia il costume in **Nero**.

.. image:: img/22_heart14.png

Ora fai iniziare il movimento, si muoverà più velocemente man mano che il valore della variabile **level** aumenta.

.. image:: img/22_heart13.png

Ora imposta il suo effetto di collisione con lo sprite **Scatola Rettangolare**.

* Se lo sprite **Freccia1** e lo sprite **Scatola Rettangolare** hanno lo stesso colore (che sarà modificato in base al valore del modulo Line Track), sia nero che bianco, viene creato un nuovo clone e il gioco continua.
* Se i loro colori non corrispondono, lo sprite **Freccia1** continua a muoversi e il gioco finisce quando colpisce lo sprite **Cuore**.

.. image:: img/22_heart15.png

.. note::
    I due blocchi [touch color()] devono rilevare i costumi neri/bianchi di Square Box separatamente.

    .. image:: img/22_heart16.png
