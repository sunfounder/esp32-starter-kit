Datentypen
===========

Eingebaute Datentypen
---------------------
MicroPython hat die folgenden Datentypen:

* Texttyp: str
* Numerische Typen: int, float, complex
* Sequenztypen: list, tuple, range
* Zuordnungstyp: dict
* Mengentypen: set, frozenset
* Boolescher Typ: bool
* Binäre Typen: bytes, bytearray, memoryview

Ermitteln des Datentyps
-----------------------------
Sie können den Datentyp eines beliebigen Objekts mit der Funktion `type()` ermitteln:



.. code-block:: python

    a = 6.8
    print(type(a))

>>> %Run -c $EDITOR_CONTENT
<class 'float'>

Festlegen des Datentyps
--------------------------
MicroPython benötigt kein spezifisches Festlegen des Datentyps, dieser wird bestimmt, wenn Sie einer Variablen einen Wert zuweisen.



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

Festlegen des spezifischen Datentyps
---------------------------------------

Wenn Sie den Datentyp spezifizieren möchten, können Sie die folgenden Konstruktorfunktionen verwenden:

.. list-table:: 
    :widths: 25 10
    :header-rows: 1

    *   - Beispiel
        - Datentyp
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

Einige davon können Sie ausdrucken, um das Ergebnis zu sehen.



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

Typumwandlung
----------------
Sie können mit den Methoden int(), float() und complex() von einem Typ in einen anderen konvertieren:
Casting in Python erfolgt daher mit Konstruktorfunktionen:

* int() - konstruiert eine ganze Zahl aus einer Ganzzahl-, Fließkommazahl- oder Stringliteral (indem alle Dezimalstellen entfernt werden)
* float() - konstruiert eine Fließkommazahl aus einer Ganzzahl-, Fließkommazahl- oder Stringliteral (vorausgesetzt, der String stellt eine Fließkommazahl oder eine Ganzzahl dar)
* str() - konstruiert einen String aus einer Vielzahl von Datentypen, einschließlich Strings, Ganzzahl- und Fließkommazahlen



.. code-block:: python

    a = float("5")
    b = int(3.7)
    c = str(6.0)

    print(a)
    print(b)
    print(c)

Hinweis: Sie können komplexe Zahlen nicht in einen anderen Zahlentyp konvertieren.
