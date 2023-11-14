.. _cpn_ultrasonic:

Ultraschall-Modul
================================

.. image:: img/ultrasonic_pic.png
    :width: 400
    :align: center

* **TRIG**: Trigger-Impuls-Eingang
* **ECHO**: Echo-Impuls-Ausgang
* **GND**: Masse
* **VCC**: 5V Versorgung

Dies ist der HC-SR04-Ultraschall-Distanzsensor, der berührungslose Messungen von 2 cm bis 400 cm mit einer Messgenauigkeit von bis zu 3 mm ermöglicht. Auf dem Modul befinden sich ein Ultraschall-Sender, ein Empfänger und eine Steuerschaltung.

Sie müssen nur 4 Pins anschließen: VCC (Strom), Trig (Auslöser), Echo (Empfang) und GND (Masse), um es für Ihre Messprojekte einfach zu verwenden.

**Merkmale**

* Arbeitsspannung: DC5V
* Arbeitsstrom: 16mA
* Arbeitsfrequenz: 40Hz
* Maximale Reichweite: 500cm
* Min Reichweite: 2cm
* Trigger-Eingangssignal: 10uS TTL-Impuls
* Echo-Ausgangssignal: Eingang TTL Hebelsignal und die Reichweite im Verhältnis
* Anschluss: XH2.54-4P
* Abmessungen: 46x20,5x15 mm

**Prinzip**

Die Grundprinzipien sind wie folgt:

* Mit IO-Trigger für mindestens 10us High-Level-Signal.

* Das Modul sendet einen 8-Zyklen-Ultraschallburst mit 40 kHz und erkennt, ob ein Impulssignal empfangen wird.

* Das Echo gibt einen hohen Pegel aus, wenn ein Signal zurückkommt; die Dauer des hohen Pegels ist die Zeit von der Aussendung bis zur Rückkehr.

* Entfernung = (Hochpegelzeit x Schallgeschwindigkeit (340M/S)) / 2

.. image:: img/ultrasonic_prin.jpg

Formel:

* us / 58 = Abstand in Zentimetern
* us / 148 = Zoll-Abstand
* Entfernung = Hochgeschwindigkeitszeit x Geschwindigkeit (340M/S) / 2

.. note::

    Dieses Modul sollte nicht unter Strom angeschlossen werden, wenn nötig, lassen Sie die GND des Moduls zuerst angeschlossen werden. Andernfalls wird es die Arbeit des Moduls beeinträchtigen.

    Die Fläche des zu messenden Objekts sollte mindestens 0,5 Quadratmeter betragen und möglichst flach sein. Andernfalls wird das Ergebnis beeinträchtigt.



**Beispiel**

* :ref:`ar_ultrasonic` (Arduino-Projekt)
* :ref:`ar_reversing_aid` (Arduino-Projekt)
* :ref:`py_ultrasonic` (MicroPython-Projekt)
* :ref:`py_reversing_aid` (MicroPython-Projekt)
* :ref:`sh_parrot` (Scratch-Projekt)

