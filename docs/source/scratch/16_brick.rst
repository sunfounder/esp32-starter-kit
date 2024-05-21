.. note::

    Hallo und willkommen in der SunFounder Raspberry Pi & Arduino & ESP32 Enthusiasten-Gemeinschaft auf Facebook! Tauchen Sie tiefer ein in die Welt von Raspberry Pi, Arduino und ESP32 mit anderen Enthusiasten.

    **Warum beitreten?**

    - **Expertenunterstützung**: Lösen Sie Nachverkaufsprobleme und technische Herausforderungen mit Hilfe unserer Gemeinschaft und unseres Teams.
    - **Lernen & Teilen**: Tauschen Sie Tipps und Anleitungen aus, um Ihre Fähigkeiten zu verbessern.
    - **Exklusive Vorschauen**: Erhalten Sie frühzeitigen Zugang zu neuen Produktankündigungen und exklusiven Einblicken.
    - **Spezialrabatte**: Genießen Sie exklusive Rabatte auf unsere neuesten Produkte.
    - **Festliche Aktionen und Gewinnspiele**: Nehmen Sie an Gewinnspielen und Feiertagsaktionen teil.

    👉 Sind Sie bereit, mit uns zu erkunden und zu erschaffen? Klicken Sie auf [|link_sf_facebook|] und treten Sie heute bei!

.. _sh_breakout_clone:

2.16 SPIEL - Breakout-Klon
============================

Hier verwenden wir den Potentiometer, um ein Breakout-Klon-Spiel zu spielen.

Nachdem du auf die grüne Flagge geklickt hast, musst du den Potentiometer verwenden, um das Schläger-Sprite auf der Bühne zu steuern, um den Ball zu fangen, damit er nach oben gehen und die Ziegel treffen kann. Wenn alle Ziegel verschwinden, ist das Spiel gewonnen, wenn du den Ball nicht fängst, ist das Spiel verloren.

.. image:: img/17_brick.png

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

Schaltung Aufbauen
-----------------------

Der Potentiometer ist ein resistives Element mit 3 Anschlüssen, die beiden seitlichen Pins sind mit 5V und GND verbunden und der mittlere Pin mit Pin35. Nach der Umwandlung durch den ADC-Konverter des ESP32-Boards liegt der Wertebereich bei 0-4095.

.. image:: img/circuit/5_moving_mouse_bb.png

Programmierung
------------------

Es gibt 3 Sprites auf der Bühne.

**1. Schläger-Sprite**

Das Ziel des **Paddle** ist es, die anfängliche Position in der Mitte unten auf der Bühne zu haben und es wird durch einen Potentiometer gesteuert, um es nach links oder rechts zu bewegen.

* Lösche das Standard-Sprite, verwende den Button **Choose a Sprite**, um das **Paddle**-Sprite hinzuzufügen, und setze seine x- und y-Koordinaten auf (0, -140).

    .. image:: img/17_padd1.png

* Gehe zur **Costumes**-Seite, entferne die Umrandung und ändere seine Farbe in Dunkelgrau.

    .. image:: img/17_padd3.png


* Programmiere jetzt das **Paddle**-Sprite, um seine anfängliche Position auf (0, -140) zu setzen, wenn die grüne Flagge angeklickt wird, und lies den Wert von Pin35 (Potentiometer) in die Variable **a0** ein. Da das **Paddle**-Sprite auf der Bühne von links nach rechts bei x-Koordinaten -195~195 bewegt, musst du den [map]-Block verwenden, um den Variablenbereich **a0** von 0~4095 auf -195~195 abzubilden. 

    .. image:: img/17_padd2.png

* Jetzt kannst du den Potentiometer drehen, um zu sehen, ob das **Paddle**-Sprite links und rechts auf der Bühne bewegt werden kann.

**2. Ball-Sprite**

