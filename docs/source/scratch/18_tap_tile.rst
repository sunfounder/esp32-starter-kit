.. _sh_tap_tile:

2.18 SPIEL - Nicht auf das weiße Kachel tippen
===================================================

Ich bin sicher, viele von euch haben dieses Spiel auf euren Handys gespielt. In diesem Spiel geht es darum, auf zufällig erscheinende schwarze Kacheln zu tippen, um Punkte zu sammeln. Das Spiel wird immer schneller, tippt man auf weiße Kacheln oder verpasst schwarze Kacheln, ist das Spiel vorbei.

Jetzt verwenden wir PictoBlox, um es nachzubilden.

Stecke zwei IR-Hindernisvermeidungsmodule vertikal auf das Breadboard, wenn deine Hand über einem der IR-Module platziert ist, erscheint ein blinkender Punkt auf der Bühne, was einem Tipp entspricht.

Wenn der Tipp auf die schwarze Kachel geht, wird der Punktestand um 1 erhöht, berührt man die weiße Kachel, wird der Punktestand um 1 verringert.

Du musst entscheiden, ob du deine Hand über dem IR-Modul links oder über dem IR-Modul rechts platzierst, abhängig von der Position der schwarzen Kachel auf der Bühne.

.. image:: img/21_tile.png

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
    *   - :ref:`cpn_avoid`
        - |link_avoid_buy|

Schaltung Aufbauen
-----------------------

Das Hindernisvermeidungsmodul ist ein infraroter Näherungssensor mit einstellbarer Entfernung, dessen Ausgang normalerweise hoch ist und bei Erkennung eines Hindernisses niedrig wird.

Bauen Sie die Schaltung gemäß dem folgenden Diagramm auf.

.. image:: img/circuit/19_tap_tile_bb.png

Programmierung
------------------

Hier benötigen wir 3 Sprites, **Tile**, **Left IR** und **Right IR**.

* **Tile**-Sprite: dient dazu, den Effekt abwechselnder schwarzer und weißer Kacheln nach unten zu erzielen. In der Handyspielversion dieses Spiels gibt es normalerweise 4 Spalten, hier machen wir nur zwei.
* **Left IR**-Sprite: dient dazu, den Klickeffekt zu erzielen. Wenn das linke IR-Modul deine Hand erkennt, sendet es eine Nachricht - **left** an das **Left IR**-Sprite, um es zu aktivieren. Wenn es die schwarze Kachel auf der Bühne berührt, wird der Punktestand um 1 erhöht, andernfalls wird er um 1 verringert.
* **Right IR**-Sprite: Die Funktion ist im Wesentlichen die gleiche wie bei **Left IR**, nur dass es die Nachricht **Right** empfängt.

**1. Ein Kachel-Sprite malen**.

Lösche das Standard-Sprite, fahre mit der Maus über das Symbol **Add Sprite**, wähle **Paint** und ein leeres Sprite erscheint, nenne es **Tile**.

.. image:: img/21_tile1.png

Gehe zur **Costumes**-Seite und verwende das **Rectangle**-Werkzeug, um ein Rechteck zu zeichnen.

.. image:: img/21_tile2.png

Wähle das Rechteck aus und klicke auf **Copy** -> **Paste**, um ein identisches Rechteck zu erstellen, und verschiebe dann die beiden Rechtecke in eine bündige Position.

.. image:: img/21_tile01.png


Wählen Sie eines der Rechtecke aus und färben Sie es schwarz.

.. image:: img/21_tile02.png

Wählen Sie nun beide Rechtecke aus und verschieben Sie sie so, dass ihre Mittelpunkte mit dem Zentrum der Leinwand übereinstimmen.

.. image:: img/21_tile0.png

Duplizieren Sie das Kostüm1, indem Sie die Füllfarben der beiden Rechtecke abwechseln. Zum Beispiel ist die Füllfarbe von Kostüm1 links weiß und rechts schwarz, während die Füllfarbe von Kostüm2 links schwarz und rechts weiß ist.

.. image:: img/21_tile3.png

**2. Programmieren des Fliesen-Sprites**

Gehen Sie zurück zur Seite **Blocks** und setzen Sie die Anfangsposition des **Tile**-Sprites so, dass es sich oben auf der Bühne befindet.

