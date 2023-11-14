.. _cpn_led:

LED
==========

**Was ist eine LED?**

.. image:: img/led_pin.jpg
    :width: 200

.. image:: img/led_polarity.jpg
    :width: 400

LEDs sind sehr verbreitete elektronische Bauteile, die häufig zur Dekoration Ihrer Räume während Festivals verwendet werden. Sie können sie auch als Anzeiger für verschiedene Zustände nutzen, zum Beispiel, um zu überprüfen, ob Ihre Haushaltsgeräte eingeschaltet sind oder nicht. LEDs gibt es in vielen verschiedenen Formen und Größen, am verbreitetsten sind Durchsteck-LEDs mit langen Anschlussdrähten, die sich einfach in ein Steckbrett einstecken lassen.

Die vollständige Bezeichnung für LED ist "lichtemittierende Diode", was bedeutet, dass sie die Eigenschaften einer Diode hat, bei der der Strom in einer Richtung fließt, vom Anoden- (positiv) zum Kathodenanschluss (negativ).

Hier sind die elektrischen Symbole für LEDs.

.. image:: img/led_symbol.png


**Verschiedene Größen und Farben**

.. image:: img/led_color.png

Die gängigsten LED-Farben sind Rot, Gelb, Blau, Grün und Weiß, wobei das emittierte Licht meistens die gleiche Farbe wie das äußere Erscheinungsbild hat.

Seltener verwenden wir LEDs, die transparent oder matt erscheinen, aber das emittierte Licht kann eine andere Farbe als Weiß haben.

LEDs gibt es in vier Größen: 3mm, 5mm, 8mm und 10mm, wobei 5mm die gängigste Größe ist.

.. image:: img/led_type.jpg

Nachfolgend finden Sie die Größe einer 5mm LED in mm.

.. image:: img/led_size.png



**Durchlassspannung**

Die Durchlassspannung ist ein sehr wichtiger Parameter beim Einsatz von LEDs, da sie bestimmt, wie viel Leistung Sie verwenden und wie groß der vorzuschaltende Strombegrenzungswiderstand sein sollte.

Die Durchlassspannung ist die Spannung, die benötigt wird, damit die LED aufleuchtet. Für die meisten roten, gelben, orangen und hellgrünen LEDs liegt diese Spannung üblicherweise zwischen 1,9V und 2,1V.


.. image:: img/led_voltage.jpg
    :width: 400
    :align: center


Nach dem Ohmschen Gesetz nimmt der Strom in diesem Stromkreis ab, wenn der Widerstand erhöht wird, was dazu führt, dass die LED dunkler leuchtet.

    I = (Vp-Vl)/R

Um die LEDs sicher und mit der richtigen Helligkeit zum Leuchten zu bringen, welchen Widerstand sollten wir im Stromkreis verwenden?

Für 99% der 5mm LEDs liegt der empfohlene Strom bei 20mA, wie Sie der Spalte "Bedingungen" im Datenblatt entnehmen können.

.. image:: img/led_datasheet.png

Nun wandeln Sie die obige Formel wie folgt um.

    R = (Vp-Vl)/I


Wenn ``Vp`` 5V, ``Vl`` (Durchlassspannung) 2V und ``I`` 20mA beträgt, dann ist ``R`` 150Ω.

Wir können die LED heller machen, indem wir den Widerstand des Widerstands verringern, aber es wird nicht empfohlen, unter 150Ω zu gehen (dieser Widerstandswert ist möglicherweise nicht sehr genau, da verschiedene Anbieter unterschiedliche LEDs liefern).

Nachfolgend finden Sie die Durchlassspannungen und Wellenlängen verschiedener farbiger LEDs, die Sie als Referenz verwenden können.

.. list-table::
   :widths: 25 25 50
   :header-rows: 1

   * - LED-Farbe
     - Durchlassspannung
     - Wellenlänge
   * - Rot
     - 1,8V ~ 2,1V
     - 620 ~ 625
   * - Gelb
     - 1,9V ~ 2,2V
     - 580 ~ 590
   * - Grün
     - 1,9V ~ 2,2V
     - 520 ~ 530
   * - Blau
     - 3,0V ~ 3,2V
     - 460 ~ 465
   * - Weiß
     - 3,0V ~ 3,2V
     - 8000 ~ 9000

**Beispiel**

* :ref:`ar_blink` (Arduino-Projekt)
* :ref:`ar_fading` (Arduino-Projekt)
* :ref:`py_blink` (MicroPython-Projekt)
* :ref:`py_fading` (MicroPython-Projekt)
* :ref:`sh_table_lamp` (Scratch-Projekt)
* :ref:`sh_breathing_led` (Scratch-Projekt)
