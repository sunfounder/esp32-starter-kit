.. note::

    ¡Hola, bienvenido a la Comunidad de Aficionados a Raspberry Pi, Arduino y ESP32 de SunFounder en Facebook! Profundiza en Raspberry Pi, Arduino y ESP32 con otros entusiastas.

    **¿Por qué unirse?**

    - **Soporte de expertos**: Resuelve problemas posventa y desafíos técnicos con ayuda de nuestra comunidad y equipo.
    - **Aprender y compartir**: Intercambia consejos y tutoriales para mejorar tus habilidades.
    - **Vistas previas exclusivas**: Obtén acceso anticipado a anuncios de nuevos productos y avances.
    - **Descuentos especiales**: Disfruta de descuentos exclusivos en nuestros productos más nuevos.
    - **Promociones festivas y sorteos**: Participa en sorteos y promociones de fiestas.

    👉 ¿Listo para explorar y crear con nosotros? Haz clic en [|link_sf_facebook|] y únete hoy!

Operadores
============
Los operadores se utilizan para realizar operaciones con variables y valores.

* :ref:`Operadores aritméticos`

* :ref:`Operadores de asignación`

* :ref:`Operadores de comparación`

* :ref:`Operadores lógicos`

* :ref:`Operadores de identidad`

* :ref:`Operadores de pertenencia`

* :ref:`Operadores a nivel de bits`

Operadores Aritméticos
-------------------------
Puedes utilizar los operadores aritméticos para realizar algunas operaciones matemáticas comunes.

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - Operador
        - Nombre
    *   - ``+``
        - Suma
    *   - ``-``
        - Resta
    *   - ``*``
        - Multiplicación
    *   - ``/``
        - División
    *   - ``%``
        - Módulo
    *   - ``**``
        - Exponenciación
    *   - ``//``
        - División entera



.. code-block:: python

    x = 5
    y = 3

    a = x + y
    b = x - y
    c = x * y
    d = x / y
    e = x % y
    f = x ** y
    g = x // y

    print(a)
    print(b)
    print(c)
    print(d)
    print(e)
    print(f)
    print(g)

>>> %Run -c $EDITOR_CONTENT
8
2
15
1.66667
2
125
1
8
2
15
>>> 

Operadores de Asignación
----------------------------------

Los operadores de asignación se utilizan para asignar valores a variables.

.. list-table:: 
    :widths: 10 30 30
    :header-rows: 1

    *   - Operador
        - Ejemplo
        - Equivalente a
    *   - ``=``
        - a = 6
        - a =6
    *   - ``+=``
        - a += 6
        - a = a + 6
    *   - ``-=``
        - a -= 6
        - a = a - 6
    *   - ``*=``
        - a ``*=`` 6
        - a = a * 6
    *   - ``/=``
        - a /= 6
        - a = a / 6
    *   - ``%=``
        - a %= 6
        - a = a % 6
    *   - ``**=``
        - a ``**=`` 6
        - a = a ** 6
    *   - ``//=``
        - a //= 6
        - a = a // 6
    *   - ``&=``
        - a &= 6
        - a = a & 6
    *   - ``|=``
        - a ``|=`` 6
        - a = a | 6
    *   - ``^=``
        - a ^= 6
        - a = a ^ 6
    *   - ``>>=``
        - a >>= 6
        - a = a >> 6
    *   - ``<<=``
        - a <<= 6
        - a = a << 6



.. code-block:: python

    a = 6

    a *= 6
    print(a)

>>> %Run test.py
36
>>> 

Operadores de Comparación
----------------------------
Los operadores de comparación se utilizan para comparar dos valores.

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - Operador
        - Nombre
    *   - ==
        - Igual
    *   - !=
        - Diferente
    *   - <
        - Menor que
    *   - >
        - Mayor que
    *   - >=
        - Mayor o igual que
    *   - <=
        - Menor o igual que




.. code-block:: python

    a = 6
    b = 8

    print(a>b)

>>> %Run test.py
False
>>> 

Devuelve **Falso**, porque **a** es menor que **b**.

Operadores Lógicos
-----------------------

Los operadores lógicos se utilizan para combinar declaraciones condicionales.

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - Operador
        - Descripción
    *   - and
        - Devuelve Verdadero si ambas declaraciones son verdaderas
    *   - or
        - Devuelve Verdadero si alguna de las declaraciones es verdadera
    *   - not
        - Invierte el resultado, devuelve Falso si el resultado es verdadero

.. code-block:: python

    a = 6
    print(a > 2 and a < 8)

>>> %Run -c $EDITOR_CONTENT
Verdadero
>>> 

Operadores de Identidad
---------------------------

Los operadores de identidad se utilizan para comparar los objetos, no si son iguales, sino si son realmente el mismo objeto, con la misma ubicación en la memoria.

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - Operador
        - Descripción
    *   - is
        - Devuelve Verdadero si ambas variables son el mismo objeto
    *   - is not
        - Devuelve Verdadero si ambas variables no son el mismo objeto

.. code-block:: python

    a = ["hola", "bienvenido"]
    b = ["hola", "bienvenido"]
    c = a

    print(a is c)
    # devuelve Verdadero porque z es el mismo objeto que x

    print(a is b)
    # devuelve Falso porque x no es el mismo objeto que y, incluso si tienen el mismo contenido

    print(a == b)
    # devuelve Verdadero porque x es igual a y

>>> %Run -c $EDITOR_CONTENT
Verdadero
Falso
Verdadero
>>> 

Operadores de Pertenencia
----------------------------
Los operadores de pertenencia se utilizan para probar si una secuencia está presente en un objeto.

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - Operador
        - Descripción
    *   - in
        - Devuelve Verdadero si una secuencia con el valor especificado está presente en el objeto
    *   - not in
        - Devuelve Verdadero si una secuencia con el valor especificado no está presente en el objeto

.. code-block:: python

    a = ["hola", "bienvenido", "buenos días"]

    print("bienvenido" in a)

>>> %Run -c $EDITOR_CONTENT
Verdadero
>>> 

Operadores a Nivel de Bits
-----------------------------

Los operadores a nivel de bits se utilizan para comparar (binariamente) números.

.. list-table:: 
    :widths: 10 20 50
    :header-rows: 1

    *   - Operador
        - Nombre
        - Descripción
    *   - &
        - AND
        - Establece cada bit en 1 si ambos bits son 1
    *   - |
        - OR
        - Establece cada bit en 1 si uno de los dos bits es 1
    *   - ^
        - XOR
        - Establece cada bit en 1 solo si uno de los dos bits es 1
    *   - ~
        - NOT
        - Invierte todos los bits
    *   - <<
        - Desplazamiento a la izquierda con relleno de ceros
        - Desplaza a la izquierda introduciendo ceros desde la derecha y dejando caer los bits más a la izquierda
    *   - >>
        - Desplazamiento a la derecha con signo
        - Desplaza a la derecha introduciendo copias del bit más a la izquierda desde la izquierda, y dejando caer los bits más a la derecha

.. code-block:: python

    num = 2

    print(num & 1)
    print(num | 1)
    print(num << 1)

>>> %Run -c $EDITOR_CONTENT
0
3
4
>>>
