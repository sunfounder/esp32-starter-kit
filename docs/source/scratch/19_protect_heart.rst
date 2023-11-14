.. _sh_protect_heart:

2.19 SPIEL - Schütze Dein Herz
=====================================

In diesem Projekt erstellen wir ein Spiel, das die Reaktionsgeschwindigkeit testet.

Auf der Bühne befindet sich ein Herz, geschützt in einem rechteckigen Kasten, und Pfeile fliegen von jeder Position der Bühne auf dieses Herz zu. Die Farbe der Pfeile wechselt zufällig zwischen Schwarz und Weiß, und die Pfeile fliegen immer schneller.

Wenn die Farbe des rechteckigen Kastens und die Pfeilfarbe gleich sind, wird der Pfeil außerhalb blockiert und das Level um 1 erhöht; sind die Farben nicht gleich, durchdringt der Pfeil das Herz und das Spiel ist beendet.

Hier wird die Farbe des Rechteckkastens durch das Linienverfolgungsmodul gesteuert. Wenn das Modul auf einer schwarzen Oberfläche (einer reflektierenden Oberfläche) platziert wird, ist die Farbe des Rechteckkastens schwarz, ansonsten weiß.

Sie müssen also entscheiden, ob Sie das Linienverfolgungsmodul auf eine weiße oder schwarze Oberfläche legen, je nach Pfeilfarbe.

.. image:: img/22_heart.png

Benötigte Komponenten
---------------------

Für dieses Projekt benötigen wir die folgenden Komponenten.

Es ist definitiv praktisch, ein ganzes Kit zu kaufen, hier ist der Link:

.. list-table::
    :widths: 20 20 20
    :header-rows: 1

    *   - Name
        - ARTIKEL IN DIESEM KIT
        - LINK
    *   - ESP32 Starter Kit
        - 320+
        - |link_esp32_starter_kit|

Sie können sie auch einzeln über die untenstehenden Links kaufen.

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
    *   - :ref:`cpn_line_track`
        - |link_line_track_buy|

Schaltung Aufbauen
----------------------------

Dies ist ein digitales Linienverfolgungsmodul, das bei Erkennung einer schwarzen Linie 1 ausgibt; bei einer weißen Linie gibt es einen Wert von 0 aus. Zusätzlich können Sie seine Erfassungsentfernung über das Potentiometer auf dem Modul einstellen.

Bauen Sie den Schaltkreis nun gemäß der untenstehenden Abbildung auf.

.. image:: img/circuit/20_protect_heart_bb.png

.. note::

    Bevor Sie mit dem Projekt beginnen, müssen Sie die Empfindlichkeit des Moduls einstellen.

    Verkabeln Sie gemäß der obigen Abbildung und schalten Sie dann das R3-Board ein (entweder direkt in das USB-Kabel oder das 9V-Batterieknopfkabel), ohne den Code hochzuladen.

    Kleben Sie nun ein schwarzes Isolierband auf den Schreibtisch, platzieren Sie das Linienverfolgungsmodul in einer Höhe von 2 cm über dem Schreibtisch.

    Beobachten Sie mit dem Sensor nach unten gerichtet die Signalleuchte auf dem Modul, um sicherzustellen, dass sie auf dem weißen Tisch aufleuchtet und auf dem schwarzen Band erlischt.

    Wenn nicht, müssen Sie das Potentiometer auf dem Modul so einstellen, dass es den obigen Effekt erzielen kann.



Programmierung
------------------

Hier müssen wir 3 Sprites erstellen: **Heart**, **Square Box** und **Arrow1**.

* **Heart**: bleibt in der Mitte der Bühne stehen, wenn es vom **Arrow1**-Sprite berührt wird, ist das Spiel vorbei.
* **Square Box**: Es gibt zwei Arten von Kostümen, schwarz und weiß, und sie wechselt die Kostüme entsprechend dem Wert des Linienverfolgungsmoduls.
* **Arrow**: fliegt von jeder Position in Schwarz/Weiß zur Mitte der Bühne; stimmt seine Farbe mit der Farbe des **Square Box**-Sprites überein, wird er blockiert und fliegt erneut von einer zufälligen Position zur Mitte der Bühne; stimmt seine Farbe nicht mit der des **Square Box**-Sprites überein, durchquert er das **Heart**-Sprite und das Spiel ist vorbei.

**1. Quadratische Box-Sprite hinzufügen**

Da das Arrow1- und Quadratische Box-Sprite beide weiße Kostüme haben, um sie auf der Bühne darzustellen, füllen Sie jetzt den Hintergrund mit einer Farbe, die jede Farbe außer Schwarz, Weiß und Rot sein kann.

