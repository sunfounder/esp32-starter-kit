Comentarios
=============

Los comentarios en el código nos ayudan a entender el código, hacen que todo el código sea más legible y comentan parte del código durante las pruebas, de modo que esta parte del código no se ejecute.

Comentario de Una Línea
----------------------------

Los comentarios de una línea en MicroPython comienzan con #, y el texto siguiente se considera un comentario hasta el final de la línea. Los comentarios se pueden colocar antes o después del código.

.. code-block:: python

    print("hello world") #This is a annotationhello world

>>> %Run -c $EDITOR_CONTENT
hello world

Los comentarios no son necesariamente texto usado para explicar el código. También puedes comentar parte del código para evitar que micropython ejecute el código.


.. code-block:: python

    #print("Can't run it！")
    print("hello world") #This is a annotationhello world

>>> %Run -c $EDITOR_CONTENT
hello world

Comentario Multilínea
------------------------------

Si deseas comentar en múltiples líneas, puedes usar múltiples signos #.

.. code-block:: python

    #This is a comment
    #written in
    #more than just one line
    print("Hello, World!")

>>> %Run -c $EDITOR_CONTENT
Hello, World!

O, puedes usar cadenas de múltiples líneas en lugar de lo esperado.

Dado que MicroPython ignora las literales de cadena que no se asignan a variables, puedes agregar múltiples líneas de cadenas (comillas triples) al código y poner comentarios en ellas:

.. code-block:: python

    """
    This is a comment
    written in
    more than just one line
    """
    print("Hello, World!")

>>> %Run -c $EDITOR_CONTENT
Hello, World!

Mientras la cadena no se asigne a una variable, MicroPython la ignorará después de leer el código y la tratará como si hubieras hecho un comentario multilínea.
