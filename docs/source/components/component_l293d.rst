.. _cpn_l293d:

L293D
=================

Der L293D ist ein integrierter 4-Kanal-Motortreiber-Chip mit hoher Spannung und hohem Strom. 
Er ist dafür konzipiert, an Standard-DTL, TTL-Logikpegel anzuschließen und induktive Lasten (wie Relaisspulen, Gleichstrom-, Schrittmotoren) sowie Leistungsschalttransistoren usw. zu steuern.
Gleichstrommotoren sind Geräte, die Gleichstromenergie in mechanische Energie umwandeln. Aufgrund ihrer überlegenen Drehzahlregelungsleistung werden sie häufig in elektrischen Antrieben eingesetzt.

Siehe die folgende Abbildung der Pins. Der L293D hat zwei Pins (Vcc1 und Vcc2) für die Stromversorgung. 
Vcc2 dient zur Stromversorgung des Motors, während Vcc1 den Chip versorgt. Da hier ein kleiner Gleichstrommotor verwendet wird, verbinden Sie beide Pins mit +5V.

.. image:: img/l293d111.png

Folgend sehen Sie die interne Struktur des L293D.
Pin EN ist ein Aktivierungspin und funktioniert nur auf hohem Niveau; A steht für Eingang und Y für Ausgang.
Die Beziehung zwischen ihnen können Sie unten rechts sehen.
Wenn Pin EN auf hohem Niveau ist, gibt Y bei hohem A ein hohes Signal aus und bei niedrigem A ein niedriges Signal. Wenn Pin EN auf niedrigem Niveau ist, funktioniert der L293D nicht.

.. image:: img/l293d334.png

* `L293D Datenblatt <https://www.ti.com/lit/ds/symlink/l293d.pdf?ts=1627004062301&ref_url=https%253A%252F%252Fwww.ti.com%252Fproduct%252FL293D>`_

**Beispiele**

* :ref:`ar_motor` (Arduino-Projekt)
* :ref:`ar_pump` (Arduino-Projekt)
* :ref:`py_motor` (MicroPython-Projekt)
* :ref:`py_pump` (MicroPython-Projekt)
* :ref:`sh_rotating_fan` (Scratch-Projekt)
