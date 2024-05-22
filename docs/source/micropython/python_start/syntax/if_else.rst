.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

If Else
=============

La toma de decisiones es necesaria cuando queremos ejecutar un código solo si se cumple una determinada condición.

if
--------------------
.. code-block:: python

    if test expression:
        statement(s)

Aquí, el programa evalúa la ``test expression`` y ejecuta la ``statement`` solo cuando la ``test expression`` es Verdadera.

Si la ``test expression`` es Falsa, entonces la(s) ``statement(s)`` no será(n) ejecutada(s).

En MicroPython, la indentación indica el cuerpo de la declaración ``if``. El cuerpo comienza con una indentación y termina con la primera línea sin indentar.

Python interpreta los valores no cero como ``True``. None y 0 se interpretan como ``False``.

**Flujograma de la Declaración if**

.. image:: img/if_statement.png

**Ejemplo**

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

La declaración ``if..else`` evalúa la ``test expression`` y ejecutará el cuerpo de ``if`` solo cuando la condición de prueba sea ``True``.

Si la condición es ``False``, se ejecuta el cuerpo de ``else``. Se utiliza la indentación para separar los bloques.

**Flujograma de la Declaración if...else**

.. image:: img/if_else.png

**Ejemplo**

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

``Elif`` es la abreviatura de ``else if``. Nos permite verificar múltiples expresiones.

Si la condición del ``if`` es Falsa, se verifica la condición del siguiente bloque elif, y así sucesivamente.

Si todas las condiciones son ``False``, se ejecuta el cuerpo de ``else``.

Solo uno de varios bloques ``if...elif...else`` se ejecuta según las condiciones.

El bloque ``if`` solo puede tener un bloque ``else``. Pero puede tener múltiples bloques ``elif``.

**Flujograma de la Declaración if...elif...else**

.. image:: img/if_elif_else.png

**Ejemplo**

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


Nested if
---------------------

Podemos incrustar una declaración if dentro de otra declaración if, a lo que se llama una declaración if anidada.

**Ejemplo**

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