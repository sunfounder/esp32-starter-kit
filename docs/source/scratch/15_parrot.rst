.. _sh_parrot:

2.15 SPIEL - Flappy Papagei
==============================

Hier verwenden wir das Ultraschallmodul, um ein Flappy-Papagei-Spiel zu spielen.

Nachdem das Skript läuft, bewegt sich der grüne Bambus langsam von rechts nach links auf einer zufälligen Höhe. Platziere jetzt deine Hand über dem Ultraschallmodul, wenn der Abstand zwischen deiner Hand und dem Ultraschallmodul weniger als 10 beträgt, fliegt der Papagei nach oben, sonst fällt er nach unten.
Du musst den Abstand zwischen deiner Hand und dem Ultraschallmodul kontrollieren, damit der Papagei den grünen Bambus (Schläger) meiden kann, wenn er ihn berührt, ist das Spiel vorbei.

.. image:: img/15_parrot.png

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
    *   - :ref:`cpn_wires`
        - |link_wires_buy|
    *   - :ref:`cpn_ultrasonic`
        - |link_ultrasonic_buy|

Schaltung Aufbauen
-----------------------

Ein Ultraschallsensormodul ist ein Instrument, das die Entfernung zu einem Objekt mit Ultraschallwellen misst.
Es hat zwei Sonden. Eine sendet Ultraschallwellen und die andere empfängt die Wellen und verwandelt die Zeit des Sendens und Empfangens in eine Entfernung, um so die Entfernung zwischen dem Gerät und einem Hindernis zu messen.

Bauen Sie die Schaltung gemäß dem folgenden Diagramm auf.

.. image:: img/circuit/16_flappy_parrot_bb.png

Programmierung
------------------

Das zu erreichende Ziel ist es, das Ultraschallmodul zu verwenden, um die Flughöhe des Sprites **Parrot** zu steuern, während es das Sprite **Paddle** vermeidet.


**1. Ein Sprite hinzufügen**

Lösche das Standard-Sprite und füge über den Button **Choose a Sprite** das **Parrot**-Sprite hinzu. Setze seine Größe auf 50% und verschiebe seine Position in die linke Mitte.

.. image:: img/15_sprite.png

Füge nun das **Paddle**-Sprite hinzu, setze seine Größe auf 150%, stelle seinen Winkel auf 180 ein und verschiebe seine anfängliche Position in die obere rechte Ecke.

.. image:: img/15_sprite1.png

Gehe zur **Costumes**-Seite des **Paddle**-Sprites und entferne die Umrandung.

.. image:: img/15_sprite2.png

**2. Skript für das Papagei-Sprite**

Programmiere jetzt das **Parrot**-Sprite, das im Flug ist und dessen Flughöhe durch den Erfassungsabstand des Ultraschallmoduls bestimmt wird.


* Wenn die grüne Flagge angeklickt wird, wechsle das Kostüm alle 0,2 Sekunden, damit es immer im Flug ist.

.. image:: img/15_parr1.png

* Lies den Wert des Ultraschallmoduls und speichere ihn nach dem Runden mit dem [round]-Block in der Variable **distance**.


.. image:: img/15_parr2.png

* Wenn die Ultraschall-Erfassungsdistanz weniger als 10 cm beträgt, erhöhe die y-Koordinate um 50, das **Parrot**-Sprite fliegt nach oben. Andernfalls wird der y-Koordinatenwert um 40 verringert, **Parrot** fällt nach unten.

.. image:: img/15_parr3.png

* Wenn das **Parrot**-Sprite das **Paddle**-Sprite berührt, endet das Spiel und das Skript stoppt.

.. image:: img/15_parr4.png


**3. Skript für das Schläger-Sprite**

Schreibe jetzt das Skript für das **Paddle**-Sprite, das zufällig auf der Bühne erscheinen muss.

* Verstecke das Sprite **Paddle**, wenn die grüne Flagge angeklickt wird, und klone es gleichzeitig. Der [`create clone of <https://en.scratch-wiki.info/wiki/Create_Clone_of_()_(block)>`_]-Block ist ein Steuerungsblock und ein Stapelblock. Er erstellt einen Klon des Sprites im Argument. Es kann auch das Sprite klonen, in dem es läuft, wodurch Klone von Klonen rekursiv erstellt werden.

.. image:: img/15_padd.png

* Wenn **Paddle** als Klon präsentiert wird, ist seine Position 220 (rechts) für die x-Koordinate und seine y-Koordinate zufällig zwischen (-125 bis 125) (Höhe zufällig).

.. image:: img/15_padd1.png

* Verwende den [repeat]-Block, um den x-Koordinatenwert langsam zu verringern, sodass du sehen kannst, wie der Klon des **Paddle**-Sprites langsam von rechts nach links bewegt wird, bis es verschwindet.

.. image:: img/15_padd2.png

* Klone erneut ein neues **Paddle**-Sprite und lösche den vorherigen Klon.

.. image:: img/15_padd3.png
