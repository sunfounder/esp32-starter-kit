.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

Funktionen
==============

In MicroPython ist eine Funktion eine Gruppe von zusammenhängenden Anweisungen, die eine spezifische Aufgabe ausführen.

Funktionen helfen dabei, unser Programm in kleinere, modulare Blöcke zu unterteilen. Je größer unser Projekt wird, desto organisierter und handhabbarer machen es Funktionen.

Außerdem vermeiden sie Duplikation und machen den Code wiederverwendbar.

Erstellen einer Funktion
---------------------------

.. code-block::

    def function_name（parameters)：
        """docstring"""
        statement(s)

* Eine Funktion wird mit dem Schlüsselwort ``def`` definiert.

* Ein Funktionsname zur eindeutigen Identifikation der Funktion. Die Benennung von Funktionen entspricht der von Variablen und folgt folgenden Regeln:
    
   * Darf nur Zahlen, Buchstaben und Unterstriche enthalten.
   * Das erste Zeichen muss ein Buchstabe oder ein Unterstrich sein.
   * Groß- und Kleinschreibung wird unterschieden.

* Parameter (Argumente), durch die wir Werte an eine Funktion übergeben. Sie sind optional.

* Der Doppelpunkt (:) markiert das Ende des Funktionskopfs.

* Ein optionaler Docstring, der verwendet wird, um die Funktion der Funktion zu beschreiben. Wir verwenden normalerweise dreifache Anführungszeichen, damit der Docstring über mehrere Zeilen erweitert werden kann.

* Eine oder mehrere gültige MicroPython-Anweisungen, die den Funktionskörper bilden. Die Anweisungen müssen das gleiche Einrückungsniveau haben (üblicherweise 4 Leerzeichen).

* Jede Funktion benötigt mindestens eine Anweisung, aber wenn es aus irgendeinem Grund eine Funktion gibt, die keine Anweisung enthält, sollte ein pass-Statement eingefügt werden, um Fehler zu vermeiden.

* Ein optionales ``return``-Statement, um einen Wert aus der Funktion zurückzugeben.


Aufrufen einer Funktion
--------------------------

Um eine Funktion aufzurufen, fügen Sie Klammern nach dem Funktionsnamen hinzu.



.. code-block:: python

    def my_function():
        print("Your first function")

    my_function()

>>> %Run -c $EDITOR_CONTENT
Your first function

Das return-Statement
-----------------------

Das return-Statement wird verwendet, um eine Funktion zu beenden und an den Ort zurückzukehren, an dem sie aufgerufen wurde.

**Syntax von return**

.. code-block:: python

    return [expression_list]

Das Statement kann einen Ausdruck enthalten, der ausgewertet wird und einen Wert zurückgibt. Wenn kein Ausdruck im Statement vorhanden ist oder das ``return``-Statement selbst in der Funktion nicht existiert, gibt die Funktion ein ``None``-Objekt zurück.



.. code-block:: python

    def my_function():
            print("Your first function")

    print(my_function())

>>> %Run -c $EDITOR_CONTENT
Your first function
None

Hier ist ``None`` der Rückgabewert, da das ``return``-Statement nicht verwendet wird.

Argumente
-------------

Informationen können als Argumente an die Funktion übergeben werden.

Spezifizieren Sie Argumente in Klammern nach dem Funktionsnamen. Sie können so viele Argumente hinzufügen, wie Sie benötigen, trennen Sie sie einfach durch Kommata.

.. code-block:: python

    def welcome(name, msg):
        """This is a welcome function for
        the person with the provided message"""
        print("Hello", name + ', ' + msg)

    welcome("Lily", "Welcome to China!")

>>> %Run -c $EDITOR_CONTENT
Hello Lily, Welcome to China!


Anzahl der Argumente
*************************

Standardmäßig muss eine Funktion mit der korrekten Anzahl von Argumenten aufgerufen werden. Das bedeutet, dass, wenn Ihre Funktion 2 Parameter erwartet, Sie die Funktion auch mit 2 Argumenten aufrufen müssen, nicht mehr und nicht weniger.



.. code-block:: python

    def welcome(name, msg):
        """This is a welcome function for
        the person with the provided message"""
        print("Hello", name + ', ' + msg)

    welcome("Lily", "Welcome to China!")

Hier hat die Funktion willkommen() 2 Parameter.

Da wir diese Funktion mit zwei Argumenten aufgerufen haben, läuft sie reibungslos und ohne Fehler.

Wird sie mit einer anderen Anzahl von Argumenten aufgerufen, zeigt der Interpreter eine Fehlermeldung an.

Folgendes ist der Aufruf dieser Funktion mit einem und keinem Argument sowie deren jeweilige Fehlermeldungen.

.. code-block::

    welcome("Lily")＃Only one argument

>>> %Run -c $EDITOR_CONTENT
Traceback (most recent call last):
  File "<stdin>", line 6, in <module>
TypeError: function takes 2 positional arguments but 1 were given

.. code-block::

    welcome()＃No arguments

>>> %Run -c $EDITOR_CONTENT
Traceback (most recent call last):
  File "<stdin>", line 6, in <module>
TypeError: function takes 2 positional arguments but 0 were given


Standardargumente
*************************

In MicroPython können wir den Zuweisungsoperator (=) verwenden, um einen Standardwert für den Parameter anzugeben.

Wenn wir die Funktion ohne Argument aufrufen, verwendet sie den Standardwert.



.. code-block:: python

    def welcome(name, msg = "Welcome to China!"):
        """This is a welcome function for
        the person with the provided message"""
        print("Hello", name + ', ' + msg)
    welcome("Lily")

>>> %Run -c $EDITOR_CONTENT
Hello Lily, Welcome to China!

