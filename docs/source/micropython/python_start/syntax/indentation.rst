.. note::

    Ciao, benvenuto nella Community di appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci il mondo di Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

Indentazione
================

L'indentazione si riferisce agli spazi all'inizio di una riga di codice.
Come nei programmi Python standard, i programmi MicroPython di solito vengono eseguiti dall'alto verso il basso:
Scorrono ogni riga a turno, la eseguono nell'interprete e poi passano alla riga successiva,
Proprio come se le digitassi riga per riga nella Shell.
Un programma che si limita a scorrere l'elenco delle istruzioni riga per riga non è molto intelligente, però: quindi MicroPython, come Python, ha il suo metodo per controllare la sequenza di esecuzione del programma: l'indentazione.

È necessario inserire almeno uno spazio prima di print(), altrimenti apparirà il messaggio di errore "Invalid syntax". Solitamente si consiglia di standardizzare gli spazi premendo uniformemente il tasto Tab.



.. code-block:: python

    if 8 > 5:
    print("Eight is greater than Five!")

>>> %Run -c $EDITOR_CONTENT
Traceback (most recent call last):
  File "<stdin>", line 2
SyntaxError: invalid syntax

È necessario utilizzare lo stesso numero di spazi nello stesso blocco di codice, altrimenti Python restituirà un errore.


.. code-block:: python

    if 8 > 5:
    print("Eight is greater than Five!")
            print("Eight is greater than Five")
            
>>> %Run -c $EDITOR_CONTENT
Traceback (most recent call last):
  File "<stdin>", line 2
SyntaxError: invalid syntax
