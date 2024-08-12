.. note::

    Ciao, benvenuto nella community di appassionati di SunFounder Raspberry Pi & Arduino & ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a promozioni e omaggi durante le festività.

    👉 Sei pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _cpn_74hc595:

74HC595
===========

.. image:: img/74HC595.png

Ti è mai capitato di voler controllare molteplici LED o di aver bisogno di più pin I/O per controllare pulsanti, sensori e servomotori contemporaneamente? Puoi collegare alcuni sensori ai pin dell'Arduino, ma presto finirai i pin disponibili.

La soluzione è utilizzare i "registri a scorrimento". I registri a scorrimento ti permettono di espandere il numero di pin I/O che puoi utilizzare dall'Arduino (o da qualsiasi altro microcontrollore). Il registro a scorrimento 74HC595 è uno dei più famosi.

Il 74HC595 controlla fondamentalmente otto pin di output indipendenti utilizzando solo tre pin di input. Se hai bisogno di più di otto linee I/O aggiuntive, puoi facilmente collegare in cascata un qualsiasi numero di registri a scorrimento e creare un gran numero di linee I/O. Tutto ciò è realizzato attraverso il cosiddetto "shifting".

**Caratteristiche**

* Registro a scorrimento seriale a 8 bit, uscita parallela
* Ampio range di tensione operativa da 2 V a 6 V
* Uscite a 3 stati ad alta corrente possono pilotare fino a 15 carichi LSTTL
* Basso consumo energetico, massimo ICC 80 µA
* tPD tipico = 14 ns
* Uscita ±6 mA a 5 V
* Bassa corrente di ingresso, massimo 1 µA
* Il registro a scorrimento ha una funzione di cancellazione diretta

**Pin del 74HC595 e loro funzioni:**

.. image:: img/74hc595_pin.png
    :width: 600

* **Q0-Q7**: Pin di uscita dati paralleli a 8 bit, in grado di controllare direttamente 8 LED o 8 pin di un display a 7 segmenti.
* **Q7'**: Pin di uscita in serie, collegato al pin DS di un altro 74HC595 per collegare più 74HC595 in serie.
* **MR**: Pin di reset, attivo a livello basso;
* **SHcp**: Ingresso della sequenza temporale del registro a scorrimento. Sul fronte di salita, i dati nel registro a scorrimento si spostano progressivamente di un bit, ad esempio, i dati in Q1 si spostano in Q2 e così via. Mentre sul fronte di discesa, i dati nel registro a scorrimento rimangono invariati.
* **STcp**: Ingresso della sequenza temporale del registro di memoria. Sul fronte di salita, i dati nel registro a scorrimento si spostano nel registro di memoria.
* **CE**: Pin di abilitazione dell'uscita, attivo a livello basso.
* **DS**: Pin di ingresso dati seriali.
* **VCC**: Tensione di alimentazione positiva.
* **GND**: Massa.

**Diagramma Funzionale**

.. image:: img/74hc595_functional_diagram.png

**Principio di Funzionamento**

Quando MR (pin10) è a livello alto e OE (pin13) è a livello basso, 
i dati vengono inseriti sul fronte di salita di SHcp e passano nel registro di memoria attraverso il fronte di salita di STcp.

* Registro a Scorrimento

    * Supponiamo di voler inserire i dati binari 1110 1110 nel registro a scorrimento del 74HC595.
    * I dati vengono inseriti dal bit 0 del registro a scorrimento.
    * Ogni volta che l'orologio del registro a scorrimento ha un fronte di salita, i bit nel registro a scorrimento vengono spostati di un passo. Ad esempio, il bit 7 accetta il valore precedente del bit 6, il bit 6 ottiene il valore del bit 5, e così via.

.. image:: img/74hc595_shift.png

* Registro di Memoria

    * Quando il registro di memoria è nello stato di fronte di salita, i dati del registro a scorrimento verranno trasferiti al registro di memoria.
    * Il registro di memoria è collegato direttamente agli 8 pin di uscita, Q0 ~ Q7 saranno in grado di ricevere un byte di dati.
    * Il cosiddetto registro di memoria significa che i dati possono esistere in questo registro e non scompariranno con un'uscita. 
    * I dati rimarranno validi e invariati fintanto che il 74HC595 rimane alimentato.
    * Quando arrivano nuovi dati, quelli nel registro di memoria verranno sovrascritti e aggiornati.

.. image:: img/74hc595_storage.png

**Esempio**

* :ref:`ar_74hc595` (Progetto Arduino)
* :ref:`ar_7_segment` (Progetto Arduino)
* :ref:`ar_dice` (Progetto Arduino)
* :ref:`py_74hc595` (Progetto MicroPython)
* :ref:`py_7_segment` (Progetto MicroPython)
* :ref:`py_dice` (Progetto MicroPython)

