.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

Variablen
==========
Variablen sind Behälter, die verwendet werden, um Datenwerte zu speichern.

Das Erstellen einer Variablen ist sehr einfach. Sie müssen ihr nur einen Namen geben und ihr einen Wert zuweisen. Sie müssen den Datentyp der Variablen bei der Zuweisung nicht angeben, denn die Variable ist eine Referenz, und sie greift durch Zuweisung auf Objekte verschiedener Datentypen zu.

Die Benennung von Variablen muss folgenden Regeln folgen:

* Variablennamen dürfen nur Zahlen, Buchstaben und Unterstriche enthalten
* Das erste Zeichen des Variablennamens muss ein Buchstabe oder Unterstrich sein
* Variablennamen sind groß- und kleinschreibungsempfindlich

Variable Erstellen
------------------
Es gibt keinen Befehl zum Deklarieren von Variablen in MicroPython. Variablen werden erstellt, wenn Sie ihnen zum ersten Mal einen Wert zuweisen. Es ist keine spezifische Typdeklaration erforderlich, und Sie können sogar den Typ nach dem Setzen der Variablen ändern.

.. code-block:: python

    x = 8       # x is of type int
    x = "lily" # x is now of type str
    print(x)

>>> %Run -c $EDITOR_CONTENT
lily

Casting
-------------
Wenn Sie den Datentyp für die Variable festlegen möchten, können Sie dies durch Casting tun.

.. code-block:: python

    x = int(5)    # y will be 5
    y = str(5)    # x will be '5'
    z = float(5)  # z will be 5.0
    print(x,y,z)

>>> %Run -c $EDITOR_CONTENT
5 5 5.0

Den Typ Erhalten
-------------------
Sie können den Datentyp einer Variablen mit der Funktion `type()` erhalten.

.. code-block:: python

    x = 5
    y = "hello"
    z = 5.0
    print(type(x),type(y),type(z))

>>> %Run -c $EDITOR_CONTENT
<class 'int'> <class 'str'> <class 'float'>

Einfache oder Doppelte Anführungszeichen?
--------------------------------------------

In MicroPython können einfache oder doppelte Anführungszeichen verwendet werden, um String-Variablen zu definieren.



.. code-block:: python

    x = "hello"
    # is the same as
    x = 'hello'

Groß- und Kleinschreibung
-----------------------------
Variablennamen sind groß- und kleinschreibungsempfindlich.

.. code-block:: python

    a = 5
    A = "lily"
    #A will not overwrite a
    print(a, A)

>>> %Run -c $EDITOR_CONTENT
5 lily