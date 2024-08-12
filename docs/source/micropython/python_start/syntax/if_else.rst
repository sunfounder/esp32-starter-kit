.. note::

    Ciao, benvenuto nella Community di appassionati di SunFounder Raspberry Pi, Arduino e ESP32 su Facebook! Approfondisci il mondo di Raspberry Pi, Arduino e ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto Esperto**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e Condividi**: Scambia suggerimenti e tutorial per migliorare le tue competenze.
    - **Anteprime Esclusive**: Ottieni accesso anticipato agli annunci di nuovi prodotti e anteprime.
    - **Sconti Speciali**: Goditi sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni Festive e Giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca [|link_sf_facebook|] e unisciti oggi stesso!

If Else
=============

È necessario prendere decisioni quando vogliamo eseguire un codice solo se una certa condizione è soddisfatta.

if
--------------------
.. code-block:: python

    if test espressione:
        istruzione(i)

Qui, il programma valuta la `test expression` ed esegue l'`statement` solo quando la `test expression` è Vera.

Se la `test expression` è Falsa, allora l'`statement(s)` non verrà eseguita.

In MicroPython, l'indentazione indica il corpo dell'istruzione `if`. Il corpo inizia con un'indentazione e termina con la prima linea non indentata.

Python interpreta i valori diversi da zero come "True". None e 0 sono interpretati come "False".

**Diagramma di flusso dell'istruzione if**

.. image:: img/if_statement.png

**Esempio**

.. code-block:: python

    num = 8
    if num > 0:
        print(num, "is a positive number.")
    print("End with this line")

>>> %Run -c $EDITOR_CONTENT
8 is a positive number.
End with this line



if...else
-----------------------

.. code-block:: python

    if test expression:
        Body of if
    else:
        Body of else

L'istruzione `if..else` valuta la `test expression` ed eseguirà il corpo di `if` solo quando la condizione del test è `True`.

Se la condizione è `False`, viene eseguito il corpo di `else`. L'indentazione viene utilizzata per separare i blocchi.

**Diagramma di flusso dell'istruzione if...else**

.. image:: img/if_else.png

**Esempio**

.. code-block:: python

    num = -8
    if num > 0:
        print(num, "is a positive number.")
    else:
        print(num, "is a negative number.")

>>> %Run -c $EDITOR_CONTENT
-8 is a negative number.



if...elif...else
--------------------

.. code-block:: python

    if test expression:
        Body of if
    elif test expression:
        Body of elif
    else: 
        Body of else

`Elif` è l'abbreviazione di `else if`. Ci permette di controllare più espressioni.

Se la condizione dell'`if` è Falsa, viene controllata la condizione del blocco elif successivo, e così via.

Se tutte le condizioni sono `False`, viene eseguito il corpo di `else`.

Viene eseguito solo uno dei diversi blocchi `if...elif...else` a seconda delle condizioni.

Il blocco `if` può avere un solo blocco `else`. Ma può avere più blocchi `elif`.

**Diagramma di flusso dell'istruzione if...elif...else**

.. image:: img/if_elif_else.png

**Esempio**

.. code-block:: python

    x = 10
    y = 9

    if x > y:
        print("x is greater than y")
    elif x == y:
        print("x and y are equal")
    else:
        print("x is greater than y")

>>> %Run -c $EDITOR_CONTENT
x is greater than y


if Annidato
---------------------

Possiamo incorporare un'istruzione if in un'altra if, e poi chiamarla if annidato.

**Esempio**

.. code-block:: python

    x = 67

    if x > 10:
        print("Above ten,")
        if x > 20:
            print("and also above 20!")
        else:
            print("but not above 20.")

>>> %Run -c $EDITOR_CONTENT
Above ten,
and also above 20!