.. image:: img/21_tile4.png

Erstellen Sie eine Variable - **blocks** und geben Sie ihr einen Anfangswert, um die Anzahl der Erscheinungen des **Tile**-Sprites zu bestimmen. Verwenden Sie den Block [repeat until], damit die Variable **blocks** allmählich abnimmt, bis **blocks** 0 ist. Währenddessen soll das Sprite **Tile** zufällig sein Kostüm wechseln.

Nach dem Klicken auf die grüne Fahne sehen Sie, wie das **Tile**-Sprite auf der Bühne schnell die Kostüme wechselt.

.. image:: img/21_tile5.png

Erstellen Sie Klone des **Tile**-Sprites, während die Variable **blocks** abnimmt, und stoppen Sie das Skript, wenn Blöcke 0 ist. Zwei Blöcke [wait () seconds] werden hier verwendet, der erste begrenzt das Intervall zwischen den Klonen von **Tile's** und der zweite lässt die Variable Blöcke auf 0 sinken, ohne das Programm sofort zu stoppen, damit das letzte Fliesen-Sprite genug Zeit hat, sich zu bewegen.

.. image:: img/21_tile6.png

Programmieren Sie nun den Klon des **Tile**-Sprites so, dass es langsam nach unten bewegt wird und löschen Sie es, wenn es den Boden der Bühne erreicht. Die Änderung der y-Koordinate beeinflusst die Fallgeschwindigkeit, je größer der Wert, desto schneller die Fallgeschwindigkeit.

.. image:: img/21_tile7.png

Verstecken Sie das Original und zeigen Sie den Klon.

.. image:: img/21_tile8.png

**3. Auslesen der Werte der 2 IR-Module**

Lesen Sie im Hintergrund die Werte der 2 IR-Module aus und führen Sie die entsprechenden Aktionen durch.

* Wenn das linke IR-Hindernisvermeidungsmodul Ihre Hand erkennt, senden Sie eine Nachricht - **left**.
* Wenn das rechte IR-Vermeidungsmodul Ihre Hand erkennt, senden Sie eine Nachricht - **right**.

.. image:: img/21_tile9.png
    :width: 800

**4. Links-IR-Sprite**

Fahren Sie mit der Maus über das Symbol **Add sprite** und wählen Sie **Paint**, um ein neues Sprite namens **Left IR** zu erstellen.

.. image:: img/21_tile10.png

Gehen Sie zur Seite **Costumes** des **Left IR**-Sprites, wählen Sie eine Füllfarbe (irgendeine Farbe außer Schwarz und Weiß) und zeichnen Sie einen Kreis.

.. image:: img/21_tile11.png

Beginnen Sie nun mit dem Programmieren des **Left IR**-Sprites. Wenn die Nachricht - **left** empfangen wird (das IR-Empfängermodul links erkennt ein Hindernis), dann prüfen Sie, ob der schwarze Block des **Tile**-Sprites berührt wird, und wenn ja, lassen Sie die Variable **count** um 1 erhöhen, andernfalls um 1 verringern.

.. image:: img/21_tile12.png

.. note::

    Sie müssen das **Tile**-Sprite auf der Bühne erscheinen lassen und dann die Farbe des schwarzen Blocks im **Tile**-Sprite aufnehmen.

    .. image:: img/21_tile13.png

Nun realisieren Sie den Sensor-Effekt (Vergrößern und Verkleinern) für **Left IR**.

.. image:: img/21_tile14.png

Lassen Sie das **Left IR**-Sprite verschwinden, wenn auf die grüne Fahne geklickt wird, erscheinen, wenn die Nachricht - **left** empfangen wird, und schließlich wieder verschwinden.

.. image:: img/21_tile15.png

**5. Rechts-IR-Sprite**

Kopieren Sie das **Left IR**-Sprite und benennen Sie es in **Right IR** um.

.. image:: img/21_tile16.png

Ändern Sie dann die empfangene Nachricht in - **right**.

.. image:: img/21_tile17.png

Nun ist die gesamte Programmierung abgeschlossen und Sie können auf die grüne Fahne klicken, um das Skript auszuführen.
