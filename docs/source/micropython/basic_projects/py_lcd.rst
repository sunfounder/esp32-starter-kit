.. _py_lcd1602:

2.6 Zeichenanzeige
==================================================

Jetzt werden wir die faszinierende Welt der Zeichenanzeige mit dem I2C LCD1602-Modul erkunden.

In diesem Projekt lernen wir, wie man das LCD-Modul initialisiert, die gewünschten Anzeigeparameter einstellt und Zeichendaten zur Anzeige auf dem Bildschirm sendet. Wir können benutzerdefinierte Nachrichten präsentieren, Sensordaten anzeigen oder interaktive Menüs erstellen. Die Möglichkeiten sind endlos!

Indem wir die Kunst der Zeichenanzeige auf dem I2C LCD1602 meistern, erschließen wir neue Wege für Kommunikation und Informationsanzeige in unseren Projekten. Lassen Sie uns in diese spannende Reise eintauchen und unsere Zeichen auf dem LCD-Bildschirm zum Leben erwecken.

**Benötigte Komponenten**

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein ganzes Set zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

Sie können sie auch separat über die unten stehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
        - KAUF-LINK

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - \-
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_lcd`
        - |link_i2clcd1602_buy|

**Verfügbare Pins**

Hier ist eine Liste der verfügbaren Pins auf dem ESP32-Board für dieses Projekt.

.. list-table::
    :widths: 5 15
    :header-rows: 1

    *   - Verfügbare Pins
        - Verwendungszweck

    *   - IO21
        - SDA
    *   - IO22
        - SCL
    
**Schaltplan**

.. image:: ../../img/circuit/circuit_2.6_lcd.png

**Verdrahtung**

.. image:: ../../img/wiring/2.6_i2clcd1602_bb.png
    :width: 800

**Code**

.. note::

    * Öffnen Sie die Datei ``2.6_liquid_crystal_display.py``, die sich im Pfad ``esp32-starter-kit-main\micropython\codes`` befindet, oder kopieren und fügen Sie den Code in Thonny ein. Klicken Sie dann auf "Aktuelles Skript ausführen" oder drücken Sie F5, um es auszuführen.
    * Stellen Sie sicher, dass Sie den Interpreter "MicroPython (ESP32).COMxx" in der unteren rechten Ecke ausgewählt haben. 
    * Die Bibliothek ``lcd1602.py`` wird hier verwendet. Überprüfen Sie, ob sie auf ESP32 hochgeladen ist. Siehe :ref:`add_libraries_py` für ein Tutorial.

.. code-block:: python

    # Import the LCD class from the lcd1602 module
    from lcd1602 import LCD

    import time

    # Create an instance of the LCD class and assign it to the lcd variable
    lcd = LCD()
    # Set the string " Hello!\n"
    string = " Hello!\n"
    # Display the string on the LCD screen
    lcd.message(string)

    time.sleep(2)
    # Set the string "    Sunfounder!"
    string = "    Sunfounder!"
    # Display the string on the LCD screen
    lcd.message(string)

    time.sleep(2)
    # Clear the LCD screen
    lcd.clear()


Nachdem das Skript ausgeführt wurde, werden Sie zwei Textzeilen auf dem LCD-Bildschirm nacheinander erscheinen und dann verschwinden sehen.


.. note:: 

    Wenn der Code und die Verdrahtung korrekt sind, das LCD aber trotzdem keinen Inhalt anzeigt, können Sie das Potentiometer auf der Rückseite justieren, um den Kontrast zu erhöhen.


**Wie funktioniert das?**

In der Bibliothek ``lcd1602`` integrieren wir die relevanten Funktionen von lcd1602 in die LCD-Klasse.

#. Importieren des ``lcd1602``-Moduls.

    .. code-block:: python

        from lcd1602 import LCD    

#. Deklarieren eines Objekts der Klasse ``LCD`` und Benennen es als ``lcd``.

    .. code-block:: python

        lcd = LCD()

#. Diese Anweisung wird den Text auf dem LCD anzeigen. Es sollte beachtet werden, dass das Argument ein Stringtyp sein muss. Wenn wir eine Ganzzahl oder Float übergeben wollen, müssen wir die erzwungene Konvertierungsanweisung ``str()`` verwenden.

    .. code-block:: python

        lcd.message(string)


#. Wenn Sie diese Anweisung mehrmals aufrufen, wird das lcd die Texte überlagern. Dies erfordert die Verwendung der folgenden Anweisung, um die Anzeige zu löschen.

    .. code-block:: python

        lcd.clear()


