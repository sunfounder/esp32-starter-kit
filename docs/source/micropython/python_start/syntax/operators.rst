.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

Operatoren
============
Operatoren werden verwendet, um Operationen mit Variablen und Werten durchzuführen.

* :ref:`Arithmetische Operatoren`

* :ref:`Zuweisungsoperatoren`

* :ref:`Vergleichsoperatoren`

* :ref:`Logische Operatoren`

* :ref:`Identitätsoperatoren`

* :ref:`Mitgliedschaftsoperatoren`

* :ref:`Bitweise Operatoren`

Arithmetische Operatoren
---------------------------
Sie können arithmetische Operatoren verwenden, um einige gängige mathematische Operationen durchzuführen.

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - Operator
        - Name
    *   - `+`
        - Addition
    *   - `-`
        - Subtraktion
    *   - `*`
        - Multiplikation
    *   - `/`
        - Division
    *   - `%`
        - Modulo
    *   - `**`
        - Potenzierung
    *   - `//`
        - Ganzzahlige Division



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

Zuweisungsoperatoren
---------------------

Zuweisungsoperatoren können verwendet werden, um Werte an Variablen zuzuweisen.

.. list-table:: 
    :widths: 10 30 30
    :header-rows: 1

    *   - Operator
        - Example
        - Same As
    *   - `=`
        - a = 6
        - a =6
    *   - `+=`
        - a += 6
        - a = a + 6
    *   - `-=`
        - a -= 6
        - a = a - 6
    *   - `*=`
        - a `*=` 6
        - a = a * 6
    *   - `/=`
        - a /= 6
        - a = a / 6
    *   - `%=`
        - a %= 6
        - a = a % 6
    *   - `**=`
        - a `**=` 6
        - a = a ** 6
    *   - `//=`
        - a //= 6
        - a = a // 6
    *   - `&=`
        - a &= 6
        - a = a & 6
    *   - `|=`
        - a `|=` 6
        - a = a | 6
    *   - `^=`
        - a ^= 6
        - a = a ^ 6
    *   - `>>=`
        - a >>= 6
        - a = a >> 6
    *   - `<<=`
        - a <<= 6
        - a = a << 6



.. code-block:: python

    a = 6

    a *= 6
    print(a)

>>> %Run test.py
36
>>> 

Vergleichsoperatoren
------------------------
Vergleichsoperatoren werden verwendet, um zwei Werte zu vergleichen.

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - Operator
        - Name
    *   - ==
        - Gleich
    *   - !=
        - Ungleich
    *   - <
        - Kleiner als
    *   - >
        - Größer als
    *   - >=
        - Größer als oder gleich
    *   - <=
        - Kleiner als oder gleich




.. code-block:: python

    a = 6
    b = 8

    print(a>b)

>>> %Run test.py
False
>>> 

Gibt **False** zurück, weil **a** kleiner als **b** ist.

Logische Operatoren
-----------------------

Logische Operatoren werden verwendet, um bedingte Aussagen zu kombinieren.

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - Operator
        - Beschreibung
    *   - and
        - Gibt True zurück, wenn beide Aussagen wahr sind
    *   - or
        - Gibt True zurück, wenn eine der Aussagen wahr ist
    *   - not
        - Kehrt das Ergebnis um, gibt False zurück, wenn das Ergebnis wahr ist

.. code-block:: python

    a = 6
    print(a > 2 and a < 8)

>>> %Run -c $EDITOR_CONTENT
True
>>> 

Identitätsoperatoren
------------------------

Identitätsoperatoren werden verwendet, um zu vergleichen, ob Objekte gleich sind, nicht ob sie gleich sind, sondern ob sie tatsächlich dasselbe Objekt mit demselben Speicherort sind.

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - Operator
        - Beschreibung
    *   - is
        - Gibt True zurück, wenn beide Variablen dasselbe Objekt sind
    *   - is not
        - Gibt True zurück, wenn beide Variablen nicht dasselbe Objekt sind

.. code-block:: python

    a = ["hello", "welcome"]
    b = ["hello", "welcome"]
    c = a

    print(a is c)
    # returns True because z is the same object as x

    print(a is b)
    # returns False because x is not the same object as y, even if they have the same content

    print(a == b)
    # returns True because x is equal to y

>>> %Run -c $EDITOR_CONTENT
True
False
True
>>> 

Mitgliedschaftsoperatoren
-----------------------------
Mitgliedschaftsoperatoren werden verwendet, um zu testen, ob eine Sequenz in einem Objekt vorhanden ist.

.. list-table:: 
    :widths: 10 30
    :header-rows: 1

    *   - Operator
        - Beschreibung
    *   - in
        - Gibt True zurück, wenn eine Sequenz mit dem angegebenen Wert im Objekt vorhanden ist
    *   - not in
        - Gibt True zurück, wenn eine Sequenz mit dem angegebenen Wert nicht im Objekt vorhanden ist

.. code-block:: python

    a = ["hello", "welcome", "Goodmorning"]

    print("welcome" in a)

>>> %Run -c $EDITOR_CONTENT
True
>>> 

Bitweise Operatoren
------------------------

Bitweise Operatoren werden verwendet, um (binäre) Zahlen zu vergleichen.

.. list-table:: 
    :widths: 10 20 50
    :header-rows: 1

    *   - Operator
        - Name
        - Beschreibung
    *   - &
        - AND
        - Setzt jedes Bit auf 1, wenn beide Bits 1 sind
    *   - |
        - OR
        - Setzt jedes Bit auf 1, wenn eines von zwei Bits 1 ist
    *   - ^
        - XOR
        - Setzt jedes Bit auf 1, wenn nur eines von zwei Bits 1 ist
    *   - ~
        - NOT
        - Invertiert alle Bits
    *   - <<
        - Zero-Fill-Linksverschiebung
        - Verschiebt nach links, indem Nullen von rechts eingeschoben werden und die linken Bits herausfallen
    *   - >>
        - Signierte Rechtsverschiebung
        - Verschiebt nach rechts, indem Kopien des linken Bits von links eingeschoben werden und die rechten Bits herausfallen

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