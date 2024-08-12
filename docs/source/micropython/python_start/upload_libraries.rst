.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a omaggi e promozioni durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _add_libraries_py:

1.4 Carica le Librerie (Importante)
========================================

In alcuni progetti, avrai bisogno di librerie aggiuntive. Quindi, per prima cosa, carichiamo queste librerie su ESP32 e successivamente potremo eseguire il codice direttamente.

#. Scarica il codice rilevante dal link qui sotto.


   * :download:`SunFounder ESP32 Starter Kit <https://github.com/sunfounder/esp32-starter-kit/archive/refs/heads/main.zip>`

#. Collega l'ESP32 WROOM 32E al computer utilizzando un cavo Micro USB. 

    .. image:: ../../img/plugin_esp32.png
        :width: 600
        :align: center

#. Apri Thonny IDE e fai clic sull'interprete "MicroPython (ESP32).COMXX" nell'angolo in basso a destra.

    .. image:: img/sec_inter.png

#. Nella barra di navigazione in alto, fai clic su **Visualizza** -> **File**.

    .. image:: img/th_files.png

#. Cambia il percorso nella cartella in cui hai scaricato in precedenza il `code package <https://github.com/sunfounder/esp32-starter-kit/archive/refs/heads/main.zip>`_, quindi vai alla cartella ``esp32-starter-kit-main\micropython\libs``.

    .. image:: img/th_path.png

#. Seleziona tutti i file o cartelle nella cartella ``libs/``, fai clic destro e seleziona **Carica su**, ci vorrà un po' di tempo per caricarli.

    .. image:: img/th_upload.png

#. Ora vedrai i file che hai appena caricato all'interno della tua unità ``MicroPython device``.

    .. image:: img/th_done.png
