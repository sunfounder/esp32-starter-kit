.. _cpn_lcd:

I2C LCD1602
==============

.. image:: img/i2c_lcd1602.png
    :width: 800

* **GND**: Masse
* **VCC**: Spannungsversorgung, 5V.
* **SDA**: Serielle Datenleitung. Mit einem Pullup-Widerstand an VCC anschließen.
* **SCL**: Serielle Taktleitung. Mit einem Pullup-Widerstand an VCC anschließen.

Wie allgemein bekannt, bereichern LCDs und andere Anzeigen zwar die Mensch-Maschine-Interaktion, teilen aber eine gemeinsame Schwäche. Wenn sie an einen Controller angeschlossen werden, belegen sie mehrere IOs des Controllers, der nicht so viele externe Ports hat. Dies beschränkt auch andere Funktionen des Controllers.

Deshalb wurde das LCD1602 mit einem I2C-Modul entwickelt, um dieses Problem zu lösen. Das I2C-Modul hat einen eingebauten PCF8574 I2C-Chip, der die I2C-Serien-Daten in parallele Daten für das LCD-Display umwandelt.

* `PCF8574 Datenblatt <https://www.ti.com/lit/ds/symlink/pcf8574.pdf?ts=1627006546204&ref_url=https%253A%252F%252Fwww.google.com%252F>`_

**I2C-Adresse**

Die Standardadresse ist grundsätzlich 0x27, in einigen Fällen kann sie 0x3F sein.

Am Beispiel der Standardadresse 0x27 kann die Geräteadresse geändert werden, indem die A0/A1/A2-Pads kurzgeschlossen werden; im Standardzustand ist A0/A1/A2 1, und wenn das Pad kurzgeschlossen wird, ist A0/A1/A2 0.

.. image:: img/i2c_address.jpg
    :width: 600

**Hintergrundbeleuchtung/Kontrast**

Die Hintergrundbeleuchtung kann durch einen Jumper aktiviert werden, entfernen Sie den Jumper, um die Hintergrundbeleuchtung zu deaktivieren. Das blaue Potentiometer auf der Rückseite dient zur Einstellung des Kontrasts (das Verhältnis der Helligkeit zwischen dem hellsten Weiß und dem dunkelsten Schwarz).


.. image:: img/back_lcd1602.jpg

* **Kurzschlusskappe**: Die Hintergrundbeleuchtung kann mit dieser Kappe aktiviert werden, entfernen Sie diese Kappe, um die Hintergrundbeleuchtung zu deaktivieren.
* **Potentiometer**: Es wird verwendet, um den Kontrast (die Klarheit des angezeigten Textes) einzustellen, der im Uhrzeigersinn erhöht und im Gegenuhrzeigersinn verringert wird.


**Beispiele**

* :ref:`ar_lcd1602` (Arduino-Projekt)
* :ref:`ar_guess_number` (Arduino-Projekt)
* :ref:`py_lcd1602` (MicroPython-Projekt)
* :ref:`py_guess_number` (MicroPython-Projekt)