In dieser Funktion hat der Parameter ``name`` keinen Standardwert und ist beim Aufruf erforderlich (obligatorisch).

Andererseits ist der Standardwert des Parameters ``msg`` "Willkommen in China!". Daher ist er beim Aufruf optional. Wird ein Wert bereitgestellt, überschreibt er den Standardwert.

Jedes Argument in der Funktion kann einen Standardwert haben. Sobald jedoch ein Standardargument vorhanden ist, müssen auch alle Argumente rechts davon Standardwerte haben.

Das bedeutet, dass nicht-standardmäßige Argumente nicht auf Standardargumente folgen können. 

Zum Beispiel, wenn wir den obigen Funktionskopf wie folgt definieren:

.. code-block:: python

    def welcome(name = "Lily", msg):

Erhalten wir folgende Fehlermeldung:

>>> %Run -c $EDITOR_CONTENT
Traceback (most recent call last):
  File "<stdin>", line 1, in <module>
SyntaxError: non-default argument follows default argument


Schlüsselwortargumente
**************************

Wenn wir eine Funktion mit bestimmten Werten aufrufen, werden diese Werte basierend auf ihrer Position den Argumenten zugewiesen.

Zum Beispiel, in der oben genannten Funktion willkommen(), als wir sie mit willkommen("Lily", "Willkommen in China") aufgerufen haben, wird der Wert "Lily" dem ``name`` und entsprechend "Willkommen in China" dem Parameter ``msg`` zugewiesen.

MicroPython erlaubt das Aufrufen von Funktionen mit Schlüsselwortargumenten. Wenn wir die Funktion auf diese Weise aufrufen, kann die Reihenfolge (Position) der Argumente geändert werden. 

.. code-block:: python

    # keyword arguments
    welcome(name = "Lily",msg = "Welcome to China!")

    # keyword arguments (out of order)
    welcome(msg = "Welcome to China！",name = "Lily") 

    #1 positional, 1 keyword argument
    welcome("Lily", msg = "Welcome to China!")

Wie wir sehen können, können wir positionelle Argumente und Schlüsselwortargumente bei Funktionsaufrufen mischen. Aber wir müssen uns daran erinnern, dass die Schlüsselwortargumente nach den positionellen Argumenten kommen müssen.

Ein positionelles Argument nach einem Schlüsselwortargument führt zu einem Fehler. 

Zum Beispiel, wenn der Funktionsaufruf wie folgt ist:

.. code-block:: python

    welcome(name="Lily","Welcome to China!")

Führt dies zu einem Fehler:

>>> %Run -c $EDITOR_CONTENT
Traceback (most recent call last):
  File "<stdin>", line 5, in <module>
SyntaxError: non-keyword arg after keyword arg


Beliebige Argumente
********************

Manchmal, wenn Sie nicht wissen, wie viele Argumente an die Funktion übergeben werden. 

In der Funktionsdefinition können wir einen Stern (*) vor dem Parameternamen hinzufügen.



.. code-block:: python

    def welcome(*names):
        """This function welcomes all the person
        in the name tuple"""
        #names is a tuple with arguments
        for name in names:
            print("Welcome to China!", name)
            
    welcome("Lily","John","Wendy")

>>> %Run -c $EDITOR_CONTENT
Welcome to China! Lily
Welcome to China! John
Welcome to China! Wendy

Hier haben wir die Funktion mit mehreren Argumenten aufgerufen. Diese Argumente werden in ein Tupel gepackt, bevor sie an die Funktion übergeben werden. 

Innerhalb der Funktion verwenden wir eine Schleife, um alle Argumente abzurufen.


Rekursion
----------------
In Python wissen wir, dass eine Funktion andere Funktionen aufrufen kann. Es ist sogar möglich, dass die Funktion sich selbst aufruft. Solche Konstrukte werden als rekursive Funktionen bezeichnet.

Dies hat den Vorteil, dass man Daten durchlaufen kann, um ein Ergebnis zu erreichen.

Entwickler sollten bei der Rekursion sehr vorsichtig sein, da es leicht passieren kann, dass man eine Funktion schreibt, die niemals endet, oder eine, die übermäßig viel Speicher oder Prozessorleistung verbraucht. Wenn sie jedoch korrekt geschrieben ist, kann Rekursion eine sehr effiziente und mathematisch-elegante Herangehensweise an die Programmierung sein.



.. code-block:: python

    def rec_func(i):
        if(i > 0):
            result = i + rec_func(i - 1)
            print(result)
        else:
            result = 0
        return result

    rec_func(6)

>>> %Run -c $EDITOR_CONTENT
1
3
6
10
15
21

In diesem Beispiel ist rek_funktion() eine Funktion, die wir definiert haben, um sich selbst aufzurufen ("Rekursion"). Wir verwenden die Variable ``i`` als Daten, und sie wird bei jeder Rekursion um eins verringert (-1). Wenn die Bedingung nicht größer als 0 ist (also 0), endet die Rekursion.

Für neue Entwickler kann es einige Zeit dauern, um zu verstehen, wie es funktioniert, und der beste Weg, es zu testen, ist es zu testen und zu modifizieren.

**Vorteile der Rekursion**

* Rekursive Funktionen machen den Code sauber und elegant.
* Eine komplexe Aufgabe kann mit Rekursion in einfachere Teilprobleme zerlegt werden.
* Die Generierung von Sequenzen ist mit Rekursion einfacher als mit verschachtelten Iterationen.

**Nachteile der Rekursion**

* Manchmal ist die Logik hinter der Rekursion schwer nachzuvollziehen.
* Rekursive Aufrufe sind teuer (ineffizient), da sie viel Speicher und Zeit in Anspruch nehmen.
* Rekursive Funktionen sind schwer zu debuggen.

