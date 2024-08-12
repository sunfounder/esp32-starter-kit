.. note::

    Ciao, benvenuto nella community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto da esperti**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

Commenti
=============

I commenti nel codice ci aiutano a comprendere meglio il codice, rendono l'intero codice più leggibile e permettono di commentare parti del codice durante i test, in modo che quella parte non venga eseguita.

Commento su una singola riga
---------------------------------

I commenti su una singola riga in MicroPython iniziano con #, e tutto il testo che segue viene considerato un commento fino alla fine della riga. I commenti possono essere posizionati prima o dopo il codice.

.. code-block:: python

    print("hello world") #Questo è un commentohello world

>>> %Run -c $EDITOR_CONTENT
hello world

I commenti non devono necessariamente essere testo utilizzato per spiegare il codice. Puoi anche commentare parte del codice per impedire a MicroPython di eseguirlo.

.. code-block:: python

    #print("Can't run it！")
    print("hello world") #Questo è un commentohello world

>>> %Run -c $EDITOR_CONTENT
hello world

Commento su più righe
------------------------------

Se vuoi commentare più righe, puoi usare più segni #.

.. code-block:: python

    #Questo è un commento
    #scritto in
    #più di una riga
    print("Hello, World!")

>>> %Run -c $EDITOR_CONTENT
Hello, World!

In alternativa, puoi usare stringhe multilinea.

Poiché MicroPython ignora i letterali stringa che non sono assegnati a variabili, puoi aggiungere più righe di stringhe (tripli apici) al codice e inserire i commenti in esse:

.. code-block:: python

    """
    This is a comment
    written in
    more than just one line
    """
    print("Hello, World!")

>>> %Run -c $EDITOR_CONTENT
Hello, World!

Finché la stringa non viene assegnata a una variabile, MicroPython la ignorerà dopo aver letto il codice e la tratterà come se fosse un commento su più righe.

