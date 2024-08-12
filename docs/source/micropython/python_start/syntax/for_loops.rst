.. note::

    Ciao, benvenuto nella community di SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasts su Facebook! Approfondisci le tue conoscenze su Raspberry Pi, Arduino ed ESP32 insieme ad altri appassionati.

    **Perché unirsi?**

    - **Supporto da esperti**: Risolvi i problemi post-vendita e le sfide tecniche con l'aiuto della nostra community e del nostro team.
    - **Impara e condividi**: Scambia consigli e tutorial per migliorare le tue competenze.
    - **Anteprime esclusive**: Accedi in anteprima agli annunci di nuovi prodotti e alle anticipazioni.
    - **Sconti speciali**: Approfitta di sconti esclusivi sui nostri prodotti più recenti.
    - **Promozioni festive e giveaway**: Partecipa a giveaway e promozioni festive.

    👉 Pronto a esplorare e creare con noi? Clicca su [|link_sf_facebook|] e unisciti oggi stesso!

Cicli For
==============

Il ciclo `for` può attraversare qualsiasi sequenza di elementi, come una lista o una stringa.

Il formato sintattico del ciclo for è il seguente:

.. code-block:: python

    for val in sequence:
        Corpo del ciclo for

Qui, `val` è una variabile che assume il valore dell'elemento nella sequenza a ogni iterazione.

Il ciclo continua fino a raggiungere l'ultimo elemento della sequenza. Utilizza l'indentazione per separare il corpo del ciclo `for` dal resto del codice.

**Diagramma di flusso del ciclo for**

.. image:: img/for_loop.png

.. code-block:: python

    numbers = [1, 2, 3, 4]
    sum = 0

    for val in numbers:
        sum = sum+val
        
    print("The sum is", sum)

>>> %Run -c $EDITOR_CONTENT
La somma è 10

L'istruzione break
-------------------------

Con l'istruzione break possiamo interrompere il ciclo prima che abbia attraversato tutti gli elementi:

.. code-block:: python

    numbers = [1, 2, 3, 4]
    sum = 0

    for val in numbers:
        sum = sum+val
        if sum == 6:
            break
    print("The sum is", sum)

>>> %Run -c $EDITOR_CONTENT
La somma è 6

L'istruzione continue
--------------------------------------------

Con l'istruzione `continue` possiamo interrompere l'iterazione corrente del ciclo e continuare con la successiva:

.. code-block:: python

    numbers = [1, 2, 3, 4]

    for val in numbers:
        if val == 3:
            continue
        print(val)

>>> %Run -c $EDITOR_CONTENT
1
2
4

La funzione range()
--------------------------------------------

Possiamo utilizzare la funzione range() per generare una sequenza di numeri. range(6) produrrà numeri tra 0 e 5 (6 numeri).

Possiamo anche definire inizio, fine e passo come range(start, stop, step_size). Se non specificato, step_size predefinito è 1.

Nel contesto di range, l'oggetto è "pigro" perché quando creiamo l'oggetto, non genera ogni numero che "contiene". Tuttavia, questo non è un iteratore poiché supporta le operazioni in, len e __getitem__.

Questa funzione non memorizza tutti i valori in memoria; sarebbe inefficiente. Quindi ricorda l'inizio, la fine, il passo e genera il numero successivo durante l'esecuzione.

Per forzare questa funzione a stampare tutti gli elementi, possiamo usare la funzione list().

.. code-block:: python

    print(range(6))

    print(list(range(6)))

    print(list(range(2, 6)))

    print(list(range(2, 10, 2)))

>>> %Run -c $EDITOR_CONTENT
range(0, 6)
[0, 1, 2, 3, 4, 5]
[2, 3, 4, 5]
[2, 4, 6, 8]

Possiamo utilizzare `range()` in un ciclo `for` per iterare su una sequenza di numeri. Può essere combinato con la funzione len() per utilizzare l'indice per attraversare la sequenza.

.. code-block:: python

    fruits = ['pear', 'apple', 'grape']

    for i in range(len(fruits)):
        print("I like", fruits[i])
        
>>> %Run -c $EDITOR_CONTENT
Mi piace pera
Mi piace mela
Mi piace uva

Else nel ciclo For
--------------------------------

Il ciclo `for` può anche avere un blocco `else` opzionale. Se gli elementi nella sequenza utilizzata per il ciclo vengono esauriti, la parte `else` viene eseguita.

La parola chiave `break` può essere utilizzata per interrompere il ciclo `for`. In tal caso, la parte `else` verrà ignorata.

Quindi, se non si verifica alcuna interruzione, la parte `else` del ciclo `for` verrà eseguita.

.. code-block:: python

    for val in range(5):
        print(val)
    else:
        print("Finished")

>>> %Run -c $EDITOR_CONTENT
0
1
2
3
4
Finito

Il blocco else NON verrà eseguito se il ciclo viene interrotto da un'istruzione break.

.. code-block:: python

    for val in range(5):
        if val == 2: break
        print(val)
    else:
        print("Finished")

>>> %Run -c $EDITOR_CONTENT
0
1

