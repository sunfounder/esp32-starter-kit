Print()
=========

Die Funktion ``print()`` gibt die angegebene Nachricht auf dem Bildschirm oder einem anderen Standardausgabegerät aus.
Die Nachricht kann eine Zeichenkette oder ein anderes Objekt sein; das Objekt wird vor dem Schreiben auf dem Bildschirm in eine Zeichenkette umgewandelt.

Mehrere Objekte drucken:

.. code-block:: python

    print("Welcome!", "Enjoy yourself!")

>>> %Run -c $EDITOR_CONTENT
Welcome! Enjoy yourself!

Tupel drucken:

.. code-block:: python

    x = ("pear", "apple", "grape")
    print(x)

>>> %Run -c $EDITOR_CONTENT
('pear', 'apple', 'grape')

Zwei Nachrichten drucken und das Trennzeichen angeben:

.. code-block:: python

    print("Hello", "how are you?", sep="---")

>>> %Run -c $EDITOR_CONTENT
Hello---how are you?