Das Ball-Sprite bewegt sich auf der Bühne, prallt ab, wenn es den Rand berührt; es prallt nach unten ab, wenn es den Block über der Bühne berührt; es prallt nach oben ab, wenn es während des Fallens das Schläger-Sprite berührt; wenn nicht, stoppt das Skript und das Spiel endet.


* Füge das **Ball**-Sprite hinzu.

    .. image:: img/17_ball1.png

* Wenn die grüne Flagge angeklickt wird, setze den Winkel des **Ball**-Sprites auf 45° und die Anfangsposition auf (0, -120).

    .. image:: img/17_ball2.png

* Lass nun das **Ball**-Sprite sich auf der Bühne bewegen und abprallen, wenn es den Rand berührt, und klicke auf die grüne Flagge, um den Effekt zu sehen.

    .. image:: img/17_ball3.png

* Wenn das **Ball**-Sprite das **Paddle**-Sprite berührt, mache eine Reflexion. Der einfache Weg, dies zu tun, ist, den Winkel direkt umzukehren, aber dann wirst du feststellen, dass der Weg des Balls völlig festgelegt ist, was zu langweilig ist. Daher verwenden wir das Zentrum der beiden Sprites, um zu berechnen und den Ball in die entgegengesetzte Richtung des Zentrums des Schlägers abprallen zu lassen.

    .. image:: img/17_ball4.png

    .. image:: img/17_ball6.png

* Wenn das **Ball**-Sprite an den Rand der Bühne fällt, stoppt das Skript und das Spiel endet.

    .. image:: img/17_ball5.png


**3. Block1-Sprite**

Das **Block1**-Sprite soll mit dem Effekt des Klonens 4x8 von sich selbst in einer zufälligen Farbe über der Bühne erscheinen und einen Klon löschen, wenn es vom **Ball**-Sprite berührt wird.

Das **Block1**-Sprite ist nicht in der **PictoBlox**-Bibliothek verfügbar, du musst es selbst zeichnen oder ein vorhandenes Sprite modifizieren. Hier werden wir es mit dem **Button3**-Sprite modifizieren.

* Nachdem du das **Button3**-Sprite hinzugefügt hast, gehe zur **Costumes**-Seite. Lösche jetzt zuerst **button-a**, reduziere dann sowohl die Breite als auch die Höhe von **button-b** und ändere den Sprite-Namen in **Block1**, wie im folgenden Bild gezeigt.

    .. note::

        * Für die Breite von **Block1** kannst du es wahrscheinlich auf dem Bildschirm simulieren, um zu sehen, ob du 8 in einer Reihe unterbringen kannst, wenn nicht, dann reduziere die Breite entsprechend.
        * Beim Verkleinern des **Block1**-Sprites musst du den Mittelpunkt in der Mitte des Sprites behalten.

    .. image:: img/17_bri2.png

* Erstelle jetzt zuerst 2 Variablen, **block**, um die Anzahl der Blöcke und **roll** zu speichern, um die Anzahl der Reihen zu speichern.

    .. image:: img/17_bri3.png

* Wir müssen einen Klon des **Block1**-Sprites erstellen, sodass es sich von links nach rechts, von oben nach unten, eins nach dem anderen, insgesamt 4x8, mit zufälligen Farben anzeigt.

    .. image:: img/17_bri4.png

* Nachdem das Skript geschrieben ist, klicke auf die grüne Flagge und schaue dir die Anzeige auf der Bühne an, wenn es zu kompakt oder zu klein ist, kannst du die Größe ändern.

    .. image:: img/17_bri5.png

* Schreibe jetzt das Auslöseereignis. Wenn der geklonte **Block1**-Sprite das **Ball**-Sprite berührt, lösche den Klon und sende die Nachricht **crush**.

    .. image:: img/17_bri6.png

* Zurück zum **Ball**-Sprite, wenn die Sendung **crush** empfangen wird (das **Ball**-Sprite berührt den Klon des **Block1**-Sprites), wird der **Ball** aus der entgegengesetzten Richtung abgeprallt.

    .. image:: img/17_ball7.png
