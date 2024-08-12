.. note::

    Ciao, benvenuto nella community di appassionati di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_receiver:

Ricevitore IR
===========================

**Ricevitore IR**

.. image:: img/ir_receiver_sl838.png
    :width: 400
    :align: center

* **OUT**: Uscita segnale
* **GND**: Massa
* **VCC**: Alimentazione, 3.3v~5V

Il ricevitore a infrarossi SL838 è un componente che riceve segnali a infrarossi e può ricevere raggi infrarossi in modo indipendente e output compatibili con il livello TTL. È simile a un normale transistor confezionato in plastica per dimensioni ed è adatto per tutti i tipi di telecomandi a infrarossi e trasmissioni a infrarossi.

L'infrarosso, o IR, è una tecnologia di comunicazione wireless popolare, a basso costo e facile da usare. La luce a infrarossi ha una lunghezza d'onda leggermente più lunga rispetto alla luce visibile, quindi è impercettibile all'occhio umano, rendendola ideale per la comunicazione wireless. Uno schema di modulazione comune per la comunicazione a infrarossi è la modulazione a 38KHz.

* Può essere utilizzato per il telecomando
* Ampia tensione operativa: 2.7~5V
* Filtro interno per frequenza PCM
* Compatibilità TTL e CMOS
* Forte capacità anti-interferenza
* Conforme alla normativa RoHS

**Telecomando**

.. image:: img/image186.jpeg
    :width: 400

Questo è un mini telecomando wireless a infrarossi sottile con 21 pulsanti di funzione e una distanza di trasmissione fino a 8 metri, adatto per il controllo di una vasta gamma di dispositivi nella stanza dei bambini.

* Dimensioni: 85x39x6mm
* Portata del telecomando: 8-10m
* Batteria: batteria al litio manganese tipo bottone 3V
* Frequenza portante a infrarossi: 38KHz
* Materiale della superficie: PET da 0,125 mm
* Durata effettiva: oltre 20.000 utilizzi

**Esempio**

* :ref:`ar_receiver` (Progetto Arduino)
* :ref:`ar_guess_number` (Progetto Arduino)
* :ref:`py_receiver` (Progetto MicroPython)
* :ref:`py_guess_number` (Progetto MicroPython)

