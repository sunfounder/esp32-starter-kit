Tipos de Datos
=====================================

Tipos de Datos Incorporados
----------------------------------
MicroPython tiene los siguientes tipos de datos:

* Tipo de Texto: str
* Tipos Numéricos: int, float, complex
* Tipos de Secuencia: list, tuple, range
* Tipo de Mapeo: dict
* Tipos de Conjuntos: set, frozenset
* Tipo Booleano: bool
* Tipos Binarios: bytes, bytearray, memoryview

Obtener el Tipo de Datos
-----------------------------
Puedes obtener el tipo de datos de cualquier objeto utilizando la función ``type()``:



.. code-block:: python

    a = 6.8
    print(type(a))

>>> %Run -c $EDITOR_CONTENT
<class 'float'>

Estableciendo el Tipo de Datos
-------------------------------------
MicroPython no necesita establecer el tipo de datos específicamente, se determina cuando asignas un valor a la variable.



.. code-block:: python

    x = "welcome"
    y = 45
    z = ["apple", "banana", "cherry"]

    print(type(x))
    print(type(y))
    print(type(z))

>>> %Run -c $EDITOR_CONTENT
<class 'str'>
<class 'int'>
<class 'list'>
>>> 

Estableciendo el Tipo de Datos Específico
------------------------------------------------

Si deseas especificar el tipo de datos, puedes usar las siguientes funciones constructoras:

.. list-table:: 
    :widths: 25 10
    :header-rows: 1

    *   - Ejemplo
        - Tipo de Dato
    *   - x = int(20)
        - int
    *   - x = float(20.5)
        - float
    *   - x = complex(1j)
        - complex
    *   - x = str("Hello World")
        - str
    *   - x = list(("apple", "banana", "cherry"))
        - list
    *   - x = tuple(("apple", "banana", "cherry"))
        - tuple
    *   - x = range(6)
        - range
    *   - x = dict(name="John", age=36)
        - dict
    *   - x = set(("apple", "banana", "cherry"))
        - set
    *   - x = frozenset(("apple", "banana", "cherry"))
        - frozenset
    *   - x = bool(5)
        - bool
    *   - x = bytes(5)
        - bytes
    *   - x = bytearray(5)
        - bytearray
    *   - x = memoryview(bytes(5))
        - memoryview

Puedes imprimir algunos de ellos para ver el resultado.



.. code-block:: python

    a = float(20.5)
    b = list(("apple", "banana", "cherry"))
    c = bool(5)

    print(a)
    print(b)
    print(c)

>>> %Run -c $EDITOR_CONTENT
20.5
['apple', 'banana', 'cherry']
True
>>> 

Conversión de Tipos
-----------------------
Puedes convertir de un tipo a otro con los métodos int(), float() y complex():
La conversión en python se realiza, por lo tanto, usando funciones constructoras:

* int() - construye un número entero a partir de un literal entero, un literal flotante (eliminando todos los decimales) o un literal de cadena (siempre que la cadena represente un número entero)
* float() - construye un número flotante a partir de un literal entero, un literal flotante o un literal de cadena (siempre que la cadena represente un flotante o un entero)
* str() - construye una cadena a partir de una amplia variedad de tipos de datos, incluyendo cadenas, literales enteros y literales flotantes



.. code-block:: python

    a = float("5")
    b = int(3.7)
    c = str(6.0)

    print(a)
    print(b)
    print(c)

Nota: No puedes convertir números complejos en otro tipo de número.
