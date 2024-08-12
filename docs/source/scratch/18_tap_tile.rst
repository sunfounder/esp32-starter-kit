.. note::

    Ciao, benvenuto nella community SunFounder per appassionati di Raspberry Pi, Arduino ed ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto Esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti Esclusivi**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Omaggi**: Partecipa a omaggi e promozioni durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _sh_tap_tile:

2.18 GIOCO - Non Toccare la Piastrella Bianca
==================================================

Sono sicuro che molti di voi abbiano già giocato a questo gioco sui vostri telefoni. Si gioca toccando le piastrelle nere che appaiono casualmente per aggiungere punti; la velocità aumenterà sempre di più e, se si toccano le piastrelle bianche o si mancano quelle nere, il gioco termina.

Ora utilizziamo PictoBlox per replicarlo.

Inserisci due moduli di evitamento ostacoli IR verticalmente sulla breadboard. Quando la tua mano viene posizionata sopra uno dei moduli IR, apparirà un punto lampeggiante sul palco, che rappresenta un tocco effettuato.

Se il tocco avviene sulla piastrella nera, il punteggio aumenta di 1, se tocca la piastrella bianca, il punteggio diminuisce di 1.

Devi decidere se posizionare la mano sopra il modulo IR a sinistra o sopra quello a destra, a seconda della posizione della piastrella nera sul palco.

.. image:: img/21_tile.png

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
    *   - :ref:`cpn_avoid`
        - |link_avoid_buy|

Costruire il Circuito
-----------------------------

Il modulo di evitamento ostacoli è un sensore di prossimità a infrarossi con distanza regolabile, il cui output è normalmente alto e basso quando viene rilevato un ostacolo.

Ora costruisci il circuito secondo lo schema seguente.

.. image:: img/circuit/19_tap_tile_bb.png

Programmazione
---------------------------

Qui abbiamo bisogno di 3 sprite, **Tile** , **Left IR** e **Right IR**.

* Sprite **Tile**: utilizzato per ottenere l'effetto di piastrelle nere e bianche che scendono alternativamente, su un cellulare questo gioco ha generalmente 4 colonne, qui ne facciamo solo due.
* Sprite **Left IR**: utilizzato per ottenere l'effetto di clic, quando il modulo IR sinistro rileva la tua mano, invia un messaggio - **left** allo sprite **Left IR**, che inizia a funzionare. Se tocca la piastrella nera sul palco, il punteggio aumenta di 1, altrimenti diminuisce di 1.
* Sprite **Right IR**: la funzione è sostanzialmente la stessa di **Left IR**, tranne per il fatto che riceve informazioni **Right**.

**1. Disegna uno sprite Tile**.

Elimina lo sprite predefinito, passa con il mouse sopra l'icona **Aggiungi Sprite**, seleziona **Disegna** e apparirà uno sprite vuoto chiamato **Tile**.

.. image:: img/21_tile1.png

Vai alla pagina **Costumi** e utilizza lo strumento **Rettangolo** per disegnare un rettangolo.

.. image:: img/21_tile2.png

Seleziona il rettangolo e fai clic su **Copia** -> **Incolla** per creare un rettangolo identico, quindi sposta i due rettangoli in posizione allineata.

.. image:: img/21_tile01.png

Seleziona uno dei rettangoli e scegli un colore di riempimento nero.

.. image:: img/21_tile02.png

Ora seleziona entrambi i rettangoli e spostali in modo che i loro punti centrali corrispondano al centro del canvas.

.. image:: img/21_tile0.png

Duplica il costume1, alternando i colori di riempimento dei due rettangoli. Ad esempio, il colore di riempimento del costume1 è bianco a sinistra e nero a destra, e il colore di riempimento del costume2 è nero a sinistra e bianco a destra.

.. image:: img/21_tile3.png

**2. Scrivere lo script per lo sprite Tile**

Ora torna alla pagina **Blocchi** e imposta la posizione iniziale dello sprite **Tile** in modo che si trovi nella parte superiore del palco.

.. image:: img/21_tile4.png

Crea una variabile - **blocks** e assegnagli un valore iniziale per determinare il numero di volte in cui lo sprite **Tile** apparirà. Utilizza il blocco [ripeti fino a] per far diminuire gradualmente la variabile **blocks** fino a che **blocks** è 0. Durante questo tempo, fai in modo che lo sprite **Tile** cambi costume in modo casuale.

Dopo aver cliccato sulla bandiera verde, vedrai lo sprite **Tile** sul palco cambiare costume rapidamente.

.. image:: img/21_tile5.png

Crea cloni dello sprite **Tile** mentre la variabile **blocks** diminuisce, e interrompi l'esecuzione dello script quando blocks è 0. Qui vengono utilizzati due blocchi [attendi () secondi], il primo per limitare l'intervallo tra i cloni di **Tile** e il secondo per far diminuire la variabile blocks fino a 0 senza interrompere immediatamente il programma, dando all'ultimo sprite tile abbastanza tempo per muoversi.

.. image:: img/21_tile6.png

Ora script il clone dello sprite **Tile** per farlo muovere lentamente verso il basso e cancellarlo quando raggiunge il fondo del palco. La variazione della coordinata y influenza la velocità di caduta, maggiore è il valore, più veloce sarà la velocità di caduta.

.. image:: img/21_tile7.png

Nascondi il corpo e mostra il clone.

.. image:: img/21_tile8.png

**3. Leggere i valori dei 2 moduli IR**

Nello sfondo, leggi i valori dei 2 moduli IR e esegui le azioni corrispondenti.

* Se il modulo IR sinistro rileva la tua mano, trasmetti un messaggio - **left**.
* Se il modulo IR destro rileva la tua mano, trasmetti un messaggio - **right**.

.. image:: img/21_tile9.png
    :width: 800

**4. Sprite Left IR**

Ancora una volta, passa con il mouse sopra l'icona **Aggiungi sprite** e seleziona **Disegna** per creare un nuovo sprite chiamato **Left IR**.

.. image:: img/21_tile10.png

Vai alla pagina **Costumi** dello sprite **Left IR**, seleziona il colore di riempimento (qualsiasi colore diverso dal nero e dal bianco) e disegna un cerchio.

.. image:: img/21_tile11.png

Ora inizia a scrivere lo script per lo sprite **Left IR**. Quando viene ricevuto il messaggio - **left** (il modulo IR ricevitore sinistro rileva un ostacolo), determina se il blocco nero dello sprite **Tile** viene toccato, e se lo è, lascia che la variabile **count** aumenti di 1, altrimenti diminuisce di 1.

.. image:: img/21_tile12.png
.. note::

    Devi fare in modo che lo sprite **Tile** appaia sul palco e poi assorba il colore del blocco nero nello sprite **Tile**.

    .. image:: img/21_tile13.png

Ora realizziamo l'effetto di rilevamento (zoom in e out) per **Left IR**.

.. image:: img/21_tile14.png

Fai nascondere lo sprite **Left IR** quando viene cliccata la bandiera verde, mostralo quando viene ricevuto il messaggio - **left** e infine nascondilo di nuovo.

.. image:: img/21_tile15.png

**5. Sprite Right IR**

Copia lo sprite **Left IR** e rinominalo in **Right IR**.

.. image:: img/21_tile16.png

Poi cambia il messaggio ricevuto in - **right**.

.. image:: img/21_tile17.png

Ora tutto lo scripting è terminato e puoi cliccare sulla bandiera verde per eseguire lo script.
