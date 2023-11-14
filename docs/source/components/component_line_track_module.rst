.. _cpn_line_track:

Linienverfolgungsmodul
================================

.. image:: img/line_track.png
    :width: 400
    :align: center

* S: Normalerweise auf niedrigem Pegel, hoher Pegel bei Erkennung einer schwarzen Linie.
* V+: Stromversorgung, 3.3V~5V
* G: Masse

Dies ist ein 1-Kanal-Linienverfolgungsmodul, das, wie der Name schon sagt, schwarze Linien auf weißem Hintergrund oder weiße Linien auf schwarzem Hintergrund verfolgt.

.. image:: img/tcrt5000.jpg
    :width: 200
    :align: center

Das Modul verwendet einen TCRT500 Infrarotsensor, der aus einer Infrarot-LED (blau) und einem fotosensitiven Triplett (schwarz) besteht.

* Die blaue Infrarot-LED sendet beim Einschalten für das menschliche Auge unsichtbares Infrarotlicht aus.
* Der schwarze Phototransistor, der zum Empfangen von Infrarotlicht verwendet wird, hat einen internen Widerstand, dessen Widerstand sich mit dem empfangenen Infrarotlicht ändert; je mehr Infrarotlicht empfangen wird, desto niedriger sinkt sein Widerstand und umgekehrt.

Auf dem Modul befindet sich ein LM393-Komparator, der dazu dient, die Spannung des Phototransistors mit der eingestellten Spannung (mittels Potentiometer angepasst) zu vergleichen. Ist sie größer als die eingestellte Spannung, ist der Ausgang 1; andernfalls ist der Ausgang 0.

Daher, wenn der Infrarotsender auf eine schwarze Oberfläche leuchtet, wird, da Schwarz Licht absorbiert, der fotosensitive Transistor weniger Infrarotlicht empfangen, sein Widerstand wird steigen (Spannungszunahme), nach dem LM393-Komparator, der Ausgang hoher Pegel.

Ebenso, wenn es auf eine weiße Oberfläche leuchtet, wird das reflektierte Licht mehr und der Widerstand des fotosensitiven Transistors wird sinken (Spannungsabnahme); daher gibt der Komparator einen niedrigen Pegel aus und die Anzeige-LED leuchtet auf.



* `TCRT5000 <https://www.vishay.com/docs/83760/tcrt5000.pdf>`_

**Merkmale**

* Verwendung des Infrarotsensors TCRT5000
* Erfassungsabstand: 1-8 mm, Brennweite von 2,5 mm
* Komparatorausgangssignal klar, gute Wellenform, Treibfähigkeit größer als 15 mA
* Verwendung eines Potentiometers zur Empfindlichkeitseinstellung
* Betriebsspannung: 3,3 V-5 V
* Digitaler Ausgang: 0 (weiß) und 1 (schwarz)
* Verwendung eines breitspannungsfähigen LM393-Komparators.
* Größe: 42 mm x 10 mm


**Beispiele**

* :ref:`ar_line_track` (Arduino-Projekt)
* :ref:`py_line_track` (MicroPython-Projekt)
* :ref:`sh_protect_heart` (Scratch-Projekt)

