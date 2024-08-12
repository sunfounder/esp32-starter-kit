.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a omaggi e promozioni durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _sh_parrot:

2.15 GIOCO - Flappy Parrot
================================

In questo progetto, utilizzeremo il modulo a ultrasuoni per giocare a Flappy Parrot.

Dopo l'avvio dello script, il bambù verde si muoverà lentamente da destra a sinistra ad un'altezza casuale. Ora posiziona la mano sopra il modulo a ultrasuoni; se la distanza tra la mano e il modulo è inferiore a 10 cm, il pappagallo volerà verso l'alto, altrimenti cadrà verso il basso.
Devi controllare la distanza tra la tua mano e il modulo a ultrasuoni in modo che il pappagallo possa evitare il bambù verde (Paddle); se lo tocca, il gioco finisce.

.. image:: img/15_parrot.png

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|

Costruire il Circuito
----------------------------

Un modulo sensore a ultrasuoni è uno strumento che misura la distanza da un oggetto utilizzando onde sonore ultrasoniche. 
Ha due sonde: una per inviare le onde ultrasoniche e l'altra per riceverle e trasformare il tempo di invio e ricezione in una distanza, rilevando così la distanza tra il dispositivo e un ostacolo.

Ora costruisci il circuito secondo il diagramma seguente.

.. image:: img/circuit/16_flappy_parrot_bb.png

Programmazione
--------------------

L'effetto che vogliamo ottenere è utilizzare il modulo a ultrasuoni per controllare l'altezza di volo della sprite **Parrot**, evitando allo stesso tempo la sprite **Paddle**.


**1. Aggiungere una sprite**

Elimina la sprite predefinita e usa il pulsante **Scegli una Sprite** per aggiungere la sprite **Parrot**. Imposta la sua dimensione al 50% e spostala nella posizione in basso a sinistra.

.. image:: img/15_sprite.png

Ora aggiungi la sprite **Paddle**, imposta la sua dimensione al 150%, imposta l'angolo a 180 e sposta la sua posizione iniziale nell'angolo in alto a destra.

.. image:: img/15_sprite1.png

Vai alla pagina **Costumi** della sprite **Paddle** e rimuovi il contorno.

.. image:: img/15_sprite2.png

**2. Script per la Sprite Parrot**

Ora crea lo script per la sprite **Parrot**, che sarà in volo e l'altitudine di volo sarà determinata dalla distanza rilevata dal modulo a ultrasuoni.

* Quando si clicca sulla bandiera verde, cambia costume ogni 0,2 secondi in modo che sia sempre in volo.

.. image:: img/15_parr1.png

* Leggi il valore del modulo a ultrasuoni e memorizzalo nella variabile **distance** dopo averlo arrotondato con il blocco [round].

.. image:: img/15_parr2.png

* Se la distanza di rilevamento degli ultrasuoni è inferiore a 10 cm, aumenta la coordinata y di 50; la sprite **Parrot** volerà verso l'alto. Altrimenti, il valore della coordinata y verrà diminuito di 40, e **Parrot** cadrà verso il basso.

.. image:: img/15_parr3.png

* Se la sprite **Parrot** tocca la sprite **Paddle**, il gioco finisce e lo script smette di funzionare.

.. image:: img/15_parr4.png


**3. Script per la sprite Paddle**

Ora scrivi lo script per la sprite **Paddle**, che deve apparire casualmente sul palco.

* Nascondi la sprite **Paddle** quando si clicca sulla bandiera verde e clona se stessa allo stesso tempo. Il blocco [`create clone of <https://en.scratch-wiki.info/wiki/Create_Clone_of_()_(block)>`_] è un blocco di controllo e un blocco stack. Crea un clone della sprite nell'argomento. Può anche clonare la sprite in cui è in esecuzione, creando cloni di cloni, ricorsivamente.

.. image:: img/15_padd.png

* Quando **Paddle** è presentata come clone, la sua posizione è 220 (massima a destra) per la coordinata x e la sua coordinata y è casuale tra (-125 e 125) (altezza casuale).

.. image:: img/15_padd1.png

* Usa il blocco [ripeti] per far sì che il valore della sua coordinata x diminuisca lentamente, così potrai vedere il clone della sprite **Paddle** muoversi lentamente da destra a sinistra fino a scomparire.

.. image:: img/15_padd2.png

* Clona nuovamente una nuova sprite **Paddle** ed elimina il clone precedente.

.. image:: img/15_padd3.png
