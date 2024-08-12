.. note::

    Ciao, benvenuto nella community di appassionati di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_joystick:

Modulo Joystick
=========================

.. image:: img/joystick_pic.png
    :align: center
    :width: 600

* **GND**: Massa.
* **+5V**: Alimentazione, accetta da 3.3V a 5V.
* **VRX**: Uscita analogica corrispondente alla posizione orizzontale del joystick (asse X).
* **VRY**: Uscita analogica corrispondente alla posizione verticale del joystick (asse Y).
* **SW**: Uscita del pulsante, attivata quando il joystick viene premuto. Per un funzionamento corretto è necessaria una resistenza di pull-up esterna. Con la resistenza in posizione, il pin SW emette un segnale alto quando è inattivo e va basso quando il joystick viene premuto.

L'idea di base di un joystick è quella di tradurre il movimento di un'asta in informazioni elettroniche che un computer può elaborare.

Per comunicare un'intera gamma di movimenti al computer, un joystick deve misurare la posizione dell'asta su due assi: l'asse X (da sinistra a destra) e l'asse Y (su e giù). Proprio come nella geometria di base, le coordinate X-Y individuano esattamente la posizione dell'asta.

Per determinare la posizione dell'asta, il sistema di controllo del joystick monitora semplicemente la posizione di ciascun asse. Il design convenzionale del joystick analogico lo fa con due potenziometri, o resistori variabili.

Il joystick ha anche un ingresso digitale che si attiva quando il joystick viene premuto.

.. image:: img/joystick318.png
    :align: center
    :width: 600
	
**Esempio**

* :ref:`ar_joystick` (Progetto Arduino)
* :ref:`py_joystick` (Progetto MicroPython)
* :ref:`sh_star_crossed` (Progetto Scratch)
* :ref:`sh_dragon` (Progetto Scratch)
