.. _sh_fishing:

2.17 SPIEL - Angeln
===========================

Hier spielen wir ein Angelspiel mit einem Knopf.

Wenn das Skript läuft, schwimmen die Fische links und rechts auf der Bühne, und du musst den Knopf drücken, wenn der Fisch fast nahe am Haken ist (es wird empfohlen, ihn länger zu drücken), um den Fisch zu fangen, und die Anzahl der gefangenen Fische wird automatisch aufgezeichnet.

.. image:: img/18_fish.png

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

Wir müssen zuerst einen **Underwater**-Hintergrund auswählen, dann ein **Fish**-Sprite hinzufügen und es auf der Bühne hin und her schwimmen lassen. Dann zeichne ein **Fishhook**-Sprite und steuere es mit einem Knopf, um mit dem Angeln zu beginnen. Wenn das **Fish**-Sprite im gehakten Zustand (wird rot) den **Fishhook**-Sprite berührt, wird es gehakt.

**1. Hintergrund hinzufügen**

Verwende den Button **Choose a Backdrop**, um einen **Underwater**-Hintergrund hinzuzufügen.

.. image:: img/18_under.png


**2. Angelhaken-Sprite**

Das **Fishhook**-Sprite bleibt normalerweise unter Wasser im gelben Zustand; wenn der Knopf gedrückt wird, befindet es sich im Angelzustand (rot) und bewegt sich über der Bühne.

Da es kein **Fishhook**-Sprite in Pictoblox gibt, können wir das **Glow-J**-Sprite so modifizieren, dass es wie ein Angelhaken aussieht.

* Füge das **Glow-J**-Sprite über **Choose a Sprite** hinzu.

.. image:: img/18_hook.png

* Gehe nun zur **Costumes**-Seite des **Glow-J**-Sprites, wähle Cyans Füllung auf dem Bildschirm aus und entferne sie. Ändere dann die J-Farbe in Rot und verringere auch seine Breite. Der wichtigste Punkt ist, dass du den oberen Teil genau am Mittelpunkt haben musst.

.. image:: img/18_hook1.png

* Verwende das **Line tool**, um eine Linie so lang wie möglich vom Mittelpunkt nach oben zu zeichnen (Linie außerhalb der Bühne). Jetzt, wo das Sprite gezeichnet ist, setze den Sprite-Namen auf **Fishhook** und verschiebe es an die richtige Position.

.. image:: img/18_hook2.png

* Wenn die grüne Flagge angeklickt wird, setze den Farbeffekt des Sprites auf 30 (Gelb) und setze seine Anfangsposition.

.. image:: img/18_hook3.png


* Wenn der Knopf gedrückt wird, setze den Farbeffekt auf 0 (Rot, Angelzustand beginnen), warte 0,1 und bewege dann das **Fishhook**-Sprite an die Oberseite der Bühne. Lasse den Knopf los und lass den **Fishhook** an seine Anfangsposition zurückkehren.

.. image:: img/18_hook4.png

**3. Fisch-Sprite**

Das zu erreichende Ziel des **Fish**-Sprites ist es, sich links und rechts auf der Bühne zu bewegen, und wenn es auf ein **Fishhook**-Sprite im Angelzustand trifft, schrumpft es, bewegt sich an eine bestimmte Position und verschwindet dann, woraufhin ein neuer **fish**-Sprite geklont wird.

* Füge jetzt das **fish**-Sprite hinzu und passe seine Größe und Position an.

.. image:: img/18_fish1.png

* Erstelle eine Variable **score**, um die Anzahl der gefangenen Fische zu speichern, verstecke dieses Sprite und klone es.

.. image:: img/18_fish2.png


* Zeige den Klon des **fish**-Sprites, wechsle sein Kostüm und setze schließlich die Anfangsposition.


.. image:: img/18_fish3.png


* Lasse den Klon des **fish**-Sprites sich links und rechts bewegen und pralle zurück, wenn es den Rand berührt.


.. image:: img/18_fish4.png


* Das **fish**-Sprite (des Klons) reagiert nicht, wenn es am **Fishhook**-Sprite vorbeikommt; wenn es das **Fishhook**-Sprite im Angelzustand (wird rot) berührt, wird es gefangen, wobei die Punktzahl (Variable Punktzahl) +1 erhöht wird, und es zeigt auch eine Punktzahlanimation (schrumpft um 40%, bewegt sich schnell an die Position der Punkteanzeige und verschwindet). Gleichzeitig wird ein neuer Fisch erstellt (ein neuer Klon des Fisch-Sprites) und das Spiel geht weiter.

.. note::
    
    Du musst auf den Farbbereich im [Touch color]-Block klicken und dann das Pipettenwerkzeug verwenden, um die rote Farbe des **Fishhook**-Sprites auf der Bühne aufzunehmen. Wenn du willkürlich eine Farbe wählst, funktioniert dieser [Touch color]-Block nicht.

.. image:: img/18_fish5.png

