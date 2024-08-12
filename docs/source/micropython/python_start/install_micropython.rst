.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a omaggi e promozioni durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

.. _install_micropython_on_esp32:

1.3 Installare MicroPython su ESP32 (Importante)
=====================================================

#. Scarica il |link_esp32_micropython_download| dal sito ufficiale di MicroPython e successivamente scarica l'ultima versione del firmware.

    .. image:: img/dowload_micropython_uf2.png

#. Collega l'ESP32 WROOM 32E al computer utilizzando un cavo Micro USB. 

    .. image:: ../../img/plugin_esp32.png
        :width: 600
        :align: center

#. Clicca nell'angolo in basso a destra di Thonny IDE, seleziona **"MicroPython(ESP32).COMXX"** dal menu a comparsa e poi seleziona **"Configura interprete"**.

    .. image:: img/install_micropython1.png

#. Nella nuova finestra pop-up, clicca su **"Installa o aggiorna MicroPython"**.

    .. image:: img/install_micropython2.png

#. Seleziona la porta corretta e il firmware che hai scaricato in precedenza, quindi clicca su **"Installa"**.

    .. image:: img/install_micropython3.png

#. Dopo un'installazione riuscita, puoi chiudere questa pagina.

    .. image:: img/install_micropython4.png

#. Quando torni alla homepage di Thonny, vedrai la versione di MicroPython e i prompt relativi all'ESP32, invece di messaggi di errore in rosso.

    .. image:: img/install_micropython5.png