* Klicken Sie auf **Backdrop1**, um zur Seite **Backdrops** zu gelangen.
* Wählen Sie die Farbe aus, mit der Sie füllen möchten.
* Verwenden Sie das **Rectangle**-Werkzeug, um ein Rechteck in der gleichen Größe wie die Zeichenfläche zu zeichnen.

.. image:: img/22_heart0.png

Löschen Sie das Standard-Sprite, verwenden Sie den Button **Choose a Sprite**, um das **Square Box**-Sprite hinzuzufügen, und setzen Sie seine x- und y-Koordinaten auf (0, 0).

.. image:: img/22_heart1.png

Gehen Sie zur Seite **Costumes** des **Square Box**-Sprites und stellen Sie die schwarz-weißen Kostüme ein.

* Klicken Sie das Auswahlwerkzeug
* Wählen Sie das Rechteck auf der Leinwand
* Wählen Sie die Füllfarbe Schwarz
* und benennen Sie das Kostüm **Black**

.. image:: img/22_heart2.png

Wählen Sie das zweite Kostüm, stellen Sie die Füllfarbe auf Weiß, benennen Sie es Weiß und löschen Sie die restlichen Kostüme.

.. image:: img/22_heart3.png

**2. Herz-Sprite hinzufügen**

Fügen Sie auch ein **Heart**-Sprite hinzu, setzen Sie seine Position auf (0, 0) und verkleinern Sie seine Größe, sodass es innerhalb der Quadratischen Box zu liegen scheint.

.. image:: img/22_heart5.png

Auf der Seite **Costumes** passen Sie das lila Herz-Kostüm so an, dass es gebrochen erscheint.

.. image:: img/22_heart6.png

**3. Pfeil1-Sprite hinzufügen**

Fügen Sie ein **Arrow1**-Sprite hinzu.

.. image:: img/22_heart7.png

Auf der Seite **Costumes** behalten und kopieren Sie das nach rechts gerichtete Kostüm und stellen Sie seine Farbe auf Schwarz und Weiß ein.

.. image:: img/22_heart8.png



**4. Programmierung für das Quadratische Box-Sprite**

Gehen Sie zurück zur Seite **Blocks** und programmieren Sie das **Square Box**-Sprite.

* Wenn der Wert des digitalen Pins 2 (Linienfolgemodul) 1 ist (schwarze Linie erkannt), dann wechseln Sie das Kostüm zu **Black**.
* Andernfalls wechseln Sie das Kostüm zu **White**.

.. image:: img/22_heart4.png


**5. Programmierung für das Herz-Sprite**

Das **Heart**-Sprite ist im **Square Box** geschützt und hat standardmäßig ein rotes Kostüm. Wenn das Pfeil1-Sprite es berührt, endet das Spiel.

.. image:: img/22_heart9.png

**6. Programmierung für das Pfeil1-Sprite**

Lassen Sie das **Arrow1**-Sprite verschwinden und erstellen Sie einen Klon, wenn auf die grüne Fahne geklickt wird.

.. image:: img/22_heart10.png

Erstellen Sie einen [init]-Block, um die Position, Ausrichtung und Farbe des **Arrow1**-Sprites zu initialisieren.

Es erscheint an einer zufälligen Position, und wenn der Abstand zwischen ihm und dem **Heart**-Sprite weniger als 200 beträgt, bewegt es sich nach außen, bis der Abstand größer als 200 ist.

.. image:: img/22_heart11.png

Richten Sie es in Richtung des **Heart**-Sprites aus.

.. image:: img/22_heart12.png

Lassen Sie seine Farbe zufällig zwischen Schwarz/Weiß wechseln.

* Ist die Variable Farbe 0, wechseln Sie das Kostüm zu **White**.
* Ist die Variable Farbe 1, wechseln Sie das Kostüm zu **Black**.

.. image:: img/22_heart14.png

Lassen Sie es jetzt starten sich zu bewegen, es wird schneller, je höher der Wert der Variablen **level** steigt.

.. image:: img/22_heart13.png

Stellen Sie nun seinen Kollisionseffekt mit dem **Square Box**-Sprite ein.

* Wenn das **Arrow1**-Sprite und das **Square Box**-Sprite dieselbe Farbe haben (die gemäß dem Wert des Linienverfolgungsmoduls geändert wird), entweder schwarz oder weiß, wird ein neuer Klon erstellt und das Spiel geht weiter.
* Stimmen ihre Farben nicht überein, bewegt sich das **Arrow1**-Sprite weiter und das Spiel endet, wenn es das **Heart**-Sprite berührt.

.. image:: img/22_heart15.png

.. note::
    Die beiden [touch color()]-Blöcke müssen die schwarz/weißen Kostüme der Quadratischen Box separat aufnehmen.

    .. image:: img/22_heart16.png

