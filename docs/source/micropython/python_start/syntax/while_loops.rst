.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

While-Schleifen
====================

Das ``while``-Statement wird verwendet, um ein Programm in einer Schleife auszuführen, d.h., es ermöglicht die wiederholte Ausführung einer Aufgabe unter bestimmten Bedingungen.

Seine grundlegende Form lautet:

.. code-block:: python

    while test expression:
        Body of while


In der ``while``-Schleife wird zuerst der ``test expression`` geprüft. Nur wenn der ``test expression`` als ``True`` bewertet wird, tritt man in den Körper der Schleife ein. Nach einer Iteration wird der ``test expression`` erneut geprüft. Dieser Prozess setzt sich fort, bis der ``test expression`` als ``False`` bewertet wird.

In MicroPython wird der Körper der ``while``-Schleife durch Einrückung bestimmt.

Der Körper beginnt mit einer Einrückung und endet mit der ersten nicht eingerückten Zeile.

Python interpretiert jeden Nicht-Null-Wert als ``True``. None und 0 werden als ``False`` interpretiert.

**Flussdiagramm der while-Schleife**

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


Break-Statement
--------------------

Mit dem Break-Statement können wir die Schleife stoppen, auch wenn die Bedingung der while-Schleife wahr ist:



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

While-Schleife mit Else
---------------------------
Ähnlich wie die `if`-Schleife kann auch die `while`-Schleife einen optionalen `else`-Block haben.

Wenn die Bedingung in der `while`-Schleife als `False` bewertet wird, wird der `else`-Teil ausgeführt.



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
