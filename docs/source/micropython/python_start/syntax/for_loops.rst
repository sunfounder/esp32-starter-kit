For-Schleifen
=================

Die `for`-Schleife kann jede Art von Elementsequenz durchlaufen, wie beispielsweise eine Liste oder einen String.

Die Syntax der For-Schleife ist wie folgt:

.. code-block:: python

    for val in sequence:
        Body of for


Hier ist `val` eine Variable, die in jeder Iteration den Wert des Elements in der Sequenz annimmt.

Die Schleife setzt sich fort, bis wir das letzte Element in der Sequenz erreicht haben. Um den Körper der `for`-Schleife vom restlichen Code abzugrenzen, verwenden wir Einrückungen.

**Flussdiagramm der for-Schleife**

.. image:: img/for_loop.png




.. code-block:: python

    numbers = [1, 2, 3, 4]
    sum = 0

    for val in numbers:
        sum = sum+val
        
    print("The sum is", sum)

>>> %Run -c $EDITOR_CONTENT
The sum is 10

Das break-Statement
-------------------------

Mit dem break-Statement können wir die Schleife stoppen, bevor sie alle Elemente durchlaufen hat:



.. code-block:: python

    numbers = [1, 2, 3, 4]
    sum = 0

    for val in numbers:
        sum = sum+val
        if sum == 6:
            break
    print("The sum is", sum)

>>> %Run -c $EDITOR_CONTENT
The sum is 6

Das continue-Statement
--------------------------------------------

Mit dem `continue`-Statement können wir die aktuelle Iteration der Schleife beenden und mit der nächsten fortfahren:



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

Die range()-Funktion
--------------------------------------------

Wir können die range()-Funktion verwenden, um eine Zahlenfolge zu generieren. range(6) erzeugt Zahlen zwischen 0 und 5 (6 Zahlen).

Wir können auch Start, Stopp und Schrittgröße als range(start, stop, step_size) definieren. Wird nichts angegeben, ist die Standard-Schrittgröße 1.

Im Sinne von range ist das Objekt „lazy“, da es bei der Erstellung nicht jede Zahl generiert, die es „enthält“. Es ist jedoch kein Iterator, da es Operationen wie in, len und __getitem__ unterstützt.

Diese Funktion speichert nicht alle Werte im Speicher; das wäre ineffizient. Sie merkt sich Start, Stopp und Schrittgröße und generiert während der Iteration die nächste Zahl.

Um diese Funktion zu zwingen, alle Elemente auszugeben, können wir die Funktion list() verwenden.



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


Wir können `range()` in einer `for`-Schleife verwenden, um über eine Zahlenfolge zu iterieren. Es kann mit der len()-Funktion kombiniert werden, um den Index zum Durchlaufen der Sequenz zu verwenden.



.. code-block:: python

    fruits = ['pear', 'apple', 'grape']

    for i in range(len(fruits)):
        print("I like", fruits[i])
        
>>> %Run -c $EDITOR_CONTENT
I like pear
I like apple
I like grape

Else in For-Schleife
--------------------------------

Die `for`-Schleife kann auch einen optionalen `else`-Block haben. Wenn die Elemente in der Sequenz, die für die Schleife verwendet werden, erschöpft sind, wird der `else`-Teil ausgeführt.

Das Schlüsselwort `break` kann verwendet werden, um die `for`-Schleife zu stoppen. In diesem Fall wird der `else`-Teil ignoriert.

Wenn also keine Unterbrechung auftritt, wird der `else`-Teil der `for`-Schleife ausgeführt.



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
Finished

Der else-Block wird NICHT ausgeführt, wenn die Schleife durch eine break-Anweisung gestoppt wird.



.. code-block:: python


    for val in range(5):
        if val == 2: break
        print(val)
    else:
        print("Finished")

>>> %Run -c $EDITOR_CONTENT
0
1

