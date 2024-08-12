.. note::

    Ciao, benvenuto nella community di appassionati di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_transistor:

Transistor
============

.. image:: img/npn_pnp.png

Il transistor è un dispositivo semiconduttore che controlla la corrente tramite corrente. Funziona amplificando segnali deboli in segnali di maggiore ampiezza ed è utilizzato anche come interruttore senza contatto.

Un transistor è una struttura a tre strati composta da semiconduttori di tipo P e N. Essi formano tre regioni interne. La più sottile al centro è la regione della base; le altre due sono entrambe di tipo N o P: la regione più piccola con portatori di carica maggioritari è la regione dell'emettitore, mentre l'altra è la regione del collettore. Questa composizione permette al transistor di funzionare come amplificatore.
Da queste tre regioni si generano rispettivamente tre terminali, che sono base (b), emettitore (e) e collettore (c). Essi formano due giunzioni P-N, ovvero la giunzione dell'emettitore e la giunzione del collettore. La direzione della freccia nel simbolo del circuito del transistor indica quella della giunzione dell'emettitore.

* `P-N junction - Wikipedia <https://en.wikipedia.org/wiki/P-n_junction>`_

In base al tipo di semiconduttore, i transistor possono essere suddivisi in due gruppi, NPN e PNP. Dall'abbreviazione possiamo dedurre che il primo è composto da due semiconduttori di tipo N e uno di tipo P, mentre il secondo è l'opposto. Vedi la figura sottostante.

.. note::
    L'S8550 è un transistor PNP e l'S8050 è uno NPN. Sembrano molto simili, quindi è necessario controllare attentamente le etichette.

.. image:: img/transistor_symbol.png

Quando un segnale di livello alto passa attraverso un transistor NPN, esso si attiva. Tuttavia, un transistor PNP necessita di un segnale di livello basso per funzionare. Entrambi i tipi di transistor sono comunemente utilizzati come interruttori senza contatto, proprio come in questo esperimento.


* `S8050 Transistor Datasheet <https://components101.com/asset/sites/default/files/component_datasheet/S8050%20Transistor%20Datasheet.pdf>`_
* `S8550 Transistor Datasheet <https://www.mouser.com/datasheet/2/149/SS8550-118608.pdf>`_

Posizionare il lato con l'etichetta rivolto verso di noi e i pin rivolti verso il basso. I pin da sinistra a destra sono emettitore(e), base(b) e collettore(c).

.. image:: img/ebc.png

.. note::
    * La base è il dispositivo di controllo della porta per l'alimentazione elettrica maggiore.
    * Nel transistor NPN, il collettore è l'alimentazione elettrica maggiore e l'emettitore è l'uscita di tale alimentazione; nel transistor PNP è esattamente l'opposto.

.. Example
.. -------------------

.. :ref:`Two Kinds of Transistors`

**Esempio**

* :ref:`ar_transistor` (Progetto Arduino)
* :ref:`ar_ac_buz` (Progetto Arduino)
* :ref:`ar_fruit_piano` (Progetto Arduino)
* :ref:`py_transistor` (Progetto MicroPython)
* :ref:`py_pa_buz` (Progetto MicroPython)
* :ref:`py_light_theremin` (Progetto MicroPython)

