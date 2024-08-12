.. note::

    Ciao, benvenuto nella Community di Appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirsi a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni l'accesso anticipato a nuovi annunci di prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

.. _add_libraries_ar:

1.4 Installare le librerie (Importante)
==========================================

Una libreria è una raccolta di codice pre-scritto o funzioni che estendono le capacità dell'IDE di Arduino. Le librerie forniscono codice pronto all'uso per varie funzionalità, permettendoti di risparmiare tempo e fatica nella programmazione di funzionalità complesse.

Ci sono due modi principali per installare le librerie:

Installazione dal Library Manager
--------------------------------------

Molte librerie sono disponibili direttamente tramite l'Arduino Library Manager. Puoi accedere al Library Manager seguendo questi passaggi:

#. Nel **Library Manager**, puoi cercare la libreria desiderata per nome o navigare tra le diverse categorie.

   .. note::

      Nei progetti in cui è necessaria l'installazione di librerie, ci saranno prompt che indicano quali librerie installare. Segui le istruzioni fornite, come "La libreria del sensore DHT viene utilizzata qui, puoi installarla dal Library Manager". Installa semplicemente le librerie raccomandate come suggerito.

   .. image:: img/install_lib3.png

#. Una volta trovata la libreria che desideri installare, clicca su di essa e poi clicca sul pulsante **Installa**.

   .. image:: img/install_lib2.png

#. L'IDE di Arduino scaricherà e installerà automaticamente la libreria per te.

.. _install_lib_man:

Installazione Manuale
--------------------------

Alcune librerie non sono disponibili tramite il **Library Manager** e devono essere installate manualmente. Per installare queste librerie, segui questi passaggi:


#. Apri l'IDE di Arduino e vai su **Sketch** -> **Include Library** -> **Add .ZIP Library**.

   .. image:: img/a2dp_add_zip.png

#. Naviga nella directory in cui si trovano i file della libreria, come la cartella ``esp32-starter-kit\c\libraries``, e seleziona il file della libreria desiderata, ad esempio ``ESP32-A2DP.zip``. Poi, clicca su **Open**.

    * :download:`SunFounder ESP32 Starter Kit <https://github.com/sunfounder/esp32-starter-kit/archive/refs/heads/main.zip>`

   .. image:: img/a2dp_choose.png

#. Dopo un breve periodo, riceverai una notifica che indica l'installazione avvenuta con successo.

   .. image:: img/a2dp_success.png

#. Ripeti lo stesso processo per aggiungere la libreria ``ESP8266Audio.zip``.

.. note::

   Le librerie installate utilizzando uno dei metodi sopra descritti si trovano nella directory di librerie predefinita dell'IDE di Arduino, che solitamente è situata in ``C:\Users\xxx\Documents\Arduino\libraries``.

   Se la tua directory delle librerie è diversa, puoi verificarlo andando su **File** -> **Preferences**.

      .. image:: img/install_lib1.png
