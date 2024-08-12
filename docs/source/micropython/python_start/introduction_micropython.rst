.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a omaggi e promozioni durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

1.1 Introduzione a MicroPython
==============================

MicroPython è un'implementazione software di un linguaggio di programmazione ampiamente compatibile con Python 3, scritto in C e ottimizzato per essere eseguito su un microcontrollore.

MicroPython è composto da un compilatore Python che genera bytecode e da un interprete di runtime che esegue tale bytecode. L'utente ha a disposizione un prompt interattivo (il REPL) per eseguire immediatamente i comandi supportati. Include una selezione di librerie core di Python; MicroPython comprende moduli che offrono al programmatore l'accesso all'hardware a basso livello.

* Riferimento: `MicroPython - Wikipedia <https://en.wikipedia.org/wiki/MicroPython>`_

La storia inizia qui
-------------------------

Le cose cambiarono nel 2013, quando Damien George lanciò una campagna di crowdfunding (Kickstarter).

Damien era uno studente universitario a Cambridge e un appassionato programmatore di robotica. Voleva ridurre il mondo di Python da una macchina da gigabyte a una da kilobyte. La sua campagna Kickstarter serviva a sostenere il suo sviluppo mentre trasformava la sua prova di concetto in un'implementazione completa.

MicroPython è sostenuto da una comunità Pythonista diversificata, che ha un forte interesse nel vedere il progetto avere successo.

Oltre a testare e supportare la base di codice, gli sviluppatori fornirono tutorial, librerie di codice e porting hardware, permettendo a Damien di concentrarsi su altri aspetti del progetto.

* Riferimento: `realpython <https://realpython.com/micropython/>`_

Perché MicroPython?
--------------------

Sebbene la campagna Kickstarter originale abbia rilasciato MicroPython come una scheda di sviluppo "pyboard" con STM32F4, MicroPython supporta molte architetture di prodotti basati su ARM. I port supportati ufficialmente includono ARM Cortex-M (molte schede STM32, TI CC3200/WiPy, schede Teensy, serie Nordic nRF, SAMD21 e SAMD51), ESP8266, ESP32, PIC a 16 bit, Unix, Windows, Zephyr e JavaScript.

In secondo luogo, MicroPython consente un feedback rapido. Questo perché puoi utilizzare REPL per inserire comandi in modo interattivo e ottenere risposte immediate. Puoi persino modificare il codice e eseguirlo immediatamente, senza dover attraversare il ciclo di codice-compilazione-caricamento-esecuzione.

Mentre Python offre gli stessi vantaggi, alcune schede Microcontroller come l'ESP32 sono piccole, semplici e hanno poca memoria per eseguire il linguaggio Python nella sua interezza. Ecco perché MicroPython si è evoluto, mantenendo le principali caratteristiche di Python e aggiungendone di nuove per funzionare con queste schede Microcontroller.

Prossimamente imparerai a installare MicroPython su ESP32.

* Riferimento: `MicroPython - Wikipedia <https://en.wikipedia.org/wiki/MicroPython>`_
* Riferimento: `realpython <https://realpython.com/micropython/>`_
