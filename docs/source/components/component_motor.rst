.. _cpn_motor:

Gleichstrommotor
===================

.. image:: img/image114.jpeg
    :align: center

Hier handelt es sich um einen 3V-Gleichstrommotor. Wenn Sie an jeden der beiden Anschlüsse einen hohen und einen niedrigen Pegel anlegen, wird er sich drehen.

* **Größe**: 25*20*15MM
* **Betriebsspannung**: 1-6V
* **Leerlaufstrom** (3V): 70mA
* **Leerlaufdrehzahl** (3V): 13000 U/min
* **Blockierstrom** (3V): 800mA
* **Wellendurchmesser**: 2mm

Ein Gleichstrommotor (DC-Motor) ist ein kontinuierlicher Aktuator, der elektrische Energie in mechanische Energie umwandelt. DC-Motoren ermöglichen es, dass rotierende Pumpen, Ventilatoren, Kompressoren, Impeller und andere Geräte durch kontinuierliche Drehbewegungen funktionieren.

Ein DC-Motor besteht aus zwei Teilen: dem feststehenden Teil des Motors, dem **Stator**, und dem internen Teil des Motors, dem **Rotor** (oder **Anker** eines Gleichstrommotors), der sich dreht, um Bewegung zu erzeugen.
Der Schlüssel zur Bewegungserzeugung ist die Positionierung des Ankers innerhalb des Magnetfelds des Permanentmagneten (dessen Feld sich vom Nordpol zum Südpol erstreckt). Die Wechselwirkung des Magnetfelds und der bewegten geladenen Partikel (der stromführende Draht erzeugt das Magnetfeld) erzeugt das Drehmoment, das den Anker dreht.

.. image:: img/motor_sche.png
    :align: center

Der Strom fließt vom positiven Pol der Batterie durch den Schaltkreis, über die Kupferbürsten zum Kommutator und dann zum Anker.
Durch die beiden Lücken im Kommutator kehrt sich dieser Fluss jedoch bei jeder vollständigen Drehung zur Hälfte um.
Diese kontinuierliche Umkehrung wandelt die Gleichstromleistung der Batterie im Wesentlichen in Wechselstrom um, wodurch der Anker das Drehmoment in der richtigen Richtung zur richtigen Zeit erfährt, um die Drehung aufrechtzuerhalten.


**Beispiele**

* :ref:`ar_motor` (Arduino-Projekt)
* :ref:`py_motor` (MicroPython-Projekt)
* :ref:`sh_rotating_fan` (Scratch-Projekt)
