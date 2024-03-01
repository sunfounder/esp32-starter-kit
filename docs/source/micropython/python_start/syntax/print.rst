Print()
=====================

La función ``print()`` imprime el mensaje especificado en la pantalla o en otro dispositivo de salida estándar.
El mensaje puede ser una cadena de texto o cualquier otro objeto; el objeto se convertirá en una cadena antes de ser escrito en la pantalla.

Imprimir múltiples objetos:



.. code-block:: python

    print("Welcome!", "Enjoy yourself!")

>>> %Run -c $EDITOR_CONTENT
Welcome! Enjoy yourself!

Imprimir tuplas:



.. code-block:: python

    x = ("pear", "apple", "grape")
    print(x)

>>> %Run -c $EDITOR_CONTENT
('pear', 'apple', 'grape')

Imprimir dos mensajes y especificar el separador:



.. code-block:: python

    print("Hello", "how are you?", sep="---")

>>> %Run -c $EDITOR_CONTENT
Hello---how are you?