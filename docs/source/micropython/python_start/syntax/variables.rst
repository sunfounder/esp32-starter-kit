.. note::

    Ciao, benvenuto nella SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts Community su Facebook! Approfondisci Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirti a noi?**

    - **Supporto esperto**: Risolvi problemi post-vendita e sfide tecniche con l'aiuto della nostra comunità e del nostro team.
    - **Impara e condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni e omaggi festivi**: Partecipa a omaggi e promozioni durante le festività.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

Variabili
============

Le variabili sono contenitori utilizzati per memorizzare valori di dati.

Creare una variabile è molto semplice. Basta darle un nome e assegnarle un valore. Non è necessario specificare il tipo di dato della variabile al momento dell'assegnazione, poiché la variabile è un riferimento che accede a oggetti di diversi tipi di dato tramite l'assegnazione.

I nomi delle variabili devono seguire le seguenti regole:

* I nomi delle variabili possono contenere solo numeri, lettere e underscore.
* Il primo carattere del nome della variabile deve essere una lettera o un underscore.
* I nomi delle variabili sono case sensitive.

Creare una Variabile
------------------------

In MicroPython non esiste un comando per dichiarare variabili. Le variabili vengono create quando le si assegna un valore per la prima volta. Non è necessario usare alcuna dichiarazione di tipo specifico e si può persino cambiare il tipo dopo aver impostato la variabile.



.. code-block:: python

    x = 8       # x is of type int
    x = "lily" # x is now of type str
    print(x)

>>> %Run -c $EDITOR_CONTENT
lily


Casting
----------

Se vuoi specificare il tipo di dato per la variabile, puoi farlo tramite il casting.



.. code-block:: python

    x = int(5)    # y will be 5
    y = str(5)    # x will be '5'
    z = float(5)  # z will be 5.0
    print(x,y,z)

>>> %Run -c $EDITOR_CONTENT
5 5 5.0

Ottenere il Tipo
-------------------------

Puoi ottenere il tipo di dato di una variabile con la funzione `type()`.



.. code-block:: python

    x = 5
    y = "hello"
    z = 5.0
    print(type(x),type(y),type(z))

>>> %Run -c $EDITOR_CONTENT
<class 'int'> <class 'str'> <class 'float'>

Apici Singoli o Doppi?
--------------------------

In MicroPython, si possono usare sia gli apici singoli che doppi per definire variabili stringa.



.. code-block:: python

    x = "hello"
    # is the same as
    x = 'hello'

Case-Sensitive
----------------------

I nomi delle variabili sono case-sensitive.



.. code-block:: python

    a = 5
    A = "lily"
    #A non sovrascriverà a
    print(a, A)

>>> %Run -c $EDITOR_CONTENT
5 lily


