Listen
===================

Listen werden verwendet, um mehrere Elemente in einer einzigen Variablen zu speichern, und werden mit eckigen Klammern erstellt:

.. code-block:: python

    B_list = ["Blossom", "Bubbles","Buttercup"]
    print(B_list)


Listenelemente sind veränderbar, geordnet und erlauben doppelte Werte.
Die Listenelemente sind indiziert, wobei das erste Element den Index [0], das zweite Element den Index [1] usw. hat.

.. code-block:: python

    C_list = ["Red", "Blue", "Green", "Blue"]
    print(C_list)            # duplicate
    print(C_list[0]) 
    print(C_list[1])         # ordered
    C_list[2] = "Purple"     # changeable
    print(C_list)

>>> %Run -c $EDITOR_CONTENT
['Red', 'Blue', 'Green', 'Blue']
Red
Blue
['Red', 'Blue', 'Purple', 'Blue']


Eine Liste kann verschiedene Datentypen enthalten:

.. code-block:: python

    A_list = ["Banana", 255, False, 3.14]
    print(A_list)

>>> %Run -c $EDITOR_CONTENT
['Banana', 255, False, 3.14]


Listenlänge
------------------
Um festzustellen, wie viele Elemente in der Liste sind, verwenden Sie die Funktion len().

.. code-block:: python

    A_list = ["Banana", 255, False, 3.14]
    print(len(A_list))

>>> %Run -c $EDITOR_CONTENT
4

Listenelemente prüfen
-----------------------

Drucken Sie das zweite Element der Liste aus:

.. code-block:: python

    A_list = ["Banana", 255, False, 3.14]
    print(A_list[1])

>>> %Run -c $EDITOR_CONTENT
[255]

Drucken Sie das letzte Element der Liste aus:

.. code-block:: python

    A_list = ["Banana", 255, False, 3.14]
    print(A_list[-1])

>>> %Run -c $EDITOR_CONTENT
[3.14]

Drucken Sie das zweite und dritte Element aus:

.. code-block:: python

    A_list = ["Banana", 255, False, 3.14]
    print(A_list[1:3])

>>> %Run -c $EDITOR_CONTENT
[255, False]


Listenelemente ändern
----------------------
Ändern Sie das zweite und dritte Element:

.. code-block:: python

    A_list = ["Banana", 255, False, 3.14]
    A_list[1:3] = [True,"Orange"] 
    print(A_list)

>>> %Run -c $EDITOR_CONTENT
['Banana', True, 'Orange', 3.14]

Ändern Sie das zweite Element, indem Sie es durch zwei Werte ersetzen:

.. code-block:: python

    A_list = ["Banana", 255, False, 3.14]
    A_list[1:2] = [True,"Orange"] 
    print(A_list)

>>> %Run -c $EDITOR_CONTENT
['Banana', True, 'Orange', False, 3.14]


Listenelemente hinzufügen
-----------------------------

Verwendung der Methode append(), um ein Element hinzuzufügen:

.. code-block:: python

    C_list = ["Red", "Blue", "Green"]
    C_list.append("Orange")
    print(C_list)

>>> %Run -c $EDITOR_CONTENT
['Red', 'Blue', 'Green', 'Orange']

Fügen Sie ein Element an der zweiten Position ein:

.. code-block:: python

    C_list = ["Red", "Blue", "Green"]
    C_list.insert(1, "Orange")
    print(C_list)

>>> %Run -c $EDITOR_CONTENT
['Red', 'Orange', 'Blue', 'Green']



Listenelemente entfernen
----------------------------

Die Methode remove() entfernt das angegebene Element.

.. code-block:: python

    C_list = ["Red", "Blue", "Green"]
    C_list.remove("Blue")
    print(C_list)

>>> %Run -c $EDITOR_CONTENT
['Red', 'Green']

Die Methode pop() entfernt den angegebenen Index. Wenn Sie den Index nicht angeben, entfernt die Methode pop() das letzte Element.

.. code-block:: python

    A_list = ["Banana", 255, False, 3.14, True,"Orange"]
    A_list.pop(1)
    print(A_list)
    A_list.pop()
    print(A_list)

>>> %Run -c $EDITOR_CONTENT
255
['Banana', False, 3.14, True, 'Orange']
'Orange'
['Banana', False, 3.14, True]

Das Schlüsselwort ``del`` entfernt ebenfalls den angegebenen Index:

.. code-block:: python

    C_list = ["Red", "Blue", "Green"]
    del C_list[1]
    print(C_list)

>>> %Run -c $EDITOR_CONTENT
['Red', 'Green']

Die Methode clear() leert die Liste. Die Liste bleibt bestehen, hat aber keinen Inhalt.

.. code-block:: python

    C_list = ["Red", "Blue", "Green"]
    C_list.clear()
    print(C_list)

>>> %Run -c $EDITOR_CONTENT
[]