.. note::

    Ciao, benvenuto nella Community di appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

Print()
=====================

La funzione ``print()`` stampa il messaggio specificato sullo schermo o su un altro dispositivo di output standard.
Il messaggio può essere una stringa o qualsiasi altro oggetto, che verrà convertito in una stringa prima di essere scritto sullo schermo.

Stampa più oggetti:



.. code-block:: python

    print("Welcome!", "Enjoy yourself!")

>>> %Run -c $EDITOR_CONTENT
Welcome! Enjoy yourself!

Print tuples:



.. code-block:: python

    x = ("pear", "apple", "grape")
    print(x)

>>> %Run -c $EDITOR_CONTENT
('pear', 'apple', 'grape')

Stampa due messaggi e specifica il separatore:



.. code-block:: python

    print("Hello", "how are you?", sep="---")

>>> %Run -c $EDITOR_CONTENT
Hello---how are you?