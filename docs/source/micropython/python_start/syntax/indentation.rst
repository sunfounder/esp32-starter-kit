Indentación
=============

La indentación se refiere a los espacios al principio de una línea de código.
Al igual que los programas estándar de Python, los programas de MicroPython generalmente se ejecutan de arriba hacia abajo:
Recorre cada línea por turno, la ejecuta en el intérprete y luego continúa con la siguiente línea,
Justo como si los escribieras línea por línea en el Shell.
Sin embargo, un programa que simplemente recorre la lista de instrucciones línea por línea no es muy inteligente, por lo que MicroPython, al igual que Python, tiene su propio método para controlar la secuencia de ejecución de su programa: la indentación.

Debes poner al menos un espacio antes de print(), de lo contrario aparecerá un mensaje de error "Sintaxis inválida". Generalmente se recomienda estandarizar los espacios presionando uniformemente la tecla Tab.



.. code-block:: python

    if 8 > 5:
    print("¡Ocho es mayor que Cinco!")

>>> %Run -c $EDITOR_CONTENT
Traceback (most recent call last):
  File "<stdin>", line 2
SyntaxError: invalid syntax

Debes usar el mismo número de espacios en el mismo bloque de código, o Python te mostrará un error.


.. code-block:: python

    if 8 > 5:
    print("¡Ocho es mayor que Cinco!")
            print("Ocho es mayor que Cinco")
            
>>> %Run -c $EDITOR_CONTENT
Traceback (most recent call last):
  File "<stdin>", line 2
SyntaxError: invalid syntax

