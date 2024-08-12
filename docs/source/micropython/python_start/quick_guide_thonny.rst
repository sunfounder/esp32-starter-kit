.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a omaggi e promozioni durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

1.5 Guida Rapida a Thonny
=============================

.. _open_run_code_py:

Apri ed Esegui Codice Direttamente
--------------------------------------

La sezione del progetto ti indica esattamente quale codice viene utilizzato, quindi fai doppio clic sul file ``.py`` con il numero di serie nel percorso ``esp32-starter-kit-main\micropython\codes\`` per aprirlo.

Tuttavia, devi prima scaricare il pacchetto e caricare le librerie, come descritto in :ref:`add_libraries_py`.

#. Apri il codice.

    Ad esempio, ``1.1_hello_led.py``.

    Se fai doppio clic su di esso, si aprirà una nuova finestra sulla destra. Puoi aprire più di un codice contemporaneamente.

    .. image:: img/quick_guide1.png

#. Collega l'esp32 al computer con un cavo micro USB.

    .. image:: ../../img/plugin_esp32.png

#. Seleziona l'interprete corretto

    Seleziona l'interprete "MicroPython (ESP32).COMxx".

    .. image:: img/sec_inter.png

#. Esegui il codice

    Per eseguire lo script, fai clic sul pulsante **Esegui script corrente** o premi F5.

    .. image:: img/quick_guide2.png

    Se il codice contiene informazioni da stampare, appariranno nella Shell; altrimenti, verranno visualizzate solo le seguenti informazioni.

    Fai clic su **Visualizza** -> **Modifica** per aprire la finestra Shell se non appare in Thonny.

        .. code-block::

            MicroPython v1.19.1 on 2022-06-18; modulo ESP32 con ESP32

            Digita "help()" per maggiori informazioni.

            >>> %Run -c $EDITOR_CONTENT

    * La prima riga mostra la versione di MicroPython, la data e le informazioni sul tuo dispositivo.
    * La seconda riga ti invita a digitare "help()" per ottenere assistenza.
    * La terza riga è un comando di Thonny che dice all'interprete MicroPython sul tuo Pico W di eseguire il contenuto dell'area script - "EDITOR_CONTENT".
    * Se c'è un messaggio dopo la terza riga, è solitamente un messaggio che hai detto a MicroPython di stampare o un messaggio di errore per il codice.


#. Interrompi l'esecuzione

    .. image:: img/quick_guide3.png

    Per interrompere l'esecuzione del codice, fai clic sul pulsante **Interrompi/Riavvia backend**. Il comando **%RUN -c $EDITOR_CONTENT** scomparirà dopo l'interruzione.

#. Salva o salva come

    Puoi salvare le modifiche apportate all'esempio aperto premendo **Ctrl+S** o facendo clic sul pulsante **Salva** in Thonny.

    Il codice può essere salvato come file separato all'interno dell'**unità MicroPython (ESP32)** facendo clic su **File** -> **Salva come**.

    .. image:: img/quick_guide4.png

    Seleziona **unità MicroPython**.

    .. image:: img/quick_guide5.png
        
    Quindi fai clic su **OK** dopo aver inserito il nome del file e l'estensione **.py**. Nell'unità MicroPython, vedrai il tuo file salvato.

    .. image:: img/quick_guide6.png

    .. note::
        Indipendentemente dal nome che dai al tuo codice, è meglio descrivere il tipo di codice e non dare un nome senza senso come ``abc.py``.
        Quando salvi il codice come ``main.py``, verrà eseguito automaticamente all'accensione.


Crea un File ed Eseguilo
------------------------------


Il codice viene mostrato direttamente nella sezione del codice. Puoi copiarlo in Thonny ed eseguirlo come segue.

#. Crea un nuovo file

    Apri Thonny IDE, fai clic sul pulsante **Nuovo** per creare un nuovo file vuoto.

    .. image:: img/quick_guide7.png

#. Copia il codice

    Copia il codice dal progetto in Thonny IDE.

    .. image:: img/quick_guide8.png

#. Collega l'esp32 al computer con un cavo micro USB.

    .. image:: ../../img/plugin_esp32.png

#. Seleziona l'interprete corretto

    Seleziona l'interprete "MicroPython (ESP32).COMxx" nell'angolo in basso a destra.

    .. image:: img/sec_inter.png

#. Esegui il codice

    Devi fare clic su **Esegui script corrente** o semplicemente premere ``F5`` per eseguirlo.

    .. image:: img/quick_guide9.png

    Se il codice contiene informazioni da stampare, appariranno nella Shell; altrimenti, verranno visualizzate solo le seguenti informazioni.

    Fai clic su **Visualizza** -> **Modifica** per aprire la finestra Shell se non appare in Thonny.

        .. code-block::

            MicroPython v1.19.1 on 2022-06-18; modulo ESP32 con ESP32

            Digita "help()" per maggiori informazioni.

            >>> %Run -c $EDITOR_CONTENT

    * La prima riga mostra la versione di MicroPython, la data e le informazioni sul tuo dispositivo.
    * La seconda riga ti invita a digitare "help()" per ottenere assistenza.
    * La terza riga è un comando di Thonny che dice all'interprete MicroPython sul tuo Pico W di eseguire il contenuto dell'area script - "EDITOR_CONTENT".
    * Se c'è un messaggio dopo la terza riga, è solitamente un messaggio che hai detto a MicroPython di stampare o un messaggio di errore per il codice.


#. Interrompi l'esecuzione

    .. image:: img/quick_guide3.png

    Per interrompere l'esecuzione del codice, fai clic sul pulsante **Interrompi/Riavvia backend**. Il comando **%RUN -c $EDITOR_CONTENT** scomparirà dopo l'interruzione.

#. Salva o salva come

    Puoi salvare il codice premendo **Ctrl+S** o facendo clic sul pulsante **Salva** in Thonny. Nella finestra pop-up, seleziona la posizione in cui desideri salvare il file.

    .. image:: img/quick_guide5.png
        
    Quindi fai clic su **OK** o **Salva** dopo aver inserito il nome del file e l'estensione **.py**.

    .. image:: img/quick_guide6.png

    .. note::
        Indipendentemente dal nome che dai al tuo codice, è meglio descrivere il tipo di codice e non dare un nome senza senso come ``abc.py``.
        Quando salvi il codice come ``main.py``, verrà eseguito automaticamente all'accensione.

#. Apri il file

    Ecco due modi per aprire un file di codice salvato.

    * Il primo metodo è fare clic sull'icona di apertura sulla barra degli strumenti di Thonny, proprio come quando salvi un programma, ti verrà chiesto se desideri aprirlo da **questo computer** o **dispositivo MicroPython**, ad esempio, fai clic su **dispositivo MicroPython** e vedrai un elenco di tutti i programmi che hai salvato sull'ESP32.
    * Il secondo è aprire direttamente l'anteprima del file facendo clic su **Visualizza** -> **File** -> e poi facendo doppio clic sul file ``.py`` corrispondente per aprirlo.
