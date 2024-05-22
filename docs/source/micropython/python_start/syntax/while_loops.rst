.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

Bucles While
====================

La instrucción ``while`` se utiliza para ejecutar un programa en un bucle, es decir, para ejecutar un programa en bucle bajo ciertas condiciones para manejar la misma tarea que necesita ser procesada repetidamente.

Su forma básica es:

.. code-block:: python

    while test expression:
        Body of while


En el bucle ``while``, primero se verifica la ``test expression``. Solo cuando la ``test expression`` se evalúa como ``True``, se entra en el cuerpo del while. Después de una iteración, se verifica nuevamente la ``test expression``. Este proceso continúa hasta que la ``test expression`` se evalúa como ``False``.

En MicroPython, el cuerpo del bucle ``while`` se determina por la indentación.

El cuerpo comienza con una indentación y termina con la primera línea sin indentar.

Python interpreta cualquier valor no cero como ``True``. None y 0 se interpretan como ``False``.

**Diagrama de flujo del bucle while**

.. image:: img/while_loop.png



.. code-block:: python

    x = 10

    while x > 0:
        print(x)
        x -= 1

>>> %Run -c $EDITOR_CONTENT
10
9
8
7
6
5
4
3
2
1


Instrucción Break
--------------------

Con la instrucción break podemos detener el bucle incluso si la condición del while es verdadera:



.. code-block:: python

    x = 10

    while x > 0:
        print(x)
        if x == 6:
            break
        x -= 1

>>> %Run -c $EDITOR_CONTENT
10
9
8
7
6

Bucle While con Else
----------------------
Al igual que el bucle ``if``, el bucle ``while`` también puede tener un bloque ``else`` opcional.

Si la condición en el bucle ``while`` se evalúa como ``False``, se ejecuta la parte ``else``.



.. code-block:: python

    x = 10

    while x > 0:
        print(x)
        x -= 1
    else:
        print("Game Over")

>>> %Run -c $EDITOR_CONTENT
10
9
8
7
6
5
4
3
2
1
Game Over