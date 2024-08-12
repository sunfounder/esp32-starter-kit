.. note::

    Ciao, benvenuto nella Community di Appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirsi a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni l'accesso anticipato a nuovi annunci di prodotti e anteprime.
    - **Sconti speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi!

1.3 Installare la Scheda ESP32 (Importante)
===============================================

Per programmare il microcontrollore ESP32, è necessario installare il pacchetto di schede ESP32 nell'Arduino IDE. Segui la guida passo-passo qui sotto:

**Installa la Scheda ESP32**

.. #. Open the Arduino IDE. Go to **File** and select **Preferences** from the drop-down menu.

..     .. image:: img/install_esp321.png

.. #. In the Preferences window, locate the **Additional Board Manager URLs** field. Click on it to activate the text box.

..     .. image:: img/install_esp322.png

.. #. Add the following URL to the **Additional Board Manager URLs** field: https://espressif.github.io/arduino-esp32/package_esp32_index.json. This URL points to the package index file for the ESP32 boards. Click the **OK** button to save the changes.

..     .. image:: img/install_esp323.png

#. Nella finestra **Gestore Schede**, digita **ESP32** nella barra di ricerca. Clicca sul pulsante **Installa** per avviare il processo di installazione. Questo scaricherà e installerà il pacchetto di schede ESP32.

    .. image:: img/install_esp324.png

#. Congratulazioni! Hai installato con successo il pacchetto di schede ESP32 nell'Arduino IDE.

**Carica il Codice**

#. Ora, collega l'ESP32 WROOM 32E al tuo computer utilizzando un cavo Micro USB.

    .. image:: ../../img/plugin_esp32.png
        :width: 600
        :align: center

#. Poi seleziona la scheda corretta, **ESP32 Dev Module**, cliccando su **Strumenti** -> **Scheda** -> **esp32**.

    .. image:: img/install_esp325.png

#. Se il tuo ESP32 è collegato al computer, puoi scegliere la porta corretta cliccando su **Strumenti** -> **Porta**.

    .. image:: img/install_esp326.png

#. Inoltre, Arduino 2.0 ha introdotto un nuovo modo per selezionare rapidamente la scheda e la porta. Per ESP32, di solito non viene riconosciuto automaticamente, quindi è necessario cliccare su **Seleziona altra scheda e porta**.

    .. image:: img/install_esp327.png

#. Nella casella di ricerca, digita **ESP32 Dev Module** e selezionalo quando appare. Poi, scegli la porta corretta e clicca su **OK**.

    .. image:: img/install_esp328.png

#. Successivamente, potrai selezionarla tramite questa finestra di accesso rapido. Nota che durante l'uso successivo, potrebbe capitare che ESP32 non sia disponibile nella finestra di accesso rapido, e dovrai ripetere i due passaggi precedenti.

    .. image:: img/install_esp329.png

#. Entrambi i metodi ti consentono di selezionare la scheda e la porta corretta, quindi scegli quello che ti è più comodo. Ora è tutto pronto per caricare il codice sull'ESP32.
