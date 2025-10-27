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

#. Collega l'ESP32 WROOM 32E al tuo computer utilizzando un cavo USB.

   .. image:: ../../img/plugin_esp32.png
        :width: 600
        :align: center

#. Clicca nell'angolo in basso a destra dell'IDE Thonny, seleziona **"MicroPython(ESP32).xxxCOMXX"** dal menu a comparsa, quindi seleziona **"Configura interprete"**.

   .. note::

      Se non vedi alcuna opzione oltre a "Local Python 3", è possibile che la tua scheda ESP32 non sia stata riconosciuta dal computer.  
      In tal caso, potresti dover :ref:`install_driver`.

   .. image:: img/install_micropython1.png

#. Clicca su **"Install or Update MicroPython"** nella nuova finestra popup.

   .. image:: img/install_micropython2.png

#. Seleziona la porta corretta, la famiglia MicroPython, la variante e la scheda, quindi clicca su **"Install"**.

   * :ref:`download_mode`
   
   .. image:: img/install_micropython3.png

#. Dopo un'installazione riuscita, torna alla schermata principale di Thonny; vedrai la versione di MicroPython e messaggi relativi all'ESP32, invece di errori in rosso.

   .. image:: img/install_micropython5.png
