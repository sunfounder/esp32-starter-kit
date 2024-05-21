.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

Kommentare
=============

Die Kommentare im Code helfen uns, den Code zu verstehen, machen den gesamten Code lesbarer und kommentieren während des Testens Teile des Codes aus, so dass dieser Teil des Codes nicht ausgeführt wird.

Einzellinienkommentar
----------------------

Einzellinienkommentare in MicroPython beginnen mit #, und der nachfolgende Text wird bis zum Ende der Zeile als Kommentar betrachtet. Kommentare können vor oder nach dem Code platziert werden.

.. code-block:: python

    print("hello world") #This is a annotationhello world

>>> %Run -c $EDITOR_CONTENT
hello world

Kommentare müssen nicht unbedingt Text sein, der den Code erklärt. Sie können auch einen Teil des Codes auskommentieren, um zu verhindern, dass MicroPython den Code ausführt.


.. code-block:: python

    #print("Can't run it！")
    print("hello world") #This is a annotationhello world

>>> %Run -c $EDITOR_CONTENT
hello world

Mehrzeiliger Kommentar
----------------------

Wenn Sie mehrere Zeilen kommentieren möchten, können Sie mehrere # Zeichen verwenden.

.. code-block:: python

    #This is a comment
    #written in
    #more than just one line
    print("Hello, World!")

>>> %Run -c $EDITOR_CONTENT
Hello, World!

Oder Sie können mehrzeilige Zeichenketten verwenden, wenn erwartet.

Da MicroPython Zeichenkettenliterale ignoriert, die nicht Variablen zugewiesen werden, können Sie dem Code mehrzeilige Zeichenketten (dreifache Anführungszeichen) hinzufügen und Kommentare darin platzieren:

.. code-block:: python

    """
    This is a comment
    written in
    more than just one line
    """
    print("Hello, World!")

>>> %Run -c $EDITOR_CONTENT
Hello, World!

Solange die Zeichenkette keiner Variablen zugewiesen wird, ignoriert MicroPython sie nach dem Lesen des Codes und behandelt sie, als hätten Sie einen mehrzeiligen Kommentar gemacht.

