.. _sh_moving_mouse:

2.4 Bewegliche Maus
===================

Heute werden wir ein von einem Potentiometer gesteuertes Mausspielzeug bauen.

Wenn die grüne Flagge angeklickt wird, bewegt sich die Maus auf der Bühne vorwärts, und wenn Sie das Potentiometer drehen, ändert die Maus die Bewegungsrichtung.

.. image:: img/6_mouse.png

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
    *   - :ref:`cpn_pot`
        - |link_potentiometer_buy|

Was Sie Lernen Werden
---------------------

- Potentiometerprinzip
- Analogen Pin lesen und Bereich verstehen
- Einen Bereich in einen anderen abbilden
- Bewegung und Richtungsänderung des Sprites


Schaltung Aufbauen
-----------------------

Das Potentiometer ist ein Widerstandselement mit 3 Anschlüssen, wobei die beiden seitlichen Pins mit 5V und GND verbunden sind und der mittlere Pin mit Pin35. Nach der Umwandlung durch den ADC-Wandler des ESP32 liegt der Wertebereich bei 0-4095.

.. image:: img/circuit/5_moving_mouse_bb.png

Programmierung
------------------

**1. Wähle ein Sprite aus**

Lösche das Standard-Sprite, klicke auf den **Choose a Sprite**-Button in der unteren rechten Ecke des Sprite-Bereichs, gib **mouse** in das Suchfeld ein und klicke dann darauf, um es hinzuzufügen.

.. image:: img/6_sprite.png

**2. Eine Variable erstellen**

Erstelle eine Variable namens **value** um den gelesenen Wert des Potentiometers zu speichern.

Sobald erstellt, erscheint **value** im **Variables**-Palette und im angekreuzten Zustand, was bedeutet, dass diese Variable auf der Bühne erscheint.

.. image:: img/6_value.png

**3. Den Wert von Pin35 lesen**

Speichere den gelesenen Wert von Pin35 in die Variable **value**.

* [set my variable to 0]: Setze den Wert der Variable.
* [read analog pin ()]: Lies den Wert von Pins im Bereich von 0-4095.

.. image:: img/6_read_a0.png

Um durchgehend lesen zu können, musst du den [forever]-Block verwenden. Klicke auf dieses Skript, um es auszuführen, drehe das Potentiometer in beide Richtungen und du wirst sehen, dass der Wertebereich 0-1023 ist.

.. image:: img/6_1023.png

**4. Bewege das Sprite**

Verwende den [move steps]-Block, um das Sprite zu bewegen. Führe das Skript aus und du wirst sehen, dass sich das Sprite von der Mitte nach rechts bewegt.

.. image:: img/6_move.png

**5. Die Bewegungsrichtung des Sprites ändern**

Ändere jetzt die Bewegungsrichtung des Sprites durch den Wert von Pin35. Da der Wert von Pin35 von 0-4095 reicht, aber die Rotationsrichtung des Sprites -180~180 ist, muss ein [map]-Block verwendet werden.

Füge auch [when green flag clicked] am Anfang hinzu, um das Skript zu starten.

* [`point in direction <https://en.scratch-wiki.info/wiki/Point_in_Direction_()_(block)>`_]: Setze den Lenkwinkel des Sprites, aus dem **Motion**-Palette.
* [map from to]: Abbilde einen Bereich auf einen anderen Bereich.

.. image:: img/6_direction.png
