.. _sh_balloon:

2.12 SPIEL - Ballon Aufblasen
=========================================

Hier spielen wir ein Ballonaufblas-Spiel.

Nachdem die grüne Flagge angeklickt wurde, wird der Ballon immer größer. Wenn der Ballon zu groß wird, platzt er; wenn der Ballon zu klein ist, fällt er herunter; du musst beurteilen, wann du den Knopf drücken solltest, um ihn nach oben fliegen zu lassen.

.. image:: img/13_balloon0.png

Benötigte Komponenten
---------------------

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein ganzes Set zu kaufen. Hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name	
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

Sie können sie auch separat über die untenstehenden Links kaufen.

.. list-table::
    :widths: 30 20
    :header-rows: 1

    *   - KOMPONENTENBESCHREIBUNG
        - KAUF-LINK

    *   - :ref:`cpn_esp32_wroom_32e`
        - |link_esp32_wroom_32e_buy|
    *   - :ref:`cpn_esp32_camera_extension`
        - \-
    *   - :ref:`cpn_breadboard`
        - |link_breadboard_buy|
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_resistor`
        - |link_resistor_buy|
    *   - :ref:`cpn_button`
        - |link_button_buy|

Was Sie Lernen Werden
---------------------

- Kostüm für das Sprite malen


Schaltung Aufbauen
-----------------------

Der Knopf ist ein 4-poliges Gerät, da Pin 1 mit Pin 2 verbunden ist und Pin 3 mit Pin 4, wenn der Knopf gedrückt wird, sind die 4 Pins verbunden, wodurch der Stromkreis geschlossen wird.

.. image:: img/5_buttonc.png

Bauen Sie die Schaltung gemäß dem folgenden Diagramm auf.

* Verbinden Sie einen der Pins auf der linken Seite des Knopfes mit Pin14, der mit einem Pull-Down-Widerstand und einem 0,1uF (104) Kondensator verbunden ist (um Schwankungen zu eliminieren und ein stabiles Level auszugeben, wenn der Knopf betätigt wird).
* Verbinden Sie das andere Ende des Widerstands und des Kondensators mit GND, und einen der Pins auf der rechten Seite des Knopfes mit 5V.

.. image:: img/circuit/6_doorbel_bb.png

Programmierung
------------------

**1. Ein Sprite und einen Hintergrund hinzufügen**

Lösche das Standard-Sprite, klicke auf den **Choose a Sprite**-Button in der unteren rechten Ecke des Sprite-Bereichs und wähle das **Balloon1**-Sprite aus.

.. image:: img/13_balloon1.png

Füge einen **Boardwalk**-Hintergrund über den Button **Choose a backdrop** hinzu oder andere Hintergründe, die dir gefallen.

.. image:: img/13_balloon2.png

**2. Ein Kostüm für das Ballon1-Sprite malen**

Jetzt malen wir ein explodierendes Effektkostüm für das Ballon-Sprite.

Gehe zur **Costumes**-Seite des **Balloon1**-Sprites, klicke auf den Button **Choose a Costume** in der unteren linken Ecke und wähle **Paint**, um ein leeres **Costume** zu erhalten.

.. image:: img/13_balloon7.png

Wähle eine Farbe und benutze dann das **Brush**-Werkzeug, um ein Muster zu zeichnen.

.. image:: img/13_balloon3.png

Wähle erneut eine Farbe, klicke auf das Füllwerkzeug und bewege die Maus innerhalb des Musters, um es mit einer Farbe zu füllen.

.. image:: img/13_balloon4.png

Schreibe abschließend den Text BOOM, damit ein Explosionseffektkostüm fertig ist.

.. image:: img/13_balloon5.png

**3. Skript für das Ballon-Sprite**

Setze die Anfangsposition und Größe des **Balloon1**-Sprites.

.. image:: img/13_balloon6.png

Lass dann das **Balloon**-Sprite langsam größer werden.

.. image:: img/13_balloon8.png

Wenn der Knopf gedrückt wird (Wert ist 1), hört das **Balloon1**-Sprite auf, größer zu werden.

* Wenn die Größe weniger als 90 beträgt, fällt es (y-Koordinate nimmt ab).
* Wenn die Größe größer als 90 und kleiner als 120 ist, fliegt es in den Himmel (y-Koordinate nimmt zu).

.. image:: img/13_balloon9.png

Wenn der Knopf nicht gedrückt wurde, wird der Ballon langsam größer und wenn die Größe größer als 120 ist, explodiert er (wechselt zum Explosionseffektkostüm).

.. image:: img/13_balloon10.png
