Einrückung
===========

Einrückung bezieht sich auf die Leerzeichen am Anfang einer Codezeile.
Wie bei Standard-Python-Programmen laufen MicroPython-Programme normalerweise von oben nach unten:
Das Programm durchläuft jede Zeile der Reihe nach, führt sie im Interpreter aus und geht dann zur nächsten Zeile über,
genau so, als ob Sie sie Zeile für Zeile in der Shell eintippen.
Ein Programm, das einfach die Anweisungsliste Zeile für Zeile durchblättert, ist jedoch nicht sehr intelligent - deshalb hat MicroPython, genau wie Python, seine eigene Methode, um die Ausführungsreihenfolge seines Programms zu steuern: Einrückung.

Sie müssen mindestens ein Leerzeichen vor print() setzen, sonst erscheint eine Fehlermeldung "Ungültige Syntax". Es wird normalerweise empfohlen, die Leerzeichen durch gleichmäßiges Drücken der Tab-Taste zu standardisieren.



.. code-block:: python

    if 8 > 5:
    print("Eight is greater than Five!")

>>> %Run -c $EDITOR_CONTENT
Traceback (most recent call last):
  File "<stdin>", line 2
SyntaxError: invalid syntax

Sie müssen die gleiche Anzahl von Leerzeichen im gleichen Codeblock verwenden, sonst wird Python einen Fehler melden.


.. code-block:: python

    if 8 > 5:
    print("Eight is greater than Five!")
            print("Eight is greater than Five")
            
>>> %Run -c $EDITOR_CONTENT
Traceback (most recent call last):
  File "<stdin>", line 2
SyntaxError: invalid syntax

